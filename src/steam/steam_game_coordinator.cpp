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
#include "steam_game_coordinator.h"

CSteamGameCoordinator::CSteamGameCoordinator()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameCoordinator::~CSteamGameCoordinator()
{
    VLOG_INFO(__FUNCTION__);
}

// sends a message to the Game Coordinator
EGCResults CSteamGameCoordinator::SendMessage( uint32 unMsgType, const void *pubData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__ " - MsgType: %d, DataSize: %d", unMsgType, cubData);
    return EGCResults::k_EGCResultOK;
}

// returns true if there is a message waiting from the game coordinator
bool CSteamGameCoordinator::IsMessageAvailable( uint32 *pcubMsgSize )
{
    VLOG_INFO(__FUNCTION__ " - MsgSize: %d", *pcubMsgSize);
    return false;
}

// fills the provided buffer with the first message in the queue and returns k_EGCResultOK or 
// returns k_EGCResultNoMessage if there is no message waiting. pcubMsgSize is filled with the message size.
// If the provided buffer is not large enough to fit the entire message, k_EGCResultBufferTooSmall is returned
// and the message remains at the head of the queue.
EGCResults CSteamGameCoordinator::RetrieveMessage( uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
{
    VLOG_INFO(__FUNCTION__ " - MsgType: %d, DataSize: %d", *punMsgType, *pcubMsgSize);
    return EGCResults::k_EGCResultOK;
}
