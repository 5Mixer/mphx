package mphx.tcp;

#if flash
import flash.net.Socket;
#else
import sys.net.Socket;
#end
import haxe.io.Bytes;

//The netsock class is a handeler for the haxe Socket class.
//Pretty much just for a raw socket that is cross platform.
class NetSock
{

	public function new(socket:Socket)
	{
		this.socket = socket;
	}

	public function isOpen()
	{
		return socket != null;
	}

	public function writeBytes(bytes:Bytes):Bool
	{
		try
		{
#if flash
			// if (writeLength) socket.writeInt(bytes.length);
			// for (i in 0...bytes.length)
			// {
			// 	socket.writeByte(bytes.get(i));
			// }
			socket.writeBytes(bytes);
			socket.flush();
#else
			// if (writeLength) socket.output.writeInt32(bytes.length);
			socket.output.writeBytes(bytes, 0, bytes.length);
#end
		}
		catch (e:Dynamic)
		{
			trace("Error writing to socket: " + e);
			return false;
		}
		return true;
	}

	public function close()
	{
		socket = null;
	}

	public var socket:Socket;

}
