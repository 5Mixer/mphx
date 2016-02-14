package mphx.client;


class Client
{
	public function new (){};

	public static function start (_ip:String,_port:Int)
	{
		#if js
		return new mphx.client.WebsocketClient(_ip,_port);
		#else
		return new mphx.client.TcpClient(_ip,_port);
		#end
	}
}
