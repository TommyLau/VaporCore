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
#include "steam_remote_play.h"

CSteamRemotePlay::CSteamRemotePlay()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamRemotePlay::~CSteamRemotePlay()
{
    VLOG_INFO(__FUNCTION__);
}

// Get the number of currently connected Steam Remote Play sessions
uint32 CSteamRemotePlay::GetSessionCount()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Get the currently connected Steam Remote Play session ID at the specified index. Returns zero if index is out of bounds.
RemotePlaySessionID_t CSteamRemotePlay::GetSessionID( int iSessionIndex )
{
    VLOG_INFO(__FUNCTION__ " - SessionIndex: %d", iSessionIndex);
    return 0;
}

// Get the SteamID of the connected user
CSteamID CSteamRemotePlay::GetSessionSteamID( RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %u", unSessionID);
    return CSteamID();
}

// Get the name of the session client device
// This returns NULL if the sessionID is not valid
const char* CSteamRemotePlay::GetSessionClientName( RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %u", unSessionID);
    return nullptr;
}

// Get the form factor of the session client device
ESteamDeviceFormFactor CSteamRemotePlay::GetSessionClientFormFactor( RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %u", unSessionID);
    return k_ESteamDeviceFormFactorUnknown;
}

// Get the resolution, in pixels, of the session client device
// This is set to 0x0 if the resolution is not available
bool CSteamRemotePlay::BGetSessionClientResolution( RemotePlaySessionID_t unSessionID, int *pnResolutionX, int *pnResolutionY )
{
    VLOG_INFO(__FUNCTION__ " - SessionID: %u, ResolutionX: %p, ResolutionY: %p", unSessionID, pnResolutionX, pnResolutionY);
    return false;
}

// Invite a friend to Remote Play Together
// This returns false if the invite can't be sent
bool CSteamRemotePlay::BSendRemotePlayTogetherInvite( CSteamID steamIDFriend )
{
    VLOG_INFO(__FUNCTION__ " - SteamID: %llu", steamIDFriend.ConvertToUint64());
    return false;
}
