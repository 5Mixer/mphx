package mphx.interfaces;

interface Client
{
	public function connect():Void;
	public function update(timeout:Float=1):Void;
	public function close():Void;
}
