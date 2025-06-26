/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_GAME_SERVER_H
#define VAPORCORE_STEAM_GAME_SERVER_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamgameserver.h>
#include <isteamgameserver004.h>
#include <isteamgameserver005.h>
#include <isteamgameserver008.h>
#include <isteamgameserver009.h>
#include <isteamgameserver010.h>
#include <isteamgameserver011.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for authenticating users via Steam to play on a game server
//-----------------------------------------------------------------------------
class CSteamGameServer :
    public ISteamGameServer,
	public ISteamGameServer004,
	public ISteamGameServer005,
	public ISteamGameServer008,
	public ISteamGameServer009,
	public ISteamGameServer010,
	public ISteamGameServer011
{
private:
    // Singleton instance
    static CSteamGameServer* s_pInstance;

public:
    CSteamGameServer();
    ~CSteamGameServer();

    // Helper methods
    static CSteamGameServer* GetInstance();
    static void ReleaseInstance();

//
// Basic server data.  These properties, if set, must be set before before calling LogOn.  They
// may not be changed after logged in.
//

	/// This is called by SteamGameServer_Init, and you will usually not need to call it directly
	bool InitGameServer( uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString ) override;

	/// Game product identifier.  This is currently used by the master server for version checking purposes.
	/// It's a required field, but will eventually will go away, and the AppID will be used for this purpose.
	void SetProduct( const char *pszProduct ) override;

	/// Description of the game.  This is a required field and is displayed in the steam server browser....for now.
	/// This is a required field, but it will go away eventually, as the data should be determined from the AppID.
	void SetGameDescription( const char *pszGameDescription ) override;

	/// If your game is a "mod," pass the string that identifies it.  The default is an empty string, meaning
	/// this application is the original game, not a mod.
	///
	/// @see k_cbMaxGameServerGameDir
	void SetModDir( const char *pszModDir ) override;

	/// Is this is a dedicated server?  The default value is false.
	void SetDedicatedServer( bool bDedicated ) override;

//
// Login
//

	/// Begin process to login to a persistent game server account
	///
	/// You need to register for callbacks to determine the result of this operation.
	/// @see SteamServersConnected_t
	/// @see SteamServerConnectFailure_t
	/// @see SteamServersDisconnected_t
	void LogOn( const char *pszToken ) override;
	// Changed from Steam SDK v1.29a, backward compatibility
	void LogOn(
		const char *pszAccountName,
		const char *pszPassword
	) override;
	// Changed from Steam SDK v1.17, backward compatibility
	void LogOn() override;

	/// Login to a generic, anonymous account.
	///
	/// Note: in previous versions of the SDK, this was automatically called within SteamGameServer_Init,
	/// but this is no longer the case.
	void LogOnAnonymous() override;

	/// Begin process of logging game server out of steam
	void LogOff() override;

	// status functions
	bool BLoggedOn() override;
	bool BSecure() override; 
	CSteamID GetSteamID() override;

	/// Returns true if the master server has requested a restart.
	/// Only returns true once per request.
	bool WasRestartRequested() override;

//
// Server state.  These properties may be changed at any time.
//

	/// Max player count that will be reported to server browser and client queries
	void SetMaxPlayerCount( int cPlayersMax ) override;

	/// Number of bots.  Default value is zero
	void SetBotPlayerCount( int cBotplayers ) override;

	/// Set the name of server as it will appear in the server browser
	///
	/// @see k_cbMaxGameServerName
	void SetServerName( const char *pszServerName ) override;

	/// Set name of map to report in the server browser
	///
	/// @see k_cbMaxGameServerName
	void SetMapName( const char *pszMapName ) override;

	/// Let people know if your server will require a password
	void SetPasswordProtected( bool bPasswordProtected ) override;

	/// Spectator server.  The default value is zero, meaning the service
	/// is not used.
	void SetSpectatorPort( uint16 unSpectatorPort ) override;

	/// Name of the spectator server.  (Only used if spectator port is nonzero.)
	///
	/// @see k_cbMaxGameServerMapName
	void SetSpectatorServerName( const char *pszSpectatorServerName ) override;

	/// Call this to clear the whole list of key/values that are sent in rules queries.
	void ClearAllKeyValues() override;
	
	/// Call this to add/update a key/value pair.
	void SetKeyValue( const char *pKey, const char *pValue ) override;

	/// Sets a string defining the "gametags" for this server, this is optional, but if it is set
	/// it allows users to filter in the matchmaking/server-browser interfaces based on the value
	///
	/// @see k_cbMaxGameServerTags
	void SetGameTags( const char *pchGameTags ) override; 
	// Sets a string defining the "gametype" for this server, this is optional, but if it is set
	// it allows users to filter in the matchmaking/server-browser interfaces based on the value
	// Changed from Steam SDK v1.09 to SetGameTags, backward compatibility
	void SetGameType( const char *pchGameType ) override; 

	/// Sets a string defining the "gamedata" for this server, this is optional, but if it is set
	/// it allows users to filter in the matchmaking/server-browser interfaces based on the value
	/// don't set this unless it actually changes, its only uploaded to the master once (when
	/// acknowledged)
	///
	/// @see k_cbMaxGameServerGameData
	void SetGameData( const char *pchGameData) override; 

	/// Region identifier.  This is an optional field, the default value is empty, meaning the "world" region
	void SetRegion( const char *pszRegion ) override;

//
// Player list management / authentication
//

	// Handles receiving a new connection from a Steam user.  This call will ask the Steam
	// servers to validate the users identity, app ownership, and VAC status.  If the Steam servers 
	// are off-line, then it will validate the cached ticket itself which will validate app ownership 
	// and identity.  The AuthBlob here should be acquired on the game client using SteamUser()->InitiateGameConnection()
	// and must then be sent up to the game server for authentication.
	//
	// Return Value: returns true if the users ticket passes basic checks. pSteamIDUser will contain the Steam ID of this user. pSteamIDUser must NOT be NULL
	// If the call succeeds then you should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
	// for the user has succeeded or failed (the steamid in the callback will match the one returned by this call)
	bool SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser ) override;

	// Return Value: true/false depending on whether the call succeeds.  If the call succeeds then you
	// should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
	// for the user has succeeded or failed.
	// Removed from Steam SDK v1.01, backward compatibility
	void SendUserConnectAndAuthenticate( CSteamID steamIDUser, uint32 unIPClient, void *pvAuthBlob, uint32 cubAuthBlobSize ) override;

	// Creates a fake user (ie, a bot) which will be listed as playing on the server, but skips validation.  
	// 
	// Return Value: Returns a SteamID for the user to be tracked with, you should call HandleUserDisconnect()
	// when this user leaves the server just like you would for a real user.
	CSteamID CreateUnauthenticatedUserConnection() override;

	// Should be called whenever a user leaves our game server, this lets Steam internally
	// track which users are currently on which servers for the purposes of preventing a single
	// account being logged into multiple servers, showing who is currently on a server, etc.
	void SendUserDisconnect( CSteamID steamIDUser ) override;

	// Update the data to be displayed in the server browser and matchmaking interfaces for a user
	// currently connected to the server.  For regular users you must call this after you receive a
	// GSUserValidationSuccess callback.
	// 
	// Return Value: true if successful, false if failure (ie, steamIDUser wasn't for an active player)
	bool BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore ) override;

	// You shouldn't need to call this as it is called internally by SteamGameServer_Init() and can only be called once.
	//
	// To update the data in this call which may change during the servers lifetime see UpdateServerStatus() below.
	//
	// Input:	nGameAppID - The Steam assigned AppID for the game
	//			unServerFlags - Any applicable combination of flags (see k_unServerFlag____ constants below)
	//			unGameIP - The IP Address the server is listening for client connections on (might be INADDR_ANY)
	//			unGamePort - The port which the server is listening for client connections on
	//			unSpectatorPort - the port on which spectators can join to observe the server, 0 if spectating is not supported
	//			usQueryPort - The port which the ISteamMasterServerUpdater API should use in order to listen for matchmaking requests
	//			pchGameDir - A unique string identifier for your game
	//			pchVersion - The current version of the server as a string like 1.0.0.0
	//			bLanMode - Is this a LAN only server?
	//			
	// bugbug jmccaskey - figure out how to remove this from the API and only expose via SteamGameServer_Init... or make this actually used,
	// and stop calling it in SteamGameServer_Init()?
	// Removed from Steam SDK v1.17, backward compatibility
	bool BSetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
								uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode ) override;
	// Removed from Steam SDK v1.01, backward compatibility
	bool BSetServerType( int32 nGameAppId, uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
							uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode ) override;

	// Updates server status values which shows up in the server browser and matchmaking APIs
	// Removed from Steam SDK v1.17, backward compatibility
	void UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, 
							 const char *pchServerName, const char *pSpectatorServerName, 
							 const char *pchMapName ) override;

	// This can be called if spectator goes away or comes back (passing 0 means there is no spectator server now).
	// Removed from Steam SDK v1.17, backward compatibility
	void UpdateSpectatorPort( uint16 unSpectatorPort ) override;

	// Ask if a user has a specific achievement for this game, will get a callback on reply
	// Removed from Steam SDK v1.08, backward compatibility
	bool BGetUserAchievementStatus( CSteamID steamID, const char *pchAchievementName ) override;

	// New auth system APIs - do not mix with the old auth system APIs.
	// ----------------------------------------------------------------

	// Retrieve ticket to be sent to the entity who wishes to authenticate you ( using BeginAuthSession API ). 
	// pcbTicket retrieves the length of the actual ticket.
	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ) override;

	// Authenticate ticket ( from GetAuthSessionTicket ) from entity steamID to be sure it is valid and isnt reused
	// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID ) override;

	// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
	void EndAuthSession( CSteamID steamID ) override;

	// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
	void CancelAuthTicket( HAuthTicket hAuthTicket ) override;

	// After receiving a user's authentication data, and passing it to SendUserConnectAndAuthenticate, use this function
	// to determine if the user owns downloadable content specified by the provided AppID.
	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID ) override;

	// Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
	// returns false if we're not connected to the steam servers and thus cannot ask
	bool RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup ) override;


	// these two functions s are deprecated, and will not return results
	// they will be removed in a future version of the SDK
	void GetGameplayStats( ) override;
	CALL_RESULT( GSReputation_t )
	SteamAPICall_t GetServerReputation() override;

	// Returns the public IP of the server according to Steam, useful when the server is 
	// behind NAT and you want to advertise its IP in a lobby for other clients to directly
	// connect to
	uint32 GetPublicIP() override;

// These are in GameSocketShare mode, where instead of ISteamGameServer creating its own
// socket to talk to the master server on, it lets the game use its socket to forward messages
// back and forth. This prevents us from requiring server ops to open up yet another port
// in their firewalls.
//
// the IP address and port should be in host order, i.e 127.0.0.1 == 0x7f000001
	
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

//
// Control heartbeats / advertisement with master server
//

	// Call this as often as you like to tell the master server updater whether or not
	// you want it to be active (default: off).
	void EnableHeartbeats( bool bActive ) override;

	// You usually don't need to modify this.
	// Pass -1 to use the default value for iHeartbeatInterval.
	// Some mods change this.
	void SetHeartbeatInterval( int iHeartbeatInterval ) override;

	// Force a heartbeat to steam at the next opportunity
	void ForceHeartbeat() override;

	// associate this game server with this clan for the purposes of computing player compat
	CALL_RESULT( AssociateWithClanResult_t )
	SteamAPICall_t AssociateWithClan( CSteamID steamIDClan ) override;
	
	// ask if any of the current players dont want to play with this new player - or vice versa
	CALL_RESULT( ComputeNewPlayerCompatibilityResult_t )
	SteamAPICall_t ComputeNewPlayerCompatibility( CSteamID steamIDNewPlayer ) override;
};

#endif // VAPORCORE_STEAM_GAME_SERVER_H

