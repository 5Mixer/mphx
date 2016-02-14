package mphx.core;

import mphx.tcp.Connection;

typedef EventFunction = Either<(Dynamic->Connection->Void), (Dynamic->Void)>;

class EventManager {

	var eventMap:Map<String,EventFunction>;

	public function new () {
		eventMap = new Map<String,EventFunction>();
	}

	public function on (eventName,event:EventFunction){
		eventMap.set(eventName,event);
	}
	public function callEvent (eventName,data,sender:mphx.tcp.Connection){
		//If an event with that name exists.
		if (eventMap.exists(eventName) == true){
			//See if the event should be called with or without the sender.
			switch(eventMap.get(eventName).type){
			case Left(eventWithSender): eventWithSender(data,sender);
			case Right(eventWithoutSender): eventWithoutSender(data);
			}
		}

	}

}




abstract Either<L, R> (haxe.ds.Either<L, R>)
{
	inline function new (e:haxe.ds.Either<L, R>)
    {
        this = e;
    }

	public var type (get, never) : haxe.ds.Either<L, R>;
	inline function get_type () : haxe.ds.Either<L, R>
    {
        return this;
    }

	@:from static inline function fromLeft<L> (left:L)
    {
        return new Either(Left(left));
    }

	@:from static inline function fromRight<R> (right:R)
    {
        return new Either(Right(right));
    }
}
