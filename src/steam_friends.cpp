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
#include "steam_friends.h"

//-----------------------------------------------------------------------------
// Purpose: avatar sizes, used in ISteamFriends::GetFriendAvatar()
//-----------------------------------------------------------------------------
// Removed from Steam SDK v1.11, backward compatibility
enum EAvatarSize
{
	k_EAvatarSize32x32 = 0,
	k_EAvatarSize64x64 = 1,
};

// Static instance
CSteamFriends* CSteamFriends::s_pInstance = nullptr;

CSteamFriends::CSteamFriends()
{
    VLOG_INFO("CSteamFriends constructor called");
}

CSteamFriends::~CSteamFriends()
{
    VLOG_INFO("CSteamFriends destructor called");
}

// Helper methods
CSteamFriends* CSteamFriends::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamFriends();
    }
    return s_pInstance;
}

void CSteamFriends::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// returns the local players name - guaranteed to not be NULL.
// this is the same name as on the users community profile page
// this is stored in UTF-8 format
// like all the other interface functions that return a char *, it's important that this pointer is not saved
// off; it will eventually be free'd or re-allocated
const char *CSteamFriends::GetPersonaName()
{
    VLOG_DEBUG("GetPersonaName called");
    return "VaporCore User";
}

// Sets the player name, stores it on the server and publishes the changes to all friends who are online.
// Changes take place locally immediately, and a PersonaStateChange_t is posted, presuming success.
//
// The final results are available through the return value SteamAPICall_t, using SetPersonaNameResponse_t.
//
// If the name change fails to happen on the server, then an additional global PersonaStateChange_t will be posted
// to change the name back, in addition to the SetPersonaNameResponse_t callback.
SteamAPICall_t CSteamFriends::SetPersonaName( const char *pchPersonaName )
{
    VLOG_DEBUG("SetPersonaName called - Name: %s", pchPersonaName ? pchPersonaName : "null");
    return 0;
}

// Changed from Steam SDK v1.20, backward compatibility
void CSteamFriends::DEPRECATED_SetPersonaName( const char *pchPersonaName )
{
    VLOG_DEBUG("SetPersonaName called - Name: %s", pchPersonaName ? pchPersonaName : "null");
}

// gets the status of the current user
EPersonaState CSteamFriends::GetPersonaState()
{
    VLOG_DEBUG("GetPersonaState called");
    return k_EPersonaStateOnline;
}

// friend iteration
// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
// then GetFriendByIndex() can then be used to return the id's of each of those users
int CSteamFriends::GetFriendCount( int iFriendFlags )
{
    VLOG_DEBUG("GetFriendCount called - Flags: %d", iFriendFlags);
    return 0;
}

// returns the steamID of a user
// iFriend is a index of range [0, GetFriendCount())
// iFriendsFlags must be the same value as used in GetFriendCount()
// the returned CSteamID can then be used by all the functions below to access details about the user
CSteamID CSteamFriends::GetFriendByIndex( int iFriend, int iFriendFlags )
{
    VLOG_DEBUG("GetFriendByIndex called - Friend: %d, Flags: %d", iFriend, iFriendFlags);
    return CSteamID();
}

// returns a relationship to a user
EFriendRelationship CSteamFriends::GetFriendRelationship( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendRelationship called");
    return k_EFriendRelationshipNone;
}

// returns the current status of the specified user
// this will only be known by the local user if steamIDFriend is in their friends list; on the same game server; in a chat room or lobby; or in a small group with the local user
EPersonaState CSteamFriends::GetFriendPersonaState( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendPersonaState called");
    return k_EPersonaStateOffline;
}

// returns the name another user - guaranteed to not be NULL.
// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically; that information will arrive asyncronously
// 
const char *CSteamFriends::GetFriendPersonaName( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendPersonaName called");
    return "";
}

// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
// Removed from Steam SDK v1.11, backward compatibility
int CSteamFriends::GetFriendAvatar( CSteamID steamIDFriend, int eAvatarSize )
{
    VLOG_DEBUG("GetFriendAvatar called - Avatar Size: %d", eAvatarSize);
    return 0;
}

// Changed from Steam SDK v1.02, backward compatibility
int CSteamFriends::GetFriendAvatar( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendAvatar called");
    return 0;
}

// returns true if the friend is actually in a game, and fills in pFriendGameInfo with an extra details 
bool CSteamFriends::GetFriendGamePlayed( CSteamID steamIDFriend, OUT_STRUCT() FriendGameInfo_t *pFriendGameInfo )
{
    VLOG_DEBUG("GetFriendGamePlayed called - SteamID: %s, GameID: %llu", steamIDFriend.GetAccountID(), pFriendGameInfo->m_gameID);
    return false;
}

// Changed from Steam SDK v1.04, backward compatibility
bool CSteamFriends::GetFriendGamePlayed( CSteamID steamIDFriend, uint64 *pulGameID, uint32 *punGameIP, uint16 *pusGamePort, uint16 *pusQueryPort )
{
    VLOG_DEBUG("GetFriendGamePlayed called - SteamID: %s, GameID: %llu, GameIP: %u, GamePort: %u, QueryPort: %u", steamIDFriend.GetAccountID(), *pulGameID, *punGameIP, *pusGamePort, *pusQueryPort);
    return false;
}

// accesses old friends names - returns an empty string when their are no more items in the history
const char *CSteamFriends::GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
{
    VLOG_DEBUG("GetFriendPersonaNameHistory called");
    return "";
}

// friends steam level
int CSteamFriends::GetFriendSteamLevel( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendSteamLevel called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}

// Returns nickname the current user has set for the specified player. Returns NULL if the no nickname has been set for that player.
const char *CSteamFriends::GetPlayerNickname( CSteamID steamIDPlayer )
{
    VLOG_DEBUG("GetPlayerNickname called - SteamID: %s", steamIDPlayer.GetAccountID());
    return "";
}

// friend grouping (tag) apis
// returns the number of friends groups
int CSteamFriends::GetFriendsGroupCount()
{
    VLOG_DEBUG("GetFriendsGroupCount called");
    return 0;
}

// returns the friends group ID for the given index (invalid indices return k_FriendsGroupID_Invalid)
FriendsGroupID_t CSteamFriends::GetFriendsGroupIDByIndex( int iFG )
{
    VLOG_DEBUG("GetFriendsGroupIDByIndex called - Index: %d", iFG);
    return k_FriendsGroupID_Invalid;
}

// returns the name for the given friends group (NULL in the case of invalid friends group IDs)
const char *CSteamFriends::GetFriendsGroupName( FriendsGroupID_t friendsGroupID )
{
    VLOG_DEBUG("GetFriendsGroupName called - GroupID: %d", friendsGroupID);
    return nullptr;
}

// returns the number of members in a given friends group
int CSteamFriends::GetFriendsGroupMembersCount( FriendsGroupID_t friendsGroupID )
{
    VLOG_DEBUG("GetFriendsGroupMembersCount called - GroupID: %d", friendsGroupID);
    return 0;
}

// gets up to nMembersCount members of the given friends group, if fewer exist than requested those positions' SteamIDs will be invalid
void CSteamFriends::GetFriendsGroupMembersList( FriendsGroupID_t friendsGroupID, CSteamID *pOutSteamIDMembers, int nMembersCount )
{
    VLOG_DEBUG("GetFriendsGroupMembersList called - GroupID: %d, Members: %p, Count: %d", 
               friendsGroupID, pOutSteamIDMembers, nMembersCount);
}

// returns true if the specified user meets any of the criteria specified in iFriendFlags
// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
bool CSteamFriends::HasFriend( CSteamID steamIDFriend, int iFriendFlags )
{
    VLOG_DEBUG("HasFriend called");
    return false;
}

// clan (group) iteration and access functions
int CSteamFriends::GetClanCount()
{
    VLOG_DEBUG("GetClanCount called");
    return 0;
}

CSteamID CSteamFriends::GetClanByIndex( int iClan )
{
    VLOG_DEBUG("GetClanByIndex called - Clan: %d", iClan);
    return CSteamID();
}

const char *CSteamFriends::GetClanName( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanName called");
    return "";
}

const char *CSteamFriends::GetClanTag( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanTag called");
    return "";
}

// returns the most recent information we have about what's happening in a clan
bool CSteamFriends::GetClanActivityCounts( CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting )
{
    VLOG_DEBUG("GetClanActivityCounts called");
    return false;
}
// for clans a user is a member of, they will have reasonably up-to-date information, but for others you'll have to download the info to have the latest
SteamAPICall_t CSteamFriends::DownloadClanActivityCounts( CSteamID *psteamIDClans, int cClansToRequest )
{
    VLOG_DEBUG("DownloadClanActivityCounts called");
    return 0;
}

// iterators for getting users in a chat room, lobby, game server or clan
// note that large clans that cannot be iterated by the local user
// note that the current user must be in a lobby to retrieve CSteamIDs of other users in that lobby
// steamIDSource can be the steamID of a group, game server, lobby or chat room
int CSteamFriends::GetFriendCountFromSource( CSteamID steamIDSource )
{
    VLOG_DEBUG("GetFriendCountFromSource called");
    return 0;
}

CSteamID CSteamFriends::GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
{
    VLOG_DEBUG("GetFriendFromSourceByIndex called - Friend: %d", iFriend);
    return CSteamID();
}

// returns true if the local user can see that steamIDUser is a member or in steamIDSource
bool CSteamFriends::IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
{
    VLOG_DEBUG("IsUserInSource called");
    return false;
}

// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
void CSteamFriends::SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
{
    VLOG_DEBUG("SetInGameVoiceSpeaking called - Speaking: %s", bSpeaking ? "true" : "false");
}

// activates the game overlay, with an optional dialog to open 
// valid options are "Friends", "Community", "Players", "Settings", "OfficialGameGroup", "Stats", "Achievements"
void CSteamFriends::ActivateGameOverlay( const char *pchDialog )
{
    VLOG_DEBUG("ActivateGameOverlay called - Dialog: %s", pchDialog ? pchDialog : "null");
}

// activates game overlay to a specific place
// valid options are
//		"steamid" - opens the overlay web browser to the specified user or groups profile
//		"chat" - opens a chat window to the specified user, or joins the group chat 
//		"jointrade" - opens a window to a Steam Trading session that was started with the ISteamEconomy/StartTrade Web API
//		"stats" - opens the overlay web browser to the specified user's stats
//		"achievements" - opens the overlay web browser to the specified user's achievements
void CSteamFriends::ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
{
    VLOG_DEBUG("ActivateGameOverlayToUser called - Dialog: %s, SteamID: %s", pchDialog ? pchDialog : "null", steamID.GetAccountID());
}

// activates game overlay web browser directly to the specified URL
// full address with protocol type is required, e.g. http://www.steamgames.com/
void CSteamFriends::ActivateGameOverlayToWebPage( const char *pchURL )
{
    VLOG_DEBUG("ActivateGameOverlayToWebPage called - URL: %s", pchURL ? pchURL : "null");
}

// activates game overlay to store page for app
void CSteamFriends::ActivateGameOverlayToStore( AppId_t nAppID, EOverlayToStoreFlag eFlag )
{
    VLOG_DEBUG("ActivateGameOverlayToStore called - AppID: %d, Flag: %d", nAppID, eFlag);
}

// Changed from Steam SDK v1.20, backward compatibility
void CSteamFriends::ActivateGameOverlayToStore( AppId_t nAppID )
{
    VLOG_DEBUG("ActivateGameOverlayToStore called - AppID: %d", nAppID);
}

// Mark a target user as 'played with'. This is a client-side only feature that requires that the calling user is 
// in game 
void CSteamFriends::SetPlayedWith( CSteamID steamIDUserPlayedWith )
{
    VLOG_DEBUG("SetPlayedWith called - SteamID: %s", steamIDUserPlayedWith.GetAccountID());
}

// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
void CSteamFriends::ActivateGameOverlayInviteDialog( CSteamID steamIDLobby )
{
    VLOG_DEBUG("ActivateGameOverlayInviteDialog called - SteamID: %s", steamIDLobby.GetAccountID());
}

// gets the small (32x32) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
int CSteamFriends::GetSmallFriendAvatar( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetSmallFriendAvatar called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}

// gets the medium (64x64) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
int CSteamFriends::GetMediumFriendAvatar( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetMediumFriendAvatar called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}

// gets the large (184x184) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
// returns -1 if this image has yet to be loaded, in this case wait for a AvatarImageLoaded_t callback and then call this again
int CSteamFriends::GetLargeFriendAvatar( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetLargeFriendAvatar called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}

// requests information about a user - persona name & avatar
// if bRequireNameOnly is set, then the avatar of a user isn't downloaded 
// - it's a lot slower to download avatars and churns the local cache, so if you don't need avatars, don't request them
// if returns true, it means that data is being requested, and a PersonaStateChanged_t callback will be posted when it's retrieved
// if returns false, it means that we already have all the details about that user, and functions can be called immediately
bool CSteamFriends::RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly )
{
    VLOG_DEBUG("RequestUserInformation called - SteamID: %s, RequireNameOnly: %s", steamIDUser.GetAccountID(), bRequireNameOnly ? "true" : "false");
    return false;
}

// requests information about a clan officer list
// when complete, data is returned in ClanOfficerListResponse_t call result
// this makes available the calls below
// you can only ask about clans that a user is a member of
// note that this won't download avatars automatically; if you get an officer,
// and no avatar image is available, call RequestUserInformation( steamID, false ) to download the avatar
SteamAPICall_t CSteamFriends::RequestClanOfficerList( CSteamID steamIDClan )
{
    VLOG_DEBUG("RequestClanOfficerList called - SteamID: %s", steamIDClan.GetAccountID());
    return 0;
}

// iteration of clan officers - can only be done when a RequestClanOfficerList() call has completed
	
// returns the steamID of the clan owner
CSteamID CSteamFriends::GetClanOwner( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanOwner called - SteamID: %s", steamIDClan.GetAccountID());
    return CSteamID();
}

// returns the number of officers in a clan (including the owner)
int CSteamFriends::GetClanOfficerCount( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanOfficerCount called - SteamID: %s", steamIDClan.GetAccountID());
    return 0;
}

// returns the steamID of a clan officer, by index, of range [0,GetClanOfficerCount)
CSteamID CSteamFriends::GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer )
{
    VLOG_DEBUG("GetClanOfficerByIndex called - SteamID: %s, Officer: %d", steamIDClan.GetAccountID(), iOfficer);
    return CSteamID();
}

// if current user is chat restricted, he can't send or receive any text/voice chat messages.
// the user can't see custom avatars. But the user can be online and send/recv game invites.
// a chat restricted user can't add friends or join any groups.
uint32 CSteamFriends::GetUserRestrictions()
{
    VLOG_DEBUG("GetUserRestrictions called");
    return 0;
}

// Rich Presence data is automatically shared between friends who are in the same game
// Each user has a set of Key/Value pairs
// Up to 20 different keys can be set
// There are two magic keys:
//		"status"  - a UTF-8 string that will show up in the 'view game info' dialog in the Steam friends list
//		"connect" - a UTF-8 string that contains the command-line for how a friend can connect to a game
// GetFriendRichPresence() returns an empty string "" if no value is set
// SetRichPresence() to a NULL or an empty string deletes the key
// You can iterate the current set of keys for a friend with GetFriendRichPresenceKeyCount()
// and GetFriendRichPresenceKeyByIndex() (typically only used for debugging)
bool CSteamFriends::SetRichPresence( const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("SetRichPresence called - Key: %s, Value: %s", pchKey ? pchKey : "null", pchValue ? pchValue : "null");
    return false;
}

void CSteamFriends::ClearRichPresence()
{
    VLOG_DEBUG("ClearRichPresence called");
}

const char *CSteamFriends::GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey )
{
    VLOG_DEBUG("GetFriendRichPresence called - SteamID: %s, Key: %s", steamIDFriend.GetAccountID(), pchKey ? pchKey : "null");
    return "";
}

int CSteamFriends::GetFriendRichPresenceKeyCount( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendRichPresenceKeyCount called");
    return 0;
}

const char *CSteamFriends::GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey )
{
    VLOG_DEBUG("GetFriendRichPresenceKeyByIndex called");
    return "";
}

// Requests rich presence for a specific user.
void CSteamFriends::RequestFriendRichPresence( CSteamID steamIDFriend )
{
    VLOG_DEBUG("RequestFriendRichPresence called - SteamID: %s", steamIDFriend.GetAccountID());
}

// rich invite support
// if the target accepts the invite, the pchConnectString gets added to the command-line for launching the game
// if the game is already running, a GameRichPresenceJoinRequested_t callback is posted containing the connect string
// invites can only be sent to friends
bool CSteamFriends::InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString )
{
    VLOG_DEBUG("InviteUserToGame called - SteamID: %s, ConnectString: %s", steamIDFriend.GetAccountID(), pchConnectString ? pchConnectString : "null");
    return false;
}

// recently-played-with friends iteration
// this iterates the entire list of users recently played with, across games
// GetFriendCoplayTime() returns as a unix time
int CSteamFriends::GetCoplayFriendCount()
{
    VLOG_DEBUG("GetCoplayFriendCount called");
    return 0;
}

CSteamID CSteamFriends::GetCoplayFriend( int iCoplayFriend )
{
    VLOG_DEBUG("GetCoplayFriend called - CoplayFriend: %d", iCoplayFriend);
    return CSteamID();
}

int CSteamFriends::GetFriendCoplayTime( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendCoplayTime called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}

AppId_t CSteamFriends::GetFriendCoplayGame( CSteamID steamIDFriend )
{
    VLOG_DEBUG("GetFriendCoplayGame called - SteamID: %s", steamIDFriend.GetAccountID());
    return 0;
}


// chat interface for games
// this allows in-game access to group (clan) chats from in the game
// the behavior is somewhat sophisticated, because the user may or may not be already in the group chat from outside the game or in the overlay
// use ActivateGameOverlayToUser( "chat", steamIDClan ) to open the in-game overlay version of the chat
SteamAPICall_t CSteamFriends::JoinClanChatRoom( CSteamID steamIDClan )
{
    VLOG_DEBUG("JoinClanChatRoom called - SteamID: %s", steamIDClan.GetAccountID());
    return 0;
}

bool CSteamFriends::LeaveClanChatRoom( CSteamID steamIDClan )
{
    VLOG_DEBUG("LeaveClanChatRoom called - SteamID: %s", steamIDClan.GetAccountID());
    return false;
}

int CSteamFriends::GetClanChatMemberCount( CSteamID steamIDClan )
{
    VLOG_DEBUG("GetClanChatMemberCount called - SteamID: %s", steamIDClan.GetAccountID());
    return 0;
}

CSteamID CSteamFriends::GetChatMemberByIndex( CSteamID steamIDClan, int iUser )
{
    VLOG_DEBUG("GetChatMemberByIndex called - SteamID: %s, User: %d", steamIDClan.GetAccountID(), iUser);
    return CSteamID();
}

bool CSteamFriends::SendClanChatMessage( CSteamID steamIDClanChat, const char *pchText )
{
    VLOG_DEBUG("SendClanChatMessage called - SteamID: %s, Text: %s", steamIDClanChat.GetAccountID(), pchText);
    return false;
}

int CSteamFriends::GetClanChatMessage( CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, OUT_STRUCT() CSteamID *psteamidChatter )
{
    VLOG_DEBUG("GetClanChatMessage called - SteamID: %s, Message: %d", steamIDClanChat.GetAccountID(), iMessage);
    return 0;
}

bool CSteamFriends::IsClanChatAdmin( CSteamID steamIDClanChat, CSteamID steamIDUser )
{
    VLOG_DEBUG("IsClanChatAdmin called - SteamID: %s, User: %s", steamIDClanChat.GetAccountID(), steamIDUser.GetAccountID());
    return false;
}

// interact with the Steam (game overlay / desktop)
bool CSteamFriends::IsClanChatWindowOpenInSteam( CSteamID steamIDClanChat )
{
    VLOG_DEBUG("IsClanChatWindowOpenInSteam called - SteamID: %s", steamIDClanChat.GetAccountID());
    return false;
}

bool CSteamFriends::OpenClanChatWindowInSteam( CSteamID steamIDClanChat )
{
    VLOG_DEBUG("OpenClanChatWindowInSteam called - SteamID: %s", steamIDClanChat.GetAccountID());
    return false;
}

bool CSteamFriends::CloseClanChatWindowInSteam( CSteamID steamIDClanChat )
{
    VLOG_DEBUG("CloseClanChatWindowInSteam called - SteamID: %s", steamIDClanChat.GetAccountID());
    return false;
}

// peer-to-peer chat interception
// this is so you can show P2P chats inline in the game
bool CSteamFriends::SetListenForFriendsMessages( bool bInterceptEnabled )
{
    VLOG_DEBUG("SetListenForFriendsMessages called - InterceptEnabled: %s", bInterceptEnabled ? "true" : "false");
    return false;
}

bool CSteamFriends::ReplyToFriendMessage( CSteamID steamIDFriend, const char *pchMsgToSend )
{
    VLOG_DEBUG("ReplyToFriendMessage called - SteamID: %s, Message: %s", steamIDFriend.GetAccountID(), pchMsgToSend);
    return false;
}

int CSteamFriends::GetFriendMessage( CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
    VLOG_DEBUG("GetFriendMessage called - SteamID: %s, MessageID: %d", steamIDFriend.GetAccountID(), iMessageID);
    return 0;
}


// following apis
SteamAPICall_t CSteamFriends::GetFollowerCount( CSteamID steamID )
{
    VLOG_DEBUG("GetFollowerCount called - SteamID: %s", steamID.GetAccountID());
    return 0;
}

SteamAPICall_t CSteamFriends::IsFollowing( CSteamID steamID )
{
    VLOG_DEBUG("IsFollowing called - SteamID: %s", steamID.GetAccountID());
    return 0;
}

SteamAPICall_t CSteamFriends::EnumerateFollowingList( uint32 unStartIndex )
{
    VLOG_DEBUG("EnumerateFollowingList called - StartIndex: %d", unStartIndex);
    return 0;
}
