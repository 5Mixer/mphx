package mphx.client.impl;

import haxe.io.Bytes;
import haxe.io.Input;
import mphx.connection.NetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.utils.event.impl.ClientEventManager;
import sys.net.Host;
import sys.net.Socket;
import mphx.utils.Log;
//The TCP client class that is used on native targets.
//This should not be created by the user! For ultimate cross compatibility
//Just create a new 'Client'. It will create this class on native targets.

class TcpClient implements IClient
{
	public var blocking(default, set):Bool;
	public var connected:Bool;
	public var serializer:ISerializer;
	public var cnx:NetSock;
	public var events:ClientEventManager;
	private var client:Socket;
	private var readSockets:Array<Socket>;

	public var onConnectionError:mphx.utils.Error.ClientError->Void;
	public var onConnectionClose:mphx.utils.Error.ClientError->Void; //String arg is the reason for termination. May or not be useful.
	public var onConnectionEstablished:Void->Void;

	//Send data from output immediently, don't wait for it to queue
	//...will not always be suitable/linked to lower lag!
	public var fastSend(default, set) = true;
	function set_fastSend(newValue){ client.setFastSend(newValue); return newValue; }

	var port:Int;
	var ip:String;

	public function new(_ip:String, _port:Int, _serializer : ISerializer = null, _blocking : Bool = false)
	{
		port = _port;
		ip = _ip;
		events = new ClientEventManager();

		if (_serializer != null)
			serializer = _serializer;
		else
			serializer = new HaxeSerializer();

		this.blocking = _blocking;
	}

	public function connect()
	{
		Log.message(DebugLevel.Info,"Attempting to connect on: "+ip+":"+port);
		client = new Socket();
		try
		{
			if (ip == null)
				ip = Host.localhost();

			client.connect(new Host(ip), port);
			client.setBlocking(this.blocking);
			connected = true;

		}
		catch (e :Dynamic)
		{
			connected = false;
			Log.message(DebugLevel.Errors,"Failed to connect. Error: "+e);

			if (onConnectionError != null)
				onConnectionError(e);
			return;
		}
		// prevent recreation of array on every update
		readSockets = [client];
		cnx = new NetSock(client);

		Log.message(DebugLevel.Info,"Connected on: "+ip+":"+port);

		if (onConnectionEstablished != null)
			onConnectionEstablished();
	}

	public function update(timeout:Float=0)
	{
		if (!connected) return;

		if (blocking)
			dataReceived(client.input);
		else
		{
			var select = Socket.select(readSockets, null, null, timeout);

			for (socket in select.read)
				readSocket(socket);
		}
	}

	public function recieve(line:String)
	{
		var msg = serializer.deserialize(line);
		events.callEvent(msg.t,msg.data);
	}

	public function dataReceived(input:Input):Void
	{
		//Convert Input to string then process.
		var line = "";
		try{
			line = input.readLine();

		}catch(e:Dynamic){
			loseConnection(mphx.utils.Error.ClientError.DroppedConnection);
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
			loseConnection(mphx.utils.Error.ClientError.DroppedConnection);
		}
	}
	public function loseConnection(?error:mphx.utils.Error.ClientError)
	{
		Log.message(DebugLevel.Info,"Client disconnected. "+error);
		if (cnx != null){
			cnx.clean();
			this.cnx = null;
		}
		connected = false;

		//This is a user set function var, so it may not be overridden.
		if (onConnectionClose != null)
			onConnectionClose(error);
	}

	public function close()
	{
		client.close();
		if (cnx != null){
			cnx.clean();
			this.cnx = null;
		}
		client = null;
	}

	public function send(event:String, ?data:Dynamic){
		if (isConnected() == false){
			Log.message(DebugLevel.Warnings | DebugLevel.Networking,"Cannot sent event "+event+" as client is not connected to a server.");
			return;
		}
		var object = {
			t: event,
			data:data
		};
		var serialiseObject =  serializer.serialize(object);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
	}

	private inline function get_connected() : Bool{ return client != null;}
	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }

	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
		return blocking = value;
	}
}
