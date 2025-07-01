/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_APP_LIST_H
#define VAPORCORE_STEAM_APP_LIST_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamapplist.h>

//-----------------------------------------------------------------------------
// Purpose: This is a restricted interface that can only be used by previously approved apps,
//	contact your Steam Account Manager if you believe you need access to this API.
//	This interface lets you detect installed apps for the local Steam client, useful for debugging tools
//	to offer lists of apps to debug via Steam.
//-----------------------------------------------------------------------------
class CSteamAppList :
    public ISteamAppList
{
public:
	// Singleton accessor
    static CSteamAppList& GetInstance()
    {
		static CSteamAppList instance;
		return instance;
    }

public:
    uint32 GetNumInstalledApps() override;
    uint32 GetInstalledApps(AppId_t* pvecAppID, uint32 unMaxAppIDs) override;

    int GetAppName(AppId_t nAppID, OUT_STRING() char* pchName, int cchNameMax) override; // returns -1 if no name was found
    int GetAppInstallDir(AppId_t nAppID, char* pchDirectory, int cchNameMax) override; // returns -1 if no dir was found

    int GetAppBuildId(AppId_t nAppID) override; // return the buildid of this app, may change at any time based on backend updates to the game

private:
    // Private constructor and destructor for singleton
    CSteamAppList();
    ~CSteamAppList();

    // Delete copy constructor and assignment operator
    CSteamAppList(const CSteamAppList&) = delete;
    CSteamAppList& operator=(const CSteamAppList&) = delete;
};

#endif // VAPORCORE_STEAM_APP_LIST_H
