package;

import massive.munit.util.Timer;
import massive.munit.Assert;
import massive.munit.async.AsyncFactory;
import mphx.server.impl.Server;

class ServerTest
{
	public function new()
	{

	}

	@BeforeClass
	public function beforeClass():Void
	{

	}

	@AfterClass
	public function afterClass():Void
	{
	}

	@Before
	public function setup():Void
	{
	}

	@After
	public function tearDown():Void
	{
	}


	@Test
	public function testRoom():Void
	{
		var server = new mphx.server.impl.Server("127.0.0.1",7272);
		var room = new mphx.server.room.Room();
		server.rooms.push(room);
		Assert.isTrue(server.rooms.length == 1);
	}

	//Test creates a server and a client
	//Server creates event for "Message"
	//Server listens
	//Client connects and sends message with data "123abc"
	//If connection is functional, server will fire event and assertion will hold true.
	@Test
	public function testConnection():Void
	{
		var sentMessage = "123abc";
		var expectedMessage = "123abc";
		var timeout = 5;

		var server = new mphx.server.impl.Server("127.0.0.1",7272);
		var client = new mphx.client.Client("127.0.0.1", 7272);

		var recievedData = "";
		server.events.on("Message",function(data:Dynamic,sender:mphx.connection.IConnection){
			recievedData = data;
		});

		server.listen();
		client.connect();

		client.send("Message",sentMessage);

		var startTime = haxe.Timer.stamp();
		while (true) {

			server.update();

			if (recievedData != ""){
				Assert.areEqual(expectedMessage, recievedData);
				break;
			}

			var messageTime = (haxe.Timer.stamp() - startTime);
			if (messageTime > timeout){
				Assert.fail("Message/connection was not established in time.");
				break;
			}

			Sys.sleep(0.05); // wait for 1 ms to prevent full cpu usage. (0.01)
		}


	}


}
