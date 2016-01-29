#ifndef INCLUDED_haxe_ds_StringMap
#define INCLUDED_haxe_ds_StringMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
namespace haxe{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  StringMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StringMap_obj OBJ_;
		StringMap_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.ds.StringMap")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< StringMap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~StringMap_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		hx::Object *__ToInterface(const hx::type_info &inType);
		operator ::haxe::IMap_obj *();
		::String __ToString() const { return HX_HCSTRING("StringMap","\x2b","\x12","\x8c","\x69"); }

		Dynamic h;
		virtual Void set( ::String key,Dynamic value);
		Dynamic set_dyn();

		virtual Dynamic get( ::String key);
		Dynamic get_dyn();

		virtual bool exists( ::String key);
		Dynamic exists_dyn();

		virtual Dynamic keys( );
		Dynamic keys_dyn();


  inline void set(String key, ::null value) { __string_hash_set(h,key,value); }
  inline void set(String key, bool value) { __string_hash_set(h,key,value); }
  inline void set(String key, char value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, unsigned char value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, signed char value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, short value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, unsigned short value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, int value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, unsigned int value) { __string_hash_set_int(h,key,value); }
  inline void set(String key, float value) { __string_hash_set_float(h,key,value); }
  inline void set(String key, double value) { __string_hash_set_float(h,key,value); }
  inline void set(String key, ::String value) { __string_hash_set_string(h,key,value); }

  template<typename V, typename H>
  inline void set(String key, const ::cpp::Struct<V,H> &value) {__string_hash_set(h,key,value); }
  template<typename V>
  inline void set(String key, const ::cpp::Function<V> &value) {__string_hash_set(h,key,(Dynamic)value ); }
  template<typename V>
  inline void set(String key, const ::cpp::Pointer<V> &value) {__string_hash_set(h,key,(Dynamic)value ); }

  template<typename VALUE>
  inline Void set(Dynamic &key, const VALUE &value) { set( (String)key, value ); return null(); }

};

} // end namespace haxe
} // end namespace ds

#endif /* INCLUDED_haxe_ds_StringMap */ 
