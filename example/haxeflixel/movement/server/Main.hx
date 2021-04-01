package ;

typedef Player = {
	x: Int,
	y: Int,
	id: String
}

class Main {
	public var players:Map<mphx.connection.IConnection,Player>;

	public function new (){
		players = new Map();

		var ip = "127.0.0.1";

		var s = new mphx.server.impl.Server(ip,8000);

		s.events.on("Join",function(data:Dynamic,sender:mphx.connection.IConnection){

			players.set(sender,data);

			s.broadcast("New Player",data);
		});

		s.events.on("Player Move",function (data,sender){
			var player = players.get(sender);
			player.x = data.x;
			player.y = data.y;
			s.broadcast("Player Move",player);
		});

		s.start();
	}

	function makeID () {
		var id = "";
		var charactersToUse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		for (i in 0...6)
		{
			id += charactersToUse.charAt(Math.floor(Math.random()*charactersToUse.length));
		}
		return id;
	}

	public static function main (){
		new Main();
	}
}
