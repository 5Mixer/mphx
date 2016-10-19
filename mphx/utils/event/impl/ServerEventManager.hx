package mphx.utils.event.impl ;

import mphx.connection.IConnection;
import mphx.utils.Log;

typedef ServerEventFunction = Dynamic->IConnection->Void;

class ServerEventManager
{

	/**
	 * call an event if exist.
	 * If the callback associed to the event is null. nothing append
	 * @param	eventName
	 * @param	data
	 * @param	sender
	 */
	public var callEvent:String->Dynamic->IConnection->Void;

	private var eventMap:Map<String,ServerEventFunction>;

	public function new()
	{
		eventMap = new Map();

		callEvent = callEventCallBack;
	}

	/**
	 * Add a event.
	 * If the event already exist, override the precedent callback
	 * @param	eventName
	 * @param	event
	 */
	public function on(eventName:String, event:ServerEventFunction)
	{
		eventMap.set(eventName,event);
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

	private function callEventCallBack(eventName:String, data:Dynamic, sender:IConnection) : Void
	{
		//If an event with that name exists.
		if (eventMap.exists(eventName))
		{
			if(eventMap.get(eventName) != null){
				eventMap.get(eventName)(data, sender);
			}else{
				//Event is null.
				Log.message(DebugLevel.Info | DebugLevel.Networking,"mphx recieved event type "+eventName+" however no event listener was registered for it.");
			}
		}
	}
}
