/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef ISTEAMPARENTALSETTINGS_H
#define ISTEAMPARENTALSETTINGS_H
#ifdef _WIN32
#pragma once
#endif

#include "steam_api_common.h"

// Feature types for parental settings
enum EParentalFeature
{
	k_EFeatureInvalid = 0,
	k_EFeatureStore = 1,
	k_EFeatureCommunity = 2,
	k_EFeatureProfile = 3,
	k_EFeatureFriends = 4,
	k_EFeatureNews = 5,
	k_EFeatureTrading = 6,
	k_EFeatureSettings = 7,
	k_EFeatureConsole = 8,
	k_EFeatureBrowser = 9,
	k_EFeatureParentalSetup = 10,
	k_EFeatureLibrary = 11,
	k_EFeatureTest = 12,
	k_EFeatureSiteLicense = 13,
	k_EFeatureMax
};

class ISteamParentalSettings
{
public:
	virtual bool BIsParentalLockEnabled() = 0;
	virtual bool BIsParentalLockLocked() = 0;

	virtual bool BIsAppBlocked( AppId_t nAppID ) = 0;
	virtual bool BIsAppInBlockList( AppId_t nAppID ) = 0;

	virtual bool BIsFeatureBlocked( EParentalFeature eFeature ) = 0;
	virtual bool BIsFeatureInBlockList( EParentalFeature eFeature ) = 0;
};

#define STEAMPARENTALSETTINGS_INTERFACE_VERSION "STEAMPARENTALSETTINGS_INTERFACE_VERSION001"

// Global interface accessor
inline ISteamParentalSettings *SteamParentalSettings();
STEAM_DEFINE_USER_INTERFACE_ACCESSOR( ISteamParentalSettings *, SteamParentalSettings, STEAMPARENTALSETTINGS_INTERFACE_VERSION );

//-----------------------------------------------------------------------------
// Purpose: Callback for querying UGC
//-----------------------------------------------------------------------------
struct SteamParentalSettingsChanged_t
{
	enum { k_iCallback = k_ISteamParentalSettingsCallbacks + 1 };
};


#endif // ISTEAMPARENTALSETTINGS_H
