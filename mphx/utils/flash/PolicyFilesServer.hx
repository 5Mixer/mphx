package mphx.utils.flash ;
import haxe.macro.Expr.Error;
import sys.net.Host;
import sys.net.Socket;
import mphx.utils.flash.PolicyFilesProvider;
import mphx.utils.Log;

class PolicyFilesServer
{
	private var socket : Socket;

	private var host : String = ""; //my domain
	private var port : Int = 843;
	private var domainAllowed : String = "*";
	private var toPort : String = "*";
	private var m_extraAllowed : Map<String,String>;
	private var m_fastSend : Bool;
	
	public var policyFile(default, null) : String;

	public function new(host : String, domainAllowed : String = "*", toPort : String = "*", extraAllowed : Map<String, String> = null,  fastSend : Bool = false)
	{
		this.host = host;
		this.domainAllowed = domainAllowed;
		this.toPort = toPort;
		m_extraAllowed = extraAllowed;
		m_fastSend = false;
		this.policyFile = PolicyFilesProvider.generateXmlPolicyFile(PermittedMode.masterOnly, domainAllowed, toPort, m_extraAllowed).toString();
	}

	public function start() : Void
	{
		if (host == null || host == "")
		{
			Log.message(DebugLevel.Errors,"PolicyFilesServer : can't start because of invalid host");
			return;
		}

		try
		{
			socket = new Socket();
			socket.bind(new Host(host), port);
			socket.listen(10);
			socket.setBlocking(false);
			socket.setFastSend(m_fastSend);
		} catch (e:Dynamic)
		{
			Log.message(DebugLevel.Errors,"PolicyFileServer : start failed on : " + host + ":" + port + " because : " + e);
			return;
		}

		Log.message(DebugLevel.Info,"PolicyFileServer : start on : " + host + ":" + port);
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

			var result = "";

			try
			{
				result = cnx.input.readString(22);
			}
			catch (e : Dynamic)
			{
				Log.message(DebugLevel.Errors,"PolicyfilesServer error : " + e);
			}


			//sending by default by adobe on Flash.net.socket.connect();
			if (result.indexOf("<policy-file-request/>") != -1)
			{
				Log.message(DebugLevel.Info,"PolicyFileServer : send policyFile");
				cnx.output.writeString(this.policyFile);
				cnx.output.writeByte(0);
				cnx.output.flush();
			}
			
			//cnx.close(); // not necessary to close. The client do it after correctly reading the crossdomain.
		}
	}

	public function close() : Void
	{
		socket.close();
	}
}
