package mphx.server;

import mphx.tcp.IConnection;

typedef EventFunction = Dynamic->IConnection->Void;

class EventManager
{
	var eventMap:Map<String,EventFunction>;

	public function new()
	{
		eventMap = new Map();
	}

	public function on(eventName:String, event:EventFunction)
	{
		eventMap.set(eventName,event);
	}

	public function callEvent(eventName:String, data:Dynamic, sender:IConnection)
	{
		//If an event with that name exists.
		if (eventMap.exists(eventName)) {
			eventMap[eventName](data, sender);
		}
	}
}
