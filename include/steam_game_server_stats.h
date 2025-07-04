/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_GAME_SERVER_STATS_H
#define VAPORCORE_STEAM_GAME_SERVER_STATS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamgameserverstats.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for authenticating users via Steam to play on a game server
//-----------------------------------------------------------------------------
class CSteamGameServerStats :
    public ISteamGameServerStats
{
public:
    // Singleton accessor
    static CSteamGameServerStats& GetInstance()
    {
		static CSteamGameServerStats instance;
		return instance;
    }

public:
	// downloads stats for the user
	// returns a GSStatsReceived_t callback when completed
	// if the user has no stats, GSStatsReceived_t.m_eResult will be set to k_EResultFail
	// these stats will only be auto-updated for clients playing on the server. For other
	// users you'll need to call RequestUserStats() again to refresh any data
	STEAM_CALL_RESULT( GSStatsReceived_t )
	SteamAPICall_t RequestUserStats( CSteamID steamIDUser ) override;

	// requests stat information for a user, usable after a successful call to RequestUserStats()
	STEAM_FLAT_NAME( GetUserStatInt32 )
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData ) override;

	STEAM_FLAT_NAME( GetUserStatFloat )
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData ) override;

	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved ) override;

	// Set / update stats and achievements. 
	// Note: These updates will work only on stats game servers are allowed to edit and only for 
	// game servers that have been declared as officially controlled by the game creators. 
	// Set the IP range of your official servers on the Steamworks page

	STEAM_FLAT_NAME( SetUserStatInt32 )
	bool SetUserStat( CSteamID steamIDUser, const char *pchName, int32 nData ) override;

	STEAM_FLAT_NAME( SetUserStatFloat )
	bool SetUserStat( CSteamID steamIDUser, const char *pchName, float fData ) override;

	bool UpdateUserAvgRateStat( CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength ) override;

	bool SetUserAchievement( CSteamID steamIDUser, const char *pchName ) override;
	bool ClearUserAchievement( CSteamID steamIDUser, const char *pchName ) override;

	// Store the current data on the server, will get a GSStatsStored_t callback when set.
	//
	// If the callback has a result of k_EResultInvalidParam, one or more stats 
	// uploaded has been rejected, either because they broke constraints
	// or were out of date. In this case the server sends back updated values.
	// The stats should be re-iterated to keep in sync.
	STEAM_CALL_RESULT( GSStatsStored_t )
	SteamAPICall_t StoreUserStats( CSteamID steamIDUser ) override;

private:
    // Private constructor and destructor for singleton
    CSteamGameServerStats();
    ~CSteamGameServerStats();

    // Delete copy constructor and assignment operator
    CSteamGameServerStats(const CSteamGameServerStats&) = delete;
    CSteamGameServerStats& operator=(const CSteamGameServerStats&) = delete;
};

#endif // VAPORCORE_STEAM_GAME_SERVER_STATS_H
