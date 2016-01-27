package mphx.tcp;

import mphx.interfaces.Connection;
import haxe.io.Input;

class Protocol extends mphx.base.Protocol {
	var events:mphx.core.EventManager;
	public function new (_events:mphx.core.EventManager){
		super();
		events = _events;
	}

	public function send (event:String,data:Dynamic){
		var object = {
			t: event,
			data:_data
		};
		var serialiseObject = haxe.Json.stringify(object);

		return cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
	}

	override public function dataReceived(input:Input){
		//Transfer the Input data to a string
		var line = input.readLine();
		trace(line);
		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		msg.data.connection = this;
		events.callEvent(msg.t,msg.data);

	}
}
