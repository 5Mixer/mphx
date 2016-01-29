#ifndef INCLUDED_mphx_server_Server
#define INCLUDED_mphx_server_Server

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(mphx,core,EventManager)
HX_DECLARE_CLASS2(mphx,server,Server)
HX_DECLARE_CLASS2(sys,net,Socket)
namespace mphx{
namespace server{


class HXCPP_CLASS_ATTRIBUTES  Server_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Server_obj OBJ_;
		Server_obj();
		Void __construct(::String hostname,int port);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="mphx.server.Server")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Server_obj > __new(::String hostname,int port);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Server_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Server","\xe3","\xbe","\xcb","\xa2"); }

		::String host;
		int port;
		bool blocking;
		::mphx::core::EventManager events;
		virtual Void listen( );
		Dynamic listen_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void update( hx::Null< Float >  timeout);
		Dynamic update_dyn();

		virtual bool broadcast( ::String event,Dynamic data);
		Dynamic broadcast_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual bool set_blocking( bool value);
		Dynamic set_blocking_dyn();

		Array< ::Dynamic > readSockets;
		::haxe::ds::ObjectMap clients;
		::sys::net::Socket listener;
		::haxe::io::Bytes buffer;
};

} // end namespace mphx
} // end namespace server

#endif /* INCLUDED_mphx_server_Server */ 
