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
#include "steam_music.h"

CSteamMusic::CSteamMusic()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMusic::~CSteamMusic()
{
    VLOG_INFO(__FUNCTION__);
}

bool CSteamMusic::BIsEnabled()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusic::BIsPlaying()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

AudioPlayback_Status CSteamMusic::GetPlaybackStatus()
{
    VLOG_INFO(__FUNCTION__);
    return AudioPlayback_Undefined;
}

void CSteamMusic::Play()
{
    VLOG_INFO(__FUNCTION__);
}

void CSteamMusic::Pause()
{
    VLOG_INFO(__FUNCTION__);
}

void CSteamMusic::PlayPrevious()
{
    VLOG_INFO(__FUNCTION__);
}

void CSteamMusic::PlayNext()
{
    VLOG_INFO(__FUNCTION__);
}

// volume is between 0.0 and 1.0
void CSteamMusic::SetVolume(float flVolume)
{
    VLOG_INFO(__FUNCTION__ " - Volume: %f", flVolume);
}

float CSteamMusic::GetVolume()
{
    VLOG_INFO(__FUNCTION__);
    return 0.0f;
}
