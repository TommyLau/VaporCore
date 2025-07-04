/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_REMOTE_PLAY_H
#define VAPORCORE_STEAM_REMOTE_PLAY_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamremoteplay.h>

//-----------------------------------------------------------------------------
// Purpose: The form factor of a device
//-----------------------------------------------------------------------------
class CSteamRemotePlay :
    public ISteamRemotePlay
{
public:
	// Singleton accessor
    static CSteamRemotePlay& GetInstance()
    {
		static CSteamRemotePlay instance;
		return instance;
    }

public:
	// Get the number of currently connected Steam Remote Play sessions
	uint32 GetSessionCount() override;
	
	// Get the currently connected Steam Remote Play session ID at the specified index. Returns zero if index is out of bounds.
	RemotePlaySessionID_t GetSessionID( int iSessionIndex ) override;

	// Get the SteamID of the connected user
	CSteamID GetSessionSteamID( RemotePlaySessionID_t unSessionID ) override;

	// Get the name of the session client device
	// This returns NULL if the sessionID is not valid
	const char *GetSessionClientName( RemotePlaySessionID_t unSessionID ) override;

	// Get the form factor of the session client device
	ESteamDeviceFormFactor GetSessionClientFormFactor( RemotePlaySessionID_t unSessionID ) override;

	// Get the resolution, in pixels, of the session client device
	// This is set to 0x0 if the resolution is not available
	bool BGetSessionClientResolution( RemotePlaySessionID_t unSessionID, int *pnResolutionX, int *pnResolutionY ) override;

	// Invite a friend to Remote Play Together
	// This returns false if the invite can't be sent
	bool BSendRemotePlayTogetherInvite( CSteamID steamIDFriend ) override;

private:
    // Private constructor and destructor for singleton
    CSteamRemotePlay();
    ~CSteamRemotePlay();

    // Delete copy constructor and assignment operator
    CSteamRemotePlay(const CSteamRemotePlay&) = delete;
    CSteamRemotePlay& operator=(const CSteamRemotePlay&) = delete;
};

#endif // VAPORCORE_STEAM_REMOTE_PLAY_H
