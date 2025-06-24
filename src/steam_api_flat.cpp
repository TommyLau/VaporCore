/*
 * VaporCore Steam API Implementation - Flat API
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * Auto-generated from steam_api_flat.h
 */

#include <steam_api.h>
#include <steam_api_flat.h>
#include <steam_gameserver.h>
#include <steam_game_server_stats.h>

#include "logger.h"

//-----------------------------------------------------------------------------
// ISteamClient flat API implementations
//-----------------------------------------------------------------------------

S_API HSteamPipe SteamAPI_ISteamClient_CreateSteamPipe(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_CreateSteamPipe called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamClient*>(instancePtr)->CreateSteamPipe();
}

S_API bool SteamAPI_ISteamClient_BReleaseSteamPipe(intptr_t instancePtr, HSteamPipe hSteamPipe)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_BReleaseSteamPipe called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamClient*>(instancePtr)->BReleaseSteamPipe(hSteamPipe);
}

S_API HSteamUser SteamAPI_ISteamClient_ConnectToGlobalUser(intptr_t instancePtr, HSteamPipe hSteamPipe)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_ConnectToGlobalUser called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamClient*>(instancePtr)->ConnectToGlobalUser(hSteamPipe);
}

S_API HSteamUser SteamAPI_ISteamClient_CreateLocalUser(intptr_t instancePtr, HSteamPipe * phSteamPipe, EAccountType eAccountType)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_CreateLocalUser called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamClient*>(instancePtr)->CreateLocalUser(phSteamPipe, eAccountType);
}

S_API void SteamAPI_ISteamClient_ReleaseUser(intptr_t instancePtr, HSteamPipe hSteamPipe, HSteamUser hUser)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_ReleaseUser called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->ReleaseUser(hSteamPipe, hUser);
}

S_API class ISteamUser * SteamAPI_ISteamClient_GetISteamUser(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamUser called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamGameServer * SteamAPI_ISteamClient_GetISteamGameServer(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamGameServer called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}

S_API void SteamAPI_ISteamClient_SetLocalIPBinding(intptr_t instancePtr, uint32 unIP, uint16 usPort)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_SetLocalIPBinding called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->SetLocalIPBinding(unIP, usPort);
}

S_API class ISteamFriends * SteamAPI_ISteamClient_GetISteamFriends(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamFriends called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamUtils * SteamAPI_ISteamClient_GetISteamUtils(intptr_t instancePtr, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamUtils called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamUtils(hSteamPipe, pchVersion);
}

S_API class ISteamMatchmaking * SteamAPI_ISteamClient_GetISteamMatchmaking(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamMatchmaking called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamMatchmakingServers * SteamAPI_ISteamClient_GetISteamMatchmakingServers(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamMatchmakingServers called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}

S_API void * SteamAPI_ISteamClient_GetISteamGenericInterface(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamGenericInterface called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamUserStats * SteamAPI_ISteamClient_GetISteamUserStats(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamUserStats called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamGameServerStats * SteamAPI_ISteamClient_GetISteamGameServerStats(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamGameServerStats called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamGameServerStats(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamApps * SteamAPI_ISteamClient_GetISteamApps(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamApps called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamNetworking * SteamAPI_ISteamClient_GetISteamNetworking(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamNetworking called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamRemoteStorage * SteamAPI_ISteamClient_GetISteamRemoteStorage(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamRemoteStorage called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamRemoteStorage(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamScreenshots * SteamAPI_ISteamClient_GetISteamScreenshots(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamScreenshots called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamScreenshots(hSteamuser, hSteamPipe, pchVersion);
}

S_API void SteamAPI_ISteamClient_RunFrame(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_RunFrame called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->RunFrame();
}

S_API uint32 SteamAPI_ISteamClient_GetIPCCallCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetIPCCallCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetIPCCallCount();
}

S_API void SteamAPI_ISteamClient_SetWarningMessageHook(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_SetWarningMessageHook called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->SetWarningMessageHook(pFunction);
}

S_API bool SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_BShutdownIfAllPipesClosed called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamClient*>(instancePtr)->BShutdownIfAllPipesClosed();
}

S_API class ISteamHTTP * SteamAPI_ISteamClient_GetISteamHTTP(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamHTTP called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamHTTP(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamUnifiedMessages * SteamAPI_ISteamClient_GetISteamUnifiedMessages(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamUnifiedMessages called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamUnifiedMessages(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamController * SteamAPI_ISteamClient_GetISteamController(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamController called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamUGC * SteamAPI_ISteamClient_GetISteamUGC(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamUGC called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamAppList * SteamAPI_ISteamClient_GetISteamAppList(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamAppList called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}

S_API class ISteamMusic * SteamAPI_ISteamClient_GetISteamMusic(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamMusic called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamMusic(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamMusicRemote * SteamAPI_ISteamClient_GetISteamMusicRemote(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamMusicRemote called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamMusicRemote(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamHTMLSurface * SteamAPI_ISteamClient_GetISteamHTMLSurface(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamHTMLSurface called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamHTMLSurface(hSteamuser, hSteamPipe, pchVersion);
}

S_API void SteamAPI_ISteamClient_Set_SteamAPI_CPostAPIResultInProcess(intptr_t instancePtr, SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_Set_SteamAPI_CPostAPIResultInProcess called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->Set_SteamAPI_CPostAPIResultInProcess(func);
}

S_API void SteamAPI_ISteamClient_Remove_SteamAPI_CPostAPIResultInProcess(intptr_t instancePtr, SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_Remove_SteamAPI_CPostAPIResultInProcess called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->Remove_SteamAPI_CPostAPIResultInProcess(func);
}

S_API void SteamAPI_ISteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(intptr_t instancePtr, SteamAPI_CheckCallbackRegistered_t func)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamClient*>(instancePtr)->Set_SteamAPI_CCheckCallbackRegisteredInProcess(func);
}

S_API class ISteamInventory * SteamAPI_ISteamClient_GetISteamInventory(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamInventory called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamInventory(hSteamuser, hSteamPipe, pchVersion);
}

S_API class ISteamVideo * SteamAPI_ISteamClient_GetISteamVideo(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
    VLOG_DEBUG("SteamAPI_ISteamClient_GetISteamVideo called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamClient*>(instancePtr)->GetISteamVideo(hSteamuser, hSteamPipe, pchVersion);
}


//-----------------------------------------------------------------------------
// ISteamUser flat API implementations
//-----------------------------------------------------------------------------

S_API HSteamUser SteamAPI_ISteamUser_GetHSteamUser(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetHSteamUser called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetHSteamUser();
}

S_API bool SteamAPI_ISteamUser_BLoggedOn(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_BLoggedOn called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUser*>(instancePtr)->BLoggedOn();
}

S_API uint64 SteamAPI_ISteamUser_GetSteamID(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetSteamID called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetSteamID().ConvertToUint64();
}

S_API int SteamAPI_ISteamUser_InitiateGameConnection(intptr_t instancePtr, void * pAuthBlob, int cbMaxAuthBlob, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_InitiateGameConnection called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->InitiateGameConnection(pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
}

S_API void SteamAPI_ISteamUser_TerminateGameConnection(intptr_t instancePtr, uint32 unIPServer, uint16 usPortServer)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_TerminateGameConnection called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->TerminateGameConnection(unIPServer, usPortServer);
}

S_API void SteamAPI_ISteamUser_TrackAppUsageEvent(intptr_t instancePtr, class CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_TrackAppUsageEvent called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
}

S_API bool SteamAPI_ISteamUser_GetUserDataFolder(intptr_t instancePtr, char * pchBuffer, int cubBuffer)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetUserDataFolder called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetUserDataFolder(pchBuffer, cubBuffer);
}

S_API void SteamAPI_ISteamUser_StartVoiceRecording(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_StartVoiceRecording called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->StartVoiceRecording();
}

S_API void SteamAPI_ISteamUser_StopVoiceRecording(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_StopVoiceRecording called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->StopVoiceRecording();
}

S_API EVoiceResult SteamAPI_ISteamUser_GetAvailableVoice(intptr_t instancePtr, uint32 * pcbCompressed, uint32 * pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetAvailableVoice called");
    if (!instancePtr) return k_EVoiceResultNotInitialized;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetAvailableVoice(pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
}

S_API EVoiceResult SteamAPI_ISteamUser_GetVoice(intptr_t instancePtr, bool bWantCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, bool bWantUncompressed, void * pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 * nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetVoice called");
    if (!instancePtr) return k_EVoiceResultNotInitialized;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetVoice(bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
}

S_API EVoiceResult SteamAPI_ISteamUser_DecompressVoice(intptr_t instancePtr, const void * pCompressed, uint32 cbCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, uint32 nDesiredSampleRate)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_DecompressVoice called");
    if (!instancePtr) return k_EVoiceResultNotInitialized;
    return reinterpret_cast<ISteamUser*>(instancePtr)->DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
}

S_API uint32 SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetVoiceOptimalSampleRate called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetVoiceOptimalSampleRate();
}

S_API HAuthTicket SteamAPI_ISteamUser_GetAuthSessionTicket(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetAuthSessionTicket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API EBeginAuthSessionResult SteamAPI_ISteamUser_BeginAuthSession(intptr_t instancePtr, const void * pAuthTicket, int cbAuthTicket, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_BeginAuthSession called");
    if (!instancePtr) return k_EBeginAuthSessionResultInvalidTicket;
    return reinterpret_cast<ISteamUser*>(instancePtr)->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
}

S_API void SteamAPI_ISteamUser_EndAuthSession(intptr_t instancePtr, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_EndAuthSession called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->EndAuthSession(steamID);
}

S_API void SteamAPI_ISteamUser_CancelAuthTicket(intptr_t instancePtr, HAuthTicket hAuthTicket)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_CancelAuthTicket called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->CancelAuthTicket(hAuthTicket);
}

S_API EUserHasLicenseForAppResult SteamAPI_ISteamUser_UserHasLicenseForApp(intptr_t instancePtr, class CSteamID steamID, AppId_t appID)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_UserHasLicenseForApp called");
    if (!instancePtr) return k_EUserHasLicenseResultHasLicense;
    return reinterpret_cast<ISteamUser*>(instancePtr)->UserHasLicenseForApp(steamID, appID);
}

S_API bool SteamAPI_ISteamUser_BIsBehindNAT(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_BIsBehindNAT called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUser*>(instancePtr)->BIsBehindNAT();
}

S_API void SteamAPI_ISteamUser_AdvertiseGame(intptr_t instancePtr, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_AdvertiseGame called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUser*>(instancePtr)->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
}

S_API SteamAPICall_t SteamAPI_ISteamUser_RequestEncryptedAppTicket(intptr_t instancePtr, void * pDataToInclude, int cbDataToInclude)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_RequestEncryptedAppTicket called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUser*>(instancePtr)->RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude);
}

S_API bool SteamAPI_ISteamUser_GetEncryptedAppTicket(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetEncryptedAppTicket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetEncryptedAppTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API int SteamAPI_ISteamUser_GetGameBadgeLevel(intptr_t instancePtr, int nSeries, bool bFoil)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetGameBadgeLevel called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetGameBadgeLevel(nSeries, bFoil);
}

S_API int SteamAPI_ISteamUser_GetPlayerSteamLevel(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_GetPlayerSteamLevel called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUser*>(instancePtr)->GetPlayerSteamLevel();
}

S_API SteamAPICall_t SteamAPI_ISteamUser_RequestStoreAuthURL(intptr_t instancePtr, const char * pchRedirectURL)
{
    VLOG_DEBUG("SteamAPI_ISteamUser_RequestStoreAuthURL called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUser*>(instancePtr)->RequestStoreAuthURL(pchRedirectURL);
}


//-----------------------------------------------------------------------------
// ISteamFriends flat API implementations
//-----------------------------------------------------------------------------

S_API const char * SteamAPI_ISteamFriends_GetPersonaName(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetPersonaName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetPersonaName();
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_SetPersonaName(intptr_t instancePtr, const char * pchPersonaName)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SetPersonaName called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->SetPersonaName(pchPersonaName);
}

S_API EPersonaState SteamAPI_ISteamFriends_GetPersonaState(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetPersonaState called");
    if (!instancePtr) return k_EPersonaStateOffline;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetPersonaState();
}

S_API int SteamAPI_ISteamFriends_GetFriendCount(intptr_t instancePtr, int iFriendFlags)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendCount(iFriendFlags);
}

S_API uint64 SteamAPI_ISteamFriends_GetFriendByIndex(intptr_t instancePtr, int iFriend, int iFriendFlags)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendByIndex(iFriend, iFriendFlags).ConvertToUint64();
}

S_API EFriendRelationship SteamAPI_ISteamFriends_GetFriendRelationship(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendRelationship called");
    if (!instancePtr) return k_EFriendRelationshipNone;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendRelationship(steamIDFriend);
}

S_API EPersonaState SteamAPI_ISteamFriends_GetFriendPersonaState(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendPersonaState called");
    if (!instancePtr) return k_EPersonaStateOffline;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendPersonaState(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendPersonaName(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendPersonaName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendPersonaName(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_GetFriendGamePlayed(intptr_t instancePtr, class CSteamID steamIDFriend, struct FriendGameInfo_t * pFriendGameInfo)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendGamePlayed called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendGamePlayed(steamIDFriend, pFriendGameInfo);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(intptr_t instancePtr, class CSteamID steamIDFriend, int iPersonaName)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendPersonaNameHistory called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
}

S_API int SteamAPI_ISteamFriends_GetFriendSteamLevel(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendSteamLevel called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendSteamLevel(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetPlayerNickname(intptr_t instancePtr, class CSteamID steamIDPlayer)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetPlayerNickname called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetPlayerNickname(steamIDPlayer);
}

S_API int SteamAPI_ISteamFriends_GetFriendsGroupCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendsGroupCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendsGroupCount();
}

S_API FriendsGroupID_t SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex(intptr_t instancePtr, int iFG)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendsGroupIDByIndex(iFG);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendsGroupName(intptr_t instancePtr, FriendsGroupID_t friendsGroupID)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendsGroupName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendsGroupName(friendsGroupID);
}

S_API int SteamAPI_ISteamFriends_GetFriendsGroupMembersCount(intptr_t instancePtr, FriendsGroupID_t friendsGroupID)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendsGroupMembersCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendsGroupMembersCount(friendsGroupID);
}

S_API void SteamAPI_ISteamFriends_GetFriendsGroupMembersList(intptr_t instancePtr, FriendsGroupID_t friendsGroupID, class CSteamID * pOutSteamIDMembers, int nMembersCount)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendsGroupMembersList called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}

S_API bool SteamAPI_ISteamFriends_HasFriend(intptr_t instancePtr, class CSteamID steamIDFriend, int iFriendFlags)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_HasFriend called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->HasFriend(steamIDFriend, iFriendFlags);
}

S_API int SteamAPI_ISteamFriends_GetClanCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanCount();
}

S_API uint64 SteamAPI_ISteamFriends_GetClanByIndex(intptr_t instancePtr, int iClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanByIndex(iClan).ConvertToUint64();
}

S_API const char * SteamAPI_ISteamFriends_GetClanName(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanName(steamIDClan);
}

S_API const char * SteamAPI_ISteamFriends_GetClanTag(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanTag called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanTag(steamIDClan);
}

S_API bool SteamAPI_ISteamFriends_GetClanActivityCounts(intptr_t instancePtr, class CSteamID steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanActivityCounts called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanActivityCounts(steamIDClan, pnOnline, pnInGame, pnChatting);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_DownloadClanActivityCounts(intptr_t instancePtr, class CSteamID * psteamIDClans, int cClansToRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_DownloadClanActivityCounts called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
}

S_API int SteamAPI_ISteamFriends_GetFriendCountFromSource(intptr_t instancePtr, class CSteamID steamIDSource)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendCountFromSource called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendCountFromSource(steamIDSource);
}

S_API uint64 SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(intptr_t instancePtr, class CSteamID steamIDSource, int iFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendFromSourceByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendFromSourceByIndex(steamIDSource, iFriend).ConvertToUint64();
}

S_API bool SteamAPI_ISteamFriends_IsUserInSource(intptr_t instancePtr, class CSteamID steamIDUser, class CSteamID steamIDSource)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_IsUserInSource called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->IsUserInSource(steamIDUser, steamIDSource);
}

S_API void SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(intptr_t instancePtr, class CSteamID steamIDUser, bool bSpeaking)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SetInGameVoiceSpeaking called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlay(intptr_t instancePtr, const char * pchDialog)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ActivateGameOverlay called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ActivateGameOverlay(pchDialog);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToUser(intptr_t instancePtr, const char * pchDialog, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ActivateGameOverlayToUser called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ActivateGameOverlayToUser(pchDialog, steamID);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage(intptr_t instancePtr, const char * pchURL)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ActivateGameOverlayToWebPage(pchURL);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayToStore(intptr_t instancePtr, AppId_t nAppID, EOverlayToStoreFlag eFlag)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ActivateGameOverlayToStore called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ActivateGameOverlayToStore(nAppID, eFlag);
}

S_API void SteamAPI_ISteamFriends_SetPlayedWith(intptr_t instancePtr, class CSteamID steamIDUserPlayedWith)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SetPlayedWith called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->SetPlayedWith(steamIDUserPlayedWith);
}

S_API void SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ActivateGameOverlayInviteDialog(steamIDLobby);
}

S_API int SteamAPI_ISteamFriends_GetSmallFriendAvatar(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetSmallFriendAvatar called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetSmallFriendAvatar(steamIDFriend);
}

S_API int SteamAPI_ISteamFriends_GetMediumFriendAvatar(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetMediumFriendAvatar called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetMediumFriendAvatar(steamIDFriend);
}

S_API int SteamAPI_ISteamFriends_GetLargeFriendAvatar(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetLargeFriendAvatar called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetLargeFriendAvatar(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_RequestUserInformation(intptr_t instancePtr, class CSteamID steamIDUser, bool bRequireNameOnly)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_RequestUserInformation called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->RequestUserInformation(steamIDUser, bRequireNameOnly);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_RequestClanOfficerList(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_RequestClanOfficerList called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->RequestClanOfficerList(steamIDClan);
}

S_API uint64 SteamAPI_ISteamFriends_GetClanOwner(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanOwner called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanOwner(steamIDClan).ConvertToUint64();
}

S_API int SteamAPI_ISteamFriends_GetClanOfficerCount(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanOfficerCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanOfficerCount(steamIDClan);
}

S_API uint64 SteamAPI_ISteamFriends_GetClanOfficerByIndex(intptr_t instancePtr, class CSteamID steamIDClan, int iOfficer)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanOfficerByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanOfficerByIndex(steamIDClan, iOfficer).ConvertToUint64();
}

S_API uint32 SteamAPI_ISteamFriends_GetUserRestrictions(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetUserRestrictions called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetUserRestrictions();
}

S_API bool SteamAPI_ISteamFriends_SetRichPresence(intptr_t instancePtr, const char * pchKey, const char * pchValue)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SetRichPresence called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->SetRichPresence(pchKey, pchValue);
}

S_API void SteamAPI_ISteamFriends_ClearRichPresence(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ClearRichPresence called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->ClearRichPresence();
}

S_API const char * SteamAPI_ISteamFriends_GetFriendRichPresence(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendRichPresence called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendRichPresence(steamIDFriend, pchKey);
}

S_API int SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendRichPresenceKeyCount(steamIDFriend);
}

S_API const char * SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(intptr_t instancePtr, class CSteamID steamIDFriend, int iKey)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
}

S_API void SteamAPI_ISteamFriends_RequestFriendRichPresence(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_RequestFriendRichPresence called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamFriends*>(instancePtr)->RequestFriendRichPresence(steamIDFriend);
}

S_API bool SteamAPI_ISteamFriends_InviteUserToGame(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchConnectString)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_InviteUserToGame called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->InviteUserToGame(steamIDFriend, pchConnectString);
}

S_API int SteamAPI_ISteamFriends_GetCoplayFriendCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetCoplayFriendCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetCoplayFriendCount();
}

S_API uint64 SteamAPI_ISteamFriends_GetCoplayFriend(intptr_t instancePtr, int iCoplayFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetCoplayFriend called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetCoplayFriend(iCoplayFriend).ConvertToUint64();
}

S_API int SteamAPI_ISteamFriends_GetFriendCoplayTime(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendCoplayTime called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendCoplayTime(steamIDFriend);
}

S_API AppId_t SteamAPI_ISteamFriends_GetFriendCoplayGame(intptr_t instancePtr, class CSteamID steamIDFriend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendCoplayGame called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendCoplayGame(steamIDFriend);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_JoinClanChatRoom(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_JoinClanChatRoom called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->JoinClanChatRoom(steamIDClan);
}

S_API bool SteamAPI_ISteamFriends_LeaveClanChatRoom(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_LeaveClanChatRoom called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->LeaveClanChatRoom(steamIDClan);
}

S_API int SteamAPI_ISteamFriends_GetClanChatMemberCount(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanChatMemberCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanChatMemberCount(steamIDClan);
}

S_API uint64 SteamAPI_ISteamFriends_GetChatMemberByIndex(intptr_t instancePtr, class CSteamID steamIDClan, int iUser)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetChatMemberByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetChatMemberByIndex(steamIDClan, iUser).ConvertToUint64();
}

S_API bool SteamAPI_ISteamFriends_SendClanChatMessage(intptr_t instancePtr, class CSteamID steamIDClanChat, const char * pchText)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SendClanChatMessage called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->SendClanChatMessage(steamIDClanChat, pchText);
}

S_API int SteamAPI_ISteamFriends_GetClanChatMessage(intptr_t instancePtr, class CSteamID steamIDClanChat, int iMessage, void * prgchText, int cchTextMax, EChatEntryType * peChatEntryType, class CSteamID * psteamidChatter)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetClanChatMessage called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetClanChatMessage(steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}

S_API bool SteamAPI_ISteamFriends_IsClanChatAdmin(intptr_t instancePtr, class CSteamID steamIDClanChat, class CSteamID steamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_IsClanChatAdmin called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->IsClanChatAdmin(steamIDClanChat, steamIDUser);
}

S_API bool SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->IsClanChatWindowOpenInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_OpenClanChatWindowInSteam called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->OpenClanChatWindowInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_CloseClanChatWindowInSteam called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->CloseClanChatWindowInSteam(steamIDClanChat);
}

S_API bool SteamAPI_ISteamFriends_SetListenForFriendsMessages(intptr_t instancePtr, bool bInterceptEnabled)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_SetListenForFriendsMessages called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->SetListenForFriendsMessages(bInterceptEnabled);
}

S_API bool SteamAPI_ISteamFriends_ReplyToFriendMessage(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchMsgToSend)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_ReplyToFriendMessage called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
}

S_API int SteamAPI_ISteamFriends_GetFriendMessage(intptr_t instancePtr, class CSteamID steamIDFriend, int iMessageID, void * pvData, int cubData, EChatEntryType * peChatEntryType)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFriendMessage called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFriendMessage(steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_GetFollowerCount(intptr_t instancePtr, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_GetFollowerCount called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->GetFollowerCount(steamID);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_IsFollowing(intptr_t instancePtr, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_IsFollowing called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->IsFollowing(steamID);
}

S_API SteamAPICall_t SteamAPI_ISteamFriends_EnumerateFollowingList(intptr_t instancePtr, uint32 unStartIndex)
{
    VLOG_DEBUG("SteamAPI_ISteamFriends_EnumerateFollowingList called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamFriends*>(instancePtr)->EnumerateFollowingList(unStartIndex);
}


//-----------------------------------------------------------------------------
// ISteamUtils flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceAppActive(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetSecondsSinceAppActive called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetSecondsSinceAppActive();
}

S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetSecondsSinceComputerActive called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetSecondsSinceComputerActive();
}

S_API EUniverse SteamAPI_ISteamUtils_GetConnectedUniverse(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetConnectedUniverse called");
    if (!instancePtr) return k_EUniverseInvalid;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetConnectedUniverse();
}

S_API uint32 SteamAPI_ISteamUtils_GetServerRealTime(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetServerRealTime called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetServerRealTime();
}

S_API const char * SteamAPI_ISteamUtils_GetIPCountry(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetIPCountry called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetIPCountry();
}

S_API bool SteamAPI_ISteamUtils_GetImageSize(intptr_t instancePtr, int iImage, uint32 * pnWidth, uint32 * pnHeight)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetImageSize called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetImageSize(iImage, pnWidth, pnHeight);
}

S_API bool SteamAPI_ISteamUtils_GetImageRGBA(intptr_t instancePtr, int iImage, uint8 * pubDest, int nDestBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetImageRGBA called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetImageRGBA(iImage, pubDest, nDestBufferSize);
}

S_API bool SteamAPI_ISteamUtils_GetCSERIPPort(intptr_t instancePtr, uint32 * unIP, uint16 * usPort)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetCSERIPPort called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetCSERIPPort(unIP, usPort);
}

S_API uint8 SteamAPI_ISteamUtils_GetCurrentBatteryPower(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetCurrentBatteryPower called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetCurrentBatteryPower();
}

S_API uint32 SteamAPI_ISteamUtils_GetAppID(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetAppID called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetAppID();
}

S_API void SteamAPI_ISteamUtils_SetOverlayNotificationPosition(intptr_t instancePtr, ENotificationPosition eNotificationPosition)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_SetOverlayNotificationPosition called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUtils*>(instancePtr)->SetOverlayNotificationPosition(eNotificationPosition);
}

S_API bool SteamAPI_ISteamUtils_IsAPICallCompleted(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, bool * pbFailed)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_IsAPICallCompleted called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->IsAPICallCompleted(hSteamAPICall, pbFailed);
}

S_API ESteamAPICallFailure SteamAPI_ISteamUtils_GetAPICallFailureReason(intptr_t instancePtr, SteamAPICall_t hSteamAPICall)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetAPICallFailureReason called");
    if (!instancePtr) return k_ESteamAPICallFailureNone;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetAPICallFailureReason(hSteamAPICall);
}

S_API bool SteamAPI_ISteamUtils_GetAPICallResult(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, void * pCallback, int cubCallback, int iCallbackExpected, bool * pbFailed)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetAPICallResult called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetAPICallResult(hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
}

S_API void SteamAPI_ISteamUtils_RunFrame(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_RunFrame called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUtils*>(instancePtr)->RunFrame();
}

S_API uint32 SteamAPI_ISteamUtils_GetIPCCallCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetIPCCallCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetIPCCallCount();
}

S_API void SteamAPI_ISteamUtils_SetWarningMessageHook(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_SetWarningMessageHook called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamUtils*>(instancePtr)->SetWarningMessageHook(pFunction);
}

S_API bool SteamAPI_ISteamUtils_IsOverlayEnabled(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_IsOverlayEnabled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->IsOverlayEnabled();
}

S_API bool SteamAPI_ISteamUtils_BOverlayNeedsPresent(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_BOverlayNeedsPresent called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->BOverlayNeedsPresent();
}

S_API SteamAPICall_t SteamAPI_ISteamUtils_CheckFileSignature(intptr_t instancePtr, const char * szFileName)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_CheckFileSignature called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->CheckFileSignature(szFileName);
}

S_API bool SteamAPI_ISteamUtils_ShowGamepadTextInput(intptr_t instancePtr, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_ShowGamepadTextInput called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
}

S_API uint32 SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetEnteredGamepadTextLength called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetEnteredGamepadTextLength();
}

S_API bool SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(intptr_t instancePtr, char * pchText, uint32 cchText)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetEnteredGamepadTextInput called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetEnteredGamepadTextInput(pchText, cchText);
}

S_API const char * SteamAPI_ISteamUtils_GetSteamUILanguage(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_GetSteamUILanguage called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->GetSteamUILanguage();
}

S_API bool SteamAPI_ISteamUtils_IsSteamRunningInVR(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUtils_IsSteamRunningInVR called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUtils*>(instancePtr)->IsSteamRunningInVR();
}


//-----------------------------------------------------------------------------
// ISteamMatchmaking flat API implementations
//-----------------------------------------------------------------------------

S_API int SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetFavoriteGameCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetFavoriteGameCount();
}

S_API bool SteamAPI_ISteamMatchmaking_GetFavoriteGame(intptr_t instancePtr, int iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetFavoriteGame called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
}

S_API int SteamAPI_ISteamMatchmaking_AddFavoriteGame(intptr_t instancePtr, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddFavoriteGame called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
}

S_API bool SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(intptr_t instancePtr, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_RemoveFavoriteGame called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_RequestLobbyList(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_RequestLobbyList called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->RequestLobbyList();
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter(intptr_t instancePtr, const char * pchKeyToMatch, const char * pchValueToMatch, ELobbyComparison eComparisonType)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(intptr_t instancePtr, const char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(intptr_t instancePtr, const char * pchKeyToMatch, int nValueToBeCloseTo)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(intptr_t instancePtr, int nSlotsAvailable)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(intptr_t instancePtr, ELobbyDistanceFilter eLobbyDistanceFilter)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(intptr_t instancePtr, int cMaxResults)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListResultCountFilter(cMaxResults);
}

S_API void SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
}

S_API uint64 SteamAPI_ISteamMatchmaking_GetLobbyByIndex(intptr_t instancePtr, int iLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyByIndex(iLobby).ConvertToUint64();
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_CreateLobby(intptr_t instancePtr, ELobbyType eLobbyType, int cMaxMembers)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_CreateLobby called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->CreateLobby(eLobbyType, cMaxMembers);
}

S_API SteamAPICall_t SteamAPI_ISteamMatchmaking_JoinLobby(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_JoinLobby called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->JoinLobby(steamIDLobby);
}

S_API void SteamAPI_ISteamMatchmaking_LeaveLobby(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_LeaveLobby called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->LeaveLobby(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_InviteUserToLobby(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDInvitee)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_InviteUserToLobby called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->InviteUserToLobby(steamIDLobby, steamIDInvitee);
}

S_API int SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetNumLobbyMembers called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetNumLobbyMembers(steamIDLobby);
}

S_API uint64 SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(intptr_t instancePtr, class CSteamID steamIDLobby, int iMember)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyMemberByIndex(steamIDLobby, iMember).ConvertToUint64();
}

S_API const char * SteamAPI_ISteamMatchmaking_GetLobbyData(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyData called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyData(steamIDLobby, pchKey);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyData(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey, const char * pchValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyData(steamIDLobby, pchKey, pchValue);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyDataCount(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyDataCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyDataCount(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex(intptr_t instancePtr, class CSteamID steamIDLobby, int iLobbyData, char * pchKey, int cchKeyBufferSize, char * pchValue, int cchValueBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
}

S_API bool SteamAPI_ISteamMatchmaking_DeleteLobbyData(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_DeleteLobbyData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->DeleteLobbyData(steamIDLobby, pchKey);
}

S_API const char * SteamAPI_ISteamMatchmaking_GetLobbyMemberData(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDUser, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyMemberData called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
}

S_API void SteamAPI_ISteamMatchmaking_SetLobbyMemberData(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey, const char * pchValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyMemberData called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
}

S_API bool SteamAPI_ISteamMatchmaking_SendLobbyChatMsg(intptr_t instancePtr, class CSteamID steamIDLobby, const void * pvMsgBody, int cubMsgBody)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SendLobbyChatMsg called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyChatEntry(intptr_t instancePtr, class CSteamID steamIDLobby, int iChatID, class CSteamID * pSteamIDUser, void * pvData, int cubData, EChatEntryType * peChatEntryType)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyChatEntry called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
}

S_API bool SteamAPI_ISteamMatchmaking_RequestLobbyData(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_RequestLobbyData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->RequestLobbyData(steamIDLobby);
}

S_API void SteamAPI_ISteamMatchmaking_SetLobbyGameServer(intptr_t instancePtr, class CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, class CSteamID steamIDGameServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyGameServer called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
}

S_API bool SteamAPI_ISteamMatchmaking_GetLobbyGameServer(intptr_t instancePtr, class CSteamID steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, class CSteamID * psteamIDGameServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyGameServer called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(intptr_t instancePtr, class CSteamID steamIDLobby, int cMaxMembers)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
}

S_API int SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyMemberLimit(steamIDLobby);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyType(intptr_t instancePtr, class CSteamID steamIDLobby, ELobbyType eLobbyType)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyType called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyType(steamIDLobby, eLobbyType);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyJoinable(intptr_t instancePtr, class CSteamID steamIDLobby, bool bLobbyJoinable)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyJoinable called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
}

S_API uint64 SteamAPI_ISteamMatchmaking_GetLobbyOwner(intptr_t instancePtr, class CSteamID steamIDLobby)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_GetLobbyOwner called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->GetLobbyOwner(steamIDLobby).ConvertToUint64();
}

S_API bool SteamAPI_ISteamMatchmaking_SetLobbyOwner(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDNewOwner)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLobbyOwner called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
}

S_API bool SteamAPI_ISteamMatchmaking_SetLinkedLobby(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDLobbyDependent)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmaking_SetLinkedLobby called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmaking*>(instancePtr)->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent);
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingServerListResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServerListResponse*>(instancePtr)->ServerResponded(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServerListResponse*>(instancePtr)->ServerFailedToRespond(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete(intptr_t instancePtr, HServerListRequest hRequest, EMatchMakingServerResponse response)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServerListResponse*>(instancePtr)->RefreshComplete(hRequest, response);
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingPingResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingPingResponse_ServerResponded(intptr_t instancePtr, class gameserveritem_t & server)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingPingResponse_ServerResponded called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingPingResponse*>(instancePtr)->ServerResponded(server);
}

S_API void SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingPingResponse*>(instancePtr)->ServerFailedToRespond();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingPlayersResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList(intptr_t instancePtr, const char * pchName, int nScore, float flTimePlayed)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingPlayersResponse*>(instancePtr)->AddPlayerToList(pchName, nScore, flTimePlayed);
}

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingPlayersResponse*>(instancePtr)->PlayersFailedToRespond();
}

S_API void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingPlayersResponse*>(instancePtr)->PlayersRefreshComplete();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingRulesResponse flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded(intptr_t instancePtr, const char * pchRule, const char * pchValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingRulesResponse*>(instancePtr)->RulesResponded(pchRule, pchValue);
}

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingRulesResponse*>(instancePtr)->RulesFailedToRespond();
}

S_API void SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingRulesResponse*>(instancePtr)->RulesRefreshComplete();
}


//-----------------------------------------------------------------------------
// ISteamMatchmakingServers flat API implementations
//-----------------------------------------------------------------------------

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestInternetServerList(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestInternetServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestLANServerList(intptr_t instancePtr, AppId_t iApp, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestLANServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestLANServerList(iApp, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

S_API void SteamAPI_ISteamMatchmakingServers_ReleaseRequest(intptr_t instancePtr, HServerListRequest hServerListRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_ReleaseRequest called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->ReleaseRequest(hServerListRequest);
}

S_API class gameserveritem_t * SteamAPI_ISteamMatchmakingServers_GetServerDetails(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_GetServerDetails called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->GetServerDetails(hRequest, iServer);
}

S_API void SteamAPI_ISteamMatchmakingServers_CancelQuery(intptr_t instancePtr, HServerListRequest hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_CancelQuery called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->CancelQuery(hRequest);
}

S_API void SteamAPI_ISteamMatchmakingServers_RefreshQuery(intptr_t instancePtr, HServerListRequest hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RefreshQuery called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RefreshQuery(hRequest);
}

S_API bool SteamAPI_ISteamMatchmakingServers_IsRefreshing(intptr_t instancePtr, HServerListRequest hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_IsRefreshing called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->IsRefreshing(hRequest);
}

S_API int SteamAPI_ISteamMatchmakingServers_GetServerCount(intptr_t instancePtr, HServerListRequest hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_GetServerCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->GetServerCount(hRequest);
}

S_API void SteamAPI_ISteamMatchmakingServers_RefreshServer(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_RefreshServer called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->RefreshServer(hRequest, iServer);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_PingServer(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingPingResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_PingServer called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->PingServer(unIP, usPort, pRequestServersResponse);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_PlayerDetails(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingPlayersResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_PlayerDetails called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->PlayerDetails(unIP, usPort, pRequestServersResponse);
}

S_API HServerQuery SteamAPI_ISteamMatchmakingServers_ServerRules(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingRulesResponse * pRequestServersResponse)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_ServerRules called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->ServerRules(unIP, usPort, pRequestServersResponse);
}

S_API void SteamAPI_ISteamMatchmakingServers_CancelServerQuery(intptr_t instancePtr, HServerQuery hServerQuery)
{
    VLOG_DEBUG("SteamAPI_ISteamMatchmakingServers_CancelServerQuery called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMatchmakingServers*>(instancePtr)->CancelServerQuery(hServerQuery);
}


//-----------------------------------------------------------------------------
// ISteamRemoteStorage flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamRemoteStorage_FileWrite(intptr_t instancePtr, const char * pchFile, const void * pvData, int32 cubData)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileWrite called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileWrite(pchFile, pvData, cubData);
}

S_API int32 SteamAPI_ISteamRemoteStorage_FileRead(intptr_t instancePtr, const char * pchFile, void * pvData, int32 cubDataToRead)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileRead called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileRead(pchFile, pvData, cubDataToRead);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileForget(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileForget called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileForget(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileDelete(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileDelete called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileDelete(pchFile);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_FileShare(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileShare called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileShare(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_SetSyncPlatforms(intptr_t instancePtr, const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_SetSyncPlatforms called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
}

S_API UGCFileWriteStreamHandle_t SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen called");
    if (!instancePtr) return k_UGCFileStreamHandleInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileWriteStreamOpen(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle, const void * pvData, int32 cubData)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileWriteStreamClose called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileWriteStreamClose(writeHandle);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileWriteStreamCancel(writeHandle);
}

S_API bool SteamAPI_ISteamRemoteStorage_FileExists(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FileExists called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FileExists(pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_FilePersisted(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_FilePersisted called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->FilePersisted(pchFile);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetFileSize(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetFileSize called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetFileSize(pchFile);
}

S_API int64 SteamAPI_ISteamRemoteStorage_GetFileTimestamp(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetFileTimestamp called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetFileTimestamp(pchFile);
}

S_API ERemoteStoragePlatform SteamAPI_ISteamRemoteStorage_GetSyncPlatforms(intptr_t instancePtr, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetSyncPlatforms called");
    if (!instancePtr) return k_ERemoteStoragePlatformNone;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetSyncPlatforms(pchFile);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetFileCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetFileCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetFileCount();
}

S_API const char * SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(intptr_t instancePtr, int iFile, int32 * pnFileSizeInBytes)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetFileNameAndSize called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetFileNameAndSize(iFile, pnFileSizeInBytes);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetQuota(intptr_t instancePtr, int32 * pnTotalBytes, int32 * puAvailableBytes)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetQuota called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetQuota(pnTotalBytes, puAvailableBytes);
}

S_API bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->IsCloudEnabledForAccount();
}

S_API bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->IsCloudEnabledForApp();
}

S_API void SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(intptr_t instancePtr, bool bEnabled)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->SetCloudEnabledForApp(bEnabled);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownload(intptr_t instancePtr, UGCHandle_t hContent, uint32 unPriority)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UGCDownload called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UGCDownload(hContent, unPriority);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress(intptr_t instancePtr, UGCHandle_t hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetUGCDownloadProgress(hContent, pnBytesDownloaded, pnBytesExpected);
}

S_API bool SteamAPI_ISteamRemoteStorage_GetUGCDetails(intptr_t instancePtr, UGCHandle_t hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, class CSteamID * pSteamIDOwner)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetUGCDetails called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
}

S_API int32 SteamAPI_ISteamRemoteStorage_UGCRead(intptr_t instancePtr, UGCHandle_t hContent, void * pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UGCRead called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UGCRead(hContent, pvData, cubDataToRead, cOffset, eAction);
}

S_API int32 SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetCachedUGCCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetCachedUGCCount();
}

S_API UGCHandle_t SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(intptr_t instancePtr, int32 iCachedContent)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle called");
    if (!instancePtr) return k_UGCHandleInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetCachedUGCHandle(iCachedContent);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishWorkshopFile(intptr_t instancePtr, const char * pchFile, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, struct SteamParamStringArray_t * pTags, EWorkshopFileType eWorkshopFileType)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_PublishWorkshopFile called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
}

S_API PublishedFileUpdateHandle_t SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest called");
    if (!instancePtr) return k_PublishedFileUpdateHandleInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->CreatePublishedFileUpdateRequest(unPublishedFileId);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileFile(updateHandle, pchFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchTitle)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileTitle(updateHandle, pchTitle);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchDescription)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileDescription(updateHandle, pchDescription);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileVisibility(updateHandle, eVisibility);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, struct SteamParamStringArray_t * pTags)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileTags(updateHandle, pTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->CommitPublishedFileUpdate(updateHandle);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_DeletePublishedFile(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_DeletePublishedFile called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->DeletePublishedFile(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(intptr_t instancePtr, uint32 unStartIndex)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->EnumerateUserPublishedFiles(unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_SubscribePublishedFile called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->SubscribePublishedFile(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(intptr_t instancePtr, uint32 unStartIndex)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->EnumerateUserSubscribedFiles(unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UnsubscribePublishedFile(unPublishedFileId);
}

S_API bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetPublishedItemVoteDetails(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, bool bVoteUp)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->GetUserPublishedItemVoteDetails(unPublishedFileId);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles(intptr_t instancePtr, class CSteamID steamId, uint32 unStartIndex, struct SteamParamStringArray_t * pRequiredTags, struct SteamParamStringArray_t * pExcludedTags)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, pRequiredTags, pExcludedTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishVideo(intptr_t instancePtr, EWorkshopVideoProvider eVideoProvider, const char * pchVideoAccount, const char * pchVideoIdentifier, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, struct SteamParamStringArray_t * pTags)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_PublishVideo called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->SetUserPublishedFileAction(unPublishedFileId, eAction);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(intptr_t instancePtr, EWorkshopFileAction eAction, uint32 unStartIndex)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles(intptr_t instancePtr, EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, struct SteamParamStringArray_t * pTags, struct SteamParamStringArray_t * pUserTags)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
}

S_API SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(intptr_t instancePtr, UGCHandle_t hContent, const char * pchLocation, uint32 unPriority)
{
    VLOG_DEBUG("SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamRemoteStorage*>(instancePtr)->UGCDownloadToLocation(hContent, pchLocation, unPriority);
}


//-----------------------------------------------------------------------------
// ISteamUserStats flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamUserStats_RequestCurrentStats(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_RequestCurrentStats called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->RequestCurrentStats();
}

S_API bool SteamAPI_ISteamUserStats_GetStat(intptr_t instancePtr, const char * pchName, int32 * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetStat0(intptr_t instancePtr, const char * pchName, float * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetStat(pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_SetStat(intptr_t instancePtr, const char * pchName, int32 nData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_SetStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->SetStat(pchName, nData);
}

S_API bool SteamAPI_ISteamUserStats_SetStat0(intptr_t instancePtr, const char * pchName, float fData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_SetStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->SetStat(pchName, fData);
}

S_API bool SteamAPI_ISteamUserStats_UpdateAvgRateStat(intptr_t instancePtr, const char * pchName, float flCountThisSession, double dSessionLength)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_UpdateAvgRateStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievement(intptr_t instancePtr, const char * pchName, bool * pbAchieved)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievement(pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_SetAchievement(intptr_t instancePtr, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_SetAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->SetAchievement(pchName);
}

S_API bool SteamAPI_ISteamUserStats_ClearAchievement(intptr_t instancePtr, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_ClearAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->ClearAchievement(pchName);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime(intptr_t instancePtr, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievementAndUnlockTime(pchName, pbAchieved, punUnlockTime);
}

S_API bool SteamAPI_ISteamUserStats_StoreStats(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_StoreStats called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->StoreStats();
}

S_API int SteamAPI_ISteamUserStats_GetAchievementIcon(intptr_t instancePtr, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievementIcon called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievementIcon(pchName);
}

S_API const char * SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(intptr_t instancePtr, const char * pchName, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievementDisplayAttribute(pchName, pchKey);
}

S_API bool SteamAPI_ISteamUserStats_IndicateAchievementProgress(intptr_t instancePtr, const char * pchName, uint32 nCurProgress, uint32 nMaxProgress)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_IndicateAchievementProgress called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
}

S_API uint32 SteamAPI_ISteamUserStats_GetNumAchievements(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetNumAchievements called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetNumAchievements();
}

S_API const char * SteamAPI_ISteamUserStats_GetAchievementName(intptr_t instancePtr, uint32 iAchievement)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievementName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievementName(iAchievement);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestUserStats(intptr_t instancePtr, class CSteamID steamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_RequestUserStats called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->RequestUserStats(steamIDUser);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetUserStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetUserStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetUserAchievement(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetUserAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserAchievement(steamIDUser, pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetUserAchievementAndUnlockTime(steamIDUser, pchName, pbAchieved, punUnlockTime);
}

S_API bool SteamAPI_ISteamUserStats_ResetAllStats(intptr_t instancePtr, bool bAchievementsToo)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_ResetAllStats called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->ResetAllStats(bAchievementsToo);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(intptr_t instancePtr, const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_FindOrCreateLeaderboard called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_FindLeaderboard(intptr_t instancePtr, const char * pchLeaderboardName)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_FindLeaderboard called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->FindLeaderboard(pchLeaderboardName);
}

S_API const char * SteamAPI_ISteamUserStats_GetLeaderboardName(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetLeaderboardName called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetLeaderboardName(hSteamLeaderboard);
}

S_API int SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetLeaderboardEntryCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetLeaderboardEntryCount(hSteamLeaderboard);
}

S_API ELeaderboardSortMethod SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetLeaderboardSortMethod called");
    if (!instancePtr) return k_ELeaderboardSortMethodNone;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetLeaderboardSortMethod(hSteamLeaderboard);
}

S_API ELeaderboardDisplayType SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetLeaderboardDisplayType called");
    if (!instancePtr) return k_ELeaderboardDisplayTypeNone;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetLeaderboardDisplayType(hSteamLeaderboard);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_DownloadLeaderboardEntries called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, class CSteamID * prgUsers, int cUsers)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers);
}

S_API bool SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry(intptr_t instancePtr, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, struct LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int cDetailsMax)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_UploadLeaderboardScore(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 * pScoreDetails, int cScoreDetailsCount)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_UploadLeaderboardScore called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_AttachLeaderboardUGC(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_AttachLeaderboardUGC called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetNumberOfCurrentPlayers();
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->RequestGlobalAchievementPercentages();
}

S_API int SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo(intptr_t instancePtr, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetMostAchievedAchievementInfo(pchName, unNameBufLen, pflPercent, pbAchieved);
}

S_API int SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo(intptr_t instancePtr, int iIteratorPrevious, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
}

S_API bool SteamAPI_ISteamUserStats_GetAchievementAchievedPercent(intptr_t instancePtr, const char * pchName, float * pflPercent)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetAchievementAchievedPercent called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetAchievementAchievedPercent(pchName, pflPercent);
}

S_API SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalStats(intptr_t instancePtr, int nHistoryDays)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_RequestGlobalStats called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->RequestGlobalStats(nHistoryDays);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStat(intptr_t instancePtr, const char * pchStatName, int64 * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetGlobalStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStat(pchStatName, pData);
}

S_API bool SteamAPI_ISteamUserStats_GetGlobalStat0(intptr_t instancePtr, const char * pchStatName, double * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetGlobalStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStat(pchStatName, pData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory(intptr_t instancePtr, const char * pchStatName, int64 * pData, uint32 cubData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetGlobalStatHistory called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStatHistory(pchStatName, pData, cubData);
}

S_API int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory0(intptr_t instancePtr, const char * pchStatName, double * pData, uint32 cubData)
{
    VLOG_DEBUG("SteamAPI_ISteamUserStats_GetGlobalStatHistory0 called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUserStats*>(instancePtr)->GetGlobalStatHistory(pchStatName, pData, cubData);
}


//-----------------------------------------------------------------------------
// ISteamApps flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamApps_BIsSubscribed(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsSubscribed called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsSubscribed();
}

S_API bool SteamAPI_ISteamApps_BIsLowViolence(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsLowViolence called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsLowViolence();
}

S_API bool SteamAPI_ISteamApps_BIsCybercafe(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsCybercafe called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsCybercafe();
}

S_API bool SteamAPI_ISteamApps_BIsVACBanned(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsVACBanned called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsVACBanned();
}

S_API const char * SteamAPI_ISteamApps_GetCurrentGameLanguage(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetCurrentGameLanguage called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetCurrentGameLanguage();
}

S_API const char * SteamAPI_ISteamApps_GetAvailableGameLanguages(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetAvailableGameLanguages called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetAvailableGameLanguages();
}

S_API bool SteamAPI_ISteamApps_BIsSubscribedApp(intptr_t instancePtr, AppId_t appID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsSubscribedApp called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsSubscribedApp(appID);
}

S_API bool SteamAPI_ISteamApps_BIsDlcInstalled(intptr_t instancePtr, AppId_t appID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsDlcInstalled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsDlcInstalled(appID);
}

S_API uint32 SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(intptr_t instancePtr, AppId_t nAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetEarliestPurchaseUnixTime(nAppID);
}

S_API bool SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsSubscribedFromFreeWeekend();
}

S_API int SteamAPI_ISteamApps_GetDLCCount(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetDLCCount called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetDLCCount();
}

S_API bool SteamAPI_ISteamApps_BGetDLCDataByIndex(intptr_t instancePtr, int iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int cchNameBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BGetDLCDataByIndex called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BGetDLCDataByIndex(iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
}

S_API void SteamAPI_ISteamApps_InstallDLC(intptr_t instancePtr, AppId_t nAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_InstallDLC called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamApps*>(instancePtr)->InstallDLC(nAppID);
}

S_API void SteamAPI_ISteamApps_UninstallDLC(intptr_t instancePtr, AppId_t nAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_UninstallDLC called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamApps*>(instancePtr)->UninstallDLC(nAppID);
}

S_API void SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(intptr_t instancePtr, AppId_t nAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamApps*>(instancePtr)->RequestAppProofOfPurchaseKey(nAppID);
}

S_API bool SteamAPI_ISteamApps_GetCurrentBetaName(intptr_t instancePtr, char * pchName, int cchNameBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetCurrentBetaName called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetCurrentBetaName(pchName, cchNameBufferSize);
}

S_API bool SteamAPI_ISteamApps_MarkContentCorrupt(intptr_t instancePtr, bool bMissingFilesOnly)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_MarkContentCorrupt called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->MarkContentCorrupt(bMissingFilesOnly);
}

S_API uint32 SteamAPI_ISteamApps_GetInstalledDepots(intptr_t instancePtr, AppId_t appID, DepotId_t * pvecDepots, uint32 cMaxDepots)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetInstalledDepots called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetInstalledDepots(appID, pvecDepots, cMaxDepots);
}

S_API uint32 SteamAPI_ISteamApps_GetAppInstallDir(intptr_t instancePtr, AppId_t appID, char * pchFolder, uint32 cchFolderBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetAppInstallDir called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
}

S_API bool SteamAPI_ISteamApps_BIsAppInstalled(intptr_t instancePtr, AppId_t appID)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_BIsAppInstalled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->BIsAppInstalled(appID);
}

S_API uint64 SteamAPI_ISteamApps_GetAppOwner(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetAppOwner called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetAppOwner().ConvertToUint64();
}

S_API const char * SteamAPI_ISteamApps_GetLaunchQueryParam(intptr_t instancePtr, const char * pchKey)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetLaunchQueryParam called");
    if (!instancePtr) return nullptr;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetLaunchQueryParam(pchKey);
}

S_API bool SteamAPI_ISteamApps_GetDlcDownloadProgress(intptr_t instancePtr, AppId_t nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetDlcDownloadProgress called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
}

S_API int SteamAPI_ISteamApps_GetAppBuildId(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamApps_GetAppBuildId called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamApps*>(instancePtr)->GetAppBuildId();
}


//-----------------------------------------------------------------------------
// ISteamNetworking flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamNetworking_SendP2PPacket(intptr_t instancePtr, class CSteamID steamIDRemote, const void * pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_SendP2PPacket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_IsP2PPacketAvailable(intptr_t instancePtr, uint32 * pcubMsgSize, int nChannel)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_IsP2PPacketAvailable called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->IsP2PPacketAvailable(pcubMsgSize, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_ReadP2PPacket(intptr_t instancePtr, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, class CSteamID * psteamIDRemote, int nChannel)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_ReadP2PPacket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->ReadP2PPacket(pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(intptr_t instancePtr, class CSteamID steamIDRemote)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->AcceptP2PSessionWithUser(steamIDRemote);
}

S_API bool SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(intptr_t instancePtr, class CSteamID steamIDRemote)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_CloseP2PSessionWithUser called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->CloseP2PSessionWithUser(steamIDRemote);
}

S_API bool SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(intptr_t instancePtr, class CSteamID steamIDRemote, int nChannel)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_CloseP2PChannelWithUser called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->CloseP2PChannelWithUser(steamIDRemote, nChannel);
}

S_API bool SteamAPI_ISteamNetworking_GetP2PSessionState(intptr_t instancePtr, class CSteamID steamIDRemote, struct P2PSessionState_t * pConnectionState)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_GetP2PSessionState called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->GetP2PSessionState(steamIDRemote, pConnectionState);
}

S_API bool SteamAPI_ISteamNetworking_AllowP2PPacketRelay(intptr_t instancePtr, bool bAllow)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_AllowP2PPacketRelay called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->AllowP2PPacketRelay(bAllow);
}

S_API SNetListenSocket_t SteamAPI_ISteamNetworking_CreateListenSocket(intptr_t instancePtr, int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_CreateListenSocket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
}

S_API SNetSocket_t SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(intptr_t instancePtr, class CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_CreateP2PConnectionSocket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
}

S_API SNetSocket_t SteamAPI_ISteamNetworking_CreateConnectionSocket(intptr_t instancePtr, uint32 nIP, uint16 nPort, int nTimeoutSec)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_CreateConnectionSocket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->CreateConnectionSocket(nIP, nPort, nTimeoutSec);
}

S_API bool SteamAPI_ISteamNetworking_DestroySocket(intptr_t instancePtr, SNetSocket_t hSocket, bool bNotifyRemoteEnd)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_DestroySocket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->DestroySocket(hSocket, bNotifyRemoteEnd);
}

S_API bool SteamAPI_ISteamNetworking_DestroyListenSocket(intptr_t instancePtr, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_DestroyListenSocket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->DestroyListenSocket(hSocket, bNotifyRemoteEnd);
}

S_API bool SteamAPI_ISteamNetworking_SendDataOnSocket(intptr_t instancePtr, SNetSocket_t hSocket, void * pubData, uint32 cubData, bool bReliable)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_SendDataOnSocket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->SendDataOnSocket(hSocket, pubData, cubData, bReliable);
}

S_API bool SteamAPI_ISteamNetworking_IsDataAvailableOnSocket(intptr_t instancePtr, SNetSocket_t hSocket, uint32 * pcubMsgSize)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_IsDataAvailableOnSocket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->IsDataAvailableOnSocket(hSocket, pcubMsgSize);
}

S_API bool SteamAPI_ISteamNetworking_RetrieveDataFromSocket(intptr_t instancePtr, SNetSocket_t hSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_RetrieveDataFromSocket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->RetrieveDataFromSocket(hSocket, pubDest, cubDest, pcubMsgSize);
}

S_API bool SteamAPI_ISteamNetworking_IsDataAvailable(intptr_t instancePtr, SNetListenSocket_t hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_IsDataAvailable called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->IsDataAvailable(hListenSocket, pcubMsgSize, phSocket);
}

S_API bool SteamAPI_ISteamNetworking_RetrieveData(intptr_t instancePtr, SNetListenSocket_t hListenSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_RetrieveData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->RetrieveData(hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
}

S_API bool SteamAPI_ISteamNetworking_GetSocketInfo(intptr_t instancePtr, SNetSocket_t hSocket, class CSteamID * pSteamIDRemote, int * peSocketStatus, uint32 * punIPRemote, uint16 * punPortRemote)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_GetSocketInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->GetSocketInfo(hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
}

S_API bool SteamAPI_ISteamNetworking_GetListenSocketInfo(intptr_t instancePtr, SNetListenSocket_t hListenSocket, uint32 * pnIP, uint16 * pnPort)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_GetListenSocketInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->GetListenSocketInfo(hListenSocket, pnIP, pnPort);
}

S_API ESNetSocketConnectionType SteamAPI_ISteamNetworking_GetSocketConnectionType(intptr_t instancePtr, SNetSocket_t hSocket)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_GetSocketConnectionType called");
    if (!instancePtr) return k_ESNetSocketConnectionTypeNotConnected;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->GetSocketConnectionType(hSocket);
}

S_API int SteamAPI_ISteamNetworking_GetMaxPacketSize(intptr_t instancePtr, SNetSocket_t hSocket)
{
    VLOG_DEBUG("SteamAPI_ISteamNetworking_GetMaxPacketSize called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamNetworking*>(instancePtr)->GetMaxPacketSize(hSocket);
}


//-----------------------------------------------------------------------------
// ISteamScreenshots flat API implementations
//-----------------------------------------------------------------------------

S_API ScreenshotHandle SteamAPI_ISteamScreenshots_WriteScreenshot(intptr_t instancePtr, void * pubRGB, uint32 cubRGB, int nWidth, int nHeight)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_WriteScreenshot called");
    if (!instancePtr) return INVALID_SCREENSHOT_HANDLE;
    return reinterpret_cast<ISteamScreenshots*>(instancePtr)->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
}

S_API ScreenshotHandle SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(intptr_t instancePtr, const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_AddScreenshotToLibrary called");
    if (!instancePtr) return INVALID_SCREENSHOT_HANDLE;
    return reinterpret_cast<ISteamScreenshots*>(instancePtr)->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
}

S_API void SteamAPI_ISteamScreenshots_TriggerScreenshot(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_TriggerScreenshot called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamScreenshots*>(instancePtr)->TriggerScreenshot();
}

S_API void SteamAPI_ISteamScreenshots_HookScreenshots(intptr_t instancePtr, bool bHook)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_HookScreenshots called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamScreenshots*>(instancePtr)->HookScreenshots(bHook);
}

S_API bool SteamAPI_ISteamScreenshots_SetLocation(intptr_t instancePtr, ScreenshotHandle hScreenshot, const char * pchLocation)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_SetLocation called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamScreenshots*>(instancePtr)->SetLocation(hScreenshot, pchLocation);
}

S_API bool SteamAPI_ISteamScreenshots_TagUser(intptr_t instancePtr, ScreenshotHandle hScreenshot, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_TagUser called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamScreenshots*>(instancePtr)->TagUser(hScreenshot, steamID);
}

S_API bool SteamAPI_ISteamScreenshots_TagPublishedFile(intptr_t instancePtr, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID)
{
    VLOG_DEBUG("SteamAPI_ISteamScreenshots_TagPublishedFile called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamScreenshots*>(instancePtr)->TagPublishedFile(hScreenshot, unPublishedFileID);
}


//-----------------------------------------------------------------------------
// ISteamMusic flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamMusic_BIsEnabled(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_BIsEnabled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusic*>(instancePtr)->BIsEnabled();
}

S_API bool SteamAPI_ISteamMusic_BIsPlaying(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_BIsPlaying called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusic*>(instancePtr)->BIsPlaying();
}

S_API AudioPlayback_Status SteamAPI_ISteamMusic_GetPlaybackStatus(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_GetPlaybackStatus called");
    if (!instancePtr) return AudioPlayback_Idle;
    return reinterpret_cast<ISteamMusic*>(instancePtr)->GetPlaybackStatus();
}

S_API void SteamAPI_ISteamMusic_Play(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_Play called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMusic*>(instancePtr)->Play();
}

S_API void SteamAPI_ISteamMusic_Pause(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_Pause called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMusic*>(instancePtr)->Pause();
}

S_API void SteamAPI_ISteamMusic_PlayPrevious(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_PlayPrevious called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMusic*>(instancePtr)->PlayPrevious();
}

S_API void SteamAPI_ISteamMusic_PlayNext(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_PlayNext called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMusic*>(instancePtr)->PlayNext();
}

S_API void SteamAPI_ISteamMusic_SetVolume(intptr_t instancePtr, float flVolume)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_SetVolume called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamMusic*>(instancePtr)->SetVolume(flVolume);
}

S_API float SteamAPI_ISteamMusic_GetVolume(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusic_GetVolume called");
    if (!instancePtr) return 0.0f;
    return reinterpret_cast<ISteamMusic*>(instancePtr)->GetVolume();
}


//-----------------------------------------------------------------------------
// ISteamMusicRemote flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote(intptr_t instancePtr, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->RegisterSteamMusicRemote(pchName);
}

S_API bool SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->DeregisterSteamMusicRemote();
}

S_API bool SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->BIsCurrentMusicRemote();
}

S_API bool SteamAPI_ISteamMusicRemote_BActivationSuccess(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_BActivationSuccess called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->BActivationSuccess(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_SetDisplayName(intptr_t instancePtr, const char * pchDisplayName)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetDisplayName called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetDisplayName(pchDisplayName);
}

S_API bool SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64(intptr_t instancePtr, void * pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetPNGIcon_64x64(pvBuffer, cbBufferLength);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlayPrevious(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnablePlayPrevious called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnablePlayPrevious(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlayNext(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnablePlayNext called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnablePlayNext(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableShuffled(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnableShuffled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnableShuffled(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableLooped(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnableLooped called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnableLooped(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnableQueue(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnableQueue called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnableQueue(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_EnablePlaylists(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_EnablePlaylists called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->EnablePlaylists(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus(intptr_t instancePtr, AudioPlayback_Status nStatus)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdatePlaybackStatus(nStatus);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateShuffled(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateShuffled called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateShuffled(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateLooped(intptr_t instancePtr, bool bValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateLooped called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateLooped(bValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateVolume(intptr_t instancePtr, float flValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateVolume called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateVolume(flValue);
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryWillChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_CurrentEntryWillChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->CurrentEntryWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable(intptr_t instancePtr, bool bAvailable)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->CurrentEntryIsAvailable(bAvailable);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText(intptr_t instancePtr, const char * pchText)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateCurrentEntryText(pchText);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds(intptr_t instancePtr, int nValue)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateCurrentEntryElapsedSeconds(nValue);
}

S_API bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt(intptr_t instancePtr, void * pvBuffer, uint32 cbBufferLength)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->UpdateCurrentEntryCoverArt(pvBuffer, cbBufferLength);
}

S_API bool SteamAPI_ISteamMusicRemote_CurrentEntryDidChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_CurrentEntryDidChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->CurrentEntryDidChange();
}

S_API bool SteamAPI_ISteamMusicRemote_QueueWillChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_QueueWillChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->QueueWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_ResetQueueEntries(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_ResetQueueEntries called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->ResetQueueEntries();
}

S_API bool SteamAPI_ISteamMusicRemote_SetQueueEntry(intptr_t instancePtr, int nID, int nPosition, const char * pchEntryText)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetQueueEntry called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetQueueEntry(nID, nPosition, pchEntryText);
}

S_API bool SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry(intptr_t instancePtr, int nID)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetCurrentQueueEntry(nID);
}

S_API bool SteamAPI_ISteamMusicRemote_QueueDidChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_QueueDidChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->QueueDidChange();
}

S_API bool SteamAPI_ISteamMusicRemote_PlaylistWillChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_PlaylistWillChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->PlaylistWillChange();
}

S_API bool SteamAPI_ISteamMusicRemote_ResetPlaylistEntries(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_ResetPlaylistEntries called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->ResetPlaylistEntries();
}

S_API bool SteamAPI_ISteamMusicRemote_SetPlaylistEntry(intptr_t instancePtr, int nID, int nPosition, const char * pchEntryText)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetPlaylistEntry called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetPlaylistEntry(nID, nPosition, pchEntryText);
}

S_API bool SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry(intptr_t instancePtr, int nID)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->SetCurrentPlaylistEntry(nID);
}

S_API bool SteamAPI_ISteamMusicRemote_PlaylistDidChange(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamMusicRemote_PlaylistDidChange called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamMusicRemote*>(instancePtr)->PlaylistDidChange();
}


//-----------------------------------------------------------------------------
// ISteamHTTP flat API implementations
//-----------------------------------------------------------------------------

S_API HTTPRequestHandle SteamAPI_ISteamHTTP_CreateHTTPRequest(intptr_t instancePtr, EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_CreateHTTPRequest called");
    if (!instancePtr) return INVALID_HTTPREQUEST_HANDLE;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(intptr_t instancePtr, HTTPRequestHandle hRequest, uint64 ulContextValue)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestContextValue called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestContextValue(hRequest, ulContextValue);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 unTimeoutSeconds)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
}

S_API bool SteamAPI_ISteamHTTP_SendHTTPRequest(intptr_t instancePtr, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SendHTTPRequest called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SendHTTPRequest(hRequest, pCallHandle);
}

S_API bool SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse(intptr_t instancePtr, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SendHTTPRequestAndStreamResponse(hRequest, pCallHandle);
}

S_API bool SteamAPI_ISteamHTTP_DeferHTTPRequest(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_DeferHTTPRequest called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->DeferHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_PrioritizeHTTPRequest called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->PrioritizeHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, uint32 * unResponseHeaderSize)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, unResponseHeaderSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32 unBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseBodySize(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 * unBodySize)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPResponseBodySize called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPResponseBodySize(hRequest, unBodySize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPResponseBodyData(intptr_t instancePtr, HTTPRequestHandle hRequest, uint8 * pBodyDataBuffer, uint32 unBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPResponseBodyData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPResponseBodyData(hRequest, pBodyDataBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 cOffset, uint8 * pBodyDataBuffer, uint32 unBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPStreamingResponseBodyData(hRequest, cOffset, pBodyDataBuffer, unBufferSize);
}

S_API bool SteamAPI_ISteamHTTP_ReleaseHTTPRequest(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_ReleaseHTTPRequest called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->ReleaseHTTPRequest(hRequest);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct(intptr_t instancePtr, HTTPRequestHandle hRequest, float * pflPercentOut)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPDownloadProgressPct(hRequest, pflPercentOut);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchContentType, uint8 * pubBody, uint32 unBodyLen)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen);
}

S_API HTTPCookieContainerHandle SteamAPI_ISteamHTTP_CreateCookieContainer(intptr_t instancePtr, bool bAllowResponsesToModify)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_CreateCookieContainer called");
    if (!instancePtr) return INVALID_HTTPCOOKIE_HANDLE;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->CreateCookieContainer(bAllowResponsesToModify);
}

S_API bool SteamAPI_ISteamHTTP_ReleaseCookieContainer(intptr_t instancePtr, HTTPCookieContainerHandle hCookieContainer)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_ReleaseCookieContainer called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->ReleaseCookieContainer(hCookieContainer);
}

S_API bool SteamAPI_ISteamHTTP_SetCookie(intptr_t instancePtr, HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetCookie called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(intptr_t instancePtr, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchUserAgentInfo)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(intptr_t instancePtr, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
}

S_API bool SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 unMilliseconds)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
}

S_API bool SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut(intptr_t instancePtr, HTTPRequestHandle hRequest, bool * pbWasTimedOut)
{
    VLOG_DEBUG("SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTTP*>(instancePtr)->GetHTTPRequestWasTimedOut(hRequest, pbWasTimedOut);
}


//-----------------------------------------------------------------------------
// ISteamUnifiedMessages flat API implementations
//-----------------------------------------------------------------------------

S_API ClientUnifiedMessageHandle SteamAPI_ISteamUnifiedMessages_SendMethod(intptr_t instancePtr, const char * pchServiceMethod, const void * pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext)
{
    VLOG_DEBUG("SteamAPI_ISteamUnifiedMessages_SendMethod called");
    if (!instancePtr) return ISteamUnifiedMessages::k_InvalidUnifiedMessageHandle;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->SendMethod(pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
}

S_API bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, uint32 * punResponseSize, EResult * peResult)
{
    VLOG_DEBUG("SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->GetMethodResponseInfo(hHandle, punResponseSize, peResult);
}

S_API bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseData(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, void * pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease)
{
    VLOG_DEBUG("SteamAPI_ISteamUnifiedMessages_GetMethodResponseData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->GetMethodResponseData(hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
}

S_API bool SteamAPI_ISteamUnifiedMessages_ReleaseMethod(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamUnifiedMessages_ReleaseMethod called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->ReleaseMethod(hHandle);
}

S_API bool SteamAPI_ISteamUnifiedMessages_SendNotification(intptr_t instancePtr, const char * pchServiceNotification, const void * pNotificationBuffer, uint32 unNotificationBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamUnifiedMessages_SendNotification called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUnifiedMessages*>(instancePtr)->SendNotification(pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
}


//-----------------------------------------------------------------------------
// ISteamController flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamController_Init(intptr_t instancePtr, const char * pchAbsolutePathToControllerConfigVDF)
{
    VLOG_DEBUG("SteamAPI_ISteamController_Init called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController*>(instancePtr)->Init(pchAbsolutePathToControllerConfigVDF);
}

S_API bool SteamAPI_ISteamController_Shutdown(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamController_Shutdown called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController*>(instancePtr)->Shutdown();
}

S_API void SteamAPI_ISteamController_RunFrame(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamController_RunFrame called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamController*>(instancePtr)->RunFrame();
}

S_API bool SteamAPI_ISteamController_GetControllerState(intptr_t instancePtr, uint32 unControllerIndex, struct SteamControllerState_t * pState)
{
    VLOG_DEBUG("SteamAPI_ISteamController_GetControllerState called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamController*>(instancePtr)->GetControllerState(unControllerIndex, pState);
}

S_API void SteamAPI_ISteamController_TriggerHapticPulse(intptr_t instancePtr, uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
    VLOG_DEBUG("SteamAPI_ISteamController_TriggerHapticPulse called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamController*>(instancePtr)->TriggerHapticPulse(unControllerIndex, eTargetPad, usDurationMicroSec);
}

S_API void SteamAPI_ISteamController_SetOverrideMode(intptr_t instancePtr, const char * pchMode)
{
    VLOG_DEBUG("SteamAPI_ISteamController_SetOverrideMode called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamController*>(instancePtr)->SetOverrideMode(pchMode);
}


//-----------------------------------------------------------------------------
// ISteamUGC flat API implementations
//-----------------------------------------------------------------------------

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(intptr_t instancePtr, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_CreateQueryUserUGCRequest called");
    if (!instancePtr) return k_UGCQueryHandleInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
}

S_API UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequest(intptr_t instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_CreateQueryAllUGCRequest called");
    if (!instancePtr) return k_UGCQueryHandleInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SendQueryUGCRequest(intptr_t instancePtr, UGCQueryHandle_t handle)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SendQueryUGCRequest called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SendQueryUGCRequest(handle);
}

S_API bool SteamAPI_ISteamUGC_GetQueryUGCResult(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, struct SteamUGCDetails_t * pDetails)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetQueryUGCResult called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetQueryUGCResult(handle, index, pDetails);
}

S_API bool SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(intptr_t instancePtr, UGCQueryHandle_t handle)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_ReleaseQueryUGCRequest called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->ReleaseQueryUGCRequest(handle);
}

S_API bool SteamAPI_ISteamUGC_AddRequiredTag(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pTagName)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_AddRequiredTag called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->AddRequiredTag(handle, pTagName);
}

S_API bool SteamAPI_ISteamUGC_AddExcludedTag(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pTagName)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_AddExcludedTag called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->AddExcludedTag(handle, pTagName);
}

S_API bool SteamAPI_ISteamUGC_SetReturnLongDescription(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnLongDescription)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetReturnLongDescription called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetReturnLongDescription(handle, bReturnLongDescription);
}

S_API bool SteamAPI_ISteamUGC_SetReturnTotalOnly(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnTotalOnly)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetReturnTotalOnly called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetReturnTotalOnly(handle, bReturnTotalOnly);
}

S_API bool SteamAPI_ISteamUGC_SetAllowCachedResponse(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 unMaxAgeSeconds)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetAllowCachedResponse called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetAllowCachedResponse(handle, unMaxAgeSeconds);
}

S_API bool SteamAPI_ISteamUGC_SetCloudFileNameFilter(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pMatchCloudFileName)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetCloudFileNameFilter called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetCloudFileNameFilter(handle, pMatchCloudFileName);
}

S_API bool SteamAPI_ISteamUGC_SetMatchAnyTag(intptr_t instancePtr, UGCQueryHandle_t handle, bool bMatchAnyTag)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetMatchAnyTag called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetMatchAnyTag(handle, bMatchAnyTag);
}

S_API bool SteamAPI_ISteamUGC_SetSearchText(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pSearchText)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetSearchText called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetSearchText(handle, pSearchText);
}

S_API bool SteamAPI_ISteamUGC_SetRankedByTrendDays(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 unDays)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetRankedByTrendDays called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetRankedByTrendDays(handle, unDays);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_RequestUGCDetails(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_RequestUGCDetails called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_CreateItem(intptr_t instancePtr, AppId_t nConsumerAppId, EWorkshopFileType eFileType)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_CreateItem called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->CreateItem(nConsumerAppId, eFileType);
}

S_API UGCUpdateHandle_t SteamAPI_ISteamUGC_StartItemUpdate(intptr_t instancePtr, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_StartItemUpdate called");
    if (!instancePtr) return k_UGCUpdateHandleInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->StartItemUpdate(nConsumerAppId, nPublishedFileID);
}

S_API bool SteamAPI_ISteamUGC_SetItemTitle(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchTitle)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemTitle called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemTitle(handle, pchTitle);
}

S_API bool SteamAPI_ISteamUGC_SetItemDescription(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchDescription)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemDescription called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemDescription(handle, pchDescription);
}

S_API bool SteamAPI_ISteamUGC_SetItemVisibility(intptr_t instancePtr, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemVisibility called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemVisibility(handle, eVisibility);
}

S_API bool SteamAPI_ISteamUGC_SetItemTags(intptr_t instancePtr, UGCUpdateHandle_t updateHandle, const struct SteamParamStringArray_t * pTags)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemTags called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemTags(updateHandle, pTags);
}

S_API bool SteamAPI_ISteamUGC_SetItemContent(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pszContentFolder)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemContent called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemContent(handle, pszContentFolder);
}

S_API bool SteamAPI_ISteamUGC_SetItemPreview(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pszPreviewFile)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SetItemPreview called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SetItemPreview(handle, pszPreviewFile);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SubmitItemUpdate(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchChangeNote)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SubmitItemUpdate called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SubmitItemUpdate(handle, pchChangeNote);
}

S_API EItemUpdateStatus SteamAPI_ISteamUGC_GetItemUpdateProgress(intptr_t instancePtr, UGCUpdateHandle_t handle, uint64 * punBytesProcessed, uint64 * punBytesTotal)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetItemUpdateProgress called");
    if (!instancePtr) return k_EItemUpdateStatusInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetItemUpdateProgress(handle, punBytesProcessed, punBytesTotal);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_SubscribeItem(intptr_t instancePtr, PublishedFileId_t nPublishedFileID)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_SubscribeItem called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->SubscribeItem(nPublishedFileID);
}

S_API SteamAPICall_t SteamAPI_ISteamUGC_UnsubscribeItem(intptr_t instancePtr, PublishedFileId_t nPublishedFileID)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_UnsubscribeItem called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->UnsubscribeItem(nPublishedFileID);
}

S_API uint32 SteamAPI_ISteamUGC_GetNumSubscribedItems(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetNumSubscribedItems called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetNumSubscribedItems();
}

S_API uint32 SteamAPI_ISteamUGC_GetSubscribedItems(intptr_t instancePtr, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetSubscribedItems called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetSubscribedItems(pvecPublishedFileID, cMaxEntries);
}

S_API bool SteamAPI_ISteamUGC_GetItemInstallInfo(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32 cchFolderSize, bool * pbLegacyItem)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetItemInstallInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetItemInstallInfo(nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, pbLegacyItem);
}

S_API bool SteamAPI_ISteamUGC_GetItemUpdateInfo(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, bool * pbNeedsUpdate, bool * pbIsDownloading, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
    VLOG_DEBUG("SteamAPI_ISteamUGC_GetItemUpdateInfo called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamUGC*>(instancePtr)->GetItemUpdateInfo(nPublishedFileID, pbNeedsUpdate, pbIsDownloading, punBytesDownloaded, punBytesTotal);
}


//-----------------------------------------------------------------------------
// ISteamAppList flat API implementations
//-----------------------------------------------------------------------------

S_API uint32 SteamAPI_ISteamAppList_GetNumInstalledApps(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamAppList_GetNumInstalledApps called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamAppList*>(instancePtr)->GetNumInstalledApps();
}

S_API uint32 SteamAPI_ISteamAppList_GetInstalledApps(intptr_t instancePtr, AppId_t * pvecAppID, uint32 unMaxAppIDs)
{
    VLOG_DEBUG("SteamAPI_ISteamAppList_GetInstalledApps called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamAppList*>(instancePtr)->GetInstalledApps(pvecAppID, unMaxAppIDs);
}

S_API int SteamAPI_ISteamAppList_GetAppName(intptr_t instancePtr, AppId_t nAppID, char * pchName, int cchNameMax)
{
    VLOG_DEBUG("SteamAPI_ISteamAppList_GetAppName called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamAppList*>(instancePtr)->GetAppName(nAppID, pchName, cchNameMax);
}

S_API int SteamAPI_ISteamAppList_GetAppInstallDir(intptr_t instancePtr, AppId_t nAppID, char * pchDirectory, int cchNameMax)
{
    VLOG_DEBUG("SteamAPI_ISteamAppList_GetAppInstallDir called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamAppList*>(instancePtr)->GetAppInstallDir(nAppID, pchDirectory, cchNameMax);
}

S_API int SteamAPI_ISteamAppList_GetAppBuildId(intptr_t instancePtr, AppId_t nAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamAppList_GetAppBuildId called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamAppList*>(instancePtr)->GetAppBuildId(nAppID);
}


//-----------------------------------------------------------------------------
// ISteamHTMLSurface flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface called");
    if (!instancePtr) return;
    // reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->DestructISteamHTMLSurface();
}

S_API bool SteamAPI_ISteamHTMLSurface_Init(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_Init called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->Init();
}

S_API bool SteamAPI_ISteamHTMLSurface_Shutdown(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_Shutdown called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->Shutdown();
}

S_API SteamAPICall_t SteamAPI_ISteamHTMLSurface_CreateBrowser(intptr_t instancePtr, const char * pchUserAgent, const char * pchUserCSS)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_CreateBrowser called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->CreateBrowser(pchUserAgent, pchUserCSS);
}

S_API void SteamAPI_ISteamHTMLSurface_RemoveBrowser(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_RemoveBrowser called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->RemoveBrowser(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_LoadURL(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_LoadURL called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->LoadURL(unBrowserHandle, pchURL, pchPostData);
}

S_API void SteamAPI_ISteamHTMLSurface_SetSize(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetSize called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetSize(unBrowserHandle, unWidth, unHeight);
}

S_API void SteamAPI_ISteamHTMLSurface_StopLoad(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_StopLoad called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->StopLoad(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_Reload(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_Reload called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->Reload(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GoBack(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_GoBack called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->GoBack(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GoForward(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_GoForward called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->GoForward(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_AddHeader(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_AddHeader called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->AddHeader(unBrowserHandle, pchKey, pchValue);
}

S_API void SteamAPI_ISteamHTMLSurface_ExecuteJavascript(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchScript)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_ExecuteJavascript called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->ExecuteJavascript(unBrowserHandle, pchScript);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseUp(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_MouseUp called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->MouseUp(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseDown(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_MouseDown called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->MouseDown(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseDoubleClick(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_MouseDoubleClick called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->MouseDoubleClick(unBrowserHandle, eMouseButton);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseMove(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_MouseMove called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->MouseMove(unBrowserHandle, x, y);
}

S_API void SteamAPI_ISteamHTMLSurface_MouseWheel(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int32 nDelta)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_MouseWheel called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->MouseWheel(unBrowserHandle, nDelta);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyDown(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_KeyDown called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyUp(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_KeyUp called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

S_API void SteamAPI_ISteamHTMLSurface_KeyChar(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_KeyChar called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

S_API void SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetHorizontalScroll called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

S_API void SteamAPI_ISteamHTMLSurface_SetVerticalScroll(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetVerticalScroll called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

S_API void SteamAPI_ISteamHTMLSurface_SetKeyFocus(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetKeyFocus called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
}

S_API void SteamAPI_ISteamHTMLSurface_ViewSource(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_ViewSource called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->ViewSource(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_CopyToClipboard(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_CopyToClipboard called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->CopyToClipboard(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_PasteFromClipboard(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_PasteFromClipboard called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->PasteFromClipboard(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_Find(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_Find called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}

S_API void SteamAPI_ISteamHTMLSurface_StopFind(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_StopFind called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->StopFind(unBrowserHandle);
}

S_API void SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_GetLinkAtPosition called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->GetLinkAtPosition(unBrowserHandle, x, y);
}

S_API void SteamAPI_ISteamHTMLSurface_SetCookie(intptr_t instancePtr, const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetCookie called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}

S_API void SteamAPI_ISteamHTMLSurface_SetPageScaleFactor(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_SetPageScaleFactor called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
}

S_API void SteamAPI_ISteamHTMLSurface_AllowStartRequest(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bAllowed)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_AllowStartRequest called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->AllowStartRequest(unBrowserHandle, bAllowed);
}

S_API void SteamAPI_ISteamHTMLSurface_JSDialogResponse(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bResult)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_JSDialogResponse called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->JSDialogResponse(unBrowserHandle, bResult);
}

S_API void SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char ** pchSelectedFiles)
{
    VLOG_DEBUG("SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamHTMLSurface*>(instancePtr)->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
}


//-----------------------------------------------------------------------------
// ISteamInventory flat API implementations
//-----------------------------------------------------------------------------

S_API EResult SteamAPI_ISteamInventory_GetResultStatus(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetResultStatus called");
    if (!instancePtr) return k_EResultFail;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetResultStatus(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetResultItems(intptr_t instancePtr, SteamInventoryResult_t resultHandle, struct SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetResultItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetResultItems(resultHandle, pOutItemsArray, punOutItemsArraySize);
}

S_API uint32 SteamAPI_ISteamInventory_GetResultTimestamp(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetResultTimestamp called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetResultTimestamp(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_CheckResultSteamID(intptr_t instancePtr, SteamInventoryResult_t resultHandle, class CSteamID steamIDExpected)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_CheckResultSteamID called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->CheckResultSteamID(resultHandle, steamIDExpected);
}

S_API void SteamAPI_ISteamInventory_DestroyResult(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_DestroyResult called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamInventory*>(instancePtr)->DestroyResult(resultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetAllItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetAllItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetAllItems(pResultHandle);
}

S_API bool SteamAPI_ISteamInventory_GetItemsByID(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemInstanceID_t * pInstanceIDs, uint32 unCountInstanceIDs)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetItemsByID called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetItemsByID(pResultHandle, pInstanceIDs, unCountInstanceIDs);
}

S_API bool SteamAPI_ISteamInventory_SerializeResult(intptr_t instancePtr, SteamInventoryResult_t resultHandle, void * pOutBuffer, uint32 * punOutBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_SerializeResult called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->SerializeResult(resultHandle, pOutBuffer, punOutBufferSize);
}

S_API bool SteamAPI_ISteamInventory_DeserializeResult(intptr_t instancePtr, SteamInventoryResult_t * pOutResultHandle, const void * pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_DeserializeResult called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->DeserializeResult(pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
}

S_API bool SteamAPI_ISteamInventory_GenerateItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GenerateItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GenerateItems(pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
}

S_API bool SteamAPI_ISteamInventory_GrantPromoItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GrantPromoItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GrantPromoItems(pResultHandle);
}

S_API bool SteamAPI_ISteamInventory_AddPromoItem(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t itemDef)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_AddPromoItem called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->AddPromoItem(pResultHandle, itemDef);
}

S_API bool SteamAPI_ISteamInventory_AddPromoItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, uint32 unArrayLength)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_AddPromoItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->AddPromoItems(pResultHandle, pArrayItemDefs, unArrayLength);
}

S_API bool SteamAPI_ISteamInventory_ConsumeItem(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_ConsumeItem called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->ConsumeItem(pResultHandle, itemConsume, unQuantity);
}

S_API bool SteamAPI_ISteamInventory_ExchangeItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayGenerate, const uint32 * punArrayGenerateQuantity, uint32 unArrayGenerateLength, const SteamItemInstanceID_t * pArrayDestroy, const uint32 * punArrayDestroyQuantity, uint32 unArrayDestroyLength)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_ExchangeItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->ExchangeItems(pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
}

S_API bool SteamAPI_ISteamInventory_TransferItemQuantity(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_TransferItemQuantity called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->TransferItemQuantity(pResultHandle, itemIdSource, unQuantity, itemIdDest);
}

S_API void SteamAPI_ISteamInventory_SendItemDropHeartbeat(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_SendItemDropHeartbeat called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamInventory*>(instancePtr)->SendItemDropHeartbeat();
}

S_API bool SteamAPI_ISteamInventory_TriggerItemDrop(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t dropListDefinition)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_TriggerItemDrop called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->TriggerItemDrop(pResultHandle, dropListDefinition);
}

S_API bool SteamAPI_ISteamInventory_TradeItems(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, class CSteamID steamIDTradePartner, const SteamItemInstanceID_t * pArrayGive, const uint32 * pArrayGiveQuantity, uint32 nArrayGiveLength, const SteamItemInstanceID_t * pArrayGet, const uint32 * pArrayGetQuantity, uint32 nArrayGetLength)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_TradeItems called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->TradeItems(pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
}

S_API bool SteamAPI_ISteamInventory_LoadItemDefinitions(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_LoadItemDefinitions called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->LoadItemDefinitions();
}

S_API bool SteamAPI_ISteamInventory_GetItemDefinitionIDs(intptr_t instancePtr, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetItemDefinitionIDs called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetItemDefinitionIDs(pItemDefIDs, punItemDefIDsArraySize);
}

S_API bool SteamAPI_ISteamInventory_GetItemDefinitionProperty(intptr_t instancePtr, SteamItemDef_t iDefinition, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSize)
{
    VLOG_DEBUG("SteamAPI_ISteamInventory_GetItemDefinitionProperty called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamInventory*>(instancePtr)->GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSize);
}


//-----------------------------------------------------------------------------
// ISteamVideo flat API implementations
//-----------------------------------------------------------------------------

S_API void SteamAPI_ISteamVideo_GetVideoURL(intptr_t instancePtr, AppId_t unVideoAppID)
{
    VLOG_DEBUG("SteamAPI_ISteamVideo_GetVideoURL called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamVideo*>(instancePtr)->GetVideoURL(unVideoAppID);
}


//-----------------------------------------------------------------------------
// ISteamGameServer flat API implementations
//-----------------------------------------------------------------------------

S_API bool SteamAPI_ISteamGameServer_InitGameServer(intptr_t instancePtr, uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char * pchVersionString)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_InitGameServer called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
}

S_API void SteamAPI_ISteamGameServer_SetProduct(intptr_t instancePtr, const char * pszProduct)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetProduct called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetProduct(pszProduct);
}

S_API void SteamAPI_ISteamGameServer_SetGameDescription(intptr_t instancePtr, const char * pszGameDescription)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetGameDescription called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetGameDescription(pszGameDescription);
}

S_API void SteamAPI_ISteamGameServer_SetModDir(intptr_t instancePtr, const char * pszModDir)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetModDir called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetModDir(pszModDir);
}

S_API void SteamAPI_ISteamGameServer_SetDedicatedServer(intptr_t instancePtr, bool bDedicated)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetDedicatedServer called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetDedicatedServer(bDedicated);
}

S_API void SteamAPI_ISteamGameServer_LogOn(intptr_t instancePtr, const char * pszToken)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_LogOn called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->LogOn(pszToken);
}

S_API void SteamAPI_ISteamGameServer_LogOnAnonymous(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_LogOnAnonymous called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->LogOnAnonymous();
}

S_API void SteamAPI_ISteamGameServer_LogOff(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_LogOff called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->LogOff();
}

S_API bool SteamAPI_ISteamGameServer_BLoggedOn(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_BLoggedOn called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->BLoggedOn();
}

S_API bool SteamAPI_ISteamGameServer_BSecure(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_BSecure called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->BSecure();
}

S_API uint64 SteamAPI_ISteamGameServer_GetSteamID(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetSteamID called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->GetSteamID().ConvertToUint64();
}

S_API bool SteamAPI_ISteamGameServer_WasRestartRequested(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_WasRestartRequested called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->WasRestartRequested();
}

S_API void SteamAPI_ISteamGameServer_SetMaxPlayerCount(intptr_t instancePtr, int cPlayersMax)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetMaxPlayerCount called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetMaxPlayerCount(cPlayersMax);
}

S_API void SteamAPI_ISteamGameServer_SetBotPlayerCount(intptr_t instancePtr, int cBotplayers)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetBotPlayerCount called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetBotPlayerCount(cBotplayers);
}

S_API void SteamAPI_ISteamGameServer_SetServerName(intptr_t instancePtr, const char * pszServerName)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetServerName called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetServerName(pszServerName);
}

S_API void SteamAPI_ISteamGameServer_SetMapName(intptr_t instancePtr, const char * pszMapName)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetMapName called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetMapName(pszMapName);
}

S_API void SteamAPI_ISteamGameServer_SetPasswordProtected(intptr_t instancePtr, bool bPasswordProtected)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetPasswordProtected called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetPasswordProtected(bPasswordProtected);
}

S_API void SteamAPI_ISteamGameServer_SetSpectatorPort(intptr_t instancePtr, uint16 unSpectatorPort)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetSpectatorPort called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetSpectatorPort(unSpectatorPort);
}

S_API void SteamAPI_ISteamGameServer_SetSpectatorServerName(intptr_t instancePtr, const char * pszSpectatorServerName)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetSpectatorServerName called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetSpectatorServerName(pszSpectatorServerName);
}

S_API void SteamAPI_ISteamGameServer_ClearAllKeyValues(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_ClearAllKeyValues called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->ClearAllKeyValues();
}

S_API void SteamAPI_ISteamGameServer_SetKeyValue(intptr_t instancePtr, const char * pKey, const char * pValue)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetKeyValue called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetKeyValue(pKey, pValue);
}

S_API void SteamAPI_ISteamGameServer_SetGameTags(intptr_t instancePtr, const char * pchGameTags)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetGameTags called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetGameTags(pchGameTags);
}

S_API void SteamAPI_ISteamGameServer_SetGameData(intptr_t instancePtr, const char * pchGameData)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetGameData called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetGameData(pchGameData);
}

S_API void SteamAPI_ISteamGameServer_SetRegion(intptr_t instancePtr, const char * pszRegion)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetRegion called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetRegion(pszRegion);
}

S_API bool SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate(intptr_t instancePtr, uint32 unIPClient, const void * pvAuthBlob, uint32 cubAuthBlobSize, class CSteamID * pSteamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
}

S_API uint64 SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->CreateUnauthenticatedUserConnection().ConvertToUint64();
}

S_API void SteamAPI_ISteamGameServer_SendUserDisconnect(intptr_t instancePtr, class CSteamID steamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SendUserDisconnect called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SendUserDisconnect(steamIDUser);
}

S_API bool SteamAPI_ISteamGameServer_BUpdateUserData(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchPlayerName, uint32 uScore)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_BUpdateUserData called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
}

S_API HAuthTicket SteamAPI_ISteamGameServer_GetAuthSessionTicket(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetAuthSessionTicket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

S_API EBeginAuthSessionResult SteamAPI_ISteamGameServer_BeginAuthSession(intptr_t instancePtr, const void * pAuthTicket, int cbAuthTicket, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_BeginAuthSession called");
    if (!instancePtr) return k_EBeginAuthSessionResultInvalidTicket;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
}

S_API void SteamAPI_ISteamGameServer_EndAuthSession(intptr_t instancePtr, class CSteamID steamID)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_EndAuthSession called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->EndAuthSession(steamID);
}

S_API void SteamAPI_ISteamGameServer_CancelAuthTicket(intptr_t instancePtr, HAuthTicket hAuthTicket)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_CancelAuthTicket called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->CancelAuthTicket(hAuthTicket);
}

S_API EUserHasLicenseForAppResult SteamAPI_ISteamGameServer_UserHasLicenseForApp(intptr_t instancePtr, class CSteamID steamID, AppId_t appID)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_UserHasLicenseForApp called");
    if (!instancePtr) return k_EUserHasLicenseResultHasLicense;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->UserHasLicenseForApp(steamID, appID);
}

S_API bool SteamAPI_ISteamGameServer_RequestUserGroupStatus(intptr_t instancePtr, class CSteamID steamIDUser, class CSteamID steamIDGroup)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_RequestUserGroupStatus called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->RequestUserGroupStatus(steamIDUser, steamIDGroup);
}

S_API void SteamAPI_ISteamGameServer_GetGameplayStats(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetGameplayStats called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->GetGameplayStats();
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_GetServerReputation(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetServerReputation called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->GetServerReputation();
}

S_API uint32 SteamAPI_ISteamGameServer_GetPublicIP(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetPublicIP called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->GetPublicIP();
}

S_API bool SteamAPI_ISteamGameServer_HandleIncomingPacket(intptr_t instancePtr, const void * pData, int cbData, uint32 srcIP, uint16 srcPort)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_HandleIncomingPacket called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
}

S_API int SteamAPI_ISteamGameServer_GetNextOutgoingPacket(intptr_t instancePtr, void * pOut, int cbMaxOut, uint32 * pNetAdr, uint16 * pPort)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_GetNextOutgoingPacket called");
    if (!instancePtr) return 0;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
}

S_API void SteamAPI_ISteamGameServer_EnableHeartbeats(intptr_t instancePtr, bool bActive)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_EnableHeartbeats called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->EnableHeartbeats(bActive);
}

S_API void SteamAPI_ISteamGameServer_SetHeartbeatInterval(intptr_t instancePtr, int iHeartbeatInterval)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_SetHeartbeatInterval called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->SetHeartbeatInterval(iHeartbeatInterval);
}

S_API void SteamAPI_ISteamGameServer_ForceHeartbeat(intptr_t instancePtr)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_ForceHeartbeat called");
    if (!instancePtr) return;
    reinterpret_cast<ISteamGameServer*>(instancePtr)->ForceHeartbeat();
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_AssociateWithClan(intptr_t instancePtr, class CSteamID steamIDClan)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_AssociateWithClan called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->AssociateWithClan(steamIDClan);
}

S_API SteamAPICall_t SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(intptr_t instancePtr, class CSteamID steamIDNewPlayer)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamGameServer*>(instancePtr)->ComputeNewPlayerCompatibility(steamIDNewPlayer);
}


//-----------------------------------------------------------------------------
// ISteamGameServerStats flat API implementations
//-----------------------------------------------------------------------------

S_API SteamAPICall_t SteamAPI_ISteamGameServerStats_RequestUserStats(intptr_t instancePtr, class CSteamID steamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_RequestUserStats called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->RequestUserStats(steamIDUser);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_GetUserStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_GetUserStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->GetUserStat(steamIDUser, pchName, pData);
}

S_API bool SteamAPI_ISteamGameServerStats_GetUserAchievement(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_GetUserAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->GetUserAchievement(steamIDUser, pchName, pbAchieved);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 nData)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_SetUserStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->SetUserStat(steamIDUser, pchName, nData);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserStat0(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float fData)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_SetUserStat0 called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->SetUserStat(steamIDUser, pchName, fData);
}

S_API bool SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float flCountThisSession, double dSessionLength)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
}

S_API bool SteamAPI_ISteamGameServerStats_SetUserAchievement(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_SetUserAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->SetUserAchievement(steamIDUser, pchName);
}

S_API bool SteamAPI_ISteamGameServerStats_ClearUserAchievement(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_ClearUserAchievement called");
    if (!instancePtr) return false;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->ClearUserAchievement(steamIDUser, pchName);
}

S_API SteamAPICall_t SteamAPI_ISteamGameServerStats_StoreUserStats(intptr_t instancePtr, class CSteamID steamIDUser)
{
    VLOG_DEBUG("SteamAPI_ISteamGameServerStats_StoreUserStats called");
    if (!instancePtr) return k_uAPICallInvalid;
    return reinterpret_cast<ISteamGameServerStats*>(instancePtr)->StoreUserStats(steamIDUser);
}
