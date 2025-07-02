/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "vapor_base.h"
#include "steam_parental_settings.h"

CSteamParentalSettings::CSteamParentalSettings()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamParentalSettings::~CSteamParentalSettings()
{
    VLOG_INFO(__FUNCTION__);
}

bool CSteamParentalSettings::BIsParentalLockEnabled()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamParentalSettings::BIsParentalLockLocked()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamParentalSettings::BIsAppBlocked(AppId_t nAppID)
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d", nAppID);
    return false;
}

bool CSteamParentalSettings::BIsAppInBlockList(AppId_t nAppID)
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d", nAppID);
    return false;
}

bool CSteamParentalSettings::BIsFeatureBlocked(EParentalFeature eFeature)
{
    VLOG_INFO(__FUNCTION__ " - Feature: %d", eFeature);
    return false;
}

bool CSteamParentalSettings::BIsFeatureInBlockList(EParentalFeature eFeature)
{
    VLOG_INFO(__FUNCTION__ " - Feature: %d", eFeature);
    return false;
} 