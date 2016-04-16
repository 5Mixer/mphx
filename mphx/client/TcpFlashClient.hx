#if flash
package mphx.client;
import flash.errors.EOFError;
import flash.events.SecurityErrorEvent;
import flash.events.IOErrorEvent;
import flash.events.Event;

import flash.net.Socket;
import haxe.io.Bytes;
import mphx.client.EventManager;
import mphx.client.IClient;
import mphx.serialization.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.tcp.NetSock;

/**
 * yannsucc
 * @author
 */
class TcpFlashClient implements IClient
{

    public var serializer:ISerializer;
    public var events:EventManager;
    private var buffer:Bytes;

    public var cnx:NetSock;
    private var m_client:Socket;

	var messageQueue:Array<Dynamic> = new Array<Dynamic>();

    private var m_readSockets:Array<Socket>; // utility ?

    // all handler for different case (ConnectError, Connect, Server Close, Connection lost for any reason)
    public var onConnectionError : Void->Void;
    public var onConnectionEstablished : Void->Void;
    public var onConnectionClose:String->Void; //String is the reason for the close.
    public var onConnectionLost : Void->Void;

    private var m_host:String;
    private var m_port:Int;

    var ready = false;

    public function new(host:String, port :Int)
    {
		trace("Start of new()");
        serializer = new HaxeSerializer();
        events = new EventManager();
        buffer = Bytes.alloc(8192); //no utility ?
        m_host = host;
        m_port = port;
    }

    public function isConnected():Bool
    {
        return m_client!=null && m_client.connected;//cnx != null && cnx.isOpen();
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


        // prevent recreation of array on every update
        m_readSockets = [m_client];
        cnx = new NetSock(m_client);

        ready = true;

        //Send queue
        for (message in messageQueue){
            send(message.t,message.data);
            messageQueue.remove(message);
        }

        //remove specific handler for connection
        m_client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
        m_client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
        m_client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);

        //add generic Flash event Handler
        m_client.addEventListener(Event.CLOSE, onFlashServerClose);
        m_client.addEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEvent);
        m_client.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEvent);
        //maybe add : m_client.addEventListener(ProgressEvent.SOCKET_DATA, *insertCallbackHere* ); but actually, done by update()


        if (onConnectionEstablished != null)
            onConnectionEstablished();
    }

    private function onFlashIoErrorEventConnect(event : IOErrorEvent) : Void
    {
        trace("Connection failed on : " + m_host +":" + m_port + " error : " + event.toString());

        //remove specific handler for connection
        m_client.removeEventListener(Event.CONNECT, onFlashConnectEvent);
        m_client.removeEventListener(IOErrorEvent.IO_ERROR, onFlashIoErrorEventConnect);
        m_client.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, onFlashSecurityErrorEventConnect);

        if (onConnectionError != null)
            onConnectionError();
    }

    private function onFlashSecurityErrorEventConnect(event : SecurityErrorEvent) : Void
    {
        trace("Connection failed on : " + m_host +":" + m_port + " error : " + event.toString());
        if (onConnectionError != null)
            onConnectionError();
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
        //trace("Result "+result);
    }

    private function onFlashServerClose(event : Event) : Void
    {
        trace("server close connection : " + event.toString());
        this.close();

        if (onConnectionClose != null)
            onConnectionClose("Flash connection shut by server.");

        if (onServerClose != null)
            onServerClose();
    }

    private function loseConnection(reason:String = "") : Void
    {
        trace("Client disconnected with code : " + reason);
        this.close();

        if (onConnectionClose != null)
            onConnectionClose(reason);

        if (onConnectionLost != null)
            onConnectionLost();
    }

    public function close():Void
    {

        if (cnx != null)
        {
            //this object contains a reference of the m_client socket and try to close it.
            //this object must only remove the reference (client = null) and don't try to close the socket.
            // only this Class (Tcpclient) must do it.
            //so i put an ugly trick
            try
            {
                this.cnx.close();
                this.cnx = null;
                m_client = null;
            } catch (e : Dynamic)
            {
                trace("Warning, can't close correctly NetSock object : " + e);
            }
        }

        this.cnx = null;

        //ugly :(
        try
        {
            if (m_client != null) //only if the NetSock object (cnx) faile close the socket
            {
                m_client.close();
                m_client = null;
            }
        }catch (e:Dynamic)
        {
            trace("Warning, can't close socket : " + e);
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

		//trace(line + " was recieved");
        //Then convert the string to a Dynamic object.
        var msg = serializer.deserialize(line);
        //The message will have a propety of T
        //This is the event name/type. It is t to reduce wasted banwidth.
        //call an event called 't' with the msg data.
        events.callEvent(msg.t,msg.data);
    }
}
#end
