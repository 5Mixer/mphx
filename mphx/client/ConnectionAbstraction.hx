package mphx.client;

class ConnectionAbstraction implements mphx.client.IConnectionAbstraction {
	public var connection:mphx.client.IClient;
	public var events:mphx.client.EventManager;
    public var serializer:mphx.serialization.ISerializer;
	public function new (_connection:mphx.client.IClient){
		connection = _connection;

        serializer = new mphx.serialization.HaxeSerializer();
        events = new EventManager();
	}
	public function send(event:String, ?data:Dynamic) {
		var object = {
			t: event,
			data:data
		};

		var serialiseObject = serializer.serialize(object);

		connection.send(serialiseObject);
	}
	public function onData (data:String){
		var msg = serializer.deserialize(data); //Is the serialized message.

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data);
	}
}
