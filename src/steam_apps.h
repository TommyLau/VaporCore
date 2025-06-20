/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_APPS_H
#define VAPORCORE_STEAM_APPS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamapps.h>
#include <isteamapps001.h>
#include <isteamapps002.h>

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
class Steam_Apps :
    public ISteamApps,
    public ISteamApps001,
    public ISteamApps002
{
public:
    Steam_Apps();
    ~Steam_Apps();

	// returns 0 if the key does not exist
	// this may be true on first call, since the app data may not be cached locally yet
	// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
    // Removed from Steam SDK v1.01, backward compatibility
	int GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax ) override;

    bool BIsSubscribed() override;
    bool BIsLowViolence() override;
    bool BIsCybercafe() override;
    bool BIsVACBanned() override;
    const char *GetCurrentGameLanguage() override;
    const char *GetAvailableGameLanguages() override;

    // only use this member if you need to check ownership of another game related to yours, a demo for example
    bool BIsSubscribedApp( AppId_t appID ) override;

	// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
	bool BIsDlcInstalled( AppId_t appID ) override;

    // Helper methods
    static Steam_Apps* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Apps* s_pInstance;
};

#endif // VAPORCORE_STEAM_APPS_H

