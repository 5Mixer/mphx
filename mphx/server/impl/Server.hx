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

class Server implements IServer
{
	private var readSockets:Array<Socket>;
	
	private var clients:Map<Socket, NetSock>;
	
	private var listener:Socket;

	private var m_buffer:Bytes;	
	
	public var host(default, null):String;
	
	public var port(default, null):Int;
	
	public var blocking(default, set):Bool = true;

	public var onConnectionAccepted : String->IConnection->Void;
	
	public var onConnectionClose : String->IConnection->Void;

	public var events : ServerEventManager;

	public var rooms:Array<Room>;
	
	private var m_connectionTemplate : IConnection;

	private var m_serializer : ISerializer;

	public function new(hostname:String, port:Int, connectionTemplate : IConnection = null, _serializer : ISerializer = null)
	{
		if (hostname == null) 
			hostname = Host.localhost();
			
		this.host = hostname;
		this.port = port;
		m_connectionTemplate = connectionTemplate;
		
		if (_serializer == null)
			m_serializer = new HaxeSerializer();
		else
			m_serializer = _serializer;
		
		m_buffer = Bytes.alloc(8192);
		listener = new Socket();
		readSockets = [listener];
		clients = new Map();		
		events = new ServerEventManager();
		rooms = [];
	}
	
	public function start (maxPendingConnection : Int = 1, blocking : Bool = true) 
	{
		trace("Server active on "+host+":"+port+". Code after server.start() will not run. ");
		listen(maxPendingConnection, blocking);
		while (true) 
		{
			update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	}	

	private function listen(maxPendingConnection : Int = 1, blocking : Bool = true)
	{
		listener.bind(new Host(host), port);
		listener.listen(1);
		this.blocking = blocking;
	}

	private function update(timeout:Float=0):Void
	{
		var protocol : IConnection;
		var bytesReceived:Int;
		var select = Socket.select(readSockets, null, null, timeout);

		for (socket in select.read)
		{
			if (socket == listener)
			{
				var client = listener.accept();
				var netsock = new NetSock(client);

				readSockets.push(client);
				clients.set(client, netsock);
				client.setBlocking(false);
				
				if (m_connectionTemplate != null)
					protocol = m_connectionTemplate.clone();
				else
					protocol = new Connection(); // default
					
				protocol.configure(this.events, this, m_serializer);
				client.custom = protocol; 
				protocol.onAccept(netsock);
			}
			else
			{
				protocol = socket.custom;
				var byte:Int = 0,
				bytesReceived:Int = 0,
				len = m_buffer.length;
				while (bytesReceived < len)
				{
					try
					{
						byte = #if flash socket.readByte() #else socket.input.readByte() #end;
					}
					catch (e:Dynamic)
					{
						// end of stream
						if (Std.is(e, haxe.io.Eof) || e== haxe.io.Eof)
						{
							protocol.loseConnection("close connection");
							readSockets.remove(socket);
							clients.remove(socket);

							break;
						}else if (e == haxe.io.Error.Blocked)
						{
							//End of message
							break;
						}else{
							trace(e);
						}
					}
					m_buffer.set(bytesReceived, byte);
					bytesReceived += 1;
				}

				// check that buffer was filled
				if (bytesReceived > 0)
				{
					//check, is message an indication of a websocket connection?
					if (new BytesInput(m_buffer, 0, bytesReceived).readLine() == "GET / HTTP/1.1")
					{
						//If so, recreate a protocol of type websocket, for this specific client.
						var socket = protocol.getContext().socket;
						var netsock = new NetSock(socket);
						protocol = new WebsocketProtocol();
						protocol.configure(this.events, this, m_serializer);
						socket.custom = protocol;
						protocol.onAccept(netsock);
					}

					//Let the protocol process the data.
					protocol.dataReceived(new BytesInput(m_buffer, 0, bytesReceived));
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

