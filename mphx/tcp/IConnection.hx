package mphx.tcp;

import haxe.io.Input;

interface IConnection
{
	function send (event:String,?data:Dynamic):Bool;
	function onConnect(cnx:NetSock):Void;
	function onAccept(cnx:NetSock):Void;
	function dataReceived(input:Input):Void;
	function loseConnection(?reason:String):Void;
	function putInRoom (newRoom:mphx.server.Room):Bool;
	function getContext():NetSock;
	function isConnected():Bool;
	var room:mphx.server.Room;
}
