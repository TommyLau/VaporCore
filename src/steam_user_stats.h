/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_USER_STATS_H
#define VAPORCORE_STEAM_USER_STATS_H
#ifdef _WIN32
#pragma once
#endif

#include "../include/sdk/isteamuserstats.h"

class Steam_User_Stats : public ISteamUserStats
{
public:
    Steam_User_Stats();
    ~Steam_User_Stats();

	// Ask the server to send down this user's data and achievements for nGameID
	bool RequestCurrentStats( ) override;

	// Data accessors
	bool GetStat( const char *pchName, int32 *pData ) override;
	bool GetStat( const char *pchName, float *pData ) override;

	// Set / update data
	bool SetStat( const char *pchName, int32 nData ) override;
	bool SetStat( const char *pchName, float fData ) override;
	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength ) override;

	// Achievement flag accessors
	bool GetAchievement( const char *pchName, bool *pbAchieved ) override;
	bool SetAchievement( const char *pchName ) override;
	bool ClearAchievement( const char *pchName ) override;

	// Store the current data on the server, will get a callback when set
	// And one callback for every new achievement
	bool StoreStats( ) override;

	// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int GetAchievementIcon( const char *pchName ) override;
	// Get general attributes (display name / text, etc) for an Achievement
	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey ) override;

	// Achievement progress - triggers an AchievementProgress callback, that is all.
	// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress ) override;

    // Helper methods
    static Steam_User_Stats* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_User_Stats* s_pInstance;
};

#endif // VAPORCORE_STEAM_USER_STATS_H

