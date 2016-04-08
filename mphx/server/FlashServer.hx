package mphx.server;
import mphx.server.PolicyFilesServer;
import mphx.server.Server;

import sys.net.Host;
import sys.net.Socket;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.tcp.NetSock;
import mphx.tcp.FlashConnection;

import mphx.server.Room;
import mphx.server.IServer;

/**
 * to use flashconnection.hx instead of mphx.tcp.Connection because of security files
 *  This will perhaps be removed on a update of the mphx library
 * @author yannsucc
 */
class FlashServer extends Server implements IServer
{

	private var m_policyServerRef : PolicyFilesServer;
	public var onConnectionClose:String->mphx.tcp.Connection->Void;

	public function new(hostname : String, port : Int)
	{
		//can't call super because super calls this!
		m_policyServerRef = new PolicyFilesServer(hostname);
		buffer = Bytes.alloc(8192);

		if (hostname == null) hostname = Host.localhost();

		this.host = hostname;
		this.port = port;

		rooms = [];

		listener = new Socket();

		readSockets = [listener];
		clients = new Map();

		//Hacks?? wip code.
		super("0",0);
	}

	override public function start()
	{
		m_policyServerRef.start();
	}


	override public function update(timeout:Float=0):Void
	{
		m_policyServerRef.update();

		var protocol :mphx.tcp.IConnection;
		var bytesReceived:Int;
		var select = Socket.select(readSockets, null, null, timeout);

		for (socket in select.read)
		{
			if (socket == listener)
			{
				var client = listener.accept();
				var netsock = new NetSock(client);

				readSockets.push(client);
				clients.set(client, netsock);

				client.setBlocking(false);
				client.custom = protocol = new FlashConnection(abstractConnectionFactory(),this.host, this.port,this);
				protocol.onAccept(netsock);
			}
			else
			{

				protocol = socket.custom;
				var byte:Int = 0,
				bytesReceived:Int = 0,
				len = buffer.length;
				while (bytesReceived < len)
				{
					try
					{
						byte = #if flash socket.readByte() #else socket.input.readByte() #end;
					}
					catch (e:Dynamic)
					{
						// end of stream
						if (Std.is(e, haxe.io.Eof) || e== haxe.io.Eof)
						{
							protocol.loseConnection("close connection");

							readSockets.remove(socket);
							clients.remove(socket);

							break;
						}else if (e == haxe.io.Error.Blocked){
							//End of message
							break;
						}else{
							trace(e);
						}

					}

					buffer.set(bytesReceived, byte);
					bytesReceived += 1;
				}

				// check that buffer was filled
				if (bytesReceived > 0)
				{
					//check, is message an indication of a websocket connection?
					if (new BytesInput(buffer, 0, bytesReceived).readLine() == "GET / HTTP/1.1"){

						//If so, recreate a protocol of type websocket, for this specific client.
						var socket = protocol.getContext().socket;
						var netsock = new mphx.tcp.NetSock(socket);

						socket.custom = protocol = new mphx.tcp.WebsocketProtocol(abstractConnectionFactory(),this);
						protocol.onAccept(netsock);
					}

					//Let the protocol process the data.
					protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
				}

				if (!protocol.isConnected())
				{
					readSockets.remove(socket);
					clients.remove(socket);
					break;
				}
			}
		}
	}
}
