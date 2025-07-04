/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "vapor_base.h"
#include "steam_api_flat.h"

//-----------------------------------------------------------------------------
// ISteamClient flat API implementations
//-----------------------------------------------------------------------------

S_API HSteamPipe SteamAPI_ISteamClient_CreateSteamPipe( ISteamClient* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateSteamPipe();
}

S_API bool SteamAPI_ISteamClient_BReleaseSteamPipe( ISteamClient* self, HSteamPipe hSteamPipe )
{
    VLOG_INFO(__FUNCTION__);
    return self->BReleaseSteamPipe(hSteamPipe);
}

S_API HSteamUser SteamAPI_ISteamClient_ConnectToGlobalUser( ISteamClient* self, HSteamPipe hSteamPipe )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConnectToGlobalUser(hSteamPipe);
}

S_API HSteamUser SteamAPI_ISteamClient_CreateLocalUser( ISteamClient* self, HSteamPipe * phSteamPipe, EAccountType eAccountType )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateLocalUser(phSteamPipe, eAccountType);
}

S_API void SteamAPI_ISteamClient_ReleaseUser( ISteamClient* self, HSteamPipe hSteamPipe, HSteamUser hUser )
{
    VLOG_INFO(__FUNCTION__);
    self->ReleaseUser(hSteamPipe, hUser);
}

S_API ISteamUser * SteamAPI_ISteamClient_GetISteamUser( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamGameServer * SteamAPI_ISteamClient_GetISteamGameServer( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}

S_API void SteamAPI_ISteamClient_SetLocalIPBinding( ISteamClient* self, const SteamIPAddress_t & unIP, uint16 usPort )
{
    VLOG_INFO(__FUNCTION__);
    self->SetLocalIPBinding(unIP, usPort);
}

S_API ISteamFriends * SteamAPI_ISteamClient_GetISteamFriends( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamUtils * SteamAPI_ISteamClient_GetISteamUtils( ISteamClient* self, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamUtils(hSteamPipe, pchVersion);
}

S_API ISteamMatchmaking * SteamAPI_ISteamClient_GetISteamMatchmaking( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamMatchmakingServers * SteamAPI_ISteamClient_GetISteamMatchmakingServers( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}

S_API void * SteamAPI_ISteamClient_GetISteamGenericInterface( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamUserStats * SteamAPI_ISteamClient_GetISteamUserStats( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamGameServerStats * SteamAPI_ISteamClient_GetISteamGameServerStats( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamGameServerStats(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamApps * SteamAPI_ISteamClient_GetISteamApps( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamNetworking * SteamAPI_ISteamClient_GetISteamNetworking( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamRemoteStorage * SteamAPI_ISteamClient_GetISteamRemoteStorage( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamRemoteStorage(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamScreenshots * SteamAPI_ISteamClient_GetISteamScreenshots( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamScreenshots(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamGameSearch * SteamAPI_ISteamClient_GetISteamGameSearch( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamGameSearch(hSteamuser, hSteamPipe, pchVersion);
}

S_API uint32 SteamAPI_ISteamClient_GetIPCCallCount( ISteamClient* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetIPCCallCount();
}

S_API void SteamAPI_ISteamClient_SetWarningMessageHook( ISteamClient* self, SteamAPIWarningMessageHook_t pFunction )
{
    VLOG_INFO(__FUNCTION__);
    self->SetWarningMessageHook(pFunction);
}

S_API bool SteamAPI_ISteamClient_BShutdownIfAllPipesClosed( ISteamClient* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BShutdownIfAllPipesClosed();
}

S_API ISteamHTTP * SteamAPI_ISteamClient_GetISteamHTTP( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamHTTP(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamController * SteamAPI_ISteamClient_GetISteamController( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamUGC * SteamAPI_ISteamClient_GetISteamUGC( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamAppList * SteamAPI_ISteamClient_GetISteamAppList( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamMusic * SteamAPI_ISteamClient_GetISteamMusic( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamMusic(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamMusicRemote * SteamAPI_ISteamClient_GetISteamMusicRemote( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamMusicRemote(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamHTMLSurface * SteamAPI_ISteamClient_GetISteamHTMLSurface( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamHTMLSurface(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamInventory * SteamAPI_ISteamClient_GetISteamInventory( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamInventory(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamVideo * SteamAPI_ISteamClient_GetISteamVideo( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamVideo(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamParentalSettings * SteamAPI_ISteamClient_GetISteamParentalSettings( ISteamClient* self, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamParentalSettings(hSteamuser, hSteamPipe, pchVersion);
}

S_API ISteamInput * SteamAPI_ISteamClient_GetISteamInput( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamInput(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamParties * SteamAPI_ISteamClient_GetISteamParties( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamParties(hSteamUser, hSteamPipe, pchVersion);
}

S_API ISteamRemotePlay * SteamAPI_ISteamClient_GetISteamRemotePlay( ISteamClient* self, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetISteamRemotePlay(hSteamUser, hSteamPipe, pchVersion);
}


//-----------------------------------------------------------------------------
// ISteamUser flat API implementations
//-----------------------------------------------------------------------------

S_API HSteamUser SteamAPI_ISteamUser_GetHSteamUser( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHSteamUser();
}

S_API bool SteamAPI_ISteamUser_BLoggedOn( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BLoggedOn();
}

S_API uint64_steamid SteamAPI_ISteamUser_GetSteamID( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSteamID().ConvertToUint64();
}

S_API int SteamAPI_ISteamUser_InitiateGameConnection( ISteamUser* self, void * pAuthBlob, int cbMaxAuthBlob, uint64_steamid steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_INFO(__FUNCTION__);
    return self->InitiateGameConnection(pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
}

S_API void SteamAPI_ISteamUser_TerminateGameConnection( ISteamUser* self, uint32 unIPServer, uint16 usPortServer )
{
    VLOG_INFO(__FUNCTION__);
    self->TerminateGameConnection(unIPServer, usPortServer);
}

S_API void SteamAPI_ISteamUser_TrackAppUsageEvent( ISteamUser* self, uint64_gameid gameID, int eAppUsageEvent, const char * pchExtraInfo )
{
    VLOG_INFO(__FUNCTION__);
    self->TrackAppUsageEvent(CGameID(gameID), eAppUsageEvent, pchExtraInfo);
}

S_API bool SteamAPI_ISteamUser_GetUserDataFolder( ISteamUser* self, char * pchBuffer, int cubBuffer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserDataFolder(pchBuffer, cubBuffer);
}

S_API void SteamAPI_ISteamUser_StartVoiceRecording( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    self->StartVoiceRecording();
}

S_API void SteamAPI_ISteamUser_StopVoiceRecording( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    self->StopVoiceRecording();
}

S_API EVoiceResult SteamAPI_ISteamUser_GetAvailableVoice( ISteamUser* self, uint32 * pcbCompressed, uint32 * pcbUncompressed_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAvailableVoice(pcbCompressed, pcbUncompressed_Deprecated, nUncompressedVoiceDesiredSampleRate_Deprecated);
}

S_API EVoiceResult SteamAPI_ISteamUser_GetVoice( ISteamUser* self, bool bWantCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, bool bWantUncompressed_Deprecated, void * pUncompressedDestBuffer_Deprecated, uint32 cbUncompressedDestBufferSize_Deprecated, uint32 * nUncompressBytesWritten_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetVoice(bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed_Deprecated, pUncompressedDestBuffer_Deprecated, cbUncompressedDestBufferSize_Deprecated, nUncompressBytesWritten_Deprecated, nUncompressedVoiceDesiredSampleRate_Deprecated);
}

S_API EVoiceResult SteamAPI_ISteamUser_DecompressVoice( ISteamUser* self, const void * pCompressed, uint32 cbCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, uint32 nDesiredSampleRate )
{
    VLOG_INFO(__FUNCTION__);
    return self->DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
}

S_API uint32 SteamAPI_ISteamUser_GetVoiceOptimalSampleRate( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetVoiceOptimalSampleRate();
}

S_API HAuthTicket SteamAPI_ISteamUser_GetAuthSessionTicket( ISteamUser* self, void * pTicket, int cbMaxTicket, uint32 * pcbTicket )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API EBeginAuthSessionResult SteamAPI_ISteamUser_BeginAuthSession( ISteamUser* self, const void * pAuthTicket, int cbAuthTicket, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
}

S_API void SteamAPI_ISteamUser_EndAuthSession( ISteamUser* self, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    self->EndAuthSession(steamID);
}

S_API void SteamAPI_ISteamUser_CancelAuthTicket( ISteamUser* self, HAuthTicket hAuthTicket )
{
    VLOG_INFO(__FUNCTION__);
    self->CancelAuthTicket(hAuthTicket);
}

S_API EUserHasLicenseForAppResult SteamAPI_ISteamUser_UserHasLicenseForApp( ISteamUser* self, uint64_steamid steamID, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__);
    return self->UserHasLicenseForApp(steamID, appID);
}

S_API bool SteamAPI_ISteamUser_BIsBehindNAT( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsBehindNAT();
}

S_API void SteamAPI_ISteamUser_AdvertiseGame( ISteamUser* self, uint64_steamid steamIDGameServer, uint32 unIPServer, uint16 usPortServer )
{
    VLOG_INFO(__FUNCTION__);
    self->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
}

S_API SteamAPICall_t SteamAPI_ISteamUser_RequestEncryptedAppTicket( ISteamUser* self, void * pDataToInclude, int cbDataToInclude )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude);
}

S_API bool SteamAPI_ISteamUser_GetEncryptedAppTicket( ISteamUser* self, void * pTicket, int cbMaxTicket, uint32 * pcbTicket )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetEncryptedAppTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API int SteamAPI_ISteamUser_GetGameBadgeLevel( ISteamUser* self, int nSeries, bool bFoil )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGameBadgeLevel(nSeries, bFoil);
}

S_API int SteamAPI_ISteamUser_GetPlayerSteamLevel( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPlayerSteamLevel();
}

S_API SteamAPICall_t SteamAPI_ISteamUser_RequestStoreAuthURL( ISteamUser* self, const char * pchRedirectURL )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestStoreAuthURL(pchRedirectURL);
}

S_API bool SteamAPI_ISteamUser_BIsPhoneVerified( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsPhoneVerified();
}

S_API bool SteamAPI_ISteamUser_BIsTwoFactorEnabled( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsTwoFactorEnabled();
}

S_API bool SteamAPI_ISteamUser_BIsPhoneIdentifying( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsPhoneIdentifying();
}

S_API bool SteamAPI_ISteamUser_BIsPhoneRequiringVerification( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsPhoneRequiringVerification();
}

S_API SteamAPICall_t SteamAPI_ISteamUser_GetMarketEligibility( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMarketEligibility();
}

S_API SteamAPICall_t SteamAPI_ISteamUser_GetDurationControl( ISteamUser* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDurationControl();
}


//-----------------------------------------------------------------------------
// ISteamFriends flat API implementations
//-----------------------------------------------------------------------------

S_API const char * SteamAPI_ISteamFriends_GetPersonaName( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPersonaName();
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_SetPersonaName( ISteamFriends* self, const char * pchPersonaName )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetPersonaName(pchPersonaName);
}

S_API EPersonaState SteamAPI_ISteamFriends_GetPersonaState( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPersonaState();
}

S_API int SteamAPI_ISteamFriends_GetFriendCount( ISteamFriends* self, int iFriendFlags )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendCount(iFriendFlags);
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetFriendByIndex( ISteamFriends* self, int iFriend, int iFriendFlags )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendByIndex(iFriend, iFriendFlags).ConvertToUint64();
}

S_API EFriendRelationship SteamAPI_ISteamFriends_GetFriendRelationship( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendRelationship(steamIDFriend);
}

S_API EPersonaState SteamAPI_ISteamFriends_GetFriendPersonaState( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendPersonaState(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendPersonaName( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendPersonaName(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_GetFriendGamePlayed( ISteamFriends* self, uint64_steamid steamIDFriend, FriendGameInfo_t * pFriendGameInfo )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendGamePlayed(steamIDFriend, pFriendGameInfo);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendPersonaNameHistory( ISteamFriends* self, uint64_steamid steamIDFriend, int iPersonaName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
}

S_API int SteamAPI_ISteamFriends_GetFriendSteamLevel( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendSteamLevel(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetPlayerNickname( ISteamFriends* self, uint64_steamid steamIDPlayer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPlayerNickname(steamIDPlayer);
}

S_API int SteamAPI_ISteamFriends_GetFriendsGroupCount( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendsGroupCount();
}

S_API FriendsGroupID_t SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex( ISteamFriends* self, int iFG )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendsGroupIDByIndex(iFG);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendsGroupName( ISteamFriends* self, FriendsGroupID_t friendsGroupID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendsGroupName(friendsGroupID);
}

S_API int SteamAPI_ISteamFriends_GetFriendsGroupMembersCount( ISteamFriends* self, FriendsGroupID_t friendsGroupID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendsGroupMembersCount(friendsGroupID);
}

S_API void SteamAPI_ISteamFriends_GetFriendsGroupMembersList( ISteamFriends* self, FriendsGroupID_t friendsGroupID, CSteamID * pOutSteamIDMembers, int nMembersCount )
{
    VLOG_INFO(__FUNCTION__);
    self->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}

S_API bool SteamAPI_ISteamFriends_HasFriend( ISteamFriends* self, uint64_steamid steamIDFriend, int iFriendFlags )
{
    VLOG_INFO(__FUNCTION__);
    return self->HasFriend(steamIDFriend, iFriendFlags);
}

S_API int SteamAPI_ISteamFriends_GetClanCount( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanCount();
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetClanByIndex( ISteamFriends* self, int iClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanByIndex(iClan).ConvertToUint64();
}

S_API const char * SteamAPI_ISteamFriends_GetClanName( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanName(steamIDClan);
}

S_API const char * SteamAPI_ISteamFriends_GetClanTag( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanTag(steamIDClan);
}

S_API bool SteamAPI_ISteamFriends_GetClanActivityCounts( ISteamFriends* self, uint64_steamid steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanActivityCounts(steamIDClan, pnOnline, pnInGame, pnChatting);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_DownloadClanActivityCounts( ISteamFriends* self, CSteamID * psteamIDClans, int cClansToRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
}

S_API int SteamAPI_ISteamFriends_GetFriendCountFromSource( ISteamFriends* self, uint64_steamid steamIDSource )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendCountFromSource(steamIDSource);
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetFriendFromSourceByIndex( ISteamFriends* self, uint64_steamid steamIDSource, int iFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendFromSourceByIndex(steamIDSource, iFriend).ConvertToUint64();
}

S_API bool SteamAPI_ISteamFriends_IsUserInSource( ISteamFriends* self, uint64_steamid steamIDUser, uint64_steamid steamIDSource )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsUserInSource(steamIDUser, steamIDSource);
}

S_API void SteamAPI_ISteamFriends_SetInGameVoiceSpeaking( ISteamFriends* self, uint64_steamid steamIDUser, bool bSpeaking )
{
    VLOG_INFO(__FUNCTION__);
    self->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlay( ISteamFriends* self, const char * pchDialog )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlay(pchDialog);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToUser( ISteamFriends* self, const char * pchDialog, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlayToUser(pchDialog, steamID);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage( ISteamFriends* self, const char * pchURL, EActivateGameOverlayToWebPageMode eMode )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlayToWebPage(pchURL, eMode);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToStore( ISteamFriends* self, AppId_t nAppID, EOverlayToStoreFlag eFlag )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlayToStore(nAppID, eFlag);
}

S_API void SteamAPI_ISteamFriends_SetPlayedWith( ISteamFriends* self, uint64_steamid steamIDUserPlayedWith )
{
    VLOG_INFO(__FUNCTION__);
    self->SetPlayedWith(steamIDUserPlayedWith);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog( ISteamFriends* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlayInviteDialog(steamIDLobby);
}

S_API int SteamAPI_ISteamFriends_GetSmallFriendAvatar( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSmallFriendAvatar(steamIDFriend);
}

S_API int SteamAPI_ISteamFriends_GetMediumFriendAvatar( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMediumFriendAvatar(steamIDFriend);
}

S_API int SteamAPI_ISteamFriends_GetLargeFriendAvatar( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLargeFriendAvatar(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_RequestUserInformation( ISteamFriends* self, uint64_steamid steamIDUser, bool bRequireNameOnly )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestUserInformation(steamIDUser, bRequireNameOnly);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_RequestClanOfficerList( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestClanOfficerList(steamIDClan);
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetClanOwner( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanOwner(steamIDClan).ConvertToUint64();
}

S_API int SteamAPI_ISteamFriends_GetClanOfficerCount( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanOfficerCount(steamIDClan);
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetClanOfficerByIndex( ISteamFriends* self, uint64_steamid steamIDClan, int iOfficer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanOfficerByIndex(steamIDClan, iOfficer).ConvertToUint64();
}

S_API uint32 SteamAPI_ISteamFriends_GetUserRestrictions( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserRestrictions();
}

S_API bool SteamAPI_ISteamFriends_SetRichPresence( ISteamFriends* self, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetRichPresence(pchKey, pchValue);
}

S_API void SteamAPI_ISteamFriends_ClearRichPresence( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    self->ClearRichPresence();
}

S_API const char * SteamAPI_ISteamFriends_GetFriendRichPresence( ISteamFriends* self, uint64_steamid steamIDFriend, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendRichPresence(steamIDFriend, pchKey);
}

S_API int SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendRichPresenceKeyCount(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex( ISteamFriends* self, uint64_steamid steamIDFriend, int iKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
}

S_API void SteamAPI_ISteamFriends_RequestFriendRichPresence( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    self->RequestFriendRichPresence(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_InviteUserToGame( ISteamFriends* self, uint64_steamid steamIDFriend, const char * pchConnectString )
{
    VLOG_INFO(__FUNCTION__);
    return self->InviteUserToGame(steamIDFriend, pchConnectString);
}

S_API int SteamAPI_ISteamFriends_GetCoplayFriendCount( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCoplayFriendCount();
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetCoplayFriend( ISteamFriends* self, int iCoplayFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCoplayFriend(iCoplayFriend).ConvertToUint64();
}

S_API int SteamAPI_ISteamFriends_GetFriendCoplayTime( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendCoplayTime(steamIDFriend);
}

S_API AppId_t SteamAPI_ISteamFriends_GetFriendCoplayGame( ISteamFriends* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendCoplayGame(steamIDFriend);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_JoinClanChatRoom( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->JoinClanChatRoom(steamIDClan);
}

S_API bool SteamAPI_ISteamFriends_LeaveClanChatRoom( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->LeaveClanChatRoom(steamIDClan);
}

S_API int SteamAPI_ISteamFriends_GetClanChatMemberCount( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanChatMemberCount(steamIDClan);
}

S_API uint64_steamid SteamAPI_ISteamFriends_GetChatMemberByIndex( ISteamFriends* self, uint64_steamid steamIDClan, int iUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetChatMemberByIndex(steamIDClan, iUser).ConvertToUint64();
}

S_API bool SteamAPI_ISteamFriends_SendClanChatMessage( ISteamFriends* self, uint64_steamid steamIDClanChat, const char * pchText )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendClanChatMessage(steamIDClanChat, pchText);
}

S_API int SteamAPI_ISteamFriends_GetClanChatMessage( ISteamFriends* self, uint64_steamid steamIDClanChat, int iMessage, void * prgchText, int cchTextMax, EChatEntryType * peChatEntryType, CSteamID * psteamidChatter )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetClanChatMessage(steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}

S_API bool SteamAPI_ISteamFriends_IsClanChatAdmin( ISteamFriends* self, uint64_steamid steamIDClanChat, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsClanChatAdmin(steamIDClanChat, steamIDUser);
}

S_API bool SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam( ISteamFriends* self, uint64_steamid steamIDClanChat )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsClanChatWindowOpenInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_OpenClanChatWindowInSteam( ISteamFriends* self, uint64_steamid steamIDClanChat )
{
    VLOG_INFO(__FUNCTION__);
    return self->OpenClanChatWindowInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_CloseClanChatWindowInSteam( ISteamFriends* self, uint64_steamid steamIDClanChat )
{
    VLOG_INFO(__FUNCTION__);
    return self->CloseClanChatWindowInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_SetListenForFriendsMessages( ISteamFriends* self, bool bInterceptEnabled )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetListenForFriendsMessages(bInterceptEnabled);
}

S_API bool SteamAPI_ISteamFriends_ReplyToFriendMessage( ISteamFriends* self, uint64_steamid steamIDFriend, const char * pchMsgToSend )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
}

S_API int SteamAPI_ISteamFriends_GetFriendMessage( ISteamFriends* self, uint64_steamid steamIDFriend, int iMessageID, void * pvData, int cubData, EChatEntryType * peChatEntryType )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFriendMessage(steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_GetFollowerCount( ISteamFriends* self, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFollowerCount(steamID);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_IsFollowing( ISteamFriends* self, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsFollowing(steamID);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_EnumerateFollowingList( ISteamFriends* self, uint32 unStartIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumerateFollowingList(unStartIndex);
}

S_API bool SteamAPI_ISteamFriends_IsClanPublic( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsClanPublic(steamIDClan);
}

S_API bool SteamAPI_ISteamFriends_IsClanOfficialGameGroup( ISteamFriends* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsClanOfficialGameGroup(steamIDClan);
}

S_API int SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages( ISteamFriends* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumChatsWithUnreadPriorityMessages();
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog( ISteamFriends* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby);
}


//-----------------------------------------------------------------------------
// ISteamUtils flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceAppActive( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSecondsSinceAppActive();
}

S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceComputerActive( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSecondsSinceComputerActive();
}

S_API EUniverse SteamAPI_ISteamUtils_GetConnectedUniverse( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectedUniverse();
}

S_API uint32 SteamAPI_ISteamUtils_GetServerRealTime( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetServerRealTime();
}

S_API const char * SteamAPI_ISteamUtils_GetIPCountry( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetIPCountry();
}

S_API bool SteamAPI_ISteamUtils_GetImageSize( ISteamUtils* self, int iImage, uint32 * pnWidth, uint32 * pnHeight )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetImageSize(iImage, pnWidth, pnHeight);
}

S_API bool SteamAPI_ISteamUtils_GetImageRGBA( ISteamUtils* self, int iImage, uint8 * pubDest, int nDestBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetImageRGBA(iImage, pubDest, nDestBufferSize);
}

S_API bool SteamAPI_ISteamUtils_GetCSERIPPort( ISteamUtils* self, uint32 * unIP, uint16 * usPort )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCSERIPPort(unIP, usPort);
}

S_API uint8 SteamAPI_ISteamUtils_GetCurrentBatteryPower( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCurrentBatteryPower();
}

S_API uint32 SteamAPI_ISteamUtils_GetAppID( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppID();
}

S_API void SteamAPI_ISteamUtils_SetOverlayNotificationPosition( ISteamUtils* self, ENotificationPosition eNotificationPosition )
{
    VLOG_INFO(__FUNCTION__);
    self->SetOverlayNotificationPosition(eNotificationPosition);
}

S_API bool SteamAPI_ISteamUtils_IsAPICallCompleted( ISteamUtils* self, SteamAPICall_t hSteamAPICall, bool * pbFailed )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsAPICallCompleted(hSteamAPICall, pbFailed);
}

S_API ESteamAPICallFailure SteamAPI_ISteamUtils_GetAPICallFailureReason( ISteamUtils* self, SteamAPICall_t hSteamAPICall )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAPICallFailureReason(hSteamAPICall);
}

S_API bool SteamAPI_ISteamUtils_GetAPICallResult( ISteamUtils* self, SteamAPICall_t hSteamAPICall, void * pCallback, int cubCallback, int iCallbackExpected, bool * pbFailed )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAPICallResult(hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
}

S_API uint32 SteamAPI_ISteamUtils_GetIPCCallCount( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetIPCCallCount();
}

S_API void SteamAPI_ISteamUtils_SetWarningMessageHook( ISteamUtils* self, SteamAPIWarningMessageHook_t pFunction )
{
    VLOG_INFO(__FUNCTION__);
    self->SetWarningMessageHook(pFunction);
}

S_API bool SteamAPI_ISteamUtils_IsOverlayEnabled( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsOverlayEnabled();
}

S_API bool SteamAPI_ISteamUtils_BOverlayNeedsPresent( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BOverlayNeedsPresent();
}

S_API SteamAPICall_t SteamAPI_ISteamUtils_CheckFileSignature( ISteamUtils* self, const char * szFileName )
{
    VLOG_INFO(__FUNCTION__);
    return self->CheckFileSignature(szFileName);
}

S_API bool SteamAPI_ISteamUtils_ShowGamepadTextInput( ISteamUtils* self, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText )
{
    VLOG_INFO(__FUNCTION__);
    return self->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
}

S_API uint32 SteamAPI_ISteamUtils_GetEnteredGamepadTextLength( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetEnteredGamepadTextLength();
}

S_API bool SteamAPI_ISteamUtils_GetEnteredGamepadTextInput( ISteamUtils* self, char * pchText, uint32 cchText )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetEnteredGamepadTextInput(pchText, cchText);
}

S_API const char * SteamAPI_ISteamUtils_GetSteamUILanguage( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSteamUILanguage();
}

S_API bool SteamAPI_ISteamUtils_IsSteamRunningInVR( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsSteamRunningInVR();
}

S_API void SteamAPI_ISteamUtils_SetOverlayNotificationInset( ISteamUtils* self, int nHorizontalInset, int nVerticalInset )
{
    VLOG_INFO(__FUNCTION__);
    self->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
}

S_API bool SteamAPI_ISteamUtils_IsSteamInBigPictureMode( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsSteamInBigPictureMode();
}

S_API void SteamAPI_ISteamUtils_StartVRDashboard( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    self->StartVRDashboard();
}

S_API bool SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsVRHeadsetStreamingEnabled();
}

S_API void SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled( ISteamUtils* self, bool bEnabled )
{
    VLOG_INFO(__FUNCTION__);
    self->SetVRHeadsetStreamingEnabled(bEnabled);
}

S_API bool SteamAPI_ISteamUtils_IsSteamChinaLauncher( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsSteamChinaLauncher();
}

S_API bool SteamAPI_ISteamUtils_InitFilterText( ISteamUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->InitFilterText();
}

S_API int SteamAPI_ISteamUtils_FilterText( ISteamUtils* self, char * pchOutFilteredText, uint32 nByteSizeOutFilteredText, const char * pchInputMessage, bool bLegalOnly )
{
    VLOG_INFO(__FUNCTION__);
    return self->FilterText(pchOutFilteredText, nByteSizeOutFilteredText, pchInputMessage, bLegalOnly);
}

S_API ESteamIPv6ConnectivityState SteamAPI_ISteamUtils_GetIPv6ConnectivityState( ISteamUtils* self, ESteamIPv6ConnectivityProtocol eProtocol )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetIPv6ConnectivityState(eProtocol);
}


//-----------------------------------------------------------------------------
// ISteamMatchmaking flat API implementations
//-----------------------------------------------------------------------------

S_API int SteamAPI_ISteamMatchmaking_GetFavoriteGameCount( ISteamMatchmaking* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFavoriteGameCount();
}

S_API bool SteamAPI_ISteamMatchmaking_GetFavoriteGame( ISteamMatchmaking* self, int iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
}

S_API int SteamAPI_ISteamMatchmaking_AddFavoriteGame( ISteamMatchmaking* self, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
}

S_API bool SteamAPI_ISteamMatchmaking_RemoveFavoriteGame( ISteamMatchmaking* self, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_RequestLobbyList( ISteamMatchmaking* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestLobbyList();
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter( ISteamMatchmaking* self, const char * pchKeyToMatch, const char * pchValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter( ISteamMatchmaking* self, const char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter( ISteamMatchmaking* self, const char * pchKeyToMatch, int nValueToBeCloseTo )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable( ISteamMatchmaking* self, int nSlotsAvailable )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter( ISteamMatchmaking* self, ELobbyDistanceFilter eLobbyDistanceFilter )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter( ISteamMatchmaking* self, int cMaxResults )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListResultCountFilter(cMaxResults);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    self->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
}

S_API uint64_steamid SteamAPI_ISteamMatchmaking_GetLobbyByIndex( ISteamMatchmaking* self, int iLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyByIndex(iLobby).ConvertToUint64();
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_CreateLobby( ISteamMatchmaking* self, ELobbyType eLobbyType, int cMaxMembers )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateLobby(eLobbyType, cMaxMembers);
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_JoinLobby( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->JoinLobby(steamIDLobby);
}

S_API void SteamAPI_ISteamMatchmaking_LeaveLobby( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    self->LeaveLobby(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_InviteUserToLobby( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint64_steamid steamIDInvitee )
{
    VLOG_INFO(__FUNCTION__);
    return self->InviteUserToLobby(steamIDLobby, steamIDInvitee);
}

S_API int SteamAPI_ISteamMatchmaking_GetNumLobbyMembers( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumLobbyMembers(steamIDLobby);
}

S_API uint64_steamid SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex( ISteamMatchmaking* self, uint64_steamid steamIDLobby, int iMember )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyMemberByIndex(steamIDLobby, iMember).ConvertToUint64();
}

S_API const char * SteamAPI_ISteamMatchmaking_GetLobbyData( ISteamMatchmaking* self, uint64_steamid steamIDLobby, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyData(steamIDLobby, pchKey);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyData( ISteamMatchmaking* self, uint64_steamid steamIDLobby, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLobbyData(steamIDLobby, pchKey, pchValue);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyDataCount( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyDataCount(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex( ISteamMatchmaking* self, uint64_steamid steamIDLobby, int iLobbyData, char * pchKey, int cchKeyBufferSize, char * pchValue, int cchValueBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
}

S_API bool SteamAPI_ISteamMatchmaking_DeleteLobbyData( ISteamMatchmaking* self, uint64_steamid steamIDLobby, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeleteLobbyData(steamIDLobby, pchKey);
}

S_API const char * SteamAPI_ISteamMatchmaking_GetLobbyMemberData( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint64_steamid steamIDUser, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
}

S_API void SteamAPI_ISteamMatchmaking_SetLobbyMemberData( ISteamMatchmaking* self, uint64_steamid steamIDLobby, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    self->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
}

S_API bool SteamAPI_ISteamMatchmaking_SendLobbyChatMsg( ISteamMatchmaking* self, uint64_steamid steamIDLobby, const void * pvMsgBody, int cubMsgBody )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyChatEntry( ISteamMatchmaking* self, uint64_steamid steamIDLobby, int iChatID, CSteamID * pSteamIDUser, void * pvData, int cubData, EChatEntryType * peChatEntryType )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
}

S_API bool SteamAPI_ISteamMatchmaking_RequestLobbyData( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestLobbyData(steamIDLobby);
}

S_API void SteamAPI_ISteamMatchmaking_SetLobbyGameServer( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, uint64_steamid steamIDGameServer )
{
    VLOG_INFO(__FUNCTION__);
    self->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
}

S_API bool SteamAPI_ISteamMatchmaking_GetLobbyGameServer( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit( ISteamMatchmaking* self, uint64_steamid steamIDLobby, int cMaxMembers )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyMemberLimit(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyType( ISteamMatchmaking* self, uint64_steamid steamIDLobby, ELobbyType eLobbyType )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLobbyType(steamIDLobby, eLobbyType);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyJoinable( ISteamMatchmaking* self, uint64_steamid steamIDLobby, bool bLobbyJoinable )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
}

S_API uint64_steamid SteamAPI_ISteamMatchmaking_GetLobbyOwner( ISteamMatchmaking* self, uint64_steamid steamIDLobby )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLobbyOwner(steamIDLobby).ConvertToUint64();
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyOwner( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint64_steamid steamIDNewOwner )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLinkedLobby( ISteamMatchmaking* self, uint64_steamid steamIDLobby, uint64_steamid steamIDLobbyDependent )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent);
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingServerListResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded( ISteamMatchmakingServerListResponse* self, HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__);
    self->ServerResponded(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond( ISteamMatchmakingServerListResponse* self, HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__);
    self->ServerFailedToRespond(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete( ISteamMatchmakingServerListResponse* self, HServerListRequest hRequest, EMatchMakingServerResponse response )
{
    VLOG_INFO(__FUNCTION__);
    self->RefreshComplete(hRequest, response);
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingPingResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingPingResponse_ServerResponded( ISteamMatchmakingPingResponse* self, gameserveritem_t & server )
{
    VLOG_INFO(__FUNCTION__);
    self->ServerResponded(server);
}

S_API void SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond( ISteamMatchmakingPingResponse* self )
{
    VLOG_INFO(__FUNCTION__);
    self->ServerFailedToRespond();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingPlayersResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList( ISteamMatchmakingPlayersResponse* self, const char * pchName, int nScore, float flTimePlayed )
{
    VLOG_INFO(__FUNCTION__);
    self->AddPlayerToList(pchName, nScore, flTimePlayed);
}

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond( ISteamMatchmakingPlayersResponse* self )
{
    VLOG_INFO(__FUNCTION__);
    self->PlayersFailedToRespond();
}

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete( ISteamMatchmakingPlayersResponse* self )
{
    VLOG_INFO(__FUNCTION__);
    self->PlayersRefreshComplete();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingRulesResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded( ISteamMatchmakingRulesResponse* self, const char * pchRule, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    self->RulesResponded(pchRule, pchValue);
}

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond( ISteamMatchmakingRulesResponse* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RulesFailedToRespond();
}

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete( ISteamMatchmakingRulesResponse* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RulesRefreshComplete();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingServers flat API implementations
//-----------------------------------------------------------------------------

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestInternetServerList( ISteamMatchmakingServers* self, AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestLANServerList( ISteamMatchmakingServers* self, AppId_t iApp, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestLANServerList(iApp, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList( ISteamMatchmakingServers* self, AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList( ISteamMatchmakingServers* self, AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList( ISteamMatchmakingServers* self, AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList( ISteamMatchmakingServers* self, AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API void SteamAPI_ISteamMatchmakingServers_ReleaseRequest( ISteamMatchmakingServers* self, HServerListRequest hServerListRequest )
{
    VLOG_INFO(__FUNCTION__);
    self->ReleaseRequest(hServerListRequest);
}

S_API gameserveritem_t * SteamAPI_ISteamMatchmakingServers_GetServerDetails( ISteamMatchmakingServers* self, HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetServerDetails(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServers_CancelQuery( ISteamMatchmakingServers* self, HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__);
    self->CancelQuery(hRequest);
}

S_API void SteamAPI_ISteamMatchmakingServers_RefreshQuery( ISteamMatchmakingServers* self, HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__);
    self->RefreshQuery(hRequest);
}

S_API bool SteamAPI_ISteamMatchmakingServers_IsRefreshing( ISteamMatchmakingServers* self, HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsRefreshing(hRequest);
}

S_API int SteamAPI_ISteamMatchmakingServers_GetServerCount( ISteamMatchmakingServers* self, HServerListRequest hRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetServerCount(hRequest);
}

S_API void SteamAPI_ISteamMatchmakingServers_RefreshServer( ISteamMatchmakingServers* self, HServerListRequest hRequest, int iServer )
{
    VLOG_INFO(__FUNCTION__);
    self->RefreshServer(hRequest, iServer);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_PingServer( ISteamMatchmakingServers* self, uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->PingServer(unIP, usPort, pRequestServersResponse);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_PlayerDetails( ISteamMatchmakingServers* self, uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->PlayerDetails(unIP, usPort, pRequestServersResponse);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_ServerRules( ISteamMatchmakingServers* self, uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse * pRequestServersResponse )
{
    VLOG_INFO(__FUNCTION__);
    return self->ServerRules(unIP, usPort, pRequestServersResponse);
}

S_API void SteamAPI_ISteamMatchmakingServers_CancelServerQuery( ISteamMatchmakingServers* self, HServerQuery hServerQuery )
{
    VLOG_INFO(__FUNCTION__);
    self->CancelServerQuery(hServerQuery);
}


//-----------------------------------------------------------------------------
// ISteamGameSearch flat API implementations
//-----------------------------------------------------------------------------

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_AddGameSearchParams( ISteamGameSearch* self, const char * pchKeyToFind, const char * pchValuesToFind )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddGameSearchParams(pchKeyToFind, pchValuesToFind);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_SearchForGameWithLobby( ISteamGameSearch* self, uint64_steamid steamIDLobby, int nPlayerMin, int nPlayerMax )
{
    VLOG_INFO(__FUNCTION__);
    return self->SearchForGameWithLobby(steamIDLobby, nPlayerMin, nPlayerMax);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_SearchForGameSolo( ISteamGameSearch* self, int nPlayerMin, int nPlayerMax )
{
    VLOG_INFO(__FUNCTION__);
    return self->SearchForGameSolo(nPlayerMin, nPlayerMax);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_AcceptGame( ISteamGameSearch* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->AcceptGame();
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_DeclineGame( ISteamGameSearch* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeclineGame();
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_RetrieveConnectionDetails( ISteamGameSearch* self, uint64_steamid steamIDHost, char * pchConnectionDetails, int cubConnectionDetails )
{
    VLOG_INFO(__FUNCTION__);
    return self->RetrieveConnectionDetails(steamIDHost, pchConnectionDetails, cubConnectionDetails);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_EndGameSearch( ISteamGameSearch* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->EndGameSearch();
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_SetGameHostParams( ISteamGameSearch* self, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetGameHostParams(pchKey, pchValue);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_SetConnectionDetails( ISteamGameSearch* self, const char * pchConnectionDetails, int cubConnectionDetails )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionDetails(pchConnectionDetails, cubConnectionDetails);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_RequestPlayersForGame( ISteamGameSearch* self, int nPlayerMin, int nPlayerMax, int nMaxTeamSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestPlayersForGame(nPlayerMin, nPlayerMax, nMaxTeamSize);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_HostConfirmGameStart( ISteamGameSearch* self, uint64 ullUniqueGameID )
{
    VLOG_INFO(__FUNCTION__);
    return self->HostConfirmGameStart(ullUniqueGameID);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame( ISteamGameSearch* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CancelRequestPlayersForGame();
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_SubmitPlayerResult( ISteamGameSearch* self, uint64 ullUniqueGameID, uint64_steamid steamIDPlayer, EPlayerResult_t EPlayerResult )
{
    VLOG_INFO(__FUNCTION__);
    return self->SubmitPlayerResult(ullUniqueGameID, steamIDPlayer, EPlayerResult);
}

S_API EGameSearchErrorCode_t SteamAPI_ISteamGameSearch_EndGame( ISteamGameSearch* self, uint64 ullUniqueGameID )
{
    VLOG_INFO(__FUNCTION__);
    return self->EndGame(ullUniqueGameID);
}


//-----------------------------------------------------------------------------
// ISteamParties flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamParties_GetNumActiveBeacons( ISteamParties* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumActiveBeacons();
}

S_API PartyBeaconID_t SteamAPI_ISteamParties_GetBeaconByIndex( ISteamParties* self, uint32 unIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetBeaconByIndex(unIndex);
}

S_API bool SteamAPI_ISteamParties_GetBeaconDetails( ISteamParties* self, PartyBeaconID_t ulBeaconID, CSteamID * pSteamIDBeaconOwner, SteamPartyBeaconLocation_t * pLocation, char * pchMetadata, int cchMetadata )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetBeaconDetails(ulBeaconID, pSteamIDBeaconOwner, pLocation, pchMetadata, cchMetadata);
}

S_API SteamAPICall_t SteamAPI_ISteamParties_JoinParty( ISteamParties* self, PartyBeaconID_t ulBeaconID )
{
    VLOG_INFO(__FUNCTION__);
    return self->JoinParty(ulBeaconID);
}

S_API bool SteamAPI_ISteamParties_GetNumAvailableBeaconLocations( ISteamParties* self, uint32 * puNumLocations )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumAvailableBeaconLocations(puNumLocations);
}

S_API bool SteamAPI_ISteamParties_GetAvailableBeaconLocations( ISteamParties* self, SteamPartyBeaconLocation_t * pLocationList, uint32 uMaxNumLocations )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAvailableBeaconLocations(pLocationList, uMaxNumLocations);
}

S_API SteamAPICall_t SteamAPI_ISteamParties_CreateBeacon( ISteamParties* self, uint32 unOpenSlots, SteamPartyBeaconLocation_t * pBeaconLocation, const char * pchConnectString, const char * pchMetadata )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateBeacon(unOpenSlots, pBeaconLocation, pchConnectString, pchMetadata);
}

S_API void SteamAPI_ISteamParties_OnReservationCompleted( ISteamParties* self, PartyBeaconID_t ulBeacon, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    self->OnReservationCompleted(ulBeacon, steamIDUser);
}

S_API void SteamAPI_ISteamParties_CancelReservation( ISteamParties* self, PartyBeaconID_t ulBeacon, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    self->CancelReservation(ulBeacon, steamIDUser);
}

S_API SteamAPICall_t SteamAPI_ISteamParties_ChangeNumOpenSlots( ISteamParties* self, PartyBeaconID_t ulBeacon, uint32 unOpenSlots )
{
    VLOG_INFO(__FUNCTION__);
    return self->ChangeNumOpenSlots(ulBeacon, unOpenSlots);
}

S_API bool SteamAPI_ISteamParties_DestroyBeacon( ISteamParties* self, PartyBeaconID_t ulBeacon )
{
    VLOG_INFO(__FUNCTION__);
    return self->DestroyBeacon(ulBeacon);
}

S_API bool SteamAPI_ISteamParties_GetBeaconLocationData( ISteamParties* self, SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eData, char * pchDataStringOut, int cchDataStringOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetBeaconLocationData(BeaconLocation, eData, pchDataStringOut, cchDataStringOut);
}


//-----------------------------------------------------------------------------
// ISteamRemoteStorage flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamRemoteStorage_FileWrite( ISteamRemoteStorage* self, const char * pchFile, const void * pvData, int32 cubData )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWrite(pchFile, pvData, cubData);
}

S_API int32 SteamAPI_ISteamRemoteStorage_FileRead( ISteamRemoteStorage* self, const char * pchFile, void * pvData, int32 cubDataToRead )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileRead(pchFile, pvData, cubDataToRead);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_FileWriteAsync( ISteamRemoteStorage* self, const char * pchFile, const void * pvData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWriteAsync(pchFile, pvData, cubData);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_FileReadAsync( ISteamRemoteStorage* self, const char * pchFile, uint32 nOffset, uint32 cubToRead )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileReadAsync(pchFile, nOffset, cubToRead);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete( ISteamRemoteStorage* self, SteamAPICall_t hReadCall, void * pvBuffer, uint32 cubToRead )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileReadAsyncComplete(hReadCall, pvBuffer, cubToRead);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileForget( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileForget(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileDelete( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileDelete(pchFile);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_FileShare( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileShare(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_SetSyncPlatforms( ISteamRemoteStorage* self, const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
}

S_API UGCFileWriteStreamHandle_t SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWriteStreamOpen(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk( ISteamRemoteStorage* self, UGCFileWriteStreamHandle_t writeHandle, const void * pvData, int32 cubData )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamClose( ISteamRemoteStorage* self, UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWriteStreamClose(writeHandle);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel( ISteamRemoteStorage* self, UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileWriteStreamCancel(writeHandle);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileExists( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FileExists(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FilePersisted( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->FilePersisted(pchFile);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetFileSize( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFileSize(pchFile);
}

S_API int64 SteamAPI_ISteamRemoteStorage_GetFileTimestamp( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFileTimestamp(pchFile);
}

S_API ERemoteStoragePlatform SteamAPI_ISteamRemoteStorage_GetSyncPlatforms( ISteamRemoteStorage* self, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSyncPlatforms(pchFile);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetFileCount( ISteamRemoteStorage* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFileCount();
}

S_API const char * SteamAPI_ISteamRemoteStorage_GetFileNameAndSize( ISteamRemoteStorage* self, int iFile, int32 * pnFileSizeInBytes )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFileNameAndSize(iFile, pnFileSizeInBytes);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetQuota( ISteamRemoteStorage* self, uint64 * pnTotalBytes, uint64 * puAvailableBytes )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQuota(pnTotalBytes, puAvailableBytes);
}

S_API bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount( ISteamRemoteStorage* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsCloudEnabledForAccount();
}

S_API bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp( ISteamRemoteStorage* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsCloudEnabledForApp();
}

S_API void SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp( ISteamRemoteStorage* self, bool bEnabled )
{
    VLOG_INFO(__FUNCTION__);
    self->SetCloudEnabledForApp(bEnabled);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownload( ISteamRemoteStorage* self, UGCHandle_t hContent, uint32 unPriority )
{
    VLOG_INFO(__FUNCTION__);
    return self->UGCDownload(hContent, unPriority);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress( ISteamRemoteStorage* self, UGCHandle_t hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUGCDownloadProgress(hContent, pnBytesDownloaded, pnBytesExpected);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetUGCDetails( ISteamRemoteStorage* self, UGCHandle_t hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, CSteamID * pSteamIDOwner )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
}

S_API int32 SteamAPI_ISteamRemoteStorage_UGCRead( ISteamRemoteStorage* self, UGCHandle_t hContent, void * pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction )
{
    VLOG_INFO(__FUNCTION__);
    return self->UGCRead(hContent, pvData, cubDataToRead, cOffset, eAction);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetCachedUGCCount( ISteamRemoteStorage* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCachedUGCCount();
}

S_API UGCHandle_t SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle( ISteamRemoteStorage* self, int32 iCachedContent )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCachedUGCHandle(iCachedContent);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishWorkshopFile( ISteamRemoteStorage* self, const char * pchFile, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType eWorkshopFileType )
{
    VLOG_INFO(__FUNCTION__);
    return self->PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
}

S_API PublishedFileUpdateHandle_t SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreatePublishedFileUpdateRequest(unPublishedFileId);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, const char * pchFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileFile(updateHandle, pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, const char * pchTitle )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileTitle(updateHandle, pchTitle);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, const char * pchDescription )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileDescription(updateHandle, pchDescription);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileVisibility(updateHandle, eVisibility);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t * pTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileTags(updateHandle, pTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->CommitPublishedFileUpdate(updateHandle);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_DeletePublishedFile( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeletePublishedFile(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles( ISteamRemoteStorage* self, uint32 unStartIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumerateUserPublishedFiles(unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_SubscribePublishedFile( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->SubscribePublishedFile(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles( ISteamRemoteStorage* self, uint32 unStartIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumerateUserSubscribedFiles(unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->UnsubscribePublishedFile(unPublishedFileId);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription( ISteamRemoteStorage* self, PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPublishedItemVoteDetails(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId, bool bVoteUp )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserPublishedItemVoteDetails(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles( ISteamRemoteStorage* self, uint64_steamid steamId, uint32 unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, pRequiredTags, pExcludedTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishVideo( ISteamRemoteStorage* self, EWorkshopVideoProvider eVideoProvider, const char * pchVideoAccount, const char * pchVideoIdentifier, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t * pTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction( ISteamRemoteStorage* self, PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetUserPublishedFileAction(unPublishedFileId, eAction);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction( ISteamRemoteStorage* self, EWorkshopFileAction eAction, uint32 unStartIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles( ISteamRemoteStorage* self, EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation( ISteamRemoteStorage* self, UGCHandle_t hContent, const char * pchLocation, uint32 unPriority )
{
    VLOG_INFO(__FUNCTION__);
    return self->UGCDownloadToLocation(hContent, pchLocation, unPriority);
}


//-----------------------------------------------------------------------------
// ISteamUserStats flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamUserStats_RequestCurrentStats( ISteamUserStats* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestCurrentStats();
}

S_API bool SteamAPI_ISteamUserStats_GetStatInt32( ISteamUserStats* self, const char * pchName, int32 * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetStatFloat( ISteamUserStats* self, const char * pchName, float * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_SetStatInt32( ISteamUserStats* self, const char * pchName, int32 nData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetStat(pchName, nData);
}

S_API bool SteamAPI_ISteamUserStats_SetStatFloat( ISteamUserStats* self, const char * pchName, float fData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetStat(pchName, fData);
}

S_API bool SteamAPI_ISteamUserStats_UpdateAvgRateStat( ISteamUserStats* self, const char * pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievement( ISteamUserStats* self, const char * pchName, bool * pbAchieved )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievement(pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_SetAchievement( ISteamUserStats* self, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetAchievement(pchName);
}

S_API bool SteamAPI_ISteamUserStats_ClearAchievement( ISteamUserStats* self, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->ClearAchievement(pchName);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime( ISteamUserStats* self, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievementAndUnlockTime(pchName, pbAchieved, punUnlockTime);
}

S_API bool SteamAPI_ISteamUserStats_StoreStats( ISteamUserStats* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->StoreStats();
}

S_API int SteamAPI_ISteamUserStats_GetAchievementIcon( ISteamUserStats* self, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievementIcon(pchName);
}

S_API const char * SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute( ISteamUserStats* self, const char * pchName, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievementDisplayAttribute(pchName, pchKey);
}

S_API bool SteamAPI_ISteamUserStats_IndicateAchievementProgress( ISteamUserStats* self, const char * pchName, uint32 nCurProgress, uint32 nMaxProgress )
{
    VLOG_INFO(__FUNCTION__);
    return self->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
}

S_API uint32 SteamAPI_ISteamUserStats_GetNumAchievements( ISteamUserStats* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumAchievements();
}

S_API const char * SteamAPI_ISteamUserStats_GetAchievementName( ISteamUserStats* self, uint32 iAchievement )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievementName(iAchievement);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestUserStats( ISteamUserStats* self, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestUserStats(steamIDUser);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStatInt32( ISteamUserStats* self, uint64_steamid steamIDUser, const char * pchName, int32 * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStatFloat( ISteamUserStats* self, uint64_steamid steamIDUser, const char * pchName, float * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserAchievement( ISteamUserStats* self, uint64_steamid steamIDUser, const char * pchName, bool * pbAchieved )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserAchievement(steamIDUser, pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime( ISteamUserStats* self, uint64_steamid steamIDUser, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserAchievementAndUnlockTime(steamIDUser, pchName, pbAchieved, punUnlockTime);
}

S_API bool SteamAPI_ISteamUserStats_ResetAllStats( ISteamUserStats* self, bool bAchievementsToo )
{
    VLOG_INFO(__FUNCTION__);
    return self->ResetAllStats(bAchievementsToo);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard( ISteamUserStats* self, const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType )
{
    VLOG_INFO(__FUNCTION__);
    return self->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_FindLeaderboard( ISteamUserStats* self, const char * pchLeaderboardName )
{
    VLOG_INFO(__FUNCTION__);
    return self->FindLeaderboard(pchLeaderboardName);
}

S_API const char * SteamAPI_ISteamUserStats_GetLeaderboardName( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLeaderboardName(hSteamLeaderboard);
}

S_API int SteamAPI_ISteamUserStats_GetLeaderboardEntryCount( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLeaderboardEntryCount(hSteamLeaderboard);
}

S_API ELeaderboardSortMethod SteamAPI_ISteamUserStats_GetLeaderboardSortMethod( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLeaderboardSortMethod(hSteamLeaderboard);
}

S_API ELeaderboardDisplayType SteamAPI_ISteamUserStats_GetLeaderboardDisplayType( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLeaderboardDisplayType(hSteamLeaderboard);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntries( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
{
    VLOG_INFO(__FUNCTION__);
    return self->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard, CSteamID * prgUsers, int cUsers )
{
    VLOG_INFO(__FUNCTION__);
    return self->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers);
}

S_API bool SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry( ISteamUserStats* self, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int cDetailsMax )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_UploadLeaderboardScore( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 * pScoreDetails, int cScoreDetailsCount )
{
    VLOG_INFO(__FUNCTION__);
    return self->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_AttachLeaderboardUGC( ISteamUserStats* self, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC )
{
    VLOG_INFO(__FUNCTION__);
    return self->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers( ISteamUserStats* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumberOfCurrentPlayers();
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages( ISteamUserStats* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestGlobalAchievementPercentages();
}

S_API int SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo( ISteamUserStats* self, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMostAchievedAchievementInfo(pchName, unNameBufLen, pflPercent, pbAchieved);
}

S_API int SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo( ISteamUserStats* self, int iIteratorPrevious, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievementAchievedPercent( ISteamUserStats* self, const char * pchName, float * pflPercent )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAchievementAchievedPercent(pchName, pflPercent);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalStats( ISteamUserStats* self, int nHistoryDays )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestGlobalStats(nHistoryDays);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStatInt64( ISteamUserStats* self, const char * pchStatName, int64 * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlobalStat(pchStatName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStatDouble( ISteamUserStats* self, const char * pchStatName, double * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlobalStat(pchStatName, pData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64( ISteamUserStats* self, const char * pchStatName, int64 * pData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlobalStatHistory(pchStatName, pData, cubData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble( ISteamUserStats* self, const char * pchStatName, double * pData, uint32 cubData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlobalStatHistory(pchStatName, pData, cubData);
}


//-----------------------------------------------------------------------------
// ISteamApps flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamApps_BIsSubscribed( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsSubscribed();
}

S_API bool SteamAPI_ISteamApps_BIsLowViolence( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsLowViolence();
}

S_API bool SteamAPI_ISteamApps_BIsCybercafe( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsCybercafe();
}

S_API bool SteamAPI_ISteamApps_BIsVACBanned( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsVACBanned();
}

S_API const char * SteamAPI_ISteamApps_GetCurrentGameLanguage( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCurrentGameLanguage();
}

S_API const char * SteamAPI_ISteamApps_GetAvailableGameLanguages( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAvailableGameLanguages();
}

S_API bool SteamAPI_ISteamApps_BIsSubscribedApp( ISteamApps* self, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsSubscribedApp(appID);
}

S_API bool SteamAPI_ISteamApps_BIsDlcInstalled( ISteamApps* self, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsDlcInstalled(appID);
}

S_API uint32 SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime( ISteamApps* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetEarliestPurchaseUnixTime(nAppID);
}

S_API bool SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsSubscribedFromFreeWeekend();
}

S_API int SteamAPI_ISteamApps_GetDLCCount( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDLCCount();
}

S_API bool SteamAPI_ISteamApps_BGetDLCDataByIndex( ISteamApps* self, int iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int cchNameBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->BGetDLCDataByIndex(iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
}

S_API void SteamAPI_ISteamApps_InstallDLC( ISteamApps* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    self->InstallDLC(nAppID);
}

S_API void SteamAPI_ISteamApps_UninstallDLC( ISteamApps* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    self->UninstallDLC(nAppID);
}

S_API void SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey( ISteamApps* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    self->RequestAppProofOfPurchaseKey(nAppID);
}

S_API bool SteamAPI_ISteamApps_GetCurrentBetaName( ISteamApps* self, char * pchName, int cchNameBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCurrentBetaName(pchName, cchNameBufferSize);
}

S_API bool SteamAPI_ISteamApps_MarkContentCorrupt( ISteamApps* self, bool bMissingFilesOnly )
{
    VLOG_INFO(__FUNCTION__);
    return self->MarkContentCorrupt(bMissingFilesOnly);
}

S_API uint32 SteamAPI_ISteamApps_GetInstalledDepots( ISteamApps* self, AppId_t appID, DepotId_t * pvecDepots, uint32 cMaxDepots )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetInstalledDepots(appID, pvecDepots, cMaxDepots);
}

S_API uint32 SteamAPI_ISteamApps_GetAppInstallDir( ISteamApps* self, AppId_t appID, char * pchFolder, uint32 cchFolderBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
}

S_API bool SteamAPI_ISteamApps_BIsAppInstalled( ISteamApps* self, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsAppInstalled(appID);
}

S_API uint64_steamid SteamAPI_ISteamApps_GetAppOwner( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppOwner().ConvertToUint64();
}

S_API const char * SteamAPI_ISteamApps_GetLaunchQueryParam( ISteamApps* self, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLaunchQueryParam(pchKey);
}

S_API bool SteamAPI_ISteamApps_GetDlcDownloadProgress( ISteamApps* self, AppId_t nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
}

S_API int SteamAPI_ISteamApps_GetAppBuildId( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppBuildId();
}

S_API void SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RequestAllProofOfPurchaseKeys();
}

S_API SteamAPICall_t SteamAPI_ISteamApps_GetFileDetails( ISteamApps* self, const char * pszFileName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFileDetails(pszFileName);
}

S_API int SteamAPI_ISteamApps_GetLaunchCommandLine( ISteamApps* self, char * pszCommandLine, int cubCommandLine )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLaunchCommandLine(pszCommandLine, cubCommandLine);
}

S_API bool SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing( ISteamApps* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsSubscribedFromFamilySharing();
}


//-----------------------------------------------------------------------------
// ISteamNetworking flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamNetworking_SendP2PPacket( ISteamNetworking* self, uint64_steamid steamIDRemote, const void * pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_IsP2PPacketAvailable( ISteamNetworking* self, uint32 * pcubMsgSize, int nChannel )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsP2PPacketAvailable(pcubMsgSize, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_ReadP2PPacket( ISteamNetworking* self, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, CSteamID * psteamIDRemote, int nChannel )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReadP2PPacket(pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser( ISteamNetworking* self, uint64_steamid steamIDRemote )
{
    VLOG_INFO(__FUNCTION__);
    return self->AcceptP2PSessionWithUser(steamIDRemote);
}

S_API bool SteamAPI_ISteamNetworking_CloseP2PSessionWithUser( ISteamNetworking* self, uint64_steamid steamIDRemote )
{
    VLOG_INFO(__FUNCTION__);
    return self->CloseP2PSessionWithUser(steamIDRemote);
}

S_API bool SteamAPI_ISteamNetworking_CloseP2PChannelWithUser( ISteamNetworking* self, uint64_steamid steamIDRemote, int nChannel )
{
    VLOG_INFO(__FUNCTION__);
    return self->CloseP2PChannelWithUser(steamIDRemote, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_GetP2PSessionState( ISteamNetworking* self, uint64_steamid steamIDRemote, P2PSessionState_t * pConnectionState )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetP2PSessionState(steamIDRemote, pConnectionState);
}

S_API bool SteamAPI_ISteamNetworking_AllowP2PPacketRelay( ISteamNetworking* self, bool bAllow )
{
    VLOG_INFO(__FUNCTION__);
    return self->AllowP2PPacketRelay(bAllow);
}

S_API SNetListenSocket_t SteamAPI_ISteamNetworking_CreateListenSocket( ISteamNetworking* self, int nVirtualP2PPort, SteamIPAddress_t nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
}

S_API SNetSocket_t SteamAPI_ISteamNetworking_CreateP2PConnectionSocket( ISteamNetworking* self, uint64_steamid steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
}

S_API SNetSocket_t SteamAPI_ISteamNetworking_CreateConnectionSocket( ISteamNetworking* self, SteamIPAddress_t nIP, uint16 nPort, int nTimeoutSec )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateConnectionSocket(nIP, nPort, nTimeoutSec);
}

S_API bool SteamAPI_ISteamNetworking_DestroySocket( ISteamNetworking* self, SNetSocket_t hSocket, bool bNotifyRemoteEnd )
{
    VLOG_INFO(__FUNCTION__);
    return self->DestroySocket(hSocket, bNotifyRemoteEnd);
}

S_API bool SteamAPI_ISteamNetworking_DestroyListenSocket( ISteamNetworking* self, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd )
{
    VLOG_INFO(__FUNCTION__);
    return self->DestroyListenSocket(hSocket, bNotifyRemoteEnd);
}

S_API bool SteamAPI_ISteamNetworking_SendDataOnSocket( ISteamNetworking* self, SNetSocket_t hSocket, void * pubData, uint32 cubData, bool bReliable )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendDataOnSocket(hSocket, pubData, cubData, bReliable);
}

S_API bool SteamAPI_ISteamNetworking_IsDataAvailableOnSocket( ISteamNetworking* self, SNetSocket_t hSocket, uint32 * pcubMsgSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsDataAvailableOnSocket(hSocket, pcubMsgSize);
}

S_API bool SteamAPI_ISteamNetworking_RetrieveDataFromSocket( ISteamNetworking* self, SNetSocket_t hSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->RetrieveDataFromSocket(hSocket, pubDest, cubDest, pcubMsgSize);
}

S_API bool SteamAPI_ISteamNetworking_IsDataAvailable( ISteamNetworking* self, SNetListenSocket_t hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsDataAvailable(hListenSocket, pcubMsgSize, phSocket);
}

S_API bool SteamAPI_ISteamNetworking_RetrieveData( ISteamNetworking* self, SNetListenSocket_t hListenSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket )
{
    VLOG_INFO(__FUNCTION__);
    return self->RetrieveData(hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
}

S_API bool SteamAPI_ISteamNetworking_GetSocketInfo( ISteamNetworking* self, SNetSocket_t hSocket, CSteamID * pSteamIDRemote, int * peSocketStatus, SteamIPAddress_t * punIPRemote, uint16 * punPortRemote )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSocketInfo(hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
}

S_API bool SteamAPI_ISteamNetworking_GetListenSocketInfo( ISteamNetworking* self, SNetListenSocket_t hListenSocket, SteamIPAddress_t * pnIP, uint16 * pnPort )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetListenSocketInfo(hListenSocket, pnIP, pnPort);
}

S_API ESNetSocketConnectionType SteamAPI_ISteamNetworking_GetSocketConnectionType( ISteamNetworking* self, SNetSocket_t hSocket )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSocketConnectionType(hSocket);
}

S_API int SteamAPI_ISteamNetworking_GetMaxPacketSize( ISteamNetworking* self, SNetSocket_t hSocket )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMaxPacketSize(hSocket);
}


//-----------------------------------------------------------------------------
// ISteamScreenshots flat API implementations
//-----------------------------------------------------------------------------

S_API ScreenshotHandle SteamAPI_ISteamScreenshots_WriteScreenshot( ISteamScreenshots* self, void * pubRGB, uint32 cubRGB, int nWidth, int nHeight )
{
    VLOG_INFO(__FUNCTION__);
    return self->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
}

S_API ScreenshotHandle SteamAPI_ISteamScreenshots_AddScreenshotToLibrary( ISteamScreenshots* self, const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
}

S_API void SteamAPI_ISteamScreenshots_TriggerScreenshot( ISteamScreenshots* self )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerScreenshot();
}

S_API void SteamAPI_ISteamScreenshots_HookScreenshots( ISteamScreenshots* self, bool bHook )
{
    VLOG_INFO(__FUNCTION__);
    self->HookScreenshots(bHook);
}

S_API bool SteamAPI_ISteamScreenshots_SetLocation( ISteamScreenshots* self, ScreenshotHandle hScreenshot, const char * pchLocation )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLocation(hScreenshot, pchLocation);
}

S_API bool SteamAPI_ISteamScreenshots_TagUser( ISteamScreenshots* self, ScreenshotHandle hScreenshot, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->TagUser(hScreenshot, steamID);
}

S_API bool SteamAPI_ISteamScreenshots_TagPublishedFile( ISteamScreenshots* self, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->TagPublishedFile(hScreenshot, unPublishedFileID);
}

S_API bool SteamAPI_ISteamScreenshots_IsScreenshotsHooked( ISteamScreenshots* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsScreenshotsHooked();
}

S_API ScreenshotHandle SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary( ISteamScreenshots* self, EVRScreenshotType eType, const char * pchFilename, const char * pchVRFilename )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename);
}


//-----------------------------------------------------------------------------
// ISteamMusic flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamMusic_BIsEnabled( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsEnabled();
}

S_API bool SteamAPI_ISteamMusic_BIsPlaying( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsPlaying();
}

S_API AudioPlayback_Status SteamAPI_ISteamMusic_GetPlaybackStatus( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPlaybackStatus();
}

S_API void SteamAPI_ISteamMusic_Play( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    self->Play();
}

S_API void SteamAPI_ISteamMusic_Pause( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    self->Pause();
}

S_API void SteamAPI_ISteamMusic_PlayPrevious( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    self->PlayPrevious();
}

S_API void SteamAPI_ISteamMusic_PlayNext( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    self->PlayNext();
}

S_API void SteamAPI_ISteamMusic_SetVolume( ISteamMusic* self, float flVolume )
{
    VLOG_INFO(__FUNCTION__);
    self->SetVolume(flVolume);
}

S_API float SteamAPI_ISteamMusic_GetVolume( ISteamMusic* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetVolume();
}


//-----------------------------------------------------------------------------
// ISteamMusicRemote flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote( ISteamMusicRemote* self, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->RegisterSteamMusicRemote(pchName);
}

S_API bool SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeregisterSteamMusicRemote();
}

S_API bool SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsCurrentMusicRemote();
}

S_API bool SteamAPI_ISteamMusicRemote_BActivationSuccess( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->BActivationSuccess(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_SetDisplayName( ISteamMusicRemote* self, const char * pchDisplayName )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetDisplayName(pchDisplayName);
}

S_API bool SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64( ISteamMusicRemote* self, void * pvBuffer, uint32 cbBufferLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetPNGIcon_64x64(pvBuffer, cbBufferLength);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlayPrevious( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnablePlayPrevious(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlayNext( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnablePlayNext(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableShuffled( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnableShuffled(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableLooped( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnableLooped(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableQueue( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnableQueue(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlaylists( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->EnablePlaylists(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus( ISteamMusicRemote* self, AudioPlayback_Status nStatus )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdatePlaybackStatus(nStatus);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateShuffled( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateShuffled(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateLooped( ISteamMusicRemote* self, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateLooped(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateVolume( ISteamMusicRemote* self, float flValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateVolume(flValue);
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryWillChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CurrentEntryWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable( ISteamMusicRemote* self, bool bAvailable )
{
    VLOG_INFO(__FUNCTION__);
    return self->CurrentEntryIsAvailable(bAvailable);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText( ISteamMusicRemote* self, const char * pchText )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateCurrentEntryText(pchText);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds( ISteamMusicRemote* self, int nValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateCurrentEntryElapsedSeconds(nValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt( ISteamMusicRemote* self, void * pvBuffer, uint32 cbBufferLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateCurrentEntryCoverArt(pvBuffer, cbBufferLength);
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryDidChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CurrentEntryDidChange();
}

S_API bool SteamAPI_ISteamMusicRemote_QueueWillChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->QueueWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_ResetQueueEntries( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->ResetQueueEntries();
}

S_API bool SteamAPI_ISteamMusicRemote_SetQueueEntry( ISteamMusicRemote* self, int nID, int nPosition, const char * pchEntryText )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetQueueEntry(nID, nPosition, pchEntryText);
}

S_API bool SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry( ISteamMusicRemote* self, int nID )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetCurrentQueueEntry(nID);
}

S_API bool SteamAPI_ISteamMusicRemote_QueueDidChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->QueueDidChange();
}

S_API bool SteamAPI_ISteamMusicRemote_PlaylistWillChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->PlaylistWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_ResetPlaylistEntries( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->ResetPlaylistEntries();
}

S_API bool SteamAPI_ISteamMusicRemote_SetPlaylistEntry( ISteamMusicRemote* self, int nID, int nPosition, const char * pchEntryText )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetPlaylistEntry(nID, nPosition, pchEntryText);
}

S_API bool SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry( ISteamMusicRemote* self, int nID )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetCurrentPlaylistEntry(nID);
}

S_API bool SteamAPI_ISteamMusicRemote_PlaylistDidChange( ISteamMusicRemote* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->PlaylistDidChange();
}


//-----------------------------------------------------------------------------
// ISteamHTTP flat API implementations
//-----------------------------------------------------------------------------

S_API HTTPRequestHandle SteamAPI_ISteamHTTP_CreateHTTPRequest( ISteamHTTP* self, EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestContextValue( ISteamHTTP* self, HTTPRequestHandle hRequest, uint64 ulContextValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestContextValue(hRequest, ulContextValue);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout( ISteamHTTP* self, HTTPRequestHandle hRequest, uint32 unTimeoutSeconds )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
}

S_API bool SteamAPI_ISteamHTTP_SendHTTPRequest( ISteamHTTP* self, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendHTTPRequest(hRequest, pCallHandle);
}

S_API bool SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse( ISteamHTTP* self, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendHTTPRequestAndStreamResponse(hRequest, pCallHandle);
}

S_API bool SteamAPI_ISteamHTTP_DeferHTTPRequest( ISteamHTTP* self, HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeferHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_PrioritizeHTTPRequest( ISteamHTTP* self, HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->PrioritizeHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchHeaderName, uint32 * unResponseHeaderSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, unResponseHeaderSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseBodySize( ISteamHTTP* self, HTTPRequestHandle hRequest, uint32 * unBodySize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPResponseBodySize(hRequest, unBodySize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseBodyData( ISteamHTTP* self, HTTPRequestHandle hRequest, uint8 * pBodyDataBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPResponseBodyData(hRequest, pBodyDataBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData( ISteamHTTP* self, HTTPRequestHandle hRequest, uint32 cOffset, uint8 * pBodyDataBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPStreamingResponseBodyData(hRequest, cOffset, pBodyDataBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_ReleaseHTTPRequest( ISteamHTTP* self, HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReleaseHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct( ISteamHTTP* self, HTTPRequestHandle hRequest, float * pflPercentOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPDownloadProgressPct(hRequest, pflPercentOut);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchContentType, uint8 * pubBody, uint32 unBodyLen )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen);
}

S_API HTTPCookieContainerHandle SteamAPI_ISteamHTTP_CreateCookieContainer( ISteamHTTP* self, bool bAllowResponsesToModify )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateCookieContainer(bAllowResponsesToModify);
}

S_API bool SteamAPI_ISteamHTTP_ReleaseCookieContainer( ISteamHTTP* self, HTTPCookieContainerHandle hCookieContainer )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReleaseCookieContainer(hCookieContainer);
}

S_API bool SteamAPI_ISteamHTTP_SetCookie( ISteamHTTP* self, HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer( ISteamHTTP* self, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo( ISteamHTTP* self, HTTPRequestHandle hRequest, const char * pchUserAgentInfo )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate( ISteamHTTP* self, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS( ISteamHTTP* self, HTTPRequestHandle hRequest, uint32 unMilliseconds )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut( ISteamHTTP* self, HTTPRequestHandle hRequest, bool * pbWasTimedOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHTTPRequestWasTimedOut(hRequest, pbWasTimedOut);
}


//-----------------------------------------------------------------------------
// ISteamInput flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamInput_Init( ISteamInput* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Init();
}

S_API bool SteamAPI_ISteamInput_Shutdown( ISteamInput* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Shutdown();
}

S_API void SteamAPI_ISteamInput_RunFrame( ISteamInput* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RunFrame();
}

S_API int SteamAPI_ISteamInput_GetConnectedControllers( ISteamInput* self, InputHandle_t * handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectedControllers(handlesOut);
}

S_API InputActionSetHandle_t SteamAPI_ISteamInput_GetActionSetHandle( ISteamInput* self, const char * pszActionSetName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActionSetHandle(pszActionSetName);
}

S_API void SteamAPI_ISteamInput_ActivateActionSet( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateActionSet(inputHandle, actionSetHandle);
}

S_API InputActionSetHandle_t SteamAPI_ISteamInput_GetCurrentActionSet( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCurrentActionSet(inputHandle);
}

S_API void SteamAPI_ISteamInput_ActivateActionSetLayer( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateActionSetLayer(inputHandle, actionSetLayerHandle);
}

S_API void SteamAPI_ISteamInput_DeactivateActionSetLayer( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->DeactivateActionSetLayer(inputHandle, actionSetLayerHandle);
}

S_API void SteamAPI_ISteamInput_DeactivateAllActionSetLayers( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->DeactivateAllActionSetLayers(inputHandle);
}

S_API int SteamAPI_ISteamInput_GetActiveActionSetLayers( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t * handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActiveActionSetLayers(inputHandle, handlesOut);
}

S_API InputDigitalActionHandle_t SteamAPI_ISteamInput_GetDigitalActionHandle( ISteamInput* self, const char * pszActionName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionHandle(pszActionName);
}

S_API InputDigitalActionData_t SteamAPI_ISteamInput_GetDigitalActionData( ISteamInput* self, InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionData(inputHandle, digitalActionHandle);
}

S_API int SteamAPI_ISteamInput_GetDigitalActionOrigins( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin * originsOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle, originsOut);
}

S_API InputAnalogActionHandle_t SteamAPI_ISteamInput_GetAnalogActionHandle( ISteamInput* self, const char * pszActionName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionHandle(pszActionName);
}

S_API InputAnalogActionData_t SteamAPI_ISteamInput_GetAnalogActionData( ISteamInput* self, InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionData(inputHandle, analogActionHandle);
}

S_API int SteamAPI_ISteamInput_GetAnalogActionOrigins( ISteamInput* self, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, EInputActionOrigin * originsOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle, originsOut);
}

S_API const char * SteamAPI_ISteamInput_GetGlyphForActionOrigin( ISteamInput* self, EInputActionOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlyphForActionOrigin(eOrigin);
}

S_API const char * SteamAPI_ISteamInput_GetStringForActionOrigin( ISteamInput* self, EInputActionOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStringForActionOrigin(eOrigin);
}

S_API void SteamAPI_ISteamInput_StopAnalogActionMomentum( ISteamInput* self, InputHandle_t inputHandle, InputAnalogActionHandle_t eAction )
{
    VLOG_INFO(__FUNCTION__);
    self->StopAnalogActionMomentum(inputHandle, eAction);
}

S_API InputMotionData_t SteamAPI_ISteamInput_GetMotionData( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMotionData(inputHandle);
}

S_API void SteamAPI_ISteamInput_TriggerVibration( ISteamInput* self, InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed);
}

S_API void SteamAPI_ISteamInput_SetLEDColor( ISteamInput* self, InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags )
{
    VLOG_INFO(__FUNCTION__);
    self->SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags);
}

S_API void SteamAPI_ISteamInput_TriggerHapticPulse( ISteamInput* self, InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec);
}

S_API void SteamAPI_ISteamInput_TriggerRepeatedHapticPulse( ISteamInput* self, InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
}

S_API bool SteamAPI_ISteamInput_ShowBindingPanel( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->ShowBindingPanel(inputHandle);
}

S_API ESteamInputType SteamAPI_ISteamInput_GetInputTypeForHandle( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetInputTypeForHandle(inputHandle);
}

S_API InputHandle_t SteamAPI_ISteamInput_GetControllerForGamepadIndex( ISteamInput* self, int nIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetControllerForGamepadIndex(nIndex);
}

S_API int SteamAPI_ISteamInput_GetGamepadIndexForController( ISteamInput* self, InputHandle_t ulinputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGamepadIndexForController(ulinputHandle);
}

S_API const char * SteamAPI_ISteamInput_GetStringForXboxOrigin( ISteamInput* self, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStringForXboxOrigin(eOrigin);
}

S_API const char * SteamAPI_ISteamInput_GetGlyphForXboxOrigin( ISteamInput* self, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlyphForXboxOrigin(eOrigin);
}

S_API EInputActionOrigin SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin( ISteamInput* self, InputHandle_t inputHandle, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActionOriginFromXboxOrigin(inputHandle, eOrigin);
}

S_API EInputActionOrigin SteamAPI_ISteamInput_TranslateActionOrigin( ISteamInput* self, ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
}

S_API bool SteamAPI_ISteamInput_GetDeviceBindingRevision( ISteamInput* self, InputHandle_t inputHandle, int * pMajor, int * pMinor )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDeviceBindingRevision(inputHandle, pMajor, pMinor);
}

S_API uint32 SteamAPI_ISteamInput_GetRemotePlaySessionID( ISteamInput* self, InputHandle_t inputHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetRemotePlaySessionID(inputHandle);
}


//-----------------------------------------------------------------------------
// ISteamController flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamController_Init( ISteamController* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Init();
}

S_API bool SteamAPI_ISteamController_Shutdown( ISteamController* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Shutdown();
}

S_API void SteamAPI_ISteamController_RunFrame( ISteamController* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RunFrame();
}

S_API int SteamAPI_ISteamController_GetConnectedControllers( ISteamController* self, ControllerHandle_t * handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectedControllers(handlesOut);
}

S_API ControllerActionSetHandle_t SteamAPI_ISteamController_GetActionSetHandle( ISteamController* self, const char * pszActionSetName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActionSetHandle(pszActionSetName);
}

S_API void SteamAPI_ISteamController_ActivateActionSet( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateActionSet(controllerHandle, actionSetHandle);
}

S_API ControllerActionSetHandle_t SteamAPI_ISteamController_GetCurrentActionSet( ISteamController* self, ControllerHandle_t controllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCurrentActionSet(controllerHandle);
}

S_API void SteamAPI_ISteamController_ActivateActionSetLayer( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->ActivateActionSetLayer(controllerHandle, actionSetLayerHandle);
}

S_API void SteamAPI_ISteamController_DeactivateActionSetLayer( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle);
}

S_API void SteamAPI_ISteamController_DeactivateAllActionSetLayers( ISteamController* self, ControllerHandle_t controllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->DeactivateAllActionSetLayers(controllerHandle);
}

S_API int SteamAPI_ISteamController_GetActiveActionSetLayers( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t * handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActiveActionSetLayers(controllerHandle, handlesOut);
}

S_API ControllerDigitalActionHandle_t SteamAPI_ISteamController_GetDigitalActionHandle( ISteamController* self, const char * pszActionName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionHandle(pszActionName);
}

S_API InputDigitalActionData_t SteamAPI_ISteamController_GetDigitalActionData( ISteamController* self, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionData(controllerHandle, digitalActionHandle);
}

S_API int SteamAPI_ISteamController_GetDigitalActionOrigins( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin * originsOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle, originsOut);
}

S_API ControllerAnalogActionHandle_t SteamAPI_ISteamController_GetAnalogActionHandle( ISteamController* self, const char * pszActionName )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionHandle(pszActionName);
}

S_API InputAnalogActionData_t SteamAPI_ISteamController_GetAnalogActionData( ISteamController* self, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionData(controllerHandle, analogActionHandle);
}

S_API int SteamAPI_ISteamController_GetAnalogActionOrigins( ISteamController* self, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin * originsOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle, originsOut);
}

S_API const char * SteamAPI_ISteamController_GetGlyphForActionOrigin( ISteamController* self, EControllerActionOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlyphForActionOrigin(eOrigin);
}

S_API const char * SteamAPI_ISteamController_GetStringForActionOrigin( ISteamController* self, EControllerActionOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStringForActionOrigin(eOrigin);
}

S_API void SteamAPI_ISteamController_StopAnalogActionMomentum( ISteamController* self, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction )
{
    VLOG_INFO(__FUNCTION__);
    self->StopAnalogActionMomentum(controllerHandle, eAction);
}

S_API InputMotionData_t SteamAPI_ISteamController_GetMotionData( ISteamController* self, ControllerHandle_t controllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetMotionData(controllerHandle);
}

S_API void SteamAPI_ISteamController_TriggerHapticPulse( ISteamController* self, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec);
}

S_API void SteamAPI_ISteamController_TriggerRepeatedHapticPulse( ISteamController* self, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
}

S_API void SteamAPI_ISteamController_TriggerVibration( ISteamController* self, ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed )
{
    VLOG_INFO(__FUNCTION__);
    self->TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed);
}

S_API void SteamAPI_ISteamController_SetLEDColor( ISteamController* self, ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags )
{
    VLOG_INFO(__FUNCTION__);
    self->SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags);
}

S_API bool SteamAPI_ISteamController_ShowBindingPanel( ISteamController* self, ControllerHandle_t controllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->ShowBindingPanel(controllerHandle);
}

S_API ESteamInputType SteamAPI_ISteamController_GetInputTypeForHandle( ISteamController* self, ControllerHandle_t controllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetInputTypeForHandle(controllerHandle);
}

S_API ControllerHandle_t SteamAPI_ISteamController_GetControllerForGamepadIndex( ISteamController* self, int nIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetControllerForGamepadIndex(nIndex);
}

S_API int SteamAPI_ISteamController_GetGamepadIndexForController( ISteamController* self, ControllerHandle_t ulControllerHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGamepadIndexForController(ulControllerHandle);
}

S_API const char * SteamAPI_ISteamController_GetStringForXboxOrigin( ISteamController* self, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetStringForXboxOrigin(eOrigin);
}

S_API const char * SteamAPI_ISteamController_GetGlyphForXboxOrigin( ISteamController* self, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGlyphForXboxOrigin(eOrigin);
}

S_API EControllerActionOrigin SteamAPI_ISteamController_GetActionOriginFromXboxOrigin( ISteamController* self, ControllerHandle_t controllerHandle, EXboxOrigin eOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetActionOriginFromXboxOrigin(controllerHandle, eOrigin);
}

S_API EControllerActionOrigin SteamAPI_ISteamController_TranslateActionOrigin( ISteamController* self, ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin )
{
    VLOG_INFO(__FUNCTION__);
    return self->TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
}

S_API bool SteamAPI_ISteamController_GetControllerBindingRevision( ISteamController* self, ControllerHandle_t controllerHandle, int * pMajor, int * pMinor )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetControllerBindingRevision(controllerHandle, pMajor, pMinor);
}


//-----------------------------------------------------------------------------
// ISteamUGC flat API implementations
//-----------------------------------------------------------------------------

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryUserUGCRequest( ISteamUGC* self, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage( ISteamUGC* self, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor( ISteamUGC* self, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, const char * pchCursor )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, pchCursor);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest( ISteamUGC* self, PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateQueryUGCDetailsRequest(pvecPublishedFileID, unNumPublishedFileIDs);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SendQueryUGCRequest( ISteamUGC* self, UGCQueryHandle_t handle )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendQueryUGCRequest(handle);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCResult( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t * pDetails )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCResult(handle, index, pDetails);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCPreviewURL( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, char * pchURL, uint32 cchURLSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCPreviewURL(handle, index, pchURL, cchURLSize);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCMetadata( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, char * pchMetadata, uint32 cchMetadatasize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCMetadata(handle, index, pchMetadata, cchMetadatasize);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCChildren( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCChildren(handle, index, pvecPublishedFileID, cMaxEntries);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCStatistic( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 * pStatValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCStatistic(handle, index, eStatType, pStatValue);
}

S_API uint32 SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCNumAdditionalPreviews(handle, index);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char * pchURLOrVideoID, uint32 cchURLSize, char * pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType * pPreviewType )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCAdditionalPreview(handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
}

S_API uint32 SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCNumKeyValueTags(handle, index);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, char * pchKey, uint32 cchKeySize, char * pchValue, uint32 cchValueSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
}

S_API bool SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag( ISteamUGC* self, UGCQueryHandle_t handle, uint32 index, const char * pchKey, char * pchValue, uint32 cchValueSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQueryUGCKeyValueTag(handle, index, pchKey, pchValue, cchValueSize);
}

S_API bool SteamAPI_ISteamUGC_ReleaseQueryUGCRequest( ISteamUGC* self, UGCQueryHandle_t handle )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReleaseQueryUGCRequest(handle);
}

S_API bool SteamAPI_ISteamUGC_AddRequiredTag( ISteamUGC* self, UGCQueryHandle_t handle, const char * pTagName )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddRequiredTag(handle, pTagName);
}

S_API bool SteamAPI_ISteamUGC_AddRequiredTagGroup( ISteamUGC* self, UGCQueryHandle_t handle, const SteamParamStringArray_t * pTagGroups )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddRequiredTagGroup(handle, pTagGroups);
}

S_API bool SteamAPI_ISteamUGC_AddExcludedTag( ISteamUGC* self, UGCQueryHandle_t handle, const char * pTagName )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddExcludedTag(handle, pTagName);
}

S_API bool SteamAPI_ISteamUGC_SetReturnOnlyIDs( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnOnlyIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnOnlyIDs(handle, bReturnOnlyIDs);
}

S_API bool SteamAPI_ISteamUGC_SetReturnKeyValueTags( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnKeyValueTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnKeyValueTags(handle, bReturnKeyValueTags);
}

S_API bool SteamAPI_ISteamUGC_SetReturnLongDescription( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnLongDescription )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnLongDescription(handle, bReturnLongDescription);
}

S_API bool SteamAPI_ISteamUGC_SetReturnMetadata( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnMetadata )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnMetadata(handle, bReturnMetadata);
}

S_API bool SteamAPI_ISteamUGC_SetReturnChildren( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnChildren )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnChildren(handle, bReturnChildren);
}

S_API bool SteamAPI_ISteamUGC_SetReturnAdditionalPreviews( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnAdditionalPreviews )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews);
}

S_API bool SteamAPI_ISteamUGC_SetReturnTotalOnly( ISteamUGC* self, UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnTotalOnly(handle, bReturnTotalOnly);
}

S_API bool SteamAPI_ISteamUGC_SetReturnPlaytimeStats( ISteamUGC* self, UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetReturnPlaytimeStats(handle, unDays);
}

S_API bool SteamAPI_ISteamUGC_SetLanguage( ISteamUGC* self, UGCQueryHandle_t handle, const char * pchLanguage )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetLanguage(handle, pchLanguage);
}

S_API bool SteamAPI_ISteamUGC_SetAllowCachedResponse( ISteamUGC* self, UGCQueryHandle_t handle, uint32 unMaxAgeSeconds )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetAllowCachedResponse(handle, unMaxAgeSeconds);
}

S_API bool SteamAPI_ISteamUGC_SetCloudFileNameFilter( ISteamUGC* self, UGCQueryHandle_t handle, const char * pMatchCloudFileName )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetCloudFileNameFilter(handle, pMatchCloudFileName);
}

S_API bool SteamAPI_ISteamUGC_SetMatchAnyTag( ISteamUGC* self, UGCQueryHandle_t handle, bool bMatchAnyTag )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetMatchAnyTag(handle, bMatchAnyTag);
}

S_API bool SteamAPI_ISteamUGC_SetSearchText( ISteamUGC* self, UGCQueryHandle_t handle, const char * pSearchText )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetSearchText(handle, pSearchText);
}

S_API bool SteamAPI_ISteamUGC_SetRankedByTrendDays( ISteamUGC* self, UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetRankedByTrendDays(handle, unDays);
}

S_API bool SteamAPI_ISteamUGC_AddRequiredKeyValueTag( ISteamUGC* self, UGCQueryHandle_t handle, const char * pKey, const char * pValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddRequiredKeyValueTag(handle, pKey, pValue);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_RequestUGCDetails( ISteamUGC* self, PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_CreateItem( ISteamUGC* self, AppId_t nConsumerAppId, EWorkshopFileType eFileType )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateItem(nConsumerAppId, eFileType);
}

S_API UGCUpdateHandle_t SteamAPI_ISteamUGC_StartItemUpdate( ISteamUGC* self, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->StartItemUpdate(nConsumerAppId, nPublishedFileID);
}

S_API bool SteamAPI_ISteamUGC_SetItemTitle( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchTitle )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemTitle(handle, pchTitle);
}

S_API bool SteamAPI_ISteamUGC_SetItemDescription( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchDescription )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemDescription(handle, pchDescription);
}

S_API bool SteamAPI_ISteamUGC_SetItemUpdateLanguage( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchLanguage )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemUpdateLanguage(handle, pchLanguage);
}

S_API bool SteamAPI_ISteamUGC_SetItemMetadata( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchMetaData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemMetadata(handle, pchMetaData);
}

S_API bool SteamAPI_ISteamUGC_SetItemVisibility( ISteamUGC* self, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemVisibility(handle, eVisibility);
}

S_API bool SteamAPI_ISteamUGC_SetItemTags( ISteamUGC* self, UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t * pTags )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemTags(updateHandle, pTags);
}

S_API bool SteamAPI_ISteamUGC_SetItemContent( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pszContentFolder )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemContent(handle, pszContentFolder);
}

S_API bool SteamAPI_ISteamUGC_SetItemPreview( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pszPreviewFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetItemPreview(handle, pszPreviewFile);
}

S_API bool SteamAPI_ISteamUGC_SetAllowLegacyUpload( ISteamUGC* self, UGCUpdateHandle_t handle, bool bAllowLegacyUpload )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetAllowLegacyUpload(handle, bAllowLegacyUpload);
}

S_API bool SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags( ISteamUGC* self, UGCUpdateHandle_t handle )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveAllItemKeyValueTags(handle);
}

S_API bool SteamAPI_ISteamUGC_RemoveItemKeyValueTags( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveItemKeyValueTags(handle, pchKey);
}

S_API bool SteamAPI_ISteamUGC_AddItemKeyValueTag( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddItemKeyValueTag(handle, pchKey, pchValue);
}

S_API bool SteamAPI_ISteamUGC_AddItemPreviewFile( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pszPreviewFile, EItemPreviewType type )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddItemPreviewFile(handle, pszPreviewFile, type);
}

S_API bool SteamAPI_ISteamUGC_AddItemPreviewVideo( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pszVideoID )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddItemPreviewVideo(handle, pszVideoID);
}

S_API bool SteamAPI_ISteamUGC_UpdateItemPreviewFile( ISteamUGC* self, UGCUpdateHandle_t handle, uint32 index, const char * pszPreviewFile )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateItemPreviewFile(handle, index, pszPreviewFile);
}

S_API bool SteamAPI_ISteamUGC_UpdateItemPreviewVideo( ISteamUGC* self, UGCUpdateHandle_t handle, uint32 index, const char * pszVideoID )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateItemPreviewVideo(handle, index, pszVideoID);
}

S_API bool SteamAPI_ISteamUGC_RemoveItemPreview( ISteamUGC* self, UGCUpdateHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveItemPreview(handle, index);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SubmitItemUpdate( ISteamUGC* self, UGCUpdateHandle_t handle, const char * pchChangeNote )
{
    VLOG_INFO(__FUNCTION__);
    return self->SubmitItemUpdate(handle, pchChangeNote);
}

S_API EItemUpdateStatus SteamAPI_ISteamUGC_GetItemUpdateProgress( ISteamUGC* self, UGCUpdateHandle_t handle, uint64 * punBytesProcessed, uint64 * punBytesTotal )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemUpdateProgress(handle, punBytesProcessed, punBytesTotal);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SetUserItemVote( ISteamUGC* self, PublishedFileId_t nPublishedFileID, bool bVoteUp )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetUserItemVote(nPublishedFileID, bVoteUp);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_GetUserItemVote( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserItemVote(nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_AddItemToFavorites( ISteamUGC* self, AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddItemToFavorites(nAppId, nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_RemoveItemFromFavorites( ISteamUGC* self, AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveItemFromFavorites(nAppId, nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SubscribeItem( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->SubscribeItem(nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_UnsubscribeItem( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->UnsubscribeItem(nPublishedFileID);
}

S_API uint32 SteamAPI_ISteamUGC_GetNumSubscribedItems( ISteamUGC* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumSubscribedItems();
}

S_API uint32 SteamAPI_ISteamUGC_GetSubscribedItems( ISteamUGC* self, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSubscribedItems(pvecPublishedFileID, cMaxEntries);
}

S_API uint32 SteamAPI_ISteamUGC_GetItemState( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemState(nPublishedFileID);
}

S_API bool SteamAPI_ISteamUGC_GetItemInstallInfo( ISteamUGC* self, PublishedFileId_t nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32 cchFolderSize, uint32 * punTimeStamp )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemInstallInfo(nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
}

S_API bool SteamAPI_ISteamUGC_GetItemDownloadInfo( ISteamUGC* self, PublishedFileId_t nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemDownloadInfo(nPublishedFileID, punBytesDownloaded, punBytesTotal);
}

S_API bool SteamAPI_ISteamUGC_DownloadItem( ISteamUGC* self, PublishedFileId_t nPublishedFileID, bool bHighPriority )
{
    VLOG_INFO(__FUNCTION__);
    return self->DownloadItem(nPublishedFileID, bHighPriority);
}

S_API bool SteamAPI_ISteamUGC_BInitWorkshopForGameServer( ISteamUGC* self, DepotId_t unWorkshopDepotID, const char * pszFolder )
{
    VLOG_INFO(__FUNCTION__);
    return self->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder);
}

S_API void SteamAPI_ISteamUGC_SuspendDownloads( ISteamUGC* self, bool bSuspend )
{
    VLOG_INFO(__FUNCTION__);
    self->SuspendDownloads(bSuspend);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_StartPlaytimeTracking( ISteamUGC* self, PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_StopPlaytimeTracking( ISteamUGC* self, PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems( ISteamUGC* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->StopPlaytimeTrackingForAllItems();
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_AddDependency( ISteamUGC* self, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddDependency(nParentPublishedFileID, nChildPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_RemoveDependency( ISteamUGC* self, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveDependency(nParentPublishedFileID, nChildPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_AddAppDependency( ISteamUGC* self, PublishedFileId_t nPublishedFileID, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddAppDependency(nPublishedFileID, nAppID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_RemoveAppDependency( ISteamUGC* self, PublishedFileId_t nPublishedFileID, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveAppDependency(nPublishedFileID, nAppID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_GetAppDependencies( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppDependencies(nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_DeleteItem( ISteamUGC* self, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeleteItem(nPublishedFileID);
}


//-----------------------------------------------------------------------------
// ISteamAppList flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamAppList_GetNumInstalledApps( ISteamAppList* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumInstalledApps();
}

S_API uint32 SteamAPI_ISteamAppList_GetInstalledApps( ISteamAppList* self, AppId_t * pvecAppID, uint32 unMaxAppIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetInstalledApps(pvecAppID, unMaxAppIDs);
}

S_API int SteamAPI_ISteamAppList_GetAppName( ISteamAppList* self, AppId_t nAppID, char * pchName, int cchNameMax )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppName(nAppID, pchName, cchNameMax);
}

S_API int SteamAPI_ISteamAppList_GetAppInstallDir( ISteamAppList* self, AppId_t nAppID, char * pchDirectory, int cchNameMax )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppInstallDir(nAppID, pchDirectory, cchNameMax);
}

S_API int SteamAPI_ISteamAppList_GetAppBuildId( ISteamAppList* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAppBuildId(nAppID);
}


//-----------------------------------------------------------------------------
// ISteamHTMLSurface flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamHTMLSurface_Init( ISteamHTMLSurface* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Init();
}

S_API bool SteamAPI_ISteamHTMLSurface_Shutdown( ISteamHTMLSurface* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->Shutdown();
}

S_API SteamAPICall_t SteamAPI_ISteamHTMLSurface_CreateBrowser( ISteamHTMLSurface* self, const char * pchUserAgent, const char * pchUserCSS )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateBrowser(pchUserAgent, pchUserCSS);
}

S_API void SteamAPI_ISteamHTMLSurface_RemoveBrowser( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->RemoveBrowser(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_LoadURL( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData )
{
    VLOG_INFO(__FUNCTION__);
    self->LoadURL(unBrowserHandle, pchURL, pchPostData);
}

S_API void SteamAPI_ISteamHTMLSurface_SetSize( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight )
{
    VLOG_INFO(__FUNCTION__);
    self->SetSize(unBrowserHandle, unWidth, unHeight);
}

S_API void SteamAPI_ISteamHTMLSurface_StopLoad( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->StopLoad(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_Reload( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->Reload(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GoBack( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->GoBack(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GoForward( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->GoForward(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_AddHeader( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    self->AddHeader(unBrowserHandle, pchKey, pchValue);
}

S_API void SteamAPI_ISteamHTMLSurface_ExecuteJavascript( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, const char * pchScript )
{
    VLOG_INFO(__FUNCTION__);
    self->ExecuteJavascript(unBrowserHandle, pchScript);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseUp( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__);
    self->MouseUp(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseDown( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__);
    self->MouseDown(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseDoubleClick( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__);
    self->MouseDoubleClick(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseMove( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_INFO(__FUNCTION__);
    self->MouseMove(unBrowserHandle, x, y);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseWheel( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, int32 nDelta )
{
    VLOG_INFO(__FUNCTION__);
    self->MouseWheel(unBrowserHandle, nDelta);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyDown( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, bool bIsSystemKey )
{
    VLOG_INFO(__FUNCTION__);
    self->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyUp( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_INFO(__FUNCTION__);
    self->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyChar( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_INFO(__FUNCTION__);
    self->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

S_API void SteamAPI_ISteamHTMLSurface_SetHorizontalScroll( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_INFO(__FUNCTION__);
    self->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

S_API void SteamAPI_ISteamHTMLSurface_SetVerticalScroll( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_INFO(__FUNCTION__);
    self->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

S_API void SteamAPI_ISteamHTMLSurface_SetKeyFocus( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus )
{
    VLOG_INFO(__FUNCTION__);
    self->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
}

S_API void SteamAPI_ISteamHTMLSurface_ViewSource( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->ViewSource(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_CopyToClipboard( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->CopyToClipboard(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_PasteFromClipboard( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->PasteFromClipboard(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_Find( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse )
{
    VLOG_INFO(__FUNCTION__);
    self->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}

S_API void SteamAPI_ISteamHTMLSurface_StopFind( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->StopFind(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GetLinkAtPosition( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_INFO(__FUNCTION__);
    self->GetLinkAtPosition(unBrowserHandle, x, y);
}

S_API void SteamAPI_ISteamHTMLSurface_SetCookie( ISteamHTMLSurface* self, const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly )
{
    VLOG_INFO(__FUNCTION__);
    self->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}

S_API void SteamAPI_ISteamHTMLSurface_SetPageScaleFactor( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY )
{
    VLOG_INFO(__FUNCTION__);
    self->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
}

S_API void SteamAPI_ISteamHTMLSurface_SetBackgroundMode( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, bool bBackgroundMode )
{
    VLOG_INFO(__FUNCTION__);
    self->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
}

S_API void SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, float flDPIScaling )
{
    VLOG_INFO(__FUNCTION__);
    self->SetDPIScalingFactor(unBrowserHandle, flDPIScaling);
}

S_API void SteamAPI_ISteamHTMLSurface_OpenDeveloperTools( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->OpenDeveloperTools(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_AllowStartRequest( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, bool bAllowed )
{
    VLOG_INFO(__FUNCTION__);
    self->AllowStartRequest(unBrowserHandle, bAllowed);
}

S_API void SteamAPI_ISteamHTMLSurface_JSDialogResponse( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, bool bResult )
{
    VLOG_INFO(__FUNCTION__);
    self->JSDialogResponse(unBrowserHandle, bResult);
}

S_API void SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse( ISteamHTMLSurface* self, HHTMLBrowser unBrowserHandle, const char ** pchSelectedFiles )
{
    VLOG_INFO(__FUNCTION__);
    self->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
}


//-----------------------------------------------------------------------------
// ISteamInventory flat API implementations
//-----------------------------------------------------------------------------

S_API EResult SteamAPI_ISteamInventory_GetResultStatus( ISteamInventory* self, SteamInventoryResult_t resultHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetResultStatus(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetResultItems( ISteamInventory* self, SteamInventoryResult_t resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetResultItems(resultHandle, pOutItemsArray, punOutItemsArraySize);
}

S_API bool SteamAPI_ISteamInventory_GetResultItemProperty( ISteamInventory* self, SteamInventoryResult_t resultHandle, uint32 unItemIndex, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
}

S_API uint32 SteamAPI_ISteamInventory_GetResultTimestamp( ISteamInventory* self, SteamInventoryResult_t resultHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetResultTimestamp(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_CheckResultSteamID( ISteamInventory* self, SteamInventoryResult_t resultHandle, uint64_steamid steamIDExpected )
{
    VLOG_INFO(__FUNCTION__);
    return self->CheckResultSteamID(resultHandle, steamIDExpected);
}

S_API void SteamAPI_ISteamInventory_DestroyResult( ISteamInventory* self, SteamInventoryResult_t resultHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->DestroyResult(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetAllItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAllItems(pResultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetItemsByID( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, const SteamItemInstanceID_t * pInstanceIDs, uint32 unCountInstanceIDs )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemsByID(pResultHandle, pInstanceIDs, unCountInstanceIDs);
}

S_API bool SteamAPI_ISteamInventory_SerializeResult( ISteamInventory* self, SteamInventoryResult_t resultHandle, void * pOutBuffer, uint32 * punOutBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->SerializeResult(resultHandle, pOutBuffer, punOutBufferSize);
}

S_API bool SteamAPI_ISteamInventory_DeserializeResult( ISteamInventory* self, SteamInventoryResult_t * pOutResultHandle, const void * pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE )
{
    VLOG_INFO(__FUNCTION__);
    return self->DeserializeResult(pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
}

S_API bool SteamAPI_ISteamInventory_GenerateItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->GenerateItems(pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
}

S_API bool SteamAPI_ISteamInventory_GrantPromoItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->GrantPromoItems(pResultHandle);
}

S_API bool SteamAPI_ISteamInventory_AddPromoItem( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, SteamItemDef_t itemDef )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddPromoItem(pResultHandle, itemDef);
}

S_API bool SteamAPI_ISteamInventory_AddPromoItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, uint32 unArrayLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddPromoItems(pResultHandle, pArrayItemDefs, unArrayLength);
}

S_API bool SteamAPI_ISteamInventory_ConsumeItem( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConsumeItem(pResultHandle, itemConsume, unQuantity);
}

S_API bool SteamAPI_ISteamInventory_ExchangeItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayGenerate, const uint32 * punArrayGenerateQuantity, uint32 unArrayGenerateLength, const SteamItemInstanceID_t * pArrayDestroy, const uint32 * punArrayDestroyQuantity, uint32 unArrayDestroyLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->ExchangeItems(pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
}

S_API bool SteamAPI_ISteamInventory_TransferItemQuantity( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest )
{
    VLOG_INFO(__FUNCTION__);
    return self->TransferItemQuantity(pResultHandle, itemIdSource, unQuantity, itemIdDest);
}

S_API void SteamAPI_ISteamInventory_SendItemDropHeartbeat( ISteamInventory* self )
{
    VLOG_INFO(__FUNCTION__);
    self->SendItemDropHeartbeat();
}

S_API bool SteamAPI_ISteamInventory_TriggerItemDrop( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, SteamItemDef_t dropListDefinition )
{
    VLOG_INFO(__FUNCTION__);
    return self->TriggerItemDrop(pResultHandle, dropListDefinition);
}

S_API bool SteamAPI_ISteamInventory_TradeItems( ISteamInventory* self, SteamInventoryResult_t * pResultHandle, uint64_steamid steamIDTradePartner, const SteamItemInstanceID_t * pArrayGive, const uint32 * pArrayGiveQuantity, uint32 nArrayGiveLength, const SteamItemInstanceID_t * pArrayGet, const uint32 * pArrayGetQuantity, uint32 nArrayGetLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->TradeItems(pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
}

S_API bool SteamAPI_ISteamInventory_LoadItemDefinitions( ISteamInventory* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->LoadItemDefinitions();
}

S_API bool SteamAPI_ISteamInventory_GetItemDefinitionIDs( ISteamInventory* self, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemDefinitionIDs(pItemDefIDs, punItemDefIDsArraySize);
}

S_API bool SteamAPI_ISteamInventory_GetItemDefinitionProperty( ISteamInventory* self, SteamItemDef_t iDefinition, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
}

S_API SteamAPICall_t SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs( ISteamInventory* self, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestEligiblePromoItemDefinitionsIDs(steamID);
}

S_API bool SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs( ISteamInventory* self, uint64_steamid steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetEligiblePromoItemDefinitionIDs(steamID, pItemDefIDs, punItemDefIDsArraySize);
}

S_API SteamAPICall_t SteamAPI_ISteamInventory_StartPurchase( ISteamInventory* self, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->StartPurchase(pArrayItemDefs, punArrayQuantity, unArrayLength);
}

S_API SteamAPICall_t SteamAPI_ISteamInventory_RequestPrices( ISteamInventory* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestPrices();
}

S_API uint32 SteamAPI_ISteamInventory_GetNumItemsWithPrices( ISteamInventory* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNumItemsWithPrices();
}

S_API bool SteamAPI_ISteamInventory_GetItemsWithPrices( ISteamInventory* self, SteamItemDef_t * pArrayItemDefs, uint64 * pCurrentPrices, uint64 * pBasePrices, uint32 unArrayLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemsWithPrices(pArrayItemDefs, pCurrentPrices, pBasePrices, unArrayLength);
}

S_API bool SteamAPI_ISteamInventory_GetItemPrice( ISteamInventory* self, SteamItemDef_t iDefinition, uint64 * pCurrentPrice, uint64 * pBasePrice )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetItemPrice(iDefinition, pCurrentPrice, pBasePrice);
}

S_API SteamInventoryUpdateHandle_t SteamAPI_ISteamInventory_StartUpdateProperties( ISteamInventory* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->StartUpdateProperties();
}

S_API bool SteamAPI_ISteamInventory_RemoveProperty( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName )
{
    VLOG_INFO(__FUNCTION__);
    return self->RemoveProperty(handle, nItemID, pchPropertyName);
}

S_API bool SteamAPI_ISteamInventory_SetPropertyString( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, const char * pchPropertyValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetProperty(handle, nItemID, pchPropertyName, pchPropertyValue);
}

S_API bool SteamAPI_ISteamInventory_SetPropertyBool( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, bool bValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetProperty(handle, nItemID, pchPropertyName, bValue);
}

S_API bool SteamAPI_ISteamInventory_SetPropertyInt64( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, int64 nValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetProperty(handle, nItemID, pchPropertyName, nValue);
}

S_API bool SteamAPI_ISteamInventory_SetPropertyFloat( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, float flValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetProperty(handle, nItemID, pchPropertyName, flValue);
}

S_API bool SteamAPI_ISteamInventory_SubmitUpdateProperties( ISteamInventory* self, SteamInventoryUpdateHandle_t handle, SteamInventoryResult_t * pResultHandle )
{
    VLOG_INFO(__FUNCTION__);
    return self->SubmitUpdateProperties(handle, pResultHandle);
}


//-----------------------------------------------------------------------------
// ISteamVideo flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamVideo_GetVideoURL( ISteamVideo* self, AppId_t unVideoAppID )
{
    VLOG_INFO(__FUNCTION__);
    self->GetVideoURL(unVideoAppID);
}

S_API bool SteamAPI_ISteamVideo_IsBroadcasting( ISteamVideo* self, int * pnNumViewers )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsBroadcasting(pnNumViewers);
}

S_API void SteamAPI_ISteamVideo_GetOPFSettings( ISteamVideo* self, AppId_t unVideoAppID )
{
    VLOG_INFO(__FUNCTION__);
    self->GetOPFSettings(unVideoAppID);
}

S_API bool SteamAPI_ISteamVideo_GetOPFStringForApp( ISteamVideo* self, AppId_t unVideoAppID, char * pchBuffer, int32 * pnBufferSize )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetOPFStringForApp(unVideoAppID, pchBuffer, pnBufferSize);
}


//-----------------------------------------------------------------------------
// ISteamTV flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamTV_IsBroadcasting( ISteamTV* self, int * pnNumViewers )
{
    VLOG_INFO(__FUNCTION__);
    return self->IsBroadcasting(pnNumViewers);
}

S_API void SteamAPI_ISteamTV_AddBroadcastGameData( ISteamTV* self, const char * pchKey, const char * pchValue )
{
    VLOG_INFO(__FUNCTION__);
    self->AddBroadcastGameData(pchKey, pchValue);
}

S_API void SteamAPI_ISteamTV_RemoveBroadcastGameData( ISteamTV* self, const char * pchKey )
{
    VLOG_INFO(__FUNCTION__);
    self->RemoveBroadcastGameData(pchKey);
}

S_API void SteamAPI_ISteamTV_AddTimelineMarker( ISteamTV* self, const char * pchTemplateName, bool bPersistent, uint8 nColorR, uint8 nColorG, uint8 nColorB )
{
    VLOG_INFO(__FUNCTION__);
    self->AddTimelineMarker(pchTemplateName, bPersistent, nColorR, nColorG, nColorB);
}

S_API void SteamAPI_ISteamTV_RemoveTimelineMarker( ISteamTV* self )
{
    VLOG_INFO(__FUNCTION__);
    self->RemoveTimelineMarker();
}

S_API uint32 SteamAPI_ISteamTV_AddRegion( ISteamTV* self, const char * pchElementName, const char * pchTimelineDataSection, const SteamTVRegion_t * pSteamTVRegion, ESteamTVRegionBehavior eSteamTVRegionBehavior )
{
    VLOG_INFO(__FUNCTION__);
    return self->AddRegion(pchElementName, pchTimelineDataSection, pSteamTVRegion, eSteamTVRegionBehavior);
}

S_API void SteamAPI_ISteamTV_RemoveRegion( ISteamTV* self, uint32 unRegionHandle )
{
    VLOG_INFO(__FUNCTION__);
    self->RemoveRegion(unRegionHandle);
}


//-----------------------------------------------------------------------------
// ISteamParentalSettings flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled( ISteamParentalSettings* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsParentalLockEnabled();
}

S_API bool SteamAPI_ISteamParentalSettings_BIsParentalLockLocked( ISteamParentalSettings* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsParentalLockLocked();
}

S_API bool SteamAPI_ISteamParentalSettings_BIsAppBlocked( ISteamParentalSettings* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsAppBlocked(nAppID);
}

S_API bool SteamAPI_ISteamParentalSettings_BIsAppInBlockList( ISteamParentalSettings* self, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsAppInBlockList(nAppID);
}

S_API bool SteamAPI_ISteamParentalSettings_BIsFeatureBlocked( ISteamParentalSettings* self, EParentalFeature eFeature )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsFeatureBlocked(eFeature);
}

S_API bool SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList( ISteamParentalSettings* self, EParentalFeature eFeature )
{
    VLOG_INFO(__FUNCTION__);
    return self->BIsFeatureInBlockList(eFeature);
}


//-----------------------------------------------------------------------------
// ISteamRemotePlay flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamRemotePlay_GetSessionCount( ISteamRemotePlay* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSessionCount();
}

S_API RemotePlaySessionID_t SteamAPI_ISteamRemotePlay_GetSessionID( ISteamRemotePlay* self, int iSessionIndex )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSessionID(iSessionIndex);
}

S_API uint64_steamid SteamAPI_ISteamRemotePlay_GetSessionSteamID( ISteamRemotePlay* self, RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSessionSteamID(unSessionID).ConvertToUint64();
}

S_API const char * SteamAPI_ISteamRemotePlay_GetSessionClientName( ISteamRemotePlay* self, RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSessionClientName(unSessionID);
}

S_API ESteamDeviceFormFactor SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor( ISteamRemotePlay* self, RemotePlaySessionID_t unSessionID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSessionClientFormFactor(unSessionID);
}

S_API bool SteamAPI_ISteamRemotePlay_BGetSessionClientResolution( ISteamRemotePlay* self, RemotePlaySessionID_t unSessionID, int * pnResolutionX, int * pnResolutionY )
{
    VLOG_INFO(__FUNCTION__);
    return self->BGetSessionClientResolution(unSessionID, pnResolutionX, pnResolutionY);
}

S_API bool SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite( ISteamRemotePlay* self, uint64_steamid steamIDFriend )
{
    VLOG_INFO(__FUNCTION__);
    return self->BSendRemotePlayTogetherInvite(steamIDFriend);
}


//-----------------------------------------------------------------------------
// ISteamNetworkingSockets flat API implementations
//-----------------------------------------------------------------------------

S_API HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP( ISteamNetworkingSockets* self, const SteamNetworkingIPAddr & localAddress, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateListenSocketIP(localAddress, nOptions, pOptions);
}

S_API HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress( ISteamNetworkingSockets* self, const SteamNetworkingIPAddr & address, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConnectByIPAddress(address, nOptions, pOptions);
}

S_API HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P( ISteamNetworkingSockets* self, int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateListenSocketP2P(nVirtualPort, nOptions, pOptions);
}

S_API HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectP2P( ISteamNetworkingSockets* self, const SteamNetworkingIdentity & identityRemote, int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConnectP2P(identityRemote, nVirtualPort, nOptions, pOptions);
}

S_API EResult SteamAPI_ISteamNetworkingSockets_AcceptConnection( ISteamNetworkingSockets* self, HSteamNetConnection hConn )
{
    VLOG_INFO(__FUNCTION__);
    return self->AcceptConnection(hConn);
}

S_API bool SteamAPI_ISteamNetworkingSockets_CloseConnection( ISteamNetworkingSockets* self, HSteamNetConnection hPeer, int nReason, const char * pszDebug, bool bEnableLinger )
{
    VLOG_INFO(__FUNCTION__);
    return self->CloseConnection(hPeer, nReason, pszDebug, bEnableLinger);
}

S_API bool SteamAPI_ISteamNetworkingSockets_CloseListenSocket( ISteamNetworkingSockets* self, HSteamListenSocket hSocket )
{
    VLOG_INFO(__FUNCTION__);
    return self->CloseListenSocket(hSocket);
}

S_API bool SteamAPI_ISteamNetworkingSockets_SetConnectionUserData( ISteamNetworkingSockets* self, HSteamNetConnection hPeer, int64 nUserData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionUserData(hPeer, nUserData);
}

S_API int64 SteamAPI_ISteamNetworkingSockets_GetConnectionUserData( ISteamNetworkingSockets* self, HSteamNetConnection hPeer )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectionUserData(hPeer);
}

S_API void SteamAPI_ISteamNetworkingSockets_SetConnectionName( ISteamNetworkingSockets* self, HSteamNetConnection hPeer, const char * pszName )
{
    VLOG_INFO(__FUNCTION__);
    self->SetConnectionName(hPeer, pszName);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetConnectionName( ISteamNetworkingSockets* self, HSteamNetConnection hPeer, char * pszName, int nMaxLen )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectionName(hPeer, pszName, nMaxLen);
}

S_API EResult SteamAPI_ISteamNetworkingSockets_SendMessageToConnection( ISteamNetworkingSockets* self, HSteamNetConnection hConn, const void * pData, uint32 cbData, int nSendFlags, int64 * pOutMessageNumber )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendMessageToConnection(hConn, pData, cbData, nSendFlags, pOutMessageNumber);
}

S_API void SteamAPI_ISteamNetworkingSockets_SendMessages( ISteamNetworkingSockets* self, int nMessages, SteamNetworkingMessage_t *const * pMessages, int64 * pOutMessageNumberOrResult )
{
    VLOG_INFO(__FUNCTION__);
    self->SendMessages(nMessages, pMessages, pOutMessageNumberOrResult);
}

S_API EResult SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection( ISteamNetworkingSockets* self, HSteamNetConnection hConn )
{
    VLOG_INFO(__FUNCTION__);
    return self->FlushMessagesOnConnection(hConn);
}

S_API int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection( ISteamNetworkingSockets* self, HSteamNetConnection hConn, SteamNetworkingMessage_t ** ppOutMessages, int nMaxMessages )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReceiveMessagesOnConnection(hConn, ppOutMessages, nMaxMessages);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetConnectionInfo( ISteamNetworkingSockets* self, HSteamNetConnection hConn, SteamNetConnectionInfo_t * pInfo )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConnectionInfo(hConn, pInfo);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetQuickConnectionStatus( ISteamNetworkingSockets* self, HSteamNetConnection hConn, SteamNetworkingQuickConnectionStatus * pStats )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetQuickConnectionStatus(hConn, pStats);
}

S_API int SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus( ISteamNetworkingSockets* self, HSteamNetConnection hConn, char * pszBuf, int cbBuf )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDetailedConnectionStatus(hConn, pszBuf, cbBuf);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress( ISteamNetworkingSockets* self, HSteamListenSocket hSocket, SteamNetworkingIPAddr * address )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetListenSocketAddress(hSocket, address);
}

S_API bool SteamAPI_ISteamNetworkingSockets_CreateSocketPair( ISteamNetworkingSockets* self, HSteamNetConnection * pOutConnection1, HSteamNetConnection * pOutConnection2, bool bUseNetworkLoopback, const SteamNetworkingIdentity * pIdentity1, const SteamNetworkingIdentity * pIdentity2 )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateSocketPair(pOutConnection1, pOutConnection2, bUseNetworkLoopback, pIdentity1, pIdentity2);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetIdentity( ISteamNetworkingSockets* self, SteamNetworkingIdentity * pIdentity )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetIdentity(pIdentity);
}

S_API ESteamNetworkingAvailability SteamAPI_ISteamNetworkingSockets_InitAuthentication( ISteamNetworkingSockets* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->InitAuthentication();
}

S_API ESteamNetworkingAvailability SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus( ISteamNetworkingSockets* self, SteamNetAuthenticationStatus_t * pDetails )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAuthenticationStatus(pDetails);
}

S_API HSteamNetPollGroup SteamAPI_ISteamNetworkingSockets_CreatePollGroup( ISteamNetworkingSockets* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreatePollGroup();
}

S_API bool SteamAPI_ISteamNetworkingSockets_DestroyPollGroup( ISteamNetworkingSockets* self, HSteamNetPollGroup hPollGroup )
{
    VLOG_INFO(__FUNCTION__);
    return self->DestroyPollGroup(hPollGroup);
}

S_API bool SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup( ISteamNetworkingSockets* self, HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionPollGroup(hConn, hPollGroup);
}

S_API int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup( ISteamNetworkingSockets* self, HSteamNetPollGroup hPollGroup, SteamNetworkingMessage_t ** ppOutMessages, int nMaxMessages )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReceiveMessagesOnPollGroup(hPollGroup, ppOutMessages, nMaxMessages);
}

S_API bool SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket( ISteamNetworkingSockets* self, const void * pvTicket, int cbTicket, SteamDatagramRelayAuthTicket * pOutParsedTicket )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReceivedRelayAuthTicket(pvTicket, cbTicket, pOutParsedTicket);
}

S_API int SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer( ISteamNetworkingSockets* self, const SteamNetworkingIdentity & identityGameServer, int nVirtualPort, SteamDatagramRelayAuthTicket * pOutParsedTicket )
{
    VLOG_INFO(__FUNCTION__);
    return self->FindRelayAuthTicketForServer(identityGameServer, nVirtualPort, pOutParsedTicket);
}

S_API HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer( ISteamNetworkingSockets* self, const SteamNetworkingIdentity & identityTarget, int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConnectToHostedDedicatedServer(identityTarget, nVirtualPort, nOptions, pOptions);
}

S_API uint16 SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort( ISteamNetworkingSockets* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHostedDedicatedServerPort();
}

S_API SteamNetworkingPOPID SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID( ISteamNetworkingSockets* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHostedDedicatedServerPOPID();
}

S_API EResult SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress( ISteamNetworkingSockets* self, SteamDatagramHostedAddress * pRouting )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetHostedDedicatedServerAddress(pRouting);
}

S_API HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket( ISteamNetworkingSockets* self, int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateHostedDedicatedServerListenSocket(nVirtualPort, nOptions, pOptions);
}

S_API EResult SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin( ISteamNetworkingSockets* self, SteamDatagramGameCoordinatorServerLogin * pLoginInfo, int * pcbSignedBlob, void * pBlob )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetGameCoordinatorServerLogin(pLoginInfo, pcbSignedBlob, pBlob);
}

S_API HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling( ISteamNetworkingSockets* self, ISteamNetworkingConnectionCustomSignaling * pSignaling, const SteamNetworkingIdentity * pPeerIdentity, int nOptions, const SteamNetworkingConfigValue_t * pOptions )
{
    VLOG_INFO(__FUNCTION__);
    return self->ConnectP2PCustomSignaling(pSignaling, pPeerIdentity, nOptions, pOptions);
}

S_API bool SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal( ISteamNetworkingSockets* self, const void * pMsg, int cbMsg, ISteamNetworkingCustomSignalingRecvContext * pContext )
{
    VLOG_INFO(__FUNCTION__);
    return self->ReceivedP2PCustomSignal(pMsg, cbMsg, pContext);
}

S_API bool SteamAPI_ISteamNetworkingSockets_GetCertificateRequest( ISteamNetworkingSockets* self, int * pcbBlob, void * pBlob, SteamNetworkingErrMsg & errMsg )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetCertificateRequest(pcbBlob, pBlob, errMsg);
}

S_API bool SteamAPI_ISteamNetworkingSockets_SetCertificate( ISteamNetworkingSockets* self, const void * pCertificate, int cbCertificate, SteamNetworkingErrMsg & errMsg )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetCertificate(pCertificate, cbCertificate, errMsg);
}


//-----------------------------------------------------------------------------
// ISteamNetworkingConnectionCustomSignaling flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamNetworkingConnectionCustomSignaling_SendSignal( ISteamNetworkingConnectionCustomSignaling* self, HSteamNetConnection hConn, const SteamNetConnectionInfo_t & info, const void * pMsg, int cbMsg )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendSignal(hConn, info, pMsg, cbMsg);
}

S_API void SteamAPI_ISteamNetworkingConnectionCustomSignaling_Release( ISteamNetworkingConnectionCustomSignaling* self )
{
    VLOG_INFO(__FUNCTION__);
    self->Release();
}


//-----------------------------------------------------------------------------
// ISteamNetworkingCustomSignalingRecvContext flat API implementations
//-----------------------------------------------------------------------------

S_API ISteamNetworkingConnectionCustomSignaling * SteamAPI_ISteamNetworkingCustomSignalingRecvContext_OnConnectRequest( ISteamNetworkingCustomSignalingRecvContext* self, HSteamNetConnection hConn, const SteamNetworkingIdentity & identityPeer )
{
    VLOG_INFO(__FUNCTION__);
    return self->OnConnectRequest(hConn, identityPeer);
}

S_API void SteamAPI_ISteamNetworkingCustomSignalingRecvContext_SendRejectionSignal( ISteamNetworkingCustomSignalingRecvContext* self, const SteamNetworkingIdentity & identityPeer, const void * pMsg, int cbMsg )
{
    VLOG_INFO(__FUNCTION__);
    self->SendRejectionSignal(identityPeer, pMsg, cbMsg);
}


//-----------------------------------------------------------------------------
// ISteamNetworkingUtils flat API implementations
//-----------------------------------------------------------------------------

S_API SteamNetworkingMessage_t * SteamAPI_ISteamNetworkingUtils_AllocateMessage( ISteamNetworkingUtils* self, int cbAllocateBuffer )
{
    VLOG_INFO(__FUNCTION__);
    return self->AllocateMessage(cbAllocateBuffer);
}

S_API void SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess( ISteamNetworkingUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    self->InitRelayNetworkAccess();
}

S_API ESteamNetworkingAvailability SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus( ISteamNetworkingUtils* self, SteamRelayNetworkStatus_t * pDetails )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetRelayNetworkStatus(pDetails);
}

S_API float SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation( ISteamNetworkingUtils* self, SteamNetworkPingLocation_t & result )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLocalPingLocation(result);
}

S_API int SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations( ISteamNetworkingUtils* self, const SteamNetworkPingLocation_t & location1, const SteamNetworkPingLocation_t & location2 )
{
    VLOG_INFO(__FUNCTION__);
    return self->EstimatePingTimeBetweenTwoLocations(location1, location2);
}

S_API int SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost( ISteamNetworkingUtils* self, const SteamNetworkPingLocation_t & remoteLocation )
{
    VLOG_INFO(__FUNCTION__);
    return self->EstimatePingTimeFromLocalHost(remoteLocation);
}

S_API void SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString( ISteamNetworkingUtils* self, const SteamNetworkPingLocation_t & location, char * pszBuf, int cchBufSize )
{
    VLOG_INFO(__FUNCTION__);
    self->ConvertPingLocationToString(location, pszBuf, cchBufSize);
}

S_API bool SteamAPI_ISteamNetworkingUtils_ParsePingLocationString( ISteamNetworkingUtils* self, const char * pszString, SteamNetworkPingLocation_t & result )
{
    VLOG_INFO(__FUNCTION__);
    return self->ParsePingLocationString(pszString, result);
}

S_API bool SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate( ISteamNetworkingUtils* self, float flMaxAgeSeconds )
{
    VLOG_INFO(__FUNCTION__);
    return self->CheckPingDataUpToDate(flMaxAgeSeconds);
}

S_API int SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter( ISteamNetworkingUtils* self, SteamNetworkingPOPID popID, SteamNetworkingPOPID * pViaRelayPoP )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPingToDataCenter(popID, pViaRelayPoP);
}

S_API int SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP( ISteamNetworkingUtils* self, SteamNetworkingPOPID popID )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetDirectPingToPOP(popID);
}

S_API int SteamAPI_ISteamNetworkingUtils_GetPOPCount( ISteamNetworkingUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPOPCount();
}

S_API int SteamAPI_ISteamNetworkingUtils_GetPOPList( ISteamNetworkingUtils* self, SteamNetworkingPOPID * list, int nListSz )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPOPList(list, nListSz);
}

S_API SteamNetworkingMicroseconds SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp( ISteamNetworkingUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetLocalTimestamp();
}

S_API void SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction( ISteamNetworkingUtils* self, ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pfnFunc )
{
    VLOG_INFO(__FUNCTION__);
    self->SetDebugOutputFunction(eDetailLevel, pfnFunc);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, int32 val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetGlobalConfigValueInt32(eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueFloat( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, float val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetGlobalConfigValueFloat(eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, const char * val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetGlobalConfigValueString(eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32( ISteamNetworkingUtils* self, HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, int32 val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionConfigValueInt32(hConn, eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueFloat( ISteamNetworkingUtils* self, HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, float val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionConfigValueFloat(hConn, eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString( ISteamNetworkingUtils* self, HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, const char * val )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConnectionConfigValueString(hConn, eValue, val);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetConfigValue( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, intptr_t scopeObj, ESteamNetworkingConfigDataType eDataType, const void * pArg )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConfigValue(eValue, eScopeType, scopeObj, eDataType, pArg);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SetConfigValueStruct( ISteamNetworkingUtils* self, const SteamNetworkingConfigValue_t & opt, ESteamNetworkingConfigScope eScopeType, intptr_t scopeObj )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetConfigValueStruct(opt, eScopeType, scopeObj);
}

S_API ESteamNetworkingGetConfigValueResult SteamAPI_ISteamNetworkingUtils_GetConfigValue( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, intptr_t scopeObj, ESteamNetworkingConfigDataType * pOutDataType, void * pResult, size_t * cbResult )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConfigValue(eValue, eScopeType, scopeObj, pOutDataType, pResult, cbResult);
}

S_API bool SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo( ISteamNetworkingUtils* self, ESteamNetworkingConfigValue eValue, const char ** pOutName, ESteamNetworkingConfigDataType * pOutDataType, ESteamNetworkingConfigScope * pOutScope, ESteamNetworkingConfigValue * pOutNextValue )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetConfigValueInfo(eValue, pOutName, pOutDataType, pOutScope, pOutNextValue);
}

S_API ESteamNetworkingConfigValue SteamAPI_ISteamNetworkingUtils_GetFirstConfigValue( ISteamNetworkingUtils* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetFirstConfigValue();
}

S_API void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString( ISteamNetworkingUtils* self, const SteamNetworkingIPAddr & addr, char * buf, uint32 cbBuf, bool bWithPort )
{
    VLOG_INFO(__FUNCTION__);
    self->SteamNetworkingIPAddr_ToString(addr, buf, cbBuf, bWithPort);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString( ISteamNetworkingUtils* self, SteamNetworkingIPAddr * pAddr, const char * pszStr )
{
    VLOG_INFO(__FUNCTION__);
    return self->SteamNetworkingIPAddr_ParseString(pAddr, pszStr);
}

S_API void SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString( ISteamNetworkingUtils* self, const SteamNetworkingIdentity & identity, char * buf, uint32 cbBuf )
{
    VLOG_INFO(__FUNCTION__);
    self->SteamNetworkingIdentity_ToString(identity, buf, cbBuf);
}

S_API bool SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString( ISteamNetworkingUtils* self, SteamNetworkingIdentity * pIdentity, const char * pszStr )
{
    VLOG_INFO(__FUNCTION__);
    return self->SteamNetworkingIdentity_ParseString(pIdentity, pszStr);
}


//-----------------------------------------------------------------------------
// ISteamGameServer flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamGameServer_SetProduct( ISteamGameServer* self, const char * pszProduct )
{
    VLOG_INFO(__FUNCTION__);
    self->SetProduct(pszProduct);
}

S_API void SteamAPI_ISteamGameServer_SetGameDescription( ISteamGameServer* self, const char * pszGameDescription )
{
    VLOG_INFO(__FUNCTION__);
    self->SetGameDescription(pszGameDescription);
}

S_API void SteamAPI_ISteamGameServer_SetModDir( ISteamGameServer* self, const char * pszModDir )
{
    VLOG_INFO(__FUNCTION__);
    self->SetModDir(pszModDir);
}

S_API void SteamAPI_ISteamGameServer_SetDedicatedServer( ISteamGameServer* self, bool bDedicated )
{
    VLOG_INFO(__FUNCTION__);
    self->SetDedicatedServer(bDedicated);
}

S_API void SteamAPI_ISteamGameServer_LogOn( ISteamGameServer* self, const char * pszToken )
{
    VLOG_INFO(__FUNCTION__);
    self->LogOn(pszToken);
}

S_API void SteamAPI_ISteamGameServer_LogOnAnonymous( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    self->LogOnAnonymous();
}

S_API void SteamAPI_ISteamGameServer_LogOff( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    self->LogOff();
}

S_API bool SteamAPI_ISteamGameServer_BLoggedOn( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BLoggedOn();
}

S_API bool SteamAPI_ISteamGameServer_BSecure( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->BSecure();
}

S_API uint64_steamid SteamAPI_ISteamGameServer_GetSteamID( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetSteamID().ConvertToUint64();
}

S_API bool SteamAPI_ISteamGameServer_WasRestartRequested( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->WasRestartRequested();
}

S_API void SteamAPI_ISteamGameServer_SetMaxPlayerCount( ISteamGameServer* self, int cPlayersMax )
{
    VLOG_INFO(__FUNCTION__);
    self->SetMaxPlayerCount(cPlayersMax);
}

S_API void SteamAPI_ISteamGameServer_SetBotPlayerCount( ISteamGameServer* self, int cBotplayers )
{
    VLOG_INFO(__FUNCTION__);
    self->SetBotPlayerCount(cBotplayers);
}

S_API void SteamAPI_ISteamGameServer_SetServerName( ISteamGameServer* self, const char * pszServerName )
{
    VLOG_INFO(__FUNCTION__);
    self->SetServerName(pszServerName);
}

S_API void SteamAPI_ISteamGameServer_SetMapName( ISteamGameServer* self, const char * pszMapName )
{
    VLOG_INFO(__FUNCTION__);
    self->SetMapName(pszMapName);
}

S_API void SteamAPI_ISteamGameServer_SetPasswordProtected( ISteamGameServer* self, bool bPasswordProtected )
{
    VLOG_INFO(__FUNCTION__);
    self->SetPasswordProtected(bPasswordProtected);
}

S_API void SteamAPI_ISteamGameServer_SetSpectatorPort( ISteamGameServer* self, uint16 unSpectatorPort )
{
    VLOG_INFO(__FUNCTION__);
    self->SetSpectatorPort(unSpectatorPort);
}

S_API void SteamAPI_ISteamGameServer_SetSpectatorServerName( ISteamGameServer* self, const char * pszSpectatorServerName )
{
    VLOG_INFO(__FUNCTION__);
    self->SetSpectatorServerName(pszSpectatorServerName);
}

S_API void SteamAPI_ISteamGameServer_ClearAllKeyValues( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    self->ClearAllKeyValues();
}

S_API void SteamAPI_ISteamGameServer_SetKeyValue( ISteamGameServer* self, const char * pKey, const char * pValue )
{
    VLOG_INFO(__FUNCTION__);
    self->SetKeyValue(pKey, pValue);
}

S_API void SteamAPI_ISteamGameServer_SetGameTags( ISteamGameServer* self, const char * pchGameTags )
{
    VLOG_INFO(__FUNCTION__);
    self->SetGameTags(pchGameTags);
}

S_API void SteamAPI_ISteamGameServer_SetGameData( ISteamGameServer* self, const char * pchGameData )
{
    VLOG_INFO(__FUNCTION__);
    self->SetGameData(pchGameData);
}

S_API void SteamAPI_ISteamGameServer_SetRegion( ISteamGameServer* self, const char * pszRegion )
{
    VLOG_INFO(__FUNCTION__);
    self->SetRegion(pszRegion);
}

S_API bool SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate( ISteamGameServer* self, uint32 unIPClient, const void * pvAuthBlob, uint32 cubAuthBlobSize, CSteamID * pSteamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
}

S_API uint64_steamid SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->CreateUnauthenticatedUserConnection().ConvertToUint64();
}

S_API void SteamAPI_ISteamGameServer_SendUserDisconnect( ISteamGameServer* self, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    self->SendUserDisconnect(steamIDUser);
}

S_API bool SteamAPI_ISteamGameServer_BUpdateUserData( ISteamGameServer* self, uint64_steamid steamIDUser, const char * pchPlayerName, uint32 uScore )
{
    VLOG_INFO(__FUNCTION__);
    return self->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
}

S_API HAuthTicket SteamAPI_ISteamGameServer_GetAuthSessionTicket( ISteamGameServer* self, void * pTicket, int cbMaxTicket, uint32 * pcbTicket )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API EBeginAuthSessionResult SteamAPI_ISteamGameServer_BeginAuthSession( ISteamGameServer* self, const void * pAuthTicket, int cbAuthTicket, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    return self->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
}

S_API void SteamAPI_ISteamGameServer_EndAuthSession( ISteamGameServer* self, uint64_steamid steamID )
{
    VLOG_INFO(__FUNCTION__);
    self->EndAuthSession(steamID);
}

S_API void SteamAPI_ISteamGameServer_CancelAuthTicket( ISteamGameServer* self, HAuthTicket hAuthTicket )
{
    VLOG_INFO(__FUNCTION__);
    self->CancelAuthTicket(hAuthTicket);
}

S_API EUserHasLicenseForAppResult SteamAPI_ISteamGameServer_UserHasLicenseForApp( ISteamGameServer* self, uint64_steamid steamID, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__);
    return self->UserHasLicenseForApp(steamID, appID);
}

S_API bool SteamAPI_ISteamGameServer_RequestUserGroupStatus( ISteamGameServer* self, uint64_steamid steamIDUser, uint64_steamid steamIDGroup )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestUserGroupStatus(steamIDUser, steamIDGroup);
}

S_API void SteamAPI_ISteamGameServer_GetGameplayStats( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    self->GetGameplayStats();
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_GetServerReputation( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetServerReputation();
}

S_API SteamIPAddress_t SteamAPI_ISteamGameServer_GetPublicIP( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetPublicIP();
}

S_API bool SteamAPI_ISteamGameServer_HandleIncomingPacket( ISteamGameServer* self, const void * pData, int cbData, uint32 srcIP, uint16 srcPort )
{
    VLOG_INFO(__FUNCTION__);
    return self->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
}

S_API int SteamAPI_ISteamGameServer_GetNextOutgoingPacket( ISteamGameServer* self, void * pOut, int cbMaxOut, uint32 * pNetAdr, uint16 * pPort )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
}

S_API void SteamAPI_ISteamGameServer_EnableHeartbeats( ISteamGameServer* self, bool bActive )
{
    VLOG_INFO(__FUNCTION__);
    self->EnableHeartbeats(bActive);
}

S_API void SteamAPI_ISteamGameServer_SetHeartbeatInterval( ISteamGameServer* self, int iHeartbeatInterval )
{
    VLOG_INFO(__FUNCTION__);
    self->SetHeartbeatInterval(iHeartbeatInterval);
}

S_API void SteamAPI_ISteamGameServer_ForceHeartbeat( ISteamGameServer* self )
{
    VLOG_INFO(__FUNCTION__);
    self->ForceHeartbeat();
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_AssociateWithClan( ISteamGameServer* self, uint64_steamid steamIDClan )
{
    VLOG_INFO(__FUNCTION__);
    return self->AssociateWithClan(steamIDClan);
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility( ISteamGameServer* self, uint64_steamid steamIDNewPlayer )
{
    VLOG_INFO(__FUNCTION__);
    return self->ComputeNewPlayerCompatibility(steamIDNewPlayer);
}


//-----------------------------------------------------------------------------
// ISteamGameServerStats flat API implementations
//-----------------------------------------------------------------------------

S_API SteamAPICall_t SteamAPI_ISteamGameServerStats_RequestUserStats( ISteamGameServerStats* self, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->RequestUserStats(steamIDUser);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStatInt32( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, int32 * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStatFloat( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, float * pData )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserAchievement( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, bool * pbAchieved )
{
    VLOG_INFO(__FUNCTION__);
    return self->GetUserAchievement(steamIDUser, pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStatInt32( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, int32 nData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetUserStat(steamIDUser, pchName, nData);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStatFloat( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, float fData )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetUserStat(steamIDUser, pchName, fData);
}

S_API bool SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName, float flCountThisSession, double dSessionLength )
{
    VLOG_INFO(__FUNCTION__);
    return self->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserAchievement( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->SetUserAchievement(steamIDUser, pchName);
}

S_API bool SteamAPI_ISteamGameServerStats_ClearUserAchievement( ISteamGameServerStats* self, uint64_steamid steamIDUser, const char * pchName )
{
    VLOG_INFO(__FUNCTION__);
    return self->ClearUserAchievement(steamIDUser, pchName);
}

S_API SteamAPICall_t SteamAPI_ISteamGameServerStats_StoreUserStats( ISteamGameServerStats* self, uint64_steamid steamIDUser )
{
    VLOG_INFO(__FUNCTION__);
    return self->StoreUserStats(steamIDUser);
}

//-----------------------------------------------------------------------------
// Preserved existing functions
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamUserStats_GetStat(intptr_t instancePtr, const char * pchName, int32 * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetStat0(intptr_t instancePtr, const char * pchName, float * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_SetStat(intptr_t instancePtr, const char * pchName, int32 nData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->SetStat(pchName, nData);
}

S_API bool SteamAPI_ISteamUserStats_SetStat0(intptr_t instancePtr, const char * pchName, float fData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->SetStat(pchName, fData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStat(intptr_t instancePtr, const char * pchStatName, int64 * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStat(pchStatName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStat0(intptr_t instancePtr, const char * pchStatName, double * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStat(pchStatName, pData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory(intptr_t instancePtr, const char * pchStatName, int64 * pData, uint32 cubData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStatHistory(pchStatName, pData, cubData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory0(intptr_t instancePtr, const char * pchStatName, double * pData, uint32 cubData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStatHistory(pchStatName, pData, cubData);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequest(intptr_t instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return k_UGCQueryHandleInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequest0(intptr_t instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, const char * pchCursor)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return k_UGCQueryHandleInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, pchCursor);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag0(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, const char * pchKey, char * pchValue, uint32 cchValueSize)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetQueryUGCKeyValueTag(handle, index, pchKey, pchValue, cchValueSize);
}

S_API void SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface(intptr_t instancePtr)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    // reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->DestructISteamHTMLSurface();
}

S_API bool SteamAPI_ISteamInventory_SetProperty(intptr_t instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, const char * pchPropertyValue)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->SetProperty(handle, nItemID, pchPropertyName, pchPropertyValue);
}

S_API bool SteamAPI_ISteamInventory_SetProperty0(intptr_t instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, bool bValue)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->SetProperty(handle, nItemID, pchPropertyName, bValue);
}

S_API bool SteamAPI_ISteamInventory_SetProperty1(intptr_t instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, int64 nValue)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->SetProperty(handle, nItemID, pchPropertyName, nValue);
}

S_API bool SteamAPI_ISteamInventory_SetProperty2(intptr_t instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, float flValue)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->SetProperty(handle, nItemID, pchPropertyName, flValue);
}

S_API bool SteamAPI_ISteamGameServer_InitGameServer(intptr_t instancePtr, uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char * pchVersionString)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 nData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->SetUserStat(steamIDUser, pchName, nData);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float fData)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->SetUserStat(steamIDUser, pchName, fData);
}

S_API bool SteamAPI_ISteamController_ShowDigitalActionOrigins(intptr_t instancePtr, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController006*>(instancePtr)->ShowDigitalActionOrigins(controllerHandle, digitalActionHandle, flScale, flXPosition, flYPosition);
}

S_API bool SteamAPI_ISteamController_ShowAnalogActionOrigins(intptr_t instancePtr, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController006*>(instancePtr)->ShowAnalogActionOrigins(controllerHandle, analogActionHandle, flScale, flXPosition, flYPosition);
}

S_API class ISteamUnifiedMessages * SteamAPI_ISteamClient_GetISteamUnifiedMessages(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient016*>(instancePtr)->GetISteamUnifiedMessages(hSteamuser, hSteamPipe, pchVersion);
}

S_API ClientUnifiedMessageHandle SteamAPI_ISteamUnifiedMessages_SendMethod(intptr_t instancePtr, const char * pchServiceMethod, const void * pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return ISteamUnifiedMessages::k_InvalidUnifiedMessageHandle;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->SendMethod(pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
}

S_API bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, uint32 * punResponseSize, EResult * peResult)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->GetMethodResponseInfo(hHandle, punResponseSize, peResult);
}

S_API bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseData(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, void * pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->GetMethodResponseData(hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
}

S_API bool SteamAPI_ISteamUnifiedMessages_ReleaseMethod(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->ReleaseMethod(hHandle);
}

S_API bool SteamAPI_ISteamUnifiedMessages_SendNotification(intptr_t instancePtr, const char * pchServiceNotification, const void * pNotificationBuffer, uint32 unNotificationBufferSize)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->SendNotification(pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
}

S_API void SteamAPI_ISteamClient_RunFrame(intptr_t instancePtr)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->RunFrame();
}

S_API void SteamAPI_ISteamClient_Set_SteamAPI_CPostAPIResultInProcess(intptr_t instancePtr, SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient016*>(instancePtr)->Set_SteamAPI_CPostAPIResultInProcess(func);
}

S_API void SteamAPI_ISteamClient_Remove_SteamAPI_CPostAPIResultInProcess(intptr_t instancePtr, SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient016*>(instancePtr)->Remove_SteamAPI_CPostAPIResultInProcess(func);
}

S_API void SteamAPI_ISteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(intptr_t instancePtr, SteamAPI_CheckCallbackRegistered_t func)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->Set_SteamAPI_CCheckCallbackRegisteredInProcess(func);
}

S_API void SteamAPI_ISteamUtils_RunFrame(intptr_t instancePtr)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamUtils*>(instancePtr)->RunFrame();
}

S_API bool SteamAPI_ISteamController_GetControllerState(intptr_t instancePtr, uint32 unControllerIndex, struct SteamControllerState001_t * pState)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController001*>(instancePtr)->GetControllerState(unControllerIndex, pState);
}

S_API void SteamAPI_ISteamController_SetOverrideMode(intptr_t instancePtr, const char * pchMode)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return;
    reinterpret_cast<ISteamController001*>(instancePtr)->SetOverrideMode(pchMode);
}

S_API bool SteamAPI_ISteamUGC_GetItemUpdateInfo(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, bool * pbNeedsUpdate, bool * pbIsDownloading, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
    VLOG_INFO(__FUNCTION__);
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC003*>(instancePtr)->GetItemUpdateInfo(nPublishedFileID, pbNeedsUpdate, pbIsDownloading, punBytesDownloaded, punBytesTotal);
}
