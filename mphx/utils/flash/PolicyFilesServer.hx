package mphx.utils.flash ;
import haxe.macro.Expr.Error;
import sys.net.Host;
import sys.net.Socket;
import mphx.utils.flash.PolicyFilesProvider;


class PolicyFilesServer
{
	private var socket : Socket;

	private var host : String = ""; //my domain
	private var port : Int = 843;
	private var domainAllowed : String = "*";
	private var toPort : String = "*";

	public function new(host : String, domainAllowed : String = "*", toPort : String = "*")
	{
		this.host = host;
		this.domainAllowed = domainAllowed;
		this.toPort = toPort;
	}

	public function start() : Void
	{
		if (host == null || host == "")
		{
			trace("PolicyFilesServer : can't start because of invalid host");
			return;
		}

		socket = new Socket();
		try
		{
			socket.bind(new Host(host), port);
			socket.listen(1);
			socket.setBlocking(false);
		} catch (e:Dynamic)
		{
			trace("PolicyFileServer : start failed on : " + host + ":" + port + " because : " + e);
			return;
		}

		trace("PolicyFileServer : start on : " + host + ":" + port);
	}

	public function update() : Void
	{
		var cnx : Socket = null;

		try
		{
			cnx = socket.accept();
		}
		catch (e : Dynamic)
		{
			cnx = null ;
		}

		if (cnx!=null)
		{
			cnx.waitForRead();
			var read = "";
			var error = "";
			
			while (true)
			{
				
				try
				{
					read += cnx.input.readString(1);
				}
				catch (e : Dynamic)
				{
					error += e;
					break;
				}
				
			}
			
			//trace("PolicyfilesServer read : " + read);
			//trace("PolicyfilesServer error : " + error);

			//sending by default by adobe on Flash.net.socket.connect();
			if (read.indexOf("<policy-file-request/>") !=-1)
			{
				var result = PolicyFilesProvider.generateXmlPolicyFile(domainAllowed, toPort).toString();
				cnx.output.writeString(result);
				cnx.output.flush();
			}
			
			Sys.sleep(0.05);//wait before close for flush
			cnx.close();
		}
	}

	public function close() : Void
	{
		socket.close();
	}
}
