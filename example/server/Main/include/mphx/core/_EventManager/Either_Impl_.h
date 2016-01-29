#ifndef INCLUDED_mphx_core__EventManager_Either_Impl_
#define INCLUDED_mphx_core__EventManager_Either_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,ds,Either)
HX_DECLARE_CLASS3(mphx,core,_EventManager,Either_Impl_)
namespace mphx{
namespace core{
namespace _EventManager{


class HXCPP_CLASS_ATTRIBUTES  Either_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Either_Impl__obj OBJ_;
		Either_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="mphx.core._EventManager.Either_Impl_")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Either_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Either_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Either_Impl_","\xc5","\xa7","\xa2","\xc9"); }

		static ::haxe::ds::Either _new( ::haxe::ds::Either e);
		static Dynamic _new_dyn();

		static ::haxe::ds::Either get_type( ::haxe::ds::Either this1);
		static Dynamic get_type_dyn();

		static ::haxe::ds::Either fromLeft( Dynamic left);
		static Dynamic fromLeft_dyn();

		static ::haxe::ds::Either fromRight( Dynamic right);
		static Dynamic fromRight_dyn();

};

} // end namespace mphx
} // end namespace core
} // end namespace _EventManager

#endif /* INCLUDED_mphx_core__EventManager_Either_Impl_ */ 
