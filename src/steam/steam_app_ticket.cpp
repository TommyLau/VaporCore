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
#include "steam_app_ticket.h"

CSteamAppTicket::CSteamAppTicket()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamAppTicket::~CSteamAppTicket()
{
    VLOG_INFO(__FUNCTION__);
}

uint32 CSteamAppTicket::GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32 *piAppId, uint32 *piSteamId, uint32 *piSignature, uint32 *pcbSignature )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d, BufferSize: %d, piAppId: %p, piSteamId: %p, piSignature: %p, pcbSignature: %p",
              nAppID, cbBufferLength, piAppId, piSteamId, piSignature, pcbSignature);
    return 0;
}
