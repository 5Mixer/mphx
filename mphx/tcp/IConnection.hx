package mphx.tcp;

import haxe.io.Input;

interface IConnection
{
	function send(data:String):Bool;
	function onConnect(cnx:NetSock):Void;
	function onAccept(cnx:NetSock):Void;
	function dataReceived(input:Input):Void;
	function loseConnection(?reason:String):Void;
	function putInRoom (newRoom:mphx.server.Room):Bool;
	function getContext():NetSock;
	function isConnected():Bool;
	var abstraction:mphx.tcp.IConnectionAbstraction;
	var room:mphx.server.Room;
	var data:Dynamic;
}
