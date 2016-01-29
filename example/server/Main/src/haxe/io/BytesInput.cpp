#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
namespace haxe{
namespace io{

Void BytesInput_obj::__construct(::haxe::io::Bytes b,Dynamic pos,Dynamic len)
{
HX_STACK_FRAME("haxe.io.BytesInput","new",0x7fa18571,"haxe.io.BytesInput.new","C:\\HaxeToolkit\\haxe\\std/haxe/io/BytesInput.hx",38,0xd7d0a806)
HX_STACK_THIS(this)
HX_STACK_ARG(b,"b")
HX_STACK_ARG(pos,"pos")
HX_STACK_ARG(len,"len")
{
	HX_STACK_LINE(39)
	bool tmp = (pos == null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(39)
	if ((tmp)){
		HX_STACK_LINE(39)
		pos = (int)0;
	}
	HX_STACK_LINE(40)
	bool tmp1 = (len == null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(40)
	if ((tmp1)){
		HX_STACK_LINE(40)
		int tmp2 = (b->length - pos);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(40)
		len = tmp2;
	}
	HX_STACK_LINE(41)
	bool tmp2 = (pos < (int)0);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(41)
	bool tmp3 = !(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(41)
	bool tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(41)
	bool tmp5;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(41)
	if ((tmp4)){
		HX_STACK_LINE(41)
		tmp5 = (len < (int)0);
	}
	else{
		HX_STACK_LINE(41)
		tmp5 = true;
	}
	HX_STACK_LINE(41)
	bool tmp6 = !(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(41)
	bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
	HX_STACK_LINE(41)
	if ((tmp6)){
		HX_STACK_LINE(41)
		int tmp8 = (pos + len);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(41)
		int tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(41)
		int tmp10 = b->length;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(41)
		tmp7 = (tmp9 > tmp10);
	}
	else{
		HX_STACK_LINE(41)
		tmp7 = true;
	}
	HX_STACK_LINE(41)
	if ((tmp7)){
		HX_STACK_LINE(41)
		HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
	}
	HX_STACK_LINE(53)
	this->b = b->b;
	HX_STACK_LINE(54)
	this->pos = pos;
	HX_STACK_LINE(55)
	this->len = len;
	HX_STACK_LINE(56)
	this->totlen = len;
}
;
	return null();
}

//BytesInput_obj::~BytesInput_obj() { }

Dynamic BytesInput_obj::__CreateEmpty() { return  new BytesInput_obj; }
hx::ObjectPtr< BytesInput_obj > BytesInput_obj::__new(::haxe::io::Bytes b,Dynamic pos,Dynamic len)
{  hx::ObjectPtr< BytesInput_obj > _result_ = new BytesInput_obj();
	_result_->__construct(b,pos,len);
	return _result_;}

Dynamic BytesInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesInput_obj > _result_ = new BytesInput_obj();
	_result_->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _result_;}

int BytesInput_obj::readByte( ){
	HX_STACK_FRAME("haxe.io.BytesInput","readByte",0xb70e46cd,"haxe.io.BytesInput.readByte","C:\\HaxeToolkit\\haxe\\std/haxe/io/BytesInput.hx",90,0xd7d0a806)
	HX_STACK_THIS(this)
	HX_STACK_LINE(94)
	int tmp = this->len;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(94)
	bool tmp1 = (tmp == (int)0);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(94)
	if ((tmp1)){
		HX_STACK_LINE(95)
		::haxe::io::Eof tmp2 = ::haxe::io::Eof_obj::__new();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(95)
		HX_STACK_DO_THROW(tmp2);
	}
	HX_STACK_LINE(96)
	(this->len)--;
	HX_STACK_LINE(102)
	int tmp2 = (this->pos)++;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(102)
	int tmp3 = this->b->__get(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(102)
	return tmp3;
}



BytesInput_obj::BytesInput_obj()
{
}

void BytesInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesInput);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(len,"len");
	HX_MARK_MEMBER_NAME(totlen,"totlen");
	HX_MARK_END_CLASS();
}

void BytesInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(pos,"pos");
	HX_VISIT_MEMBER_NAME(len,"len");
	HX_VISIT_MEMBER_NAME(totlen,"totlen");
}

Dynamic BytesInput_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		if (HX_FIELD_EQ(inName,"len") ) { return len; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"totlen") ) { return totlen; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BytesInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"len") ) { len=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"totlen") ) { totlen=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool BytesInput_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void BytesInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("b","\x62","\x00","\x00","\x00"));
	outFields->push(HX_HCSTRING("pos","\x94","\x5d","\x55","\x00"));
	outFields->push(HX_HCSTRING("len","\xd5","\x4b","\x52","\x00"));
	outFields->push(HX_HCSTRING("totlen","\xdc","\x4a","\xdf","\x97"));
	outFields->push(HX_HCSTRING("position","\xa9","\xa0","\xfa","\xca"));
	outFields->push(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< unsigned char >*/ ,(int)offsetof(BytesInput_obj,b),HX_HCSTRING("b","\x62","\x00","\x00","\x00")},
	{hx::fsInt,(int)offsetof(BytesInput_obj,pos),HX_HCSTRING("pos","\x94","\x5d","\x55","\x00")},
	{hx::fsInt,(int)offsetof(BytesInput_obj,len),HX_HCSTRING("len","\xd5","\x4b","\x52","\x00")},
	{hx::fsInt,(int)offsetof(BytesInput_obj,totlen),HX_HCSTRING("totlen","\xdc","\x4a","\xdf","\x97")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("b","\x62","\x00","\x00","\x00"),
	HX_HCSTRING("pos","\x94","\x5d","\x55","\x00"),
	HX_HCSTRING("len","\xd5","\x4b","\x52","\x00"),
	HX_HCSTRING("totlen","\xdc","\x4a","\xdf","\x97"),
	HX_HCSTRING("readByte","\x7e","\xf9","\x1a","\x69"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytesInput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytesInput_obj::__mClass,"__mClass");
};

#endif

hx::Class BytesInput_obj::__mClass;

void BytesInput_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.io.BytesInput","\xff","\xf8","\x5b","\x64");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &BytesInput_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< BytesInput_obj >;
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
