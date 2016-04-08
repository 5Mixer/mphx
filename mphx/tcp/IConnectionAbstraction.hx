package mphx.tcp;
import mphx.serialization.ISerializer;
import mphx.tcp.IConnection;

interface IConnectionAbstraction {
	public var serializer:ISerializer;
	public var connection:IConnection;
	public var events:mphx.server.EventManager;
	public function send(event:String,data:Dynamic) :Bool;
	public function onData(line:String):Void;
}
