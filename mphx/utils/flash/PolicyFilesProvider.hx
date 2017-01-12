package mphx.utils.flash ;

/**
 * @author yannsucc
 */

 
 
 /**
  * The permitted mode enum is necessary to set the "permitted-cross-domain-policy" of the socket cross domain
  * 
  * The flash client socket ask for a socket policy files (crossdomain.xml) in three step :
  * 
  * 1 - Ask the crossdomain on {ip-needed}:843. If this files is not found or "permitted-cross-domain-policy" set to all, 
  * the client socket jump to the step 2. If the "permitted-cross-domain-policy" set to "masterOnly" ans the crossdomain exist on port 843,
  * Step 2 & 3 are not check. If it's set to "none", The client is forbidden to send/receive data from this connection
  * 
  * 2 - Ask the crossdomain on all {ip}:{port} call into a Security.LoadPolicyFile("{ip}:{port}") 
  * if this line of code is call before the socket.connect() on client-side. Else jump to step 3
  * 
  * 3 - Ask the crossdomain on {ip-needed}:{port-needed} => socket.connect({ip-needed}:{port-needed})
  * 
  * masterOnly (default) = autorize domain subscribe into a crossdomain.xml on port 843 (step 1 only)
  * checkAllPort  = autorize to ckeck all crossdomain.xml (step 1 & 2 & 3) 
  * none = forbid all domain 
  */
 enum PermittedMode
 {
	masterOnly;
	checkAllPort;
	none;
 }
 
class PolicyFilesProvider
{
	/**
	 * Generate a flash policy files for tcp connection
	 * @param   set the permitted-cross-domain-policy value. See PermittedMode for more details 
	 * @param 	mainHost = the main host allowed
	 * @param 	mainport = the main port accepted
	 * @param	domainsPortsAllowed = extra map of domain(key)/port(value) allowed. for port, you can specify a range (8000-8005 for exemple)
	 * use "*" for allow all
	 * @return
	 */
	public static function generateXmlPolicyFile(pmode : PermittedMode, mainHost : String, mainport : String, domainsPortsAllowed : Map<String,String> = null) : String
	{
		var str : String = "";
		str += "<?xml version=\"1.0\"?>";
		str += "<!DOCTYPE cross-domain-policy SYSTEM \"http://www.adobe.com/xml/dtds/cross-domain-policy.dtd\">";
		str += "<cross-domain-policy>";
		str += "<site-control permitted-cross-domain-policies=\"" + getPermittedModeStr(pmode) +"\"/>";
		str += "<allow-access-from domain=\"" + mainHost + "\" to-ports=\"" + mainport + "\"/>";

		if(domainsPortsAllowed != null)
			for(dpaKey in domainsPortsAllowed.keys())
				str += "<allow-access-from domain=\"" + dpaKey + "\" to-ports=\"" + domainsPortsAllowed.get(dpaKey) + "\"/>";

		str += "</cross-domain-policy>";
		return str;
	}
	
	private static function getPermittedModeStr(mode : PermittedMode) : String
	{
		switch(mode)
		{
			case PermittedMode.masterOnly : return "master-only";
			case PermittedMode.checkAllPort : return "all";
			case PermittedMode.none : return "none";
			default : return "master-only";
		}
	}

}
