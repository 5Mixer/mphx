mphx is in alpha and has rough edges. It has not been updated or developed in some time - you might like to evaluate other haxe networking libraries that are under active maintenece.


![#mphx](Logo.png)

mphx is a new library made with Haxe to allow for easy creation of multiplayer games. It was based off [HxNet](https://github.com/MattTuttle/hxnet), whose code is authored by [Matt Tuttle](https://github.com/MattTuttle). The code is of a very different structure now. mphx is still 'alpha' and things might break. 

[**Wiki**](https://github.com/5Mixer/mphx/wiki)

-------------

mphx allows for creation of both servers and clients, which connect to each other, sending messages. For the client, it works both natively with TCP sockets and in the browser via websockets.

There are examples in the examples folder, for different libraries. (Basic has no external libraries.)

This library is not be dependent on any graphical library (eg. Haxeflixel, OpenFL etc).

Please raise issues if you find issues, however also check other issues to see if they can help. Thanks!

-------------

### Supported Targets
Client

- [x] Native targets (C++)
- [x] Hashlink
- [x] Web (JS with websockets)
- [x] Neko
- [ ] Flash (Not maintained, but likely functional. Policy File hosting inbuilt.)
- [ ] Mobile (May work, never tested) 

Server

- [x] Native targets (C++)
- [x] Hashlink
- [x] Neko
- [ ] Node JS

### Alternatives.
mphx is one of a few Haxe network libraries.  That said, these libraries do networking a bit different from me, in a way you might prefer.
 - [HxBit](https://github.com/ncannasse/hxbit). By the creator of haxe. Uses macros for field syncronisation. Likely more suitable for large projects than mphx.
 - [HxNet](https://github.com/MattTuttle/hxnet). Hasn't been updated for awhile. Was the base for mphx.
 - [Extention-networking](https://github.com/wikiti/extension-networking). OpenFL specific networking. Hasn't been updated for awhile.
 - [OSIS](https://github.com/Dvergar/OSIS). ECS library with optional network syncronisation.
 - [heaps](https://github.com/ncannasse/heaps/tree/master/hxd/net) has built in networking code, if you're already using Heaps.

### Warnings

 - mphx is **not compatible with haxe version 3.3.0** as a core part of networking code is broken in **haxe 3.3.0**. Versions before/after should be corrected.
 - Performance is lower priority than usability. Ultimately, if you want superfast networking, you should look into UDP and solutions closer to the metal.
 - If `client.connect` is called before error handlers (`client.onConnectionError = function()`) are setup, the error functions won't throw.

--------------

Features:

-  Documentation and examples. (Work in progress)
-  Cross platform, with no changes required.
-  Automatic or manual management of 'rooms'.
-  Event based multiplayer.
-  Abstracted server and client.
-  Ability to share code between server and client.
-  No macro magic, easy to understand.

Pong:
-![](/Pong.gif)
