package mphx.utils.event.impl ;

import mphx.utils.Log;

typedef EventFunction = Dynamic->Void;

class ClientEventManager
{
	public var callEvent : String->Dynamic->Void;

	var eventMap:Map<String,EventFunction>;

	public function new()
	{
		eventMap = new Map();
		callEvent = callEventCallback;
	}

	/**
	 * Add a event.
	 * If the event already exist, override the precedent callback
	 * @param	eventName
	 * @param	event
	 */
	public function on(eventName:String, event:EventFunction)
	{
		eventMap.set(eventName, event);
	}

	/**
	 * Remove an event if exist
	 * @param	eventName
	 */
	public function remove(eventName:String)
	{
		if (eventMap.exists(eventName))
		{
			eventMap.set(eventName,null);
			eventMap.remove(eventName);
		}
	}

	/**
	 * call an event if exist.
	 * If the callback associed to the event is null. nothing append
	 * @param	eventName
	 * @param	data
	 */
	public function callEventCallback(eventName:String, data:Dynamic)
	{
		//If an event with that name exists.
		if (eventMap.exists(eventName))
		{
			//See if the event should be called with or without the sender.
			if(eventMap.get(eventName) != null){
				eventMap.get(eventName)(data);
			}else{
				Log.message(DebugLevel.Info | DebugLevel.Networking,"mphx recieved event type "+eventName+" however no event listener was registered for it.");
			}
		}
	}
}
