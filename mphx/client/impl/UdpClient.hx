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
	public var address:Address;
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

	public function connect(serverAddress:Address)
	{
		client = new UdpSocket();
		// client.setBlocking(blocking);
		address = serverAddress;


		client.bind(new Host("127.0.0.1"),port);
		client.setBlocking(false);
		trace("UDP client binded to "+this.host+":"+this.port);

		connection = new UdpNetSock(client, address);

		//client.sendTo(Bytes.ofString("Hi!"), 0, 3, address);

	}

	public function send(event:String, ?data:Dynamic){
		connection.send(event,data);

		var object = {
			t: event,
			data:data
		}

		var serialiseObject = 'connection.serializer.serialize(object)';

		var b = Bytes.ofString(serialiseObject);

		trace(address);
		client.sendTo(b, 0, b.length, address);
	}
	public function close(){

	}
	public function update(timeout:Float=0){
		// if (!connected) return;


		var bytesReceived = 0;
		try
		{


			bytesReceived = client.readFrom(buffer, 0, buffer.length, address);

			//client.sendTo(Bytes.ofString("Hi!"), 0, 3, address);

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
			trace(buffer.getString(0,bytesReceived));
			send("Thx for sending me msg!");
			client.sendTo(Bytes.ofString("Reply!"), 0, 6, address);

			//protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
		}
	}
}
