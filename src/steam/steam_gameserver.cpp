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

// Global game server initialization counter
static uint32 g_uGameServerCallCounter = 0;

// Game server initialization parameters
static bool g_bGameServerInitialized = false;
static bool g_bGameServerSecure = false;
static CSteamID g_steamGameServerID;

// Shutdown SteamGameSeverXxx interfaces, log out, and free resources.
S_API void SteamGameServer_Shutdown()
{
    VLOG_INFO(__FUNCTION__);

    // Reset global interface pointers
    g_pSteamGameServer = nullptr;
    g_pSteamGameServerUtils = nullptr;
    g_pSteamMasterServerUpdater = nullptr;
    g_pSteamGameServerNetworking = nullptr;
    g_pSteamGameServerStats = nullptr;
    g_pSteamGameServerHTTP = nullptr;
    g_pSteamGameServerInventory = nullptr;
    g_pSteamGameServerUGC = nullptr;
}

S_API bool SteamGameServer_BSecure()
{
    VLOG_INFO(__FUNCTION__ " - returning: %s", g_bGameServerSecure ? "true" : "false");
    return g_bGameServerSecure;
}

S_API uint64 SteamGameServer_GetSteamID()
{
    VLOG_INFO(__FUNCTION__);
    if (g_pSteamGameServer) {
        CSteamID steamID = g_pSteamGameServer->GetSteamID();
        return steamID.ConvertToUint64();
    }
    return 0;
}

S_API bool S_CALLTYPE SteamInternal_GameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString )
{
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, GamePort: %u, QueryPort: %u, ServerMode: %d, Version: %s", 
               unIP, usPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    return true;
}

// Initialize SteamGameServer client and interface objects, and set server properties which may not be changed.
//
// After calling this function, you should set any additional server parameters, and then
// call ISteamGameServer::LogOnAnonymous() or ISteamGameServer::LogOn()
//
// - usSteamPort is the local port used to communicate with the steam servers.
//   NOTE: unless you are using ver old Steam client binaries, this parameter is ignored, and
//         you should pass 0.  Gameservers now always use WebSockets to talk to Steam.
//         This protocol is TCP-based and thus always uses an ephemeral local port.
//         Older steam client binaries used UDP to talk to Steam, and this argument was useful.
//         A future version of the SDK will remove this argument.
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
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, GamePort: %u, QueryPort: %u, ServerMode: %d, Version: %s", 
               unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    return SteamInternal_GameServer_Init( unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString );
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
    VLOG_INFO(__FUNCTION__ " - IP: %u, Port: %u, GamePort: %u, QueryPort: %u, ServerMode: %d, Version: %s", 
               unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    return SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
}

// If your application contains modules which could be built against different Steamworks SDK
// versions, then you should define VERSION_SAFE_STEAM_API_INTERFACES to enforce that you cannot
// use the version-less global accessors. Instead, create and use CSteamGameServerAPIContext
// objects to retrieve interface pointers which are appropriate for your Steamworks SDK headers.

S_API ISteamGameServer *SteamGameServer()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServer;
}

S_API ISteamUtils *SteamGameServerUtils()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerUtils;
}

// Removed from Steam SDK v1.17, backward compatibility
S_API ISteamMasterServerUpdater *SteamMasterServerUpdater()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamMasterServerUpdater;
}

S_API ISteamNetworking *SteamGameServerNetworking()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerNetworking;
}

S_API ISteamGameServerStats *SteamGameServerStats()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerStats;
}

S_API ISteamHTTP *SteamGameServerHTTP()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerHTTP;
}

S_API ISteamInventory *SteamGameServerInventory()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerInventory;
}

S_API ISteamUGC *SteamGameServerUGC()
{
    VLOG_INFO(__FUNCTION__);
    return g_pSteamGameServerUGC;
}
