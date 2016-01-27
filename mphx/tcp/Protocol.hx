package mphx.tcp;

import mphx.interfaces.Connection;
import haxe.io.Input;

class Protocol extends mphx.base.Protocol {

	public function new (){
		super();
	}

	override public function dataReceived(input:Input){
		var line = input.readLine();
		trace(line);

	}
}
