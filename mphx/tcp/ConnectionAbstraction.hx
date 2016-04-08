package mphx.tcp;

import mphx.serialization.ISerializer;

/* Sometimes it would be nice to completly change the behaviour of a connection.
	Maybe you want to handle events yourself.
	Maybe you want to store data with every connection.
	But you can't just extend Connection, because there are multiple connection classes.
	Instead, you should extend ConnectionAbstraction.

	Connections contain a factory, which creates these. The factory can pass extra data to the connection abstraction.

*/
class ConnectionAbstraction implements mphx.tcp.IConnectionAbstraction {

	public var serializer:ISerializer;
	public var connection:IConnection;
	public var events:mphx.server.EventManager;

	public function new (_connection:IConnection){
		serializer = new mphx.serialization.HaxeSerializer();
		connection = _connection;

		events = new mphx.server.EventManager();
	}

	public function send(event:String,data:Dynamic) :Bool
	{
		var object = {
			t: event,
			data:data
		};
		var serialisedObject = serializer.serialize(object);

		return connection.send(serialisedObject);
	}

	public function onData(line:String){
		//Transfer the Input data to a string

		//Then convert the string to a Dynamic object.
		var msg = serializer.deserialize(line);

		//The message will have a propety of T
		//This is the event name/type. It is t to reduce wasted banwidth.
		//call an event called 't' with the msg data.
		events.callEvent(msg.t,msg.data,this);

	}

}
