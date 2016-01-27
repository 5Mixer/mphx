package mphx.base;

import mphx.interfaces.Connection;
import mphx.interfaces.Server;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import haxe.io.Eof;
import haxe.io.Input;

class Protocol implements mphx.interfaces.Protocol
{

	public function new()
	{
		_packetLength = _packetPos = 0;
	}

	public function isConnected():Bool { return this.cnx != null && this.cnx.isOpen(); }

	public function dataReceived(input:Input):Void
	{
		if (_packetPos > 0)
		{
			readPacket(input);
		}

		while (initPacket(input))
		{
			readPacket(input);
		}
	}

	private function packetReceived(input:Input):Void
	{

	}

	private function initPacket(input:Input):Bool
	{
		try
		{
			_packetLength = input.readInt32();
			if (_packetLength == 0) return false;
			_packet = Bytes.alloc(_packetLength);
		}
		catch (e:Eof)
		{
			return false;
		}
		catch (e:Dynamic)
		{
			trace(e);
			return false;
		}
		return true;
	}

	private inline function readPacket(input:Input):Bool
	{
		var finish = true, byte:Int = 0;
		while (finish)
		{
			try
			{
				byte = input.readByte();
			}
			catch (e:Eof)
			{
				finish = false;
			}
			_packet.set(_packetPos, byte);
			_packetPos += 1;

			if (_packetPos >= _packetLength)
			{
				var input = new BytesInput(_packet);
				packetReceived(input);
				_packetPos = 0;
				break;
			}
		}
		return finish;
	}

	public function onConnect(cnx:Connection) { this.cnx = cnx; }
	public function onAccept(cnx:Connection, server:Server) { this.cnx = cnx; this.server = server; }

	public function loseConnection(?reason:String) { this.cnx = null; }

	public var cnx:Connection;
	private var server:Server;

	private var _packetLength:Int;
	private var _packetPos:Int;
	private var _packet:Bytes;
}
