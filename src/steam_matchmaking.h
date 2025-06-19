/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_MATCHMAKING_H
#define VAPORCORE_STEAM_MATCHMAKING_H
#ifdef _WIN32
#pragma once
#endif

#include "../include/sdk/isteammatchmaking.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//			and to operate on game lobbies.
//-----------------------------------------------------------------------------
class Steam_Matchmaking : public ISteamMatchmaking
{
public:
    Steam_Matchmaking();
    ~Steam_Matchmaking();

	// returns the number of favorites servers the user has stored
	int GetFavoriteGameCount() override;
	
	// returns the details of the game server
	// iGame is of range [0,GetFavoriteGameCount())
	// *pnIP, *pnConnPort are filled in the with IP:port of the game server
	// *punFlags specify whether the game server was stored as an explicit favorite or in the history of connections
	// *pRTime32LastPlayedOnServer is filled in the with the Unix time the favorite was added
	bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer ) override;

	// adds the game server to the local list; updates the time played of the server if it already exists in the list
	int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer ) override;
	
	// removes the game server from the local storage; returns true if one was removed
    bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags ) override;

	// Get a list of relevant lobbies
	// this is an asynchronous request
	// results will be returned by LobbyMatchList_t callback, with the number of servers requested
	// if the user is not currently connected to Steam (i.e. SteamUser()->BLoggedOn() returns false) then
	// a LobbyMatchList_t callback will be posted immediately with no servers
	void RequestLobbyList() override;

	// returns the CSteamID of a lobby, as retrieved by a RequestLobbyList call
	// should only be called after a LobbyMatchList_t callback is received
	// iLobby is of the range [0, LobbyMatchList_t::m_nLobbiesMatching)
	// the returned CSteamID::IsValid() will be false if iLobby is out of range
	CSteamID GetLobbyByIndex( int iLobby ) override;

	// Create a lobby on the Steam servers.
	// If bPrivate is true, then the lobby will not be returned by any RequestLobbyList() call; the CSteamID
	// of the lobby will need to be communicated via game channels or via InviteUserToLobby()
	// this is an asynchronous request
	// results will be returned by LobbyCreated_t callback when the lobby has been created;
	// local user will the join the lobby, resulting in an additional LobbyEnter_t callback being sent
	// operations on the chat room can only proceed once the LobbyEnter_t has been received
	void CreateLobby( bool bPrivate ) override;

	// Joins an existing lobby
	// this is an asynchronous request
	// results will be returned by LobbyEnter_t callback when the lobby has been joined
	void JoinLobby( CSteamID steamIDLobby ) override;

	// Leave a lobby; this will take effect immediately on the client side
	// other users in the lobby will be notified by a LobbyChatUpdate_t callback
	void LeaveLobby( CSteamID steamIDLobby ) override;

	// Invite another user to the lobby
	// the target user will receive a LobbyInvite_t callback
	// will return true if the invite is successfully sent, whether or not the target responds
	// returns false if the local user is not connected to the Steam servers
	bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee ) override;

	// returns the number of users in the specified lobby
	int GetNumLobbyMembers( CSteamID steamIDLobby ) override;
	// returns the CSteamID of a user in the lobby
	// iMember is of range [0,GetNumLobbyMembers())
	CSteamID GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember ) override;

	// Get data associated with this lobby
	// takes a simple key, and returns the string associated with it
	// "" will be returned if no value is set, or if steamIDLobby is invalid
	const char *GetLobbyData( CSteamID steamIDLobby, const char *pchKey ) override;
	// Sets a key/value pair in the lobby metadata
	// each user in the lobby will be broadcast this new value, and any new users joining will receive any existing data
	// this can be used to set lobby names, map, etc.
	// to reset a key, just set it to ""
	// other users in the lobby will receive notification of the lobby data change via a LobbyDataUpdate_t callback
	bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) override;

	// As above, but gets per-user data for someone in this lobby
	const char *GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey ) override;
	// Sets per-user metadata (for the local user implicitly)
	void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) override;
	
	// Broadcasts a chat message to the all the users in the lobby
	// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
	// returns true if the message is successfully sent
	bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody ) override;
	// Get a chat message as specified in a LobbyChatMsg_t callback
	// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
	// *pSteamIDUser is filled in with the CSteamID of the member
	// *pvData is filled in with the message itself
	// return value is the number of bytes written into the buffer
	int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType ) override;

	// Fetch metadata for a lobby you're not necessarily in right now
	// this will send down all the metadata associated with a lobby
	// this is an asynchronous call
	// returns false if the local user is not connected to the Steam servers
	bool RequestLobbyData( CSteamID steamIDLobby ) override;
	
	// sets the game server associated with the lobby
	// usually at this point, the users will leave the lobby and join the specified game server
	// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
	void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer ) override;

    // Helper methods
    static Steam_Matchmaking* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Matchmaking* s_pInstance;
};

#endif // VAPORCORE_STEAM_MATCHMAKING_H

