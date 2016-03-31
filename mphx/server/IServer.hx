package mphx.server;

interface IServer {
	public var onConnectionClose:mphx.tcp.IConnection->Void;
}
