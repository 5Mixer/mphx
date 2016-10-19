package mphx.server.impl ;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.connection.IConnection;
import mphx.connection.impl.Connection;
import mphx.connection.impl.WebsocketProtocol;
import mphx.connection.NetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.server.room.Room;
import mphx.utils.event.impl.ServerEventManager;
import sys.net.Host;
import sys.net.Socket;
import mphx.utils.Log;

class Server implements IServer
{
	private var readSockets:Array<Socket>;
	private var clients:Map<Socket, NetSock>;
	private var listener:Socket;
	private var buffer:Bytes;

	public var host(default, null):String;
	public var port(default, null):Int;

	public var blocking(default, set):Bool = true;

	public var onConnectionAccepted : String->IConnection->Void;
	public var onConnectionClose : String->IConnection->Void;

	public var events : ServerEventManager;
	public var rooms:Array<Room>;

	private var connectionTemplate : IConnection;
	private var serializer : ISerializer;

	public var maximumBufferSize = 10240;

	//Send data from output immediently, don't wait for it to queue
	//...will not always be suitable/linked to lower lag!
	public var fastSend(default, set) = true;
	function set_fastSend(newValue){ listener.setFastSend(newValue); return newValue; }

	/**
	 * @param	hostname
	 * @param	port
	 * @param	connectionTemplate
	 * @param	_serializer
	 * @param	buffer : set the max read buffer (default = 8Kb) the buffer size is set with buffer * 1024
	 */
	public function new(hostname:String, port:Int, connectionTemplate : IConnection = null, _serializer : ISerializer = null, bufferSize : Int = 8)
	{
		if (hostname == null)
			hostname = Host.localhost();

		this.host = hostname;
		this.port = port;
		this.connectionTemplate = connectionTemplate;

		if (_serializer == null)
			serializer = new HaxeSerializer();
		else
			serializer = _serializer;

		buffer = Bytes.alloc(1024 * bufferSize);
		listener = new Socket();
		readSockets = [listener];
		clients = new Map();
		events = new ServerEventManager();
		rooms = [];
	}

	public function start (maxPendingConnection : Int = 1, blocking : Bool = true)
	{
		Log.message(DebugLevel.Info,"Server active on "+host+":"+port+". Code after server.start() will not run. ");
		listen(maxPendingConnection, blocking);
		while (true)
		{
			update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	}

	public function listen(maxPendingConnection : Int = 1, blocking : Bool = true)
	{
		listener.bind(new Host(host), port);
		listener.listen(1);
		this.blocking = blocking;
	}

	public function update(timeout:Float=0):Void
	{
		var protocol : IConnection;
		var bytesReceived:Int;

		//Select waits until a socket can be read.
		//The two null parameters allow waiting for a sockets write/exception, and are unneeded.
		var select = Socket.select(readSockets, null, null, timeout);

		for (socket in select.read)
		{
			if (socket == listener)
			{
				//If the socket that has data to read is the listener socket,
				//allocate a new netsock/protocol for this client to be processed with.

				var client = listener.accept();
				client.setFastSend(fastSend);
				var netsock = new NetSock(client);

				readSockets.push(client);
				clients.set(client, netsock);
				client.setBlocking(false);

				if (connectionTemplate != null)
					protocol = connectionTemplate.clone();
				else
					protocol = new Connection(); // default

				protocol.configure(this.events, this, serializer);
				client.custom = protocol;
				protocol.onAccept(netsock);

			}else{
				//The server has recieved data from an already established client.

				protocol = socket.custom;
				var byte:Int = 0,
				bytesReceived:Int = 0,
				len = buffer.length;

				var error = false;
				while (true) //Reaching the end of the message or an error will break the loop
				{
					if (bytesReceived == len - 1){
						if (bytesReceived > maximumBufferSize){
							trace("Attention: A client has exceeded maximum memory. This could be an attack on the server. The server can be allowed more space by increasing it's maximumBufferSize. Client disconnected.");
							protocol.loseConnection("Connection exceeded allocated memory");
							readSockets.remove(socket);
							clients.remove(socket);

							error = true;
							break; //Continue to recieve messages from other clients
						}
						//We have reached maximum buffer size! We have not allocated enough buffer space.
						trace('Warning: Recieved message too large to fit into buffer; Automatically increasing buffer size to '+len+1024);
						var oldBuffer = buffer;
						buffer = Bytes.alloc(len + 1024); //Add an extra 1024 bytes space.
						buffer.blit(0,oldBuffer,0,len);
						len = buffer.length;

					}

					try
					{
						byte = #if flash socket.readByte() #else socket.input.readByte() #end;
					}
					catch (e:Dynamic)
					{
						// end of stream
						if (Std.is(e, haxe.io.Eof) || e== haxe.io.Eof)
						{
							readSockets.remove(socket);
							clients.remove(socket);
							error = true;
							protocol.loseConnection("close connection");

							break;
						}else if (e == haxe.io.Error.Blocked)
						{
							//End of message. Not an error - This is still a connected, valid client.
							break;
						}else{
							trace(e);
						}
					}
					buffer.set(bytesReceived, byte);
					bytesReceived += 1;
				}

				// check that buffer was filled
				if (bytesReceived > 0 && error == false) //If some data was recieved and the client is valid still
				{
					//check, is message an indication of a websocket connection?
					if (new BytesInput(buffer, 0, bytesReceived).readLine() == "GET / HTTP/1.1")
					{
						//If so, recreate a protocol of type websocket, for this specific client.
						var socket = protocol.getContext().socket;
						var netsock = new NetSock(socket);
						protocol = new WebsocketProtocol();
						protocol.configure(this.events, this, serializer);
						socket.custom = protocol;
						protocol.onAccept(netsock);
					}

					//Let the protocol process the data.
					protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
				}

				if (!protocol.isConnected())
				{
					readSockets.remove(socket);
					clients.remove(socket);
					break;
				}
			}
		}
	}

	public function broadcast(event:String, ?data:Dynamic):Bool
	{
		var success = true;
		for (client in clients)
		{
			if (!cast(client.socket.custom, IConnection).send(event,data))
			{
				success = false;
			}
		}
		return success;
	}

	public function close()
	{
		listener.close();
	}

	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
		if (listener != null) listener.setBlocking(value);
		return blocking = value;
	}
}
