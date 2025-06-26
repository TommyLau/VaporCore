/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>
#include <cstdlib>

#include <steam_gameserver.h>

#include "vapor_base.h"
#include "steam_client.h"
#include "steam_game_server.h"
#include "steam_utils.h"
#include "steam_master_server_updater.h"
#include "steam_networking.h"
#include "steam_inventory.h"

// Global Steam client interface pointer for game server
static CSteamClient* g_pSteamGameServerClient = nullptr;

// Global game server interface pointers
static ISteamGameServer* g_pSteamGameServer = nullptr;
static ISteamUtils* g_pSteamGameServerUtils = nullptr;
static ISteamMasterServerUpdater* g_pSteamMasterServerUpdater = nullptr;
static ISteamNetworking* g_pSteamGameServerNetworking = nullptr;
static ISteamGameServerStats* g_pSteamGameServerStats = nullptr;
static ISteamHTTP* g_pSteamGameServerHTTP = nullptr;
static ISteamInventory* g_pSteamGameServerInventory = nullptr;
static ISteamUGC* g_pSteamGameServerUGC = nullptr;

S_API ISteamClient *g_pSteamClientGameServer;

// Global pipe and user handles for game server
static HSteamPipe g_hSteamGameServerPipe = 0;
static HSteamUser g_hSteamGameServerUser = 0;

// Global game server initialization counter
static uint32 g_uGameServerCallCounter = 0;

// Game server initialization parameters
static bool g_bGameServerInitialized = false;
static bool g_bGameServerSecure = false;
static CSteamID g_steamGameServerID;

// Initialize ISteamGameServer interface object, and set server properties which may not be changed.
//
// After calling this function, you should set any additional server parameters, and then
// call ISteamGameServer::LogOnAnonymous() or ISteamGameServer::LogOn()
//
// - usSteamPort is the local port used to communicate with the steam servers.
// - usGamePort is the port that clients will connect to for gameplay.
// - usQueryPort is the port that will manage server browser related duties and info
//		pings from clients.  If you pass MASTERSERVERUPDATERPORT_USEGAMESOCKETSHARE for usQueryPort, then it
//		will use "GameSocketShare" mode, which means that the game is responsible for sending and receiving
//		UDP packets for the master  server updater. See references to GameSocketShare in isteamgameserver.h.
// - The version string is usually in the form x.x.x.x, and is used by the master server to detect when the
//		server is out of date.  (Only servers with the latest version will be listed.)

// Steam SDK v1.00 - SteamGameServer004 and before
// S_API bool SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, int nGameAppId, const char *pchGameDir, const char *pchVersionString );
// Steam SDK v1.01 - SteamGameServer010 and before
// S_API bool SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );
// Steam SDK v1.17 - SteamGameServer011 ~
S_API bool SteamGameServer_Init( uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString )
{
    VLOG_DEBUG("SteamGameServer_Init called: %d, %d, %d, %d, %d, %s", unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    return SteamInternal_GameServer_Init( unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString );
}

S_API void SteamGameServer_Shutdown()
{
    VLOG_INFO("SteamGameServer_Shutdown called");

    // TODO: Implement game server shutdown
    
    // Reset global interface pointers
    g_pSteamGameServer = nullptr;
    g_pSteamGameServerUtils = nullptr;
    g_pSteamMasterServerUpdater = nullptr;
    g_pSteamGameServerNetworking = nullptr;
    g_pSteamGameServerStats = nullptr;
    g_pSteamGameServerHTTP = nullptr;
    g_pSteamGameServerInventory = nullptr;
    g_pSteamGameServerUGC = nullptr;

    VLOG_INFO("SteamGameServer_Shutdown completed");
}

S_API void SteamGameServer_RunCallbacks()
{
    VLOG_DEBUG("SteamGameServer_RunCallbacks called");
    // TODO: Implement game server callback processing
    // This would typically process callbacks for game server events
}

S_API bool SteamGameServer_BSecure()
{
    VLOG_DEBUG("SteamGameServer_BSecure called - returning: %s", g_bGameServerSecure ? "true" : "false");
    return g_bGameServerSecure;
}

S_API uint64 SteamGameServer_GetSteamID()
{
    VLOG_DEBUG("SteamGameServer_GetSteamID called");
    if (g_pSteamGameServer) {
        CSteamID steamID = g_pSteamGameServer->GetSteamID();
        return steamID.ConvertToUint64();
    }
    return 0;
}

// If your application contains modules which could be built against different Steamworks SDK
// versions, then you should define VERSION_SAFE_STEAM_API_INTERFACES to enforce that you cannot
// use the version-less global accessors. Instead, create and use CSteamGameServerAPIContext
// objects to retrieve interface pointers which are appropriate for your Steamworks SDK headers.

S_API ISteamGameServer *SteamGameServer()
{
    VLOG_DEBUG("SteamGameServer() called");
    return g_pSteamGameServer;
}

S_API ISteamUtils *SteamGameServerUtils()
{
    VLOG_DEBUG("SteamGameServerUtils() called");
    return g_pSteamGameServerUtils;
}

// Removed from Steam SDK v1.17, backward compatibility
S_API ISteamMasterServerUpdater *SteamMasterServerUpdater()
{
    VLOG_DEBUG("SteamMasterServerUpdater() called");
    return g_pSteamMasterServerUpdater;
}

S_API ISteamNetworking *SteamGameServerNetworking()
{
    VLOG_DEBUG("SteamGameServerNetworking() called");
    return g_pSteamGameServerNetworking;
}

S_API ISteamGameServerStats *SteamGameServerStats()
{
    VLOG_DEBUG("SteamGameServerStats() called");
    return g_pSteamGameServerStats;
}

S_API ISteamHTTP *SteamGameServerHTTP()
{
    VLOG_DEBUG("SteamGameServerHTTP() called");
    return g_pSteamGameServerHTTP;
}

S_API ISteamInventory *SteamGameServerInventory()
{
    VLOG_DEBUG("SteamGameServerInventory() called");
    return g_pSteamGameServerInventory;
}

S_API ISteamUGC *SteamGameServerUGC()
{
    VLOG_DEBUG("SteamGameServerUGC() called");
    return g_pSteamGameServerUGC;
}

// Older SDKs exported this global pointer, but it is no longer supported.
// You should use SteamGameServerClient() or CSteamGameServerAPIContext to
// safely access the ISteamClient APIs from your game server application.
//S_API ISteamClient *g_pSteamClientGameServer;

// SteamGameServer_InitSafe has been replaced with SteamGameServer_Init and
// is no longer supported. Use SteamGameServer_Init instead.
//S_API void S_CALLTYPE SteamGameServer_InitSafe();

// Steam SDK v1.01 - SteamGameServer010 and before
// S_API bool SteamGameServer_InitSafe( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );
// Steam SDK v1.17 - SteamGameServer011 ~ SteamGameServer012
// Removed from Steam SDK v1.37, backward compatibility
S_API bool SteamGameServer_InitSafe( uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString )
{
    return SteamInternal_GameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steamclient.dll private wrapper functions
//
//	The following functions are part of abstracting API access to the steamclient.dll, but should only be used in very specific cases
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

S_API HSteamPipe SteamGameServer_GetHSteamPipe()
{
    VLOG_DEBUG("SteamGameServer_GetHSteamPipe called");
    return g_hSteamGameServerPipe;
}

S_API HSteamUser SteamGameServer_GetHSteamUser()
{
    VLOG_DEBUG("SteamGameServer_GetHSteamUser called");
    return g_hSteamGameServerUser;
}

S_API bool S_CALLTYPE SteamInternal_GameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString )
{
    VLOG_DEBUG("SteamInternal_GameServer_Init called - IP: %u, Port: %u, GamePort: %u, QueryPort: %u, ServerMode: %d, Version: %s", 
               unIP, usPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    return true;
}
