/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_game_coordinator.h"
#include "logger.h"

// Static instance
Steam_Game_Coordinator* Steam_Game_Coordinator::s_pInstance = nullptr;

Steam_Game_Coordinator::Steam_Game_Coordinator()
{
    VLOG_INFO("Steam_Game_Coordinator constructor called");
}

Steam_Game_Coordinator::~Steam_Game_Coordinator()
{
    VLOG_INFO("Steam_Game_Coordinator destructor called");
}

// sends a message to the Game Coordinator
EGCResults Steam_Game_Coordinator::SendMessage( uint32 unMsgType, const void *pubData, uint32 cubData )
{
    VLOG_DEBUG("SendMessage called - MsgType: %d, DataSize: %d", unMsgType, cubData);
    return EGCResults::k_EGCResultOK;
}

// returns true if there is a message waiting from the game coordinator
bool Steam_Game_Coordinator::IsMessageAvailable( uint32 *pcubMsgSize )
{
    VLOG_DEBUG("IsMessageAvailable called - MsgSize: %d", *pcubMsgSize);
    return false;
}

// fills the provided buffer with the first message in the queue and returns k_EGCResultOK or 
// returns k_EGCResultNoMessage if there is no message waiting. pcubMsgSize is filled with the message size.
// If the provided buffer is not large enough to fit the entire message, k_EGCResultBufferTooSmall is returned
// and the message remains at the head of the queue.
EGCResults Steam_Game_Coordinator::RetrieveMessage( uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
{
    VLOG_DEBUG("RetrieveMessage called - MsgType: %d, DataSize: %d", *punMsgType, *pcubMsgSize);
    return EGCResults::k_EGCResultOK;
}

// Helper methods
Steam_Game_Coordinator* Steam_Game_Coordinator::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Game_Coordinator();
    }
    return s_pInstance;
}

void Steam_Game_Coordinator::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
