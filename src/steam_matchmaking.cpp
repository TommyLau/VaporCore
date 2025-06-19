/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_matchmaking.h"
#include "logger.h"

// Static instance
Steam_Matchmaking* Steam_Matchmaking::s_pInstance = nullptr;

Steam_Matchmaking::Steam_Matchmaking()
{
    VLOG_INFO("Steam_Matchmaking constructor called");
}

Steam_Matchmaking::~Steam_Matchmaking()
{
    VLOG_INFO("Steam_Matchmaking destructor called");
}

// returns the number of favorites servers the user has stored
int Steam_Matchmaking::GetFavoriteGameCount()
{
    VLOG_DEBUG("GetFavoriteGameCount called");
    return 0;
}

// returns the details of the game server
// iGame is of range [0,GetFavoriteGameCount())
// *pnIP, *pnConnPort are filled in the with IP:port of the game server
// *punFlags specify whether the game server was stored as an explicit favorite or in the history of connections
// *pRTime32LastPlayedOnServer is filled in the with the Unix time the favorite was added
bool Steam_Matchmaking::GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer )
{
    VLOG_DEBUG("GetFavoriteGame called - Game: %d", iGame);
    return false;
}

// adds the game server to the local list; updates the time played of the server if it already exists in the list
int Steam_Matchmaking::AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
{
    VLOG_DEBUG("AddFavoriteGame called - AppID: %u, IP: %u, ConnPort: %u, QueryPort: %u", nAppID, nIP, nConnPort, nQueryPort);
    return 0;
}

// removes the game server from the local storage; returns true if one was removed
bool Steam_Matchmaking::RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
{
    VLOG_DEBUG("RemoveFavoriteGame called - AppID: %u, IP: %u, ConnPort: %u, QueryPort: %u", nAppID, nIP, nConnPort, nQueryPort);
    return false;
}

// Get a list of relevant lobbies
// this is an asynchronous request
// results will be returned by LobbyMatchList_t callback, with the number of servers requested
// if the user is not currently connected to Steam (i.e. SteamUser()->BLoggedOn() returns false) then
// a LobbyMatchList_t callback will be posted immediately with no servers
// Changed from Steam SDK v1.03, backward compatibility
void Steam_Matchmaking::DEPRECATED_RequestLobbyList()
{
    VLOG_DEBUG("DEPRECATED_RequestLobbyList called");
}

// results will be returned by LobbyMatchList_t callback & call result, with the number of lobbies found
// this will never return lobbies that are full
// to add more filter, the filter calls below need to be call before each and every RequestLobbyList() call
// use the CCallResult<> object in steam_api.h to match the SteamAPICall_t call result to a function in an object, e.g.
/*
    class CMyLobbyListManager
    {
        CCallResult<CMyLobbyListManager, LobbyMatchList_t> m_CallResultLobbyMatchList;
        void FindLobbies()
        {
            // SteamMatchmaking()->AddRequestLobbyListFilter*() functions would be called here, before RequestLobbyList()
            SteamAPICall_t hSteamAPICall = SteamMatchmaking()->RequestLobbyList();
            m_CallResultLobbyMatchList.Set( hSteamAPICall, this, &CMyLobbyListManager::OnLobbyMatchList );
        }

        void OnLobbyMatchList( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
        {
            // lobby list has be retrieved from Steam back-end, use results
        }
    }
*/
// 
SteamAPICall_t Steam_Matchmaking::RequestLobbyList()
{
    VLOG_DEBUG("RequestLobbyList called");
    return 0;
}

// filters for lobbies
// this needs to be called before RequestLobbyList() to take effect
// these are cleared on each call to RequestLobbyList()
// Removed from Steam SDK v1.05, backward compatibility
void Steam_Matchmaking::AddRequestLobbyListFilter( const char *pchKeyToMatch, const char *pchValueToMatch )
{
    VLOG_DEBUG("AddRequestLobbyListFilter called - Key: %s, Value: %s", pchKeyToMatch, pchValueToMatch);
}

void Steam_Matchmaking::AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_DEBUG("AddRequestLobbyListStringFilter called - Key: %s, Value: %s, Comparison Type: %d", pchKeyToMatch, pchValueToMatch, eComparisonType);
}

// numerical comparison - 0 is equal, -1 is the lobby value is less than nValueToMatch, 1 is the lobby value is greater than nValueToMatch
// Removed from Steam SDK v1.05, backward compatibility
void Steam_Matchmaking::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, int nComparisonType /* 0 is equal, -1 is less than, 1 is greater than */ )
{
    VLOG_DEBUG("AddRequestLobbyListNumericalFilter called - Key: %s, Value: %d, Comparison Type: %d", pchKeyToMatch, nValueToMatch, nComparisonType);
}

void Steam_Matchmaking::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_DEBUG("AddRequestLobbyListNumericalFilter called - Key: %s, Value: %d, Comparison Type: %d", pchKeyToMatch, nValueToMatch, eComparisonType);
}

// sets RequestLobbyList() to only returns lobbies which aren't yet full - needs SetLobbyMemberLimit() called on the lobby to set an initial limit
// Removed from Steam SDK v1.03, backward compatibility
void Steam_Matchmaking::AddRequestLobbyListSlotsAvailableFilter()
{
    VLOG_DEBUG("AddRequestLobbyListSlotsAvailableFilter called");
}

// returns results closest to the specified value. Multiple near filters can be added, with early filters taking precedence
void Steam_Matchmaking::AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo )
{
    VLOG_DEBUG("AddRequestLobbyListNearValueFilter called - Key: %s, Value: %d", pchKeyToMatch, nValueToBeCloseTo);
}

// returns only lobbies with the specified number of slots available
void Steam_Matchmaking::AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable )
{
    VLOG_DEBUG("AddRequestLobbyListFilterSlotsAvailable called - Slots Available: %d", nSlotsAvailable);
}

// returns the CSteamID of a lobby, as retrieved by a RequestLobbyList call
// should only be called after a LobbyMatchList_t callback is received
// iLobby is of the range [0, LobbyMatchList_t::m_nLobbiesMatching)
// the returned CSteamID::IsValid() will be false if iLobby is out of range
CSteamID Steam_Matchmaking::GetLobbyByIndex( int iLobby )
{
    VLOG_DEBUG("GetLobbyByIndex called - Lobby: %d", iLobby);
    return CSteamID();
}

// Create a lobby on the Steam servers.
// If bPrivate is true, then the lobby will not be returned by any RequestLobbyList() call; the CSteamID
// of the lobby will need to be communicated via game channels or via InviteUserToLobby()
// this is an asynchronous request
// results will be returned by LobbyCreated_t callback when the lobby has been created;
// local user will the join the lobby, resulting in an additional LobbyEnter_t callback being sent
// operations on the chat room can only proceed once the LobbyEnter_t has been received
// Removed from Steam SDK v1.03, backward compatibility
void Steam_Matchmaking::CreateLobby( bool bPrivate )
{
    VLOG_DEBUG("CreateLobby called - Private: %s", bPrivate ? "true" : "false");
}

// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this pointer
// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
SteamAPICall_t Steam_Matchmaking::CreateLobby( ELobbyType eLobbyType, int cMaxMembers )
{
    VLOG_DEBUG("CreateLobby called - LobbyType: %d, MaxMembers: %d", eLobbyType, cMaxMembers);
    return 0;
}

// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this pointer
// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
SteamAPICall_t Steam_Matchmaking::CreateLobby( ELobbyType eLobbyType )
{
    VLOG_DEBUG("CreateLobby called - LobbyType: %d", eLobbyType);
    return 0;
}

// Joins an existing lobby
// this is an asynchronous request
// results will be returned by LobbyEnter_t callback when the lobby has been joined
// Removed from Steam SDK v1.03, backward compatibility
void Steam_Matchmaking::DEPRECATED_JoinLobby( CSteamID steamIDLobby )
{
    VLOG_DEBUG("DEPRECATED_JoinLobby called - Lobby: %llu", steamIDLobby.GetAccountID());
}

// results will be returned by LobbyEnter_t callback & call result, check m_EChatRoomEnterResponse to see if was successful
// lobby metadata is available to use immediately on this call completing
SteamAPICall_t Steam_Matchmaking::JoinLobby( CSteamID steamIDLobby )
{
    VLOG_DEBUG("JoinLobby called - Lobby: %llu", steamIDLobby.GetAccountID());
    return 0;
}

// Leave a lobby; this will take effect immediately on the client side
// other users in the lobby will be notified by a LobbyChatUpdate_t callback
void Steam_Matchmaking::LeaveLobby( CSteamID steamIDLobby )
{
    VLOG_DEBUG("LeaveLobby called - Lobby: %llu", steamIDLobby.GetAccountID());
}

// Invite another user to the lobby
// the target user will receive a LobbyInvite_t callback
// will return true if the invite is successfully sent, whether or not the target responds
// returns false if the local user is not connected to the Steam servers
bool Steam_Matchmaking::InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
{
    VLOG_DEBUG("InviteUserToLobby called - Lobby: %llu, Invitee: %llu", steamIDLobby.GetAccountID(), steamIDInvitee.GetAccountID());
    return false;
}

// returns the number of users in the specified lobby
int Steam_Matchmaking::GetNumLobbyMembers( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetNumLobbyMembers called - Lobby: %llu", steamIDLobby.GetAccountID());
    return 0;
}

// returns the CSteamID of a user in the lobby
// iMember is of range [0,GetNumLobbyMembers())
CSteamID Steam_Matchmaking::GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember )
{
    VLOG_DEBUG("GetLobbyMemberByIndex called - Lobby: %llu, Member: %d", steamIDLobby.GetAccountID(), iMember);
    return CSteamID();
}

// Get data associated with this lobby
// takes a simple key, and returns the string associated with it
// "" will be returned if no value is set, or if steamIDLobby is invalid
const char *Steam_Matchmaking::GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
    VLOG_DEBUG("GetLobbyData called - Lobby: %llu, Key: %s", steamIDLobby.GetAccountID(), pchKey ? pchKey : "null");
    return "";
}

// Sets a key/value pair in the lobby metadata
// each user in the lobby will be broadcast this new value, and any new users joining will receive any existing data
// this can be used to set lobby names, map, etc.
// to reset a key, just set it to ""
// other users in the lobby will receive notification of the lobby data change via a LobbyDataUpdate_t callback
bool Steam_Matchmaking::SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("SetLobbyData called - Lobby: %llu, Key: %s, Value: %s", 
               steamIDLobby.GetAccountID(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
    return true;
}

// returns the number of metadata keys set on the specified lobby
int Steam_Matchmaking::GetLobbyDataCount( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetLobbyDataCount called - Lobby: %llu", steamIDLobby.ConvertToUint64());
    return 0;
}

// returns a lobby metadata key/values pair by index, of range [0, GetLobbyDataCount())
bool Steam_Matchmaking::GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize )
{
    VLOG_DEBUG("GetLobbyDataByIndex called - Lobby: %llu, Index: %d, KeySize: %d, ValueSize: %d", 
               steamIDLobby.GetAccountID(), iLobbyData, cchKeyBufferSize, cchValueBufferSize);
    return false;
}

// removes a metadata key from the lobby
bool Steam_Matchmaking::DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
    VLOG_DEBUG("DeleteLobbyData called - Lobby: %llu, Key: %s", steamIDLobby.GetAccountID(), pchKey ? pchKey : "null");
    return false;
}

// Gets per-user metadata for someone in this lobby
const char *Steam_Matchmaking::GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
{
    VLOG_DEBUG("GetLobbyMemberData called - Lobby: %llu, User: %llu, Key: %s", 
               steamIDLobby.GetAccountID(), steamIDUser.GetAccountID(), pchKey ? pchKey : "null");
    return "";
}

// Sets per-user metadata (for the local user implicitly)
void Steam_Matchmaking::SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("SetLobbyMemberData called - Lobby: %llu, Key: %s, Value: %s", 
               steamIDLobby.GetAccountID(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// Broadcasts a chat message to the all the users in the lobby
// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
// returns true if the message is successfully sent
bool Steam_Matchmaking::SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
{
    VLOG_DEBUG("SendLobbyChatMsg called - Lobby: %llu, MsgSize: %d", steamIDLobby.GetAccountID(), cubMsgBody);
    return false;
}

// Get a chat message as specified in a LobbyChatMsg_t callback
// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
// *pSteamIDUser is filled in with the CSteamID of the member
// *pvData is filled in with the message itself
// return value is the number of bytes written into the buffer
int Steam_Matchmaking::GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
    VLOG_DEBUG("GetLobbyChatEntry called - Lobby: %llu, ChatID: %d, DataSize: %d", steamIDLobby.GetAccountID(), iChatID, cubData);
    return 0;
}

// Fetch metadata for a lobby you're not necessarily in right now
// this will send down all the metadata associated with a lobby
// this is an asynchronous call
// returns false if the local user is not connected to the Steam servers
bool Steam_Matchmaking::RequestLobbyData( CSteamID steamIDLobby )
{
    VLOG_DEBUG("RequestLobbyData called - Lobby: %llu", steamIDLobby.GetAccountID());
    return false;
}

// sets the game server associated with the lobby
// usually at this point, the users will leave the lobby and join the specified game server
// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
void Steam_Matchmaking::SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
{
    VLOG_DEBUG("SetLobbyGameServer called - Lobby: %llu, ServerIP: %u, ServerPort: %u, GameServer: %llu", 
               steamIDLobby.GetAccountID(), unGameServerIP, unGameServerPort, steamIDGameServer.GetAccountID());
}

// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
bool Steam_Matchmaking::GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer )
{
    VLOG_DEBUG("GetLobbyGameServer called - Lobby: %llu, ServerIP: %u, ServerPort: %u, GameServer: %llu", 
               steamIDLobby.GetAccountID(), punGameServerIP, punGameServerPort, psteamIDGameServer->GetAccountID());
    return false;
}

// set the limit on the # of users who can join the lobby
bool Steam_Matchmaking::SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
{
    VLOG_DEBUG("SetLobbyMemberLimit called - Lobby: %llu, MaxMembers: %d", steamIDLobby.GetAccountID(), cMaxMembers);
    return false;
}

// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
int Steam_Matchmaking::GetLobbyMemberLimit( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetLobbyMemberLimit called - Lobby: %llu", steamIDLobby.GetAccountID());
    return 0;
}

// asks the Steam servers for a list of lobbies that friends are in
// returns results by posting one RequestFriendsLobbiesResponse_t callback per friend/lobby pair
// if no friends are in lobbies, RequestFriendsLobbiesResponse_t will be posted but with 0 results
// filters don't apply to lobbies (currently)
// Removed from Steam SDK v1.03, backward compatibility
bool Steam_Matchmaking::RequestFriendsLobbies()
{
    VLOG_DEBUG("RequestFriendsLobbies called");
    return false;
}

// updates which type of lobby it is
// only lobbies that are k_ELobbyTypePublic will be returned by RequestLobbyList() calls
bool Steam_Matchmaking::SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType )
{
    VLOG_DEBUG("SetLobbyType called - Lobby: %llu, Type: %d", steamIDLobby.GetAccountID(), eLobbyType);
    return false;
}

// sets whether or not a lobby is joinable - defaults to true for a new lobby
// if set to false, no user can join, even if they are a friend or have been invited
bool Steam_Matchmaking::SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable )
{
    VLOG_DEBUG("SetLobbyJoinable called - Lobby: %llu, Joinable: %s", steamIDLobby.GetAccountID(), bLobbyJoinable ? "true" : "false");
    return false;
}

// returns the current lobby owner
// you must be a member of the lobby to access this
// there always one lobby owner - if the current owner leaves, another user will become the owner
// it is possible (bur rare) to join a lobby just as the owner is leaving, thus entering a lobby with self as the owner
CSteamID Steam_Matchmaking::GetLobbyOwner( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetLobbyOwner called - Lobby: %llu", steamIDLobby.GetAccountID());
    return CSteamID();
}

// changes who the lobby owner is
// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
// after completion, the local user will no longer be the owner
bool Steam_Matchmaking::SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner )
{
    VLOG_DEBUG("SetLobbyOwner called - Lobby: %llu, NewOwner: %llu", steamIDLobby.GetAccountID(), steamIDNewOwner.GetAccountID());
    return false;
}

// Helper methods
Steam_Matchmaking* Steam_Matchmaking::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Matchmaking();
    }
    return s_pInstance;
}

void Steam_Matchmaking::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

//-----------------------------------------------------------------------------
// Callback interfaces for server list functions (see ISteamMatchmakingServers below)
//
// The idea here is that your game code implements objects that implement these
// interfaces to receive callback notifications after calling asynchronous functions
// inside the ISteamMatchmakingServers() interface below.
//
// This is different than normal Steam callback handling due to the potentially
// large size of server lists.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after a server list refresh
// or an individual server update.
//
// Since you get these callbacks after requesting full list refreshes you will
// usually implement this interface inside an object like CServerBrowser.  If that
// object is getting destructed you should use ISteamMatchMakingServers()->CancelQuery()
// to cancel any in-progress queries so you don't get a callback into the destructed
// object and crash.
//-----------------------------------------------------------------------------
// Server has responded ok with updated data
void Steam_Matchmaking_Server_List_Response::ServerResponded( int iServer )
{
    VLOG_DEBUG("ServerResponded called - Server: %d", iServer);
} 

// Server has failed to respond
void Steam_Matchmaking_Server_List_Response::ServerFailedToRespond( int iServer )
{
    VLOG_DEBUG("ServerFailedToRespond called - Server: %d", iServer);
} 

// A list refresh you had initiated is now 100% completed
void Steam_Matchmaking_Server_List_Response::RefreshComplete( EMatchMakingServerResponse response )
{
    VLOG_DEBUG("RefreshComplete called - Response: %d", response);
} 

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after pinging an individual server 
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->PingServer() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
// Server has responded successfully and has updated data
void Steam_MatchmakingPingResponse::ServerResponded( gameserveritem_t &server )
{
    VLOG_DEBUG("ServerResponded called - Server: %d", server.m_nPing);
}

// Server failed to respond to the ping request
void Steam_MatchmakingPingResponse::ServerFailedToRespond()
{
    VLOG_DEBUG("ServerFailedToRespond called");
}

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting details on
// who is playing on a particular server.
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->PlayerDetails() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
// Got data on a new player on the server -- you'll get this callback once per player
// on the server which you have requested player data on.
void Steam_Matchmaking_Players_Response::AddPlayerToList( const char *pchName, int nScore, float flTimePlayed )
{
    VLOG_DEBUG("AddPlayerToList called - Name: %s, Score: %d, TimePlayed: %f", pchName, nScore, flTimePlayed);
}

// The server failed to respond to the request for player details
void Steam_Matchmaking_Players_Response::PlayersFailedToRespond()
{
    VLOG_DEBUG("PlayersFailedToRespond called");
}

// The server has finished responding to the player details request 
// (ie, you won't get anymore AddPlayerToList callbacks)
void Steam_Matchmaking_Players_Response::PlayersRefreshComplete()
{
    VLOG_DEBUG("PlayersRefreshComplete called");
}


//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting rules
// details on a particular server.
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->ServerRules() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
// Got data on a rule on the server -- you'll get one of these per rule defined on
// the server you are querying
void Steam_Matchmaking_Rules_Response::RulesResponded( const char *pchRule, const char *pchValue )
{
    VLOG_DEBUG("RulesResponded called - Rule: %s, Value: %s", pchRule, pchValue);
}

// The server failed to respond to the request for rule details
void Steam_Matchmaking_Rules_Response::RulesFailedToRespond()
{
    VLOG_DEBUG("RulesFailedToRespond called");
}

// The server has finished responding to the rule details request 
// (ie, you won't get anymore RulesResponded callbacks)
void Steam_Matchmaking_Rules_Response::RulesRefreshComplete()
{
    VLOG_DEBUG("RulesRefreshComplete called");
}

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
//-----------------------------------------------------------------------------
// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
void Steam_Matchmaking_Servers::RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestInternetServerList called - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void Steam_Matchmaking_Servers::RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestLANServerList called - AppID: %u, Response: %p", iApp, pRequestServersResponse);
}

void Steam_Matchmaking_Servers::RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestFriendsServerList called - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void Steam_Matchmaking_Servers::RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestFavoritesServerList called - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void Steam_Matchmaking_Servers::RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestHistoryServerList called - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void Steam_Matchmaking_Servers::RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_DEBUG("RequestSpectatorServerList called - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

/* the filters that are available in the ppchFilters params are:

    "map"		- map the server is running, as set in the dedicated server api
    "dedicated" - reports bDedicated from the API
    "secure"	- VAC-enabled
    "full"		- not full
    "empty"		- not empty
    "noplayers" - is empty
    "proxy"		- a relay server

*/

// Get details on a given server in the list, you can get the valid range of index
// values by calling GetServerCount().  You will also receive index values in 
// ISteamMatchmakingServerListResponse::ServerResponded() callbacks
gameserveritem_t *Steam_Matchmaking_Servers::GetServerDetails( EMatchMakingType eType, int iServer )
{
    VLOG_DEBUG("GetServerDetails called - Type: %d, Server: %d", eType, iServer);
    return nullptr;
} 

// Cancel an request which is operation on the given list type.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above list request calls.  Not doing so may result in a crash when a callback
// occurs on the destructed object.
void Steam_Matchmaking_Servers::CancelQuery( EMatchMakingType eType )
{
    VLOG_DEBUG("CancelQuery called - Type: %d", eType);
} 

// Ping every server in your list again but don't update the list of servers
void Steam_Matchmaking_Servers::RefreshQuery( EMatchMakingType eType )
{
    VLOG_DEBUG("RefreshQuery called - Type: %d", eType);
} 

// Returns true if the list is currently refreshing its server list
bool Steam_Matchmaking_Servers::IsRefreshing( EMatchMakingType eType )
{
    VLOG_DEBUG("IsRefreshing called - Type: %d", eType);
    return false;
} 

// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
int Steam_Matchmaking_Servers::GetServerCount( EMatchMakingType eType )
{
    VLOG_DEBUG("GetServerCount called - Type: %d", eType);
    return 0;
} 

// Refresh a single server inside of a query (rather than all the servers )
void Steam_Matchmaking_Servers::RefreshServer( EMatchMakingType eType, int iServer )
{
    VLOG_DEBUG("RefreshServer called - Type: %d, Server: %d", eType, iServer);
} 


//-----------------------------------------------------------------------------
// Queries to individual servers directly via IP/Port
//-----------------------------------------------------------------------------

// Request updated ping time and other details from a single server
HServerQuery Steam_Matchmaking_Servers::PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse )
{
    VLOG_DEBUG("PingServer called - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
} 

// Request the list of players currently playing on a server
HServerQuery Steam_Matchmaking_Servers::PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse )
{
    VLOG_DEBUG("PlayerDetails called - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
}

// Request the list of rules that the server is running (See ISteamMasterServerUpdater->SetKeyValue() to set the rules server side)
HServerQuery Steam_Matchmaking_Servers::ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse )
{
    VLOG_DEBUG("ServerRules called - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
}

// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above calls to avoid crashing when callbacks occur.
void Steam_Matchmaking_Servers::CancelServerQuery( HServerQuery hServerQuery )
{
    VLOG_DEBUG("CancelServerQuery called - Query: %d", hServerQuery);
}
