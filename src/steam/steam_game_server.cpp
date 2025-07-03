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
#include "steam_game_server.h"

CSteamGameServer::CSteamGameServer()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameServer::~CSteamGameServer()
{
    VLOG_INFO(__FUNCTION__);
}

//
// Basic server data.  These properties, if set, must be set before before calling LogOn.  They
// may not be changed after logged in.
//

// This is called by SteamGameServer_Init, and you will usually not need to call it directly
bool CSteamGameServer::InitGameServer( uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, GamePort: %u, QueryPort: %u, Flags: %u, AppID: %u, Version: %s", unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString ? pchVersionString : "null");
    return true;
}

// Game product identifier.  This is currently used by the master server for version checking purposes.
// It's a required field, but will eventually will go away, and the AppID will be used for this purpose.
void CSteamGameServer::SetProduct( const char *pszProduct )
{
    VLOG_INFO(__FUNCTION__ " - Product: %s", pszProduct ? pszProduct : "null");
}

// Description of the game.  This is a required field and is displayed in the steam server browser....for now.
// This is a required field, but it will go away eventually, as the data should be determined from the AppID.
void CSteamGameServer::SetGameDescription( const char *pszGameDescription )
{
    VLOG_INFO(__FUNCTION__ " - Description: %s", pszGameDescription ? pszGameDescription : "null");
}

// If your game is a "mod," pass the string that identifies it.  The default is an empty string, meaning
// this application is the original game, not a mod.
//
// @see k_cbMaxGameServerGameDir
void CSteamGameServer::SetModDir( const char *pszModDir )
{
    VLOG_INFO(__FUNCTION__ " - ModDir: %s", pszModDir ? pszModDir : "null");
}

// Is this is a dedicated server?  The default value is false.
void CSteamGameServer::SetDedicatedServer( bool bDedicated )
{
    VLOG_INFO(__FUNCTION__ " - Dedicated: %s", bDedicated ? "true" : "false");
}

//
// Login
//

// Begin process to login to a persistent game server account
//
// You need to register for callbacks to determine the result of this operation.
// @see SteamServersConnected_t
// @see SteamServerConnectFailure_t
// @see SteamServersDisconnected_t
void CSteamGameServer::LogOn( const char *pszToken )
{
    VLOG_INFO(__FUNCTION__ " - Token: %s", pszToken ? pszToken : "null");
}

// Changed from Steam SDK v1.29a, backward compatibility
void CSteamGameServer::LogOn( const char *pszAccountName, const char *pszPassword )
{
    VLOG_INFO(__FUNCTION__ " - Account: %s, Password: %s", pszAccountName ? pszAccountName : "null", pszPassword ? pszPassword : "null");
}

// Changed from Steam SDK v1.17, backward compatibility
void CSteamGameServer::LogOn()
{
    VLOG_INFO(__FUNCTION__);
}

// Login to a generic, anonymous account.
//
// Note: in previous versions of the SDK, this was automatically called within SteamGameServer_Init,
// but this is no longer the case.
void CSteamGameServer::LogOnAnonymous()
{
    VLOG_INFO(__FUNCTION__);
}

// Begin process of logging game server out of steam
void CSteamGameServer::LogOff()
{
    VLOG_INFO(__FUNCTION__);
}

// status functions
bool CSteamGameServer::BLoggedOn()
{
    VLOG_INFO(__FUNCTION__);

    // TODO: Add offline setting in config file, now always online
    return true;
}

bool CSteamGameServer::BSecure()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

CSteamID CSteamGameServer::GetSteamID()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamID();
}

// Returns true if the master server has requested a restart.
// Only returns true once per request.
bool CSteamGameServer::WasRestartRequested()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

//
// Server state.  These properties may be changed at any time.
//

// Max player count that will be reported to server browser and client queries
void CSteamGameServer::SetMaxPlayerCount( int cPlayersMax )
{
    VLOG_INFO(__FUNCTION__ " - PlayersMax: %d", cPlayersMax);
}

// Number of bots.  Default value is zero
void CSteamGameServer::SetBotPlayerCount( int cBotplayers )
{
    VLOG_INFO(__FUNCTION__ " - Bots: %d", cBotplayers);
}

// Set the name of server as it will appear in the server browser
//
// @see k_cbMaxGameServerName
void CSteamGameServer::SetServerName( const char *pszServerName )
{
    VLOG_INFO(__FUNCTION__ " - ServerName: %s", pszServerName ? pszServerName : "null");
}

// Set name of map to report in the server browser
//
// @see k_cbMaxGameServerName
void CSteamGameServer::SetMapName( const char *pszMapName )
{
    VLOG_INFO(__FUNCTION__ " - MapName: %s", pszMapName ? pszMapName : "null");
}

// Let people know if your server will require a password
void CSteamGameServer::SetPasswordProtected( bool bPasswordProtected )
{
    VLOG_INFO(__FUNCTION__ " - PasswordProtected: %s", bPasswordProtected ? "true" : "false");
}

// Spectator server.  The default value is zero, meaning the service
// is not used.
void CSteamGameServer::SetSpectatorPort( uint16 unSpectatorPort )
{
    VLOG_INFO(__FUNCTION__ " - SpectatorPort: %u", unSpectatorPort);
}

// Name of the spectator server.  (Only used if spectator port is nonzero.)
//
// @see k_cbMaxGameServerMapName
void CSteamGameServer::SetSpectatorServerName( const char *pszSpectatorServerName )
{
    VLOG_INFO(__FUNCTION__ " - SpectatorServerName: %s", pszSpectatorServerName ? pszSpectatorServerName : "null");
}

// Call this to clear the whole list of key/values that are sent in rules queries.
void CSteamGameServer::ClearAllKeyValues()
{
    VLOG_INFO(__FUNCTION__);
}
	
// Call this to add/update a key/value pair.
void CSteamGameServer::SetKeyValue( const char *pKey, const char *pValue )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %s", pKey ? pKey : "null", pValue ? pValue : "null");
}

// Sets a string defining the "gametags" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
//
// @see k_cbMaxGameServerTags
void CSteamGameServer::SetGameTags( const char *pchGameTags )
{
    VLOG_INFO(__FUNCTION__ " - GameTags: %s", pchGameTags ? pchGameTags : "null");
}

// Sets a string defining the "gametype" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
// Changed from Steam SDK v1.09 to SetGameTags, backward compatibility
void CSteamGameServer::SetGameType( const char *pchGameType )
{
    VLOG_INFO(__FUNCTION__ " - GameType: %s", pchGameType ? pchGameType : "null");
    // TODO: Call SetGameTags?
}

// Sets a string defining the "gamedata" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
// don't set this unless it actually changes, its only uploaded to the master once (when
// acknowledged)
//
// @see k_cbMaxGameServerGameData
void CSteamGameServer::SetGameData( const char *pchGameData)
{
    VLOG_INFO(__FUNCTION__ " - GameData: %s", pchGameData ? pchGameData : "null");
}

// Region identifier.  This is an optional field, the default value is empty, meaning the "world" region
void CSteamGameServer::SetRegion( const char *pszRegion )
{
    VLOG_INFO(__FUNCTION__ " - Region: %s", pszRegion ? pszRegion : "null");
}

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
bool CSteamGameServer::SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, BlobSize: %u", unIPClient, cubAuthBlobSize);
    return false;
}

// Return Value: true/false depending on whether the call succeeds.  If the call succeeds then you
// should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
// for the user has succeeded or failed.
// Removed from Steam SDK v1.01, backward compatibility
void CSteamGameServer::SendUserConnectAndAuthenticate( CSteamID steamIDUser, uint32 unIPClient, void *pvAuthBlob, uint32 cubAuthBlobSize )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu, IP: %u, BlobSize: %u", steamIDUser.ConvertToUint64(), unIPClient, cubAuthBlobSize);
}

// Creates a fake user (ie, a bot) which will be listed as playing on the server, but skips validation.  
// 
// Return Value: Returns a SteamID for the user to be tracked with, you should call HandleUserDisconnect()
// when this user leaves the server just like you would for a real user.
CSteamID CSteamGameServer::CreateUnauthenticatedUserConnection()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamID();
}

// Should be called whenever a user leaves our game server, this lets Steam internally
// track which users are currently on which servers for the purposes of preventing a single
// account being logged into multiple servers, showing who is currently on a server, etc.
void CSteamGameServer::SendUserDisconnect( CSteamID steamIDUser )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu", steamIDUser.ConvertToUint64());
}

// Update the data to be displayed in the server browser and matchmaking interfaces for a user
// currently connected to the server.  For regular users you must call this after you receive a
// GSUserValidationSuccess callback.
// 
// Return Value: true if successful, false if failure (ie, steamIDUser wasn't for an active player)
bool CSteamGameServer::BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu, Name: %s, Score: %u", steamIDUser.ConvertToUint64(), pchPlayerName ? pchPlayerName : "null", uScore);
    return true;
}

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
bool CSteamGameServer::BSetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
								uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
{
    VLOG_INFO(__FUNCTION__ " - Flags: %u, GamePort: %u", unServerFlags, unGamePort);
    return true;
}

// Removed from Steam SDK v1.01, backward compatibility
bool CSteamGameServer::BSetServerType( int32 nGameAppId, uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
						uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %d, Flags: %u, GamePort: %u", nGameAppId, unServerFlags, unGamePort);
    return true;
}

// Updates server status values which shows up in the server browser and matchmaking APIs
// Removed from Steam SDK v1.17, backward compatibility
void CSteamGameServer::UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, 
						 const char *pchServerName, const char *pSpectatorServerName, 
						 const char *pchMapName )
{
    VLOG_INFO(__FUNCTION__ " - Players: %d/%d, Bots: %d, Server: %s, Map: %s", 
               cPlayers, cPlayersMax, cBotPlayers, 
               pchServerName ? pchServerName : "null", 
               pchMapName ? pchMapName : "null");
}

// This can be called if spectator goes away or comes back (passing 0 means there is no spectator server now).
// Removed from Steam SDK v1.17, backward compatibility
void CSteamGameServer::UpdateSpectatorPort( uint16 unSpectatorPort )
{
    VLOG_INFO(__FUNCTION__ " - Port: %u", unSpectatorPort);
}


// Ask if a user has a specific achievement for this game, will get a callback on reply
// Removed from Steam SDK v1.08, backward compatibility
bool CSteamGameServer::BGetUserAchievementStatus( CSteamID steamID, const char *pchAchievementName )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu, Achievement: %s", 
               steamID.ConvertToUint64(), pchAchievementName ? pchAchievementName : "null");
    return false;
}

// New auth system APIs - do not mix with the old auth system APIs.
// ----------------------------------------------------------------

// Retrieve ticket to be sent to the entity who wishes to authenticate you ( using BeginAuthSession API ). 
// pcbTicket retrieves the length of the actual ticket.
HAuthTicket CSteamGameServer::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Authenticate ticket ( from GetAuthSessionTicket ) from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
EBeginAuthSessionResult CSteamGameServer::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
    VLOG_INFO(__FUNCTION__);
    return EBeginAuthSessionResult::k_EBeginAuthSessionResultOK;
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
void CSteamGameServer::EndAuthSession( CSteamID steamID )
{
    VLOG_INFO(__FUNCTION__);
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
void CSteamGameServer::CancelAuthTicket( HAuthTicket hAuthTicket )
{
    VLOG_INFO(__FUNCTION__);
}

// After receiving a user's authentication data, and passing it to SendUserConnectAndAuthenticate, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
EUserHasLicenseForAppResult CSteamGameServer::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu, AppID: %u", steamID.ConvertToUint64(), appID);
    return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
}

// Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
// returns false if we're not connected to the steam servers and thus cannot ask
bool CSteamGameServer::RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup )
{
    VLOG_INFO(__FUNCTION__ " - User: %llu, Group: %llu", 
               steamIDUser.ConvertToUint64(), steamIDGroup.ConvertToUint64());
    return false;
}


// these two functions s are deprecated, and will not return results
// they will be removed in a future version of the SDK
void CSteamGameServer::GetGameplayStats( )
{
    VLOG_INFO(__FUNCTION__);
}

SteamAPICall_t CSteamGameServer::GetServerReputation( )
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Returns the public IP of the server according to Steam, useful when the server is 
// behind NAT and you want to advertise its IP in a lobby for other clients to directly
// connect to
uint32 CSteamGameServer::GetPublicIP()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

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
bool CSteamGameServer::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
{
    VLOG_INFO(__FUNCTION__ " - DataSize: %d, SourceIP: %u, SourcePort: %u", cbData, srcIP, srcPort);
    return false;
}

// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
// This gets a packet that the master server updater needs to send out on UDP.
// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
// Call this each frame until it returns 0.
int CSteamGameServer::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
{
    VLOG_INFO(__FUNCTION__ " - MaxOut: %d", cbMaxOut);
    return 0;
}

//
// Control heartbeats / advertisement with master server
//

// Call this as often as you like to tell the master server updater whether or not
// you want it to be active (default: off).
void CSteamGameServer::EnableHeartbeats( bool bActive )
{
    VLOG_INFO(__FUNCTION__ " - Active: %s", bActive ? "true" : "false");
}

// You usually don't need to modify this.
// Pass -1 to use the default value for iHeartbeatInterval.
// Some mods change this.
void CSteamGameServer::SetHeartbeatInterval( int iHeartbeatInterval )
{
    VLOG_INFO(__FUNCTION__ " - Interval: %d", iHeartbeatInterval);
}

// Force a heartbeat to steam at the next opportunity
void CSteamGameServer::ForceHeartbeat()
{
    VLOG_INFO(__FUNCTION__);
}

// associate this game server with this clan for the purposes of computing player compat
SteamAPICall_t CSteamGameServer::AssociateWithClan( CSteamID steamIDClan )
{
    VLOG_INFO(__FUNCTION__ " - Clan: %llu", steamIDClan.GetAccountID());
    return 0;
}

// ask if any of the current players dont want to play with this new player - or vice versa
SteamAPICall_t CSteamGameServer::ComputeNewPlayerCompatibility( CSteamID steamIDNewPlayer )
{
    VLOG_INFO(__FUNCTION__ " - NewPlayer: %llu", steamIDNewPlayer.GetAccountID());
    return 0;
}
