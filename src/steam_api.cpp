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

#include "logger.h"
#include "steam_client.h"

// Global Steam client interface pointer
static Steam_Client* g_pSteamClient = nullptr;

// Global interface pointers
static ISteamUser* g_pSteamUser = nullptr;
static ISteamFriends* g_pSteamFriends = nullptr;
static ISteamUtils* g_pSteamUtils = nullptr;
static ISteamMatchmaking* g_pSteamMatchmaking = nullptr;
static ISteamUserStats* g_pSteamUserStats = nullptr;
static ISteamApps* g_pSteamApps = nullptr;
static ISteamNetworking* g_pSteamNetworking = nullptr;
static ISteamMatchmakingServers* g_pSteamMatchmakingServers = nullptr;
static ISteamRemoteStorage* g_pSteamRemoteStorage = nullptr;
static ISteamHTTP* g_pSteamHTTP = nullptr;

// Global pipe and user handles
static HSteamPipe g_hSteamPipe = 0;
static HSteamUser g_hSteamUser = 0;

// Global initialization counter
static uintp g_uSteamAPICallCounter = 0;

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam API setup & shutdown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// S_API void SteamAPI_Init(); (see below)
S_API void SteamAPI_Shutdown() {
    // TODO: Implement SteamAPI_Shutdown
    VLOG_INFO("SteamAPI_Shutdown called");
    
    if (g_pSteamClient && g_hSteamPipe) {
        // Release user and pipe through Steam client
        //g_pSteamClient->ReleaseUser(g_hSteamPipe, g_hSteamUser);
        g_pSteamClient->BReleaseSteamPipe(g_hSteamPipe);
    }

    // Clean up global interface pointers in the order as in the header
    g_uSteamAPICallCounter--;

    g_pSteamUser = nullptr;
    g_pSteamFriends = nullptr;
    g_pSteamUtils = nullptr;
    g_pSteamMatchmaking = nullptr;
    g_pSteamMatchmakingServers = nullptr;
    g_pSteamUserStats = nullptr;
    g_pSteamApps = nullptr;
    g_pSteamNetworking = nullptr;

    g_hSteamUser = 0;
    g_hSteamPipe = 0;

    if (g_uSteamAPICallCounter == 0) {
        Steam_Client::ReleaseInstance();
        g_pSteamClient = nullptr;
    }
    
    VLOG_INFO("SteamAPI_Shutdown completed");
}

// checks if a local Steam client is running 
S_API bool SteamAPI_IsSteamRunning()
{
    VLOG_DEBUG("SteamAPI_IsSteamRunning called");
    return true;
}

// restart your app through Steam to enable required Steamworks features
// Removed from Steam SDK v1.07, backward compatibility
S_API bool SteamAPI_RestartApp( uint32 unOwnAppID )
{
    VLOG_DEBUG("SteamAPI_RestartApp called - AppID: %d", unOwnAppID);
    return true;
}

// Detects if your executable was launched through the Steam client, and restarts your game through 
// the client if necessary. The Steam client will be started if it is not running.
//
// Returns: true if your executable was NOT launched through the Steam client. This function will
//          then start your application through the client. Your current process should exit.
//
//          false if your executable was started through the Steam client or a steam_appid.txt file
//          is present in your game's directory (for development). Your current process should continue.
//
// NOTE: This function should be used only if you are using CEG or not using Steam's DRM. Once applied
//       to your executable, Steam's DRM will handle restarting through Steam if necessary.
S_API bool SteamAPI_RestartAppIfNecessary( uint32 unOwnAppID )
{
    VLOG_DEBUG("SteamAPI_RestartAppIfNecessary called - AppID: %d", unOwnAppID);
    return true;
}

// crash dump recording functions
S_API void SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID )
{
    VLOG_DEBUG("SteamAPI_WriteMiniDump called - Structured Exception Code: %d, Exception Info: %p, Build ID: %d", uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}

S_API void SteamAPI_SetMiniDumpComment( const char *pchMsg )
{
    VLOG_DEBUG("SteamAPI_SetMiniDumpComment called - Comment: %s", pchMsg);
}

// this should be called before the game initialized the steam APIs
// pchDate should be of the format "Mmm dd yyyy" (such as from the __DATE__ macro )
// pchTime should be of the format "hh:mm:ss" (such as from the __TIME__ macro )
// bFullMemoryDumps (Win32 only) -- writes out a uuid-full.dmp in the client/dumps folder
// pvContext-- can be NULL, will be the void * context passed into m_pfnPreMinidumpCallback
// PFNPreMinidumpCallback m_pfnPreMinidumpCallback   -- optional callback which occurs just before a .dmp file is written during a crash.  Applications can hook this to allow adding additional information into the .dmp comment stream.
// Steam SDK v1.09
// S_API void SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime )
// Steam SDK v1.10
S_API void SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime, bool bFullMemoryDumps, void *pvContext, PFNPreMinidumpCallback m_pfnPreMinidumpCallback )
{
    VLOG_DEBUG("SteamAPI_UseBreakpadCrashHandler called - Version: %s, Date: %s, Time: %s", pchVersion, pchDate, pchTime);
}

S_API void SteamAPI_SetBreakpadAppID( uint32 unAppID )
{
    VLOG_DEBUG("SteamAPI_SetBreakpadAppID called - AppID: %u", unAppID);
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
    VLOG_INFO("SteamAPI_InitSafe called");
    return SteamAPI_Init();
}

S_API bool SteamAPI_Init() {
    // TODO: Implement SteamAPI_Init
#ifdef VAPORCORE_ENABLE_LOGGING
    // Initialize logger
    VaporCore::Logger::getInstance().initialize("vaporcore_log.txt");
#endif

    VLOG_INFO("SteamAPI_Init called");

    if(g_hSteamPipe) {
        VLOG_INFO("SteamAPI_Init already initialized");
        return true;
    }
    
    // Initialize Steam client
    g_pSteamClient = Steam_Client::GetInstance();
    if (!g_pSteamClient) {
        VLOG_ERROR("Failed to create Steam client instance");
        return false;
    }
    
    // Create steam pipe and connect to global user
    g_hSteamPipe = g_pSteamClient->CreateSteamPipe();
    g_hSteamUser = g_pSteamClient->ConnectToGlobalUser(g_hSteamPipe);
    g_uSteamAPICallCounter++;

    /*
    if (g_hSteamPipe == 0 || g_hSteamUser == 0) {
        VLOG_ERROR("Failed to create Steam pipe or connect to user");
        return false;
    }
    
    // Get interface pointers
    g_pSteamUser = g_pSteamClient->GetISteamUser(g_hSteamUser, g_hSteamPipe, STEAMUSER_INTERFACE_VERSION);
    g_pSteamFriends = g_pSteamClient->GetISteamFriends(g_hSteamUser, g_hSteamPipe, STEAMFRIENDS_INTERFACE_VERSION);
    g_pSteamUtils = g_pSteamClient->GetISteamUtils(g_hSteamPipe, STEAMUTILS_INTERFACE_VERSION);
    g_pSteamMatchmaking = g_pSteamClient->GetISteamMatchmaking(g_hSteamUser, g_hSteamPipe, STEAMMATCHMAKING_INTERFACE_VERSION);
    g_pSteamUserStats = g_pSteamClient->GetISteamUserStats(g_hSteamUser, g_hSteamPipe, STEAMUSERSTATS_INTERFACE_VERSION);
    g_pSteamApps = g_pSteamClient->GetISteamApps(g_hSteamUser, g_hSteamPipe, STEAMAPPS_INTERFACE_VERSION);
    g_pSteamNetworking = g_pSteamClient->GetISteamNetworking(g_hSteamUser, g_hSteamPipe, STEAMNETWORKING_INTERFACE_VERSION);
    g_pSteamMatchmakingServers = g_pSteamClient->GetISteamMatchmakingServers(g_hSteamUser, g_hSteamPipe, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION);

    VLOG_INFO("SteamAPI_Init completed successfully");
    */

    return true;
}

S_API ISteamUser *SteamUser() {
    // TODO: Implement SteamUser
    VLOG_DEBUG("SteamUser() called");
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

S_API ISteamRemoteStorage *SteamRemoteStorage() {
    // TODO: Implement SteamRemoteStorage
    return g_pSteamRemoteStorage;
}

S_API ISteamHTTP *SteamHTTP() {
    // TODO: Implement SteamHTTP
    return g_pSteamHTTP;
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

// functions used by the utility CCallResult objects to receive async call results
S_API void SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall ) {
    // TODO: Implement SteamAPI_RegisterCallResult
}

S_API void SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall ) {
    // TODO: Implement SteamAPI_UnregisterCallResult
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

// returns the pipe we are communicating to Steam with
S_API HSteamPipe SteamAPI_GetHSteamPipe() {
    // TODO: Implement SteamAPI_GetHSteamPipe
    return g_hSteamPipe;
}

// sets whether or not Steam_RunCallbacks() should do a try {} catch (...) {} around calls to issuing callbacks
S_API void SteamAPI_SetTryCatchCallbacks( bool bTryCatchCallbacks ) {
    // TODO: Implement SteamAPI_SetTryCatchCallbacks
}

// backwards compat export, passes through to SteamAPI_ variants
S_API HSteamPipe GetHSteamPipe() {
    return g_hSteamPipe;
}

S_API HSteamUser GetHSteamUser() {
    return g_hSteamUser;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
// VERSION_SAFE_STEAM_API_INTERFACES uses CSteamAPIContext to provide interfaces to each module in a way that 
// lets them each specify the interface versions they are compiled with.
//
// It's important that these stay inlined in the header so the calling module specifies the interface versions
// for whatever Steam API version it has.
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

S_API HSteamUser SteamAPI_GetHSteamUser() {
    // TODO: Implement SteamAPI_GetHSteamUser
    return g_hSteamUser;
}
