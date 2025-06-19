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

#include <sdk/isteamuserstats.h>
#include <sdk/isteamuserstats003.h>
#include <sdk/isteamuserstats004.h>

class Steam_User_Stats :
	public ISteamUserStats,
	public ISteamUserStats003,
	public ISteamUserStats004
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

	// Friends stats & achievements

	// downloads stats for the user
	// returns a UserStatsReceived_t received when completed
	// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
	// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
	SteamAPICall_t RequestUserStats( CSteamID steamIDUser ) override;

	// requests stat information for a user, usable after a successful call to RequestUserStats()
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData ) override;
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData ) override;
	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved ) override;

	// Reset stats 
	bool ResetAllStats( bool bAchievementsToo ) override;

	// Leaderboard functions

	// asks the Steam back-end for a leaderboard by name, and will create it if it's not yet
	// This call is asynchronous, with the result returned in LeaderboardFindResult_t
	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) override;

	// as above, but won't create the leaderboard if it's not found
	// This call is asynchronous, with the result returned in LeaderboardFindResult_t
	SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName ) override;

	// returns the name of a leaderboard
	const char *GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard ) override;

	// returns the total number of entries in a leaderboard, as of the last request
	int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard ) override;

	// returns the sort method of the leaderboard
	ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard ) override;

	// returns the display type of the leaderboard
	ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard ) override;

	// Asks the Steam back-end for a set of rows in the leaderboard.
	// This call is asynchronous, with the result returned in LeaderboardScoresDownloaded_t
	// LeaderboardScoresDownloaded_t will contain a handle to pull the results from GetDownloadedLeaderboardEntries() (below)
	// You can ask for more entries than exist, and it will return as many as do exist.
	// k_ELeaderboardDataRequestGlobal requests rows in the leaderboard from the full table, with nRangeStart & nRangeEnd in the range [1, TotalEntries]
	// k_ELeaderboardDataRequestGlobalAroundUser requests rows around the current user, nRangeStart being negate
	//   e.g. DownloadLeaderboardEntries( hLeaderboard, k_ELeaderboardDataRequestGlobalAroundUser, -3, 3 ) will return 7 rows, 3 before the user, 3 after
	// k_ELeaderboardDataRequestFriends requests all the rows for friends of the current user 
	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) override;

	// Returns data about a single leaderboard entry
	// use a for loop from 0 to LeaderboardScoresDownloaded_t::m_cEntryCount to get all the downloaded entries
	// e.g.
	//		void OnLeaderboardScoresDownloaded( LeaderboardScoresDownloaded_t *pLeaderboardScoresDownloaded )
	//		{
	//			for ( int index = 0; index < pLeaderboardScoresDownloaded->m_cEntryCount; index++ )
	//			{
	//				LeaderboardEntry_t leaderboardEntry;
	//				int32 details[3];		// we know this is how many we've stored previously
	//				GetDownloadedLeaderboardEntry( pLeaderboardScoresDownloaded->m_hSteamLeaderboardEntries, index, &leaderboardEntry, details, 3 );
	//				assert( leaderboardEntry.m_cDetails == 3 );
	//				...
	//			}
	// once you've accessed all the entries, the data will be free'd, and the SteamLeaderboardEntries_t handle will become invalid
	bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax ) override;

	// Uploads a user score to the Steam back-end.
	// This call is asynchronous, with the result returned in LeaderboardScoreUploaded_t
	// If the score passed in is no better than the existing score this user has in the leaderboard, then the leaderboard will not be updated.
	// Details are extra game-defined information regarding how the user got that score
	// pScoreDetails points to an array of int32's, cScoreDetailsCount is the number of int32's in the list
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount ) override;

    // Helper methods
    static Steam_User_Stats* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_User_Stats* s_pInstance;
};

#endif // VAPORCORE_STEAM_USER_STATS_H

