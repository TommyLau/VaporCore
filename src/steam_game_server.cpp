/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "logger.h"
#include "steam_game_server.h"

// Static instance
Steam_Game_Server* Steam_Game_Server::s_pInstance = nullptr;

Steam_Game_Server::Steam_Game_Server()
{
    VLOG_INFO("Steam_Game_Server constructor called");
}

Steam_Game_Server::~Steam_Game_Server()
{
    VLOG_INFO("Steam_Game_Server destructor called");
}

// Helper methods
Steam_Game_Server* Steam_Game_Server::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Game_Server();
    }
    return s_pInstance;
}

void Steam_Game_Server::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

//
// Basic server data.  These properties, if set, must be set before before calling LogOn.  They
// may not be changed after logged in.
//

// This is called by SteamGameServer_Init, and you will usually not need to call it directly
bool Steam_Game_Server::InitGameServer( uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString )
{
    VLOG_DEBUG("InitGameServer called - IP: %u, GamePort: %u, QueryPort: %u, Flags: %u, AppID: %u, Version: %s", unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString ? pchVersionString : "null");
    return true;
}

// Game product identifier.  This is currently used by the master server for version checking purposes.
// It's a required field, but will eventually will go away, and the AppID will be used for this purpose.
void Steam_Game_Server::SetProduct( const char *pszProduct )
{
    VLOG_DEBUG("SetProduct called - Product: %s", pszProduct ? pszProduct : "null");
}

// Description of the game.  This is a required field and is displayed in the steam server browser....for now.
// This is a required field, but it will go away eventually, as the data should be determined from the AppID.
void Steam_Game_Server::SetGameDescription( const char *pszGameDescription )
{
    VLOG_DEBUG("SetGameDescription called - Description: %s", pszGameDescription ? pszGameDescription : "null");
}

// If your game is a "mod," pass the string that identifies it.  The default is an empty string, meaning
// this application is the original game, not a mod.
//
// @see k_cbMaxGameServerGameDir
void Steam_Game_Server::SetModDir( const char *pszModDir )
{
    VLOG_DEBUG("SetModDir called - ModDir: %s", pszModDir ? pszModDir : "null");
}

// Is this is a dedicated server?  The default value is false.
void Steam_Game_Server::SetDedicatedServer( bool bDedicated )
{
    VLOG_DEBUG("SetDedicatedServer called - Dedicated: %s", bDedicated ? "true" : "false");
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
void Steam_Game_Server::LogOn( const char *pszToken )
{
    VLOG_DEBUG("LogOn called - Token: %s", pszToken ? pszToken : "null");
}

// Changed from Steam SDK v1.29a, backward compatibility
void Steam_Game_Server::LogOn( const char *pszAccountName, const char *pszPassword )
{
    VLOG_DEBUG("LogOn called - Account: %s, Password: %s", pszAccountName ? pszAccountName : "null", pszPassword ? pszPassword : "null");
}

// Changed from Steam SDK v1.17, backward compatibility
void Steam_Game_Server::LogOn()
{
    VLOG_DEBUG("LogOn called");
}

// Login to a generic, anonymous account.
//
// Note: in previous versions of the SDK, this was automatically called within SteamGameServer_Init,
// but this is no longer the case.
void Steam_Game_Server::LogOnAnonymous()
{
    VLOG_DEBUG("LogOnAnonymous called");
}

// Begin process of logging game server out of steam
void Steam_Game_Server::LogOff()
{
    VLOG_DEBUG("LogOff called");
}

// status functions
bool Steam_Game_Server::BLoggedOn()
{
    VLOG_DEBUG("BLoggedOn called");
    return true;
}

bool Steam_Game_Server::BSecure()
{
    VLOG_DEBUG("BSecure called");
    return false;
}

CSteamID Steam_Game_Server::GetSteamID()
{
    VLOG_DEBUG("GetSteamID called");
    return CSteamID();
}

// Returns true if the master server has requested a restart.
// Only returns true once per request.
bool Steam_Game_Server::WasRestartRequested()
{
    VLOG_DEBUG("WasRestartRequested called");
    return false;
}

//
// Server state.  These properties may be changed at any time.
//

// Max player count that will be reported to server browser and client queries
void Steam_Game_Server::SetMaxPlayerCount( int cPlayersMax )
{
    VLOG_DEBUG("SetMaxPlayerCount called - PlayersMax: %d", cPlayersMax);
}

// Number of bots.  Default value is zero
void Steam_Game_Server::SetBotPlayerCount( int cBotplayers )
{
    VLOG_DEBUG("SetBotPlayerCount called - Bots: %d", cBotplayers);
}

// Set the name of server as it will appear in the server browser
//
// @see k_cbMaxGameServerName
void Steam_Game_Server::SetServerName( const char *pszServerName )
{
    VLOG_DEBUG("SetServerName called - ServerName: %s", pszServerName ? pszServerName : "null");
}

// Set name of map to report in the server browser
//
// @see k_cbMaxGameServerName
void Steam_Game_Server::SetMapName( const char *pszMapName )
{
    VLOG_DEBUG("SetMapName called - MapName: %s", pszMapName ? pszMapName : "null");
}

// Let people know if your server will require a password
void Steam_Game_Server::SetPasswordProtected( bool bPasswordProtected )
{
    VLOG_DEBUG("SetPasswordProtected called - PasswordProtected: %s", bPasswordProtected ? "true" : "false");
}

// Spectator server.  The default value is zero, meaning the service
// is not used.
void Steam_Game_Server::SetSpectatorPort( uint16 unSpectatorPort )
{
    VLOG_DEBUG("SetSpectatorPort called - SpectatorPort: %u", unSpectatorPort);
}

// Name of the spectator server.  (Only used if spectator port is nonzero.)
//
// @see k_cbMaxGameServerMapName
void Steam_Game_Server::SetSpectatorServerName( const char *pszSpectatorServerName )
{
    VLOG_DEBUG("SetSpectatorServerName called - SpectatorServerName: %s", pszSpectatorServerName ? pszSpectatorServerName : "null");
}

// Call this to clear the whole list of key/values that are sent in rules queries.
void Steam_Game_Server::ClearAllKeyValues()
{
    VLOG_DEBUG("ClearAllKeyValues called");
}
	
// Call this to add/update a key/value pair.
void Steam_Game_Server::SetKeyValue( const char *pKey, const char *pValue )
{
    VLOG_DEBUG("SetKeyValue called - Key: %s, Value: %s", pKey ? pKey : "null", pValue ? pValue : "null");
}

// Sets a string defining the "gametags" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
//
// @see k_cbMaxGameServerTags
void Steam_Game_Server::SetGameTags( const char *pchGameTags )
{
    VLOG_DEBUG("SetGameTags called - GameTags: %s", pchGameTags ? pchGameTags : "null");
}

// Sets a string defining the "gametype" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
// Changed from Steam SDK v1.09 to SetGameTags, backward compatibility
void Steam_Game_Server::SetGameType( const char *pchGameType )
{
    VLOG_DEBUG("SetGameType called - GameType: %s", pchGameType ? pchGameType : "null");
    // TODO: Call SetGameTags?
}

// Sets a string defining the "gamedata" for this server, this is optional, but if it is set
// it allows users to filter in the matchmaking/server-browser interfaces based on the value
// don't set this unless it actually changes, its only uploaded to the master once (when
// acknowledged)
//
// @see k_cbMaxGameServerGameData
void Steam_Game_Server::SetGameData( const char *pchGameData)
{
    VLOG_DEBUG("SetGameData called - GameData: %s", pchGameData ? pchGameData : "null");
}

// Region identifier.  This is an optional field, the default value is empty, meaning the "world" region
void Steam_Game_Server::SetRegion( const char *pszRegion )
{
    VLOG_DEBUG("SetRegion called - Region: %s", pszRegion ? pszRegion : "null");
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
bool Steam_Game_Server::SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
{
    VLOG_DEBUG("SendUserConnectAndAuthenticate called - IP: %u, BlobSize: %u", unIPClient, cubAuthBlobSize);
    return false;
}

// Return Value: true/false depending on whether the call succeeds.  If the call succeeds then you
// should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
// for the user has succeeded or failed.
// Removed from Steam SDK v1.01, backward compatibility
void Steam_Game_Server::SendUserConnectAndAuthenticate( CSteamID steamIDUser, uint32 unIPClient, void *pvAuthBlob, uint32 cubAuthBlobSize )
{
    VLOG_DEBUG("SendUserConnectAndAuthenticate called - User: %llu, IP: %u, BlobSize: %u", steamIDUser.ConvertToUint64(), unIPClient, cubAuthBlobSize);
}

// Creates a fake user (ie, a bot) which will be listed as playing on the server, but skips validation.  
// 
// Return Value: Returns a SteamID for the user to be tracked with, you should call HandleUserDisconnect()
// when this user leaves the server just like you would for a real user.
CSteamID Steam_Game_Server::CreateUnauthenticatedUserConnection()
{
    VLOG_DEBUG("CreateUnauthenticatedUserConnection called");
    return CSteamID();
}

// Should be called whenever a user leaves our game server, this lets Steam internally
// track which users are currently on which servers for the purposes of preventing a single
// account being logged into multiple servers, showing who is currently on a server, etc.
void Steam_Game_Server::SendUserDisconnect( CSteamID steamIDUser )
{
    VLOG_DEBUG("SendUserDisconnect called - User: %llu", steamIDUser.ConvertToUint64());
}

// Update the data to be displayed in the server browser and matchmaking interfaces for a user
// currently connected to the server.  For regular users you must call this after you receive a
// GSUserValidationSuccess callback.
// 
// Return Value: true if successful, false if failure (ie, steamIDUser wasn't for an active player)
bool Steam_Game_Server::BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore )
{
    VLOG_DEBUG("BUpdateUserData called - User: %llu, Name: %s, Score: %u", steamIDUser.ConvertToUint64(), pchPlayerName ? pchPlayerName : "null", uScore);
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
bool Steam_Game_Server::BSetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
								uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
{
    VLOG_DEBUG("BSetServerType called - Flags: %u, GamePort: %u", unServerFlags, unGamePort);
    return true;
}

// Removed from Steam SDK v1.01, backward compatibility
bool Steam_Game_Server::BSetServerType( int32 nGameAppId, uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
						uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
{
    VLOG_DEBUG("BSetServerType called - AppID: %d, Flags: %u, GamePort: %u", nGameAppId, unServerFlags, unGamePort);
    return true;
}

// Updates server status values which shows up in the server browser and matchmaking APIs
// Removed from Steam SDK v1.17, backward compatibility
void Steam_Game_Server::UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, 
						 const char *pchServerName, const char *pSpectatorServerName, 
						 const char *pchMapName )
{
    VLOG_DEBUG("UpdateServerStatus called - Players: %d/%d, Bots: %d, Server: %s, Map: %s", 
               cPlayers, cPlayersMax, cBotPlayers, 
               pchServerName ? pchServerName : "null", 
               pchMapName ? pchMapName : "null");
}

// This can be called if spectator goes away or comes back (passing 0 means there is no spectator server now).
// Removed from Steam SDK v1.17, backward compatibility
void Steam_Game_Server::UpdateSpectatorPort( uint16 unSpectatorPort )
{
    VLOG_DEBUG("UpdateSpectatorPort called - Port: %u", unSpectatorPort);
}


// Ask if a user has a specific achievement for this game, will get a callback on reply
// Removed from Steam SDK v1.08, backward compatibility
bool Steam_Game_Server::BGetUserAchievementStatus( CSteamID steamID, const char *pchAchievementName )
{
    VLOG_DEBUG("BGetUserAchievementStatus called - User: %llu, Achievement: %s", 
               steamID.ConvertToUint64(), pchAchievementName ? pchAchievementName : "null");
    return false;
}

// New auth system APIs - do not mix with the old auth system APIs.
// ----------------------------------------------------------------

// Retrieve ticket to be sent to the entity who wishes to authenticate you ( using BeginAuthSession API ). 
// pcbTicket retrieves the length of the actual ticket.
HAuthTicket Steam_Game_Server::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
    VLOG_DEBUG("GetAuthSessionTicket called");
    return 0;
}

// Authenticate ticket ( from GetAuthSessionTicket ) from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
EBeginAuthSessionResult Steam_Game_Server::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
    VLOG_DEBUG("BeginAuthSession called");
    return EBeginAuthSessionResult::k_EBeginAuthSessionResultOK;
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
void Steam_Game_Server::EndAuthSession( CSteamID steamID )
{
    VLOG_DEBUG("EndAuthSession called");
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
void Steam_Game_Server::CancelAuthTicket( HAuthTicket hAuthTicket )
{
    VLOG_DEBUG("CancelAuthTicket called");
}

// After receiving a user's authentication data, and passing it to SendUserConnectAndAuthenticate, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
EUserHasLicenseForAppResult Steam_Game_Server::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
    VLOG_DEBUG("UserHasLicenseForApp called - User: %llu, AppID: %u", steamID.ConvertToUint64(), appID);
    return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
}

// Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
// returns false if we're not connected to the steam servers and thus cannot ask
bool Steam_Game_Server::RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup )
{
    VLOG_DEBUG("RequestUserGroupStatus called - User: %llu, Group: %llu", 
               steamIDUser.ConvertToUint64(), steamIDGroup.ConvertToUint64());
    return false;
}

//
// Query steam for server data
//

// Ask for the gameplay stats for the server. Results returned in a callback
void Steam_Game_Server::GetGameplayStats( )
{
    VLOG_DEBUG("GetGameplayStats called");
}

// Gets the reputation score for the game server. This API also checks if the server or some
// other server on the same IP is banned from the Steam master servers.
SteamAPICall_t Steam_Game_Server::GetServerReputation( )
{
    VLOG_DEBUG("GetServerReputation called");
    return 0;
}

// Returns the public IP of the server according to Steam, useful when the server is 
// behind NAT and you want to advertise its IP in a lobby for other clients to directly
// connect to
uint32 Steam_Game_Server::GetPublicIP()
{
    VLOG_DEBUG("GetPublicIP called");
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
bool Steam_Game_Server::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
{
    VLOG_DEBUG("HandleIncomingPacket called - DataSize: %d, SourceIP: %u, SourcePort: %u", cbData, srcIP, srcPort);
    return false;
}

// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
// This gets a packet that the master server updater needs to send out on UDP.
// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
// Call this each frame until it returns 0.
int Steam_Game_Server::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
{
    VLOG_DEBUG("GetNextOutgoingPacket called - MaxOut: %d", cbMaxOut);
    return 0;
}

//
// Control heartbeats / advertisement with master server
//

// Call this as often as you like to tell the master server updater whether or not
// you want it to be active (default: off).
void Steam_Game_Server::EnableHeartbeats( bool bActive )
{
    VLOG_DEBUG("EnableHeartbeats called - Active: %s", bActive ? "true" : "false");
}

// You usually don't need to modify this.
// Pass -1 to use the default value for iHeartbeatInterval.
// Some mods change this.
void Steam_Game_Server::SetHeartbeatInterval( int iHeartbeatInterval )
{
    VLOG_DEBUG("SetHeartbeatInterval called - Interval: %d", iHeartbeatInterval);
}

// Force a heartbeat to steam at the next opportunity
void Steam_Game_Server::ForceHeartbeat()
{
    VLOG_DEBUG("ForceHeartbeat called");
}

// associate this game server with this clan for the purposes of computing player compat
SteamAPICall_t Steam_Game_Server::AssociateWithClan( CSteamID steamIDClan )
{
    VLOG_DEBUG("AssociateWithClan called - Clan: %llu", steamIDClan.GetAccountID());
    return 0;
}

// ask if any of the current players dont want to play with this new player - or vice versa
SteamAPICall_t Steam_Game_Server::ComputeNewPlayerCompatibility( CSteamID steamIDNewPlayer )
{
    VLOG_DEBUG("ComputeNewPlayerCompatibility called - NewPlayer: %llu", steamIDNewPlayer.GetAccountID());
    return 0;
}
