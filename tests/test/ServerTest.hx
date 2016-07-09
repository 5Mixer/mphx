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

	@Test
	public function testConnection():Void
	{
		var server = new mphx.server.impl.Server("127.0.0.1",7272);
		var client = new mphx.client.Client("127.0.0.1", 7272);



		var time = haxe.Timer.stamp();
		var serverRun = true;

		server.events.on("Message",function(data:Dynamic,sender:mphx.connection.IConnection){
			Assert.isTrue(data == "123abc");
			serverRun = false;
		});

		server.listen();


		client.connect();
		client.send("Message","123abc");

		while (serverRun) {

			server.update();
			update(haxe.Timer.stamp() - time);

			time = haxe.Timer.stamp();
			Sys.sleep(0.05); // wait for 1 ms to prevent full cpu usage. (0.01)
		}

	}


}
