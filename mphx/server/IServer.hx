package mphx.server;
import mphx.connection.IConnection;

interface IServer
{
	public var onConnectionClose : String->IConnection->Void;
	public var onConnectionAccepted : String->IConnection->Void;
	public function start(maxPendingConnection : Int = 1, blocking : Bool = true) : Void;
	private function update(timeout:Float=0) : Void;
}
