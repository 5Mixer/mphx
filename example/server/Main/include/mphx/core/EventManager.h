#ifndef INCLUDED_mphx_core_EventManager
#define INCLUDED_mphx_core_EventManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,Either)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(mphx,core,EventManager)
HX_DECLARE_CLASS2(mphx,tcp,Protocol)
namespace mphx{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  EventManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventManager_obj OBJ_;
		EventManager_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="mphx.core.EventManager")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< EventManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventManager_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("EventManager","\x93","\xd5","\x28","\x6c"); }

		::haxe::ds::StringMap eventMap;
		virtual Void on( ::String eventName,::haxe::ds::Either event);
		Dynamic on_dyn();

		virtual Void callEvent( ::String eventName,Dynamic data,::mphx::tcp::Protocol sender);
		Dynamic callEvent_dyn();

};

} // end namespace mphx
} // end namespace core

#endif /* INCLUDED_mphx_core_EventManager */ 
