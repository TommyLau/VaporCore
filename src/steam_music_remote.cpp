/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "steam_music_remote.h"
#include "logger.h"

// Static instance
Steam_Music_Remote* Steam_Music_Remote::s_pInstance = nullptr;

Steam_Music_Remote::Steam_Music_Remote()
{
    VLOG_INFO("Steam_Music_Remote constructor called");
}

Steam_Music_Remote::~Steam_Music_Remote()
{
    VLOG_INFO("Steam_Music_Remote destructor called");
}

// Helper methods
Steam_Music_Remote* Steam_Music_Remote::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Music_Remote();
    }
    return s_pInstance;
}

void Steam_Music_Remote::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Service Definition
bool Steam_Music_Remote::RegisterSteamMusicRemote(const char *pchName)
{
    VLOG_DEBUG("RegisterSteamMusicRemote called");
    return false;
}

bool Steam_Music_Remote::DeregisterSteamMusicRemote()
{
    VLOG_DEBUG("DeregisterSteamMusicRemote called");
    return false;
}

bool Steam_Music_Remote::BIsCurrentMusicRemote()
{
    VLOG_DEBUG("BIsCurrentMusicRemote called");
    return false;
}

bool Steam_Music_Remote::BActivationSuccess(bool bValue)
{
    VLOG_DEBUG("BActivationSuccess called");
    return false;
}

bool Steam_Music_Remote::SetDisplayName(const char *pchDisplayName)
{
    VLOG_DEBUG("SetDisplayName called");
    return false;
}

bool Steam_Music_Remote::SetPNGIcon_64x64(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("SetPNGIcon_64x64 called");
    return false;
}

// Abilities for the user interface
bool Steam_Music_Remote::EnablePlayPrevious(bool bValue)
{
    VLOG_DEBUG("EnablePlayPrevious called");
    return false;
}

bool Steam_Music_Remote::EnablePlayNext(bool bValue)
{
    VLOG_DEBUG("EnablePlayNext called");
    return false;
}

bool Steam_Music_Remote::EnableShuffled(bool bValue)
{
    VLOG_DEBUG("EnableShuffled called");
    return false;
}

bool Steam_Music_Remote::EnableLooped(bool bValue)
{
    VLOG_DEBUG("EnableLooped called");
    return false;
}

bool Steam_Music_Remote::EnableQueue(bool bValue)
{
    VLOG_DEBUG("EnableQueue called");
    return false;
}

bool Steam_Music_Remote::EnablePlaylists(bool bValue)
{
    VLOG_DEBUG("EnablePlaylists called");
    return false;
}

// Status
bool Steam_Music_Remote::UpdatePlaybackStatus(AudioPlayback_Status nStatus)
{
    VLOG_DEBUG("UpdatePlaybackStatus called");
    return false;
}

bool Steam_Music_Remote::UpdateShuffled(bool bValue)
{
    VLOG_DEBUG("UpdateShuffled called");
    return false;
}

bool Steam_Music_Remote::UpdateLooped(bool bValue)
{
    VLOG_DEBUG("UpdateLooped called");
    return false;
}

// volume is between 0.0 and 1.0
bool Steam_Music_Remote::UpdateVolume(float flValue)
{
    VLOG_DEBUG("UpdateVolume called");
    return false;
}

// Current Entry
bool Steam_Music_Remote::CurrentEntryWillChange()
{
    VLOG_DEBUG("CurrentEntryWillChange called");
    return false;
}

bool Steam_Music_Remote::CurrentEntryIsAvailable(bool bAvailable)
{
    VLOG_DEBUG("CurrentEntryIsAvailable called");
    return false;
}

bool Steam_Music_Remote::UpdateCurrentEntryText(const char *pchText)
{
    VLOG_DEBUG("UpdateCurrentEntryText called");
    return false;
}

bool Steam_Music_Remote::UpdateCurrentEntryElapsedSeconds(int nValue)
{
    VLOG_DEBUG("UpdateCurrentEntryElapsedSeconds called");
    return false;
}

bool Steam_Music_Remote::UpdateCurrentEntryCoverArt(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("UpdateCurrentEntryCoverArt called");
    return false;
}

bool Steam_Music_Remote::CurrentEntryDidChange()
{
    VLOG_DEBUG("CurrentEntryDidChange called");
    return false;
}

// Queue
bool Steam_Music_Remote::QueueWillChange()
{
    VLOG_DEBUG("QueueWillChange called");
    return false;
}

bool Steam_Music_Remote::ResetQueueEntries()
{
    VLOG_DEBUG("ResetQueueEntries called");
    return false;
}

bool Steam_Music_Remote::SetQueueEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_DEBUG("SetQueueEntry called");
    return false;
}

bool Steam_Music_Remote::SetCurrentQueueEntry(int nID)
{
    VLOG_DEBUG("SetCurrentQueueEntry called");
    return false;
}

bool Steam_Music_Remote::QueueDidChange()
{
    VLOG_DEBUG("QueueDidChange called");
    return false;
}

// Playlist
bool Steam_Music_Remote::PlaylistWillChange()
{
    VLOG_DEBUG("PlaylistWillChange called");
    return false;
}

bool Steam_Music_Remote::ResetPlaylistEntries()
{
    VLOG_DEBUG("ResetPlaylistEntries called");
    return false;
}

bool Steam_Music_Remote::SetPlaylistEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_DEBUG("SetPlaylistEntry called");
    return false;
}

bool Steam_Music_Remote::SetCurrentPlaylistEntry(int nID)
{
    VLOG_DEBUG("SetCurrentPlaylistEntry called");
    return false;
}

bool Steam_Music_Remote::PlaylistDidChange()
{
    VLOG_DEBUG("PlaylistDidChange called");
    return false;
}
