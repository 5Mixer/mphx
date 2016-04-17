package mphx.connection.impl ;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.connection.IConnection;
import mphx.server.IServer;
import mphx.server.room.Room;
import mphx.utils.event.impl.ServerEventManager;

class Connection implements IConnection
{
	private var m_server:IServer;
	public var cnx:NetSock;
	public var serializer:ISerializer;
	public var events:ServerEventManager;
	public var room:Room = null;
	public var data:Dynamic;

	public function new ()
	{
	}
	
	public function clone() : IConnection
	{
		return new Connection();
	}
	
	public function configure(_events : ServerEventManager, _server:IServer, _serializer : ISerializer = null) : Void
	{
		events = _events;
		m_server = _server;
		
		if (_serializer == null)
			this.serializer = new HaxeSerializer();
		else
			serializer = _serializer;
	}
	
	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }
	public function getContext() :NetSock {return cnx;}

	public function putInRoom (newRoom:mphx.server.room.Room)
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

	public function onAccept(cnx:NetSock) : Void
	{ 
		this.cnx = cnx;
		
		if (m_server.onConnectionAccepted != null)
			m_server.onConnectionAccepted("accept : " + this.getContext().peerToString(), this);
	}
	
	//difference with onAccept ?
	public function onConnect(cnx:NetSock) : Void
	{ 
		this.cnx = cnx; 
		
		//if (m_server.onConnectionAccepted != null)
			//m_server.onConnectionAccepted("connect : " + this.getContext().peerToString(), this);
	}
	
	public function loseConnection(?reason:String)
	{
		trace("Client disconnected with code: "+reason);
		if (cnx != null){
			cnx.clean();
			this.cnx = null;
		}
		if (room != null){
			room.onLeave(this);
		}

		if (m_server.onConnectionClose != null)
			m_server.onConnectionClose(reason, this);
	}
	
	public function send(event:String, ?data:Dynamic):Bool 
	{
		var object = {
			t: event,
			data:data
		}
		
		var serialiseObject = serializer.serialize(object);
		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
		return result;
	}

	public function recieve(line:String)
	{
		var msg = serializer.deserialize(line);
		events.callEvent(msg.t,msg.data,this);
	}

	public function dataReceived(input:Input):Void
	{
		var line = "";
		try{
			line = input.readLine();
		}catch(e:Dynamic){
			loseConnection("Lost connection to server");
			return;
		}
		recieve(line);
	}
}
