#ifndef INCLUDED_mphx_tcp_Connection
#define INCLUDED_mphx_tcp_Connection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(mphx,tcp,Connection)
HX_DECLARE_CLASS2(sys,net,Socket)
namespace mphx{
namespace tcp{


class HXCPP_CLASS_ATTRIBUTES  Connection_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Connection_obj OBJ_;
		Connection_obj();
		Void __construct(::sys::net::Socket socket);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="mphx.tcp.Connection")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Connection_obj > __new(::sys::net::Socket socket);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Connection_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Connection","\x3e","\xa4","\xc3","\xeb"); }

		virtual bool isOpen( );
		Dynamic isOpen_dyn();

		virtual bool writeBytes( ::haxe::io::Bytes bytes);
		Dynamic writeBytes_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		::sys::net::Socket socket;
};

} // end namespace mphx
} // end namespace tcp

#endif /* INCLUDED_mphx_tcp_Connection */ 
