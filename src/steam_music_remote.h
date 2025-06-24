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

#include <isteamclient.h>
#include <isteammusicremote.h>

class Steam_Music_Remote :
    public ISteamMusicRemote
{
private:
    // Singleton instance
    static Steam_Music_Remote* s_pInstance;

public:
    Steam_Music_Remote();
    ~Steam_Music_Remote();

    // Helper methods
    static Steam_Music_Remote* GetInstance();
    static void ReleaseInstance();

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
};

#endif // VAPORCORE_STEAM_MUSIC_REMOTE_H
