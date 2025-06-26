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

// Static instance
CSteamMusic* CSteamMusic::s_pInstance = nullptr;

CSteamMusic::CSteamMusic()
{
    VLOG_INFO("CSteamMusic constructor called");
}

CSteamMusic::~CSteamMusic()
{
    VLOG_INFO("CSteamMusic destructor called");
}

// Helper methods
CSteamMusic* CSteamMusic::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamMusic();
    }
    return s_pInstance;
}

void CSteamMusic::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

bool CSteamMusic::BIsEnabled()
{
    VLOG_DEBUG("BIsEnabled called");
    return false;
}

bool CSteamMusic::BIsPlaying()
{
    VLOG_DEBUG("BIsPlaying called");
    return false;
}

AudioPlayback_Status CSteamMusic::GetPlaybackStatus()
{
    VLOG_DEBUG("GetPlaybackStatus called");
    return AudioPlayback_Undefined;
}

void CSteamMusic::Play()
{
    VLOG_DEBUG("Play called");
}

void CSteamMusic::Pause()
{
    VLOG_DEBUG("Pause called");
}

void CSteamMusic::PlayPrevious()
{
    VLOG_DEBUG("PlayPrevious called");
}

void CSteamMusic::PlayNext()
{
    VLOG_DEBUG("PlayNext called");
}

// volume is between 0.0 and 1.0
void CSteamMusic::SetVolume(float flVolume)
{
    VLOG_DEBUG("SetVolume called with volume: %f", flVolume);
}

float CSteamMusic::GetVolume()
{
    VLOG_DEBUG("GetVolume called");
    return 0.0f;
}
