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

#include "../include/sdk/isteamfriends.h"

//-----------------------------------------------------------------------------
// Purpose: interface to accessing information about individual users,
//			that can be a friend, in a group, on a game server or in a lobby with the local user
//-----------------------------------------------------------------------------
class Steam_Friends : public ISteamFriends
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
	int GetFriendAvatar( CSteamID steamIDFriend ) override;
	// returns true if the friend is actually in a game
	bool GetFriendGamePlayed( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort, uint16 *pusQueryPort ) override;
	// accesses old friends names - returns an empty string when their are no more items in the history
	const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName ) override;

	// returns true if the specified user meets any of the criteria specified in iFriendFlags
	// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
	bool HasFriend( CSteamID steamIDFriend, int iFriendFlags ) override;

	// clan (group) iteration and access functions
	int GetClanCount() override;
	CSteamID GetClanByIndex( int iClan ) override;
	const char *GetClanName( CSteamID steamIDClan ) override;

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

    // Helper methods
    static Steam_Friends* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_Friends* s_pInstance;
};

#endif // VAPORCORE_STEAM_FRIENDS_H

