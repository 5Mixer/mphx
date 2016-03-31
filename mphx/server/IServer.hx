package mphx.server;

interface IServer {
	public var onConnectionClose:mphx.tcp.Connection->Void;
}
