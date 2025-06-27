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
#include <steam_api_internal.h>

#include "vapor_base.h"

S_API HSteamUser SteamAPI_GetHSteamUser()
{
    VLOG_INFO(__FUNCTION__);
    // Use the public API to get the current user handle
    return Steam_GetHSteamUserCurrent();
}

S_API bool S_CALLTYPE SteamInternal_Init()
{
    VLOG_DEBUG("SteamInternal_Init called");
    return true;
}

S_API void * S_CALLTYPE SteamInternal_CreateInterface( const char *ver )
{
    VLOG_DEBUG("SteamInternal_CreateInterface called - Version: %s", ver);

    if (!ver) {
        VLOG_ERROR("SteamInternal_CreateInterface: Invalid version string (null)");
        return nullptr;
    }

    // Get the Steam client through the public API
    CSteamClient* pSteamClient = CSteamClient::GetInstance();

    if (!pSteamClient) {
        VLOG_ERROR("SteamInternal_CreateInterface: Steam client not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamClient (latest) - %s", STEAMCLIENT_INTERFACE_VERSION);
        return static_cast<ISteamClient*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_016) == 0) {
        VLOG_DEBUG("Returning ISteamClient016");
        return static_cast<ISteamClient016*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_015) == 0) {
        VLOG_DEBUG("Returning ISteamClient015");
        return static_cast<ISteamClient015*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_014) == 0) {
        VLOG_DEBUG("Returning ISteamClient014");
        return static_cast<ISteamClient014*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_012) == 0) {
        VLOG_DEBUG("Returning ISteamClient012");
        return static_cast<ISteamClient012*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_011) == 0) {
        VLOG_DEBUG("Returning ISteamClient011");
        return static_cast<ISteamClient011*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_010) == 0) {
        VLOG_DEBUG("Returning ISteamClient010");
        return static_cast<ISteamClient010*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_009) == 0) {
        VLOG_DEBUG("Returning ISteamClient009");
        return static_cast<ISteamClient009*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_008) == 0) {
        VLOG_DEBUG("Returning ISteamClient008");
        return static_cast<ISteamClient008*>(pSteamClient);
    } else if (strcmp(ver, STEAMCLIENT_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamClient007");
        return static_cast<ISteamClient007*>(pSteamClient);
    } else {
        VLOG_WARNING("SteamInternal_CreateInterface: Unknown interface version '%s', returning " STEAMCLIENT_INTERFACE_VERSION, ver);
        // Return the latest interface as fallback
        return static_cast<ISteamClient*>(pSteamClient);
    }
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
    VLOG_DEBUG("SteamAPI_UseBreakpadCrashHandler called - Version: %s, Date: %s, Time: %s", pchVersion, pchDate, pchTime);
}

S_API void S_CALLTYPE SteamAPI_SetBreakpadAppID( uint32 unAppID )
{
    VLOG_DEBUG("SteamAPI_SetBreakpadAppID called - AppID: %u", unAppID);
}
