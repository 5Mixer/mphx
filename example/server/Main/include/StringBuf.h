#ifndef INCLUDED_StringBuf
#define INCLUDED_StringBuf

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)


class HXCPP_CLASS_ATTRIBUTES  StringBuf_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StringBuf_obj OBJ_;
		StringBuf_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="StringBuf")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< StringBuf_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~StringBuf_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("StringBuf","\xc2","\xca","\x83","\x69"); }

		Array< ::String > b;
		virtual Void add( Dynamic x);
		Dynamic add_dyn();

};


#endif /* INCLUDED_StringBuf */ 
