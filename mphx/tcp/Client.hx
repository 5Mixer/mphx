package mphx.tcp;


#if flash
import flash.net.Socket;
#else
import sys.net.Host;
import sys.net.Socket;
#end
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.tcp.Protocol;

class Client implements mphx.interfaces.Client
{

	public var protocol(default, set):mphx.tcp.Protocol;
	public var blocking(default, set):Bool = true;
	public var connected(get, never):Bool;

	var port:Int;
	var ip:String;

	public function new(_port:Int,_ip:String,events:mphx.core.EventManager)
	{
		buffer = Bytes.alloc(8192);
		protocol = new mphx.tcp.Protocol(events);

		port = _port;
		ip = _ip;
	}

	public function connect()
	{
		try
		{
			client = new Socket();
#if flash
			client.connect(ip, port);
#else
			if (ip == null) ip = Host.localhost();
			client.connect(new Host(ip), port);
			client.setBlocking(blocking);
#end
			// prevent recreation of array on every update
			readSockets = [client];
			if (protocol != null)
			{
				protocol.onConnect(new Connection(client));
			}
		}
		catch (e:Dynamic)
		{
			trace(e);
			client = null;
		}
	}

	public function update(timeout:Float=0)
	{
		if (!connected) return;

		try
		{
#if flash
			readSocket(client);
#else
			if (blocking)
			{
				protocol.dataReceived(client.input);
			}
			else
			{
				var select = Socket.select(readSockets, null, null, timeout);
				for (socket in select.read)
				{
					readSocket(socket);
				}
			}
#end
		}
		catch (e:Dynamic)
		{
			protocol.loseConnection("disconnected");
			client.close();
			client = null;
		}
	}

	private function readSocket(socket:Socket)
	{
		var byte:Int = 0,
			bytesReceived:Int = 0,
			len = buffer.length;
		while (bytesReceived < len)
		{
			try
			{

				byte = #if flash socket.readByte() #else socket.input.readByte() #end;
			}
			catch (e:haxe.io.Error)
			{
				// end of stream
				if (e == Blocked)
				{
					buffer.set(bytesReceived, byte);
					break;
				}
			}

			buffer.set(bytesReceived, byte);
			bytesReceived += 1;
		}

		// check that buffer was filled
		if (bytesReceived > 0)
		{
			protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
		}
	}

	public function close()
	{
		client.close();
		protocol.loseConnection();
		protocol = null;
		client = null;
	}

	private inline function get_connected():Bool
	{
		return client != null && protocol != null;
	}

	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
#if !flash
		if (client != null) client.setBlocking(value);
#end
		return blocking = value;
	}

	private function set_protocol(value:Protocol):Protocol
	{
		if (client != null)
		{
			value.onConnect(new Connection(client));
		}
		return protocol = value;
	}

	private var client:Socket;
	private var readSockets:Array<Socket>;
	private var buffer:Bytes;

}
