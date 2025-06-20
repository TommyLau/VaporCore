/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_APP_TICKET_H
#define VAPORCORE_STEAM_APP_TICKET_H
#ifdef _WIN32
#pragma once
#endif

#include <steamtypes.h>
#include <isteamappticket.h>

//-----------------------------------------------------------------------------
// Purpose: hand out a reasonable "future proof" view of an app ownership ticket
// the raw (signed) buffer, and indices into that buffer where the appid and 
// steamid are located.  the sizes of the appid and steamid are implicit in 
// (each version of) the interface - currently uin32 appid and uint64 steamid
//-----------------------------------------------------------------------------
class Steam_App_Ticket :
    public ISteamAppTicket
{
public:
    Steam_App_Ticket();
    ~Steam_App_Ticket();

    uint32 GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32 *piAppId, uint32 *piSteamId, uint32 *piSignature, uint32 *pcbSignature ) override;

    // Helper methods
    static Steam_App_Ticket* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_App_Ticket* s_pInstance;
};

#endif // VAPORCORE_STEAM_APP_TICKET_H
