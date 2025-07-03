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

#include <isteamvideo.h>
#include <isteamvideo001.h>

//-----------------------------------------------------------------------------
// Purpose: Steam Video API
//-----------------------------------------------------------------------------
class CSteamVideo :
	public ISteamVideo,
    public ISteamVideo001
{
public:
	// Singleton accessor
    static CSteamVideo& GetInstance()
    {
		static CSteamVideo instance;
		return instance;
    }

public:
	// Get a URL suitable for streaming the given Video app ID's video
	void GetVideoURL( AppId_t unVideoAppID ) override;

	// returns true if user is uploading a live broadcast
	bool IsBroadcasting( int *pnNumViewers ) override;

	// Get the OPF Details for 360 Video Playback
	void GetOPFSettings( AppId_t unVideoAppID ) override;
	bool GetOPFStringForApp( AppId_t unVideoAppID, char *pchBuffer, int32 *pnBufferSize ) override;

private:
    // Private constructor and destructor for singleton
    CSteamVideo();
    ~CSteamVideo();

    // Delete copy constructor and assignment operator
    CSteamVideo(const CSteamVideo&) = delete;
    CSteamVideo& operator=(const CSteamVideo&) = delete;
};

#endif // VAPORCORE_STEAM_VIDEO_H
