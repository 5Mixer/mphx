package mphx.interfaces;

import haxe.io.Bytes;

interface Connection
{
	public function isOpen():Bool;
	public function writeBytes(bytes:Bytes):Bool;
	public function close():Void;
}
