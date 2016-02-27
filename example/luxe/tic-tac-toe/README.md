
# Luxe Example: Tic-Tac-Toe

This example demonstrates the following concepts:

* Rooms; automatic room creation and joining, room size requirements and initiating game when requirements are met
* Automatic reconnection attempts if server is unavailable
* Sharing of state, with the majority of game state handling on the server side

## How to run

### Server
1. Go to the `server` directory
2. Run `haxe build.hxml` (builds a _neko_ server per default)

### Client
1. Install [`flow` and `luxe`](http://luxeengine.com/docs/setup.html)
2. Go to the `client` directory
3. Run `haxelib run flow run web` (or `haxelib run flow run` for creating a native app)
4. Repeat as many times as desired
