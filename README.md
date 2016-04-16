Alpha. Rough edges everywhere, but they're being refined.


![#MPHX](Logo.png)

MpHx is a new library made with Haxe to allow for easy creation of multiplayer games. It was based off [HxNet](https://github.com/MattTuttle/hxnet), whose code is authored by [Matt Tuttle](https://github.com/MattTuttle). The code is of a very different structure now. MPHX is still 'alpha' and things might break. But give it a try, it will only make the library better. Feel free to contribute or create issues, even if your changes seem small!

[**Wiki**](https://github.com/5Mixer/mphx/wiki)

-------------

MpHx allows for creation of both servers and clients, which connect to each other, sending messages. For the client, it works both natively and in the browser, with websockets, without you having to change a thing.

There are examples in the examples folder, for different libraries. (Basic has no external libraries.)

This library is not be dependent on any 'graphical' library (eg. Haxeflixel, Open FL or Luxe). If you want to, you can make a text based multiplayer game that runs in the terminal!

[![Join the chat at https://gitter.im/5Mixer/mphx](https://badges.gitter.im/5Mixer/mphx.svg)](https://gitter.im/5Mixer/mphx?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

-------------

###Supported Targets
Client

- [x] Native targets (C++)
- [x] Web (JS with websockets)
- [x] Neko
- [ ] Flash (In progress - See issues.)
- [ ] Mobile (Should work, however never tested) 

Server

- [x] Native targets (C++)
- [x] Neko
- [ ] Node JS


--------------

Features (planned or avaliable):

-  Documentation (Work in progress)
-  Cross platform, with no changes required.
-  Automatic or manual management of 'rooms'.
-  Event based multiplayer.
-  Highly abstracted server and client, without bloating or taking away control.
-  Easy creation of 'packets' or data objects.
-  Ability to share code between server and client.


-![](/Pong.gif)
