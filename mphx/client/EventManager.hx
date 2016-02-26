package mphx.client;

typedef EventFunction = Dynamic->Void;

class EventManager
{
	var eventMap:Map<String,EventFunction>;

	public function new ()
	{
		eventMap = new Map<String,EventFunction>();
	}

	public function on (eventName,event:EventFunction)
	{
		eventMap.set(eventName,event);
	}
	public function callEvent (eventName,data)
	{
		//If an event with that name exists.
		if (eventMap.exists(eventName) == true){
			//See if the event should be called with or without the sender.
			eventMap.get(eventName)(data);
		}

	}
}
