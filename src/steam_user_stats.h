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

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing stats, achievements, and leaderboard information
//-----------------------------------------------------------------------------
class Steam_User_Stats :
	public ISteamUserStats,
	public ISteamUserStats003,
	public ISteamUserStats004,
	public ISteamUserStats005,
	public ISteamUserStats006,
	public ISteamUserStats007
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

	// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set. 
	// A return value of 0 may indicate we are still fetching data, and you can wait for the UserAchievementIconReady_t callback
	// which will notify you when the bits are actually read.  If the callback still returns zero, then there is no image set
	// and there never will be.
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
	// See notes for GetAchievementAndUnlockTime above
	bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime ) override;

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
	// as above, but downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers
	// if a user doesn't have a leaderboard entry, they won't be included in the result
	// a max of 100 users can be downloaded at a time, with only one outstanding call at a time
	SteamAPICall_t DownloadLeaderboardEntriesForUsers( SteamLeaderboard_t hSteamLeaderboard, CSteamID *prgUsers, int cUsers ) override;

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
	// Changed from Steam SDK v1.05, backward compatibility
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount ) override;
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount ) override;

	// Attaches a piece of user generated content the user's entry on a leaderboard.
	// hContent is a handle to a piece of user generated content that was shared using ISteamUserRemoteStorage::FileShare().
	// This call is asynchronous, with the result returned in LeaderboardUGCSet_t.
	SteamAPICall_t AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC ) override;

	// Retrieves the number of players currently playing your game (online + offline)
	// This call is asynchronous, with the result returned in NumberOfCurrentPlayers_t
	SteamAPICall_t GetNumberOfCurrentPlayers() override;

    // Helper methods
    static Steam_User_Stats* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_User_Stats* s_pInstance;
};

#endif // VAPORCORE_STEAM_USER_STATS_H

