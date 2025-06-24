/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_app_list.h"
#include "logger.h"

// Static instance
Steam_App_List* Steam_App_List::s_pInstance = nullptr;

Steam_App_List::Steam_App_List()
{
    VLOG_INFO("Steam_App_List constructor called");
}

Steam_App_List::~Steam_App_List()
{
    VLOG_INFO("Steam_App_List destructor called");
}

// Helper methods
Steam_App_List* Steam_App_List::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_App_List();
    }
    return s_pInstance;
}

void Steam_App_List::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

uint32 Steam_App_List::GetNumInstalledApps()
{
    VLOG_DEBUG("GetNumInstalledApps called");
    return 0;
}

uint32 Steam_App_List::GetInstalledApps(AppId_t* pvecAppID, uint32 unMaxAppIDs)
{
    VLOG_DEBUG("GetInstalledApps called - MaxAppIDs: %d", unMaxAppIDs);
    return 0;
}

// returns -1 if no name was found
int Steam_App_List::GetAppName(AppId_t nAppID, char* pchName, int cchNameMax)
{
    VLOG_DEBUG("GetAppName called - AppID: %d, MaxNameLength: %d", nAppID, cchNameMax);
    return -1;
}

// returns -1 if no dir was found
int Steam_App_List::GetAppInstallDir(AppId_t nAppID, char* pchDirectory, int cchNameMax)
{
    VLOG_DEBUG("GetAppInstallDir called - AppID: %d, MaxDirLength: %d", nAppID, cchNameMax);
    return -1;
}

// return the buildid of this app, may change at any time based on backend updates to the game
int Steam_App_List::GetAppBuildId(AppId_t nAppID)
{
    VLOG_DEBUG("GetAppBuildId called - AppID: %d", nAppID);
    return 0;
}
