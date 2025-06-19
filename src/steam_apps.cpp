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

