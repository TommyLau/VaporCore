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
#include "steam_game_stats.h"

CSteamGameStats::CSteamGameStats()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameStats::~CSteamGameStats()
{
    VLOG_INFO(__FUNCTION__);
}

SteamAPICall_t CSteamGameStats::GetNewSession( int8 nAccountType, uint64 ulAccountID, int32 nAppID, RTime32 rtTimeStarted )
{
    VLOG_INFO(__FUNCTION__ " - AccountType: %d, AccountID: %llu, AppID: %d, TimeStarted: %d", nAccountType, ulAccountID, nAppID, rtTimeStarted);
    return 0;
}

SteamAPICall_t CSteamGameStats::EndSession( uint64 ulSessionID, RTime32 rtTimeEnded, int nReasonCode )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, TimeEnded: %d, ReasonCode: %d", ulSessionID, rtTimeEnded, nReasonCode);
    return 0;
}

EResult CSteamGameStats::AddSessionAttributeInt( uint64 ulSessionID, const char* pstrName, int32 nData )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, Name: %s, Data: %d", ulSessionID, pstrName, nData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddSessionAttributeString( uint64 ulSessionID, const char* pstrName, const char *pstrData )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, Name: %s, Data: %s", ulSessionID, pstrName, pstrData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddSessionAttributeFloat( uint64 ulSessionID, const char* pstrName, float fData )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, Name: %s, Data: %f", ulSessionID, pstrName, fData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddNewRow( uint64 *pulRowID, uint64 ulSessionID, const char *pstrTableName )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, TableName: %s", ulSessionID, pstrTableName);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::CommitRow( uint64 ulRowID )
{
    VLOG_INFO(__FUNCTION__ " - RowID: %llu", ulRowID);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::CommitOutstandingRows( uint64 ulSessionID )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu", ulSessionID);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddRowAttributeInt( uint64 ulRowID, const char *pstrName, int32 nData )
{
    VLOG_INFO(__FUNCTION__ " - RowID: %llu, Name: %s, Data: %d", ulRowID, pstrName, nData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddRowAtributeString( uint64 ulRowID, const char *pstrName, const char *pstrData )
{
    VLOG_INFO(__FUNCTION__ " - RowID: %llu, Name: %s, Data: %s", ulRowID, pstrName, pstrData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddRowAttributeFloat( uint64 ulRowID, const char *pstrName, float fData )
{
    VLOG_INFO(__FUNCTION__ " - RowID: %llu, Name: %s, Data: %f", ulRowID, pstrName, fData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddSessionAttributeInt64( uint64 ulSessionID, const char *pstrName, int64 llData )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %llu, Name: %s, Data: %lld", ulSessionID, pstrName, llData);
    return EResult::k_EResultOK;
}

EResult CSteamGameStats::AddRowAttributeInt64( uint64 ulRowID, const char *pstrName, int64 llData )
{
    VLOG_INFO(__FUNCTION__ " - RowID: %llu, Name: %s, Data: %lld", ulRowID, pstrName, llData);
    return EResult::k_EResultOK;
}
