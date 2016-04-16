package mphx.connection.impl ;

import haxe.io.Bytes;
import haxe.io.Input;
import mphx.connection.IConnection;
import mphx.connection.NetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.server.IServer;
import mphx.server.room.Room;
import mphx.utils.event.impl.ServerEventManager;
import mphx.utils.flash.PolicyFilesProvider;
/**
 * A modified mphx.tcp.connection for managing flash policy files security
 * see : http://help.adobe.com/fr_FR/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7c60.html#WS5b3ccc516d4fbf351e63e3d118a9b90204-7c63
 * This will be removed on a update of the mphx library (perhaps)
 * @author
 */
class FlashConnection implements IConnection
{
	public var events : ServerEventManager;
	public var cnx : NetSock;
	public var serializer : ISerializer;
	public var room : Room = null;
	public var data : Dynamic;

	private var m_domainAccept : String;
	private var m_portAccept : Int;

	var m_server:IServer;

	public function new (domainAccept : String,  portAccept : Int)
	{
		m_domainAccept = domainAccept;
		m_portAccept  = portAccept;
	}
	
	public function clone() : IConnection
	{
		return new FlashConnection(m_domainAccept, m_portAccept);
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

	public function putInRoom (newRoom:Room)
	{
		if (newRoom.full)
			return false;
			
		if (room != null)
			room.onLeave(this);
			
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
		if (cnx != null)
		{
			cnx.clean();
			this.cnx = null;
		}
		
		if (room != null)
			room.onLeave(this);
			
		if (m_server.onConnectionClose != null)
			m_server.onConnectionClose(reason, this);
	}

	public function send(event:String, ?data:Dynamic):Bool
	{
		var object = {
			t: event,
			data:data
		};
		
		var serialiseObject = serializer.serialize(object);
		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
		return result;
	}

	public function recieve(line:String)
	{
		//flash specific, if we receive this, we need to return the policy files
		if (line == "<policy-file-request/>")
		{
			trace("receive policyfile request");
			cnx.socket.output.writeString(PolicyFilesProvider.generateXmlPolicyFile(m_domainAccept,Std.string(m_portAccept)).toString());
			cnx.socket.output.flush();
			return;
		}
		var msg = serializer.deserialize(line);
		events.callEvent(msg.t,msg.data,this);
	}

	public function dataReceived(input:Input):Void
	{
		//Convert Input to string then process.
		var line = "";
		try{
			line = input.readLine();
		}catch (e:Dynamic)
		{
			loseConnection("Lost connection to server");
			return;
		}
		recieve(line);
	}
}
