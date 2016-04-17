package mphx.serialization.impl ;

class JSONSerializer implements ISerializer
{
	public function new() {

	}

	public function serialize(object:Dynamic):String
	{
		return haxe.Json.stringify(object);
	}

	public function deserialize(string:String):Dynamic
	{
		return haxe.Json.parse(string);
	}
}
