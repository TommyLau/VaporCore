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
#include "steam_master_server_updater.h"

CSteamMasterServerUpdater::CSteamMasterServerUpdater()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMasterServerUpdater::~CSteamMasterServerUpdater()
{
    VLOG_INFO(__FUNCTION__);
}

// Call this as often as you like to tell the master server updater whether or not
// you want it to be active (default: off).
void CSteamMasterServerUpdater::SetActive( bool bActive )
{
    VLOG_INFO(__FUNCTION__ " - Active: %s", bActive ? "true" : "false");
}

// You usually don't need to modify this.
// Pass -1 to use the default value for iHeartbeatInterval.
// Some mods change this.
void CSteamMasterServerUpdater::SetHeartbeatInterval( int iHeartbeatInterval )
{
    VLOG_INFO(__FUNCTION__ " - Interval: %d", iHeartbeatInterval);
}

// These are used when you've elected to multiplex the game server's UDP socket
// rather than having the master server updater use its own sockets.
// 
// Source games use this to simplify the job of the server admins, so they 
// don't have to open up more ports on their firewalls.

// Call this when a packet that starts with 0xFFFFFFFF comes in. That means
// it's for us.
bool CSteamMasterServerUpdater::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
{
    VLOG_INFO(__FUNCTION__ " - DataSize: %d, SrcIP: %u, SrcPort: %u", cbData, srcIP, srcPort);
    return false;
}

// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
// This gets a packet that the master server updater needs to send out on UDP.
// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
// Call this each frame until it returns 0.
int CSteamMasterServerUpdater::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
{
    VLOG_INFO(__FUNCTION__ " - MaxOut: %d", cbMaxOut);
    return 0;
}

// Call this to set basic data that is passed to the server browser.
void CSteamMasterServerUpdater::SetBasicServerData(
	unsigned short nProtocolVersion,
	bool bDedicatedServer,
	const char *pRegionName,
	const char *pProductName,
	unsigned short nMaxReportedClients,
	bool bPasswordProtected,
	const char *pGameDescription )
{
    VLOG_INFO(__FUNCTION__ " - Protocol: %u, Dedicated: %s, Region: %s, Product: %s, MaxClients: %u, Password: %s, Description: %s",
               nProtocolVersion,
               bDedicatedServer ? "true" : "false",
               pRegionName ? pRegionName : "null",
               pProductName ? pProductName : "null",
               nMaxReportedClients,
               bPasswordProtected ? "true" : "false",
               pGameDescription ? pGameDescription : "null");
}

// Call this to clear the whole list of key/values that are sent in rules queries.
void CSteamMasterServerUpdater::ClearAllKeyValues()
{
    VLOG_INFO(__FUNCTION__);
}

// Call this to add/update a key/value pair.
void CSteamMasterServerUpdater::SetKeyValue( const char *pKey, const char *pValue )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %s", pKey ? pKey : "null", pValue ? pValue : "null");
}

// You can call this upon shutdown to clear out data stored for this game server and
// to tell the master servers that this server is going away.
void CSteamMasterServerUpdater::NotifyShutdown()
{
    VLOG_INFO(__FUNCTION__);
}

// Returns true if the master server has requested a restart.
// Only returns true once per request.
bool CSteamMasterServerUpdater::WasRestartRequested()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Force it to request a heartbeat from the master servers.
void CSteamMasterServerUpdater::ForceHeartbeat()
{
    VLOG_INFO(__FUNCTION__);
}

// Manually edit and query the master server list.
// It will provide name resolution and use the default master server port if none is provided.
bool CSteamMasterServerUpdater::AddMasterServer( const char *pServerAddress )
{
    VLOG_INFO(__FUNCTION__ " - Address: %s", pServerAddress ? pServerAddress : "null");
    return true;
}

bool CSteamMasterServerUpdater::RemoveMasterServer( const char *pServerAddress )
{
    VLOG_INFO(__FUNCTION__ " - Address: %s", pServerAddress ? pServerAddress : "null");
    return true;
}

int CSteamMasterServerUpdater::GetNumMasterServers()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Returns the # of bytes written to pOut.
int CSteamMasterServerUpdater::GetMasterServerAddress( int iServer, char *pOut, int outBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - Server: %d, BufferSize: %d", iServer, outBufferSize);
    if (pOut && outBufferSize > 0)
    {
        pOut[0] = '\0';
    }
    return 0;
}
