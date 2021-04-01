package mphx.utils;

@:enum abstract DebugLevel(Int) from Int to Int
{
    var None = 0;
	var Warnings = value(0);  //Large messages, weird behaviour
	var Errors = value(1);    //Socket drops, corrupt data
	var Info = value(2);      //Serialization method, start/stop of server...
	var Networking = value(3);//Every message sent and received.

    static inline function value(index:Int) return 1 << index;
}

class Log {
	public static var debugLevel = DebugLevel.Errors | DebugLevel.Warnings | DebugLevel.Info;
    public static var usePrintLn = #if sys true #else false #end;
    public static var printLevel = true;
    public static var printLocation = true;
	public static function message(level,message, ?infos:haxe.PosInfos){

        var l = "";
        if (printLevel){
            if (level & DebugLevel.Warnings != 0) l += "[Warning]";
            if (level & DebugLevel.Errors != 0) l += "[Error]";
            if (level & DebugLevel.Info != 0) l += "[Info]";
            if (level & DebugLevel.Networking != 0) l += "[Networking]";
            l+=' ';
        }
        var location = "";
        if (printLocation)
            location = infos.fileName+":"+infos.lineNumber + " : ";

        #if sys
            if (debugLevel & level != 0)
                Sys.println(l + location + message);
        #else
            if (debugLevel & level != 0)
                trace(l + location + message);
        #end
	}
}
