/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_user.h"
#include "logger.h"

// Static instance
Steam_User* Steam_User::s_pInstance = nullptr;

Steam_User::Steam_User()
{
    VLOG_INFO("Steam_User constructor called");
}

Steam_User::~Steam_User()
{
    VLOG_INFO("Steam_User destructor called");
}

// returns the HSteamUser this interface represents
// this is only used internally by the API, and by a few select interfaces that support multi-user
HSteamUser Steam_User::GetHSteamUser()
{
    VLOG_DEBUG("GetHSteamUser called");
    return 1;
}

// returns true if the Steam client current has a live connection to the Steam servers. 
// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
// The Steam client will automatically be trying to recreate the connection as often as possible.
bool Steam_User::BLoggedOn()
{
    VLOG_DEBUG("BLoggedOn called");
    return true;
}

// returns the CSteamID of the account currently logged into the Steam client
// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
CSteamID Steam_User::GetSteamID()
{
    VLOG_DEBUG("GetSteamID called");
    return CSteamID();
}

// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
//
// Parameters:
// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
// CGameID gameID - the ID of the current game. For games without mods, this is just CGameID( <appID> )
// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
//
// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
int Steam_User::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_DEBUG("InitiateGameConnection called - GameServer: %llu, GameID: %llu, Server: %u:%u, Secure: %s", 
               steamIDGameServer.ConvertToUint64(), gameID.ToUint64(), unIPServer, usPortServer, bSecure ? "true" : "false");
    
    if (!pAuthBlob || cbMaxAuthBlob < 64)
    {
        return 0;
    }
    
    // Fill with dummy auth token
    memset(pAuthBlob, 0, cbMaxAuthBlob);
    return 64;
}

// notify of disconnect
// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
void Steam_User::TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
{
    VLOG_DEBUG("TerminateGameConnection called - Server: %u:%u", unIPServer, usPortServer);
}

// used by only a few games to track usage events
void Steam_User::TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo )
{
    VLOG_DEBUG("TrackAppUsageEvent called - GameID: %llu, Event: %d, ExtraInfo: %s", 
               gameID.ToUint64(), eAppUsageEvent, pchExtraInfo ? pchExtraInfo : "null");
}

// legacy authentication support - need to be called if the game server rejects the user with a 'bad ticket' error
// this is only needed under very specific circumstances
void Steam_User::RefreshSteam2Login()
{
    VLOG_DEBUG("RefreshSteam2Login called");
}

// Helper methods
Steam_User* Steam_User::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_User();
    }
    return s_pInstance;
}

void Steam_User::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

