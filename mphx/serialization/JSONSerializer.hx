package mphx.serialization;


class JSONSerializer implements mphx.serialization.ISerializer
{
	public function new (){

	}
	public function serialize (object:Dynamic):String
	{
		return haxe.Json.stringify(object);
	}
	public function deserialize (string:String):Dynamic
	{
		return haxe.Json.parse(string);
	}
}
