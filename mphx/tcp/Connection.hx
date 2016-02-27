package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.serialization.ISerializer;

class Connection implements mphx.tcp.IConnection
{
	public var events:mphx.server.EventManager;
	public var cnx:NetSock;
	public var serializer:ISerializer;
	public var room:mphx.server.Room = null;
	public var data:Dynamic;


	public function new (_events:mphx.server.EventManager){
		events = _events;
		serializer = new mphx.serialization.HaxeSerializer();
	}

	public function onConnect(cnx:NetSock) { this.cnx = cnx; }
	public function onAccept(cnx:NetSock) { this.cnx = cnx; }

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
		//Transfer the Input data to a string

		//Then convert the string to a Dynamic object.
		var msg = serializer.deserialize(line);

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
