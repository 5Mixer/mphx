package mphx.client;

import mphx.serialization.ISerializer;

//The client class that is used with JS websockets.
class WebsocketClient implements IClient
{

	var websocket : js.html.WebSocket;

	var port:Int;
	var ip:String;

	var ready = false;
	var messageQueue:Array<Dynamic>;

	public var onConnectionError :Void->Void;
	public var onConnectionEstablished :Void->Void;
	public var onConnectionClose:String->Void; //String is the reason for the close.

	public var abstraction:mphx.client.ConnectionAbstraction;

	public function new(_ip:String,_port:Int)
	{
		ip = _ip;
		port = _port;

		messageQueue = new Array<Dynamic>();

        abstraction = new mphx.client.ConnectionAbstraction(this);
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
				send(message);
				messageQueue.remove(message);
			}
		}

		websocket.onmessage = function (line)
		{
			var data = line.data; //It's inside the JSON websocket request
			abstraction.onData(data);
		}
	}

	public function send(data:String)
	{

		if (ready == true)
		{
			websocket.send(data + "\r\n");
		}else{
			messageQueue.push(data);
		}

	}

	public function update(timeout:Float=0)
	{
		//JS Websockets don't need to be updated.
	}

	public function close (){
		websocket.close();
		onConnectionClose("Websocket connection was closed.");
	}
}
