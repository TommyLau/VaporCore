/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_MUSIC_H
#define VAPORCORE_STEAM_MUSIC_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteammusic.h>

//-----------------------------------------------------------------------------
// Purpose: Functions to control music playback in the steam client
//-----------------------------------------------------------------------------
class Steam_Music :
	public ISteamMusic
{
private:
    // Singleton instance
    static Steam_Music* s_pInstance;

public:
    Steam_Music();
    ~Steam_Music();

    // Helper methods
    static Steam_Music* GetInstance();
    static void ReleaseInstance();

	bool BIsEnabled() override;
	bool BIsPlaying() override;
	
	AudioPlayback_Status GetPlaybackStatus() override;

	void Play() override;
	void Pause() override;
	void PlayPrevious() override;
	void PlayNext() override;

	// volume is between 0.0 and 1.0
	void SetVolume( float flVolume ) override;
	float GetVolume() override;
};

#endif // VAPORCORE_STEAM_MUSIC_H
