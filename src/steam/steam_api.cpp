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

// Global Steam client interface pointer
static CSteamClient* g_pSteamClient = nullptr;

// Global callback manager
static CCallbackMgr* g_pCallbackManager = nullptr;

// Global VaporCore config instance pointer
static VaporCore::Config* g_pVaporConfig = nullptr;

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


// SteamAPI_Init must be called before using any other API functions. If it fails, an
// error message will be output to the debugger (or stderr) with further information.
S_API bool S_CALLTYPE SteamAPI_Init() {
    VLOG_INFO(__FUNCTION__);

#ifdef VAPORCORE_ENABLE_LOGGING
    // Set log level to DEBUG to show all log messages
    VLOG_SET_DEBUG();
#endif

    if(g_hSteamPipe) {
        return true;
    }
    
    // Initialize VaporCore configuration
    g_pVaporConfig = VaporCore::Config::GetInstance();
    if (!g_pVaporConfig) {
        VLOG_ERROR(__FUNCTION__ " - Failed to create VaporCore config instance");
        return false;
    }
    
    // Load configuration file (will use defaults if file doesn't exist)
    g_pVaporConfig->LoadConfig();
    VLOG_DEBUG(__FUNCTION__ " - VaporCore configuration loaded - AppId: %u, SteamId: %llu, Username: %s, Language: %s",
               g_pVaporConfig->GetGameId().AppID(),
               g_pVaporConfig->GetSteamId().ConvertToUint64(),
               g_pVaporConfig->GetUsername().c_str(),
               g_pVaporConfig->GetLanguage().c_str());
    
    // Initialize Steam client
    g_pSteamClient = CSteamClient::GetInstance();

    // Initialize callback manager
    g_pCallbackManager = CCallbackMgr::GetInstance();

    if (!g_pSteamClient) {
        VLOG_ERROR(__FUNCTION__ " - Failed to create Steam client instance");
        return false;
    }
    
    // Create steam pipe and connect to global user
    g_hSteamPipe = g_pSteamClient->CreateSteamPipe();
    g_hSteamUser = g_pSteamClient->ConnectToGlobalUser(g_hSteamPipe);
    g_uSteamAPICallCounter++;

    return true;
}

// SteamAPI_Shutdown should be called during process shutdown if possible.
S_API void S_CALLTYPE SteamAPI_Shutdown() {
    VLOG_INFO(__FUNCTION__);
    
    if (g_pSteamClient && g_hSteamPipe) {
        // Release user and pipe through Steam client
        g_pSteamClient->ReleaseUser(g_hSteamPipe, g_hSteamUser);
        g_pSteamClient->BReleaseSteamPipe(g_hSteamPipe);
        g_pSteamClient->BShutdownIfAllPipesClosed();
    }

    // Release callback manager
    if (g_pCallbackManager) {
        CCallbackMgr::ReleaseInstance();
        g_pCallbackManager = nullptr;
    }

    // Release VaporCore configuration instance
    if (g_pVaporConfig) {
        VaporCore::Config::ReleaseInstance();
        g_pVaporConfig = nullptr;
    }

    // Clean up global interface pointers in the order as in the header
    g_uSteamAPICallCounter--;

    g_hSteamUser = 0;
    g_hSteamPipe = 0;

    if (g_uSteamAPICallCounter == 0) {
        CSteamClient::ReleaseInstance();
        g_pSteamClient = nullptr;
    }
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
    return true;
}

// Most Steam API functions allocate some amount of thread-local memory for parameter storage.
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


// If your application contains modules or libraries which could be built against different SDK
// versions, then you should define VERSION_SAFE_STEAM_API_INTERFACES to enforce that you cannot
// use the un-versioned global accessors. Instead, always create and use CSteamAPIContext objects
// to retrieve interface pointers which match the Steamworks SDK headers which match your build.

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamClient *S_CALLTYPE SteamClient() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamClient017 here, to be updated to macro later when we have more version
    return static_cast<ISteamClient*>(SteamInternal_CreateInterface(STEAMCLIENT_INTERFACE_VERSION));
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUser *S_CALLTYPE SteamUser() {
    VLOG_INFO(__FUNCTION__);
    return g_pSteamClient->GetISteamUser(g_hSteamPipe, g_hSteamUser, STEAMUSER_INTERFACE_VERSION_018);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamFriends *S_CALLTYPE SteamFriends() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamFriends015 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamFriends(g_hSteamPipe, g_hSteamUser, STEAMFRIENDS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUtils *S_CALLTYPE SteamUtils() {
    VLOG_INFO(__FUNCTION__);
    return g_pSteamClient->GetISteamUtils(g_hSteamPipe, STEAMUTILS_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMatchmaking *S_CALLTYPE SteamMatchmaking() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMatchmaking009 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamMatchmaking(g_hSteamPipe, g_hSteamUser, STEAMMATCHMAKING_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUserStats *S_CALLTYPE SteamUserStats() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamUserStats011 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamUserStats(g_hSteamPipe, g_hSteamUser, STEAMUSERSTATS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamApps *S_CALLTYPE SteamApps() {
    VLOG_INFO(__FUNCTION__);
    return g_pSteamClient->GetISteamApps(g_hSteamPipe, g_hSteamUser, STEAMAPPS_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamNetworking *S_CALLTYPE SteamNetworking() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamNetworking005 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamNetworking(g_hSteamPipe, g_hSteamUser, STEAMNETWORKING_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMatchmakingServers *S_CALLTYPE SteamMatchmakingServers() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMatchmakingServers002 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamMatchmakingServers(g_hSteamPipe, g_hSteamUser, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamRemoteStorage *S_CALLTYPE SteamRemoteStorage() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamRemoteStorage013 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamRemoteStorage(g_hSteamPipe, g_hSteamUser, STEAMREMOTESTORAGE_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamScreenshots *S_CALLTYPE SteamScreenshots() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamScreenshots002 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamScreenshots(g_hSteamPipe, g_hSteamUser, STEAMSCREENSHOTS_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamHTTP *S_CALLTYPE SteamHTTP() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamHTTP002 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamHTTP(g_hSteamPipe, g_hSteamUser, STEAMHTTP_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUnifiedMessages *S_CALLTYPE SteamUnifiedMessages() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamUnifiedMessages001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamUnifiedMessages(g_hSteamPipe, g_hSteamUser, STEAMUNIFIEDMESSAGES_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamController *S_CALLTYPE SteamController() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamController003 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamController(g_hSteamPipe, g_hSteamUser, STEAMCONTROLLER_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamUGC *S_CALLTYPE SteamUGC() {
    VLOG_INFO(__FUNCTION__);
    return g_pSteamClient->GetISteamUGC(g_hSteamPipe, g_hSteamUser, STEAMUGC_INTERFACE_VERSION_007);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamAppList *S_CALLTYPE SteamAppList() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamAppList001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamAppList(g_hSteamPipe, g_hSteamUser, STEAMAPPLIST_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMusic *S_CALLTYPE SteamMusic() {
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMusic001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamMusic(g_hSteamPipe, g_hSteamUser, STEAMMUSIC_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamMusicRemote *S_CALLTYPE SteamMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamMusicRemote001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamMusicRemote(g_hSteamPipe, g_hSteamUser, STEAMMUSICREMOTE_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamHTMLSurface *S_CALLTYPE SteamHTMLSurface()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamHTMLSurface003 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamHTMLSurface(g_hSteamPipe, g_hSteamUser, STEAMHTMLSURFACE_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamInventory *S_CALLTYPE SteamInventory()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamInventory001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamInventory(g_hSteamPipe, g_hSteamUser, STEAMINVENTORY_INTERFACE_VERSION);
}

// Removed from Steam SDK v1.37, backward compatibility
S_API ISteamVideo *S_CALLTYPE SteamVideo()
{
    VLOG_INFO(__FUNCTION__);
    // TODO: SteamVideo001 here, to be updated to macro later when we have more version
    return g_pSteamClient->GetISteamVideo(g_hSteamPipe, g_hSteamUser, STEAMVIDEO_INTERFACE_VERSION);
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

// SteamAPI_RunCallbacks is safe to call from multiple threads simultaneously,
// but if you choose to do this, callback code could be executed on any thread.
// One alternative is to call SteamAPI_RunCallbacks from the main thread only,
// and call SteamAPI_ReleaseCurrentThreadMemory regularly on other threads.
S_API void S_CALLTYPE SteamAPI_RunCallbacks()
{
    // Run all pending Steam callbacks and call results
    g_pCallbackManager->RunCallbacks();
}

// Internal functions used by the utility CCallback objects to receive callbacks
S_API void S_CALLTYPE SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p, Callback ID: %d", pCallback, iCallback);
    VAPORCORE_LOCK_GUARD();

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }

    // Determine callback subsystem based on the callback ID ranges
    const char* callbackSubsystemName = "Unknown";
    int callbackBaseId = (iCallback / 100) * 100;
    int callbackOffsetId = iCallback % 100;
    
    switch (callbackBaseId) {
        case k_iSteamUserCallbacks:                     callbackSubsystemName = "SteamUser"; break;
        case k_iSteamGameServerCallbacks:               callbackSubsystemName = "SteamGameServer"; break;
        case k_iSteamFriendsCallbacks:                  callbackSubsystemName = "SteamFriends"; break;
        case k_iSteamBillingCallbacks:                  callbackSubsystemName = "SteamBilling"; break;
        case k_iSteamMatchmakingCallbacks:              callbackSubsystemName = "SteamMatchmaking"; break;
        case k_iSteamContentServerCallbacks:            callbackSubsystemName = "SteamContentServer"; break;
        case k_iSteamUtilsCallbacks:                    callbackSubsystemName = "SteamUtils"; break;
        case k_iClientFriendsCallbacks:                 callbackSubsystemName = "ClientFriends"; break;
        case k_iClientUserCallbacks:                    callbackSubsystemName = "ClientUser"; break;
        case k_iSteamAppsCallbacks:                     callbackSubsystemName = "SteamApps"; break;
        case k_iSteamUserStatsCallbacks:                callbackSubsystemName = "SteamUserStats"; break;
        case k_iSteamNetworkingCallbacks:               callbackSubsystemName = "SteamNetworking"; break;
        case k_iClientRemoteStorageCallbacks:           callbackSubsystemName = "ClientRemoteStorage"; break;
        case k_iClientDepotBuilderCallbacks:            callbackSubsystemName = "ClientDepotBuilder"; break;
        case k_iSteamGameServerItemsCallbacks:          callbackSubsystemName = "SteamGameServerItems"; break;
        case k_iClientUtilsCallbacks:                   callbackSubsystemName = "ClientUtils"; break;
        case k_iSteamGameCoordinatorCallbacks:          callbackSubsystemName = "SteamGameCoordinator"; break;
        case k_iSteamGameServerStatsCallbacks:          callbackSubsystemName = "SteamGameServerStats"; break;
        case k_iSteam2AsyncCallbacks:                   callbackSubsystemName = "Steam2Async"; break;
        case k_iSteamGameStatsCallbacks:                callbackSubsystemName = "SteamGameStats"; break;
        case k_iClientHTTPCallbacks:                    callbackSubsystemName = "ClientHTTP"; break;
        case k_iClientScreenshotsCallbacks:             callbackSubsystemName = "ClientScreenshots"; break;
        case k_iSteamScreenshotsCallbacks:              callbackSubsystemName = "SteamScreenshots"; break;
        case k_iClientAudioCallbacks:                   callbackSubsystemName = "ClientAudio"; break;
        case k_iClientUnifiedMessagesCallbacks:         callbackSubsystemName = "ClientUnifiedMessages"; break;
        case k_iSteamStreamLauncherCallbacks:           callbackSubsystemName = "SteamStreamLauncher"; break;
        case k_iClientControllerCallbacks:              callbackSubsystemName = "ClientController"; break;
        case k_iSteamControllerCallbacks:               callbackSubsystemName = "SteamController"; break;
        case k_iClientParentalSettingsCallbacks:        callbackSubsystemName = "ClientParentalSettings"; break;
        case k_iClientDeviceAuthCallbacks:              callbackSubsystemName = "ClientDeviceAuth"; break;
        case k_iClientNetworkDeviceManagerCallbacks:    callbackSubsystemName = "ClientNetworkDeviceManager"; break;
        case k_iClientMusicCallbacks:                   callbackSubsystemName = "ClientMusic"; break;
        case k_iClientRemoteClientManagerCallbacks:     callbackSubsystemName = "ClientRemoteClientManager"; break;
        case k_iClientUGCCallbacks:                     callbackSubsystemName = "ClientUGC"; break;
        case k_iSteamStreamClientCallbacks:             callbackSubsystemName = "SteamStreamClient"; break;
        case k_IClientProductBuilderCallbacks:          callbackSubsystemName = "ClientProductBuilder"; break;
        case k_iClientShortcutsCallbacks:               callbackSubsystemName = "ClientShortcuts"; break;
        case k_iClientRemoteControlManagerCallbacks:    callbackSubsystemName = "ClientRemoteControlManager"; break;
        case k_iSteamAppListCallbacks:                  callbackSubsystemName = "SteamAppList"; break;
        case k_iSteamMusicCallbacks:                    callbackSubsystemName = "SteamMusic"; break;
        case k_iSteamMusicRemoteCallbacks:              callbackSubsystemName = "SteamMusicRemote"; break;
        case k_iClientVRCallbacks:                      callbackSubsystemName = "ClientVR"; break;
        case k_iClientGameNotificationCallbacks:        callbackSubsystemName = "ClientGameNotification"; break;
        case k_iSteamGameNotificationCallbacks:         callbackSubsystemName = "SteamGameNotification"; break;
        case k_iSteamHTMLSurfaceCallbacks:              callbackSubsystemName = "SteamHTMLSurface"; break;
        case k_iClientVideoCallbacks:                   callbackSubsystemName = "ClientVideo"; break;
        case k_iClientInventoryCallbacks:               callbackSubsystemName = "ClientInventory"; break;
        case k_iClientBluetoothManagerCallbacks:        callbackSubsystemName = "ClientBluetoothManager"; break;
        default:
            VLOG_WARNING(__FUNCTION__ " - Unknown callback subsystem for ID %d (baseId=%d)", iCallback, callbackBaseId);
            break;
    }
    
    VLOG_DEBUG(__FUNCTION__ " - Registering %s callback: baseId=%d offsetId=%d (fullId=%d)", 
               callbackSubsystemName, callbackBaseId, callbackOffsetId, iCallback);

    // Note: In a real Steam implementation, the callback would be registered with Steam client
    // For emulation purposes, we would maintain our own callback registry here
    g_pCallbackManager->RegisterCallback(pCallback, iCallback);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallback( class CCallbackBase *pCallback )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p", pCallback);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }
    
    // Unregister the callback from our callback manager
    g_pCallbackManager->UnregisterCallback(pCallback);
}

// Internal functions used by the utility CCallResult objects to receive async call results
S_API void S_CALLTYPE SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p, API Call: %d", pCallback, hAPICall);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }
    
    // Register the callback with our callback manager to handle the async call result
    g_pCallbackManager->RegisterCallResult(pCallback, hAPICall);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p, API Call: %d", pCallback, hAPICall);
   
    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }
    
    // Unregister the callback from our callback manager to stop receiving async call results
    g_pCallbackManager->UnregisterCallResult(pCallback, hAPICall);
}


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

// returns the pipe we are communicating to Steam with
S_API HSteamPipe SteamAPI_GetHSteamPipe() {
    VLOG_INFO(__FUNCTION__ " - SteamPipe: %d", g_hSteamPipe);
    return g_hSteamPipe;
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

// backwards compat with older SDKs
S_API bool S_CALLTYPE SteamAPI_InitSafe() {
    VLOG_INFO(__FUNCTION__);
    return SteamAPI_Init();
}
