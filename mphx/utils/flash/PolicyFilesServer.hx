package mphx.utils.flash ;
import haxe.macro.Expr.Error;
import sys.net.Host;
import sys.net.Socket;
import mphx.utils.flash.PolicyFilesProvider;

/**
 * ...
 * @author
 */
class PolicyFilesServer
{
	private static var m_socket : Socket;

	private static var m_host : String = ""; //my domain
	private static var m_port : Int = 843;
	private static var m_domainAllowed : String = "*";
	private static var m_toPort : String = "*";

	public function new(host : String, domainAllowed : String = "*", toPort : String = "*")
	{
		m_host = host;
		m_domainAllowed = domainAllowed;
		m_toPort = toPort;
	}

	public function start() : Void
	{
		if (m_host == null || m_host == "")
		{
			trace("PolicyFilesServer : can't start because of invalid host");
			return;
		}

		m_socket = new Socket();
		try
		{
			m_socket.bind(new Host(m_host), m_port);
			m_socket.listen(1);
			m_socket.setBlocking(false);
		} catch (e:Dynamic)
		{
			trace("PolicyFileServer : start failed on : " + m_host + ":" + m_port + " because : " + e);
			return;
		}

		trace("PolicyFileServer : start on : " + m_host + ":" + m_port);
	}

	public function update() : Void
	{
		var cnx : Socket = null;
		
		try
		{
			cnx = m_socket.accept();
		}
		catch (e : Dynamic)
		{
			cnx = null ;
		}

		if (cnx!=null)
		{
			cnx.waitForRead();

			//sending by default by adobe on Flash.net.socket.connect();
			if (cnx.input.readString(22) == "<policy-file-request/>")
			{
				var result = PolicyFilesProvider.generateXmlPolicyFile(m_domainAllowed, m_toPort).toString();
				cnx.output.writeString(result);
				cnx.output.flush();
			}
			cnx.close();
		}
	}

	public function close() : Void
	{
		m_socket.close();
	}
}
