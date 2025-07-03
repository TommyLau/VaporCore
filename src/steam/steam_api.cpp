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

#include <steam_api.h>

#include "vapor_base.h"

// Global pipe and user handles
static HSteamPipe g_hSteamPipe = 0;
static HSteamUser g_hSteamUser = 0;

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam API setup & shutdown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//


// SteamAPI_Init must be called before using any other API functions. If it fails, an
// error message will be output to the debugger (or stderr) with further information.
S_API bool S_CALLTYPE SteamAPI_Init() {
    VLOG_INFO(__FUNCTION__);

    if(g_hSteamPipe) {
        return true;
    }
    
    // Load configuration file (will use defaults if file doesn't exist)
    VLOG_DEBUG(__FUNCTION__ " - VaporCore configuration loaded - AppId: %u, SteamId: %llu, Username: %s, Language: %s",
               VaporCore::Config::GetInstance().GameID().AppID(),
               VaporCore::Config::GetInstance().SteamID().ConvertToUint64(),
               VaporCore::Config::GetInstance().PersonaName(),
               VaporCore::Config::GetInstance().Language());
    
    // Create steam pipe and connect to global user
    g_hSteamPipe = CSteamClient::GetInstance().CreateSteamPipe();
    g_hSteamUser = CSteamClient::GetInstance().ConnectToGlobalUser(g_hSteamPipe);
    CSteamClient::GetInstance().IncrementCallCounter();

    return true;
}

// SteamAPI_Shutdown should be called during process shutdown if possible.
S_API void S_CALLTYPE SteamAPI_Shutdown() {
    VLOG_INFO(__FUNCTION__);
    
    if (g_hSteamPipe) {
        // Release user and pipe through Steam client
        CSteamClient::GetInstance().ReleaseUser(g_hSteamPipe, g_hSteamUser);
        CSteamClient::GetInstance().BReleaseSteamPipe(g_hSteamPipe);
        CSteamClient::GetInstance().BShutdownIfAllPipesClosed();
    }

    // Clean up global interface pointers in the order as in the header
    CSteamClient::GetInstance().DecrementCallCounter();

    g_hSteamUser = 0;
    g_hSteamPipe = 0;
}

// restart your app through Steam to enable required Steamworks features
// Removed from Steam SDK v1.07, backward compatibility
S_API bool S_CALLTYPE SteamAPI_RestartApp( uint32 unOwnAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d", unOwnAppID);
    return true;
}

// SteamAPI_RestartAppIfNecessary ensures that your executable was launched through Steam.
//
// Returns true if the current process should terminate. Steam is now re-launching your application.
//
// Returns false if no action needs to be taken. This means that your executable was started through
// the Steam client, or a steam_appid.txt file is present in your game's directory (for development).
// Your current process should continue if false is returned.
//
// NOTE: If you use the Steam DRM wrapper on your primary executable file, this check is unnecessary
// since the DRM wrapper will ensure that your application was launched properly through Steam.
S_API bool S_CALLTYPE SteamAPI_RestartAppIfNecessary( uint32 unOwnAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d", unOwnAppID);

    if (unOwnAppID != 0 && !VaporCore::Config::GetInstance().GameID().AppID())
    {
        VLOG_DEBUG(__FUNCTION__ " - Setting AppID: %d", unOwnAppID);
        VaporCore::Config::GetInstance().SetGameID(unOwnAppID);
    }

    return false;
}

// Many Steam API functions allocate a small amount of thread-local memory for parameter storage.
// SteamAPI_ReleaseCurrentThreadMemory() will free API memory associated with the calling thread.
// This function is also called automatically by SteamAPI_RunCallbacks(), so a single-threaded
// program never needs to explicitly call this function.
S_API void S_CALLTYPE SteamAPI_ReleaseCurrentThreadMemory()
{
    VLOG_INFO(__FUNCTION__);
}


// crash dump recording functions
S_API void S_CALLTYPE SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID )
{
    VLOG_INFO(__FUNCTION__ " - Structured Exception Code: %d, Exception Info: %p, Build ID: %d", uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}

S_API void S_CALLTYPE SteamAPI_SetMiniDumpComment( const char *pchMsg )
{
    VLOG_INFO(__FUNCTION__ " - Comment: %s", pchMsg);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------//
// Global accessors for Steamworks C++ APIs. See individual isteam*.h files for details.
// You should not cache the results of these accessors or pass the result pointers across
// modules! Different modules may be compiled against different SDK header versions, and
// the interface pointers could therefore be different across modules. Every line of code
// which calls into a Steamworks API should retrieve the interface from a global accessor.
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamClient *S_CALLTYPE SteamClient() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamClient017 here, to be updated to macro later when we have more version
    return static_cast<ISteamClient*>(SteamInternal_CreateInterface(STEAMCLIENT_INTERFACE_VERSION));
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUser *S_CALLTYPE SteamUser() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamUser(g_hSteamPipe, g_hSteamUser, STEAMUSER_INTERFACE_VERSION_018);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamFriends *S_CALLTYPE SteamFriends() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamFriends015 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamFriends(g_hSteamPipe, g_hSteamUser, STEAMFRIENDS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUtils *S_CALLTYPE SteamUtils() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamUtils(g_hSteamPipe, STEAMUTILS_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMatchmaking *S_CALLTYPE SteamMatchmaking() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMatchmaking009 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamMatchmaking(g_hSteamPipe, g_hSteamUser, STEAMMATCHMAKING_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUserStats *S_CALLTYPE SteamUserStats() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamUserStats011 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamUserStats(g_hSteamPipe, g_hSteamUser, STEAMUSERSTATS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamApps *S_CALLTYPE SteamApps() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamApps(g_hSteamPipe, g_hSteamUser, STEAMAPPS_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamNetworking *S_CALLTYPE SteamNetworking() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamNetworking005 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamNetworking(g_hSteamPipe, g_hSteamUser, STEAMNETWORKING_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMatchmakingServers *S_CALLTYPE SteamMatchmakingServers() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMatchmakingServers002 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamMatchmakingServers(g_hSteamPipe, g_hSteamUser, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamRemoteStorage *S_CALLTYPE SteamRemoteStorage() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamRemoteStorage(g_hSteamPipe, g_hSteamUser, STEAMREMOTESTORAGE_INTERFACE_VERSION_013);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamScreenshots *S_CALLTYPE SteamScreenshots() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamScreenshots(g_hSteamPipe, g_hSteamUser, STEAMSCREENSHOTS_INTERFACE_VERSION_002);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamHTTP *S_CALLTYPE SteamHTTP() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamHTTP002 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamHTTP(g_hSteamPipe, g_hSteamUser, STEAMHTTP_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUnifiedMessages *S_CALLTYPE SteamUnifiedMessages() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamUnifiedMessages001 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamUnifiedMessages(g_hSteamPipe, g_hSteamUser, STEAMUNIFIEDMESSAGES_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamController *S_CALLTYPE SteamController() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamController(g_hSteamPipe, g_hSteamUser, STEAMCONTROLLER_INTERFACE_VERSION_003);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUGC *S_CALLTYPE SteamUGC() {
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamUGC(g_hSteamPipe, g_hSteamUser, STEAMUGC_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamAppList *S_CALLTYPE SteamAppList() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamAppList001 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamAppList(g_hSteamPipe, g_hSteamUser, STEAMAPPLIST_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMusic *S_CALLTYPE SteamMusic() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMusic001 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamMusic(g_hSteamPipe, g_hSteamUser, STEAMMUSIC_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMusicRemote *S_CALLTYPE SteamMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMusicRemote001 here, to be updated to macro later when we have more version
    return CSteamClient::GetInstance().GetISteamMusicRemote(g_hSteamPipe, g_hSteamUser, STEAMMUSICREMOTE_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamHTMLSurface *S_CALLTYPE SteamHTMLSurface()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamHTMLSurface(g_hSteamPipe, g_hSteamUser, STEAMHTMLSURFACE_INTERFACE_VERSION_003);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamInventory *S_CALLTYPE SteamInventory()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamInventory(g_hSteamPipe, g_hSteamUser, STEAMINVENTORY_INTERFACE_VERSION_001);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamVideo *S_CALLTYPE SteamVideo()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamClient::GetInstance().GetISteamVideo(g_hSteamPipe, g_hSteamUser, STEAMVIDEO_INTERFACE_VERSION_001);
}

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


//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steamclient.dll private wrapper functions
//
//	The following functions are part of abstracting API access to the steamclient.dll, but should only be used in very specific cases
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// SteamAPI_IsSteamRunning() returns true if Steam is currently running
S_API bool S_CALLTYPE SteamAPI_IsSteamRunning()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// Pumps out all the steam messages, calling registered callbacks.
// NOT THREADSAFE - do not call from multiple threads simultaneously.
S_API void Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks )
{
    // TODO: Implement Steam_RunCallbacks
    VLOG_INFO(__FUNCTION__ " - Steam Pipe: %d, Game Server Callbacks: %d", hSteamPipe, bGameServerCallbacks);
}

// register the callback funcs to use to interact with the steam dll
S_API void Steam_RegisterInterfaceFuncs( void *hModule )
{
    // TODO: Implement Steam_RegisterInterfaceFuncs
    VLOG_INFO(__FUNCTION__ " - Module: %p", hModule);
}

// returns the HSteamUser of the last user to dispatch a callback
S_API HSteamUser Steam_GetHSteamUserCurrent()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: Implement Steam_GetHSteamUserCurrent
    return g_hSteamUser;
}

// returns the filename path of the current running Steam process, used if you need to load an explicit steam dll by name.
// DEPRECATED - implementation is Windows only, and the path returned is a UTF-8 string which must be converted to UTF-16 for use with Win32 APIs
S_API const char *SteamAPI_GetSteamInstallPath()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: Implement SteamAPI_GetSteamInstallPath
    static const char* steamPath = "C:\\Program Files (x86)\\Steam";
    return steamPath;
}

// sets whether or not Steam_RunCallbacks() should do a try {} catch (...) {} around calls to issuing callbacks
S_API void SteamAPI_SetTryCatchCallbacks( bool bTryCatchCallbacks ) {
    VLOG_INFO(__FUNCTION__ " - Try Catch Callbacks: %d", bTryCatchCallbacks);
    // TODO: Implement SteamAPI_SetTryCatchCallbacks
}

// backwards compat export, passes through to SteamAPI_ variants
S_API HSteamPipe GetHSteamPipe() {
    VLOG_INFO(__FUNCTION__);
    return g_hSteamPipe;
}

S_API HSteamUser GetHSteamUser() {
    VLOG_INFO(__FUNCTION__ " - SteamUser: %d", g_hSteamUser);
    return g_hSteamUser;
}

// exists only for backwards compat with code written against older SDKs
S_API bool S_CALLTYPE SteamAPI_InitSafe() {
    VLOG_INFO(__FUNCTION__);
    return SteamAPI_Init();
}

// this should be called before the game initialized the steam APIs
// pchDate should be of the format "Mmm dd yyyy" (such as from the __ DATE __ macro )
// pchTime should be of the format "hh:mm:ss" (such as from the __ TIME __ macro )
// bFullMemoryDumps (Win32 only) -- writes out a uuid-full.dmp in the client/dumps folder
// pvContext-- can be NULL, will be the void * context passed into m_pfnPreMinidumpCallback
// PFNPreMinidumpCallback m_pfnPreMinidumpCallback   -- optional callback which occurs just before a .dmp file is written during a crash.  Applications can hook this to allow adding additional information into the .dmp comment stream.
// Steam SDK v1.09
// S_API void SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime )
// Steam SDK v1.10
S_API void S_CALLTYPE SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime, bool bFullMemoryDumps, void *pvContext, PFNPreMinidumpCallback m_pfnPreMinidumpCallback )
{
    VLOG_INFO(__FUNCTION__ " - Version: %s, Date: %s, Time: %s", pchVersion, pchDate, pchTime);
}

S_API void S_CALLTYPE SteamAPI_SetBreakpadAppID( uint32 unAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", unAppID);
}
