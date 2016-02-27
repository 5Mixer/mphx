package mphx.client;

typedef EventFunction = Dynamic->Void;

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

	public function callEvent(eventName:String, data:Dynamic)
	{
		//If an event with that name exists.
		if (eventMap.exists(eventName)) {
			//See if the event should be called with or without the sender.
			eventMap.get(eventName)(data);
		}
	}
}
