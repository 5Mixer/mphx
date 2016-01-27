package mphx.tcp;

#if !flash

import sys.net.Host;
import sys.net.Socket;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.interfaces.Protocol;

class Server implements mphx.interfaces.Server
{

	public var host(default, null):String;
	public var port(default, null):Int;
	public var blocking(default, set):Bool = true;

	var events:mphx.core.EventManager;

	public function new(port:Int, ?hostname:String,eventManager:mphx.core.EventManager)
	{
		buffer = Bytes.alloc(8192);

		if (hostname == null) hostname = Host.localhost();

		this.host = hostname;
		this.port = port;

		events = eventManager;

		listener = new Socket();

		readSockets = [listener];
		clients = new Map<Socket, Connection>();
	}

	public function listen()
	{
		listener.bind(#if flash host #else new Host(host) #end, port);
		listener.listen(1);
		listener.setBlocking(blocking);
	}


	public function update(timeout:Float=0):Void
	{
		var protocol:Protocol;
		var bytesReceived:Int;
		var select = Socket.select(readSockets, null, null, timeout);
		for (socket in select.read)
		{
			if (socket == listener)
			{
				var client = listener.accept();
				var connection = new Connection(client);

				readSockets.push(client);
				clients.set(client, connection);

				client.setBlocking(false);
				client.custom = protocol = new mphx.tcp.Protocol(events);
				protocol.onAccept(connection, this);
			}
			else
			{
				protocol = socket.custom;
				try
				{
					bytesReceived = socket.input.readBytes(buffer, 0, buffer.length);
					// check that buffer was filled
					if (bytesReceived > 0)
					{
						protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
					}
				}
				catch (e:Dynamic)
				{
					protocol.loseConnection("disconnected");
					socket.close();
					readSockets.remove(socket);
					clients.remove(socket);
				}
				if (!protocol.isConnected())
				{
					readSockets.remove(socket);
					clients.remove(socket);
				}
			}
		}
	}

	public function broadcast(event:String,data:Dynamic):Bool
	{
		var success = true;
		for (client in clients)
		{
			if (!cast(client.socket.custom,mphx.tcp.Protocol).send(event,data))
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

	private var readSockets:Array<Socket>;
	private var clients:Map<Socket, Connection>;
	private var listener:Socket;

	private var buffer:Bytes;

}

#end
