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
#include "../include/sdk/steam_gameserver.h"
#include "logger.h"
#include "steam_client.h"
#include "steam_game_server.h"
#include "steam_utils.h"
#include "steam_master_server_updater.h"
#include "steam_networking.h"

// Global Steam client interface pointer for game server
static Steam_Client* g_pSteamGameServerClient = nullptr;

// Global game server interface pointers
static ISteamGameServer* g_pSteamGameServer = nullptr;
static ISteamUtils* g_pSteamGameServerUtils = nullptr;
static ISteamMasterServerUpdater* g_pSteamMasterServerUpdater = nullptr;
static ISteamNetworking* g_pSteamGameServerNetworking = nullptr;
static ISteamGameServerStats* g_pSteamGameServerStats = nullptr;
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

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam Game Server API setup & shutdown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll for game servers
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// Steam SDK v1.00
// S_API bool SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, int nGameAppId, const char *pchGameDir, const char *pchVersionString );
// Steam SDK v1.01
S_API bool SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
{
    VLOG_INFO("SteamGameServer_Init called - IP: %u, Port: %u, GamePort: %u, SpectatorPort: %u, QueryPort: %u, ServerMode: %d, GameDir: %s, Version: %s",
              unIP, usPort, usGamePort, usSpectatorPort, usQueryPort, eServerMode, 
              pchGameDir ? pchGameDir : "null", pchVersionString ? pchVersionString : "null");

/*
#ifdef VAPORCORE_ENABLE_LOGGING
    // Initialize logger if not already done
    VaporCore::Logger::getInstance().initialize("vaporcore_gameserver_log.txt");
#endif

    if (g_bGameServerInitialized) {
        VLOG_INFO("SteamGameServer_Init already initialized");
        return true;
    }

    // Initialize Steam client for game server
    g_pSteamGameServerClient = Steam_Client::GetInstance();
    if (!g_pSteamGameServerClient) {
        VLOG_ERROR("Failed to create Steam client instance for game server");
        return false;
    }

    // Create steam pipe and connect to server user
    g_hSteamGameServerPipe = g_pSteamGameServerClient->CreateSteamPipe();
    g_hSteamGameServerUser = g_pSteamGameServerClient->CreateLocalUser(&g_hSteamGameServerPipe);
    g_uGameServerCallCounter++;

    if (g_hSteamGameServerPipe == 0 || g_hSteamGameServerUser == 0) {
        VLOG_ERROR("Failed to create Steam pipe or connect to game server user");
        return false;
    }

    // Initialize interface instances
    g_pSteamGameServer = Steam_Game_Server::GetInstance();
    g_pSteamGameServerUtils = Steam_Utils::GetInstance();
    g_pSteamMasterServerUpdater = Steam_Master_Server_Updater::GetInstance();
    g_pSteamGameServerNetworking = Steam_Networking::GetInstance();

    // Set game server parameters
    g_bGameServerSecure = (eServerMode == eServerModeAuthenticationAndSecure);
    
    // Initialize the game server with provided parameters
    if (g_pSteamGameServer) {
        g_pSteamGameServer->BSetServerType(nGameAppId, 
                                          (eServerMode == eServerModeNoAuthentication) ? k_unServerFlagNone : k_unServerFlagActive,
                                          unIP, usGamePort, usSpectatorPort, usQueryPort,
                                          pchGameDir, pchVersionString, false);
    }

    // Initialize master server updater if query port is specified
    if (g_pSteamMasterServerUpdater && usQueryPort != 0) {
        g_pSteamMasterServerUpdater->SetActive(true);
    }

    g_bGameServerInitialized = true;
    VLOG_INFO("SteamGameServer_Init completed successfully");
    */
    return true;
}

S_API void SteamGameServer_Shutdown()
{
    VLOG_INFO("SteamGameServer_Shutdown called");

    if (!g_bGameServerInitialized) {
        VLOG_INFO("SteamGameServer_Shutdown called but not initialized");
        return;
    }

    if (g_pSteamGameServerClient && g_hSteamGameServerPipe) {
        // Release user and pipe through Steam client
        g_pSteamGameServerClient->ReleaseUser(g_hSteamGameServerPipe, g_hSteamGameServerUser);
        g_pSteamGameServerClient->BReleaseSteamPipe(g_hSteamGameServerPipe);
    }

    // Clean up global interface pointers
    g_uGameServerCallCounter--;

    g_pSteamGameServer = nullptr;
    g_pSteamGameServerUtils = nullptr;
    g_pSteamMasterServerUpdater = nullptr;
    g_pSteamGameServerNetworking = nullptr;

    g_hSteamGameServerUser = 0;
    g_hSteamGameServerPipe = 0;

    // Release singleton instances if this is the last reference
    if (g_uGameServerCallCounter == 0) {
        Steam_Game_Server::ReleaseInstance();
        Steam_Utils::ReleaseInstance();
        Steam_Master_Server_Updater::ReleaseInstance();
        Steam_Networking::ReleaseInstance();
        Steam_Client::ReleaseInstance();
        g_pSteamGameServerClient = nullptr;
    }

    g_bGameServerInitialized = false;
    g_bGameServerSecure = false;
    g_steamGameServerID = CSteamID();

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

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
// VERSION_SAFE_STEAM_API_INTERFACES uses CSteamAPIContext to provide interfaces to each module in a way that 
// lets them each specify the interface versions they are compiled with.
//
// It's important that these stay inlined in the header so the calling module specifies the interface versions
// for whatever Steam API version it has.
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

S_API HSteamUser SteamGameServer_GetHSteamUser()
{
    VLOG_DEBUG("SteamGameServer_GetHSteamUser called");
    return g_hSteamGameServerUser;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Interface accessor functions
//
//	These functions return pointers to the various Steam interfaces for game servers
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

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
