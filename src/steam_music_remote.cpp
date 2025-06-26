/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "vapor_base.h"
#include "steam_music_remote.h"

// Static instance
CSteamMusicRemote* CSteamMusicRemote::s_pInstance = nullptr;

CSteamMusicRemote::CSteamMusicRemote()
{
    VLOG_INFO("CSteamMusicRemote constructor called");
}

CSteamMusicRemote::~CSteamMusicRemote()
{
    VLOG_INFO("CSteamMusicRemote destructor called");
}

// Helper methods
CSteamMusicRemote* CSteamMusicRemote::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamMusicRemote();
    }
    return s_pInstance;
}

void CSteamMusicRemote::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Service Definition
bool CSteamMusicRemote::RegisterSteamMusicRemote(const char *pchName)
{
    VLOG_DEBUG("RegisterSteamMusicRemote called");
    return false;
}

bool CSteamMusicRemote::DeregisterSteamMusicRemote()
{
    VLOG_DEBUG("DeregisterSteamMusicRemote called");
    return false;
}

bool CSteamMusicRemote::BIsCurrentMusicRemote()
{
    VLOG_DEBUG("BIsCurrentMusicRemote called");
    return false;
}

bool CSteamMusicRemote::BActivationSuccess(bool bValue)
{
    VLOG_DEBUG("BActivationSuccess called");
    return false;
}

bool CSteamMusicRemote::SetDisplayName(const char *pchDisplayName)
{
    VLOG_DEBUG("SetDisplayName called");
    return false;
}

bool CSteamMusicRemote::SetPNGIcon_64x64(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("SetPNGIcon_64x64 called");
    return false;
}

// Abilities for the user interface
bool CSteamMusicRemote::EnablePlayPrevious(bool bValue)
{
    VLOG_DEBUG("EnablePlayPrevious called");
    return false;
}

bool CSteamMusicRemote::EnablePlayNext(bool bValue)
{
    VLOG_DEBUG("EnablePlayNext called");
    return false;
}

bool CSteamMusicRemote::EnableShuffled(bool bValue)
{
    VLOG_DEBUG("EnableShuffled called");
    return false;
}

bool CSteamMusicRemote::EnableLooped(bool bValue)
{
    VLOG_DEBUG("EnableLooped called");
    return false;
}

bool CSteamMusicRemote::EnableQueue(bool bValue)
{
    VLOG_DEBUG("EnableQueue called");
    return false;
}

bool CSteamMusicRemote::EnablePlaylists(bool bValue)
{
    VLOG_DEBUG("EnablePlaylists called");
    return false;
}

// Status
bool CSteamMusicRemote::UpdatePlaybackStatus(AudioPlayback_Status nStatus)
{
    VLOG_DEBUG("UpdatePlaybackStatus called");
    return false;
}

bool CSteamMusicRemote::UpdateShuffled(bool bValue)
{
    VLOG_DEBUG("UpdateShuffled called");
    return false;
}

bool CSteamMusicRemote::UpdateLooped(bool bValue)
{
    VLOG_DEBUG("UpdateLooped called");
    return false;
}

// volume is between 0.0 and 1.0
bool CSteamMusicRemote::UpdateVolume(float flValue)
{
    VLOG_DEBUG("UpdateVolume called");
    return false;
}

// Current Entry
bool CSteamMusicRemote::CurrentEntryWillChange()
{
    VLOG_DEBUG("CurrentEntryWillChange called");
    return false;
}

bool CSteamMusicRemote::CurrentEntryIsAvailable(bool bAvailable)
{
    VLOG_DEBUG("CurrentEntryIsAvailable called");
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryText(const char *pchText)
{
    VLOG_DEBUG("UpdateCurrentEntryText called");
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryElapsedSeconds(int nValue)
{
    VLOG_DEBUG("UpdateCurrentEntryElapsedSeconds called");
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryCoverArt(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("UpdateCurrentEntryCoverArt called");
    return false;
}

bool CSteamMusicRemote::CurrentEntryDidChange()
{
    VLOG_DEBUG("CurrentEntryDidChange called");
    return false;
}

// Queue
bool CSteamMusicRemote::QueueWillChange()
{
    VLOG_DEBUG("QueueWillChange called");
    return false;
}

bool CSteamMusicRemote::ResetQueueEntries()
{
    VLOG_DEBUG("ResetQueueEntries called");
    return false;
}

bool CSteamMusicRemote::SetQueueEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_DEBUG("SetQueueEntry called");
    return false;
}

bool CSteamMusicRemote::SetCurrentQueueEntry(int nID)
{
    VLOG_DEBUG("SetCurrentQueueEntry called");
    return false;
}

bool CSteamMusicRemote::QueueDidChange()
{
    VLOG_DEBUG("QueueDidChange called");
    return false;
}

// Playlist
bool CSteamMusicRemote::PlaylistWillChange()
{
    VLOG_DEBUG("PlaylistWillChange called");
    return false;
}

bool CSteamMusicRemote::ResetPlaylistEntries()
{
    VLOG_DEBUG("ResetPlaylistEntries called");
    return false;
}

bool CSteamMusicRemote::SetPlaylistEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_DEBUG("SetPlaylistEntry called");
    return false;
}

bool CSteamMusicRemote::SetCurrentPlaylistEntry(int nID)
{
    VLOG_DEBUG("SetCurrentPlaylistEntry called");
    return false;
}

bool CSteamMusicRemote::PlaylistDidChange()
{
    VLOG_DEBUG("PlaylistDidChange called");
    return false;
}
