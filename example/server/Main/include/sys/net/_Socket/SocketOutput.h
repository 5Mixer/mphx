#ifndef INCLUDED_sys_net__Socket_SocketOutput
#define INCLUDED_sys_net__Socket_SocketOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS3(sys,net,_Socket,SocketOutput)
namespace sys{
namespace net{
namespace _Socket{


class HXCPP_CLASS_ATTRIBUTES  SocketOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef SocketOutput_obj OBJ_;
		SocketOutput_obj();
		Void __construct(Dynamic s);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="sys.net._Socket.SocketOutput")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< SocketOutput_obj > __new(Dynamic s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SocketOutput_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("SocketOutput","\x34","\xa3","\xea","\x62"); }

		static void __boot();
		Dynamic __s;
		virtual Void writeByte( int c);

		virtual int writeBytes( ::haxe::io::Bytes buf,int pos,int len);

		virtual Void close( );

		static Dynamic socket_close;
		static Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_send_char;
		static Dynamic &socket_send_char_dyn() { return socket_send_char;}
		static Dynamic socket_send;
		static Dynamic &socket_send_dyn() { return socket_send;}
};

} // end namespace sys
} // end namespace net
} // end namespace _Socket

#endif /* INCLUDED_sys_net__Socket_SocketOutput */ 
