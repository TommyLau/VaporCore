/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_MUSIC_REMOTE_H
#define VAPORCORE_STEAM_MUSIC_REMOTE_H
#ifdef _WIN32
#pragma once
#endif

#include <isteammusicremote.h>

class CSteamMusicRemote :
    public ISteamMusicRemote
{
public:
	// Singleton accessor
    static CSteamMusicRemote& GetInstance()
    {
		static CSteamMusicRemote instance;
		return instance;
    }

public:
	// Service Definition
    bool RegisterSteamMusicRemote(const char *pchName) override;
    bool DeregisterSteamMusicRemote() override;
    bool BIsCurrentMusicRemote() override;
    bool BActivationSuccess(bool bValue) override;

    bool SetDisplayName(const char *pchDisplayName) override;
    bool SetPNGIcon_64x64(void *pvBuffer, uint32 cbBufferLength) override;

	// Abilities for the user interface
    bool EnablePlayPrevious(bool bValue) override;
    bool EnablePlayNext(bool bValue) override;
    bool EnableShuffled(bool bValue) override;
    bool EnableLooped(bool bValue) override;
    bool EnableQueue(bool bValue) override;
    bool EnablePlaylists(bool bValue) override;

	// Status
    bool UpdatePlaybackStatus(AudioPlayback_Status nStatus) override;
    bool UpdateShuffled(bool bValue) override;
    bool UpdateLooped(bool bValue) override;
    bool UpdateVolume(float flValue) override; // volume is between 0.0 and 1.0

	// Current Entry
    bool CurrentEntryWillChange() override;
    bool CurrentEntryIsAvailable(bool bAvailable) override;
    bool UpdateCurrentEntryText(const char *pchText) override;
    bool UpdateCurrentEntryElapsedSeconds(int nValue) override;
    bool UpdateCurrentEntryCoverArt(void *pvBuffer, uint32 cbBufferLength) override;
    bool CurrentEntryDidChange() override;

	// Queue
    bool QueueWillChange() override;
    bool ResetQueueEntries() override;
    bool SetQueueEntry(int nID, int nPosition, const char *pchEntryText) override;
    bool SetCurrentQueueEntry(int nID) override;
    bool QueueDidChange() override;

	// Playlist
    bool PlaylistWillChange() override;
    bool ResetPlaylistEntries() override;
    bool SetPlaylistEntry(int nID, int nPosition, const char *pchEntryText) override;
    bool SetCurrentPlaylistEntry(int nID) override;
    bool PlaylistDidChange() override;

private:
    // Private constructor and destructor for singleton
    CSteamMusicRemote();
    ~CSteamMusicRemote();

    // Delete copy constructor and assignment operator
    CSteamMusicRemote(const CSteamMusicRemote&) = delete;
    CSteamMusicRemote& operator=(const CSteamMusicRemote&) = delete;
};

#endif // VAPORCORE_STEAM_MUSIC_REMOTE_H
