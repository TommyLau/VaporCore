/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_music.h"
#include "logger.h"

// Static instance
Steam_Music* Steam_Music::s_pInstance = nullptr;

Steam_Music::Steam_Music()
{
    VLOG_INFO("Steam_Music constructor called");
}

Steam_Music::~Steam_Music()
{
    VLOG_INFO("Steam_Music destructor called");
}

// Helper methods
Steam_Music* Steam_Music::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Music();
    }
    return s_pInstance;
}

void Steam_Music::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

bool Steam_Music::BIsEnabled()
{
    VLOG_DEBUG("BIsEnabled called");
    return false;
}

bool Steam_Music::BIsPlaying()
{
    VLOG_DEBUG("BIsPlaying called");
    return false;
}

AudioPlayback_Status Steam_Music::GetPlaybackStatus()
{
    VLOG_DEBUG("GetPlaybackStatus called");
    return AudioPlayback_Undefined;
}

void Steam_Music::Play()
{
    VLOG_DEBUG("Play called");
}

void Steam_Music::Pause()
{
    VLOG_DEBUG("Pause called");
}

void Steam_Music::PlayPrevious()
{
    VLOG_DEBUG("PlayPrevious called");
}

void Steam_Music::PlayNext()
{
    VLOG_DEBUG("PlayNext called");
}

// volume is between 0.0 and 1.0
void Steam_Music::SetVolume(float flVolume)
{
    VLOG_DEBUG("SetVolume called with volume: %f", flVolume);
}

float Steam_Music::GetVolume()
{
    VLOG_DEBUG("GetVolume called");
    return 0.0f;
}
