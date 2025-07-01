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

CSteamMusicRemote::CSteamMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMusicRemote::~CSteamMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
}

// Service Definition
bool CSteamMusicRemote::RegisterSteamMusicRemote(const char *pchName)
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchName);
    return false;
}

bool CSteamMusicRemote::DeregisterSteamMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::BIsCurrentMusicRemote()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::BActivationSuccess(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::SetDisplayName(const char *pchDisplayName)
{
    VLOG_INFO(__FUNCTION__ " - Name: %s", pchDisplayName);
    return false;
}

bool CSteamMusicRemote::SetPNGIcon_64x64(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_INFO(__FUNCTION__ " - Buffer: %p, Length: %u", pvBuffer, cbBufferLength);
    return false;
}

// Abilities for the user interface
bool CSteamMusicRemote::EnablePlayPrevious(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::EnablePlayNext(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::EnableShuffled(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::EnableLooped(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::EnableQueue(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::EnablePlaylists(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

// Status
bool CSteamMusicRemote::UpdatePlaybackStatus(AudioPlayback_Status nStatus)
{
    VLOG_INFO(__FUNCTION__ " - Status: %d", nStatus);
    return false;
}

bool CSteamMusicRemote::UpdateShuffled(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::UpdateLooped(bool bValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %s", bValue ? "true" : "false");
    return false;
}

// volume is between 0.0 and 1.0
bool CSteamMusicRemote::UpdateVolume(float flValue)
{
    VLOG_INFO(__FUNCTION__ " - Value: %f", flValue);
    return false;
}

// Current Entry
bool CSteamMusicRemote::CurrentEntryWillChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::CurrentEntryIsAvailable(bool bAvailable)
{
    VLOG_INFO(__FUNCTION__ " - Available: %s", bAvailable ? "true" : "false");
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryText(const char *pchText)
{
    VLOG_INFO(__FUNCTION__ " - Text: %s", pchText);
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryElapsedSeconds(int nValue)
{
    VLOG_INFO(__FUNCTION__ " - Seconds: %d", nValue);
    return false;
}

bool CSteamMusicRemote::UpdateCurrentEntryCoverArt(void *pvBuffer, uint32 cbBufferLength)
{
    VLOG_INFO(__FUNCTION__ " - Buffer: %p, Length: %u", pvBuffer, cbBufferLength);
    return false;
}

bool CSteamMusicRemote::CurrentEntryDidChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Queue
bool CSteamMusicRemote::QueueWillChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::ResetQueueEntries()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::SetQueueEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_INFO(__FUNCTION__ " - ID: %d, Position: %d, Text: %s", nID, nPosition, pchEntryText);
    return false;
}

bool CSteamMusicRemote::SetCurrentQueueEntry(int nID)
{
    VLOG_INFO(__FUNCTION__ " - ID: %d", nID);
    return false;
}

bool CSteamMusicRemote::QueueDidChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Playlist
bool CSteamMusicRemote::PlaylistWillChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::ResetPlaylistEntries()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamMusicRemote::SetPlaylistEntry(int nID, int nPosition, const char *pchEntryText)
{
    VLOG_INFO(__FUNCTION__ " - ID: %d, Position: %d, Text: %s", nID, nPosition, pchEntryText);
    return false;
}

bool CSteamMusicRemote::SetCurrentPlaylistEntry(int nID)
{
    VLOG_INFO(__FUNCTION__ " - ID: %d", nID);
    return false;
}

bool CSteamMusicRemote::PlaylistDidChange()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}
