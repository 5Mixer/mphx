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
	public var onConnectionError : String->Void;
	public var onConnectionEstablished : Void->Void;
	public var onConnectionClose:String->Void; //Server close the connection (with the reason)
	public var onConnectionLost : String->Void; //Client lost the connexion (with the reason)

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

	/*public function isConnected():Bool
	{
		return client!=null && client.connected;
	}*/

	public function connect():Void
	{
		client = new Socket();
		//add specific handler for connection
		
		client.addEventListener(Event.CONNECT, onFlashConnectEvent);
		client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
		
		if(!client.hasEventListener(SecurityErrorEvent.SECURITY_ERROR))
			client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);
			
		client.connect(host, port);
	}

	//temporisation to wait the policyFiles from the server
	private function waitForPolicyFiles(e: Event)
	{
		Timer.delay(onFlashConnectEvent.bind(e), 100);
	}

	private function onFlashConnectEvent(event : Event) : Void
	{
		trace("Connection established on : " + host +":" + port);
		cnx = new NetSock(client);

		//remove specific handler for connection
		client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
		client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
		client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);

		//add generic Flash event Handler
		client.addEventListener(Event.CLOSE, onFlashServerClose);
		client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEvent);
		client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEvent);
		//maybe add : client.addEventListener(ProgressEvent.SOCKET_DATA, *insertCallbackHere* ); but actually, done by update()

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
		trace("Connection failed on : " + host + ":" + port + " error : " + event.toString());

		//remove specific handler for connection
		client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
		client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);

		if (onConnectionError != null)
			onConnectionError("error:"+event.toString());
	}

	private function onFlashSecurityErrorEventConnect(event : SecurityErrorEvent) : Void
	{
		trace("Flash security error on connection : " + host + ":" + port + " error : " + event.toString());
		//not necessary to call onConnectionError here Because onFlashIoErrorEventConnect was call too on a connection Failed. 
		// Only manage Security error to avoid app crash on connection.
		//if (onConnectionError != null)
			//onConnectionError("error:"+event.toString());
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
		if (isConnected() == false)
		{
			("Cannot sent event "+event+" as client is not connected to a server.");
			return;
		}
		var object =
		{
			t: event,
			data:data
		};

		if (!ready)
		{
			trace("Stock message : " + object);
			messageQueue.push(object);
			return;
		}

		var serialisedObject =  serializer.serialize(object);
		var result = cnx.writeBytes(Bytes.ofString(serialisedObject + "\r\n"));
	}

	private function onFlashServerClose(event : Event) : Void
	{
		trace("server close connection : " + event.toString());
		this.close();

		if (onConnectionClose != null)
			onConnectionClose("Flash connection shut by server.");
	}

	private function loseConnection(reason:String = "") : Void
	{
		trace("Client disconnected with code : " + reason);
		this.close();

		if (onConnectionLost != null)
			onConnectionLost(reason);
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
				trace("Warning, can't close correctly NetSock object : " + e);
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

		} catch ( e : EOFError )
		{
			done = true;
		} catch (e : Dynamic)
		{
			done = true;
			trace("unknown error : " + e);
		}
	}
	
	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }

	public function recieve(line:String) : Void
	{
		var msg = serializer.deserialize(line);

		if (msg.t != null && msg.data != null)
			events.callEvent(msg.t, msg.data);
		else
			trace("can't call event with invalid data");
	}
}
#end
