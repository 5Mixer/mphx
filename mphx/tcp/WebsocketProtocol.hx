package mphx.tcp;

import mphx.tcp.IConnection;

import haxe.crypto.Base64;
import haxe.crypto.Sha1;
import haxe.io.Bytes;
import haxe.io.BytesOutput;
import haxe.io.Input;
import haxe.io.Eof;
import mphx.serialization.ISerializer;

#if neko
import neko.Lib;
#elseif cpp
import cpp.Lib;
#end

using StringTools;

enum Opcode
{
	Continue;
	Text(text:String);
	Binary(data:Bytes);
	Close;
	Ping;
	Pong;
}

/**
* WebSocket protocol (RFC 6455)
*/

class WebsocketProtocol extends mphx.tcp.Connection implements mphx.tcp.IConnection
{


	public function new (events)
	{
		super(events);
		_headers=new Array<String>();
	}

	override public function send(event:String,?data:Dynamic) :Bool
	{
		var object = {
			t: event,
			data:data
		};
		var serialisedObject = serializer.serialize(object);

		var result = cnx.writeBytes(createFrame(Text(serialisedObject)));

		return result;
	}
	override public function onConnect(cnx:NetSock):Void
	{
		super.onConnect(cnx);

		// generate a random key
		var chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		var key = "";
		for (i in 0...10) key += chars.charAt(Std.int(Math.random() * chars.length));
		_key = Base64.encode(Bytes.ofString(key));

		setHeader("Host", _host + ":" + _port);
		setHeader("Upgrade", "websocket");
		setHeader("Connection", "upgrade");
		setHeader("Sec-WebSocket-Key", _key);
		setHeader("Sec-WebSocket-Version", WEBSOCKET_VERSION);
		setHeader("Origin", _origin);

		// send headers
		writeHeader("GET " + _url + " HTTP/1.1");

	}

	function onHandshake():Void
	{
		_useHttp = false;
	}

	/**
	 * Set an HTTP header value
	 * @param String key   The header key value
	 * @param String value The header value
	 */
	function setHeader(key:String, value:String):Void
	{
		_headers.push(key + ": " + value);
	}

	/**
	 * Write out the http header
	 * @param String http The version/status line of the http header
	 */
	function writeHeader(http:String):Void
	{
		_headers.insert(0, http);
		cnx.writeBytes(Bytes.ofString(_headers.join("\r\n") + "\r\n\r\n"));
		_headers = new Array<String>();
	}

	/**
	* When data is received for the protocol this method is called.
	* @param input The input data
	*/
	override public function dataReceived(input:Input):Void
	{
		if (_useHttp) // http protocol
		{
			var line:String;
			var switchProtocols = false;
			while((line = input.readLine()) != "")
			{
				var colon = line.indexOf(":");
				if (colon != -1)
				{
					var key = line.substr(0, colon).trim();
					var value = line.substr(colon + 1).trim();
					if (key == "Sec-WebSocket-Key")
					{
						setHeader("Upgrade", "websocket");
						setHeader("Connection", "upgrade");
						setHeader("Sec-WebSocket-Accept", acceptKey(_key = value));
						switchProtocols = true;
					}
					else if (key == "Sec-WebSocket-Accept")
					{
						if (acceptKey(_key) != value)
						{
							throw "Mismatched key for Sec-WebSocket-Accept";
						}
						switchProtocols = false;
					}
				}
			}
			if (switchProtocols) writeHeader("HTTP/1.1 101 Switching Protocols");
			onHandshake();
		}
		else
		{
			// websocket protocol
			switch (recvFrame(input))
			{
				case Continue: // continuation
				case Text(text): // text
					recvText(text);
				case Binary(bytes): // binary
					recvBinary(bytes);
				case Close: // close
					loseConnection("close connection");
					//cnx.close();
				case Ping: // ping
					cnx.writeBytes(createFrame(Pong)); // send pong
				case Pong: // pong
					// do nothing
			}
		}
	}

	function recvText(text:String):Void { super.recieve(text); }

	function recvBinary(data:Bytes):Void { }


	/**
	* Sends binary data over connection
	*/
	public function sendBinary(bytes:Bytes):Void
	{
		cnx.writeBytes(createFrame(Binary(bytes)));
	}

	/**
	* Sends a frame of data (text, binary, ping)
	* @param opcode  Value of the WebSocket protocol opcode
	* @param bytes   The data to send, if any
	*/
	public static function createFrame(opcode:Opcode):Bytes
	{
		var bytes = null;
		var out = new BytesOutput();

		out.writeByte((switch (opcode) {
			case Continue: OPCODE_CONTINUE;
			case Text(text): bytes = Bytes.ofString(text); OPCODE_TEXT;
			case Binary(data): bytes = data; OPCODE_BINARY;
			case Close: OPCODE_CLOSE;
			case Ping: OPCODE_PING;
			case Pong: OPCODE_PONG;
		}) | 0x80);

		if (bytes == null)
		{
			out.writeByte(0); // zero length since there is no data
		}
		else
		{
			var len = bytes.length;
			if (len < 0x7E)
			{
				out.writeByte(len);
			}
			else if (len < 0xFFFF)
			{
				out.writeByte(0x7E);
				out.writeByte(len >> 8 & 0xFF);
				out.writeByte(len & 0xFF);
			}
			else
			{
				throw "Can't send data this large yet";
			}

			out.writeBytes(bytes, 0, len);
		}

		return out.getBytes();
	}

	/**
	* Reads a complete WebSocket frame
	*/
	private function recvFrame(input:Input):Opcode
	{
		if (_payload == null)
		{

			_opcode = input.readByte();
			_bytesTotal = input.readByte();

			_final = (_opcode & 0x80) != 0; // check byte 0
			_opcode = _opcode & 0x0F;
			var mask = _bytesTotal >> 7 == 1;
			_bytesTotal = _bytesTotal & 0x7F;

			if (_bytesTotal == 126)
			{
				_bytesTotal = (input.readByte() << 8) + input.readByte();
			}
			else if (_bytesTotal > 126)
			{
				var high = (input.readByte() << 24) + (input.readByte() << 16) + (input.readByte() << 8) + input.readByte();
				var low = (input.readByte() << 24) + (input.readByte() << 16) + (input.readByte() << 8) + input.readByte();
				// TODO: prevent data truncation
				_bytesTotal = haxe.Int64.toInt(haxe.Int64.make(high, low));
			}

			_maskKey = (mask ? input.read(4) : null);
			_payload = Bytes.alloc(_bytesTotal);
			_bytesRead = 0;
		}

		_bytesRead += input.readBytes(_payload, _bytesRead, _bytesTotal - _bytesRead);

		if (_bytesRead == _bytesTotal)
		{
			if (_final)
			{
				if (_maskKey != null)
				{
					// unmask data
					for (i in 0..._payload.length)
					{
						_payload.set(i, _payload.get(i) ^ _maskKey.get(i % 4));
					}
				}

				var result = switch (_opcode) {
					case OPCODE_CONTINUE: Continue;
					case OPCODE_TEXT: Text(_payload.toString());
					case OPCODE_BINARY: Binary(_payload);
					case OPCODE_CLOSE: Close;
					case OPCODE_PING: Ping;
					case OPCODE_PONG: Pong;
					default: throw "Unsupported websocket opcode: " + _opcode;
				}
				_payload = null;
				return result;
			}
			else
			{
				if (_lastPayload == null)
				{
					_lastPayload = _payload;
				}
				else
				{
					var b = Bytes.alloc(_lastPayload.length + _payload.length);
					b.blit(0, _lastPayload, 0, _lastPayload.length);
					b.blit(_lastPayload.length, _payload, 0, _payload.length);
					_lastPayload = b;
				}
				_payload = null;
			}
		}

		return Continue;
	}

	private inline function acceptKey(key:String):String
	{
		return Base64.encode(Sha1.make(Bytes.ofString(key + MAGIC_STRING)));
	}

	private var _host:String;
	private var _url:String;
	private var _port:Int;
	private var _key:String;
	private var _origin:String;
	private var _headers:Array<String>;
	private var _useHttp:Bool = true;

	private var _payload:Bytes;
	private var _lastPayload:Bytes;
	private var _bytesRead:Int;
	private var _bytesTotal:Int;
	private var _maskKey:Bytes;
	private var _opcode:Int;
	private var _final:Bool;

	private static inline var WEBSOCKET_VERSION = "13";

	private static inline var OPCODE_CONTINUE = 0x0;
	private static inline var OPCODE_TEXT = 0x1;
	private static inline var OPCODE_BINARY = 0x2;
	private static inline var OPCODE_CLOSE = 0x8;
	private static inline var OPCODE_PING = 0x9;
	private static inline var OPCODE_PONG = 0xA;

	private static inline var MAGIC_STRING:String = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
}
