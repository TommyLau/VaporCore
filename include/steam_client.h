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

class ISteamUnifiedMessages;

#include <isteammasterserverupdater.h>
#include <isteamclient.h>
#include <isteamclient007.h>
#include <isteamclient008.h>
#include <isteamclient009.h>
#include <isteamclient010.h>
#include <isteamclient011.h>
#include <isteamclient012.h>
#include <isteamclient014.h>
#include <isteamclient015.h>
#include <isteamclient016.h>
#include <isteamclient017.h>

#include "steam_user.h"
#include "steam_game_server.h"
#include "steam_friends.h"
#include "steam_utils.h"
#include "steam_master_server_updater.h"
#include "steam_matchmaking.h"
#include "steam_user_stats.h"
#include "steam_game_server_stats.h"
#include "steam_apps.h"
#include "steam_networking.h"
#include "steam_remote_storage.h"
#include "steam_screenshots.h"
#include "steam_http.h"
#include "steam_unified_messages.h"
#include "steam_controller.h"
#include "steam_ugc.h"
#include "steam_app_list.h"
#include "steam_music.h"
#include "steam_music_remote.h"
#include "steam_html_surface.h"
#include "steam_inventory.h"
#include "steam_video.h"
#include "steam_parental_settings.h"
#include "steam_input.h"

// Steam pipe state enumeration
enum ESteamPipe {
    k_ESteamPipeNone = 0,
    k_ESteamPipeClient = 1,
    k_ESteamPipeServer = 2
};

//-----------------------------------------------------------------------------
// Purpose: Interface to creating a new steam instance, or to
//			connect to an existing steam instance, whether it's in a
//			different process or is local.
//
//			For most scenarios this is all handled automatically via SteamAPI_Init().
//			You'll only need these APIs if you have a more complex versioning scheme,
//			or if you want to implement a multiplexed gameserver where a single process
//			is handling multiple games at once with independent gameserver SteamIDs.
//-----------------------------------------------------------------------------
class CSteamClient :
	public ISteamClient,
    public ISteamClient007,
    public ISteamClient008,
    public ISteamClient009,
    public ISteamClient010,
    public ISteamClient011,
    public ISteamClient012,
    public ISteamClient014,
    public ISteamClient015,
    public ISteamClient016,
    public ISteamClient017
{
public:
	// Singleton accessor
    static CSteamClient& GetInstance()
    {
		static CSteamClient instance;
		return instance;
    }

    // Counter access methods
    uintp IncrementCallCounter() { return ++m_uCallCounter; }
    uintp DecrementCallCounter() { return --m_uCallCounter; }
    uintp GetCallCounter() const { return m_uCallCounter; }

public:
	// Creates a communication pipe to the Steam client.
	// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
	HSteamPipe CreateSteamPipe() override;

	// Releases a previously created communications pipe
	// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
	bool BReleaseSteamPipe( HSteamPipe hSteamPipe ) override;

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
	HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe ) override;

	// used by game servers, create a steam user that won't be shared with anyone else
	// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType ) override;
	// Changed from Steam SDK v1.04, backward compatibility
	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe ) override;

	// removes an allocated user
	// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
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

	// game search
	ISteamGameSearch *GetISteamGameSearch( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Deprecated. Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead.
	// Deprecated from Steam SDK v1.36, backward compatibility
	STEAM_PRIVATE_API( void RunFrame() override; )

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	uint32 GetIPCCallCount() override;

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message.
	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction ) override;

	// Trigger global shutdown for the DLL
	bool BShutdownIfAllPipesClosed() override;

	// Expose HTTP interface
	ISteamHTTP *GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Deprecated - the ISteamUnifiedMessages interface is no longer intended for public consumption.
	STEAM_PRIVATE_API( void *DEPRECATED_GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override ; )
	// Removed from Steam SDK v1.42, backward compatibility
	ISteamUnifiedMessages *GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the ISteamController interface - deprecated in favor of Steam Input
	ISteamController *GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the ISteamUGC interface
	ISteamUGC *GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// returns app list interface, only available on specially registered apps
	ISteamAppList *GetISteamAppList( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;
	
	// Music Player
	ISteamMusic *GetISteamMusic( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Music Player Remote
	ISteamMusicRemote *GetISteamMusicRemote( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// html page display
	ISteamHTMLSurface *GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion) override;

	// Helper functions for internal Steam usage
	// Deprecated from Steam SDK v1.37, backward compatibility
	STEAM_PRIVATE_API( void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess( void (*)() ) override; )
	// Changed from Steam SDK v1.36, backward compatibility
	STEAM_PRIVATE_API( void Set_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func) override; )
	// Deprecated from Steam SDK v1.37, backward compatibility
	STEAM_PRIVATE_API( void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess( void (*)() ) override; )
	// Changed from Steam SDK v1.36, backward compatibility
	STEAM_PRIVATE_API( void Remove_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func) override; )
	// Changed from Steam SDK v1.36, backward compatibility
	STEAM_PRIVATE_API( void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t func) override; )

	// inventory
	ISteamInventory *GetISteamInventory( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Video
	ISteamVideo *GetISteamVideo( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Parental controls
	ISteamParentalSettings *GetISteamParentalSettings( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Exposes the Steam Input interface for controller support
	ISteamInput *GetISteamInput( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

	// Steam Parties interface
	ISteamParties *GetISteamParties( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) override;

private:
    // Private constructor and destructor for singleton
    CSteamClient();
    ~CSteamClient();

    // Delete copy constructor and assignment operator
    CSteamClient(const CSteamClient&) = delete;
    CSteamClient& operator=(const CSteamClient&) = delete;

private:
    // Internal state
    HSteamUser m_hSteamUser;
    uint32 m_unSteamPipeCounter;
    SteamAPIWarningMessageHook_t m_pWarningMessageHook;
    bool m_bUserLoggedIn;
    
    // Steam pipe management
    std::map<HSteamPipe, ESteamPipe> m_mapSteamPipes;
    
    // Implementation class instances
    CSteamUser& m_steamUser;
    CSteamGameServer& m_steamGameServer;
    CSteamFriends& m_steamFriends;
    CSteamUtils& m_steamUtils;
    CSteamMasterServerUpdater& m_steamMasterServerUpdater;
    CSteamMatchmaking& m_steamMatchmaking;
	CSteamGameSearch& m_steamGameSearch;
    CSteamUserStats& m_steamUserStats;
    CSteamGameServerStats& m_steamGameServerStats;
    CSteamApps& m_steamApps;
    CSteamMatchmakingServers& m_steamMatchmakingServers;
    CSteamNetworking& m_steamNetworking;
    CSteamRemoteStorage& m_steamRemoteStorage;
    CSteamScreenshots& m_steamScreenshots;
    CSteamHTTP& m_steamHTTP;
    CSteamUnifiedMessages& m_steamUnifiedMessages;
    CSteamController& m_steamController;
    CSteamUGC& m_steamUGC;
    CSteamAppList& m_steamAppList;
    CSteamMusic& m_steamMusic;
    CSteamMusicRemote& m_steamMusicRemote;
    CSteamHTMLSurface& m_steamHTMLSurface;
    CSteamInventory& m_steamInventory;
    CSteamVideo& m_steamVideo;
    CSteamParentalSettings& m_steamParentalSettings;
    CSteamInput& m_steamInput;
    CSteamParties& m_steamParties;
    
    // Initialization counter
    uintp m_uCallCounter;    // Tracks API calls
};

#endif // VAPORCORE_STEAM_CLIENT_H 
