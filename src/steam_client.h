/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: Steam Client implementation
 */

#ifndef VAPORCORE_STEAM_CLIENT_H
#define VAPORCORE_STEAM_CLIENT_H
#ifdef _WIN32
#pragma once
#endif

#include <map>

#include "../include/sdk/100/steam_api.h"

// Steam pipe state enumeration
enum Steam_Pipe {
    STEAM_PIPE_NONE = 0,
    STEAM_PIPE_CLIENT = 1,
    STEAM_PIPE_SERVER = 2
};

class Steam_Client : public ISteamClient
{
public:
    Steam_Client();
    ~Steam_Client();

	// Creates a communication pipe to the Steam client
	HSteamPipe CreateSteamPipe();

	// Releases a previously created communications pipe
	bool BReleaseSteamPipe( HSteamPipe hSteamPipe );

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe );

	// used by game servers, create a steam user that won't be shared with anyone else
	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe );

	// removes an allocated user
	void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser );

	// retrieves the ISteamUser interface associated with the handle
	ISteamUser *GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// retrieves the ISteamGameServer interface associated with the handle
	ISteamGameServer *GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// set the local IP and Port to bind to
	// this must be set before CreateLocalUser()
	void SetLocalIPBinding( uint32 unIP, uint16 usPort ); 

	// returns the ISteamFriends interface
	ISteamFriends *GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the ISteamUtils interface
	ISteamUtils *GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the ISteamMatchmaking interface
	ISteamMatchmaking *GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the ISteamContentServer interface
	ISteamContentServer *GetISteamContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the ISteamMasterServerUpdater interface
	ISteamMasterServerUpdater *GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the ISteamMatchmakingServers interface
	ISteamMatchmakingServers *GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the a generic interface
	void *GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// this needs to be called every frame to process matchmaking results
	// redundant if you're already calling SteamAPI_RunCallbacks()
	void RunFrame();

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	uint32 GetIPCCallCount();

	// returns the ISteamUserStats interface
	ISteamUserStats *GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns apps interface
	ISteamApps *GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// networking
	ISteamNetworking *GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction );

    // Helper methods
    static Steam_Client* GetInstance();
    static void ReleaseInstance();
    bool IsValidPipe(HSteamPipe hSteamPipe);
    bool IsValidUser(HSteamUser hSteamUser);

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
};

#endif // VAPORCORE_STEAM_CLIENT_H 
