/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_apps.h"
#include "logger.h"

// Static instance
Steam_Apps* Steam_Apps::s_pInstance = nullptr;

Steam_Apps::Steam_Apps()
{
    VLOG_INFO("Steam_Apps constructor called");
}

Steam_Apps::~Steam_Apps()
{
    VLOG_INFO("Steam_Apps destructor called");
}

// returns 0 if the key does not exist
// this may be true on first call, since the app data may not be cached locally yet
// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
// Removed from Steam SDK v1.01, backward compatibility
int Steam_Apps::GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax )
{
    VLOG_DEBUG("GetAppData called - AppID: %u, Key: %s", nAppID, pchKey ? pchKey : "null");
    
    if (!pchKey || !pchValue || cchValueMax <= 0)
    {
        return 0;
    }
    
    // Return empty string for now - can be extended later
    pchValue[0] = '\0';
    return 0;
}

bool Steam_Apps::BIsSubscribed()
{
    return false;
}

bool Steam_Apps::BIsLowViolence()
{
    return false;
}

bool Steam_Apps::BIsCybercafe()
{
    return false;
}

bool Steam_Apps::BIsVACBanned()
{
    return false;
}

const char *Steam_Apps::GetCurrentGameLanguage()
{
    return nullptr;
}

const char *Steam_Apps::GetAvailableGameLanguages()
{
    return nullptr;
}

// only use this member if you need to check ownership of another game related to yours, a demo for example
bool Steam_Apps::BIsSubscribedApp( AppId_t appID )
{
    return false;
}

// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
bool Steam_Apps::BIsDlcInstalled( AppId_t appID )
{
    return false;
}

// returns the Unix time of the purchase of the app
uint32 Steam_Apps::GetEarliestPurchaseUnixTime( AppId_t nAppID )
{
    return 0;
}

// Checks if the user is subscribed to the current app through a free weekend
// This function will return false for users who have a retail or other type of license
// Before using, please ask your Valve technical contact how to package and secure your free weekened
bool Steam_Apps::BIsSubscribedFromFreeWeekend()
{
    return false;
}

// Returns the number of DLC pieces for the running app
int Steam_Apps::GetDLCCount()
{
    return 0;
}

// Returns metadata for DLC by index, of range [0, GetDLCCount()]
bool Steam_Apps::BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize )
{
    return false;
}

// Install/Uninstall control for optional DLC
void Steam_Apps::InstallDLC( AppId_t nAppID )
{
}

void Steam_Apps::UninstallDLC( AppId_t nAppID )
{
}

// Helper methods
Steam_Apps* Steam_Apps::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Apps();
    }
    return s_pInstance;
}

void Steam_Apps::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
