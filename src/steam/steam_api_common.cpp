/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>
#include <cstdlib>

#include <steam_api_common.h>

#include "vapor_base.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steam callback and call-result helpers
//
//	The following macros and classes are used to register your application for
//	callbacks and call-results, which are delivered in a predictable manner.
//
//	STEAM_CALLBACK macros are meant for use inside of a C++ class definition.
//	They map a Steam notification callback directly to a class member function
//	which is automatically prototyped as "void func( callback_type *pParam )".
//
//	CCallResult is used with specific Steam APIs that return "result handles".
//	The handle can be passed to a CCallResult object's Set function, along with
//	an object pointer and member-function pointer. The member function will
//	be executed once the results of the Steam API call are available.
//
//	CCallback and CCallbackManual classes can be used instead of STEAM_CALLBACK
//	macros if you require finer control over registration and unregistration.
//
//	Callbacks and call-results are queued automatically and are only
//	delivered/executed when your application calls SteamAPI_RunCallbacks().
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// Dispatch all queued Steamworks callbacks.
//
// This is safe to call from multiple threads simultaneously,
// but if you choose to do this, callback code could be executed on any thread.
// One alternative is to call SteamAPI_RunCallbacks from the main thread only,
// and call SteamAPI_ReleaseCurrentThreadMemory regularly on other threads.
S_API void S_CALLTYPE SteamAPI_RunCallbacks()
{
    VLOG_INFO(__FUNCTION__);
    CCallbackMgr::GetInstance().DispatchCallbacks();
}

// Dispatch callbacks relevant to the gameserver client and interfaces.
// To register for these, you need to use STEAM_GAMESERVER_CALLBACK.
// (Or call SetGameserverFlag on your CCallbackBase object.)
S_API void S_CALLTYPE SteamGameServer_RunCallbacks()
{
    VLOG_INFO(__FUNCTION__);
    CCallbackMgr::GetInstance().DispatchCallbacks();
}
