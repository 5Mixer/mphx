#ifndef INCLUDED_haxe_format_JsonParser
#define INCLUDED_haxe_format_JsonParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,format,JsonParser)
namespace haxe{
namespace format{


class HXCPP_CLASS_ATTRIBUTES  JsonParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JsonParser_obj OBJ_;
		JsonParser_obj();
		Void __construct(::String str);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.format.JsonParser")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< JsonParser_obj > __new(::String str);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~JsonParser_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("JsonParser","\x47","\x65","\x2e","\x25"); }

		::String str;
		int pos;
		virtual Dynamic parseRec( );
		Dynamic parseRec_dyn();

		virtual ::String parseString( );
		Dynamic parseString_dyn();

		virtual Void invalidChar( );
		Dynamic invalidChar_dyn();

		virtual Void invalidNumber( int start);
		Dynamic invalidNumber_dyn();

};

} // end namespace haxe
} // end namespace format

#endif /* INCLUDED_haxe_format_JsonParser */ 
