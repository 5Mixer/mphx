package mphx.client;

#if flash
import flash.net.Socket;
#else
import sys.net.Host;
import sys.net.Socket;
#end
import haxe.io.Bytes;
import haxe.io.BytesInput;
import haxe.io.Input;
import mphx.tcp.IConnection;
import mphx.tcp.NetSock;

//The TCP client class that is used on native targets.
//This should not be created by the user! For ultimate cross compatibility
//Just create a new 'Client'. It will create this class on native targets.

class TcpClient implements IClient
{

	public var blocking(default, set):Bool = true;
	public var connected(get, never):Bool;

	public var cnx:NetSock;

	public var events:mphx.client.EventManager;

	var port:Int;
	var ip:String;

	public function new(_ip:String,_port:Int)
	{
		events = new mphx.client.EventManager();

		buffer = Bytes.alloc(8192);

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
			cnx = new NetSock(client);

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
				dataReceived(client.input);
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
	}

	public function recieve(line:String){
		//Transfer the Input data to a string

		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data);

	}

	public function dataReceived(input:Input):Void
	{
		//Convert Input to string then process.
		var line = "";
		try{
			line = input.readLine();
		}catch(e:Dynamic){
			loseConnection("Lost connection to server");
			return;
		}
		recieve(line);
	}

	function readSocket(socket:Socket)
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
		{
			new BytesInput(buffer, 0, bytesReceived));
		}*/
		try
		{
			dataReceived(socket.input);
		}catch(e:haxe.io.Eof){
			loseConnection("Lost connection to server");
		};
	}
	public function loseConnection(?reason:String)
	{
		trace("Client disconnected with code: "+reason);
		if (cnx != null){
			cnx.close();
			this.cnx = null;
		}
	}

	public function close()
	{
		client.close();
		if (cnx != null){
			cnx.close();
			this.cnx = null;
		}
		client = null;
	}

	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = haxe.Json.stringify(object);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
	}


	private inline function get_connected():Bool
	{
		return client != null;
	}
	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }


	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
#if !flash
		if (client != null) client.setBlocking(value);
#end
		return blocking = value;
	}
	private var client:Socket;
	private var readSockets:Array<Socket>;
	private var buffer:Bytes;

}
