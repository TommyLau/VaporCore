/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <steam_api.h>
#include <steam_api_internal.h>

#include "logger.h"

// Global pipe and user handles
static HSteamUser g_hSteamUser = 0;

S_API HSteamUser SteamAPI_GetHSteamUser()
{
    // TODO: Implement SteamAPI_GetHSteamUser
    return g_hSteamUser;
}

S_API bool S_CALLTYPE SteamInternal_Init()
{
    VLOG_DEBUG("SteamInternal_Init called");
    return true;
}

S_API void * S_CALLTYPE SteamInternal_CreateInterface( const char *ver )
{
    VLOG_DEBUG("SteamInternal_CreateInterface called - Version: %s", ver);
    return nullptr;
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
