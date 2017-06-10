package mphx.connection;

#if !flash

import sys.net.UdpSocket;
import sys.net.Address;
import haxe.io.Bytes;
import haxe.io.BytesOutput;

//Used by both server and client (as really, at the low networking level, there is no difference with UDP.)
//This could be used to represent clients on the server side, or the server on the client side.
class UdpNetSock
{
	var socket:UdpSocket;
	var remoteAddress:Address;
	public var serializer:mphx.serialization.ISerializer;

	public function new(socket:UdpSocket, remoteAddress:Address)
	{
		this.socket = socket;
		this.remoteAddress = remoteAddress.clone();
		this.serializer = new mphx.serialization.impl.HaxeSerializer();
	}

	//this could really be in a connection class that has this class in it.
	public function send (event,data){
		var object = {
			t: event,
			data:data
		}

		var serialiseObject = serializer.serialize(object);

		var b = Bytes.ofString(serialiseObject);
		return writeBytes(b,false);

	}

	public function writeBytes(bytes:Bytes, writeLength:Bool=false):Bool
	{
		try
		{
			if (writeLength)
			{
				var out = new BytesOutput();
				out.prepare(bytes.length);
				out.writeInt32(bytes.length);
				out.writeBytes(bytes, 0, bytes.length);
				bytes = out.getBytes();
			}
			//trace("Writing to "+remoteAddress+" from "+this.socket.host()+" *> "+bytes);
			socket.sendTo(bytes, 0, bytes.length, remoteAddress);
			//trace("Sent data to "+remoteAddress);

		}
		catch (e:Dynamic)
		{
			//#if debug
			throw ("Error writing to udp socket: " + e);
			//#end
			return false;
		}
		return true;
	}

	public function close()
	{
		socket.close();
	}
}

#end
