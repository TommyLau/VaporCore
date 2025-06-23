/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_CONTROLLER_H
#define VAPORCORE_STEAM_CONTROLLER_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamcontroller.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing stats, achievements, and leaderboard information
//-----------------------------------------------------------------------------
class Steam_Controller :
    public ISteamController
{
public:
    Steam_Controller();
    ~Steam_Controller();

    // Helper methods
    static Steam_Controller* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Controller* s_pInstance;
};

#endif // VAPORCORE_STEAM_CONTROLLER_H
