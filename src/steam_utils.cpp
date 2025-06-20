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

// API asynchronous call results
// can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
bool Steam_Utils::IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed )
{
    VLOG_DEBUG("IsAPICallCompleted called - Call: %u", hSteamAPICall);
    return false;
}

ESteamAPICallFailure Steam_Utils::GetAPICallFailureReason( SteamAPICall_t hSteamAPICall )
{
    VLOG_DEBUG("GetAPICallFailureReason called - Call: %u", hSteamAPICall);
    return k_ESteamAPICallFailureNone;
}

bool Steam_Utils::GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed )
{
    VLOG_DEBUG("GetAPICallResult called - Call: %u", hSteamAPICall);
    return false;
}

// this needs to be called every frame to process matchmaking results
// redundant if you're already calling SteamAPI_RunCallbacks()
void Steam_Utils::RunFrame()
{
    VLOG_DEBUG("RunFrame called");
}

// returns the number of IPC calls made since the last time this function was called
// Used for perf debugging so you can understand how many IPC calls your game makes per frame
// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
// control how often you do them.
uint32 Steam_Utils::GetIPCCallCount()
{
    VLOG_DEBUG("GetIPCCallCount called");
    return 0;
}

// API warning handling
// 'int' is the severity; 0 for msg, 1 for warning
// 'const char *' is the text of the message
// callbacks will occur directly after the API function is called that generated the warning or message
void Steam_Utils::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
    VLOG_DEBUG("SetWarningMessageHook called - Function: %p", pFunction);
}

// Returns true if the overlay is running & the user can access it. The overlay process could take a few seconds to
// start & hook the game process, so this function will initially return false while the overlay is loading.
bool Steam_Utils::IsOverlayEnabled()
{
    VLOG_DEBUG("IsOverlayEnabled called");
    return false;
}

// Normally this call is unneeded if your game has a constantly running frame loop that calls the 
// D3D Present API, or OGL SwapBuffers API every frame.
//
// However, if you have a game that only refreshes the screen on an event driven basis then that can break 
// the overlay, as it uses your Present/SwapBuffers calls to drive it's internal frame loop and it may also
// need to Present() to the screen any time an even needing a notification happens or when the overlay is
// brought up over the game by a user.  You can use this API to ask the overlay if it currently need a present
// in that case, and then you can check for this periodically (roughly 33hz is desirable) and make sure you
// refresh the screen with Present or SwapBuffers to allow the overlay to do it's work.
bool Steam_Utils::BOverlayNeedsPresent()
{
    VLOG_DEBUG("BOverlayNeedsPresent called");
    return false;
}

// Asynchronous call to check if file is signed, result is returned in CheckFileSignature_t
SteamAPICall_t Steam_Utils::CheckFileSignature( const char *szFileName )
{
    VLOG_DEBUG("CheckFileSignature called - File: %s", szFileName);
    return k_uAPICallInvalid;
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

