#ifndef INCLUDED_sys_net__Socket_SocketInput
#define INCLUDED_sys_net__Socket_SocketInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS3(sys,net,_Socket,SocketInput)
namespace sys{
namespace net{
namespace _Socket{


class HXCPP_CLASS_ATTRIBUTES  SocketInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef SocketInput_obj OBJ_;
		SocketInput_obj();
		Void __construct(Dynamic s);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="sys.net._Socket.SocketInput")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< SocketInput_obj > __new(Dynamic s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SocketInput_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("SocketInput","\x37","\xf7","\x80","\xbe"); }

		static void __boot();
		Dynamic __s;
		virtual int readByte( );

		virtual Void close( );

		static Dynamic socket_recv_char;
		static Dynamic &socket_recv_char_dyn() { return socket_recv_char;}
		static Dynamic socket_close;
		static Dynamic &socket_close_dyn() { return socket_close;}
};

} // end namespace sys
} // end namespace net
} // end namespace _Socket

#endif /* INCLUDED_sys_net__Socket_SocketInput */ 
