package ;

class Main {
	public function new (){
		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];

		var server = new mphx.server.Server(ip,8000);


		var roomA = new mphx.server.Room();
		server.rooms.push(roomA);

		var roomB = new mphx.server.Room();
		server.rooms.push(roomB);

		var roomC = new mphx.server.Room();
		server.rooms.push(roomC);

		server.events.on("MoveIntoRoom",function(data:Dynamic,sender:mphx.tcp.IConnection){
			trace("Recieved a message from the client.");
			trace("Placing the client in room "+data);

			if (data == "A")
			{
				trace(sender.putInRoom(roomA));
				roomA.broadcast("RoomBroadcast","Someone was put into room A");

			}else if (data == "B")
			{
				trace(sender.putInRoom(roomB));
				roomB.broadcast("RoomBroadcast","Someone was put into room B");

			}else if (data == "C")
			{
				trace(sender.putInRoom(roomC));
				roomC.broadcast("RoomBroadcast","Someone was put into room C");

			}else{
				trace("Client requested to be put into unknown room "+data);
			}

		});

		server.start();
	}
	public static function main (){
		new Main();
	}
}
