package mphx.server.impl ;

// A basic understanding of UDP is important to understand the difference between
// this class and it's tcp oposite. UDP doesn't have 'connections', as TCP abstracts away
// it just sends and recieves stuff, not caring if it gets there or if the connection is established
// thus; connections are mapped from mphx connections to tcp connections, mphx connections are mapped
// to addresses, which are literally just IP's. There is no real 'connection' here.

import mphx.connection.IConnection;
import mphx.connection.UdpNetSock;
import mphx.serialization.ISerializer;
import mphx.server.impl.Server;
import mphx.server.IServer;

import mphx.serialization.impl.HaxeSerializer;

import sys.net.UdpSocket;
import sys.net.Address;
import sys.net.Host;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import haxe.Timer;
import mphx.utils.event.impl.ServerEventManager;

typedef UdpConnection = {
	var timeout:Float;
	var sock:UdpNetSock;
}

class UdpNativeServer implements IServer
{
	public var onConnectionClose : String->IConnection->Void;
	public var onConnectionAccepted : String->IConnection->Void;

	public var host(default, null):String;
	public var port(default, null):Int;
	public var blocking(default, set):Bool = true;

	public var events : ServerEventManager;

	var connectionTemplate : IConnection;
	var serializer : ISerializer;

	var buffer:Bytes;

	var listener:UdpSocket;
	var address:Address;

	var clients:Map<Address,UdpConnection>;


	public function new(hostname:String, port:Int, connectionTemplate : IConnection = null, _serializer : ISerializer = null, bufferSize : Int = 8){
		if (hostname == null)
			hostname = Host.localhost();

		this.host = hostname;
		this.port = port;
		this.connectionTemplate = connectionTemplate;

		if (_serializer == null)
			serializer = new HaxeSerializer();
		else
			serializer = _serializer;

		buffer = Bytes.alloc(1024 * bufferSize);
		events = new ServerEventManager();

		clients = new Map<Address,UdpConnection>();

		listener = new UdpSocket();
		listener.bind(new Host(host),port);
		listener.setBlocking(false);

		//stores last remote Address
		address = new Address();
	}

	public function start(maxPendingConnection : Int = 1, blocking : Bool = true) : Void{
		while (true)
		{
			update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	};
	private function update(timeout:Float=0) {
		for (cnx in clients){

		}
		try {
			var bytesReceived = listener.readFrom(buffer, 0, buffer.length, address);

			//If data was received
			if (bytesReceived > 0) {
				var input = new BytesInput(buffer, 0, bytesReceived);

				var cnx:UdpConnection;
				if (clients.exists(address))
				{
					//If this is an already 'connected' IP just store which 'connection' it is
					cnx = clients.get(address);
				}
				else
				{
					// new connection, as this IP wasn't 'connected'.

					//create IConnection....

					//Connection that is responsible to sending to that address

					var connection = new UdpSocket();
					var sock = new UdpNetSock(connection, address);
					cnx = { sock: sock, timeout: 10 };
					clients.set(address, cnx);
				}
				cnx.timeout = 10;
				//cnx.protocol.dataReceived(input);
			}
		}catch (e:haxe.io.Error)
		{
			if (e == haxe.io.Error.Blocked){
				//trace("Blocked");
			}else{

				throw e;
			}
		}
	}

	public function broadcast(event:String, ?data:Dynamic):Bool
	{
		var success = true;
		for (client in clients)
		{
			if (!client.sock.send(event,data))
			{
				success = false;
			}
		}
		return success;
	}

	public function close()
	{
		listener.close();
	}

	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
		if (listener != null) listener.setBlocking(value);
		return blocking = value;
	}
}
