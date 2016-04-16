package mphx.connection ;

import haxe.io.Input;
import mphx.serialization.ISerializer;
import mphx.server.IServer;
import mphx.server.room.Room;
import mphx.utils.event.impl.ServerEventManager;

interface IConnection
{
	public function clone() : IConnection;
	public function send (event:String,?data:Dynamic):Bool;
	public function onConnect(cnx:NetSock):Void;
	public function onAccept(cnx:NetSock):Void;
	public function dataReceived(input:Input):Void;
	public function loseConnection(?reason:String):Void;
	public function putInRoom (newRoom:mphx.server.room.Room):Bool;
	public function getContext():NetSock;
	public function isConnected():Bool;
	public function configure(_events : ServerEventManager, _server:IServer, _serializer : ISerializer = null): Void;
	public var room:Room;
	public var data:Dynamic;
}
