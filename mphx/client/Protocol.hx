package mphx.tcp;

import haxe.io.Input;
import haxe.io.Bytes;

class Connection implements mphx.tcp.IConnection
{
	public var events:mphx.core.EventManager;

	public function new (_events:mphx.client.EventManager){
		events = _events;
	}

	//WARNING: This is server only. Attempting to use rooms on the client is a bad idea!
	//This perhaps needs better structuring, but having a client/server 'Connection' is undesirable.
	public var room:mphx.server.Room = null;

	public function onConnect(cnx:NetSock) { this.cnx = cnx; }
	public function onAccept(cnx:NetSock) { this.cnx = cnx; }

	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }





}
