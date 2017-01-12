package mphx.connection ;

#if flash
import flash.net.Socket;
#else
import sys.net.Socket;
#end
import haxe.io.Bytes;
import mphx.utils.Log;

//The netsock class is a handeler for the haxe Socket class.
//Pretty much just for a raw socket that is cross platform.
class NetSock
{
	public var socket:Socket;

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
				 for (i in 0...bytes.length)
					socket.writeByte(bytes.get(i));
				socket.flush();
			#else
				socket.output.writeBytes(bytes, 0, bytes.length);
			#end
		}
		catch (e:Dynamic)
		{
			Log.message(DebugLevel.Errors,"Failed writing to socket: "+e);
			return false;
		}
		return true;
	}

	public function readByte() : Int
	{
		#if flash
			return socket.readByte();
		#else
			return socket.input.readByte();
		#end
	}

	public function clean()
	{
		socket = null;
	}

	public function peerToString() : String
	{
		try{
			#if!flash
			var peer = this.socket.peer();
			return "[" + peer.host + ":" + peer.port + "]";
			#else
			//See : http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/flash/net/Socket.html#localAddress
			return "Flash socket can't tell the peer host/port unless the adobe Air runtime";
			
			#end
		}
		catch (e : Dynamic) // in case of the socket was close before call this function
		{
			return "[unknow, unknow] (peer data lost)";
		}
	}
}
