package mphx.server;

import mphx.tcp.Connection;

class Room {
	public var full:Bool = false; // inhabitants.length == maxPopulation
	public var maxConnections = 0; //A max population of 0 will never be full.

	public var connections:Array<Connection>;
	public function new (){
		connections = new Array<Connection>();
	}

	/* Do not remove a client from the room with this message, rather treat it as an event.
		Remember to call super.onLeave!*/
	public function onLeave (client:Connection){
		connections.remove(client);
	}
	/* Do not put a client in the room with this message, rather treat it as an event.
		Remember to call super.onJoin!*/
	public function onJoin(client:Connection){
		connections.push(client);
	}

	public function broadcast(event:String,data:Dynamic):Bool
	{
		var success = true;
		for (client in connections)
		{
			if (client.send(event,data))
			{
				success = false;
			}
		}
		return success;
	}
}
