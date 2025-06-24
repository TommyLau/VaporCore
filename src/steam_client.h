/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_CLIENT_H
#define VAPORCORE_STEAM_CLIENT_H
#ifdef _WIN32
#pragma once
#endif

#include <map>

#include <isteammasterserverupdater.h>
#include <isteamclient.h>
#include <isteamclient007.h>
#include <isteamclient008.h>
#include <isteamclient009.h>
#include <isteamclient010.h>
#include <isteamclient011.h>
#include <isteamclient012.h>
#include <isteamclient014.h>

// Steam pipe state enumeration
enum Steam_Pipe {
    STEAM_PIPE_NONE = 0,
    STEAM_PIPE_CLIENT = 1,
    STEAM_PIPE_SERVER = 2
};

//-----------------------------------------------------------------------------
// Purpose: Interface to creating a new steam instance, or to
//			connect to an existing steam instance, whether it's in a
//			different process or is local.
//
//			For most scenarios this is all handled automatically via SteamAPI_Init().
//			You'll only need to use these interfaces if you have a more complex versioning scheme,
//			where you want to get different versions of the same interface in different dll's in your project.
//-----------------------------------------------------------------------------
class Steam_Client :
	public ISteamClient,
    public ISteamClient007,
    public ISteamClient008,
    public ISteamClient009,
    public ISteamClient010,
    public ISteamClient011,
    public ISteamClient012,
    public ISteamClient014
{
private:
    // Internal state
    HSteamUser m_hSteamUser;
    uint32 m_unSteamPipeCounter;
    SteamAPIWarningMessageHook_t m_pWarningMessageHook;
    
    // Steam pipe management
    std::map<HSteamPipe, Steam_Pipe> m_mapSteamPipes;
    
    // Interface instances
    ISteamUser* m_pSteamUser;
    ISteamFriends* m_pSteamFriends;
    ISteamUtils* m_pSteamUtils;
    ISteamMatchmaking* m_pSteamMatchmaking;
    ISteamMatchmakingServers* m_pSteamMatchmakingServers;
    ISteamUserStats* m_pSteamUserStats;
    ISteamApps* m_pSteamApps;
    ISteamNetworking* m_pSteamNetworking;
    ISteamContentServer* m_pSteamContentServer;
    ISteamMasterServerUpdater* m_pSteamMasterServerUpdater;
    
    // Singleton instance
    static Steam_Client* s_pInstance;
    
    // Helper methods
    const char* GetInterfaceVersion(const char* pchVersion, const char* pchDefaultVersion);

public:
    Steam_Client();
    ~Steam_Client();

    // Helper methods
    static Steam_Client* GetInstance();
    static void ReleaseInstance();

	// Creates a communication pipe to the Steam client
	HSteamPipe CreateSteamPipe() override;

	// Releases a previously created communications pipe
	bool BReleaseSteamPipe( HSteamPipe hSteamPipe ) override;

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe ) override;

	// used by game servers, create a steam user that won't be shared with anyone else
	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType ) override;
	// Changed from Steam SDK v1.04, backward compatibility
	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe ) override;

	// removes an allocated user
	void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser ) override;

	// retrieves the ISteamUser interface associated with the handle
	ISteamUser *GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// retrieves the ISteamGameServer interface associated with the handle
	ISteamGameServer *GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// set the local IP and Port to bind to
	// this must be set before CreateLocalUser()
	void SetLocalIPBinding( uint32 unIP, uint16 usPort ) override; 

	// returns the ISteamFriends interface
	ISteamFriends *GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamUtils interface
	ISteamUtils *GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamMatchmaking interface
	ISteamMatchmaking *GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamContentServer interface
	// Removed from Steam SDK v1.04, backward compatibility
	ISteamContentServer *GetISteamContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamMasterServerUpdater interface
	// Removed from Steam SDK v1.17, backward compatibility
	ISteamMasterServerUpdater *GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamMatchmakingServers interface
	ISteamMatchmakingServers *GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the a generic interface
	void *GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamUserStats interface
	ISteamUserStats *GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns the ISteamGameServerStats interface
	ISteamGameServerStats *GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns apps interface
	ISteamApps *GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// networking
	ISteamNetworking *GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// remote storage
	ISteamRemoteStorage *GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// user screenshots
	ISteamScreenshots *GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// this needs to be called every frame to process matchmaking results
	// redundant if you're already calling SteamAPI_RunCallbacks()
	void RunFrame() override;

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	uint32 GetIPCCallCount() override;

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction ) override;

	// Trigger global shutdown for the DLL
	bool BShutdownIfAllPipesClosed() override;

#ifdef _PS3
	ISteamPS3OverlayRender *GetISteamPS3OverlayRender() override;
#endif

	// Expose HTTP interface
	ISteamHTTP *GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the ISteamUnifiedMessages interface
	ISteamUnifiedMessages *GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the ISteamController interface
	ISteamController *GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the ISteamUGC interface
	ISteamUGC *GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns app list interface, only available on specially registered apps
	ISteamAppList *GetISteamAppList( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;
	
	// Music Player
	ISteamMusic *GetISteamMusic( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Music Player Remote
	ISteamMusicRemote *GetISteamMusicRemote( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;
	ISteamHTMLSurface *GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion) override;
	void Set_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func) override;
	void Remove_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func) override;
	void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t func) override;
};

#endif // VAPORCORE_STEAM_CLIENT_H 
