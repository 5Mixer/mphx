package mphx.client;


typedef Client = #if js mphx.client.WebsocketClient; #else mphx.client.TcpClient; #end
/*{
	public function new (_ip:String,_port:Int):mphx.client.IClient
	{
		throw "Incorrect usage - Use 'mphx.client.Client.Start(IP,PORT), rather than new client.'"
	};

	public static function start (_ip:String,_port:Int)
	{
		#if js
		return new mphx.client.WebsocketClient(_ip,_port);
		#else
		return new mphx.client.TcpClient(_ip,_port);
		#end
	}
}
*/
