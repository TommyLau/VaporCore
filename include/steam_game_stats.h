/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_GAME_STATS_H
#define VAPORCORE_STEAM_GAME_STATS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamgamestats.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for recording game play sessions and details thereof
//-----------------------------------------------------------------------------
class CSteamGameStats :
    public ISteamGameStats
{
public:
    // Singleton accessor
    static CSteamGameStats& GetInstance()
    {
		static CSteamGameStats instance;
		return instance;
    }

public:
	SteamAPICall_t GetNewSession( int8 nAccountType, uint64 ulAccountID, int32 nAppID, RTime32 rtTimeStarted ) override;
	SteamAPICall_t EndSession( uint64 ulSessionID, RTime32 rtTimeEnded, int nReasonCode ) override;
	EResult AddSessionAttributeInt( uint64 ulSessionID, const char* pstrName, int32 nData ) override;
	EResult AddSessionAttributeString( uint64 ulSessionID, const char* pstrName, const char *pstrData ) override;
	EResult AddSessionAttributeFloat( uint64 ulSessionID, const char* pstrName, float fData ) override;

	EResult AddNewRow( uint64 *pulRowID, uint64 ulSessionID, const char *pstrTableName ) override;
	EResult CommitRow( uint64 ulRowID ) override;
	EResult CommitOutstandingRows( uint64 ulSessionID ) override;
	EResult AddRowAttributeInt( uint64 ulRowID, const char *pstrName, int32 nData ) override;
	EResult AddRowAtributeString( uint64 ulRowID, const char *pstrName, const char *pstrData ) override;
	EResult AddRowAttributeFloat( uint64 ulRowID, const char *pstrName, float fData ) override;

	EResult AddSessionAttributeInt64( uint64 ulSessionID, const char *pstrName, int64 llData ) override;
	EResult AddRowAttributeInt64( uint64 ulRowID, const char *pstrName, int64 llData ) override;

private:
    // Private constructor and destructor for singleton
    CSteamGameStats();
    ~CSteamGameStats();

    // Delete copy constructor and assignment operator
    CSteamGameStats(const CSteamGameStats&) = delete;
    CSteamGameStats& operator=(const CSteamGameStats&) = delete;
};

#endif // VAPORCORE_STEAM_GAME_STATS_H
