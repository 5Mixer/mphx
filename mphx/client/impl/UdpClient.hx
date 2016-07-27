package mphx.client.impl;

import haxe.io.Bytes;
import haxe.io.Input;
import mphx.connection.UdpNetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.utils.event.impl.ClientEventManager;
import sys.net.Host;
import sys.net.UdpSocket;
import sys.net.Address;

class UdpClient {

	public var onConnectionError:String->Void;
	public var onConnectionClose:String->Void; //String arg is the reason for termination. May or not be useful.
	public var onConnectionEstablished:Void->Void;
	public var events:ClientEventManager;
	public var serializer:ISerializer;

	private var connection:UdpNetSock;
	private var client:UdpSocket;
	private var buffer:Bytes;
	// connection info
	private var address:Address;
	var host:String;
	private var port:Int;

	public function new (?hostname:String, port:Int, _serializer : ISerializer = null){

		buffer = Bytes.alloc(8192);

		if (hostname == null)
			hostname = Host.localhost();



		this.host = hostname;
		this.port = port;

		events = new ClientEventManager();

		if (_serializer != null)
			serializer = _serializer;
		else
			serializer = new HaxeSerializer();

	}

	function dot2num(dot:String)
	{
	    var parts = dot.split(".");
		return ((16777216 * Std.parseInt(parts[0])) + (65536 *  Std.parseInt(parts[1])) + (256 *  Std.parseInt(parts[2])) +  Std.parseInt(parts[3]));
	}

	public function connect()
	{
		client = new UdpSocket();
		// client.setBlocking(blocking);
		address = new Address();
		address.host = 2130706433;//dot2num("127.0.0.1");
		address.port = port;


		client.bind(new Host("127.0.0.1"),port);

		connection = new UdpNetSock(client, address);
	}

	public function send(event:String, ?data:Dynamic){
		connection.send(event,data);
	}
	public function close(){

	}
	public function update(timeout:Float=0){
		// if (!connected) return;

		var bytesReceived = 0;
		try
		{
			bytesReceived = client.readFrom(buffer, 0, buffer.length, address);
		}
		catch (e:haxe.io.Eof)
		{
			throw "disconnect";
			//protocol.loseConnection("disconnected");
			client.close();
			client = null;
		}
		catch (e:haxe.io.Error)
		{
			// End of stream
		}

		if (bytesReceived > 0)
		{
			//protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
		}
	}
}
