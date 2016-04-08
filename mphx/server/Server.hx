package mphx.server;

#if !flash

import sys.net.Host;
import sys.net.Socket;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.tcp.NetSock;

import mphx.server.Room;

import mphx.tcp.IConnection;

class Server implements IServer
{

	public var host(default, null):String;
	public var port(default, null):Int;
	public var blocking(default, set):Bool = true;

	public var onConnectionClose:IConnection->Void;

	public var abstractConnectionFactory:IConnection->mphx.tcp.ConnectionAbstraction;

	public var rooms:Array<Room>;


	public function new(hostname:String,port:Int)
	{
		buffer = Bytes.alloc(8192);

		if (hostname == null) hostname = Host.localhost();

		this.host = hostname;
		this.port = port;

		//By default use the string based event connection abstraction. A good base for basic networking.
		abstractConnectionFactory = function (connection:IConnection) {
			return new mphx.tcp.ConnectionAbstraction(connection);
		}

		rooms = [];

		listener = new Socket();

		readSockets = [listener];
		clients = new Map();
	}

	public function listen()
	{
		listener.bind(#if flash host #else new Host(host) #end, port);
		listener.listen(1);
		listener.setBlocking(false);
	}

	public function start () {

		trace("Server active on "+host+":"+port+". Code after server.start() will not run. ");

		listen();
		while (true) {
			update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	}

	public function update(timeout:Float=0):Void
	{
		var protocol :mphx.tcp.IConnection;
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
				client.custom = protocol = new mphx.tcp.Connection(abstractConnectionFactory,this);
				protocol.onAccept(netsock);
			}
			else
			{

				protocol = socket.custom;

				var byte:Int = 0,
				bytesReceived:Int = 0,
				len = buffer.length;
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
						}else if (e == haxe.io.Error.Blocked){
							//End of message
							break;
						}else{
							trace(e);
						}

					}

					buffer.set(bytesReceived, byte);
					bytesReceived += 1;
				}

				// check that buffer was filled
				if (bytesReceived > 0)
				{
					//check, is message an indication of a websocket connection?
					if (new BytesInput(buffer, 0, bytesReceived).readLine() == "GET / HTTP/1.1"){

						//If so, recreate a protocol of type websocket, for this specific client.
						var socket = protocol.getContext().socket;
						var netsock = new mphx.tcp.NetSock(socket);

						socket.custom = protocol = new mphx.tcp.WebsocketProtocol(abstractConnectionFactory,this);
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
	{/*
		var success = true;
		for (client in clients)
		{
			if (!cast(client.socket.custom, mphx.tcp.IConnection).send(event,data))
			{
				success = false;
			}
		}
		return success;
	*/
		return false;
	}

	public function close()
	{
		listener.close();
	}

	function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
		if (listener != null) listener.setBlocking(value);
		return blocking = value;
	}

	private var readSockets:Array<Socket>;
	private var clients:Map<Socket, NetSock>;
	private var listener:Socket;

	private var buffer:Bytes;

}

#end
