package;

import luxe.Input;
import luxe.Vector;

import mphx.client.Client;

class Main extends luxe.Game {
    var client:Client;
    var players:Map<String, Player>;
    var localPlayer:Player;
    var joined:Bool;

    override function config(config :luxe.GameConfig) {
        config.render.antialiasing = 2;

        config.preload.textures.push({ id:'assets/car.png' });

        return config;
    }

    override function ready() {
        joined = false;
        players = new Map<String, Player>();

        client = new Client('127.0.0.1', 8001);
		client.connect();

        localPlayer = new Player(true, { id: "p"+Math.floor(Math.random()*10000), x: 50, y: 50, angle: 0, speed: 0});
        localPlayer.add(new LocalPlayer(client));

        client.send('join', localPlayer.data);

        client.events.on('accepted', function (data : Dynamic) {
            //If it was us being accepted, join the game.
            if (localPlayer.data.id == data.id){
                localPlayer.data.id = data.id;
                localPlayer.receiveData(data);

                players.set(localPlayer.data.id,localPlayer);

                joined = true;
            }else{
                //Someone else joined the game. Register them.
                var remotePlayer = new Player(false, data);
                players.set(remotePlayer.id,remotePlayer);
            }

		});

		client.events.on('update', function (data : Dynamic) {
            if (!joined) return;

            if (players[data.id] == null){
                trace("Player with id "+data.id+" was meant to receive an update but doesn't exist.");
                players.set(data.id,new Player(false, data));
                return;
            }

            if (data.id != localPlayer.data.id)
                players[data.id].receiveData(data);
		});

        client.events.on('keydown', function (data : Dynamic) {
            if (!joined) return;

            if (players[data.id] == null){
                trace("Player with id "+data.id+" was meant to receive an update but doesn't exist.");
                players.set(data.id,new Player(false, {id: data.id, x: 50, y: 50, speed: 0, angle: 0}));
                return;
            }

            trace("Key down "+data.keys);

            if (players[data.id] == null){
                trace("Received keydown event for player "+data.id+" which wasn't registered!");
                return;
            }

            if (data.id != localPlayer.data.id)
                cast(players[data.id].get('car movement'), CarMovement).controls = data.keys;
		});
        client.events.on('keyup', function (data : Dynamic) {
            if (!joined) return;

            if (players[data.id] == null){
                trace("Player with id "+data.id+" was meant to receive an update but doesn't exist.");
                players.set(data.id,new Player(false, {id: data.id, x: 50, y: 50, speed: 0, angle: 0}));
                return;
            }
            trace("Key up "+data.keys);


            if (players[data.id] == null){
                trace("Received keydown event for player "+data.id+" which wasn't registered!");
                return;
            }

            if (data.id != localPlayer.data.id)
                cast(players[data.id].get('car movement'), CarMovement).controls = data.keys;
		});

        Luxe.input.bind_key('up', Key.up);
        Luxe.input.bind_key('up', Key.key_w);

        Luxe.input.bind_key('left', Key.left);
        Luxe.input.bind_key('left', Key.key_a);

        Luxe.input.bind_key('right', Key.right);
        Luxe.input.bind_key('right', Key.key_d);

    }

    override function onrender() {
        client.update();

        if (!joined) return;

        for (id in players.keys()) {
            var player = players[id];

            Luxe.draw.text({
                immediate: true,
                point_size: 11,
                pos: new Vector(player.pos.x, player.pos.y-20),
                text: player.data.id + (player.data.id == localPlayer.data.id ? '(You) ' : ''),
                align: luxe.Text.TextAlign.center,
                align_vertical: luxe.Text.TextAlign.center
            });
        }
    }

    override function onkeyup(e :KeyEvent) {
        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }
    }
}
