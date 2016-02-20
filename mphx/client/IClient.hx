package mphx.client;

interface IClient
{
	public function send(event:String, data:Dynamic):Void;
	public function close ():Void;
	public function connect ():Void;
	public function update(timeout:Float=0):Void;
	public var events:mphx.client.EventManager;
}
