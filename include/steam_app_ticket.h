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

#include <isteamclient.h>
#include <isteamappticket.h>

//-----------------------------------------------------------------------------
// Purpose: hand out a reasonable "future proof" view of an app ownership ticket
// the raw (signed) buffer, and indices into that buffer where the appid and 
// steamid are located.  the sizes of the appid and steamid are implicit in 
// (each version of) the interface - currently uin32 appid and uint64 steamid
//-----------------------------------------------------------------------------
class CSteamAppTicket :
    public ISteamAppTicket
{
public:
	// Singleton accessor
    static CSteamAppTicket& GetInstance()
    {
		static CSteamAppTicket instance;
		return instance;
    }

public:
    uint32 GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32 *piAppId, uint32 *piSteamId, uint32 *piSignature, uint32 *pcbSignature ) override;

private:
    // Private constructor and destructor for singleton
    CSteamAppTicket();
    ~CSteamAppTicket();

    // Delete copy constructor and assignment operator
    CSteamAppTicket(const CSteamAppTicket&) = delete;
    CSteamAppTicket& operator=(const CSteamAppTicket&) = delete;
};

#endif // VAPORCORE_STEAM_APP_TICKET_H
