package ;

typedef Player = {
	x: Int,
	y: Int,
	id: String
}

class Main {
	public var players:Map<mphx.tcp.Connection,Player>;

	public function new (){
		players = new Map<mphx.tcp.Connection,Player>();

		var s = new mphx.server.Server("127.0.0.1",8000);

		s.events.on("Join",function(data:Dynamic,sender:mphx.tcp.Connection){


			s.broadcast("New Player",data);
		});

		s.events.on("Player Move",function (data,sender){
			//trace(data);
			if (players.exists(sender) == false){
				var player:Player = {
					x: data.x,
					y: data.y,
					id: data.id
				};
				players.set(sender,player);
			}

			var player = players.get(sender);
			players.get(sender).x = data.x;
			players.get(sender).y = data.y;
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
