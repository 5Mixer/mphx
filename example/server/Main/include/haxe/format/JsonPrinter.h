#ifndef INCLUDED_haxe_format_JsonPrinter
#define INCLUDED_haxe_format_JsonPrinter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS2(haxe,format,JsonPrinter)
namespace haxe{
namespace format{


class HXCPP_CLASS_ATTRIBUTES  JsonPrinter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JsonPrinter_obj OBJ_;
		JsonPrinter_obj();
		Void __construct(Dynamic replacer,::String space);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.format.JsonPrinter")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< JsonPrinter_obj > __new(Dynamic replacer,::String space);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~JsonPrinter_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("JsonPrinter","\x72","\x68","\x9d","\xfd"); }

		::StringBuf buf;
		Dynamic replacer;
		Dynamic &replacer_dyn() { return replacer;}
		::String indent;
		bool pretty;
		int nind;
		virtual Void write( Dynamic k,Dynamic v);
		Dynamic write_dyn();

		virtual Void fieldsString( Dynamic v,Array< ::String > fields);
		Dynamic fieldsString_dyn();

		virtual Void quote( ::String s);
		Dynamic quote_dyn();

		virtual Void quoteUtf8( ::String s);
		Dynamic quoteUtf8_dyn();

		static ::String print( Dynamic o,Dynamic replacer,::String space);
		static Dynamic print_dyn();

};

} // end namespace haxe
} // end namespace format

#endif /* INCLUDED_haxe_format_JsonPrinter */ 
