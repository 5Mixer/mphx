package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;
import mphx.server.Server;

class Protocol {
	public var events:mphx.core.EventManager;
	public function new (_events:mphx.core.EventManager){
		events = _events;
	}

	public function onConnect(cnx:Connection) { this.cnx = cnx; }
	public function onAccept(cnx:Connection) { this.cnx = cnx; }

	public function loseConnection(?reason:String) { this.cnx = null; trace("CONNECTION CLOSING!!");}

	var cnx:Connection;


	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }


	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = haxe.Json.stringify(object);


		trace("Sending event: "+event);

		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));

		trace("Sent event: "+event);

		return result;
	}

	public function dataReceived(input:Input){
		//Transfer the Input data to a string
		var line = input.readLine();
		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//msg.data.sender = this;

		//
		//Reflect.setField(msg.data,"sender",this);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data,this);

	}
}
