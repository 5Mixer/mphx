#ifndef INCLUDED_haxe_Utf8
#define INCLUDED_haxe_Utf8

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Utf8)
namespace haxe{


class HXCPP_CLASS_ATTRIBUTES  Utf8_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Utf8_obj OBJ_;
		Utf8_obj();
		Void __construct(Dynamic size);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.Utf8")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Utf8_obj > __new(Dynamic size);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Utf8_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Utf8","\x51","\x81","\x87","\x38"); }

		Array< int > __s;
		virtual Void addChar( int c);
		Dynamic addChar_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static Void iter( ::String s,Dynamic chars);
		static Dynamic iter_dyn();

		static int length( ::String s);
		static Dynamic length_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Utf8 */ 
