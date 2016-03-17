package mphx.utils;

/**
 * @author yannsucc
 */
class PolicyFilesProvider
{
	/**
	 * Generate a flash policy files for tcp connection
	 * @param 	mainHost = the main host allowed
	 * @param 	mainport = the main port accepted
	 * @param	domainsPortsAllowed = extra map of domain(key)/port(value) allowed. for port, you can specify a range (8000-8005 for exemple)
	 * use "*" for allow all
	 * @return
	 */
	public static function generateXmlPolicyFile(mainHost : String, mainport : String, domainsPortsAllowed : Map<String,String> = null) : StringBuf
	{
		var str : StringBuf = new StringBuf();
		str.add("<?xml version=\"1.0\"?>");
		str.add("<!DOCTYPE cross-domain-policy SYSTEM \"http://www.adobe.com/xml/dtds/cross-domain-policy.dtd\">");
		str.add("<!-- Policy file for main host xmlsocket://"+mainHost+":"+ mainport +"-->");
		str.add("<cross-domain-policy> " );
		str.add("<site-control permitted-cross-domain-policies=\"master-only\" />");
		str.add("\t<allow-access-from domain=\"" + mainHost + "\" to-ports=\"" + mainport + "\" />" );

		if(domainsPortsAllowed != null)
			for(dpaKey in domainsPortsAllowed.keys())
				str.add("\t<allow-access-from domain=\"" + dpaKey + "\" to-ports=\"" + domainsPortsAllowed.get(dpaKey) + "\" />" );

		str.add("</cross-domain-policy>");
		str.addChar(0); //needed by flash socket
		return str;
	}

}
