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
#include "steam_user_stats.h"

CSteamUserStats::CSteamUserStats()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamUserStats::~CSteamUserStats()
{
    VLOG_INFO(__FUNCTION__);
}

// Ask the server to send down this user's data and achievements for this game
bool CSteamUserStats::RequestCurrentStats( )
{
    VLOG_INFO(__FUNCTION__);

    VAPORCORE_LOCK_GUARD();

    UserStatsReceived_t callback = {
        VaporCore::Config::GetInstance().GameID().ToUint64(),
        k_EResultOK,
        VaporCore::Config::GetInstance().SteamID().ConvertToUint64()
    };

    return CCallbackMgr::GetInstance().PostCallback(callback.k_iCallback, &callback, sizeof(callback));
}

// Data accessors
bool CSteamUserStats::GetStat( const char *pchName, int32 *pData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    if (pData) *pData = 0;
    return false;
}

bool CSteamUserStats::GetStat( const char *pchName, float *pData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    if (pData) *pData = 0.0f;
    return false;
}

// Set / update data
bool CSteamUserStats::SetStat( const char *pchName, int32 nData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Data: %d", pchName ? pchName : "null", nData);
    return true;
}

bool CSteamUserStats::SetStat( const char *pchName, float fData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Data: %f", pchName ? pchName : "null", fData);
    return true;
}

bool CSteamUserStats::UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Count: %f, Length: %f", 
               pchName ? pchName : "null", flCountThisSession, dSessionLength);
    return true;
}

// Achievement flag accessors
bool CSteamUserStats::GetAchievement( const char *pchName, bool *pbAchieved )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    if (pbAchieved) *pbAchieved = false;
    return false;
}

bool CSteamUserStats::SetAchievement( const char *pchName )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return true;
}

bool CSteamUserStats::ClearAchievement( const char *pchName )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return true;
}

// Get the achievement status, and the time it was unlocked if unlocked.
// If the return value is true, but the unlock time is zero, that means it was unlocked before Steam 
// began tracking achievement unlock times (December 2009). Time is seconds since January 1, 1970.
bool CSteamUserStats::GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, uint32 *punUnlockTime )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return false;
}

// Store the current data on the server, will get a callback when set
// And one callback for every new achievement
//
// If the callback has a result of k_EResultInvalidParam, one or more stats 
// uploaded has been rejected, either because they broke constraints
// or were out of date. In this case the server sends back updated values.
// The stats should be re-iterated to keep in sync.
bool CSteamUserStats::StoreStats( )
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// Achievement / GroupAchievement metadata

// Gets the icon of the achievement, which is a handle to be used in ISteamUtils::GetImageRGBA(), or 0 if none set. 
// A return value of 0 may indicate we are still fetching data, and you can wait for the UserAchievementIconFetched_t callback
// which will notify you when the bits are ready. If the callback still returns zero, then there is no image set for the
// specified achievement.
int CSteamUserStats::GetAchievementIcon( const char *pchName )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return 0;
}

// Get general attributes for an achievement. Accepts the following keys:
// - "name" and "desc" for retrieving the localized achievement name and description (returned in UTF8)
// - "hidden" for retrieving if an achievement is hidden (returns "0" when not hidden, "1" when hidden)
const char *CSteamUserStats::GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Key: %s", 
               pchName ? pchName : "null", pchKey ? pchKey : "null");
    return "";
}

// Achievement progress - triggers an AchievementProgress callback, that is all.
// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
bool CSteamUserStats::IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Progress: %u/%u", 
               pchName ? pchName : "null", nCurProgress, nMaxProgress);
    return true;
}

// Used for iterating achievements. In general games should not need these functions because they should have a
// list of existing achievements compiled into them
uint32 CSteamUserStats::GetNumAchievements()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Get achievement name iAchievement in [0,GetNumAchievements)
const char* CSteamUserStats::GetAchievementName(uint32 iAchievement)
{
    VLOG_INFO(__FUNCTION__ " - Achievement: %u", iAchievement);
    return "";
}

// Friends stats & achievements

// downloads stats for the user
// returns a UserStatsReceived_t received when completed
// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
SteamAPICall_t CSteamUserStats::RequestUserStats( CSteamID steamIDUser )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu", steamIDUser.ConvertToUint64());
    return 0;
}

// requests stat information for a user, usable after a successful call to RequestUserStats()
bool CSteamUserStats::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName ? pchName : "null");
    return false;
}

bool CSteamUserStats::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName ? pchName : "null");
    return false;
}

bool CSteamUserStats::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName ? pchName : "null");
    return false;
}

// See notes for GetAchievementAndUnlockTime above
bool CSteamUserStats::GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu, Name: %s", steamIDUser.ConvertToUint64(), pchName ? pchName : "null");
    return false;
}

// Reset stats 
bool CSteamUserStats::ResetAllStats( bool bAchievementsToo )
{
    VLOG_INFO(__FUNCTION__ " - Achievements: %d", bAchievementsToo);
    return true;
}

// Leaderboard functions

// asks the Steam back-end for a leaderboard by name, and will create it if it's not yet
// This call is asynchronous, with the result returned in LeaderboardFindResult_t
SteamAPICall_t CSteamUserStats::FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Sort: %d, Display: %d", 
               pchLeaderboardName ? pchLeaderboardName : "null", eLeaderboardSortMethod, eLeaderboardDisplayType);
    return 0;
}

// as above, but won't create the leaderboard if it's not found
// This call is asynchronous, with the result returned in LeaderboardFindResult_t
SteamAPICall_t CSteamUserStats::FindLeaderboard( const char *pchLeaderboardName )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchLeaderboardName ? pchLeaderboardName : "null");
    return 0;
}

// returns the name of a leaderboard
const char *CSteamUserStats::GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u", hSteamLeaderboard);
    return "";
}

// returns the total number of entries in a leaderboard, as of the last request
int CSteamUserStats::GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u", hSteamLeaderboard);
    return 0;
}

// returns the sort method of the leaderboard
ELeaderboardSortMethod CSteamUserStats::GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u", hSteamLeaderboard);
    return ELeaderboardSortMethod::k_ELeaderboardSortMethodNone;
}

// returns the display type of the leaderboard
ELeaderboardDisplayType CSteamUserStats::GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u", hSteamLeaderboard);
    return ELeaderboardDisplayType::k_ELeaderboardDisplayTypeNone;
}

// Asks the Steam back-end for a set of rows in the leaderboard.
// This call is asynchronous, with the result returned in LeaderboardScoresDownloaded_t
// LeaderboardScoresDownloaded_t will contain a handle to pull the results from GetDownloadedLeaderboardEntries() (below)
// You can ask for more entries than exist, and it will return as many as do exist.
// k_ELeaderboardDataRequestGlobal requests rows in the leaderboard from the full table, with nRangeStart & nRangeEnd in the range [1, TotalEntries]
// k_ELeaderboardDataRequestGlobalAroundUser requests rows around the current user, nRangeStart being negate
//   e.g. DownloadLeaderboardEntries( hLeaderboard, k_ELeaderboardDataRequestGlobalAroundUser, -3, 3 ) will return 7 rows, 3 before the user, 3 after
// k_ELeaderboardDataRequestFriends requests all the rows for friends of the current user 
SteamAPICall_t CSteamUserStats::DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, Request: %d, Range: %d-%d", hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
    return 0;
}

// as above, but downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers
// if a user doesn't have a leaderboard entry, they won't be included in the result
// a max of 100 users can be downloaded at a time, with only one outstanding call at a time
METHOD_DESC(Downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers)
SteamAPICall_t CSteamUserStats::DownloadLeaderboardEntriesForUsers( SteamLeaderboard_t hSteamLeaderboard,
	                                                                 ARRAY_COUNT_D(cUsers, Array of users to retrieve) CSteamID *prgUsers, int cUsers )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, Users: %d", hSteamLeaderboard, cUsers);
    return 0;
}

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
bool CSteamUserStats::GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, Index: %d, Details: %d", hSteamLeaderboardEntries, index, cDetailsMax);
    return false;
}

// Uploads a user score to the Steam back-end.
// This call is asynchronous, with the result returned in LeaderboardScoreUploaded_t
// Details are extra game-defined information regarding how the user got that score
// pScoreDetails points to an array of int32's, cScoreDetailsCount is the number of int32's in the list
SteamAPICall_t CSteamUserStats::UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, Score: %d, Details: %d", hSteamLeaderboard, nScore, cScoreDetailsCount);
    return 0;
}

// Changed from Steam SDK v1.05, backward compatibility
SteamAPICall_t CSteamUserStats::UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, Score: %d, Details: %d", hSteamLeaderboard, nScore, cScoreDetailsCount);
    return 0;
}

// Attaches a piece of user generated content the user's entry on a leaderboard.
// hContent is a handle to a piece of user generated content that was shared using ISteamUserRemoteStorage::FileShare().
// This call is asynchronous, with the result returned in LeaderboardUGCSet_t.
SteamAPICall_t CSteamUserStats::AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC )
{
    VLOG_INFO(__FUNCTION__ " - Leaderboard: %u, UGC: %u", hSteamLeaderboard, hUGC);
    return 0;
}

// Retrieves the number of players currently playing your game (online + offline)
// This call is asynchronous, with the result returned in NumberOfCurrentPlayers_t
SteamAPICall_t CSteamUserStats::GetNumberOfCurrentPlayers()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Requests that Steam fetch data on the percentage of players who have received each achievement
// for the game globally.
// This call is asynchronous, with the result returned in GlobalAchievementPercentagesReady_t.
SteamAPICall_t CSteamUserStats::RequestGlobalAchievementPercentages()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Get the info on the most achieved achievement for the game, returns an iterator index you can use to fetch
// the next most achieved afterwards.  Will return -1 if there is no data on achievement 
// percentages (ie, you haven't called RequestGlobalAchievementPercentages and waited on the callback).
int CSteamUserStats::GetMostAchievedAchievementInfo( char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return 0;
}

// Get the info on the next most achieved achievement for the game. Call this after GetMostAchievedAchievementInfo or another
// GetNextMostAchievedAchievementInfo call passing the iterator from the previous call. Returns -1 after the last
// achievement has been iterated.
int CSteamUserStats::GetNextMostAchievedAchievementInfo( int iIteratorPrevious, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved )
{
    VLOG_INFO(__FUNCTION__ " - Iterator: %d", iIteratorPrevious);
    return 0;
}

// Returns the percentage of users who have achieved the specified achievement.
bool CSteamUserStats::GetAchievementAchievedPercent( const char *pchName, float *pflPercent )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName ? pchName : "null");
    return false;
}

// Requests global stats data, which is available for stats marked as "aggregated".
// This call is asynchronous, with the results returned in GlobalStatsReceived_t.
// nHistoryDays specifies how many days of day-by-day history to retrieve in addition
// to the overall totals. The limit is 60.
SteamAPICall_t CSteamUserStats::RequestGlobalStats( int nHistoryDays )
{
    VLOG_INFO(__FUNCTION__ " - History: %d", nHistoryDays);
    return 0;
}

// Gets the lifetime totals for an aggregated stat
bool CSteamUserStats::GetGlobalStat( const char *pchStatName, int64 *pData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchStatName ? pchStatName : "null");
    return false;
}

bool CSteamUserStats::GetGlobalStat( const char *pchStatName, double *pData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchStatName ? pchStatName : "null");
    return false;
}

// Gets history for an aggregated stat. pData will be filled with daily values, starting with today.
// So when called, pData[0] will be today, pData[1] will be yesterday, and pData[2] will be two days ago, 
// etc. cubData is the size in bytes of the pubData buffer. Returns the number of 
// elements actually set.
int32 CSteamUserStats::GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) int64 *pData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchStatName ? pchStatName : "null");
    return 0;
}

int32 CSteamUserStats::GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) double *pData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchStatName ? pchStatName : "null");
    return 0;
}
