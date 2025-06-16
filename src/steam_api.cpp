//====== Copyright © 1996-2008, Valve Corporation, All rights reserved. =======
//
// Purpose: Steam API implementation
//
//=============================================================================

#include <cstring>
#include <cstdlib>
#include "../include/sdk/100/steam_api.h"

// Global Steam client interface pointer
static ISteamClient* g_pSteamClient = nullptr;

// Global interface pointers
static ISteamUser* g_pSteamUser = nullptr;
static ISteamFriends* g_pSteamFriends = nullptr;
static ISteamUtils* g_pSteamUtils = nullptr;
static ISteamMatchmaking* g_pSteamMatchmaking = nullptr;
static ISteamUserStats* g_pSteamUserStats = nullptr;
static ISteamApps* g_pSteamApps = nullptr;
static ISteamNetworking* g_pSteamNetworking = nullptr;
static ISteamMatchmakingServers* g_pSteamMatchmakingServers = nullptr;

// Global pipe and user handles
static HSteamPipe g_hSteamPipe = 0;
static HSteamUser g_hSteamUser = 0;

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam API setup & shutdown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// S_API void SteamAPI_Init(); (see below)
S_API void SteamAPI_Shutdown() {
    // TODO: Implement SteamAPI_Shutdown
}

// crash dump recording functions
S_API void SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID ) {
    // TODO: Implement SteamAPI_WriteMiniDump
}

S_API void SteamAPI_SetMiniDumpComment( const char *pchMsg ) {
    // TODO: Implement SteamAPI_SetMiniDumpComment
}

// interface pointers, configured by SteamAPI_Init()
S_API ISteamClient *SteamClient() {
    // TODO: Implement SteamClient
    return g_pSteamClient;
}

//
// VERSION_SAFE_STEAM_API_INTERFACES is usually not necessary, but it provides safety against releasing
// new steam_api.dll's without recompiling/rereleasing modules that use it.
//
// If you use VERSION_SAFE_STEAM_API_INTERFACES, then you should call SteamAPI_InitSafe(). Also, to get the 
// Steam interfaces, you must create and Init() a CSteamAPIContext (below) and use the interfaces in there.
//
// If you don't use VERSION_SAFE_STEAM_API_INTERFACES, then you can use SteamAPI_Init() and the SteamXXXX() 
// functions below to get at the Steam interfaces.
//
S_API bool SteamAPI_InitSafe() {
    // TODO: Implement SteamAPI_InitSafe
    return true;
}

S_API bool SteamAPI_Init() {
    // TODO: Implement SteamAPI_Init
    return true;
}

S_API ISteamUser *SteamUser() {
    // TODO: Implement SteamUser
    return g_pSteamUser;
}

S_API ISteamFriends *SteamFriends() {
    // TODO: Implement SteamFriends
    return g_pSteamFriends;
}

S_API ISteamUtils *SteamUtils() {
    // TODO: Implement SteamUtils
    return g_pSteamUtils;
}

S_API ISteamMatchmaking *SteamMatchmaking() {
    // TODO: Implement SteamMatchmaking
    return g_pSteamMatchmaking;
}

S_API ISteamUserStats *SteamUserStats() {
    // TODO: Implement SteamUserStats
    return g_pSteamUserStats;
}

S_API ISteamApps *SteamApps() {
    // TODO: Implement SteamApps
    return g_pSteamApps;
}

S_API ISteamNetworking *SteamNetworking() {
    // TODO: Implement SteamNetworking
    return g_pSteamNetworking;
}

S_API ISteamMatchmakingServers *SteamMatchmakingServers() {
    // TODO: Implement SteamMatchmakingServers
    return g_pSteamMatchmakingServers;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steam callback helper functions
//
//	The following classes/macros are used to be able to easily multiplex callbacks 
//	from the Steam API into various objects in the app in a thread-safe manner
//
//	These functors are triggered via the SteamAPI_RunCallbacks() function, mapping the callback
//  to as many functions/objects as are registered to it
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
S_API void SteamAPI_RunCallbacks() {
    // TODO: Implement SteamAPI_RunCallbacks
}

// functions used by the utility CCallback objects to receive callbacks
S_API void SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback ) {
    // TODO: Implement SteamAPI_RegisterCallback
}

S_API void SteamAPI_UnregisterCallback( class CCallbackBase *pCallback ) {
    // TODO: Implement SteamAPI_UnregisterCallback
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steamclient.dll private wrapper functions
//
//	The following functions are part of abstracting API access to the steamclient.dll, but should only be used in very specific cases
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// pumps out all the steam messages, calling the register callback
S_API void Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks ) {
    // TODO: Implement Steam_RunCallbacks
}

// register the callback funcs to use to interact with the steam dll
S_API void Steam_RegisterInterfaceFuncs( void *hModule ) {
    // TODO: Implement Steam_RegisterInterfaceFuncs
}

// returns the HSteamUser of the last user to dispatch a callback
S_API HSteamUser Steam_GetHSteamUserCurrent() {
    // TODO: Implement Steam_GetHSteamUserCurrent
    return g_hSteamUser;
}

// returns the filename path of the current running Steam process, used if you need to load an explicit steam dll by name
S_API const char *SteamAPI_GetSteamInstallPath() {
    // TODO: Implement SteamAPI_GetSteamInstallPath
    static const char* steamPath = "C:\\Program Files (x86)\\Steam";
    return steamPath;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
// VERSION_SAFE_STEAM_API_INTERFACES uses CSteamAPIContext to provide interfaces to each module in a way that 
// lets them each specify the interface versions they are compiled with.
//
// It's important that these stay inlined in the header so the calling module specifies the interface versions
// for whatever Steam API version it has.
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

S_API HSteamPipe GetHSteamPipe() {
    return g_hSteamPipe;
}

S_API HSteamUser GetHSteamUser() {
    return g_hSteamUser;
}
