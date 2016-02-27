package mphx.client;

import mphx.serialization.ISerializer;

//The client class that is used with JS websockets.
class WebsocketClient implements IClient
{

	var websocket : js.html.WebSocket;

	public var events:mphx.client.EventManager;
	public var serializer:ISerializer;

	var port:Int;
	var ip:String;

	var ready = false;
	var messageQueue:Array<Dynamic>;

	public var onConnectionError :Void->Void;
	public var onConnectionEstablished :Void->Void;

	public function new(_ip:String,_port:Int)
	{
		events = new mphx.client.EventManager();

		serializer = new mphx.serialization.HaxeSerializer();

		ip = _ip;
		port = _port;

		messageQueue = new Array<Dynamic>();

	}

	public function connect() {
		websocket = new js.html.WebSocket("ws://"+ip+":"+port);

		websocket.onerror = function(e) {
			if (onConnectionError != null) onConnectionError();
		}

		websocket.onopen = function() {
			if (onConnectionEstablished != null) onConnectionEstablished();
			ready = true;

			for (message in messageQueue){
				send(message.t,message.data);
				messageQueue.remove(message);
			}
		}

		websocket.onmessage = function (line)
		{
			var data = line.data; //It's inside the JSON websocket request
			var msg = serializer.deserialize(data); //Is the serialized message.

			//The message will have a propety of T
			//This is the event name/type. It is t to reduce wasted banwidth.
			//call an event called 't' with the msg data.
			events.callEvent(msg.t,msg.data);
		}
	}

	public function send(event:String, ?data:Dynamic)
	{
		var object = {
			t: event,
			data:data
		};

		if (ready == true)
		{
			var serialiseObject = serializer.serialize(object);

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
