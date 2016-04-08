package mphx.client;
import mphx.serialization.ISerializer;
import mphx.client.IClient;

interface IConnectionAbstraction {
	public var serializer:ISerializer;
	public var connection:IClient;
	public function send(event:String,?data:Dynamic) :Void;
	public function onData(line:String):Void;
}
