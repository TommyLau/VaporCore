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

#include "../include/sdk/isteamapps.h"

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
class Steam_Apps : public ISteamApps
{
public:
    Steam_Apps();
    ~Steam_Apps();

	// returns 0 if the key does not exist
	// this may be true on first call, since the app data may not be cached locally yet
	// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
	int GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax ) override;

    // Helper methods
    static Steam_Apps* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Apps* s_pInstance;
};

#endif // VAPORCORE_STEAM_APPS_H

