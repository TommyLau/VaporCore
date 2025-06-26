/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_VIDEO_H
#define VAPORCORE_STEAM_VIDEO_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamvideo.h>

//-----------------------------------------------------------------------------
// Purpose: Steam Video API
//-----------------------------------------------------------------------------
class CSteamVideo :
	public ISteamVideo
{
private:
    // Singleton instance
    static CSteamVideo* s_pInstance;

public:
    CSteamVideo();
    ~CSteamVideo();

    // Helper methods
    static CSteamVideo* GetInstance();
    static void ReleaseInstance();

	// Get a URL suitable for streaming the given Video app ID's video
	void GetVideoURL( AppId_t unVideoAppID ) override;

	// returns true if user is uploading a live broadcast
	bool IsBroadcasting( int *pnNumViewers ) override;
};

#endif // VAPORCORE_STEAM_VIDEO_H
