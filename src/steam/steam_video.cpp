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

CSteamVideo::CSteamVideo()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamVideo::~CSteamVideo()
{
    VLOG_INFO(__FUNCTION__);
}

// Get a URL suitable for streaming the given Video app ID's video
void CSteamVideo::GetVideoURL( AppId_t unVideoAppID )
{
    VLOG_INFO(__FUNCTION__ " - app id: %d", unVideoAppID);
}

// returns true if user is uploading a live broadcast
bool CSteamVideo::IsBroadcasting( int *pnNumViewers )
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Get the OPF Details for 360 Video Playback
void CSteamVideo::GetOPFSettings(AppId_t unVideoAppID)
{
    VLOG_INFO(__FUNCTION__ " - app id: %d", unVideoAppID);
}

bool CSteamVideo::GetOPFStringForApp(AppId_t unVideoAppID, char *pchBuffer, int32 *pnBufferSize)
{
    VLOG_INFO(__FUNCTION__ " - app id: %d", unVideoAppID);
    return false;
}
