package mphx.client;

class WebsocketClient implements IClient
{

	var websocket : js.html.WebSocket;


	public var events:mphx.core.EventManager;

	var port:Int;
	var ip:String;

	var ready = false;
	var messageQueue:Array<Dynamic>;

	public var protocol:mphx.tcp.Connection;

	public function new(_ip:String,_port:Int)
	{
		trace("Using -Websocket- client");
		events = new mphx.core.EventManager();

		ip = _ip;
		port = _port;

		messageQueue = new Array<Dynamic>();

		protocol = new mphx.tcp.Connection(events);


	}
	public function connect () {

		websocket = new js.html.WebSocket("ws://"+ip+":"+port);

		websocket.onopen = function (){
			ready=true;

			for (message in messageQueue){
				send(message.t,message.data);
				messageQueue.remove(message);
			}
		}

		websocket.onmessage = function (m) protocol.recieve(m.data);
	}

	public function send(event:String, data:Dynamic){
		var object = {
			t: event,
			data:data
		};

		if (ready == true){
			var serialiseObject = haxe.Json.stringify(object);

			websocket.send(serialiseObject + "\r\n");
		}else{
			messageQueue.push(object);
		}

	}

	public function update(timeout:Float=0)
	{
		//JS Websockets don't need to be updated.
	}

	public function close (){
		websocket.close(0,"Close requested");
	}
}
