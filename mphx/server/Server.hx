package mphx.server;

#if !flash

import sys.net.Host;
import sys.net.Socket;
import haxe.io.Bytes;
import haxe.io.BytesInput;
import mphx.tcp.Connection;


class Server
{

	public var host(default, null):String;
	public var port(default, null):Int;
	public var blocking(default, set):Bool = true;

	public var events:mphx.core.EventManager;

	public function new(hostname:String,port:Int)
	{
		buffer = Bytes.alloc(8192);

		if (hostname == null) hostname = Host.localhost();

		this.host = hostname;
		this.port = port;

		events = new mphx.core.EventManager();

		listener = new Socket();

		readSockets = [listener];
		clients = new Map<Socket, Connection>();
	}

	public function listen()
	{
		listener.bind(#if flash host #else new Host(host) #end, port);
		listener.listen(1);
		listener.setBlocking(false);
	}

	public function start () {

		trace("Server active. Anycode after this point will not run, your app will hang.");
		trace("You can instead call 'update' frequently, and run your code along side it.");

		listen();
		while (true) {
			update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	}

	public function update(timeout:Float=0):Void
	{
		//trace("Start update");
		var protocol:mphx.tcp.Protocol;
		var bytesReceived:Int;
		var select = Socket.select(readSockets, null, null, timeout);

		for (socket in select.read)
		{
			if (socket == listener)
			{
				var client = listener.accept();
				var connection = new Connection(client);

				readSockets.push(client);
				clients.set(client, connection);

				client.setBlocking(false);
				client.custom = protocol = new mphx.tcp.Protocol(events);
				protocol.onAccept(connection);
			}
			else
			{
				trace("CONNECTION UPDATING!!");

				protocol = socket.custom;

				var byte:Int = 0,
				bytesReceived:Int = 0,
				len = buffer.length;
				while (bytesReceived < len)
				{
					trace("loop");
					try
					{

						byte = #if flash socket.readByte() #else socket.input.readByte() #end;
					}
					catch (e:Dynamic)
					{
						trace("CATCH");
						// end of stream
						if (Std.is(e, haxe.io.Eof) || e== haxe.io.Eof)
						{
							trace("EOF");

							readSockets.remove(socket);
							clients.remove(socket);

							break;
						}else if (e == haxe.io.Error.Blocked){
							trace("BLOCKED");
							//trace("Blocking error. Something would've caused the server to block, and was thrown.
							//       -  set blocking to true on server!");


							//End of message
							break;
						}else{
							trace(e);
						}
					}
					if (byte == 0) break;

					buffer.set(bytesReceived, byte);
					bytesReceived += 1;
				}

				// check that buffer was filled
				if (bytesReceived > 0)
				{
					protocol.dataReceived(new BytesInput(buffer, 0, bytesReceived));
				}
				if (!protocol.isConnected())
				{
					trace("NOT CONNECTED");
					//readSockets.remove(socket);
					//clients.remove(socket);
					break;
				}
			}
		}
		//trace("End update");
	}

	public function broadcast(event:String,data:Dynamic):Bool
	{
		var success = true;
		for (client in clients)
		{
			if (!cast(client.socket.custom,mphx.tcp.Protocol).send(event,data))
			{
				success = false;
			}
		}
		return success;
	}

	public function close()
	{
		trace("CLOSED");
		listener.close();
	}

	private function set_blocking(value:Bool):Bool
	{
		if (blocking == value) return value;
		if (listener != null) listener.setBlocking(value);
		return blocking = value;
	}

	private var readSockets:Array<Socket>;
	private var clients:Map<Socket, Connection>;
	private var listener:Socket;

	private var buffer:Bytes;

}

#end
