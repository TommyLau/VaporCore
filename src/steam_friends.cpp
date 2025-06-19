/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_friends.h"
#include "logger.h"

// Static instance
Steam_Friends* Steam_Friends::s_pInstance = nullptr;

Steam_Friends::Steam_Friends()
{
    VLOG_INFO("Steam_Friends constructor called");
}

Steam_Friends::~Steam_Friends()
{
    VLOG_INFO("Steam_Friends destructor called");
}

// returns the local players name - guaranteed to not be NULL.
// this is the same name as on the users community profile page
// this is stored in UTF-8 format
// like all the other interface functions that return a char *, it's important that this pointer is not saved
// off; it will eventually be free'd or re-allocated
const char *Steam_Friends::GetPersonaName()
{
    VLOG_DEBUG("GetPersonaName called");
    return "VaporCore User";
}

// sets the player name, stores it on the server and publishes the changes to all friends who are online
void Steam_Friends::SetPersonaName( const char *pchPersonaName )
{
    VLOG_DEBUG("SetPersonaName called - Name: %s", pchPersonaName ? pchPersonaName : "null");
}

// gets the status of the current user
EPersonaState Steam_Friends::GetPersonaState()
{
    VLOG_DEBUG("GetPersonaState called");
    return k_EPersonaStateOnline;
}

// friend iteration
// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
// then GetFriendByIndex() can then be used to return the id's of each of those users
int Steam_Friends::GetFriendCount( int iFriendFlags )
{
    VLOG_DEBUG("GetFriendCount called - Flags: %d", iFriendFlags);
    return 0;
}

// returns the steamID of a user
// iFriend is a index of range [0, GetFriendCount())
// iFriendsFlags must be the same value as used in GetFriendCount()
// the returned CSteamID can then be used by all the functions below to access details about the user
CSteamID Steam_Friends::GetFriendByIndex( int iFriend, int iFriendFlags )
{
    VLOG_DEBUG("GetFriendByIndex called - Friend: %d, Flags: %d", iFriend, iFriendFlags);
    return CSteamID();
}

// returns a relationship to a user
EFriendRelationship Steam_Friends::GetFriendRelationship( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendRelationship called");
    return k_EFriendRelationshipNone;
}

// returns the current status of the specified user
// this will only be known by the local user if steamIDFriend is in their friends list; on the same game server; in a chat room or lobby; or in a small group with the local user
EPersonaState Steam_Friends::GetFriendPersonaState( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendPersonaState called");
    return k_EPersonaStateOffline;
}

// returns the name another user - guaranteed to not be NULL.
// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically; that information will arrive asyncronously
// 
const char *Steam_Friends::GetFriendPersonaName( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendPersonaName called");
    return "";
}

// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
// Removed from Steam SDK v1.02, backward compatibility
int Steam_Friends::GetFriendAvatar( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendAvatar called");
    return 0;
}

int Steam_Friends::GetFriendAvatar( CSteamID steamIDFriend, int eAvatarSize )
{
    VLOG_DEBUG("GetFriendAvatar called - Avatar Size: %d", eAvatarSize);
    return 0;
}

// returns true if the friend is actually in a game
bool Steam_Friends::GetFriendGamePlayed( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort, uint16 *pusQueryPort )
{
    VLOG_DEBUG("GetFriendGamePlayed called");
    return false;
}

// accesses old friends names - returns an empty string when their are no more items in the history
const char *Steam_Friends::GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
{
    VLOG_DEBUG("GetFriendPersonaNameHistory called");
    return "";
}

// returns true if the specified user meets any of the criteria specified in iFriendFlags
// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
bool Steam_Friends::HasFriend( CSteamID steamIDFriend, int iFriendFlags )
{
    VLOG_DEBUG("HasFriend called");
    return false;
}

// clan (group) iteration and access functions
int Steam_Friends::GetClanCount()
{
    VLOG_DEBUG("GetClanCount called");
    return 0;
}

CSteamID Steam_Friends::GetClanByIndex( int iClan )
{
    VLOG_DEBUG("GetClanByIndex called - Clan: %d", iClan);
    return CSteamID();
}

const char *Steam_Friends::GetClanName( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanName called");
    return "";
}

// iterators for getting users in a chat room, lobby, game server or clan
// note that large clans that cannot be iterated by the local user
// steamIDSource can be the steamID of a group, game server, lobby or chat room
int Steam_Friends::GetFriendCountFromSource( CSteamID steamIDSource )
{
    VLOG_DEBUG("GetFriendCountFromSource called");
    return 0;
}

CSteamID Steam_Friends::GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
{
    VLOG_DEBUG("GetFriendFromSourceByIndex called - Friend: %d", iFriend);
    return CSteamID();
}

// returns true if the local user can see that steamIDUser is a member or in steamIDSource
bool Steam_Friends::IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
{
    VLOG_DEBUG("IsUserInSource called");
    return false;
}

// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
void Steam_Friends::SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
{
    VLOG_DEBUG("SetInGameVoiceSpeaking called - Speaking: %s", bSpeaking ? "true" : "false");
}

// activates the game overlay, with an optional dialog to open ("Friends", "Community", "Players", "Settings")
void Steam_Friends::ActivateGameOverlay( const char *pchDialog )
{
    VLOG_DEBUG("ActivateGameOverlay called - Dialog: %s", pchDialog ? pchDialog : "null");
}

// Helper methods
Steam_Friends* Steam_Friends::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Friends();
    }
    return s_pInstance;
}

void Steam_Friends::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

