/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>
#include <ctime>

#include "steam_utils.h"
#include "logger.h"

// Static instance
Steam_Utils* Steam_Utils::s_pInstance = nullptr;

Steam_Utils::Steam_Utils()
{
    VLOG_INFO("Steam_Utils constructor called");
}

Steam_Utils::~Steam_Utils()
{
    VLOG_INFO("Steam_Utils destructor called");
}

// return the number of seconds since the user 
uint32 Steam_Utils::GetSecondsSinceAppActive()
{
    VLOG_DEBUG("GetSecondsSinceAppActive called");
    return 0;
}

uint32 Steam_Utils::GetSecondsSinceComputerActive()
{
    VLOG_DEBUG("GetSecondsSinceComputerActive called");
    return 0;
}

// the universe this client is connecting to
EUniverse Steam_Utils::GetConnectedUniverse()
{
    VLOG_DEBUG("GetConnectedUniverse called");
    return k_EUniversePublic;
}

// Steam server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
uint32 Steam_Utils::GetServerRealTime()
{
    VLOG_DEBUG("GetServerRealTime called");
    return static_cast<uint32>(time(nullptr));
}

// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
// e.g "US" or "UK".
const char *Steam_Utils::GetIPCountry()
{
    VLOG_DEBUG("GetIPCountry called");
    return "US";
}

// returns true if the image exists, and valid sizes were filled out
bool Steam_Utils::GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight )
{
    VLOG_DEBUG("GetImageSize called - Image: %d", iImage);
    if (pnWidth) *pnWidth = 0;
    if (pnHeight) *pnHeight = 0;
    return false;
}

// returns true if the image exists, and the buffer was successfully filled out
// results are returned in RGBA format
// the destination buffer size should be 4 * height * width * sizeof(char)
bool Steam_Utils::GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize )
{
    VLOG_DEBUG("GetImageRGBA called - Image: %d, BufferSize: %d", iImage, nDestBufferSize);
    return false;
}

// returns the IP of the reporting server for valve - currently only used in Source engine games
bool Steam_Utils::GetCSERIPPort( uint32 *unIP, uint16 *usPort )
{
    VLOG_DEBUG("GetCSERIPPort called");
    if (unIP) *unIP = 0;
    if (usPort) *usPort = 0;
    return false;
}

// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
uint8 Steam_Utils::GetCurrentBatteryPower()
{
    VLOG_DEBUG("GetCurrentBatteryPower called");
    return 255; // Assume on AC power
}

// returns the appID of the current process
uint32 Steam_Utils::GetAppID()
{
    VLOG_DEBUG("GetAppID called");
    return 0;
}

// Sets the position where the overlay instance for the currently calling game should show notifications.
// This position is per-game and if this function is called from outside of a game context it will do nothing.
void Steam_Utils::SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
{
    VLOG_DEBUG("SetOverlayNotificationPosition called - Position: %d", eNotificationPosition);
}

// Helper methods
Steam_Utils* Steam_Utils::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Utils();
    }
    return s_pInstance;
}

void Steam_Utils::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

