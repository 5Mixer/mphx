package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.server.Server;

class Connection {
	public var events:mphx.core.EventManager;
	public function new (_events:mphx.core.EventManager){
		events = _events;
	}

	//WARNING: This is server only. Attempting to use rooms on the client is a bad idea!
	//This perhaps needs better structuring, but having a client/server 'Connection' is undesirable.
	public var room:mphx.server.Room = null;

	public function onConnect(cnx:NetSock) { this.cnx = cnx; }
	public function onAccept(cnx:NetSock) { this.cnx = cnx; }

	public function putInRoom (newRoom:mphx.server.Room){
		if (room != null){
			room.onLeave(this);
		}

		room = newRoom;
		newRoom.onJoin(this);
	}

	public function loseConnection(?reason:String) {
		if (cnx != null){
			cnx.close();
			this.cnx = null;
		}
		if (room != null){

			room.onLeave(this);
		}


		trace("CONNECTION CLOSING!!");
	}

	var cnx:NetSock;


	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }


	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = haxe.Json.stringify(object);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));

		trace("Sent event: "+event+" with result "+result);
		return result;
	}

	public function dataReceived(input:Input){
		//Transfer the Input data to a string
		var line = input.readLine();
		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//msg.data.sender = this;

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data,this);

	}
}
