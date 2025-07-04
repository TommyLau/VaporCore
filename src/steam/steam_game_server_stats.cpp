/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "vapor_base.h"
#include "steam_game_server_stats.h"

CSteamGameServerStats::CSteamGameServerStats()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameServerStats::~CSteamGameServerStats()
{
    VLOG_INFO(__FUNCTION__);
}

// downloads stats for the user
// returns a GSStatsReceived_t callback when completed
// if the user has no stats, GSStatsReceived_t.m_eResult will be set to k_EResultFail
// these stats will only be auto-updated for clients playing on the server. For other
// users you'll need to call RequestUserStats() again to refresh any data
STEAM_CALL_RESULT( GSStatsReceived_t )
SteamAPICall_t CSteamGameServerStats::RequestUserStats( CSteamID steamIDUser )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu", steamIDUser.ConvertToUint64());
    return 0;
}

// requests stat information for a user, usable after a successful call to RequestUserStats()
STEAM_FLAT_NAME( GetUserStatInt32 )
bool CSteamGameServerStats::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

STEAM_FLAT_NAME( GetUserStatFloat )
bool CSteamGameServerStats::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

bool CSteamGameServerStats::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

// Set / update stats and achievements. 
// Note: These updates will work only on stats game servers are allowed to edit and only for 
// game servers that have been declared as officially controlled by the game creators. 
// Set the IP range of your official servers on the Steamworks page

STEAM_FLAT_NAME( SetUserStatInt32 )
bool CSteamGameServerStats::SetUserStat( CSteamID steamIDUser, const char *pchName, int32 nData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s, Data: %d", steamIDUser.ConvertToUint64(), pchName, nData);
    return false;
}

STEAM_FLAT_NAME( SetUserStatFloat )
bool CSteamGameServerStats::SetUserStat( CSteamID steamIDUser, const char *pchName, float fData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s, Data: %f", steamIDUser.ConvertToUint64(), pchName, fData);
    return false;
}

bool CSteamGameServerStats::UpdateUserAvgRateStat( CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s, Count: %f, Length: %f", steamIDUser.ConvertToUint64(), pchName, flCountThisSession, dSessionLength);
    return false;
}


bool CSteamGameServerStats::SetUserAchievement( CSteamID steamIDUser, const char *pchName )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

bool CSteamGameServerStats::ClearUserAchievement( CSteamID steamIDUser, const char *pchName )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

// Store the current data on the server, will get a GSStatsStored_t callback when set.
//
// If the callback has a result of k_EResultInvalidParam, one or more stats 
// uploaded has been rejected, either because they broke constraints
// or were out of date. In this case the server sends back updated values.
// The stats should be re-iterated to keep in sync.
STEAM_CALL_RESULT( GSStatsStored_t )
SteamAPICall_t CSteamGameServerStats::StoreUserStats( CSteamID steamIDUser )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu", steamIDUser.ConvertToUint64());
    return 0;
}
