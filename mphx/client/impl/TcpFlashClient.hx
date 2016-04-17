#if flash
package mphx.client.impl ;
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
    private var m_client:Socket;

	var messageQueue:Array<Dynamic> = new Array<Dynamic>();

    // all handler for different case (ConnectError, Connect, Server Close, Connection lost for any reason)
    public var onConnectionError : String->Void;
    public var onConnectionEstablished : Void->Void;
    public var onConnectionClose:String->Void; //Server close the connection (with the reason)
    public var onConnectionLost : String->Void; //Client lost the connexion (with the reason)

    private var m_host:String;
    private var m_port:Int;

    var ready = false;

    public function new(host:String, port :Int, _serializer : ISerializer = null, _blocking : Bool = false)
    {
        events = new ClientEventManager();
        m_host = host;
        m_port = port;
		serializer = _serializer == null ? new HaxeSerializer() : _serializer;
    }

    public function isConnected():Bool
    {
        return m_client!=null && m_client.connected;
    }
	
    public function connect():Void
    {
        m_client = new Socket(m_host, m_port);
        //add specific handler for connection
        m_client.addEventListener(Event.CONNECT, onFlashConnectEvent);
        m_client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
        m_client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);
    }

    private function onFlashConnectEvent(event : Event) : Void
    {
        trace("Connection established on : " + m_host +":" + m_port);
        cnx = new NetSock(m_client);
		
        //remove specific handler for connection
        m_client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
        m_client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
        m_client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);

        //add generic Flash event Handler
        m_client.addEventListener(Event.CLOSE, onFlashServerClose);
        m_client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEvent);
        m_client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEvent);
        //maybe add : m_client.addEventListener(ProgressEvent.SOCKET_DATA, *insertCallbackHere* ); but actually, done by update()

		ready = true;
		
        if (onConnectionEstablished != null)
            onConnectionEstablished();
			
        //Send queue
        for (message in messageQueue){
            send(message.t,message.data);
            messageQueue.remove(message);
        }			
    }

    private function onFlashIoErrorEventConnect(event : IOErrorEvent) : Void
    {
        trace("Connection failed on : " + m_host + ":" + m_port + " error : " + event.toString());

        //remove specific handler for connection
        m_client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
        m_client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
        
        if (onConnectionError != null)
            onConnectionError("error:"+event.toString());
    }

    private function onFlashSecurityErrorEventConnect(event : SecurityErrorEvent) : Void
    {
		trace("Connection failed on : " + m_host + ":" + m_port + " error : " + event.toString());
		m_client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);
        if (onConnectionError != null)
            onConnectionError("error:"+event.toString());
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
        var object =
        {
            t: event,
            data:data
        };
		
        if (!ready)
        {
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
				
				if (m_client != null)
					m_client.close();
                m_client = null;
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
        readSocket(m_client);
    }

    private function readSocket(client)
    {
        var buf = new StringBuf();
        var last : Int;
        var line : String = "";

        //try to get RT/LF line
        try
        {
            while((last = m_client.readByte()) != 10)
                buf.addChar(last);

            line = buf.toString();

            if (line.charCodeAt(line.length - 1) == 13)
                line = line.substr(0, -1);

            recieve(line);

        } catch ( e : EOFError )
        {
            //nothing special ?
            //trace("no data on socket");
            //line = buf.toString();
            //if(line.length == 0)
                //throw (new Eof());
        } catch (e : Dynamic)
        {
            trace("unknown error : " + e);
        }
    }

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
