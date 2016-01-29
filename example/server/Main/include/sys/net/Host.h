#ifndef INCLUDED_sys_net_Host
#define INCLUDED_sys_net_Host

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(cpp,Lib)
HX_DECLARE_CLASS2(sys,net,Host)
namespace sys{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Host_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Host_obj OBJ_;
		Host_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="sys.net.Host")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Host_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Host_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		static void __init__();

		::String __ToString() const { return HX_HCSTRING("Host","\x88","\xfb","\xeb","\x2f"); }

		static void __boot();
		int ip;
		static ::String localhost( );
		static Dynamic localhost_dyn();

		static Dynamic host_resolve;
		static Dynamic &host_resolve_dyn() { return host_resolve;}
		static Dynamic host_local;
		static Dynamic &host_local_dyn() { return host_local;}
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Host */ 
