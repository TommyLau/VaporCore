/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_user_stats.h"
#include "logger.h"

// Static instance
Steam_User_Stats* Steam_User_Stats::s_pInstance = nullptr;

Steam_User_Stats::Steam_User_Stats()
{
    VLOG_INFO("Steam_User_Stats constructor called");
}

Steam_User_Stats::~Steam_User_Stats()
{
    VLOG_INFO("Steam_User_Stats destructor called");
}

// Ask the server to send down this user's data and achievements for nGameID
bool Steam_User_Stats::RequestCurrentStats( )
{
    VLOG_DEBUG("RequestCurrentStats called");
    return true;
}

// Data accessors
bool Steam_User_Stats::GetStat( const char *pchName, int32 *pData )
{
    VLOG_DEBUG("GetStat(int32) called - Name: %s", pchName ? pchName : "null");
    if (pData) *pData = 0;
    return false;
}

bool Steam_User_Stats::GetStat( const char *pchName, float *pData )
{
    VLOG_DEBUG("GetStat(float) called - Name: %s", pchName ? pchName : "null");
    if (pData) *pData = 0.0f;
    return false;
}

// Set / update data
bool Steam_User_Stats::SetStat( const char *pchName, int32 nData )
{
    VLOG_DEBUG("SetStat(int32) called - Name: %s, Data: %d", pchName ? pchName : "null", nData);
    return true;
}

bool Steam_User_Stats::SetStat( const char *pchName, float fData )
{
    VLOG_DEBUG("SetStat(float) called - Name: %s, Data: %f", pchName ? pchName : "null", fData);
    return true;
}

bool Steam_User_Stats::UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_DEBUG("UpdateAvgRateStat called - Name: %s, Count: %f, Length: %f", 
               pchName ? pchName : "null", flCountThisSession, dSessionLength);
    return true;
}

// Achievement flag accessors
bool Steam_User_Stats::GetAchievement( const char *pchName, bool *pbAchieved )
{
    VLOG_DEBUG("GetAchievement called - Name: %s", pchName ? pchName : "null");
    if (pbAchieved) *pbAchieved = false;
    return false;
}

bool Steam_User_Stats::SetAchievement( const char *pchName )
{
    VLOG_DEBUG("SetAchievement called - Name: %s", pchName ? pchName : "null");
    return true;
}

bool Steam_User_Stats::ClearAchievement( const char *pchName )
{
    VLOG_DEBUG("ClearAchievement called - Name: %s", pchName ? pchName : "null");
    return true;
}

// Store the current data on the server, will get a callback when set
// And one callback for every new achievement
bool Steam_User_Stats::StoreStats( )
{
    VLOG_DEBUG("StoreStats called");
    return true;
}

// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
int Steam_User_Stats::GetAchievementIcon( const char *pchName )
{
    VLOG_DEBUG("GetAchievementIcon called - Name: %s", pchName ? pchName : "null");
    return 0;
}

// Get general attributes (display name / text, etc) for an Achievement
const char *Steam_User_Stats::GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
{
    VLOG_DEBUG("GetAchievementDisplayAttribute called - Name: %s, Key: %s", 
               pchName ? pchName : "null", pchKey ? pchKey : "null");
    return "";
}

// Achievement progress - triggers an AchievementProgress callback, that is all.
// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
bool Steam_User_Stats::IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
{
    VLOG_DEBUG("IndicateAchievementProgress called - Name: %s, Progress: %u/%u", 
               pchName ? pchName : "null", nCurProgress, nMaxProgress);
    return true;
}

// Helper methods
Steam_User_Stats* Steam_User_Stats::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_User_Stats();
    }
    return s_pInstance;
}

void Steam_User_Stats::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

