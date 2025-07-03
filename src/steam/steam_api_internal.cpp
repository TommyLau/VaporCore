/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include <steam_api.h>
#include <steam_api_common.h>

#include "vapor_base.h"

// Global pipe and user handles for game server
static HSteamPipe g_hSteamGameServerPipe = 0;
static HSteamUser g_hSteamGameServerUser = 0;

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
    CCallbackMgr::GetInstance().RegisterCallback(pCallback, iCallback);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallback( class CCallbackBase *pCallback )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p", pCallback);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }
    
    // Unregister the callback from our callback manager
    CCallbackMgr::GetInstance().UnregisterCallback(pCallback);
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
    CCallbackMgr::GetInstance().RegisterCallResult(pCallback, hAPICall);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
    VLOG_INFO(__FUNCTION__ " - Callback: %p, API Call: %d", pCallback, hAPICall);
   
    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback pointer");
        return;
    }
    
    // Unregister the callback from our callback manager to stop receiving async call results
    CCallbackMgr::GetInstance().UnregisterCallResult(pCallback, hAPICall);
}


S_API HSteamPipe S_CALLTYPE SteamAPI_GetHSteamPipe() {
    VLOG_INFO(__FUNCTION__ " - SteamPipe: %d", GetHSteamPipe());
    return GetHSteamPipe();
}

S_API HSteamUser S_CALLTYPE SteamAPI_GetHSteamUser()
{
    VLOG_INFO(__FUNCTION__ " HSteamUser: %d", GetHSteamUser());
    // Use the public API to get the current user handle
    return GetHSteamUser();
}

S_API HSteamPipe S_CALLTYPE SteamGameServer_GetHSteamPipe()
{
    VLOG_INFO(__FUNCTION__ " - SteamPipe: %d", g_hSteamGameServerPipe);
    return g_hSteamGameServerPipe;
}

S_API HSteamUser S_CALLTYPE SteamGameServer_GetHSteamUser()
{
    VLOG_INFO(__FUNCTION__ " - HSteamUser: %d", g_hSteamGameServerUser);
    return g_hSteamGameServerUser;
}

// Removed from Steam SDK v1.38, backward compatibility
S_API bool S_CALLTYPE SteamInternal_Init()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

struct ContextInitData {
    void (*pfnInit)(void*);  // SteamInternal_OnContextInit function pointer
    uintp counter;           // Global init counter
    CSteamAPIContext ctx;    // The context instance
};

S_API void * S_CALLTYPE SteamInternal_ContextInit( void *pContextInitData )
{
    if (!pContextInitData) {
        VLOG_ERROR(__FUNCTION__);
        return nullptr;
    }

    ContextInitData *pData = (ContextInitData*)pContextInitData;
    uintp uCallCounter = CSteamClient::GetInstance().GetCallCounter();

    // Check if the counter is different from the current counter
    if (pData->counter != uCallCounter) {
        VLOG_DEBUG(__FUNCTION__ " - data: %p, init fn: %p, counter: %lu, ctx: %p, current counter: %lu",
                  pData, pData->pfnInit, pData->counter, &pData->ctx, uCallCounter);

        // Call the context init function 
        if (pData->pfnInit) {
            pData->pfnInit(&pData->ctx);
        }

        // Set counter to prevent re-initialization of this context
        pData->counter = uCallCounter;
    }

    return &pData->ctx;
}

// Steam SDK v1.10
S_API void * S_CALLTYPE SteamInternal_CreateInterface( const char *ver )
{
    VLOG_INFO(__FUNCTION__ " - Version: %s", ver);

    if (!ver) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Get the Steam client through the public API - store reference first
    CSteamClient& steamClient = CSteamClient::GetInstance();

    // Return the appropriate interface version based on the version string
    if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamClient (latest) - %s", STEAMCLIENT_INTERFACE_VERSION);
        return &steamClient;
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_016) == 0) {
        VLOG_DEBUG("Returning ISteamClient016");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient016*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_015) == 0) {
        VLOG_DEBUG("Returning ISteamClient015");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient015*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_014) == 0) {
        VLOG_DEBUG("Returning ISteamClient014");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient014*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_012) == 0) {
        VLOG_DEBUG("Returning ISteamClient012");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient012*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_011) == 0) {
        VLOG_DEBUG("Returning ISteamClient011");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient011*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_010) == 0) {
        VLOG_DEBUG("Returning ISteamClient010");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient010*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_009) == 0) {
        VLOG_DEBUG("Returning ISteamClient009");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient009*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_008) == 0) {
        VLOG_DEBUG("Returning ISteamClient008");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient008*>(&steamClient));
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamClient007");
        return reinterpret_cast<ISteamClient*>(static_cast<ISteamClient007*>(&steamClient));
    } else {
        VLOG_WARNING(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMCLIENT_INTERFACE_VERSION, ver);
        // Return the latest interface as fallback
        return &steamClient;
    }
}

S_API void *S_CALLTYPE SteamInternal_FindOrCreateUserInterface( HSteamUser hSteamUser, const char *pszVersion )
{
    VLOG_INFO(__FUNCTION__ " - SteamUser: %d, Version: %s", hSteamUser, pszVersion);
    
    if (!pszVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    return CSteamClient::GetInstance().GetISteamGenericInterface(hSteamUser, SteamAPI_GetHSteamPipe(), pszVersion);
}

S_API void *S_CALLTYPE SteamInternal_FindOrCreateGameServerInterface( HSteamUser hSteamUser, const char *pszVersion )
{
    VLOG_INFO(__FUNCTION__ " - SteamUser: %d, Version: %s", hSteamUser, pszVersion);

    if (!pszVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    return CSteamClient::GetInstance().GetISteamGenericInterface(hSteamUser, SteamGameServer_GetHSteamPipe(), pszVersion);
}
