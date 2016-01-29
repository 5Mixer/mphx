#include <hxcpp.h>

#include "hxMath.h"
#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Utf8
#include <haxe/Utf8.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
namespace haxe{
namespace format{

Void JsonPrinter_obj::__construct(Dynamic replacer,::String space)
{
HX_STACK_FRAME("haxe.format.JsonPrinter","new",0xeb68de75,"haxe.format.JsonPrinter.new","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",54,0x660ed7d4)
HX_STACK_THIS(this)
HX_STACK_ARG(replacer,"replacer")
HX_STACK_ARG(space,"space")
{
	HX_STACK_LINE(55)
	this->replacer = replacer;
	HX_STACK_LINE(56)
	this->indent = space;
	HX_STACK_LINE(57)
	bool tmp = (space != null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(57)
	this->pretty = tmp;
	HX_STACK_LINE(58)
	this->nind = (int)0;
	HX_STACK_LINE(65)
	::StringBuf tmp1 = ::StringBuf_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(65)
	this->buf = tmp1;
}
;
	return null();
}

//JsonPrinter_obj::~JsonPrinter_obj() { }

Dynamic JsonPrinter_obj::__CreateEmpty() { return  new JsonPrinter_obj; }
hx::ObjectPtr< JsonPrinter_obj > JsonPrinter_obj::__new(Dynamic replacer,::String space)
{  hx::ObjectPtr< JsonPrinter_obj > _result_ = new JsonPrinter_obj();
	_result_->__construct(replacer,space);
	return _result_;}

Dynamic JsonPrinter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JsonPrinter_obj > _result_ = new JsonPrinter_obj();
	_result_->__construct(inArgs[0],inArgs[1]);
	return _result_;}

Void JsonPrinter_obj::write( Dynamic k,Dynamic v){
{
		HX_STACK_FRAME("haxe.format.JsonPrinter","write",0x755dea34,"haxe.format.JsonPrinter.write","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",77,0x660ed7d4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(k,"k")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(78)
		Dynamic tmp = this->replacer_dyn();		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(78)
		bool tmp1 = (tmp != null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(78)
		if ((tmp1)){
			HX_STACK_LINE(78)
			Dynamic tmp2 = k;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(78)
			Dynamic tmp3 = v;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(78)
			Dynamic tmp4 = this->replacer(tmp2,tmp3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(78)
			v = tmp4;
		}
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			Dynamic tmp2 = v;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(79)
			::ValueType tmp3 = ::Type_obj::_typeof(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(79)
			::ValueType _g = tmp3;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(79)
			switch( (int)(_g->__Index())){
				case (int)8: {
					HX_STACK_LINE(81)
					::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(81)
					tmp4->add(HX_HCSTRING("\"???\"","\x45","\x2f","\x74","\xbd"));
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(83)
					Dynamic tmp4 = v;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(83)
					Dynamic tmp5 = v;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(83)
					this->fieldsString(tmp4,::Reflect_obj::fields(tmp5));
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(85)
					::String v1 = v;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(85)
					::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(85)
					::String tmp5 = v1;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(85)
					tmp4->add(tmp5);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(87)
					Dynamic tmp4 = v;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(87)
					bool tmp5 = ::Math_obj::isFinite(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(87)
					::String tmp6;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(87)
					if ((tmp5)){
						HX_STACK_LINE(87)
						tmp6 = v;
					}
					else{
						HX_STACK_LINE(87)
						tmp6 = HX_HCSTRING("null","\x87","\x9e","\x0e","\x49");
					}
					HX_STACK_LINE(87)
					::String v1 = tmp6;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(87)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(87)
					::String tmp8 = v1;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(87)
					tmp7->add(tmp8);
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(89)
					::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(89)
					tmp4->add(HX_HCSTRING("\"<fun>\"","\x09","\x3c","\xcc","\x8b"));
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(79)
					::hx::Class tmp4 = (::ValueType(_g))->__Param(0);		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(79)
					::hx::Class c = tmp4;		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(90)
					{
						HX_STACK_LINE(91)
						bool tmp5 = (c == hx::ClassOf< ::String >());		HX_STACK_VAR(tmp5,"tmp5");
						HX_STACK_LINE(91)
						if ((tmp5)){
							HX_STACK_LINE(92)
							Dynamic tmp6 = v;		HX_STACK_VAR(tmp6,"tmp6");
							HX_STACK_LINE(92)
							this->quote(tmp6);
						}
						else{
							HX_STACK_LINE(93)
							bool tmp6 = (c == hx::ClassOf< Array<int> >());		HX_STACK_VAR(tmp6,"tmp6");
							HX_STACK_LINE(93)
							if ((tmp6)){
								HX_STACK_LINE(94)
								cpp::ArrayBase v1 = v;		HX_STACK_VAR(v1,"v1");
								HX_STACK_LINE(95)
								{
									HX_STACK_LINE(95)
									::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
									HX_STACK_LINE(95)
									::String tmp8 = HX_HCSTRING("[","\x5b","\x00","\x00","\x00");		HX_STACK_VAR(tmp8,"tmp8");
									HX_STACK_LINE(95)
									tmp7->b->push(tmp8);
								}
								HX_STACK_LINE(97)
								int len = v1->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"), hx::paccDynamic );		HX_STACK_VAR(len,"len");
								HX_STACK_LINE(98)
								int tmp7 = (len - (int)1);		HX_STACK_VAR(tmp7,"tmp7");
								HX_STACK_LINE(98)
								int last = tmp7;		HX_STACK_VAR(last,"last");
								HX_STACK_LINE(99)
								{
									HX_STACK_LINE(99)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(99)
									while((true)){
										HX_STACK_LINE(99)
										bool tmp8 = (_g1 < len);		HX_STACK_VAR(tmp8,"tmp8");
										HX_STACK_LINE(99)
										bool tmp9 = !(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
										HX_STACK_LINE(99)
										if ((tmp9)){
											HX_STACK_LINE(99)
											break;
										}
										HX_STACK_LINE(99)
										int tmp10 = (_g1)++;		HX_STACK_VAR(tmp10,"tmp10");
										HX_STACK_LINE(99)
										int i = tmp10;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(101)
										bool tmp11 = (i > (int)0);		HX_STACK_VAR(tmp11,"tmp11");
										HX_STACK_LINE(101)
										if ((tmp11)){
											HX_STACK_LINE(101)
											::StringBuf tmp12 = this->buf;		HX_STACK_VAR(tmp12,"tmp12");
											HX_STACK_LINE(101)
											::String tmp13 = HX_HCSTRING(",","\x2c","\x00","\x00","\x00");		HX_STACK_VAR(tmp13,"tmp13");
											HX_STACK_LINE(101)
											tmp12->b->push(tmp13);
										}
										else{
											HX_STACK_LINE(101)
											(this->nind)++;
										}
										HX_STACK_LINE(102)
										{
											HX_STACK_LINE(102)
											bool tmp12 = this->pretty;		HX_STACK_VAR(tmp12,"tmp12");
											HX_STACK_LINE(102)
											if ((tmp12)){
												HX_STACK_LINE(102)
												::StringBuf tmp13 = this->buf;		HX_STACK_VAR(tmp13,"tmp13");
												HX_STACK_LINE(102)
												::String tmp14 = HX_HCSTRING("\n","\x0a","\x00","\x00","\x00");		HX_STACK_VAR(tmp14,"tmp14");
												HX_STACK_LINE(102)
												tmp13->b->push(tmp14);
											}
										}
										HX_STACK_LINE(103)
										{
											HX_STACK_LINE(103)
											bool tmp12 = this->pretty;		HX_STACK_VAR(tmp12,"tmp12");
											HX_STACK_LINE(103)
											if ((tmp12)){
												HX_STACK_LINE(103)
												::String tmp13 = this->indent;		HX_STACK_VAR(tmp13,"tmp13");
												HX_STACK_LINE(103)
												int tmp14 = this->nind;		HX_STACK_VAR(tmp14,"tmp14");
												HX_STACK_LINE(103)
												::String tmp15 = this->indent;		HX_STACK_VAR(tmp15,"tmp15");
												HX_STACK_LINE(103)
												int tmp16 = tmp15.length;		HX_STACK_VAR(tmp16,"tmp16");
												HX_STACK_LINE(103)
												int tmp17 = (tmp14 * tmp16);		HX_STACK_VAR(tmp17,"tmp17");
												HX_STACK_LINE(103)
												::String tmp18 = ::StringTools_obj::lpad(HX_HCSTRING("","\x00","\x00","\x00","\x00"),tmp13,tmp17);		HX_STACK_VAR(tmp18,"tmp18");
												HX_STACK_LINE(103)
												::String v2 = tmp18;		HX_STACK_VAR(v2,"v2");
												HX_STACK_LINE(103)
												::StringBuf tmp19 = this->buf;		HX_STACK_VAR(tmp19,"tmp19");
												HX_STACK_LINE(103)
												::String tmp20 = v2;		HX_STACK_VAR(tmp20,"tmp20");
												HX_STACK_LINE(103)
												tmp19->add(tmp20);
											}
										}
										HX_STACK_LINE(104)
										int tmp12 = i;		HX_STACK_VAR(tmp12,"tmp12");
										HX_STACK_LINE(104)
										Dynamic tmp13 = v1->__GetItem(i);		HX_STACK_VAR(tmp13,"tmp13");
										HX_STACK_LINE(104)
										this->write(tmp12,tmp13);
										HX_STACK_LINE(105)
										bool tmp14 = (i == last);		HX_STACK_VAR(tmp14,"tmp14");
										HX_STACK_LINE(105)
										if ((tmp14)){
											HX_STACK_LINE(107)
											(this->nind)--;
											HX_STACK_LINE(108)
											{
												HX_STACK_LINE(108)
												bool tmp15 = this->pretty;		HX_STACK_VAR(tmp15,"tmp15");
												HX_STACK_LINE(108)
												if ((tmp15)){
													HX_STACK_LINE(108)
													::StringBuf tmp16 = this->buf;		HX_STACK_VAR(tmp16,"tmp16");
													HX_STACK_LINE(108)
													::String tmp17 = HX_HCSTRING("\n","\x0a","\x00","\x00","\x00");		HX_STACK_VAR(tmp17,"tmp17");
													HX_STACK_LINE(108)
													tmp16->b->push(tmp17);
												}
											}
											HX_STACK_LINE(109)
											{
												HX_STACK_LINE(109)
												bool tmp15 = this->pretty;		HX_STACK_VAR(tmp15,"tmp15");
												HX_STACK_LINE(109)
												if ((tmp15)){
													HX_STACK_LINE(109)
													::String tmp16 = this->indent;		HX_STACK_VAR(tmp16,"tmp16");
													HX_STACK_LINE(109)
													int tmp17 = this->nind;		HX_STACK_VAR(tmp17,"tmp17");
													HX_STACK_LINE(109)
													::String tmp18 = this->indent;		HX_STACK_VAR(tmp18,"tmp18");
													HX_STACK_LINE(109)
													int tmp19 = tmp18.length;		HX_STACK_VAR(tmp19,"tmp19");
													HX_STACK_LINE(109)
													int tmp20 = (tmp17 * tmp19);		HX_STACK_VAR(tmp20,"tmp20");
													HX_STACK_LINE(109)
													::String tmp21 = ::StringTools_obj::lpad(HX_HCSTRING("","\x00","\x00","\x00","\x00"),tmp16,tmp20);		HX_STACK_VAR(tmp21,"tmp21");
													HX_STACK_LINE(109)
													::String v2 = tmp21;		HX_STACK_VAR(v2,"v2");
													HX_STACK_LINE(109)
													::StringBuf tmp22 = this->buf;		HX_STACK_VAR(tmp22,"tmp22");
													HX_STACK_LINE(109)
													::String tmp23 = v2;		HX_STACK_VAR(tmp23,"tmp23");
													HX_STACK_LINE(109)
													tmp22->add(tmp23);
												}
											}
										}
									}
								}
								HX_STACK_LINE(112)
								{
									HX_STACK_LINE(112)
									::StringBuf tmp8 = this->buf;		HX_STACK_VAR(tmp8,"tmp8");
									HX_STACK_LINE(112)
									::String tmp9 = HX_HCSTRING("]","\x5d","\x00","\x00","\x00");		HX_STACK_VAR(tmp9,"tmp9");
									HX_STACK_LINE(112)
									tmp8->b->push(tmp9);
								}
							}
							else{
								HX_STACK_LINE(113)
								bool tmp7 = (c == hx::ClassOf< ::haxe::ds::StringMap >());		HX_STACK_VAR(tmp7,"tmp7");
								HX_STACK_LINE(113)
								if ((tmp7)){
									HX_STACK_LINE(114)
									::haxe::ds::StringMap v1 = v;		HX_STACK_VAR(v1,"v1");
									struct _Function_7_1{
										inline static Dynamic Block( ){
											HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",115,0x660ed7d4)
											{
												hx::Anon __result = hx::Anon_obj::Create();
												return __result;
											}
											return null();
										}
									};
									HX_STACK_LINE(115)
									Dynamic tmp8 = _Function_7_1::Block();		HX_STACK_VAR(tmp8,"tmp8");
									HX_STACK_LINE(115)
									Dynamic o = tmp8;		HX_STACK_VAR(o,"o");
									HX_STACK_LINE(116)
									Dynamic tmp9 = v1->keys();		HX_STACK_VAR(tmp9,"tmp9");
									HX_STACK_LINE(116)
									for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(tmp9);  __it->hasNext(); ){
										::String k1 = __it->next();
										{
											HX_STACK_LINE(117)
											Dynamic tmp10 = o;		HX_STACK_VAR(tmp10,"tmp10");
											HX_STACK_LINE(117)
											::String tmp11 = k1;		HX_STACK_VAR(tmp11,"tmp11");
											HX_STACK_LINE(117)
											::String tmp12 = k1;		HX_STACK_VAR(tmp12,"tmp12");
											HX_STACK_LINE(117)
											Dynamic tmp13 = v1->get(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
											HX_STACK_LINE(117)
											::Reflect_obj::setField(tmp10,tmp11,tmp13);
										}
;
									}
									HX_STACK_LINE(118)
									{
										HX_STACK_LINE(118)
										Dynamic tmp10 = o;		HX_STACK_VAR(tmp10,"tmp10");
										HX_STACK_LINE(118)
										Dynamic tmp11 = o;		HX_STACK_VAR(tmp11,"tmp11");
										HX_STACK_LINE(118)
										this->fieldsString(tmp10,::Reflect_obj::fields(tmp11));
									}
								}
								else{
									HX_STACK_LINE(119)
									bool tmp8 = (c == hx::ClassOf< ::Date >());		HX_STACK_VAR(tmp8,"tmp8");
									HX_STACK_LINE(119)
									if ((tmp8)){
										HX_STACK_LINE(120)
										::Date v1 = v;		HX_STACK_VAR(v1,"v1");
										HX_STACK_LINE(121)
										::String tmp9 = v1->toString();		HX_STACK_VAR(tmp9,"tmp9");
										HX_STACK_LINE(121)
										this->quote(tmp9);
									}
									else{
										HX_STACK_LINE(126)
										Dynamic tmp9 = v;		HX_STACK_VAR(tmp9,"tmp9");
										HX_STACK_LINE(126)
										Dynamic tmp10 = v;		HX_STACK_VAR(tmp10,"tmp10");
										HX_STACK_LINE(126)
										this->fieldsString(tmp9,::Reflect_obj::fields(tmp10));
									}
								}
							}
						}
					}
				}
				;break;
				case (int)7: {
					HX_STACK_LINE(129)
					int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(129)
					{
						HX_STACK_LINE(129)
						Dynamic e = v;		HX_STACK_VAR(e,"e");
						HX_STACK_LINE(129)
						tmp4 = e->__Index();
					}
					HX_STACK_LINE(129)
					Dynamic i = tmp4;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(130)
					{
						HX_STACK_LINE(130)
						::String v1 = i;		HX_STACK_VAR(v1,"v1");
						HX_STACK_LINE(130)
						::StringBuf tmp5 = this->buf;		HX_STACK_VAR(tmp5,"tmp5");
						HX_STACK_LINE(130)
						::String tmp6 = v1;		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(130)
						tmp5->add(tmp6);
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(132)
					::String v1 = v;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(132)
					::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(132)
					::String tmp5 = v1;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(132)
					tmp4->add(tmp5);
				}
				;break;
				case (int)0: {
					HX_STACK_LINE(134)
					::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(134)
					tmp4->add(HX_HCSTRING("null","\x87","\x9e","\x0e","\x49"));
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(JsonPrinter_obj,write,(void))

Void JsonPrinter_obj::fieldsString( Dynamic v,Array< ::String > fields){
{
		HX_STACK_FRAME("haxe.format.JsonPrinter","fieldsString",0x974bd375,"haxe.format.JsonPrinter.fieldsString","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",165,0x660ed7d4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_ARG(fields,"fields")
		HX_STACK_LINE(166)
		{
			HX_STACK_LINE(166)
			::StringBuf tmp = this->buf;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(166)
			::String tmp1 = HX_HCSTRING("{","\x7b","\x00","\x00","\x00");		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(166)
			tmp->b->push(tmp1);
		}
		HX_STACK_LINE(167)
		int len = fields->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(168)
		int tmp = (len - (int)1);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(168)
		int last = tmp;		HX_STACK_VAR(last,"last");
		HX_STACK_LINE(169)
		bool first = true;		HX_STACK_VAR(first,"first");
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(170)
			while((true)){
				HX_STACK_LINE(170)
				bool tmp1 = (_g < len);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(170)
				bool tmp2 = !(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(170)
				if ((tmp2)){
					HX_STACK_LINE(170)
					break;
				}
				HX_STACK_LINE(170)
				int tmp3 = (_g)++;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(170)
				int i = tmp3;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(171)
				::String tmp4 = fields->__get(i);		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(171)
				::String f = tmp4;		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(172)
				Dynamic tmp5 = v;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(172)
				::String tmp6 = f;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(172)
				Dynamic tmp7 = ::Reflect_obj::field(tmp5,tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(172)
				Dynamic value = tmp7;		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(173)
				Dynamic tmp8 = value;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(173)
				bool tmp9 = ::Reflect_obj::isFunction(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(173)
				if ((tmp9)){
					HX_STACK_LINE(173)
					continue;
				}
				HX_STACK_LINE(174)
				bool tmp10 = first;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(174)
				if ((tmp10)){
					HX_STACK_LINE(174)
					(this->nind)++;
					HX_STACK_LINE(174)
					first = false;
				}
				else{
					HX_STACK_LINE(174)
					::StringBuf tmp11 = this->buf;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(174)
					::String tmp12 = HX_HCSTRING(",","\x2c","\x00","\x00","\x00");		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(174)
					tmp11->b->push(tmp12);
				}
				HX_STACK_LINE(175)
				{
					HX_STACK_LINE(175)
					bool tmp11 = this->pretty;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(175)
					if ((tmp11)){
						HX_STACK_LINE(175)
						::StringBuf tmp12 = this->buf;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(175)
						::String tmp13 = HX_HCSTRING("\n","\x0a","\x00","\x00","\x00");		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(175)
						tmp12->b->push(tmp13);
					}
				}
				HX_STACK_LINE(176)
				{
					HX_STACK_LINE(176)
					bool tmp11 = this->pretty;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(176)
					if ((tmp11)){
						HX_STACK_LINE(176)
						::String tmp12 = this->indent;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(176)
						int tmp13 = this->nind;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(176)
						::String tmp14 = this->indent;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(176)
						int tmp15 = tmp14.length;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(176)
						int tmp16 = (tmp13 * tmp15);		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(176)
						::String tmp17 = ::StringTools_obj::lpad(HX_HCSTRING("","\x00","\x00","\x00","\x00"),tmp12,tmp16);		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(176)
						::String v1 = tmp17;		HX_STACK_VAR(v1,"v1");
						HX_STACK_LINE(176)
						::StringBuf tmp18 = this->buf;		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(176)
						::String tmp19 = v1;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(176)
						tmp18->add(tmp19);
					}
				}
				HX_STACK_LINE(177)
				::String tmp11 = f;		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(177)
				this->quote(tmp11);
				HX_STACK_LINE(178)
				{
					HX_STACK_LINE(178)
					::StringBuf tmp12 = this->buf;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(178)
					::String tmp13 = HX_HCSTRING(":","\x3a","\x00","\x00","\x00");		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(178)
					tmp12->b->push(tmp13);
				}
				HX_STACK_LINE(179)
				bool tmp12 = this->pretty;		HX_STACK_VAR(tmp12,"tmp12");
				HX_STACK_LINE(179)
				if ((tmp12)){
					HX_STACK_LINE(179)
					::StringBuf tmp13 = this->buf;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(179)
					::String tmp14 = HX_HCSTRING(" ","\x20","\x00","\x00","\x00");		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(179)
					tmp13->b->push(tmp14);
				}
				HX_STACK_LINE(180)
				::String tmp13 = f;		HX_STACK_VAR(tmp13,"tmp13");
				HX_STACK_LINE(180)
				Dynamic tmp14 = value;		HX_STACK_VAR(tmp14,"tmp14");
				HX_STACK_LINE(180)
				this->write(tmp13,tmp14);
				HX_STACK_LINE(181)
				bool tmp15 = (i == last);		HX_STACK_VAR(tmp15,"tmp15");
				HX_STACK_LINE(181)
				if ((tmp15)){
					HX_STACK_LINE(183)
					(this->nind)--;
					HX_STACK_LINE(184)
					{
						HX_STACK_LINE(184)
						bool tmp16 = this->pretty;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(184)
						if ((tmp16)){
							HX_STACK_LINE(184)
							::StringBuf tmp17 = this->buf;		HX_STACK_VAR(tmp17,"tmp17");
							HX_STACK_LINE(184)
							::String tmp18 = HX_HCSTRING("\n","\x0a","\x00","\x00","\x00");		HX_STACK_VAR(tmp18,"tmp18");
							HX_STACK_LINE(184)
							tmp17->b->push(tmp18);
						}
					}
					HX_STACK_LINE(185)
					{
						HX_STACK_LINE(185)
						bool tmp16 = this->pretty;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(185)
						if ((tmp16)){
							HX_STACK_LINE(185)
							::String tmp17 = this->indent;		HX_STACK_VAR(tmp17,"tmp17");
							HX_STACK_LINE(185)
							int tmp18 = this->nind;		HX_STACK_VAR(tmp18,"tmp18");
							HX_STACK_LINE(185)
							::String tmp19 = this->indent;		HX_STACK_VAR(tmp19,"tmp19");
							HX_STACK_LINE(185)
							int tmp20 = tmp19.length;		HX_STACK_VAR(tmp20,"tmp20");
							HX_STACK_LINE(185)
							int tmp21 = (tmp18 * tmp20);		HX_STACK_VAR(tmp21,"tmp21");
							HX_STACK_LINE(185)
							::String tmp22 = ::StringTools_obj::lpad(HX_HCSTRING("","\x00","\x00","\x00","\x00"),tmp17,tmp21);		HX_STACK_VAR(tmp22,"tmp22");
							HX_STACK_LINE(185)
							::String v1 = tmp22;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(185)
							::StringBuf tmp23 = this->buf;		HX_STACK_VAR(tmp23,"tmp23");
							HX_STACK_LINE(185)
							::String tmp24 = v1;		HX_STACK_VAR(tmp24,"tmp24");
							HX_STACK_LINE(185)
							tmp23->add(tmp24);
						}
					}
				}
			}
		}
		HX_STACK_LINE(188)
		{
			HX_STACK_LINE(188)
			::StringBuf tmp1 = this->buf;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(188)
			::String tmp2 = HX_HCSTRING("}","\x7d","\x00","\x00","\x00");		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(188)
			tmp1->b->push(tmp2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(JsonPrinter_obj,fieldsString,(void))

Void JsonPrinter_obj::quote( ::String s){
{
		HX_STACK_FRAME("haxe.format.JsonPrinter","quote",0x02f6a091,"haxe.format.JsonPrinter.quote","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",191,0x660ed7d4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(193)
		int tmp = s.length;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(193)
		::String tmp1 = s;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(193)
		int tmp2 = ::haxe::Utf8_obj::length(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(193)
		bool tmp3 = (tmp != tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(193)
		if ((tmp3)){
			HX_STACK_LINE(194)
			::String tmp4 = s;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(194)
			this->quoteUtf8(tmp4);
			HX_STACK_LINE(195)
			return null();
		}
		HX_STACK_LINE(198)
		{
			HX_STACK_LINE(198)
			::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(198)
			::String tmp5 = HX_HCSTRING("\"","\x22","\x00","\x00","\x00");		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(198)
			tmp4->b->push(tmp5);
		}
		HX_STACK_LINE(199)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(200)
		while((true)){
			HX_STACK_LINE(201)
			int tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(201)
			{
				HX_STACK_LINE(201)
				int tmp5 = (i)++;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(201)
				int index = tmp5;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(201)
				int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(201)
				tmp4 = s.cca(tmp6);
			}
			HX_STACK_LINE(201)
			int c = tmp4;		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(202)
			bool tmp5 = (c == (int)0);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(202)
			if ((tmp5)){
				HX_STACK_LINE(202)
				break;
			}
			HX_STACK_LINE(203)
			int tmp6 = c;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(203)
			switch( (int)(tmp6)){
				case (int)34: {
					HX_STACK_LINE(204)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(204)
					tmp7->add(HX_HCSTRING("\\\"","\x46","\x50","\x00","\x00"));
				}
				;break;
				case (int)92: {
					HX_STACK_LINE(205)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(205)
					tmp7->add(HX_HCSTRING("\\\\","\x80","\x50","\x00","\x00"));
				}
				;break;
				case (int)10: {
					HX_STACK_LINE(206)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(206)
					tmp7->add(HX_HCSTRING("\\n","\x92","\x50","\x00","\x00"));
				}
				;break;
				case (int)13: {
					HX_STACK_LINE(207)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(207)
					tmp7->add(HX_HCSTRING("\\r","\x96","\x50","\x00","\x00"));
				}
				;break;
				case (int)9: {
					HX_STACK_LINE(208)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(208)
					tmp7->add(HX_HCSTRING("\\t","\x98","\x50","\x00","\x00"));
				}
				;break;
				case (int)8: {
					HX_STACK_LINE(209)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(209)
					tmp7->add(HX_HCSTRING("\\b","\x86","\x50","\x00","\x00"));
				}
				;break;
				case (int)12: {
					HX_STACK_LINE(210)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(210)
					tmp7->add(HX_HCSTRING("\\f","\x8a","\x50","\x00","\x00"));
				}
				;break;
				default: {
					HX_STACK_LINE(215)
					::StringBuf tmp7 = this->buf;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(215)
					int tmp8 = c;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(215)
					::String tmp9 = ::String::fromCharCode(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(215)
					tmp7->b->push(tmp9);
				}
			}
		}
		HX_STACK_LINE(219)
		{
			HX_STACK_LINE(219)
			::StringBuf tmp4 = this->buf;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(219)
			::String tmp5 = HX_HCSTRING("\"","\x22","\x00","\x00","\x00");		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(219)
			tmp4->b->push(tmp5);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(JsonPrinter_obj,quote,(void))

Void JsonPrinter_obj::quoteUtf8( ::String s){
{
		HX_STACK_FRAME("haxe.format.JsonPrinter","quoteUtf8",0x88683e62,"haxe.format.JsonPrinter.quoteUtf8","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",223,0x660ed7d4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(224)
		::haxe::Utf8 tmp = ::haxe::Utf8_obj::__new(null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(224)
		::haxe::Utf8 u = tmp;		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(225)
		::String tmp1 = s;		HX_STACK_VAR(tmp1,"tmp1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,::haxe::Utf8,u)
		int __ArgCount() const { return 1; }
		Void run(int c){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",225,0x660ed7d4)
			HX_STACK_ARG(c,"c")
			{
				HX_STACK_LINE(226)
				int tmp2 = c;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(226)
				switch( (int)(tmp2)){
					case (int)92: case (int)34: {
						HX_STACK_LINE(227)
						u->addChar((int)92);
						HX_STACK_LINE(227)
						int tmp3 = c;		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(227)
						u->addChar(tmp3);
					}
					;break;
					case (int)10: {
						HX_STACK_LINE(228)
						u->addChar((int)92);
						HX_STACK_LINE(228)
						u->addChar((int)110);
					}
					;break;
					case (int)13: {
						HX_STACK_LINE(229)
						u->addChar((int)92);
						HX_STACK_LINE(229)
						u->addChar((int)114);
					}
					;break;
					case (int)9: {
						HX_STACK_LINE(230)
						u->addChar((int)92);
						HX_STACK_LINE(230)
						u->addChar((int)116);
					}
					;break;
					case (int)8: {
						HX_STACK_LINE(231)
						u->addChar((int)92);
						HX_STACK_LINE(231)
						u->addChar((int)98);
					}
					;break;
					case (int)12: {
						HX_STACK_LINE(232)
						u->addChar((int)92);
						HX_STACK_LINE(232)
						u->addChar((int)102);
					}
					;break;
					default: {
						HX_STACK_LINE(233)
						int tmp3 = c;		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(233)
						u->addChar(tmp3);
					}
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(225)
		::haxe::Utf8_obj::iter(tmp1, Dynamic(new _Function_1_1(u)));
		HX_STACK_LINE(236)
		::StringBuf tmp2 = this->buf;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(236)
		tmp2->add(HX_HCSTRING("\"","\x22","\x00","\x00","\x00"));
		HX_STACK_LINE(237)
		::StringBuf tmp3 = this->buf;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(237)
		::String tmp4 = u->toString();		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(237)
		tmp3->add(tmp4);
		HX_STACK_LINE(238)
		::StringBuf tmp5 = this->buf;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(238)
		tmp5->add(HX_HCSTRING("\"","\x22","\x00","\x00","\x00"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(JsonPrinter_obj,quoteUtf8,(void))

::String JsonPrinter_obj::print( Dynamic o,Dynamic replacer,::String space){
	HX_STACK_FRAME("haxe.format.JsonPrinter","print",0x6d8fd582,"haxe.format.JsonPrinter.print","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonPrinter.hx",42,0x660ed7d4)
	HX_STACK_ARG(o,"o")
	HX_STACK_ARG(replacer,"replacer")
	HX_STACK_ARG(space,"space")
	HX_STACK_LINE(43)
	::haxe::format::JsonPrinter tmp = ::haxe::format::JsonPrinter_obj::__new(replacer,space);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(43)
	::haxe::format::JsonPrinter printer = tmp;		HX_STACK_VAR(printer,"printer");
	HX_STACK_LINE(44)
	Dynamic tmp1 = o;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(44)
	printer->write(HX_HCSTRING("","\x00","\x00","\x00","\x00"),tmp1);
	HX_STACK_LINE(45)
	::String tmp2 = printer->buf->b->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(45)
	return tmp2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonPrinter_obj,print,return )


JsonPrinter_obj::JsonPrinter_obj()
{
}

void JsonPrinter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JsonPrinter);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(replacer,"replacer");
	HX_MARK_MEMBER_NAME(indent,"indent");
	HX_MARK_MEMBER_NAME(pretty,"pretty");
	HX_MARK_MEMBER_NAME(nind,"nind");
	HX_MARK_END_CLASS();
}

void JsonPrinter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buf,"buf");
	HX_VISIT_MEMBER_NAME(replacer,"replacer");
	HX_VISIT_MEMBER_NAME(indent,"indent");
	HX_VISIT_MEMBER_NAME(pretty,"pretty");
	HX_VISIT_MEMBER_NAME(nind,"nind");
}

Dynamic JsonPrinter_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"nind") ) { return nind; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		if (HX_FIELD_EQ(inName,"quote") ) { return quote_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indent") ) { return indent; }
		if (HX_FIELD_EQ(inName,"pretty") ) { return pretty; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"replacer") ) { return replacer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"quoteUtf8") ) { return quoteUtf8_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"fieldsString") ) { return fieldsString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool JsonPrinter_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { outValue = print_dyn(); return true;  }
	}
	return false;
}

Dynamic JsonPrinter_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"nind") ) { nind=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indent") ) { indent=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pretty") ) { pretty=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"replacer") ) { replacer=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool JsonPrinter_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void JsonPrinter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("buf","\x33","\xc3","\x4a","\x00"));
	outFields->push(HX_HCSTRING("indent","\x6c","\x0c","\xf3","\x93"));
	outFields->push(HX_HCSTRING("pretty","\xb6","\x82","\xc1","\xae"));
	outFields->push(HX_HCSTRING("nind","\x31","\x85","\x05","\x49"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::StringBuf*/ ,(int)offsetof(JsonPrinter_obj,buf),HX_HCSTRING("buf","\x33","\xc3","\x4a","\x00")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(JsonPrinter_obj,replacer),HX_HCSTRING("replacer","\xbe","\xe5","\x16","\x18")},
	{hx::fsString,(int)offsetof(JsonPrinter_obj,indent),HX_HCSTRING("indent","\x6c","\x0c","\xf3","\x93")},
	{hx::fsBool,(int)offsetof(JsonPrinter_obj,pretty),HX_HCSTRING("pretty","\xb6","\x82","\xc1","\xae")},
	{hx::fsInt,(int)offsetof(JsonPrinter_obj,nind),HX_HCSTRING("nind","\x31","\x85","\x05","\x49")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("buf","\x33","\xc3","\x4a","\x00"),
	HX_HCSTRING("replacer","\xbe","\xe5","\x16","\x18"),
	HX_HCSTRING("indent","\x6c","\x0c","\xf3","\x93"),
	HX_HCSTRING("pretty","\xb6","\x82","\xc1","\xae"),
	HX_HCSTRING("nind","\x31","\x85","\x05","\x49"),
	HX_HCSTRING("write","\xdf","\x6c","\x59","\xd0"),
	HX_HCSTRING("fieldsString","\x2a","\xcc","\x56","\x34"),
	HX_HCSTRING("quote","\x3c","\x23","\xf2","\x5d"),
	HX_HCSTRING("quoteUtf8","\x8d","\xf2","\xd1","\x09"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JsonPrinter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(JsonPrinter_obj::__mClass,"__mClass");
};

#endif

hx::Class JsonPrinter_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("print","\x2d","\x58","\x8b","\xc8"),
	::String(null()) };

void JsonPrinter_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.format.JsonPrinter","\x03","\x80","\xb9","\xf7");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &JsonPrinter_obj::__GetStatic;
	__mClass->mSetStaticField = &JsonPrinter_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< JsonPrinter_obj >;
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
} // end namespace format
