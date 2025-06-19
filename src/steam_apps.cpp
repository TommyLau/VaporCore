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

