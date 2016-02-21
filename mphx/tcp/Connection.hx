package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;

class Connection implements mphx.tcp.IConnection
{
	public var events:mphx.server.EventManager;
	public var cnx:NetSock;

	public function new (_events:mphx.server.EventManager){
		events = _events;
	}

	//WARNING: This is server only. Attempting to use rooms on the client is a bad idea!
	//This perhaps needs better structuring, but having a client/server 'Connection' is undesirable.
	public var room:mphx.server.Room = null;

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

	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }


	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = haxe.Json.stringify(object);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));

		//trace("Sent event: "+event);
		return result;
	}

	public function recieve(line:String){
		//Transfer the Input data to a string

		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

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
