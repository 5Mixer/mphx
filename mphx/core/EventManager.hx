package mphx.core;

class EventManager {
	var eventMap:Map<String,Dynamic->Void>;

	public function new () {
		eventMap = new Map<String,Dynamic->Void>();
	}

	public function on (eventName,event:Dynamic->Void){
		eventMap.set(eventName,event);
	}
	public function callEvent (eventName,data:Dynamic){
		eventMap.get(eventName)(data);
		trace(eventName);
	}
}
