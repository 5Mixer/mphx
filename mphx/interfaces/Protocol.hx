package mphx.interfaces;

import haxe.io.Input;

interface Protocol
{
	public function isConnected():Bool;
	public function onConnect(cnx:Connection):Void;
	public function onAccept(cnx:Connection, server:Server):Void;
	public function loseConnection(?reason:String):Void;
	public function dataReceived(input:Input):Void;
}
