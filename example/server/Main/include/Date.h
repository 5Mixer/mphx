#ifndef INCLUDED_Date
#define INCLUDED_Date

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Date)


class HXCPP_CLASS_ATTRIBUTES  Date_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Date_obj OBJ_;
		Date_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="Date")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Date_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Date_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Date","\x4e","\x82","\x3c","\x2d"); }

		Float mSeconds;
		virtual ::String toString( );
		Dynamic toString_dyn();

};


#endif /* INCLUDED_Date */ 
