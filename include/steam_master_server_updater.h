/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_MASTER_SERVER_UPDATER_H
#define VAPORCORE_STEAM_MASTER_SERVER_UPDATER_H
#ifdef _WIN32
#pragma once
#endif

#include <isteammasterserverupdater.h>

//-----------------------------------------------------------------------------
// Purpose: Game engines use this to tell the Steam master servers
// about their games so their games can show up in the server browser.
//-----------------------------------------------------------------------------
class CSteamMasterServerUpdater : public ISteamMasterServerUpdater
{
public:
	// Singleton accessor
    static CSteamMasterServerUpdater& GetInstance()
    {
		static CSteamMasterServerUpdater instance;
		return instance;
    }

public:
	// Call this as often as you like to tell the master server updater whether or not
	// you want it to be active (default: off).
	void SetActive( bool bActive ) override;

	// You usually don't need to modify this.
	// Pass -1 to use the default value for iHeartbeatInterval.
	// Some mods change this.
	void SetHeartbeatInterval( int iHeartbeatInterval ) override;

	// These are used when you've elected to multiplex the game server's UDP socket
	// rather than having the master server updater use its own sockets.
	// 
	// Source games use this to simplify the job of the server admins, so they 
	// don't have to open up more ports on their firewalls.
	
	// Call this when a packet that starts with 0xFFFFFFFF comes in. That means
	// it's for us.
	bool HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort ) override;

	// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
	// This gets a packet that the master server updater needs to send out on UDP.
	// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
	// Call this each frame until it returns 0.
	int GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort ) override;

	// Call this to set basic data that is passed to the server browser.
	void SetBasicServerData(
		unsigned short nProtocolVersion,
		bool bDedicatedServer,
		const char *pRegionName,
		const char *pProductName,
		unsigned short nMaxReportedClients,
		bool bPasswordProtected,
		const char *pGameDescription ) override;

	// Call this to clear the whole list of key/values that are sent in rules queries.
	void ClearAllKeyValues() override;
	
	// Call this to add/update a key/value pair.
	void SetKeyValue( const char *pKey, const char *pValue ) override;

	// You can call this upon shutdown to clear out data stored for this game server and
	// to tell the master servers that this server is going away.
	void NotifyShutdown() override;

	// Returns true if the master server has requested a restart.
	// Only returns true once per request.
	bool WasRestartRequested() override;

	// Force it to request a heartbeat from the master servers.
	void ForceHeartbeat() override;
	
	// Manually edit and query the master server list.
	// It will provide name resolution and use the default master server port if none is provided.
	bool AddMasterServer( const char *pServerAddress ) override;
	bool RemoveMasterServer( const char *pServerAddress ) override;

	int GetNumMasterServers() override;
	
	// Returns the # of bytes written to pOut.
	int GetMasterServerAddress( int iServer, char *pOut, int outBufferSize ) override;

private:
    // Private constructor and destructor for singleton
    CSteamMasterServerUpdater();
    ~CSteamMasterServerUpdater();

    // Delete copy constructor and assignment operator
    CSteamMasterServerUpdater(const CSteamMasterServerUpdater&) = delete;
    CSteamMasterServerUpdater& operator=(const CSteamMasterServerUpdater&) = delete;
};

#endif // VAPORCORE_STEAM_MASTER_SERVER_UPDATER_H
