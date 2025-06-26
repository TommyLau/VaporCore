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
#include "steam_video.h"

// Static instance
CSteamVideo* CSteamVideo::s_pInstance = nullptr;

CSteamVideo::CSteamVideo()
{
    VLOG_INFO("CSteamVideo constructor called");
}

CSteamVideo::~CSteamVideo()
{
    VLOG_INFO("CSteamVideo destructor called");
}

// Helper methods
CSteamVideo* CSteamVideo::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamVideo();
    }
    return s_pInstance;
}

void CSteamVideo::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Get a URL suitable for streaming the given Video app ID's video
void CSteamVideo::GetVideoURL( AppId_t unVideoAppID )
{
	VLOG_DEBUG("GetVideoURL called - %d", unVideoAppID);
}

// returns true if user is uploading a live broadcast
bool CSteamVideo::IsBroadcasting( int *pnNumViewers )
{
    VLOG_DEBUG("IsBroadcasting called");
    return false;
}
