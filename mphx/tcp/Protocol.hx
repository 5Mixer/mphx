package mphx.tcp;

import mphx.interfaces.Connection;
import haxe.io.Input;

class Protocol extends mphx.base.Protocol {
	var events:mphx.core.EventManager;
	public function new (_events:mphx.core.EventManager){
		super();
		events = _events;
	}

	override public function dataReceived(input:Input){
		//Transfer the Input data to a string
		var line = input.readLine();

		//Then convert the string to a Dynamic object.
		var msg = haxe.Json.parse(line);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data);

	}
}
