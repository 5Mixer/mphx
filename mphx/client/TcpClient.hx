package mphx.client;

#if flash
import flash.net.Socket;
#else
import sys.net.Host;
import sys.net.Socket;
#end
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.tcp.Connection;
import mphx.tcp.NetSock;

class TcpClient implements IClient
{

	public var protocol(default, set):mphx.tcp.Connection;
	public var blocking(default, set):Bool = true;
	public var connected(get, never):Bool;

	public var events:mphx.core.EventManager;

	var port:Int;
	var ip:String;

	public function new(_ip:String,_port:Int)
	{
		events = new mphx.core.EventManager();

		buffer = Bytes.alloc(8192);
		protocol = new mphx.tcp.Connection(events);

		port = _port;
		ip = _ip;

		blocking = false;

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
				protocol.onConnect(new NetSock(client));
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

		///try
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
		// catch (e:Dynamic)
		// {
		// 	trace("Disconnected");
		// 	protocol.loseConnection("disconnected");
		// 	client.close();
		// 	client = null;
		// }
	}

	private function readSocket(socket:Socket)
	{
	/*	var byte:Int = 0,
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
				if (Std.is(e, haxe.io.Eof)){

					buffer.set(bytesReceived, byte);
					break;
				}else if ( e == haxe.io.Error.Blocked ) {
					buffer.set(bytesReceived, byte);
					break;
					//This error always happens at the end of a message.
					//throw "A blocking operation was ran but your blocking mode doesn't let it. :/";
				}
			}

			buffer.set(bytesReceived, byte);
			bytesReceived += 1;
		}

		// check that buffer was filled
		if (bytesReceived > 0)
		{*/
		try
		{
			protocol.dataReceived(socket.input);
		}catch(e:haxe.io.Eof){
			//throw("DISCONNECTED. "+e);
		};//new BytesInput(buffer, 0, bytesReceived));
		//}
	}

	public function close()
	{
		client.close();
		protocol.loseConnection();
		protocol = null;
		client = null;
	}

	public function send (event:String,data:Dynamic){
		protocol.send(event,data);
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

	private function set_protocol(value:Connection):Connection
	{
		if (client != null)
		{
			value.onConnect(new NetSock(client));
		}
		return protocol = value;
	}

	private var client:Socket;
	private var readSockets:Array<Socket>;
	private var buffer:Bytes;

}
