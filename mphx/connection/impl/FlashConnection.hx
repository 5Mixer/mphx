package mphx.connection.impl ;

import haxe.io.Bytes;
import haxe.io.Eof;
import haxe.io.Input;
import haxe.io.Error;
import mphx.connection.IConnection;
import mphx.connection.NetSock;
import mphx.serialization.impl.HaxeSerializer;
import mphx.serialization.ISerializer;
import mphx.server.IServer;
import mphx.server.room.Room;
import mphx.utils.event.impl.ServerEventManager;
import mphx.utils.flash.PolicyFilesProvider;
import mphx.utils.Log;

/**
 * A modified mphx.tcp.connection for managing flash policy files security
 * see : http://help.adobe.com/fr_FR/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7c60.html#WS5b3ccc516d4fbf351e63e3d118a9b90204-7c63
 * This will be removed on a update of the mphx library (perhaps)
 * @author
 */
class FlashConnection implements IConnection
{
	public var events : ServerEventManager;
	public var cnx : NetSock;
	public var serializer : ISerializer;
	public var room : Room = null;
	public var data : Dynamic;

	private var domainAccept : String;
	private var portAccept : Int;

	var server:IServer;

	public function new (_domainAccept : String,  _portAccept : Int)
	{
		domainAccept = _domainAccept;
		portAccept  = _portAccept;
	}

	public function clone() : IConnection
	{
		return new FlashConnection(domainAccept, portAccept);
	}

	public function configure(_events : ServerEventManager, _server:IServer, _serializer : ISerializer = null) : Void
	{
		events = _events;
		server = _server;

		if (_serializer == null)
			this.serializer = new HaxeSerializer();
		else
			serializer = _serializer;
	}


	public function isConnected():Bool { return cnx != null && cnx.isOpen(); }
	public function getContext() :NetSock {return cnx;}

	public function putInRoom (newRoom:Room)
	{
		if (newRoom.full)
			return false;

		if (room != null)
			room.onLeave(this);

		room = newRoom;
		newRoom.onJoin(this);
		return true;
	}

	public function onAccept(cnx:NetSock) : Void
	{
		this.cnx = cnx;

		if (server.onConnectionAccepted != null)
			server.onConnectionAccepted("accept : " + this.getContext().peerToString(), this);
	}

	//difference with onAccept ?
	public function onConnect(cnx:NetSock) : Void
	{
		this.cnx = cnx;

		//if (server.onConnectionAccepted != null)
			//server.onConnectionAccepted("connect : " + this.getContext().peerToString(), this);
	}

	public function loseConnection(?reason:String)
	{
		Log.message(DebugLevel.Networking,"Client disconnected with code: " + reason);

		if (server.onConnectionClose != null)
			server.onConnectionClose(reason, this);

		if (room != null)
			room.onLeave(this);

		if (cnx != null)
		{
			cnx.clean();
			this.cnx = null;
		}
	}

	public function send(event:String, ?data:Dynamic):Bool
	{
		var object = {
			t: event,
			data:data
		};

		var serialiseObject = serializer.serialize(object);
		var result = cnx.writeBytes(Bytes.ofString(serialiseObject + "\r\n"));
		return result;
	}

	public function recieve(line:String)
	{
		//flash specific, if we receive this, we need to return the policy files
		//trace("my line = " + line);
		
		if (line.indexOf("<policy-file-request/>")!=-1)
		{
			cnx.socket.output.writeString(PolicyFilesProvider.generateXmlPolicyFile(PermittedMode.checkAllPort, domainAccept,Std.string(portAccept)).toString());
			cnx.socket.output.flush();
			return;
		}
		
		var msg = serializer.deserialize(line);
		events.callEvent(msg.t,msg.data,this);
	}

	public function dataReceived(input:Input):Void
	{
		//Convert Input to string then process.
		var line = "";
		var done : Bool = false;
		var data : String = "";
		while (!done)
		{
			try
			{
				data = input.readLine();

				try
				{
					recieve(data);
				}
				catch (e:Dynamic)
				{
					Log.message(DebugLevel.Errors | DebugLevel.Networking,"Can't use data: " + data + " because: "+e );
					throw Error.Blocked;
				}
			}
			catch (e : Eof)
			{
				done = true;
			}
			catch (e : Error)
			{
				//nothing special, continue.
			}
			catch (e:Dynamic)
			{
				Log.message(DebugLevel.Errors | DebugLevel.Networking,"Data can't be read because: "+e+". Skipping.");
			}
		}
	}
}
