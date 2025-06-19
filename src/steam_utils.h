/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_UTILS_H
#define VAPORCORE_STEAM_UTILS_H
#ifdef _WIN32
#pragma once
#endif

#include "../include/sdk/isteamutils.h"

//-----------------------------------------------------------------------------
// Purpose: interface to user independent utility functions
//-----------------------------------------------------------------------------
class Steam_Utils : public ISteamUtils
{
public:
    Steam_Utils();
    ~Steam_Utils();

	// return the number of seconds since the user 
	uint32 GetSecondsSinceAppActive() override;
	uint32 GetSecondsSinceComputerActive() override;

	// the universe this client is connecting to
	EUniverse GetConnectedUniverse() override;

	// Steam server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
	uint32 GetServerRealTime() override;

	// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
	// e.g "US" or "UK".
	const char *GetIPCountry() override;

	// returns true if the image exists, and valid sizes were filled out
	bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight ) override;

	// returns true if the image exists, and the buffer was successfully filled out
	// results are returned in RGBA format
	// the destination buffer size should be 4 * height * width * sizeof(char)
	bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize ) override;

	// returns the IP of the reporting server for valve - currently only used in Source engine games
	bool GetCSERIPPort( uint32 *unIP, uint16 *usPort ) override;

	// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
	uint8 GetCurrentBatteryPower() override;

	// returns the appID of the current process
	uint32 GetAppID() override;

	// Sets the position where the overlay instance for the currently calling game should show notifications.
	// This position is per-game and if this function is called from outside of a game context it will do nothing.
	void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition ) override;

    // Helper methods
    static Steam_Utils* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Utils* s_pInstance;
};

#endif // VAPORCORE_STEAM_UTILS_H

