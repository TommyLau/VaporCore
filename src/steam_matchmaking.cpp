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
void Steam_Matchmaking::RequestLobbyList()
{
    VLOG_DEBUG("RequestLobbyList called");
}

// filters for lobbies
// this needs to be called before RequestLobbyList() to take effect
// these are cleared on each call to RequestLobbyList()
void Steam_Matchmaking::AddRequestLobbyListFilter( const char *pchKeyToMatch, const char *pchValueToMatch )
{
    VLOG_DEBUG("AddRequestLobbyListFilter called - Key: %s, Value: %s", pchKeyToMatch, pchValueToMatch);
}

// numerical comparison - 0 is equal, -1 is the lobby value is less than nValueToMatch, 1 is the lobby value is greater than nValueToMatch
void Steam_Matchmaking::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, int nComparisonType /* 0 is equal, -1 is less than, 1 is greater than */ )
{
    VLOG_DEBUG("AddRequestLobbyListNumericalFilter called - Key: %s, Value: %d, Comparison Type: %d", pchKeyToMatch, nValueToMatch, nComparisonType);
}

// sets RequestLobbyList() to only returns lobbies which aren't yet full - needs SetLobbyMemberLimit() called on the lobby to set an initial limit
void Steam_Matchmaking::AddRequestLobbyListSlotsAvailableFilter()
{
    VLOG_DEBUG("AddRequestLobbyListSlotsAvailableFilter called");
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
void Steam_Matchmaking::CreateLobby( bool bPrivate )
{
    VLOG_DEBUG("CreateLobby called - Private: %s", bPrivate ? "true" : "false");
}

// Joins an existing lobby
// this is an asynchronous request
// results will be returned by LobbyEnter_t callback when the lobby has been joined
void Steam_Matchmaking::JoinLobby( CSteamID steamIDLobby )
{
    VLOG_DEBUG("JoinLobby called - Lobby: %llu", steamIDLobby.ConvertToUint64());
}

// Leave a lobby; this will take effect immediately on the client side
// other users in the lobby will be notified by a LobbyChatUpdate_t callback
void Steam_Matchmaking::LeaveLobby( CSteamID steamIDLobby )
{
    VLOG_DEBUG("LeaveLobby called - Lobby: %llu", steamIDLobby.ConvertToUint64());
}

// Invite another user to the lobby
// the target user will receive a LobbyInvite_t callback
// will return true if the invite is successfully sent, whether or not the target responds
// returns false if the local user is not connected to the Steam servers
bool Steam_Matchmaking::InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
{
    VLOG_DEBUG("InviteUserToLobby called - Lobby: %llu, Invitee: %llu", steamIDLobby.ConvertToUint64(), steamIDInvitee.ConvertToUint64());
    return false;
}

// returns the number of users in the specified lobby
int Steam_Matchmaking::GetNumLobbyMembers( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetNumLobbyMembers called - Lobby: %llu", steamIDLobby.ConvertToUint64());
    return 0;
}

// returns the CSteamID of a user in the lobby
// iMember is of range [0,GetNumLobbyMembers())
CSteamID Steam_Matchmaking::GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember )
{
    VLOG_DEBUG("GetLobbyMemberByIndex called - Lobby: %llu, Member: %d", steamIDLobby.ConvertToUint64(), iMember);
    return CSteamID();
}

// Get data associated with this lobby
// takes a simple key, and returns the string associated with it
// "" will be returned if no value is set, or if steamIDLobby is invalid
const char *Steam_Matchmaking::GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
    VLOG_DEBUG("GetLobbyData called - Lobby: %llu, Key: %s", steamIDLobby.ConvertToUint64(), pchKey ? pchKey : "null");
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
               steamIDLobby.ConvertToUint64(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
    return true;
}

// As above, but gets per-user data for someone in this lobby
const char *Steam_Matchmaking::GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
{
    VLOG_DEBUG("GetLobbyMemberData called - Lobby: %llu, User: %llu, Key: %s", 
               steamIDLobby.ConvertToUint64(), steamIDUser.ConvertToUint64(), pchKey ? pchKey : "null");
    return "";
}

// Sets per-user metadata (for the local user implicitly)
void Steam_Matchmaking::SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("SetLobbyMemberData called - Lobby: %llu, Key: %s, Value: %s", 
               steamIDLobby.ConvertToUint64(), pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// Broadcasts a chat message to the all the users in the lobby
// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
// returns true if the message is successfully sent
bool Steam_Matchmaking::SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
{
    VLOG_DEBUG("SendLobbyChatMsg called - Lobby: %llu, MsgSize: %d", steamIDLobby.ConvertToUint64(), cubMsgBody);
    return false;
}

// Get a chat message as specified in a LobbyChatMsg_t callback
// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
// *pSteamIDUser is filled in with the CSteamID of the member
// *pvData is filled in with the message itself
// return value is the number of bytes written into the buffer
int Steam_Matchmaking::GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
    VLOG_DEBUG("GetLobbyChatEntry called - Lobby: %llu, ChatID: %d, DataSize: %d", steamIDLobby.ConvertToUint64(), iChatID, cubData);
    return 0;
}

// Fetch metadata for a lobby you're not necessarily in right now
// this will send down all the metadata associated with a lobby
// this is an asynchronous call
// returns false if the local user is not connected to the Steam servers
bool Steam_Matchmaking::RequestLobbyData( CSteamID steamIDLobby )
{
    VLOG_DEBUG("RequestLobbyData called - Lobby: %llu", steamIDLobby.ConvertToUint64());
    return false;
}

// sets the game server associated with the lobby
// usually at this point, the users will leave the lobby and join the specified game server
// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
void Steam_Matchmaking::SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
{
    VLOG_DEBUG("SetLobbyGameServer called - Lobby: %llu, ServerIP: %u, ServerPort: %u, GameServer: %llu", 
               steamIDLobby.ConvertToUint64(), unGameServerIP, unGameServerPort, steamIDGameServer.ConvertToUint64());
}

// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
bool Steam_Matchmaking::GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer )
{
    VLOG_DEBUG("GetLobbyGameServer called - Lobby: %llu, ServerIP: %u, ServerPort: %u, GameServer: %llu", 
               steamIDLobby.ConvertToUint64(), punGameServerIP, punGameServerPort, psteamIDGameServer->ConvertToUint64());
    return false;
}

// set the limit on the # of users who can join the lobby
bool Steam_Matchmaking::SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
{
    VLOG_DEBUG("SetLobbyMemberLimit called - Lobby: %llu, MaxMembers: %d", steamIDLobby.ConvertToUint64(), cMaxMembers);
    return false;
}

// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
int Steam_Matchmaking::GetLobbyMemberLimit( CSteamID steamIDLobby )
{
    VLOG_DEBUG("GetLobbyMemberLimit called - Lobby: %llu", steamIDLobby.ConvertToUint64());
    return 0;
}

// asks the Steam servers for a list of lobbies that friends are in
// returns results by posting one RequestFriendsLobbiesResponse_t callback per friend/lobby pair
// if no friends are in lobbies, RequestFriendsLobbiesResponse_t will be posted but with 0 results
// filters don't apply to lobbies (currently)
bool Steam_Matchmaking::RequestFriendsLobbies()
{
    VLOG_DEBUG("RequestFriendsLobbies called");
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

