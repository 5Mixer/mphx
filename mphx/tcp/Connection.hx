package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.serialization.ISerializer;

class Connection implements mphx.tcp.IConnection
{
	public var events:mphx.server.EventManager;
	public var cnx:NetSock;
	public var room:mphx.server.Room = null;
	public var data:Dynamic;

	public var abstraction:mphx.tcp.ConnectionAbstraction;

	var server:mphx.server.IServer;

	public function new (abstractConnectionFactory:IConnection->mphx.tcp.ConnectionAbstraction,_server:mphx.server.IServer){
		server = _server;
		abstraction = abstractConnectionFactory(this);
	}

	public function onConnect(cnx:NetSock) { this.cnx = cnx; }
	public function onAccept(cnx:NetSock) { this.cnx = cnx; }

	public function getContext() :NetSock {
		return cnx;
	}

	public function putInRoom (newRoom:mphx.server.Room)
	{

		if (newRoom.full){
			return false;
		}
		if (room != null){
			room.onLeave(this);
		}

		room = newRoom;
		newRoom.onJoin(this);

		return true;
	}

	public function loseConnection(?reason:String)
	{
		trace("Client disconnected with code: "+reason);
		if (cnx != null){
			cnx.close();
			this.cnx = null;
		}
		if (room != null){
			room.onLeave(this);
		}

		if (server.onConnectionClose != null)
			server.onConnectionClose(this);
	}

	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }


	public function send(data:String):Bool {

		var result = cnx.writeBytes(Bytes.ofString(data + "\r\n"));

		//trace("Sent event: "+event);
		return result;
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
		abstraction.onData(line);
	}

}
