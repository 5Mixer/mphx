package ;

typedef PlayerData = {
	x: Int,
	y: Int,
	dir: Float,
	speed: Float,
	id: String
};


class Main {
	var server:mphx.server.impl.Server;
	public function new ()
	{
		server = new mphx.server.impl.Server("127.0.0.1",8000);

		server.events.on("Join", function(data:Dynamic,sender:mphx.connection.IConnection)
		{
			trace("Player: "+data.id+" has joined!");

			sender.data = {
				x: data.x,
				y: data.y,
				dir: data.dir,
				id: data.id,
				speed: data.speed
			};
			server.broadcast("Join",data);
		});
		server.events.on("Update",function(data:Dynamic,sender:mphx.connection.IConnection)
		{
			sender.data = data;
			server.broadcast("Update",data);
		});
		server.events.on("Shoot",function(data:Dynamic,sender:mphx.connection.IConnection)
		{
			server.broadcast("NB",data);
		});
		server.start();
	}
	public static function main ()
	{
		new Main();
	}
}
