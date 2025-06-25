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

// Static instance
Steam_Game_Stats* Steam_Game_Stats::s_pInstance = nullptr;

Steam_Game_Stats::Steam_Game_Stats()
{
    VLOG_INFO("Steam_Game_Stats constructor called");
}

Steam_Game_Stats::~Steam_Game_Stats()
{
    VLOG_INFO("Steam_Game_Stats destructor called");
}

SteamAPICall_t Steam_Game_Stats::GetNewSession( int8 nAccountType, uint64 ulAccountID, int32 nAppID, RTime32 rtTimeStarted )
{
    VLOG_DEBUG("GetNewSession called - AccountType: %d, AccountID: %llu, AppID: %d, TimeStarted: %d", nAccountType, ulAccountID, nAppID, rtTimeStarted);
    return 0;
}

SteamAPICall_t Steam_Game_Stats::EndSession( uint64 ulSessionID, RTime32 rtTimeEnded, int nReasonCode )
{
    VLOG_DEBUG("EndSession called - SessionID: %llu, TimeEnded: %d, ReasonCode: %d", ulSessionID, rtTimeEnded, nReasonCode);
    return 0;
}

EResult Steam_Game_Stats::AddSessionAttributeInt( uint64 ulSessionID, const char* pstrName, int32 nData )
{
    VLOG_DEBUG("AddSessionAttributeInt called - SessionID: %llu, Name: %s, Data: %d", ulSessionID, pstrName, nData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddSessionAttributeString( uint64 ulSessionID, const char* pstrName, const char *pstrData )
{
    VLOG_DEBUG("AddSessionAttributeString called - SessionID: %llu, Name: %s, Data: %s", ulSessionID, pstrName, pstrData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddSessionAttributeFloat( uint64 ulSessionID, const char* pstrName, float fData )
{
    VLOG_DEBUG("AddSessionAttributeFloat called - SessionID: %llu, Name: %s, Data: %f", ulSessionID, pstrName, fData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddNewRow( uint64 *pulRowID, uint64 ulSessionID, const char *pstrTableName )
{
    VLOG_DEBUG("AddNewRow called - SessionID: %llu, TableName: %s", ulSessionID, pstrTableName);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::CommitRow( uint64 ulRowID )
{
    VLOG_DEBUG("CommitRow called - RowID: %llu", ulRowID);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::CommitOutstandingRows( uint64 ulSessionID )
{
    VLOG_DEBUG("CommitOutstandingRows called - SessionID: %llu", ulSessionID);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddRowAttributeInt( uint64 ulRowID, const char *pstrName, int32 nData )
{
    VLOG_DEBUG("AddRowAttributeInt called - RowID: %llu, Name: %s, Data: %d", ulRowID, pstrName, nData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddRowAtributeString( uint64 ulRowID, const char *pstrName, const char *pstrData )
{
    VLOG_DEBUG("AddRowAtributeString called - RowID: %llu, Name: %s, Data: %s", ulRowID, pstrName, pstrData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddRowAttributeFloat( uint64 ulRowID, const char *pstrName, float fData )
{
    VLOG_DEBUG("AddRowAttributeFloat called - RowID: %llu, Name: %s, Data: %f", ulRowID, pstrName, fData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddSessionAttributeInt64( uint64 ulSessionID, const char *pstrName, int64 llData )
{
    VLOG_DEBUG("AddSessionAttributeInt64 called - SessionID: %llu, Name: %s, Data: %lld", ulSessionID, pstrName, llData);
    return EResult::k_EResultOK;
}

EResult Steam_Game_Stats::AddRowAttributeInt64( uint64 ulRowID, const char *pstrName, int64 llData )
{
    VLOG_DEBUG("AddRowAttributeInt64 called - RowID: %llu, Name: %s, Data: %lld", ulRowID, pstrName, llData);
    return EResult::k_EResultOK;
}

// Helper methods
Steam_Game_Stats* Steam_Game_Stats::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Game_Stats();
    }
    return s_pInstance;
}

void Steam_Game_Stats::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
