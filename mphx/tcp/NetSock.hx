package mphx.tcp;

#if flash
import flash.net.Socket;
#elseif !js
import sys.net.Socket;
#end
import haxe.io.Bytes;

#if !js

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
			for (i in 0...bytes.length)
			{
				socket.writeByte(bytes.get(i));
			}
#else
			// if (writeLength) socket.output.writeInt32(bytes.length);
			socket.output.writeBytes(bytes, 0, bytes.length);
#end
		}
		catch (e:Dynamic)
		{
			#if debug
			trace("Error writing to socket: " + e);
			#end
			return false;
		}
		return true;
	}

	public function close()
	{
		socket.close();
		socket = null;
	}

	public var socket:Socket;

}
#else

class NetSock
{

	public function new(socket:Dynamic)
	{
	}

	public function isOpen()
	{
		return true;
	}

	public function writeBytes(bytes:Bytes):Bool
	{
		return true;
	}

	public function close(){

	}


}
#end
