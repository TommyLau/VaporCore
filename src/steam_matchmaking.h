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

#include <isteammatchmaking.h>
#include <isteammatchmaking002.h>
#include <isteammatchmaking004.h>
#include <isteammatchmaking006.h>
#include <isteammatchmaking007.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//			and to operate on game lobbies.
//-----------------------------------------------------------------------------
class Steam_Matchmaking :
	public ISteamMatchmaking,
    public ISteamMatchmaking002,
    public ISteamMatchmaking004,
    public ISteamMatchmaking006,
    public ISteamMatchmaking007
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
	// Changed from Steam SDK v1.03, backward compatibility
	void DEPRECATED_RequestLobbyList() override;
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
	SteamAPICall_t RequestLobbyList() override;

	// filters for lobbies
	// this needs to be called before RequestLobbyList() to take effect
	// these are cleared on each call to RequestLobbyList()
	// Removed from Steam SDK v1.05, backward compatibility
	void AddRequestLobbyListFilter( const char *pchKeyToMatch, const char *pchValueToMatch ) override;
	void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType ) override;
	// numerical comparison - 0 is equal, -1 is the lobby value is less than nValueToMatch, 1 is the lobby value is greater than nValueToMatch
	// Removed from Steam SDK v1.05, backward compatibility
	void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, int nComparisonType /* 0 is equal, -1 is less than, 1 is greater than */ ) override;
	void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType ) override;
	// sets RequestLobbyList() to only returns lobbies which aren't yet full - needs SetLobbyMemberLimit() called on the lobby to set an initial limit
	// Removed from Steam SDK v1.03, backward compatibility
	void AddRequestLobbyListSlotsAvailableFilter() override;
	// returns results closest to the specified value. Multiple near filters can be added, with early filters taking precedence
	void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo ) override;
	// returns only lobbies with the specified number of slots available
	void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable ) override;
	// sets the distance for which we should search for lobbies (based on users IP address to location map on the Steam backed)
	void AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter ) override;
	// sets how many results to return, the lower the count the faster it is to download the lobby results & details to the client
	void AddRequestLobbyListResultCountFilter( int cMaxResults ) override;

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
	// Changed from Steam SDK v1.05, backward compatibility
	void CreateLobby( bool bPrivate ) override;
	SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int cMaxMembers ) override;
	// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this pointer
	// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
	SteamAPICall_t CreateLobby( ELobbyType eLobbyType ) override;

	// Joins an existing lobby
	// this is an asynchronous request
	// results will be returned by LobbyEnter_t callback when the lobby has been joined
	// Removed from Steam SDK v1.03, backward compatibility
	void DEPRECATED_JoinLobby( CSteamID steamIDLobby ) override;
	// results will be returned by LobbyEnter_t callback & call result, check m_EChatRoomEnterResponse to see if was successful
	// lobby metadata is available to use immediately on this call completing
	SteamAPICall_t JoinLobby( CSteamID steamIDLobby ) override;

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

	// returns the number of metadata keys set on the specified lobby
	int GetLobbyDataCount( CSteamID steamIDLobby ) override;

	// returns a lobby metadata key/values pair by index, of range [0, GetLobbyDataCount())
	bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize ) override;

	// removes a metadata key from the lobby
	bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey ) override;

	// Gets per-user metadata for someone in this lobby
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
	// results will be returned by a LobbyDataUpdate_t callback
	// if the specified lobby doesn't exist, LobbyDataUpdate_t::m_bSuccess will be set to false
	bool RequestLobbyData( CSteamID steamIDLobby ) override;
	
	// sets the game server associated with the lobby
	// usually at this point, the users will leave the lobby and join the specified game server
	// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
	void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer ) override;
	// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
	bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer ) override;

	// set the limit on the # of users who can join the lobby
	bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers ) override;
	// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
	int GetLobbyMemberLimit( CSteamID steamIDLobby ) override;

	// asks the Steam servers for a list of lobbies that friends are in
	// returns results by posting one RequestFriendsLobbiesResponse_t callback per friend/lobby pair
	// if no friends are in lobbies, RequestFriendsLobbiesResponse_t will be posted but with 0 results
	// filters don't apply to lobbies (currently)
	// Removed from Steam SDK v1.03, backward compatibility
	bool RequestFriendsLobbies() override;

	// updates which type of lobby it is
	// only lobbies that are k_ELobbyTypePublic will be returned by RequestLobbyList() calls
	bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType ) override;

	// sets whether or not a lobby is joinable - defaults to true for a new lobby
	// if set to false, no user can join, even if they are a friend or have been invited
	bool SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable ) override;

	// returns the current lobby owner
	// you must be a member of the lobby to access this
	// there always one lobby owner - if the current owner leaves, another user will become the owner
	// it is possible (bur rare) to join a lobby just as the owner is leaving, thus entering a lobby with self as the owner
	CSteamID GetLobbyOwner( CSteamID steamIDLobby ) override;

	// changes who the lobby owner is
	// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
	// after completion, the local user will no longer be the owner
	bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner ) override;

    // Helper methods
    static Steam_Matchmaking* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Matchmaking* s_pInstance;
};

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
class Steam_Matchmaking_Server_List_Response :
	public ISteamMatchmakingServerListResponse,
	public ISteamMatchmakingServerListResponse001
{
public:
	// Server has responded ok with updated data
	// Removed from Steam SDK v1.06, backward compatibility
	void ServerResponded( int iServer ) override;

	// Server has failed to respond
	// Removed from Steam SDK v1.06, backward compatibility
	void ServerFailedToRespond( int iServer ) override; 

	// A list refresh you had initiated is now 100% completed
	// Removed from Steam SDK v1.06, backward compatibility
	void RefreshComplete( EMatchMakingServerResponse response ) override; 
	
	// Server has responded ok with updated data
	void ServerResponded( HServerListRequest hRequest, int iServer ) override; 

	// Server has failed to respond
	void ServerFailedToRespond( HServerListRequest hRequest, int iServer ) override; 

	// A list refresh you had initiated is now 100% completed
	void RefreshComplete( HServerListRequest hRequest, EMatchMakingServerResponse response ) override; 
};


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
class Steam_MatchmakingPingResponse : public ISteamMatchmakingPingResponse
{
public:
	// Server has responded successfully and has updated data
	void ServerResponded( gameserveritem_t &server ) override;

	// Server failed to respond to the ping request
	void ServerFailedToRespond() override;
};


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
class Steam_Matchmaking_Players_Response : public ISteamMatchmakingPlayersResponse
{
public:
	// Got data on a new player on the server -- you'll get this callback once per player
	// on the server which you have requested player data on.
	void AddPlayerToList( const char *pchName, int nScore, float flTimePlayed ) override;

	// The server failed to respond to the request for player details
	void PlayersFailedToRespond() override;

	// The server has finished responding to the player details request 
	// (ie, you won't get anymore AddPlayerToList callbacks)
	void PlayersRefreshComplete() override;
};


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
class Steam_Matchmaking_Rules_Response : public ISteamMatchmakingRulesResponse
{
public:
	// Got data on a rule on the server -- you'll get one of these per rule defined on
	// the server you are querying
	void RulesResponded( const char *pchRule, const char *pchValue ) override;

	// The server failed to respond to the request for rule details
	void RulesFailedToRespond() override;

	// The server has finished responding to the rule details request 
	// (ie, you won't get anymore RulesResponded callbacks)
	void RulesRefreshComplete() override;
};

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
//-----------------------------------------------------------------------------
class Steam_Matchmaking_Servers :
	public ISteamMatchmakingServers,
	public ISteamMatchmakingServers001
{
public:
	// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
	void RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;
	void RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;
	void RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;
	void RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;
	void RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;
	void RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse001 *pRequestServersResponse ) override;

	// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
	// Each call allocates a new asynchronous request object.
	// Request object must be released by calling ReleaseRequest( hServerListRequest )
	HServerListRequest RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;
	HServerListRequest RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;
	HServerListRequest RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;
	HServerListRequest RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;
	HServerListRequest RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;
	HServerListRequest RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) override;

	// Releases the asynchronous request object and cancels any pending query on it if there's a pending query in progress.
	// RefreshComplete callback is not posted when request is released.
	void ReleaseRequest( HServerListRequest hServerListRequest ) override;

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
	// Changed from Steam SDK v1.06, backward compatibility
	gameserveritem_t *GetServerDetails( EMatchMakingType eType, int iServer ) override; 
	gameserveritem_t *GetServerDetails( HServerListRequest hRequest, int iServer ) override; 

	// Cancel an request which is operation on the given list type.  You should call this to cancel
	// any in-progress requests before destructing a callback object that may have been passed 
	// to one of the above list request calls.  Not doing so may result in a crash when a callback
	// occurs on the destructed object.
	// Changed from Steam SDK v1.06, backward compatibility
	void CancelQuery( EMatchMakingType eType ) override; 
	// Canceling a query does not release the allocated request handle.
	// The request handle must be released using ReleaseRequest( hRequest )
	void CancelQuery( HServerListRequest hRequest ) override; 

	// Ping every server in your list again but don't update the list of servers
	// Changed from Steam SDK v1.06, backward compatibility
	void RefreshQuery( EMatchMakingType eType ) override; 
	// Query callback installed when the server list was requested will be used
	// again to post notifications and RefreshComplete, so the callback must remain
	// valid until another RefreshComplete is called on it or the request
	// is released with ReleaseRequest( hRequest )
	void RefreshQuery( HServerListRequest hRequest ) override; 

	// Returns true if the list is currently refreshing its server list
	// Changed from Steam SDK v1.06, backward compatibility
	bool IsRefreshing( EMatchMakingType eType ) override; 
	bool IsRefreshing( HServerListRequest hRequest ) override; 

	// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
	// Changed from Steam SDK v1.06, backward compatibility
	int GetServerCount( EMatchMakingType eType ) override; 
	int GetServerCount( HServerListRequest hRequest ) override; 

	// Refresh a single server inside of a query (rather than all the servers )
	// Changed from Steam SDK v1.06, backward compatibility
	void RefreshServer( EMatchMakingType eType, int iServer ) override; 
	void RefreshServer( HServerListRequest hRequest, int iServer ) override; 


	//-----------------------------------------------------------------------------
	// Queries to individual servers directly via IP/Port
	//-----------------------------------------------------------------------------

	// Request updated ping time and other details from a single server
	HServerQuery PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse ) override; 

	// Request the list of players currently playing on a server
	HServerQuery PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse ) override;

	// Request the list of rules that the server is running (See ISteamMasterServerUpdater->SetKeyValue() to set the rules server side)
	HServerQuery ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse ) override; 

	// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
	// any in-progress requests before destructing a callback object that may have been passed 
	// to one of the above calls to avoid crashing when callbacks occur.
	void CancelServerQuery( HServerQuery hServerQuery ) override; 
};

#endif // VAPORCORE_STEAM_MATCHMAKING_H
