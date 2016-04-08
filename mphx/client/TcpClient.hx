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
import mphx.serialization.ISerializer;

//The TCP client class that is used on native targets.
//This should not be created by the user! For ultimate cross compatibility
//Just create a new 'Client'. It will create this class on native targets.

class TcpClient implements IClient
{

	public var blocking(default, set):Bool = true;
	public var connected:Bool;

	public var cnx:NetSock;

	public var abstraction:mphx.client.ConnectionAbstraction;
	public var onConnectionError:Void->Void;
	public var onConnectionEstablished:Void->Void;
	public var onConnectionClose:String->Void; //String arg is the reason for termination. May or not be useful.

	var port:Int;
	var ip:String;


	public function new(_ip:String,_port:Int)
	{
		abstraction = new mphx.client.ConnectionAbstraction(this);

		buffer = Bytes.alloc(8192);

		port = _port;
		ip = _ip;

		blocking = false;
	}

	public function connect()
	{
		client = new Socket();
		try {
#if flash
		client.connect(ip, port);
		connected = true;
#else
		if (ip == null) ip = Host.localhost();
		client.connect(new Host(ip), port);
		client.setBlocking(blocking);
		connected = true;
#end
		} catch (e :Dynamic) {
			if (onConnectionError != null) onConnectionError();
			return;
		}
		// prevent recreation of array on every update
		readSockets = [client];
		cnx = new NetSock(client);

		if (onConnectionEstablished != null) onConnectionEstablished();
	}

	public function update(timeout:Float=0)
	{
		if (!connected) return;

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

	public function recieve(line:String){
		abstraction.onData(line);
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
		try
		{
			dataReceived(socket.input);
		}catch(e:haxe.io.Eof){
			loseConnection("Lost connection to server");
		}
	}
	public function loseConnection(?reason:String)
	{
		trace("Client disconnected with code: "+reason);
		if (cnx != null){
			cnx.close();
			this.cnx = null;
		}
		connected = false;

		//This is a user set function var, so it may not be overridden.
		if (onConnectionClose != null) onConnectionClose(reason);
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

	public function send(data:String){

		cnx.writeBytes(Bytes.ofString(data + "\r\n"));
	}


	private inline function get_connected():Bool
	{
		return client != null;
	}
	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }


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
