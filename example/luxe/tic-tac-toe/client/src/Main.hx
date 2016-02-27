package;

import luxe.Input;
import luxe.Vector;

import mphx.client.Client;

class Main extends luxe.Game {
    var client :Client = null;
    var my_turn :Bool = false;
    var room_id :String;

    var statusText :luxe.Text;

    override function config(config :luxe.AppConfig) {
        config.render.antialiasing = 2;
        return config;
    }

    override function ready() {
        statusText = new luxe.Text({
            pos: new Vector(Luxe.screen.mid.x, 100),
            text: '',
            point_size: 36,
            align: luxe.Text.TextAlign.center,
            align_vertical: luxe.Text.TextAlign.center,
            color: new luxe.Color(0.8, 0.8, 0.8)
        });

        client = new Client('127.0.0.1', 8000);
		client.connect();

        client.send('join_game');

        client.events.on('game_joined', function(data) {
            room_id = data.room_id;
        });

        client.events.on('game_started', function(_) {
            statusText.text = 'Game started!';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.25, b: 0.1 });
        });

        client.events.on('game_waiting', function(data) {
            statusText.text = 'Waiting for ${data.players_missing} player(s)';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.15, b: 0.15 });
        });

        client.events.on('start_turn', function(data) {
            statusText.text = 'Your turn';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.1, b: 0.25 });
            my_turn = true;
        });

        client.events.on('move', function(data) {
            trace('client: move');
            Luxe.draw.text({
                pos: new Vector(data.pos.x, data.pos.y),
                text: data.symbol,
                point_size: 72,
                align: luxe.Text.TextAlign.center,
                align_vertical: luxe.Text.TextAlign.center
            });
        });

        client.events.on('game_stopped', function(data) {
            statusText.text = 'Game stopped';
        });
    }

    override function onmousedown(e :MouseEvent) {
        if (!my_turn) return;
        statusText.text = '';
        Luxe.renderer.clear_color.tween(0.3, { r: 0.25, b: 0.1 });
        client.send('move', { room_id: room_id, move: { x: e.pos.x, y: e.pos.y } });
        my_turn = false;
    }

    override function onrender() {
        #if cpp
        if (client != null) client.update();
        #end
    }

    override function onkeyup(e :KeyEvent) {
        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }
    }
}
