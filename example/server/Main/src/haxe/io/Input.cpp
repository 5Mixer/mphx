#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
namespace haxe{
namespace io{

Void Input_obj::__construct()
{
	return null();
}

//Input_obj::~Input_obj() { }

Dynamic Input_obj::__CreateEmpty() { return  new Input_obj; }
hx::ObjectPtr< Input_obj > Input_obj::__new()
{  hx::ObjectPtr< Input_obj > _result_ = new Input_obj();
	_result_->__construct();
	return _result_;}

Dynamic Input_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Input_obj > _result_ = new Input_obj();
	_result_->__construct();
	return _result_;}

int Input_obj::readByte( ){
	HX_STACK_FRAME("haxe.io.Input","readByte",0x4de8a3c2,"haxe.io.Input.readByte","C:\\HaxeToolkit\\haxe\\std/haxe/io/Input.hx",48,0x854a6ecd)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	HX_STACK_DO_THROW(HX_HCSTRING("Not implemented","\x15","\x1e","\x32","\x34"));
	HX_STACK_LINE(48)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readByte,return )

Void Input_obj::close( ){
{
		HX_STACK_FRAME("haxe.io.Input","close",0xfc421af4,"haxe.io.Input.close","C:\\HaxeToolkit\\haxe\\std/haxe/io/Input.hx",87,0x854a6ecd)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,close,(void))

::String Input_obj::readLine( ){
	HX_STACK_FRAME("haxe.io.Input","readLine",0x54789cae,"haxe.io.Input.readLine","C:\\HaxeToolkit\\haxe\\std/haxe/io/Input.hx",171,0x854a6ecd)
	HX_STACK_THIS(this)
	HX_STACK_LINE(172)
	::StringBuf tmp = ::StringBuf_obj::__new();		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(172)
	::StringBuf buf = tmp;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(173)
	int last;		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(174)
	::String s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(175)
	try
	{
	HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
	{
		HX_STACK_LINE(176)
		while((true)){
			HX_STACK_LINE(176)
			int tmp1 = this->readByte();		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(176)
			int tmp2 = last = tmp1;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(176)
			bool tmp3 = (tmp2 != (int)10);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(176)
			bool tmp4 = !(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(176)
			if ((tmp4)){
				HX_STACK_LINE(176)
				break;
			}
			HX_STACK_LINE(177)
			int tmp5 = last;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(177)
			::String tmp6 = ::String::fromCharCode(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(177)
			buf->b->push(tmp6);
		}
		HX_STACK_LINE(178)
		::String tmp1 = buf->b->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(178)
		s = tmp1;
		HX_STACK_LINE(179)
		int tmp2 = (s.length - (int)1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(179)
		Dynamic tmp3 = s.charCodeAt(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(179)
		bool tmp4 = (tmp3 == (int)13);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(179)
		if ((tmp4)){
			HX_STACK_LINE(179)
			::String tmp5 = s.substr((int)0,(int)-1);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(179)
			s = tmp5;
		}
	}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::haxe::io::Eof >() ){
			HX_STACK_BEGIN_CATCH
			::haxe::io::Eof e = __e;{
				HX_STACK_LINE(181)
				::String tmp1 = buf->b->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(181)
				s = tmp1;
				HX_STACK_LINE(182)
				bool tmp2 = (s.length == (int)0);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(182)
				if ((tmp2)){
					HX_STACK_LINE(183)
					::haxe::io::Eof tmp3 = e;		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(183)
					HX_STACK_DO_THROW(tmp3);
				}
			}
		}
		else {
		    HX_STACK_DO_THROW(__e);
		}
	}
	HX_STACK_LINE(185)
	::String tmp1 = s;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(185)
	return tmp1;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readLine,return )


Input_obj::Input_obj()
{
}

Dynamic Input_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"readLine") ) { return readLine_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("readByte","\x7e","\xf9","\x1a","\x69"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	HX_HCSTRING("readLine","\x6a","\xf2","\xaa","\x6f"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Input_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Input_obj::__mClass,"__mClass");
};

#endif

hx::Class Input_obj::__mClass;

void Input_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.io.Input","\xaa","\x0e","\xf5","\x9f");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Input_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

} // end namespace haxe
} // end namespace io
