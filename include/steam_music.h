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
class CSteamMusic :
	public ISteamMusic
{
public:
	// Singleton accessor
    static CSteamMusic& GetInstance()
    {
		static CSteamMusic instance;
		return instance;
    }

public:
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

private:
    // Private constructor and destructor for singleton
    CSteamMusic();
    ~CSteamMusic();

    // Delete copy constructor and assignment operator
    CSteamMusic(const CSteamMusic&) = delete;
    CSteamMusic& operator=(const CSteamMusic&) = delete;
};

#endif // VAPORCORE_STEAM_MUSIC_H
