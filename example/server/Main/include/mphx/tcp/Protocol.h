#ifndef INCLUDED_mphx_tcp_Protocol
#define INCLUDED_mphx_tcp_Protocol

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(mphx,core,EventManager)
HX_DECLARE_CLASS2(mphx,tcp,Connection)
HX_DECLARE_CLASS2(mphx,tcp,Protocol)
namespace mphx{
namespace tcp{


class HXCPP_CLASS_ATTRIBUTES  Protocol_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Protocol_obj OBJ_;
		Protocol_obj();
		Void __construct(::mphx::core::EventManager _events);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="mphx.tcp.Protocol")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Protocol_obj > __new(::mphx::core::EventManager _events);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Protocol_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Protocol","\x78","\x12","\x15","\xda"); }

		::mphx::core::EventManager events;
		virtual Void onConnect( ::mphx::tcp::Connection cnx);
		Dynamic onConnect_dyn();

		virtual Void onAccept( ::mphx::tcp::Connection cnx);
		Dynamic onAccept_dyn();

		virtual Void loseConnection( ::String reason);
		Dynamic loseConnection_dyn();

		::mphx::tcp::Connection cnx;
		virtual bool isConnected( );
		Dynamic isConnected_dyn();

		virtual bool send( ::String event,Dynamic data);
		Dynamic send_dyn();

		virtual Void dataReceived( ::haxe::io::Input input);
		Dynamic dataReceived_dyn();

};

} // end namespace mphx
} // end namespace tcp

#endif /* INCLUDED_mphx_tcp_Protocol */ 
