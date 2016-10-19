package;

class Main {
    public static function main() {
        var players = new Map<mphx.connection.IConnection,Player>();
		var server = new mphx.server.impl.Server('127.0.0.1', 8001);

        //The join event is responsible for handling new clients.
        server.events.on('join', function(data :Dynamic, client :mphx.connection.IConnection) {

            var id = data.id;
            if (id == null){
                id = "Player "+Math.floor(Math.random()*10000);
            }

            var player = new Player(id, data.x, data.y);
            players.set(client,player);

            server.broadcast('accepted', player);
		});

		server.events.on('update', function(data :Dynamic, client :mphx.connection.IConnection) {
            var p = players.get(client);
            p.x = data.x;
            p.y = data.y;
            p.angle = data.angle;
            p.speed = data.speed;
			server.broadcast('update', p);

            trace("Moved. "+data);
		});
        server.events.on('keydown', function (data:Dynamic, client:mphx.connection.IConnection){
            server.broadcast("keydown",{ id: players.get(client).id, keys: data});
        });
        server.events.on('keyup', function (data:Dynamic, client:mphx.connection.IConnection){
            server.broadcast("keyup",{ id: players.get(client).id, keys: data});
        });

		server.start();
	}
}
