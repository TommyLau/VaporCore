/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_FRIENDS_H
#define VAPORCORE_STEAM_FRIENDS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamfriends.h>
#include <isteamfriends003.h>
#include <isteamfriends004.h>
#include <isteamfriends005.h>
#include <isteamfriends006.h>
#include <isteamfriends007.h>

//-----------------------------------------------------------------------------
// Purpose: interface to accessing information about individual users,
//			that can be a friend, in a group, on a game server or in a lobby with the local user
//-----------------------------------------------------------------------------
class Steam_Friends :
	public ISteamFriends,
	public ISteamFriends003,
	public ISteamFriends004,
	public ISteamFriends005,
	public ISteamFriends006,
	public ISteamFriends007
{
public:
    Steam_Friends();
    ~Steam_Friends();

	// returns the local players name - guaranteed to not be NULL.
	// this is the same name as on the users community profile page
	// this is stored in UTF-8 format
	// like all the other interface functions that return a char *, it's important that this pointer is not saved
	// off; it will eventually be free'd or re-allocated
	const char *GetPersonaName() override;
	
	// sets the player name, stores it on the server and publishes the changes to all friends who are online
	void SetPersonaName( const char *pchPersonaName ) override;

	// gets the status of the current user
	EPersonaState GetPersonaState() override;

	// friend iteration
	// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
	// then GetFriendByIndex() can then be used to return the id's of each of those users
	int GetFriendCount( int iFriendFlags ) override;

	// returns the steamID of a user
	// iFriend is a index of range [0, GetFriendCount())
	// iFriendsFlags must be the same value as used in GetFriendCount()
	// the returned CSteamID can then be used by all the functions below to access details about the user
	CSteamID GetFriendByIndex( int iFriend, int iFriendFlags ) override;

	// returns a relationship to a user
	EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend ) override;

	// returns the current status of the specified user
	// this will only be known by the local user if steamIDFriend is in their friends list; on the same game server; in a chat room or lobby; or in a small group with the local user
	EPersonaState GetFriendPersonaState( CSteamID steamIDFriend ) override;

	// returns the name another user - guaranteed to not be NULL.
	// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
	// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically; that information will arrive asyncronously
	// 
	const char *GetFriendPersonaName( CSteamID steamIDFriend ) override;

	// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	// Changed from Steam SDK v1.02, backward compatibility
	int GetFriendAvatar( CSteamID steamIDFriend ) override;
	// Removed from Steam SDK v1.11, backward compatibility
	int GetFriendAvatar( CSteamID steamIDFriend, int eAvatarSize ) override;
	// returns true if the friend is actually in a game
	// Changed from Steam SDK v1.04, backward compatibility
	bool GetFriendGamePlayed( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort, uint16 *pusQueryPort ) override;
	// returns true if the friend is actually in a game, and fills in pFriendGameInfo with an extra details 
	bool GetFriendGamePlayed( CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo ) override;
	// accesses old friends names - returns an empty string when their are no more items in the history
	const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName ) override;

	// returns true if the specified user meets any of the criteria specified in iFriendFlags
	// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
	bool HasFriend( CSteamID steamIDFriend, int iFriendFlags ) override;

	// clan (group) iteration and access functions
	int GetClanCount() override;
	CSteamID GetClanByIndex( int iClan ) override;
	const char *GetClanName( CSteamID steamIDClan ) override;
	const char *GetClanTag( CSteamID steamIDClan ) override;

	// iterators for getting users in a chat room, lobby, game server or clan
	// note that large clans that cannot be iterated by the local user
	// steamIDSource can be the steamID of a group, game server, lobby or chat room
	int GetFriendCountFromSource( CSteamID steamIDSource ) override;
	CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend ) override;

	// returns true if the local user can see that steamIDUser is a member or in steamIDSource
	bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource ) override;

	// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
	void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking ) override;

	// activates the game overlay, with an optional dialog to open ("Friends", "Community", "Players", "Settings")
	void ActivateGameOverlay( const char *pchDialog ) override;
	
	// activates game overlay to a specific place
	// valid options are
	//		"steamid" - opens the overlay web browser to the specified user or groups profile
	//		"chat" - opens a chat window to the specified user, or joins the group chat 
	//		"stats" - opens the overlay web browser to the specified user's stats
	//		"achievements" - opens the overlay web browser to the specified user's achievements
	void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID ) override;

	// activates game overlay web browser directly to the specified URL
	// full address with protocol type is required, e.g. http://www.steamgames.com/
	void ActivateGameOverlayToWebPage( const char *pchURL ) override;

	// activates game overlay to store page for app
	void ActivateGameOverlayToStore( AppId_t nAppID ) override;

	// Mark a target user as 'played with'. This is a client-side only feature that requires that the calling user is 
	// in game 
	void SetPlayedWith( CSteamID steamIDUserPlayedWith ) override;

	// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
	// You can also use ActivateGameOverlay( "LobbyInvite" ) to allow the user to create invitations for their current public lobby.
	void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby ) override;

	// gets the small (32x32) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int GetSmallFriendAvatar( CSteamID steamIDFriend ) override;

	// gets the medium (64x64) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int GetMediumFriendAvatar( CSteamID steamIDFriend ) override;

	// gets the large (184x184) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	// returns -1 if this image has yet to be loaded, in this case wait for a AvatarImageLoaded_t callback and then call this again
	int GetLargeFriendAvatar( CSteamID steamIDFriend ) override;

	// requests information about a user - persona name & avatar
	// if bRequireNameOnly is set, then the avatar of a user isn't downloaded 
	// - it's a lot slower to download avatars and churns the local cache, so if you don't need avatars, don't request them
	// if returns true, it means that data is being requested, and a PersonaStateChanged_t callback will be posted when it's retrieved
	// if returns false, it means that we already have all the details about that user, and functions can be called immediately
	bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly ) override;

	// requests information about a clan officer list
	// when complete, data is returned in ClanOfficerListResponse_t call result
	// this makes available the calls below
	// you can only ask about clans that a user is a member of
	// note that this won't download avatars automatically; if you get an officer,
	// and no avatar image is available, call RequestUserInformation( steamID, false ) to download the avatar
	SteamAPICall_t RequestClanOfficerList( CSteamID steamIDClan ) override;

	// iteration of clan officers - can only be done when a RequestClanOfficerList() call has completed
	
	// returns the steamID of the clan owner
	CSteamID GetClanOwner( CSteamID steamIDClan ) override;
	// returns the number of officers in a clan (including the owner)
	int GetClanOfficerCount( CSteamID steamIDClan ) override;
	// returns the steamID of a clan officer, by index, of range [0,GetClanOfficerCount)
	CSteamID GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer ) override;
	// if current user is chat restricted, he can't send or receive any text/voice chat messages.
	// the user can't see custom avatars. But the user can be online and send/recv game invites.
	// a chat restricted user can't add friends or join any groups.
	uint32 GetUserRestrictions() override;

    // Helper methods
    static Steam_Friends* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Friends* s_pInstance;
};

#endif // VAPORCORE_STEAM_FRIENDS_H

