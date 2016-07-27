package mphx.connection;

#if !flash

import sys.net.UdpSocket;
import sys.net.Address;
import haxe.io.Bytes;
import haxe.io.BytesOutput;

class UdpNetSock
{
	var socket:UdpSocket;
	var address:Address;
	var serializer:mphx.serialization.ISerializer;

	public function new(socket:UdpSocket, address:Address)
	{
		this.socket = socket;
		this.address = address.clone();
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
			socket.sendTo(bytes, 0, bytes.length, address);
		}
		catch (e:Dynamic)
		{
			#if debug
			trace("Error writing to udp socket: " + e);
			#end
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
