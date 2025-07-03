/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_GAME_COORDINATOR_H
#define VAPORCORE_STEAM_GAME_COORDINATOR_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamgamecoordinator.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for sending and receiving messages from the Game Coordinator
//			for this application
//-----------------------------------------------------------------------------
class CSteamGameCoordinator :
    public ISteamGameCoordinator
{
public:
    // Singleton accessor
    static CSteamGameCoordinator& GetInstance()
    {
		static CSteamGameCoordinator instance;
		return instance;
    }

public:
    // sends a message to the Game Coordinator
    EGCResults SendMessage( uint32 unMsgType, const void *pubData, uint32 cubData ) override;

    // returns true if there is a message waiting from the game coordinator
    bool IsMessageAvailable( uint32 *pcubMsgSize ) override; 

	// fills the provided buffer with the first message in the queue and returns k_EGCResultOK or 
	// returns k_EGCResultNoMessage if there is no message waiting. pcubMsgSize is filled with the message size.
	// If the provided buffer is not large enough to fit the entire message, k_EGCResultBufferTooSmall is returned
	// and the message remains at the head of the queue.
    EGCResults RetrieveMessage( uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize ) override; 


private:
    // Private constructor and destructor for singleton
    CSteamGameCoordinator();
    ~CSteamGameCoordinator();

    // Delete copy constructor and assignment operator
    CSteamGameCoordinator(const CSteamGameCoordinator&) = delete;
    CSteamGameCoordinator& operator=(const CSteamGameCoordinator&) = delete;
};

#endif // VAPORCORE_STEAM_GAME_COORDINATOR_H
