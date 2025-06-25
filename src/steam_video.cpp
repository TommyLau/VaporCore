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
Steam_Video* Steam_Video::s_pInstance = nullptr;

Steam_Video::Steam_Video()
{
    VLOG_INFO("Steam_Video constructor called");
}

Steam_Video::~Steam_Video()
{
    VLOG_INFO("Steam_Video destructor called");
}

// Helper methods
Steam_Video* Steam_Video::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Video();
    }
    return s_pInstance;
}

void Steam_Video::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Get a URL suitable for streaming the given Video app ID's video
void Steam_Video::GetVideoURL( AppId_t unVideoAppID )
{
	VLOG_DEBUG("GetVideoURL called - %d", unVideoAppID);
}

// returns true if user is uploading a live broadcast
bool Steam_Video::IsBroadcasting( int *pnNumViewers )
{
    VLOG_DEBUG("IsBroadcasting called");
    return false;
}
