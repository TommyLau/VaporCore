/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_app_ticket.h"
#include "logger.h"

// Static instance
Steam_App_Ticket* Steam_App_Ticket::s_pInstance = nullptr;

Steam_App_Ticket::Steam_App_Ticket()
{
    VLOG_INFO("Steam_App_Ticket constructor called");
}

Steam_App_Ticket::~Steam_App_Ticket()
{
    VLOG_INFO("Steam_App_Ticket destructor called");
}

uint32 Steam_App_Ticket::GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32 *piAppId, uint32 *piSteamId, uint32 *piSignature, uint32 *pcbSignature )
{
    VLOG_DEBUG("GetAppOwnershipTicketData called - AppID: %d, BufferSize: %d", nAppID, cbBufferLength);
    return 0;
}

// Helper methods
Steam_App_Ticket* Steam_App_Ticket::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_App_Ticket();
    }
    return s_pInstance;
}

void Steam_App_Ticket::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
