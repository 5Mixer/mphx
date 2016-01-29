#ifndef INCLUDED_cpp_Lib
#define INCLUDED_cpp_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(cpp,Lib)
namespace cpp{


class HXCPP_CLASS_ATTRIBUTES  Lib_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lib_obj OBJ_;
		Lib_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="cpp.Lib")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Lib_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Lib_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Lib","\x25","\x07","\x3a","\x00"); }

		static Dynamic load( ::String lib,::String prim,int nargs);
		static Dynamic load_dyn();

};

} // end namespace cpp

#endif /* INCLUDED_cpp_Lib */ 
