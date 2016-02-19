package mphx.tcp;

import haxe.io.Input;

interface IConnection
{
	public function send (event:String,data:Dynamic):Bool;
	public function onConnect(cnx:NetSock):Void;
	public function dataReceived(input:Input):Void;

}
