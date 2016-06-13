package mphx.server.impl ;

import mphx.connection.IConnection;
import mphx.connection.impl.FlashConnection;
import mphx.serialization.ISerializer;
import mphx.server.impl.Server;
import mphx.server.IServer;
import mphx.utils.flash.PolicyFilesServer;

/**
 * to use flashconnection.hx instead of mphx.tcp.Connection because of security files
 *  This will perhaps be removed on a update of the mphx library
 * @author yannsucc
 */
class FlashServer extends Server implements IServer
{
	private var policyServerRef : PolicyFilesServer;

	public function new(hostname : String, port : Int, _serializer : ISerializer = null, buffer : Int = 8)
	{
		policyServerRef = new PolicyFilesServer(hostname);
		super(hostname, port, new FlashConnection(hostname, port), _serializer, buffer);
	}

	override public function start(maxPendingConnection : Int = 1, blocking : Bool = true)
	{
		policyServerRef.start();
		super.start(maxPendingConnection, blocking);
	}

	override public function update(timeout:Float=0):Void
	{
		policyServerRef.update();
		super.update(timeout);
	}
}
