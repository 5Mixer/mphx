package mphx.base;

import mphx.interfaces.Protocol;

class Factory implements mphx.interfaces.Factory
{
	public function new(protocol:Class<Protocol>)
	{
		this.protocol = protocol;
	}

	public function buildProtocol():Protocol
	{
		return Type.createInstance(protocol, []);
	}

	private var protocol:Class<Protocol>;
}
