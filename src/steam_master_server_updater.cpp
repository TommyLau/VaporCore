/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_master_server_updater.h"
#include "logger.h"

// Static instance
Steam_Master_Server_Updater* Steam_Master_Server_Updater::s_pInstance = nullptr;

Steam_Master_Server_Updater::Steam_Master_Server_Updater()
{
    VLOG_INFO("Steam_Master_Server_Updater constructor called");
}

Steam_Master_Server_Updater::~Steam_Master_Server_Updater()
{
    VLOG_INFO("Steam_Master_Server_Updater destructor called");
}

// Call this as often as you like to tell the master server updater whether or not
// you want it to be active (default: off).
void Steam_Master_Server_Updater::SetActive( bool bActive )
{
    VLOG_DEBUG("SetActive called - Active: %s", bActive ? "true" : "false");
}

// You usually don't need to modify this.
// Pass -1 to use the default value for iHeartbeatInterval.
// Some mods change this.
void Steam_Master_Server_Updater::SetHeartbeatInterval( int iHeartbeatInterval )
{
    VLOG_DEBUG("SetHeartbeatInterval called - Interval: %d", iHeartbeatInterval);
}

// Call this when a packet that starts with 0xFFFFFFFF comes in. That means
// it's for us.
bool Steam_Master_Server_Updater::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
{
    VLOG_DEBUG("HandleIncomingPacket called - DataSize: %d, SrcIP: %u, SrcPort: %u", cbData, srcIP, srcPort);
    return false;
}

// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
// This gets a packet that the master server updater needs to send out on UDP.
// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
// Call this each frame until it returns 0.
int Steam_Master_Server_Updater::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
{
    VLOG_DEBUG("GetNextOutgoingPacket called - MaxOut: %d", cbMaxOut);
    return 0;
}

// Call this to set basic data that is passed to the server browser.
void Steam_Master_Server_Updater::SetBasicServerData(
	unsigned short nProtocolVersion,
	bool bDedicatedServer,
	const char *pRegionName,
	const char *pProductName,
	unsigned short nMaxReportedClients,
	bool bPasswordProtected,
	const char *pGameDescription )
{
    VLOG_DEBUG("SetBasicServerData called - Protocol: %u, Dedicated: %s, Region: %s, Product: %s, MaxClients: %u, Password: %s, Description: %s",
               nProtocolVersion,
               bDedicatedServer ? "true" : "false",
               pRegionName ? pRegionName : "null",
               pProductName ? pProductName : "null",
               nMaxReportedClients,
               bPasswordProtected ? "true" : "false",
               pGameDescription ? pGameDescription : "null");
}

// Call this to clear the whole list of key/values that are sent in rules queries.
void Steam_Master_Server_Updater::ClearAllKeyValues()
{
    VLOG_DEBUG("ClearAllKeyValues called");
}

// Call this to add/update a key/value pair.
void Steam_Master_Server_Updater::SetKeyValue( const char *pKey, const char *pValue )
{
    VLOG_DEBUG("SetKeyValue called - Key: %s, Value: %s", pKey ? pKey : "null", pValue ? pValue : "null");
}

// You can call this upon shutdown to clear out data stored for this game server and
// to tell the master servers that this server is going away.
void Steam_Master_Server_Updater::NotifyShutdown()
{
    VLOG_DEBUG("NotifyShutdown called");
}

// Returns true if the master server has requested a restart.
// Only returns true once per request.
bool Steam_Master_Server_Updater::WasRestartRequested()
{
    VLOG_DEBUG("WasRestartRequested called");
    return false;
}

// Force it to request a heartbeat from the master servers.
void Steam_Master_Server_Updater::ForceHeartbeat()
{
    VLOG_DEBUG("ForceHeartbeat called");
}

// Manually edit and query the master server list.
// It will provide name resolution and use the default master server port if none is provided.
bool Steam_Master_Server_Updater::AddMasterServer( const char *pServerAddress )
{
    VLOG_DEBUG("AddMasterServer called - Address: %s", pServerAddress ? pServerAddress : "null");
    return true;
}

bool Steam_Master_Server_Updater::RemoveMasterServer( const char *pServerAddress )
{
    VLOG_DEBUG("RemoveMasterServer called - Address: %s", pServerAddress ? pServerAddress : "null");
    return true;
}

int Steam_Master_Server_Updater::GetNumMasterServers()
{
    VLOG_DEBUG("GetNumMasterServers called");
    return 0;
}

// Returns the # of bytes written to pOut.
int Steam_Master_Server_Updater::GetMasterServerAddress( int iServer, char *pOut, int outBufferSize )
{
    VLOG_DEBUG("GetMasterServerAddress called - Server: %d, BufferSize: %d", iServer, outBufferSize);
    if (pOut && outBufferSize > 0)
    {
        pOut[0] = '\0';
    }
    return 0;
}

// Helper methods
Steam_Master_Server_Updater* Steam_Master_Server_Updater::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Master_Server_Updater();
    }
    return s_pInstance;
}

void Steam_Master_Server_Updater::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

