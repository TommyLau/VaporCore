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
// Purpose: Steam Video api
//-----------------------------------------------------------------------------
class Steam_Video :
	public ISteamVideo
{
private:
    // Singleton instance
    static Steam_Video* s_pInstance;

public:
    Steam_Video();
    ~Steam_Video();

    // Helper methods
    static Steam_Video* GetInstance();
    static void ReleaseInstance();

	// Get a URL suitable for streaming the given Video app ID's video
	void GetVideoURL( AppId_t unVideoAppID ) override;
};

#endif // VAPORCORE_STEAM_VIDEO_H
