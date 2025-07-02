/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_PARENTAL_H
#define VAPORCORE_STEAM_PARENTAL_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamparentalsettings.h>

//-----------------------------------------------------------------------------
// Purpose: interface to accessing Steam parental settings
//-----------------------------------------------------------------------------
class CSteamParentalSettings : public ISteamParentalSettings
{
public:
    // Singleton accessor
    static CSteamParentalSettings& GetInstance()
    {
        static CSteamParentalSettings instance;
        return instance;
    }

public:
    // Returns true if parental lock is enabled
    bool BIsParentalLockEnabled() override;

    // Returns true if parental lock is locked
    bool BIsParentalLockLocked() override;

    // Returns true if specified app is blocked
    bool BIsAppBlocked(AppId_t nAppID) override;

    // Returns true if specified app is in block list
    bool BIsAppInBlockList(AppId_t nAppID) override;

    // Returns true if specified feature is blocked
    bool BIsFeatureBlocked(EParentalFeature eFeature) override;

    // Returns true if specified feature is in block list
    bool BIsFeatureInBlockList(EParentalFeature eFeature) override;

private:
    // Private constructor and destructor for singleton
    CSteamParentalSettings();
    ~CSteamParentalSettings();

    // Delete copy constructor and assignment operator
    CSteamParentalSettings(const CSteamParentalSettings&) = delete;
    CSteamParentalSettings& operator=(const CSteamParentalSettings&) = delete;
};

#endif // VAPORCORE_STEAM_PARENTAL_H 