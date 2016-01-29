#ifndef INCLUDED_haxe_io_BytesInput
#define INCLUDED_haxe_io_BytesInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,BytesInput)
HX_DECLARE_CLASS2(haxe,io,Input)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  BytesInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef BytesInput_obj OBJ_;
		BytesInput_obj();
		Void __construct(::haxe::io::Bytes b,Dynamic pos,Dynamic len);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.io.BytesInput")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< BytesInput_obj > __new(::haxe::io::Bytes b,Dynamic pos,Dynamic len);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BytesInput_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("BytesInput","\xbf","\xcb","\x76","\xe6"); }

		Array< unsigned char > b;
		int pos;
		int len;
		int totlen;
		virtual int readByte( );

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_BytesInput */ 
