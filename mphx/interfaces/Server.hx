package mphx.interfaces;

import haxe.io.Bytes;

interface Server
{
	public function broadcast(bytes:Bytes):Bool;
	public function update(timeout:Float=1):Void;
	public function close():Void;
}
