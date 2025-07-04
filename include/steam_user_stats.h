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

#include <isteamuserstats.h>
#include <isteamuserstats003.h>
#include <isteamuserstats004.h>
#include <isteamuserstats005.h>
#include <isteamuserstats006.h>
#include <isteamuserstats007.h>
#include <isteamuserstats009.h>
#include <isteamuserstats010.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing stats, achievements, and leaderboard information
//-----------------------------------------------------------------------------
class CSteamUserStats :
	public ISteamUserStats,
	public ISteamUserStats003,
	public ISteamUserStats004,
	public ISteamUserStats005,
	public ISteamUserStats006,
	public ISteamUserStats007,
	public ISteamUserStats009,
	public ISteamUserStats010
{
public:
    // Singleton accessor
    static CSteamUserStats& GetInstance()
	{
		static CSteamUserStats instance;
		return instance;
	}

public:
	// Ask the server to send down this user's data and achievements for this game
	STEAM_CALL_BACK( UserStatsReceived_t )
	bool RequestCurrentStats( ) override;

	// Data accessors
	STEAM_FLAT_NAME( GetStatInt32 )
	bool GetStat( const char *pchName, int32 *pData ) override;

	STEAM_FLAT_NAME( GetStatFloat )
	bool GetStat( const char *pchName, float *pData ) override;

	// Set / update data
	STEAM_FLAT_NAME( SetStatInt32 )
	bool SetStat( const char *pchName, int32 nData ) override;

	STEAM_FLAT_NAME( SetStatFloat )
	bool SetStat( const char *pchName, float fData ) override;

	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength ) override;

	// Achievement flag accessors
	bool GetAchievement( const char *pchName, bool *pbAchieved ) override;
	bool SetAchievement( const char *pchName ) override;
	bool ClearAchievement( const char *pchName ) override;

	// Get the achievement status, and the time it was unlocked if unlocked.
	// If the return value is true, but the unlock time is zero, that means it was unlocked before Steam 
	// began tracking achievement unlock times (December 2009). Time is seconds since January 1, 1970.
	bool GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, uint32 *punUnlockTime ) override;

	// Store the current data on the server, will get a callback when set
	// And one callback for every new achievement
	//
	// If the callback has a result of k_EResultInvalidParam, one or more stats 
	// uploaded has been rejected, either because they broke constraints
	// or were out of date. In this case the server sends back updated values.
	// The stats should be re-iterated to keep in sync.
	bool StoreStats() override;

	// Achievement / GroupAchievement metadata

	// Gets the icon of the achievement, which is a handle to be used in ISteamUtils::GetImageRGBA(), or 0 if none set. 
	// A return value of 0 may indicate we are still fetching data, and you can wait for the UserAchievementIconFetched_t callback
	// which will notify you when the bits are ready. If the callback still returns zero, then there is no image set for the
	// specified achievement.
	int GetAchievementIcon( const char *pchName ) override;

	// Get general attributes for an achievement. Accepts the following keys:
	// - "name" and "desc" for retrieving the localized achievement name and description (returned in UTF8)
	// - "hidden" for retrieving if an achievement is hidden (returns "0" when not hidden, "1" when hidden)
	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey ) override;

	// Achievement progress - triggers an AchievementProgress callback, that is all.
	// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress ) override;

	// Used for iterating achievements. In general games should not need these functions because they should have a
	// list of existing achievements compiled into them
	uint32 GetNumAchievements() override;
	// Get achievement name iAchievement in [0,GetNumAchievements)
	const char *GetAchievementName( uint32 iAchievement ) override;

	// Friends stats & achievements

	// downloads stats for the user
	// returns a UserStatsReceived_t received when completed
	// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
	// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
	STEAM_CALL_RESULT( UserStatsReceived_t )
	SteamAPICall_t RequestUserStats( CSteamID steamIDUser ) override;

	// requests stat information for a user, usable after a successful call to RequestUserStats()
	STEAM_FLAT_NAME( GetUserStatInt32 )
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData ) override;

	STEAM_FLAT_NAME( GetUserStatFloat )
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData ) override;

	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved ) override;
	// See notes for GetAchievementAndUnlockTime above
	bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime ) override;

	// Reset stats 
	bool ResetAllStats( bool bAchievementsToo ) override;

	// Leaderboard functions

	// asks the Steam back-end for a leaderboard by name, and will create it if it's not yet
	// This call is asynchronous, with the result returned in LeaderboardFindResult_t
	STEAM_CALL_RESULT(LeaderboardFindResult_t)
	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) override;

	// as above, but won't create the leaderboard if it's not found
	// This call is asynchronous, with the result returned in LeaderboardFindResult_t
	STEAM_CALL_RESULT( LeaderboardFindResult_t )
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
	STEAM_CALL_RESULT( LeaderboardScoresDownloaded_t )
	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) override;

	// as above, but downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers
	// if a user doesn't have a leaderboard entry, they won't be included in the result
	// a max of 100 users can be downloaded at a time, with only one outstanding call at a time
	STEAM_METHOD_DESC(Downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers)
	STEAM_CALL_RESULT( LeaderboardScoresDownloaded_t )
	SteamAPICall_t DownloadLeaderboardEntriesForUsers( SteamLeaderboard_t hSteamLeaderboard,
	                                                   STEAM_ARRAY_COUNT_D(cUsers, Array of users to retrieve) CSteamID *prgUsers, int cUsers ) override;

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
	// Details are extra game-defined information regarding how the user got that score
	// pScoreDetails points to an array of int32's, cScoreDetailsCount is the number of int32's in the list
	STEAM_CALL_RESULT( LeaderboardScoreUploaded_t )
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount ) override;
	// Changed from Steam SDK v1.05, backward compatibility
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount ) override;

	// Attaches a piece of user generated content the user's entry on a leaderboard.
	// hContent is a handle to a piece of user generated content that was shared using ISteamUserRemoteStorage::FileShare().
	// This call is asynchronous, with the result returned in LeaderboardUGCSet_t.
	STEAM_CALL_RESULT( LeaderboardUGCSet_t )
	SteamAPICall_t AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC ) override;

	// Retrieves the number of players currently playing your game (online + offline)
	// This call is asynchronous, with the result returned in NumberOfCurrentPlayers_t
	STEAM_CALL_RESULT( NumberOfCurrentPlayers_t )
	SteamAPICall_t GetNumberOfCurrentPlayers() override;

	// Requests that Steam fetch data on the percentage of players who have received each achievement
	// for the game globally.
	// This call is asynchronous, with the result returned in GlobalAchievementPercentagesReady_t.
	STEAM_CALL_RESULT( GlobalAchievementPercentagesReady_t )
	SteamAPICall_t RequestGlobalAchievementPercentages() override;

	// Get the info on the most achieved achievement for the game, returns an iterator index you can use to fetch
	// the next most achieved afterwards.  Will return -1 if there is no data on achievement 
	// percentages (ie, you haven't called RequestGlobalAchievementPercentages and waited on the callback).
	int GetMostAchievedAchievementInfo( char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved ) override;

	// Get the info on the next most achieved achievement for the game. Call this after GetMostAchievedAchievementInfo or another
	// GetNextMostAchievedAchievementInfo call passing the iterator from the previous call. Returns -1 after the last
	// achievement has been iterated.
	int GetNextMostAchievedAchievementInfo( int iIteratorPrevious, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved ) override;

	// Returns the percentage of users who have achieved the specified achievement.
	bool GetAchievementAchievedPercent( const char *pchName, float *pflPercent ) override;

	// Requests global stats data, which is available for stats marked as "aggregated".
	// This call is asynchronous, with the results returned in GlobalStatsReceived_t.
	// nHistoryDays specifies how many days of day-by-day history to retrieve in addition
	// to the overall totals. The limit is 60.
	STEAM_CALL_RESULT( GlobalStatsReceived_t )
	SteamAPICall_t RequestGlobalStats( int nHistoryDays ) override;

	// Gets the lifetime totals for an aggregated stat
	STEAM_FLAT_NAME( GetGlobalStatInt64 )
	bool GetGlobalStat( const char *pchStatName, int64 *pData ) override;

	STEAM_FLAT_NAME( GetGlobalStatDouble )
	bool GetGlobalStat( const char *pchStatName, double *pData ) override;

	// Gets history for an aggregated stat. pData will be filled with daily values, starting with today.
	// So when called, pData[0] will be today, pData[1] will be yesterday, and pData[2] will be two days ago, 
	// etc. cubData is the size in bytes of the pubData buffer. Returns the number of 
	// elements actually set.

	STEAM_FLAT_NAME( GetGlobalStatHistoryInt64 )
	int32 GetGlobalStatHistory( const char *pchStatName, STEAM_ARRAY_COUNT(cubData) int64 *pData, uint32 cubData ) override;

	STEAM_FLAT_NAME( GetGlobalStatHistoryDouble )
	int32 GetGlobalStatHistory( const char *pchStatName, STEAM_ARRAY_COUNT(cubData) double *pData, uint32 cubData ) override;

#ifdef _PS3
	// Call to kick off installation of the PS3 trophies. This call is asynchronous, and the results will be returned in a PS3TrophiesInstalled_t
	// callback.
	bool InstallPS3Trophies() override;

	// Returns the amount of space required at boot to install trophies. This value can be used when comparing the amount of space needed
	// by the game to the available space value passed to the game at boot. The value is set during InstallPS3Trophies().
	uint64 GetTrophySpaceRequiredBeforeInstall() override;

	// On PS3, user stats & achievement progress through Steam must be stored with the user's saved game data.
	// At startup, before calling RequestCurrentStats(), you must pass the user's stats data to Steam via this method.
	// If you do not have any user data, call this function with pvData = NULL and cubData = 0
	bool SetUserStatsData( const void *pvData, uint32 cubData ) override;

	// Call to get the user's current stats data. You should retrieve this data after receiving successful UserStatsReceived_t & UserStatsStored_t
	// callbacks, and store the data with the user's save game data. You can call this method with pvData = NULL and cubData = 0 to get the required
	// buffer size.
	bool GetUserStatsData( void *pvData, uint32 cubData, uint32 *pcubWritten ) override;
#endif

private:
    // Private constructor and destructor for singleton
    CSteamUserStats();
    ~CSteamUserStats();

    // Delete copy constructor and assignment operator
    CSteamUserStats(const CSteamUserStats&) = delete;
    CSteamUserStats& operator=(const CSteamUserStats&) = delete;
};

#endif // VAPORCORE_STEAM_USER_STATS_H

