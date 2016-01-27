package mphx.client;

import haxe.io.Bytes;

class Client {

	var client:mphx.tcp.Client;
	var events:mphx.core.EventManager;

	public function new (ip:String,port:Int){

		events = new mphx.core.EventManager();

		client = new mphx.tcp.Client(port,ip,events);

		client.blocking = false;
	}
	public function connect (){
		client.connect();
	}
	public function update (){
		client.update();
	}
	public function send (event:String,_data:Dynamic){
		var object = {
			t: event,
			data:_data
		};
		var serialiseObject = haxe.Json.stringify(object);

		client.protocol.cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
	}


}
