#if flash
package mphx.client.impl ;
import haxe.Timer;
import flash.errors.EOFError;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.events.SecurityErrorEvent;
import flash.net.Socket;
import haxe.io.Bytes;
import mphx.client.IClient;
import mphx.connection.NetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.utils.event.impl.ClientEventManager;
import mphx.utils.Log;

/**
 * yannsucc
 * @author
 */
class TcpFlashClient implements IClient
{
	public var serializer:ISerializer;
	public var events:ClientEventManager;
	public var cnx:NetSock;
	private var client:Socket;

	var messageQueue:Array<Dynamic> = new Array<Dynamic>();

	// all handler for different case (ConnectError, Connect, Server Close, Connection lost for any reason)
	public var onConnectionEstablished : Void->Void;
	public var onConnectionError : mphx.utils.Error.ClientError->Void;
	public var onConnectionClose: mphx.utils.Error.ClientError->Void; //Server close the connection (with the reason)
	public var onConnectionLost : mphx.utils.Error.ClientError->Void; //Client lost the connexion (with the reason)

	private var host:String;
	private var port:Int;

	var ready = false;

	//Send data from output immediently, don't wait for it to queue
	//...will not always be suitable/linked to lower lag!
	//not necessery for flash (maybe delay socket.flush() but client.setFastSend doesn't exist in flash)
	public var fastSend(default, set) = true;
	function set_fastSend(newValue){ fastSend = newValue; return newValue; }

	public function new(host:String, port :Int, _serializer : ISerializer = null, _blocking : Bool = false)
	{
		events = new ClientEventManager();
		this.host = host;
		this.port = port;
		serializer = _serializer == null ? new HaxeSerializer() : _serializer;
	}

	public function isConnected():Bool
	{
		return client!=null && client.connected && cnx != null && cnx.isOpen();
	}

	public function connect():Void
	{
		client = new Socket();
		//add specific handler for connection
		client.addEventListener(Event.CONNECT, onFlashConnectEvent);
		client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
		client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);
		client.connect(host, port);

		Log.message(DebugLevel.Info,"Attempting to connect on: "+host+":"+port);
	}

	//temporisation to wait the policyFiles from the server
	private function waitForPolicyFiles(e: Event)
	{
		Timer.delay(onFlashConnectEvent.bind(e), 100);
	}

	private function onFlashConnectEvent(event : Event) : Void
	{
		Log.message(DebugLevel.Info,"Connected on: "+host+":"+port);
		cnx = new NetSock(client);

		//remove specific handler for connection
		client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
		client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
		client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);

		//add generic Flash event Handler
		client.addEventListener(Event.CLOSE, onFlashServerClose);
		client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEvent);
		client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEvent);

		ready = true;

		if (onConnectionEstablished != null)
			onConnectionEstablished();

		//Send queue
		for (message in messageQueue){
			send(message.t,message.data);
		}

		messageQueue = [];
	}

	private function onFlashIoErrorEventConnect(event : IOErrorEvent) : Void
	{
		Log.message(DebugLevel.Errors,"Failed to connect on: " + host + ":" + port + ". Error: " + event.toString());

		//remove specific handler for connection
		client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
		client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);

		if (onConnectionError != null)
			onConnectionError(mphx.utils.Error.ClientError.Other("error: "+event.toString()));
	}

	private function onFlashSecurityErrorEventConnect(event : SecurityErrorEvent) : Void
	{
		Log.message(DebugLevel.Errors,"Failed to connect on: " + host + ":" + port + ". Error: " + event.toString());
		client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);
		if (onConnectionError != null)
			onConnectionError(mphx.utils.Error.ClientError.Other("error:"+event.toString()));
	}

	private function onFlashIoErrorEvent(event : IOErrorEvent) : Void
	{
		loseConnection(event.toString());
	}

	private function onFlashSecurityErrorEvent(event : SecurityErrorEvent) : Void
	{
		loseConnection(event.toString());
	}

	public function send(event:String, ?data:Dynamic):Void
	{
		if (isConnected() == false){
			Log.message(DebugLevel.Warnings | DebugLevel.Networking,"Cannot sent event "+event+" as client is not connected to a server.");
			return;
		}

		var object = {
			t: event,
			data:data
		};

		if (!ready)
		{
			Log.message(DebugLevel.Networking,"Put "+event+" into message queue. Not ready to send yet.");
			messageQueue.push(object);
			return;
		}

		var serialisedObject =  serializer.serialize(object);
		var result = cnx.writeBytes(Bytes.ofString(serialisedObject + "\r\n"));
	}

	private function onFlashServerClose(event : Event) : Void
	{
		Log.message(DebugLevel.Networking,"Server closed connection with event "+event.toString());
		this.close();

		if (onConnectionClose != null)
			onConnectionClose(mphx.utils.Error.ClientError.Other("Flash connection shut by server."));
	}

	private function loseConnection(reason:String = "") : Void
	{
		Log.message(DebugLevel.Warnings | DebugLevel.Networking,"Client disconnected with reason " + reason);

		this.close();

		if (onConnectionLost != null)
			onConnectionLost(mphx.utils.Error.ClientError.Other(reason));
	}

	public function close():Void
	{
		if (cnx != null)
		{
			try
			{
				this.cnx.clean();
				this.cnx = null;

				if (client != null)
					client.close();
				client = null;
			}
			catch (e : Dynamic)
			{
				Log.message(DebugLevel.Warnings,"Couldn't close NetSock object gracefully :" + e);
			}
		}
	}

	public function update(timeout:Float = 0):Void
	{
		if (!isConnected())
			return;
		readSocket(client);
	}

	private function readSocket(client)
	{
		var buf = new StringBuf();
		var last : Int;
		var line : String = "";
		var done : Bool = false;

		//try to get RT/LF line
		try
		{
			while (!done)
			{
				while((last = client.readByte()) != 10)
					buf.addChar(last);

				line = buf.toString();

				if (line.charCodeAt(line.length - 1) == 13)
					line = line.substr(0, -1);

				recieve(line);
			}

		} catch ( e : EOFError ) {
			done = true;
		} catch (e : Dynamic) {
			done = true;
			Log.message(DebugLevel.Warnings,"Unknown problem reading socket "+e);
		}
	}


	public function recieve(line:String) : Void
	{
		var msg = serializer.deserialize(line);

		if (msg.t != null)
			events.callEvent(msg.t, msg.data);
		else
			Log.message(DebugLevel.Warnings | DebugLevel.Networking,"Could call event, invalid data received. Data: "+msg);
	}
}
#end
