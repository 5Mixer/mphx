#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_ds_Either
#include <haxe/ds/Either.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketOutput
#include <sys/net/_Socket/SocketOutput.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketInput
#include <sys/net/_Socket/SocketInput.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_mphx_tcp_Protocol
#include <mphx/tcp/Protocol.h>
#endif
#ifndef INCLUDED_mphx_tcp_Connection
#include <mphx/tcp/Connection.h>
#endif
#ifndef INCLUDED_mphx_server_Server
#include <mphx/server/Server.h>
#endif
#ifndef INCLUDED_mphx_core__EventManager_Either_Impl_
#include <mphx/core/_EventManager/Either_Impl_.h>
#endif
#ifndef INCLUDED_mphx_core_EventManager
#include <mphx/core/EventManager.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_haxe_Utf8
#include <haxe/Utf8.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Date
#include <Date.h>
#endif

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxe::io::Error_obj::__register();
::haxe::ds::Either_obj::__register();
::ValueType_obj::__register();
::sys::net::Socket_obj::__register();
::sys::net::_Socket::SocketOutput_obj::__register();
::sys::net::_Socket::SocketInput_obj::__register();
::sys::net::Host_obj::__register();
::haxe::Log_obj::__register();
::Sys_obj::__register();
::mphx::tcp::Protocol_obj::__register();
::mphx::tcp::Connection_obj::__register();
::mphx::server::Server_obj::__register();
::mphx::core::_EventManager::Either_Impl__obj::__register();
::mphx::core::EventManager_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesInput_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::format::JsonPrinter_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ds::ObjectMap_obj::__register();
::haxe::Utf8_obj::__register();
::haxe::IMap_obj::__register();
::Type_obj::__register();
::cpp::Lib_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::Main_obj::__register();
::Date_obj::__register();
::haxe::io::Error_obj::__boot();
::haxe::ds::Either_obj::__boot();
::ValueType_obj::__boot();
::sys::net::Host_obj::__init__();
::haxe::Log_obj::__boot();
::Sys_obj::__boot();
::sys::net::Host_obj::__boot();
::sys::net::_Socket::SocketInput_obj::__boot();
::sys::net::_Socket::SocketOutput_obj::__boot();
::sys::net::Socket_obj::__boot();
}

