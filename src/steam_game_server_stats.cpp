/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_game_server_stats.h"
#include "logger.h"

// Static instance
Steam_Game_Server_Stats* Steam_Game_Server_Stats::s_pInstance = nullptr;

Steam_Game_Server_Stats::Steam_Game_Server_Stats()
{
    VLOG_INFO("Steam_Game_Server_Stats constructor called");
}

Steam_Game_Server_Stats::~Steam_Game_Server_Stats()
{
    VLOG_INFO("Steam_Game_Server_Stats destructor called");
}

// downloads stats for the user
// returns a GSStatsReceived_t callback when completed
// if the user has no stats, GSStatsReceived_t.m_eResult will be set to k_EResultFail
// these stats will only be auto-updated for clients playing on the server. For other
// users you'll need to call RequestUserStats() again to refresh any data
SteamAPICall_t Steam_Game_Server_Stats::RequestUserStats( CSteamID steamIDUser )
{
    VLOG_DEBUG("RequestUserStats called - SteamID: %llu", steamIDUser.ConvertToUint64());
    return 0;
}

// requests stat information for a user, usable after a successful call to RequestUserStats()
bool Steam_Game_Server_Stats::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
    VLOG_DEBUG("GetUserStat called - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

bool Steam_Game_Server_Stats::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
    VLOG_DEBUG("GetUserStat called - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

bool Steam_Game_Server_Stats::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
    VLOG_DEBUG("GetUserAchievement called - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

// Set / update stats and achievements. 
// Note: These updates will work only on stats game servers are allowed to edit and only for 
// game servers that have been declared as officially controlled by the game creators. 
// Set the IP range of your official servers on the Steamworks page
bool Steam_Game_Server_Stats::SetUserStat( CSteamID steamIDUser, const char *pchName, int32 nData )
{
    VLOG_DEBUG("SetUserStat called - SteamID: %llu, Name: %s, Data: %d", steamIDUser.ConvertToUint64(), pchName, nData);
    return false;
}

bool Steam_Game_Server_Stats::SetUserStat( CSteamID steamIDUser, const char *pchName, float fData )
{
    VLOG_DEBUG("SetUserStat called - SteamID: %llu, Name: %s, Data: %f", steamIDUser.ConvertToUint64(), pchName, fData);
    return false;
}

bool Steam_Game_Server_Stats::UpdateUserAvgRateStat( CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_DEBUG("UpdateUserAvgRateStat called - SteamID: %llu, Name: %s, Count: %f, Length: %f", steamIDUser.ConvertToUint64(), pchName, flCountThisSession, dSessionLength);
    return false;
}


bool Steam_Game_Server_Stats::SetUserAchievement( CSteamID steamIDUser, const char *pchName )
{
    VLOG_DEBUG("SetUserAchievement called - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);
    return false;
}

bool Steam_Game_Server_Stats::ClearUserAchievement( CSteamID steamIDUser, const char *pchName )
{
    VLOG_DEBUG("ClearUserAchievement called - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName);

    return false;
}

// Store the current data on the server, will get a GSStatsStored_t callback when set.
//
// If the callback has a result of k_EResultInvalidParam, one or more stats 
// uploaded has been rejected, either because they broke constraints
// or were out of date. In this case the server sends back updated values.
// The stats should be re-iterated to keep in sync.
SteamAPICall_t Steam_Game_Server_Stats::StoreUserStats( CSteamID steamIDUser )
{
    VLOG_DEBUG("StoreUserStats called - SteamID: %llu", steamIDUser.ConvertToUint64());
    return 0;
}

// Helper methods
Steam_Game_Server_Stats* Steam_Game_Server_Stats::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Game_Server_Stats();
    }
    return s_pInstance;
}

void Steam_Game_Server_Stats::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
