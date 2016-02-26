package mphx.serialization;

/*
	General serialization helper that allows for different serialization methods.
	Serialized objects should not 'build up' like the default haxe serializer does.
*/
interface ISerializer
{
	public function serialize (object:Dynamic):String;
	public function deserialize (string:String):Dynamic;
}
