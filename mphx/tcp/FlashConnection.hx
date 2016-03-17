package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.serialization.ISerializer;
import mphx.server.EventManager;
import mphx.tcp.IConnection;
import mphx.tcp.NetSock;
import mphx.utils.PolicyFilesProvider;

/**
 * A modified mphx.tcp.connection for managing flash policy files security
 * see : http://help.adobe.com/fr_FR/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7c60.html#WS5b3ccc516d4fbf351e63e3d118a9b90204-7c63
 * This will be removed on a update of the mphx library (perhaps)
 * @author
 */
class FlashConnection implements IConnection
{

	public var events:EventManager;
	public var cnx:NetSock;
	public var serializer:ISerializer;
	public var room:mphx.server.Room = null;
	public var data:Dynamic;

	private var m_domainAccept : String;
	private var m_portAccept : Int;


	public function new (_events:mphx.server.EventManager, domainAccept : String,  portAccept : Int)
	{
		events = _events;
		serializer = new mphx.serialization.HaxeSerializer();
		m_domainAccept = domainAccept;
		m_portAccept  = portAccept;
	}

	public function onConnect(cnx:NetSock) { this.cnx = cnx; }
	public function onAccept(cnx:NetSock) { this.cnx = cnx; }

	public function getContext() :NetSock
	{
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
	}

	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }


	public function send(event:String,?data:Dynamic):Bool {
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = serializer.serialize(object);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));

		//trace("Sent event: "+event);
		return result;
	}

	public function recieve(line:String){
		trace(line);
		//Transfer the Input data to a string

		//flash specific, if we receive this, we need to return the policy files
		if (line == "<policy-file-request/>")
		{
			trace("receive policyfile request");
			cnx.socket.output.writeString(PolicyFilesProvider.generateXmlPolicyFile(m_domainAccept,Std.string(m_portAccept)).toString());
			cnx.socket.output.flush();
			return;
		}

		//Then convert the string to a Dynamic object.
		var msg = serializer.deserialize(line);
		trace(msg);
		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data,this);

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
}
