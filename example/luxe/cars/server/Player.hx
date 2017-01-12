package ;

class Player {
	public var x:Int;
	public var y:Int;

	public var id:String;

	public var angle:Int;
	public var speed:Int;

	public function new (id,x,y){
		this.x = x;
		this.y = y;
		this.id = id;

		this.angle = 0;
		this.speed = 0;
	}
}
