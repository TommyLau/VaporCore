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
#include "steam_app_list.h"

CSteamAppList::CSteamAppList()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamAppList::~CSteamAppList()
{
    VLOG_INFO(__FUNCTION__);
}

uint32 CSteamAppList::GetNumInstalledApps()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

uint32 CSteamAppList::GetInstalledApps(AppId_t* pvecAppID, uint32 unMaxAppIDs)
{
    VLOG_INFO(__FUNCTION__ " - MaxAppIDs: %d", unMaxAppIDs);
    return 0;
}

// returns -1 if no name was found
int CSteamAppList::GetAppName(AppId_t nAppID, char* pchName, int cchNameMax)
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d, MaxNameLength: %d", nAppID, cchNameMax);
    return -1;
}

// returns -1 if no dir was found
int CSteamAppList::GetAppInstallDir(AppId_t nAppID, char* pchDirectory, int cchNameMax)
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d, MaxDirLength: %d", nAppID, cchNameMax);
    return -1;
}

// return the buildid of this app, may change at any time based on backend updates to the game
int CSteamAppList::GetAppBuildId(AppId_t nAppID)
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d", nAppID);
    return 0;
}
