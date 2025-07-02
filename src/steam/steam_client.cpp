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
#include "steam_client.h"

CSteamClient::CSteamClient()
    : m_hSteamUser(1) // Start with user ID 1
    , m_unSteamPipeCounter(1)
    , m_pWarningMessageHook(nullptr)
    , m_bUserLoggedIn(false)
    , m_steamUser(CSteamUser::GetInstance())
    , m_steamGameServer(CSteamGameServer::GetInstance())
    , m_steamFriends(CSteamFriends::GetInstance())
    , m_steamUtils(CSteamUtils::GetInstance())
    , m_steamMasterServerUpdater(CSteamMasterServerUpdater::GetInstance())
    , m_steamMatchmaking(*CSteamMatchmaking::GetInstance())
    , m_steamUserStats(CSteamUserStats::GetInstance())
    , m_steamGameServerStats(CSteamGameServerStats::GetInstance())
    , m_steamApps(CSteamApps::GetInstance())
    , m_steamMatchmakingServers(*CSteamMatchmakingServers::GetInstance())
    , m_steamNetworking(CSteamNetworking::GetInstance())
    , m_steamRemoteStorage(CSteamRemoteStorage::GetInstance())
    , m_steamScreenshots(CSteamScreenshots::GetInstance())
    , m_steamHTTP(CSteamHTTP::GetInstance())
    , m_steamUnifiedMessages(CSteamUnifiedMessages::GetInstance())
    , m_steamController(CSteamController::GetInstance())
    , m_steamUGC(CSteamUGC::GetInstance())
    , m_steamAppList(CSteamAppList::GetInstance())
    , m_steamMusic(CSteamMusic::GetInstance())
    , m_steamMusicRemote(CSteamMusicRemote::GetInstance())
    , m_steamHTMLSurface(CSteamHTMLSurface::GetInstance())
    , m_steamInventory(CSteamInventory::GetInstance())
    , m_steamVideo(CSteamVideo::GetInstance())
    , m_steamParentalSettings(CSteamParentalSettings::GetInstance())
    , m_uCallCounter(0)
{
    VLOG_INFO(__FUNCTION__);
}

CSteamClient::~CSteamClient()
{
    VLOG_INFO(__FUNCTION__);
}

// Creates a communication pipe to the Steam client
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
HSteamPipe CSteamClient::CreateSteamPipe()
{
    VLOG_INFO(__FUNCTION__);

    VAPORCORE_LOCK_GUARD();

    HSteamPipe hSteamPipe = m_unSteamPipeCounter++;
    m_mapSteamPipes[hSteamPipe] = ESteamPipe::k_ESteamPipeNone;

    return hSteamPipe;
}

// Releases a previously created communications pipe
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
bool CSteamClient::BReleaseSteamPipe( HSteamPipe hSteamPipe )
{
    VLOG_INFO(__FUNCTION__ " - hSteamPipe: %u", hSteamPipe);

    VAPORCORE_LOCK_GUARD();

    if (m_mapSteamPipes.count(hSteamPipe)) {
        m_mapSteamPipes.erase(hSteamPipe);
        return true;
    }

    return false;
}

// connects to an existing global user, failing if none exists
// used by the game to coordinate with the steamUI
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
HSteamUser CSteamClient::ConnectToGlobalUser( HSteamPipe hSteamPipe )
{
    VLOG_INFO(__FUNCTION__ " - hSteamPipe: %u", hSteamPipe);

    VAPORCORE_LOCK_GUARD();

    if (!m_mapSteamPipes.count(hSteamPipe)) {
        return 0;
    }

    // Mark user as logged in when connecting to global user
    m_bUserLoggedIn = true;
    m_mapSteamPipes[hSteamPipe] = ESteamPipe::k_ESteamPipeClient;

    return VaporCore::DEFAULT_CLIENT_USER;
}

// used by game servers, create a steam user that won't be shared with anyone else
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
HSteamUser CSteamClient::CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType )
{
    VLOG_INFO(__FUNCTION__ " - phSteamPipe: %u, eAccountType: %d", phSteamPipe, eAccountType);
    return VaporCore::DEFAULT_SERVER_USER;
}

// Changed from Steam SDK v1.04, backward compatibility
HSteamUser CSteamClient::CreateLocalUser( HSteamPipe *phSteamPipe )
{
    VLOG_INFO(__FUNCTION__ " - phSteamPipe: %u", phSteamPipe);
    return VaporCore::DEFAULT_SERVER_USER;
}

// removes an allocated user
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
void CSteamClient::ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser )
{
    VLOG_INFO(__FUNCTION__ " - hSteamPipe: %u, hUser: %u", hSteamPipe, hUser);

    VAPORCORE_LOCK_GUARD();

    // Mark user as logged out when releasing user
    m_bUserLoggedIn = false;
}

// retrieves the ISteamUser interface associated with the handle
ISteamUser *CSteamClient::GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUser*
    if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION) == 0) {
        return &m_steamUser;
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_018) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser018*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_017) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser017*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_016) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser016*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_014) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser014*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_013) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser013*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_012) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser012*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_010) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser010*>(&m_steamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_009) == 0) {
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser009*>(&m_steamUser));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMUSER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUser*>(&m_steamUser);
    }
}

// retrieves the ISteamGameServer interface associated with the handle
ISteamGameServer *CSteamClient::GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamGameServer*
    if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamGameServer*>(&m_steamGameServer);
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_011) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer011*>(&m_steamGameServer));
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_010) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer010*>(&m_steamGameServer));
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_009) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer009*>(&m_steamGameServer));
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_008) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer008*>(&m_steamGameServer));
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer005*>(&m_steamGameServer));
    } else if (strcmp(pchVersion, STEAMGAMESERVER_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamGameServer*>(static_cast<ISteamGameServer004*>(&m_steamGameServer));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMGAMESERVER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamGameServer*>(&m_steamGameServer);
    }
}

// set the local IP and Port to bind to
// this must be set before CreateLocalUser()
void CSteamClient::SetLocalIPBinding( uint32 unIP, uint16 usPort )
{
    VLOG_INFO(__FUNCTION__ " - unIP: %u, usPort: %u", unIP, usPort);
}

// returns the ISteamFriends interface
ISteamFriends *CSteamClient::GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamFriends*
    if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamFriends*>(&m_steamFriends);
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_014) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends014*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_013) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends013*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_011) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends011*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_009) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends009*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends007*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends005*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends004*>(&m_steamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends003*>(&m_steamFriends));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMFRIENDS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamFriends*>(&m_steamFriends);
    }
}

// returns the ISteamUtils interface
ISteamUtils *CSteamClient::GetISteamUtils(HSteamPipe hSteamPipe, const char *pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamPipe: %u, pchVersion: %s", hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version
    if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamUtils*>(&m_steamUtils);
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_008) == 0) {
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils008*>(&m_steamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils007*>(&m_steamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils005*>(&m_steamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils004*>(&m_steamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils002*>(&m_steamUtils));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMUTILS_INTERFACE_VERSION, pchVersion);
        return static_cast<ISteamUtils*>(&m_steamUtils);
    }
}

// returns the ISteamMatchmaking interface
ISteamMatchmaking *CSteamClient::GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamMatchmaking*
    if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamMatchmaking*>(&m_steamMatchmaking);
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_008) == 0) {
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking008*>(&m_steamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking007*>(&m_steamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_006) == 0) {
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking006*>(&m_steamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking004*>(&m_steamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking002*>(&m_steamMatchmaking));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMMATCHMAKING_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMatchmaking*>(&m_steamMatchmaking);
    }
}

// returns the ISteamContentServer interface
// Removed from Steam SDK v1.04, backward compatibility
ISteamContentServer *CSteamClient::GetISteamContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamuser: %d, hSteamPipe: %d, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);
    return nullptr;
}

// returns the ISteamMasterServerUpdater interface
// Removed from Steam SDK v1.17, backward compatibility
ISteamMasterServerUpdater *CSteamClient::GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    VAPORCORE_LOCK_GUARD();

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    if (strcmp(pchVersion, STEAMMASTERSERVERUPDATER_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamMasterServerUpdater*>(&m_steamMasterServerUpdater);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMMASTERSERVERUPDATER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMasterServerUpdater*>(&m_steamMasterServerUpdater);
    }
}

// returns the ISteamMatchmakingServers interface
ISteamMatchmakingServers *CSteamClient::GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %d, hSteamPipe: %d, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamMatchmakingServers*
    if (strcmp(pchVersion, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamMatchmakingServers*>(&m_steamMatchmakingServers);
    } else if (strcmp(pchVersion, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamMatchmakingServers*>(static_cast<ISteamMatchmakingServers001*>(&m_steamMatchmakingServers));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMatchmakingServers*>(&m_steamMatchmakingServers);
    }
}

// returns the a generic interface
void *CSteamClient::GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement generic interface lookup
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);
    return nullptr;
}

// returns the ISteamUserStats interface
ISteamUserStats *CSteamClient::GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUserStats*
    if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamUserStats*>(&m_steamUserStats);
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_010) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats010*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_009) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats009*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats007*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_006) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats006*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats005*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats004*>(&m_steamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats003*>(&m_steamUserStats));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMUSERSTATS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUserStats*>(&m_steamUserStats);
    }
}

// returns the ISteamGameServerStats interface
ISteamGameServerStats *CSteamClient::GetISteamGameServerStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %d, hSteamPipe: %d, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    if (strcmp(pchVersion, STEAMGAMESERVERSTATS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamGameServerStats*>(&m_steamGameServerStats);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMGAMESERVERSTATS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamGameServerStats*>(&m_steamGameServerStats);
    }
}

// returns apps interface
ISteamApps *CSteamClient::GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version
    if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamApps*>(&m_steamApps);
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps007*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_006) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps006*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps005*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps004*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps003*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps002*>(&m_steamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps001*>(&m_steamApps));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMAPPS_INTERFACE_VERSION, pchVersion);
        return static_cast<ISteamApps*>(&m_steamApps);
    }
}

// networking
ISteamNetworking *CSteamClient::GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamNetworking*
    if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamNetworking*>(&m_steamNetworking);
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking004*>(&m_steamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking003*>(&m_steamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking002*>(&m_steamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking001*>(&m_steamNetworking));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMNETWORKING_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamNetworking*>(&m_steamNetworking);
    }
}

// remote storage
ISteamRemoteStorage *CSteamClient::GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamuser: %d, hSteamPipe: %d, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamRemoteStorage*
    if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamRemoteStorage*>(&m_steamRemoteStorage);
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_013) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage013*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_012) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage012*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_011) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage011*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_010) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage010*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_008) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage008*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_006) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage006*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage005*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage004*>(&m_steamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage002*>(&m_steamRemoteStorage));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMREMOTESTORAGE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamRemoteStorage*>(&m_steamRemoteStorage);
    }
}

// user screenshots
ISteamScreenshots *CSteamClient::GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamuser: %d, hSteamPipe: %d, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamScreenshots*
    if (strcmp(pchVersion, STEAMSCREENSHOTS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamScreenshots*>(&m_steamScreenshots);
    } else if (strcmp(pchVersion, STEAMSCREENSHOTS_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamScreenshots*>(static_cast<ISteamScreenshots002*>(&m_steamScreenshots));
    } else if (strcmp(pchVersion, STEAMSCREENSHOTS_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamScreenshots*>(static_cast<ISteamScreenshots001*>(&m_steamScreenshots));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMSCREENSHOTS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamScreenshots*>(&m_steamScreenshots);
    }
}

// Deprecated. Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead.
// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::RunFrame()
{
    VLOG_INFO(__FUNCTION__);
}

// returns the number of IPC calls made since the last time this function was called
// Used for perf debugging so you can understand how many IPC calls your game makes per frame
// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
// control how often you do them.
uint32 CSteamClient::GetIPCCallCount()
{
    VLOG_INFO(__FUNCTION__);
    return 1;
}


// API warning handling
// 'int' is the severity; 0 for msg, 1 for warning
// 'const char *' is the text of the message
// callbacks will occur directly after the API function is called that generated the warning or message
void CSteamClient::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
    VLOG_INFO(__FUNCTION__);
} 

// Trigger global shutdown for the DLL
bool CSteamClient::BShutdownIfAllPipesClosed()
{
    VLOG_INFO(__FUNCTION__);

    VAPORCORE_LOCK_GUARD();

    if (m_mapSteamPipes.size() != 0) {
        VLOG_WARNING(__FUNCTION__ " - Pipes are still open");
    }

    // TODO: Implement shutdown logic

    return true;
}

// Expose HTTP interface
ISteamHTTP *CSteamClient::GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamuser: %d, hSteamPipe: %d, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamHTTP*
    if (strcmp(pchVersion, STEAMHTTP_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamHTTP*>(&m_steamHTTP);
    } else if (strcmp(pchVersion, STEAMHTTP_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamHTTP*>(static_cast<ISteamHTTP001*>(&m_steamHTTP));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMHTTP_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamHTTP*>(&m_steamHTTP);
    }
}

// Deprecated - the ISteamUnifiedMessages interface is no longer intended for public consumption.
void *CSteamClient::DEPRECATED_GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);
    return nullptr;
}

// Removed from Steam SDK v1.42, backward compatibility
ISteamUnifiedMessages* CSteamClient::GetISteamUnifiedMessages(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMUNIFIEDMESSAGES_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamUnifiedMessages*>(&m_steamUnifiedMessages);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMUNIFIEDMESSAGES_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUnifiedMessages*>(&m_steamUnifiedMessages);
    }
}


// Exposes the ISteamController interface
ISteamController* CSteamClient::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamController*
    if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamController*>(&m_steamController);
    } else if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION_004) == 0) {
        return reinterpret_cast<ISteamController*>(static_cast<ISteamController004*>(&m_steamController));
    } else if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamController*>(static_cast<ISteamController003*>(&m_steamController));
    } else if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamController*>(static_cast<ISteamController001*>(&m_steamController));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMCONTROLLER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamController*>(&m_steamController);
    }
}

// Exposes the ISteamUGC interface 
ISteamUGC* CSteamClient::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUGC*
    if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamUGC*>(&m_steamUGC);
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_009) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC009*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_008) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC008*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_007) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC007*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_005) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC005*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC003*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC002*>(&m_steamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC001*>(&m_steamUGC));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMUGC_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUGC*>(&m_steamUGC);
    }
}

// returns app list interface, only available on specially registered apps
ISteamAppList* CSteamClient::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMAPPLIST_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamAppList*>(&m_steamAppList);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMAPPLIST_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamAppList*>(&m_steamAppList);
    }
}

// Music Player
ISteamMusic* CSteamClient::GetISteamMusic(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMMUSIC_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamMusic*>(&m_steamMusic);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMMUSIC_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMusic*>(&m_steamMusic);
    }
}

// Music Player Remote
ISteamMusicRemote* CSteamClient::GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMMUSICREMOTE_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamMusicRemote*>(&m_steamMusicRemote);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMMUSICREMOTE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMusicRemote*>(&m_steamMusicRemote);
    }
}

// html page display
ISteamHTMLSurface* CSteamClient::GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamHTMLSurface*
    if (strcmp(pchVersion, STEAMHTMLSURFACE_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamHTMLSurface*>(&m_steamHTMLSurface);
    } else if (strcmp(pchVersion, STEAMHTMLSURFACE_INTERFACE_VERSION_003) == 0) {
        return reinterpret_cast<ISteamHTMLSurface*>(static_cast<ISteamHTMLSurface003*>(&m_steamHTMLSurface));
    } else if (strcmp(pchVersion, STEAMHTMLSURFACE_INTERFACE_VERSION_002) == 0) {
        return reinterpret_cast<ISteamHTMLSurface*>(static_cast<ISteamHTMLSurface002*>(&m_steamHTMLSurface));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMHTMLSURFACE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamHTMLSurface*>(&m_steamHTMLSurface);
    }
}

// Helper functions for internal Steam usage
// Deprecated from Steam SDK v1.37, backward compatibility
void CSteamClient::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess(void (*func)())
{
    VLOG_INFO(__FUNCTION__);
}

// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Set_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_INFO(__FUNCTION__);
}

// Deprecated from Steam SDK v1.37, backward compatibility
void CSteamClient::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess(void (*func)())
{
    VLOG_INFO(__FUNCTION__);
}

// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Remove_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_INFO(__FUNCTION__);
}

// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t func)
{
    VLOG_INFO(__FUNCTION__);
}

// inventory
ISteamInventory* CSteamClient::GetISteamInventory(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (V001)
    if (strcmp(pchVersion, STEAMINVENTORY_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamInventory*>(&m_steamInventory);
    } else if (strcmp(pchVersion, STEAMINVENTORY_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamInventory*>(static_cast<ISteamInventory001*>(&m_steamInventory));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMINVENTORY_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamInventory*>(&m_steamInventory);
    }
}

// Video
ISteamVideo* CSteamClient::GetISteamVideo(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (V001)
    if (strcmp(pchVersion, STEAMVIDEO_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamVideo*>(&m_steamVideo);
    } else if (strcmp(pchVersion, STEAMVIDEO_INTERFACE_VERSION_001) == 0) {
        return reinterpret_cast<ISteamVideo*>(static_cast<ISteamVideo001*>(&m_steamVideo));
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMVIDEO_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamVideo*>(&m_steamVideo);
    }
}

// Parental controls
ISteamParentalSettings *CSteamClient::GetISteamParentalSettings( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_INFO(__FUNCTION__ " - hSteamUser: %u, hSteamPipe: %u, pchVersion: %s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR(__FUNCTION__ " - Invalid version string (null)");
        return nullptr;
    }
    
    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMPARENTALSETTINGS_INTERFACE_VERSION) == 0) {
        return static_cast<ISteamParentalSettings*>(&m_steamParentalSettings);
    } else {
        VLOG_ERROR(__FUNCTION__ " - Unknown interface version '%s', returning " STEAMPARENTALSETTINGS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamParentalSettings*>(&m_steamParentalSettings);
    }
}
