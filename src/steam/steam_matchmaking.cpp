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
#include "steam_matchmaking.h"

CSteamMatchmaking::CSteamMatchmaking()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMatchmaking::~CSteamMatchmaking()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMatchmakingServers::CSteamMatchmakingServers()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamMatchmakingServers::~CSteamMatchmakingServers()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameSearch::CSteamGameSearch()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamGameSearch::~CSteamGameSearch()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamParties::CSteamParties()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamParties::~CSteamParties()
{
    VLOG_INFO(__FUNCTION__);
}

// game server favorites storage
// saves basic details about a multiplayer game server locally

// returns the number of favorites servers the user has stored
int CSteamMatchmaking::GetFavoriteGameCount()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// returns the details of the game server
// iGame is of range [0,GetFavoriteGameCount())
// *pnIP, *pnConnPort are filled in the with IP:port of the game server
// *punFlags specify whether the game server was stored as an explicit favorite or in the history of connections
// *pRTime32LastPlayedOnServer is filled in the with the Unix time the favorite was added
bool CSteamMatchmaking::GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer )
{
    VLOG_INFO(__FUNCTION__ " - Game: %d", iGame);
    return false;
}

// adds the game server to the local list; updates the time played of the server if it already exists in the list
int CSteamMatchmaking::AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, IP: %u, ConnPort: %u, QueryPort: %u", nAppID, nIP, nConnPort, nQueryPort);
    return 0;
}

// removes the game server from the local storage; returns true if one was removed
bool CSteamMatchmaking::RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, IP: %u, ConnPort: %u, QueryPort: %u", nAppID, nIP, nConnPort, nQueryPort);
    return false;
}

///////
// Game lobby functions

// Get a list of relevant lobbies
// this is an asynchronous request
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
STEAM_CALL_RESULT( LobbyMatchList_t )
SteamAPICall_t CSteamMatchmaking::RequestLobbyList()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Changed from Steam SDK v1.03, backward compatibility
void CSteamMatchmaking::DEPRECATED_RequestLobbyList()
{
    VLOG_INFO(__FUNCTION__);
}

// filters for lobbies
// this needs to be called before RequestLobbyList() to take effect
// these are cleared on each call to RequestLobbyList()
// Removed from Steam SDK v1.05, backward compatibility
void CSteamMatchmaking::AddRequestLobbyListFilter( const char *pchKeyToMatch, const char *pchValueToMatch )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %s", pchKeyToMatch, pchValueToMatch);
}

void CSteamMatchmaking::AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %s, Comparison Type: %d", pchKeyToMatch, pchValueToMatch, eComparisonType);
}

// numerical comparison - 0 is equal, -1 is the lobby value is less than nValueToMatch, 1 is the lobby value is greater than nValueToMatch
// Removed from Steam SDK v1.05, backward compatibility
void CSteamMatchmaking::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, int nComparisonType /* 0 is equal, -1 is less than, 1 is greater than */ )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %d, Comparison Type: %d", pchKeyToMatch, nValueToMatch, nComparisonType);
}

void CSteamMatchmaking::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %d, Comparison Type: %d", pchKeyToMatch, nValueToMatch, eComparisonType);
}

// sets RequestLobbyList() to only returns lobbies which aren't yet full - needs SetLobbyMemberLimit() called on the lobby to set an initial limit
// Removed from Steam SDK v1.03, backward compatibility
void CSteamMatchmaking::AddRequestLobbyListSlotsAvailableFilter()
{
    VLOG_INFO(__FUNCTION__);
}

// returns results closest to the specified value. Multiple near filters can be added, with early filters taking precedence
void CSteamMatchmaking::AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %d", pchKeyToMatch, nValueToBeCloseTo);
}

// returns only lobbies with the specified number of slots available
void CSteamMatchmaking::AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable )
{
    VLOG_INFO(__FUNCTION__ " - Slots Available: %d", nSlotsAvailable);
}

// sets the distance for which we should search for lobbies (based on users IP address to location map on the Steam backed)
void CSteamMatchmaking::AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter )
{
    VLOG_INFO(__FUNCTION__ " - Distance Filter: %d", eLobbyDistanceFilter);
}

// sets how many results to return, the lower the count the faster it is to download the lobby results & details to the client
void CSteamMatchmaking::AddRequestLobbyListResultCountFilter( int cMaxResults )
{
    VLOG_INFO(__FUNCTION__ " - Max Results: %d", cMaxResults);
}

void CSteamMatchmaking::AddRequestLobbyListCompatibleMembersFilter( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
}

// returns the CSteamID of a lobby, as retrieved by a RequestLobbyList call
// should only be called after a LobbyMatchList_t callback is received
// iLobby is of the range [0, LobbyMatchList_t::m_nLobbiesMatching)
// the returned CSteamID::IsValid() will be false if iLobby is out of range
CSteamID CSteamMatchmaking::GetLobbyByIndex( int iLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %d", iLobby);
    return CSteamID();
}

// Create a lobby on the Steam servers.
// If private, then the lobby will not be returned by any RequestLobbyList() call; the CSteamID
// of the lobby will need to be communicated via game channels or via InviteUserToLobby()
// this is an asynchronous request
// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this point
// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
STEAM_CALL_RESULT( LobbyCreated_t )
SteamAPICall_t CSteamMatchmaking::CreateLobby( ELobbyType eLobbyType, int cMaxMembers )
{
    VLOG_INFO(__FUNCTION__ " - LobbyType = %d, MaxMembers = %d", eLobbyType, cMaxMembers);
    return 0;
}

// Changed from Steam SDK v1.05, backward compatibility
SteamAPICall_t CSteamMatchmaking::CreateLobby( ELobbyType eLobbyType )
{
    VLOG_INFO(__FUNCTION__ " - LobbyType: %d", eLobbyType);
    return 0;
}

// Changed from Steam SDK v1.03, backward compatibility
void CSteamMatchmaking::CreateLobby( bool bPrivate )
{
    VLOG_INFO(__FUNCTION__ " - Private: %s", bPrivate ? "true" : "false");
}

// Joins an existing lobby
// this is an asynchronous request
// results will be returned by LobbyEnter_t callback & call result, check m_EChatRoomEnterResponse to see if was successful
// lobby metadata is available to use immediately on this call completing
STEAM_CALL_RESULT( LobbyEnter_t )
SteamAPICall_t CSteamMatchmaking::JoinLobby( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu", steamIDLobby.GetAccountID());
    return 0;
}

// Changed from Steam SDK v1.03, backward compatibility
void CSteamMatchmaking::DEPRECATED_JoinLobby( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
}

// Leave a lobby; this will take effect immediately on the client side
// other users in the lobby will be notified by a LobbyChatUpdate_t callback
void CSteamMatchmaking::LeaveLobby( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu", steamIDLobby.GetAccountID());
}

// Invite another user to the lobby
// the target user will receive a LobbyInvite_t callback
// will return true if the invite is successfully sent, whether or not the target responds
// returns false if the local user is not connected to the Steam servers
// if the other user clicks the join link, a GameLobbyJoinRequested_t will be posted if the user is in-game,
// or if the game isn't running yet the game will be launched with the parameter +connect_lobby <64-bit lobby id>
bool CSteamMatchmaking::InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Invitee: %llu", steamIDLobby.GetAccountID(), steamIDInvitee.GetAccountID());
    return false;
}

// Lobby iteration, for viewing details of users in a lobby
// only accessible if the lobby user is a member of the specified lobby
// persona information for other lobby members (name, avatar, etc.) will be asynchronously received
// and accessible via ISteamFriends interface

// returns the number of users in the specified lobby
int CSteamMatchmaking::GetNumLobbyMembers( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
    return 0;
}

// returns the CSteamID of a user in the lobby
// iMember is of range [0,GetNumLobbyMembers())
// note that the current user must be in a lobby to retrieve CSteamIDs of other users in that lobby
CSteamID CSteamMatchmaking::GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Member: %d", steamIDLobby.GetAccountID(), iMember);
    return CSteamID();
}

// Get data associated with this lobby
// takes a simple key, and returns the string associated with it
// "" will be returned if no value is set, or if steamIDLobby is invalid
const char *CSteamMatchmaking::GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Key: %s", steamIDLobby.GetAccountID(), pchKey ? pchKey : "null");
    return "";
}

// Sets a key/value pair in the lobby metadata
// each user in the lobby will be broadcast this new value, and any new users joining will receive any existing data
// this can be used to set lobby names, map, etc.
// to reset a key, just set it to ""
// other users in the lobby will receive notification of the lobby data change via a LobbyDataUpdate_t callback
bool CSteamMatchmaking::SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Key: %s, Value: %s", 
               steamIDLobby.GetAccountID(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
    return true;
}

// returns the number of metadata keys set on the specified lobby
int CSteamMatchmaking::GetLobbyDataCount( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.ConvertToUint64());
    return 0;
}

// returns a lobby metadata key/values pair by index, of range [0, GetLobbyDataCount())
bool CSteamMatchmaking::GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Index: %d, KeySize: %d, ValueSize: %d", 
               steamIDLobby.GetAccountID(), iLobbyData, cchKeyBufferSize, cchValueBufferSize);
    return false;
}

// removes a metadata key from the lobby
bool CSteamMatchmaking::DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Key: %s", steamIDLobby.GetAccountID(), pchKey ? pchKey : "null");
    return false;
}

// Gets per-user metadata for someone in this lobby
const char *CSteamMatchmaking::GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, User: %llu, Key: %s", 
               steamIDLobby.GetAccountID(), steamIDUser.GetAccountID(), pchKey ? pchKey : "null");
    return "";
}

// Sets per-user metadata (for the local user implicitly)
void CSteamMatchmaking::SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, Key: %s, Value: %s", 
               steamIDLobby.GetAccountID(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// Broadcasts a chat message to the all the users in the lobby
// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
// returns true if the message is successfully sent
// pvMsgBody can be binary or text data, up to 4k
// if pvMsgBody is text, cubMsgBody should be strlen( text ) + 1, to include the null terminator
bool CSteamMatchmaking::SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, MsgSize: %d", steamIDLobby.GetAccountID(), cubMsgBody);
    return false;
}

// Get a chat message as specified in a LobbyChatMsg_t callback
// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
// *pSteamIDUser is filled in with the CSteamID of the member
// *pvData is filled in with the message itself
// return value is the number of bytes written into the buffer
int CSteamMatchmaking::GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, STEAM_OUT_STRUCT() CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, ChatID: %d, DataSize: %d", steamIDLobby.GetAccountID(), iChatID, cubData);
    return 0;
}

// Refreshes metadata for a lobby you're not necessarily in right now
// you never do this for lobbies you're a member of, only if your
// this will send down all the metadata associated with a lobby
// this is an asynchronous call
// returns false if the local user is not connected to the Steam servers
// results will be returned by a LobbyDataUpdate_t callback
// if the specified lobby doesn't exist, LobbyDataUpdate_t::m_bSuccess will be set to false
bool CSteamMatchmaking::RequestLobbyData( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
    return false;
}

// sets the game server associated with the lobby
// usually at this point, the users will join the specified game server
// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
void CSteamMatchmaking::SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu, ServerIP = %u, ServerPort = %u, GameServer = %llu", 
               steamIDLobby.GetAccountID(), unGameServerIP, unGameServerPort, steamIDGameServer.GetAccountID());
}

// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
bool CSteamMatchmaking::GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, STEAM_OUT_STRUCT() CSteamID *psteamIDGameServer )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, ServerIP: %u, ServerPort: %u, GameServer: %llu", 
               steamIDLobby.GetAccountID(), punGameServerIP, punGameServerPort, psteamIDGameServer->GetAccountID());
    return false;
}

// set the limit on the # of users who can join the lobby
bool CSteamMatchmaking::SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, MaxMembers: %d", steamIDLobby.GetAccountID(), cMaxMembers);
    return false;
}

// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
int CSteamMatchmaking::GetLobbyMemberLimit( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
    return 0;
}

// asks the Steam servers for a list of lobbies that friends are in
// returns results by posting one RequestFriendsLobbiesResponse_t callback per friend/lobby pair
// if no friends are in lobbies, RequestFriendsLobbiesResponse_t will be posted but with 0 results
// filters don't apply to lobbies (currently)
// Removed from Steam SDK v1.03, backward compatibility
bool CSteamMatchmaking::RequestFriendsLobbies()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// updates which type of lobby it is
// only lobbies that are k_ELobbyTypePublic or k_ELobbyTypeInvisible, and are set to joinable, will be returned by RequestLobbyList() calls
bool CSteamMatchmaking::SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu, Type = %d", steamIDLobby.GetAccountID(), eLobbyType);
    return false;
}

// sets whether or not a lobby is joinable - defaults to true for a new lobby
// if set to false, no user can join, even if they are a friend or have been invited
bool CSteamMatchmaking::SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu, Joinable = %s", steamIDLobby.GetAccountID(), bLobbyJoinable ? "true" : "false");
    return false;
}

// returns the current lobby owner
// you must be a member of the lobby to access this
// there always one lobby owner - if the current owner leaves, another user will become the owner
// it is possible (bur rare) to join a lobby just as the owner is leaving, thus entering a lobby with self as the owner
CSteamID CSteamMatchmaking::GetLobbyOwner( CSteamID steamIDLobby )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu", steamIDLobby.GetAccountID());
    return CSteamID();
}

// changes who the lobby owner is
// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
// after completion, the local user will no longer be the owner
bool CSteamMatchmaking::SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner )
{
    VLOG_INFO(__FUNCTION__ " - Lobby = %llu, NewOwner = %llu", steamIDLobby.GetAccountID(), steamIDNewOwner.GetAccountID());
    return false;
}

// link two lobbies for the purposes of checking player compatibility
// you must be the lobby owner of both lobbies
bool CSteamMatchmaking::SetLinkedLobby( CSteamID steamIDLobby, CSteamID steamIDLobbyDependent )
{
    VLOG_INFO(__FUNCTION__ " - Lobby: %llu, DependentLobby: %llu", steamIDLobby.GetAccountID(), steamIDLobbyDependent.GetAccountID());
    return false;
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
// Removed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServerListResponse::ServerResponded( int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Server: %d", iServer);
} 

// Server has failed to respond
// Removed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServerListResponse::ServerFailedToRespond( int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Server: %d", iServer);
} 

// A list refresh you had initiated is now 100% completed
// Removed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServerListResponse::RefreshComplete( EMatchMakingServerResponse response )
{
    VLOG_INFO(__FUNCTION__ " - Response: %d", response);
} 

// Server has responded ok with updated data
void CSteamMatchmakingServerListResponse::ServerResponded( HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d, Server: %d", hRequest, iServer);
} 

// Server has failed to respond
void CSteamMatchmakingServerListResponse::ServerFailedToRespond( HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d, Server: %d", hRequest, iServer);
} 

// A list refresh you had initiated is now 100% completed
void CSteamMatchmakingServerListResponse::RefreshComplete( HServerListRequest hRequest, EMatchMakingServerResponse response )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d, Response: %d", hRequest, response);
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
void CSteamMatchmakingPingResponse::ServerResponded( gameserveritem_t &server )
{
    VLOG_INFO(__FUNCTION__ " - Server: %d", server.m_nPing);
}

// Server failed to respond to the ping request
void CSteamMatchmakingPingResponse::ServerFailedToRespond()
{
    VLOG_INFO(__FUNCTION__);
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
void CSteamMatchmakingPlayersResponse::AddPlayerToList( const char *pchName, int nScore, float flTimePlayed )
{
    VLOG_INFO(__FUNCTION__ " - Name: %s, Score: %d, TimePlayed: %f", pchName, nScore, flTimePlayed);
}

// The server failed to respond to the request for player details
void CSteamMatchmakingPlayersResponse::PlayersFailedToRespond()
{
    VLOG_INFO(__FUNCTION__);
}

// The server has finished responding to the player details request 
// (ie, you won't get anymore AddPlayerToList callbacks)
void CSteamMatchmakingPlayersResponse::PlayersRefreshComplete()
{
    VLOG_INFO(__FUNCTION__);
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
void CSteamMatchmakingRulesResponse::RulesResponded( const char *pchRule, const char *pchValue )
{
    VLOG_INFO(__FUNCTION__ " - Rule: %s, Value: %s", pchRule, pchValue);
}

// The server failed to respond to the request for rule details
void CSteamMatchmakingRulesResponse::RulesFailedToRespond()
{
    VLOG_INFO(__FUNCTION__);
}

// The server has finished responding to the rule details request 
// (ie, you won't get anymore RulesResponded callbacks)
void CSteamMatchmakingRulesResponse::RulesRefreshComplete()
{
    VLOG_INFO(__FUNCTION__);
}

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
//-----------------------------------------------------------------------------
// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
void CSteamMatchmakingServers::RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void CSteamMatchmakingServers::RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Response: %p", iApp, pRequestServersResponse);
}

void CSteamMatchmakingServers::RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void CSteamMatchmakingServers::RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void CSteamMatchmakingServers::RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

void CSteamMatchmakingServers::RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
}

// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
// Each call allocates a new asynchronous request object.
// Request object must be released by calling ReleaseRequest( hServerListRequest )
HServerListRequest CSteamMatchmakingServers::RequestInternetServerList( AppId_t iApp, STEAM_ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
    return 0;
}

HServerListRequest CSteamMatchmakingServers::RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Response: %p", iApp, pRequestServersResponse);
    return 0;
}

HServerListRequest CSteamMatchmakingServers::RequestFriendsServerList( AppId_t iApp, STEAM_ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
    return 0;
}

HServerListRequest CSteamMatchmakingServers::RequestFavoritesServerList( AppId_t iApp, STEAM_ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
    return 0;
}

HServerListRequest CSteamMatchmakingServers::RequestHistoryServerList( AppId_t iApp, STEAM_ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
    return 0;
}

HServerListRequest CSteamMatchmakingServers::RequestSpectatorServerList( AppId_t iApp, STEAM_ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Filters: %d, Response: %p", iApp, nFilters, pRequestServersResponse);
    return 0;
}

// Releases the asynchronous request object and cancels any pending query on it if there's a pending query in progress.
// RefreshComplete callback is not posted when request is released.
void CSteamMatchmakingServers::ReleaseRequest( HServerListRequest hServerListRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d", hServerListRequest);
}

/* the filter operation codes that go in the key part of MatchMakingKeyValuePair_t should be one of these:

	"map"
		- Server passes the filter if the server is playing the specified map.
	"gamedataand"
		- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains all of the
		specified strings.  The value field is a comma-delimited list of strings to match.
	"gamedataor"
		- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains at least one of the
		specified strings.  The value field is a comma-delimited list of strings to match.
	"gamedatanor"
		- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) does not contain any
		of the specified strings.  The value field is a comma-delimited list of strings to check.
	"gametagsand"
		- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) contains all
		of the specified strings.  The value field is a comma-delimited list of strings to check.
	"gametagsnor"
		- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) does not contain any
		of the specified strings.  The value field is a comma-delimited list of strings to check.
	"and" (x1 && x2 && ... && xn)
	"or" (x1 || x2 || ... || xn)
	"nand" !(x1 && x2 && ... && xn)
	"nor" !(x1 || x2 || ... || xn)
		- Performs Boolean operation on the following filters.  The operand to this filter specifies
		the "size" of the Boolean inputs to the operation, in Key/value pairs.  (The keyvalue
		pairs must immediately follow, i.e. this is a prefix logical operator notation.)
		In the simplest case where Boolean expressions are not nested, this is simply
		the number of operands.

		For example, to match servers on a particular map or with a particular tag, would would
		use these filters.

			( server.map == "cp_dustbowl" || server.gametags.contains("payload") )
			"or", "2"
			"map", "cp_dustbowl"
			"gametagsand", "payload"

		If logical inputs are nested, then the operand specifies the size of the entire
		"length" of its operands, not the number of immediate children.

			( server.map == "cp_dustbowl" || ( server.gametags.contains("payload") && !server.gametags.contains("payloadrace") ) )
			"or", "4"
			"map", "cp_dustbowl"
			"and", "2"
			"gametagsand", "payload"
			"gametagsnor", "payloadrace"

		Unary NOT can be achieved using either "nand" or "nor" with a single operand.

	"addr"
		- Server passes the filter if the server's query address matches the specified IP or IP:port.
	"gameaddr"
		- Server passes the filter if the server's game address matches the specified IP or IP:port.

	The following filter operations ignore the "value" part of MatchMakingKeyValuePair_t

	"dedicated"
		- Server passes the filter if it passed true to SetDedicatedServer.
	"secure"
		- Server passes the filter if the server is VAC-enabled.
	"notfull"
		- Server passes the filter if the player count is less than the reported max player count.
	"hasplayers"
		- Server passes the filter if the player count is greater than zero.
	"noplayers"
		- Server passes the filter if it doesn't have any players.
	"linux"
		- Server passes the filter if it's a linux server
*/

// Get details on a given server in the list, you can get the valid range of index
// values by calling GetServerCount().  You will also receive index values in 
// ISteamMatchmakingServerListResponse::ServerResponded() callbacks
gameserveritem_t *CSteamMatchmakingServers::GetServerDetails( HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d, Server: %d", hRequest, iServer);
    return nullptr;
} 

// Changed from Steam SDK v1.06, backward compatibility
gameserveritem_t *CSteamMatchmakingServers::GetServerDetails( EMatchMakingType eType, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d, Server: %d", eType, iServer);
    return nullptr;
} 

// Cancel an request which is operation on the given list type.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above list request calls.  Not doing so may result in a crash when a callback
// occurs on the destructed object.
// Canceling a query does not release the allocated request handle.
// The request handle must be released using ReleaseRequest( hRequest )
void CSteamMatchmakingServers::CancelQuery( HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d", hRequest);
} 

// Changed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServers::CancelQuery( EMatchMakingType eType )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d", eType);
} 

// Ping every server in your list again but don't update the list of servers
// Query callback installed when the server list was requested will be used
// again to post notifications and RefreshComplete, so the callback must remain
// valid until another RefreshComplete is called on it or the request
// is released with ReleaseRequest( hRequest )
void CSteamMatchmakingServers::RefreshQuery( HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d", hRequest);
} 

// Changed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServers::RefreshQuery( EMatchMakingType eType )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d", eType);
} 

// Returns true if the list is currently refreshing its server list
bool CSteamMatchmakingServers::IsRefreshing( HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d", hRequest);
    return false;
} 

// Changed from Steam SDK v1.06, backward compatibility
bool CSteamMatchmakingServers::IsRefreshing( EMatchMakingType eType )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d", eType);
    return false;
} 

// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
int CSteamMatchmakingServers::GetServerCount( HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d", hRequest);
    return 0;
} 

// Changed from Steam SDK v1.06, backward compatibility
int CSteamMatchmakingServers::GetServerCount( EMatchMakingType eType )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d", eType);
    return 0;
}

// Refresh a single server inside of a query (rather than all the servers )
void CSteamMatchmakingServers::RefreshServer( HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Request: %d, Server: %d", hRequest, iServer);
} 

// Changed from Steam SDK v1.06, backward compatibility
void CSteamMatchmakingServers::RefreshServer( EMatchMakingType eType, int iServer )
{
    VLOG_INFO(__FUNCTION__ " - Type: %d, Server: %d", eType, iServer);
} 


//-----------------------------------------------------------------------------
// Queries to individual servers directly via IP/Port
//-----------------------------------------------------------------------------

// Request updated ping time and other details from a single server
HServerQuery CSteamMatchmakingServers::PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
} 

// Request the list of players currently playing on a server
HServerQuery CSteamMatchmakingServers::PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
}

// Request the list of rules that the server is running (See ISteamGameServer::SetKeyValue() to set the rules server side)
HServerQuery CSteamMatchmakingServers::ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, Response: %p", unIP, usPort, pRequestServersResponse);
    return 0;
}

// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above calls to avoid crashing when callbacks occur.
void CSteamMatchmakingServers::CancelServerQuery( HServerQuery hServerQuery )
{
    VLOG_INFO(__FUNCTION__ " - Query: %d", hServerQuery);
}

// =============================================================================================
// Game Player APIs

// a keyname and a list of comma separated values: one of which is must be found in order for the match to qualify
// fails if a search is currently in progress
EGameSearchErrorCode_t CSteamGameSearch::AddGameSearchParams(const char *pchKeyToFind, const char *pchValuesToFind)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// all players in lobby enter the queue and await a SearchForGameNotificationCallback_t callback. fails if another search is currently in progress
// if not the owner of the lobby or search already in progress this call fails
// periodic callbacks will be sent as queue time estimates change
EGameSearchErrorCode_t CSteamGameSearch::SearchForGameWithLobby(CSteamID steamIDLobby, int nPlayerMin, int nPlayerMax)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// user enter the queue and await a SearchForGameNotificationCallback_t callback. fails if another search is currently in progress
// periodic callbacks will be sent as queue time estimates change
EGameSearchErrorCode_t CSteamGameSearch::SearchForGameSolo(int nPlayerMin, int nPlayerMax)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// after receiving SearchForGameResultCallback_t, accept or decline the game
// multiple SearchForGameResultCallback_t will follow as players accept game until the host starts or cancels the game
EGameSearchErrorCode_t CSteamGameSearch::AcceptGame()
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

EGameSearchErrorCode_t CSteamGameSearch::DeclineGame()
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// after receiving GameStartedByHostCallback_t get connection details to server
EGameSearchErrorCode_t CSteamGameSearch::RetrieveConnectionDetails(CSteamID steamIDHost, char *pchConnectionDetails, int cubConnectionDetails)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// leaves queue if still waiting
EGameSearchErrorCode_t CSteamGameSearch::EndGameSearch()
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// =============================================================================================
// Game Host APIs

// a keyname and a list of comma separated values: all the values you allow
EGameSearchErrorCode_t CSteamGameSearch::SetGameHostParams(const char *pchKey, const char *pchValue)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// set connection details for players once game is found so they can connect to this server
EGameSearchErrorCode_t CSteamGameSearch::SetConnectionDetails(const char *pchConnectionDetails, int cubConnectionDetails)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// mark server as available for more players with nPlayerMin,nPlayerMax desired
// accept no lobbies with playercount greater than nMaxTeamSize
// the set of lobbies returned must be partitionable into teams of no more than nMaxTeamSize
// RequestPlayersForGameNotificationCallback_t callback will be sent when the search has started
// multple RequestPlayersForGameResultCallback_t callbacks will follow when players are found
EGameSearchErrorCode_t CSteamGameSearch::RequestPlayersForGame(int nPlayerMin, int nPlayerMax, int nMaxTeamSize)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// accept the player list and release connection details to players
// players will only be given connection details and host steamid when this is called
// ( allows host to accept after all players confirm, some confirm, or none confirm. decision is entirely up to the host )
EGameSearchErrorCode_t CSteamGameSearch::HostConfirmGameStart(uint64 ullUniqueGameID)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// cancel request and leave the pool of game hosts looking for players
// if a set of players has already been sent to host, all players will receive SearchForGameHostFailedToConfirm_t
EGameSearchErrorCode_t CSteamGameSearch::CancelRequestPlayersForGame()
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// submit a result for one player. does not end the game. ullUniqueGameID continues to describe this game
EGameSearchErrorCode_t CSteamGameSearch::SubmitPlayerResult(uint64 ullUniqueGameID, CSteamID steamIDPlayer, EPlayerResult_t EPlayerResult)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// ends the game. no further SubmitPlayerResults for ullUniqueGameID will be accepted
// any future requests will provide a new ullUniqueGameID
EGameSearchErrorCode_t CSteamGameSearch::EndGame(uint64 ullUniqueGameID)
{
    return k_EGameSearchErrorCode_Failed_Offline;
}

// =============================================================================================
// Party Client APIs

// Enumerate any active beacons for parties you may wish to join
uint32 CSteamParties::GetNumActiveBeacons()
{
    return 0;
}

PartyBeaconID_t CSteamParties::GetBeaconByIndex(uint32 unIndex)
{
    return k_ulPartyBeaconIdInvalid;
}

bool CSteamParties::GetBeaconDetails(PartyBeaconID_t ulBeaconID, CSteamID *pSteamIDBeaconOwner, STEAM_OUT_STRUCT() SteamPartyBeaconLocation_t *pLocation, STEAM_OUT_STRING_COUNT(cchMetadata) char *pchMetadata, int cchMetadata)
{
    return false;
}

// Join an open party. Steam will reserve one beacon slot for your SteamID,
// and return the necessary JoinGame string for you to use to connect
STEAM_CALL_RESULT(JoinPartyCallback_t)
SteamAPICall_t CSteamParties::JoinParty(PartyBeaconID_t ulBeaconID)
{
    return k_uAPICallInvalid;
}

// =============================================================================================
// Party Host APIs

// Get a list of possible beacon locations
bool CSteamParties::GetNumAvailableBeaconLocations(uint32 *puNumLocations)
{
    return false;
}

bool CSteamParties::GetAvailableBeaconLocations(SteamPartyBeaconLocation_t *pLocationList, uint32 uMaxNumLocations)
{
    return false;
}

// Create a new party beacon and activate it in the selected location.
// unOpenSlots is the maximum number of users that Steam will send to you.
// When people begin responding to your beacon, Steam will send you
// PartyReservationCallback_t callbacks to let you know who is on the way.
STEAM_CALL_RESULT(CreateBeaconCallback_t)
SteamAPICall_t CSteamParties::CreateBeacon(uint32 unOpenSlots, SteamPartyBeaconLocation_t *pBeaconLocation, const char *pchConnectString, const char *pchMetadata)
{
    return k_uAPICallInvalid;
}

// Call this function when a user that had a reservation (see callback below) 
// has successfully joined your party.
// Steam will manage the remaining open slots automatically.
void CSteamParties::OnReservationCompleted(PartyBeaconID_t ulBeacon, CSteamID steamIDUser)
{
}

// To cancel a reservation (due to timeout or user input), call this.
// Steam will open a new reservation slot.
// Note: The user may already be in-flight to your game, so it's possible they will still connect and try to join your party.
void CSteamParties::CancelReservation(PartyBeaconID_t ulBeacon, CSteamID steamIDUser)
{
}

// Change the number of open beacon reservation slots.
// Call this if, for example, someone without a reservation joins your party (eg a friend, or via your own matchmaking system).
STEAM_CALL_RESULT(ChangeNumOpenSlotsCallback_t)
SteamAPICall_t CSteamParties::ChangeNumOpenSlots(PartyBeaconID_t ulBeacon, uint32 unOpenSlots)
{
    return k_uAPICallInvalid;
}

// Turn off the beacon. 
bool CSteamParties::DestroyBeacon(PartyBeaconID_t ulBeacon)
{
    return false;
}

// Utils
bool CSteamParties::GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eData, STEAM_OUT_STRING_COUNT(cchDataStringOut) char *pchDataStringOut, int cchDataStringOut)
{
    return false;
}
