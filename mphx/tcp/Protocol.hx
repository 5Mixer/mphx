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
	public function onAccept(cnx:Connection, server:Server) { this.cnx = cnx; this.server = server; }

	public function loseConnection(?reason:String) { this.cnx = null; }

	public var cnx:Connection;
	private var server:Server;


	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }


	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:data
		};
		var serialiseObject = haxe.Json.stringify(object);

		return cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
	}

	public function dataReceived(input:Input){
		//Transfer the Input data to a string
		var line = input.readLine();
		trace(line);
		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		//msg.data.connection = this;
		events.callEvent(msg.t,msg.data);

	}
}
