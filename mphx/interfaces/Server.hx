package mphx.interfaces;

import haxe.io.Bytes;

interface Server
{
	public function broadcast(event:String,data:Dynamic):Bool;
	public function update(timeout:Float=1):Void;
	public function close():Void;
}
