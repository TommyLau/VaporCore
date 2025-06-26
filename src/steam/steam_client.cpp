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

// Static instance
CSteamClient* CSteamClient::s_pInstance = nullptr;

CSteamClient::CSteamClient()
    : m_hSteamUser(1) // Start with user ID 1
    , m_unSteamPipeCounter(1)
    , m_pWarningMessageHook(nullptr)
    , m_bUserLoggedIn(false)
    , m_pSteamUser(CSteamUser::GetInstance())
    , m_pSteamFriends(CSteamFriends::GetInstance())
    , m_pSteamUtils(CSteamUtils::GetInstance())
    , m_pSteamMatchmaking(CSteamMatchmaking::GetInstance())
    , m_pSteamUserStats(CSteamUserStats::GetInstance())
    , m_pSteamApps(CSteamApps::GetInstance())
    , m_pSteamMatchmakingServers(CSteamMatchmakingServers::GetInstance())
    , m_pSteamNetworking(CSteamNetworking::GetInstance())
    , m_pSteamRemoteStorage(CSteamRemoteStorage::GetInstance())
    , m_pSteamScreenshots(CSteamScreenshots::GetInstance())
    , m_pSteamHTTP(CSteamHTTP::GetInstance())
    , m_pSteamUnifiedMessages(CSteamUnifiedMessages::GetInstance())
    , m_pSteamController(CSteamController::GetInstance())
    , m_pSteamUGC(CSteamUGC::GetInstance())
    , m_pSteamAppList(CSteamAppList::GetInstance())
    , m_pSteamMusic(CSteamMusic::GetInstance())
    , m_pSteamMusicRemote(CSteamMusicRemote::GetInstance())
    , m_pSteamHTMLSurface(CSteamHTMLSurface::GetInstance())
    , m_pSteamInventory(CSteamInventory::GetInstance())
    , m_pSteamVideo(CSteamVideo::GetInstance())
{
    VLOG_INFO("CSteamClient constructor called");
}

CSteamClient::~CSteamClient()
{
    VLOG_INFO("CSteamClient destructor called");
}

CSteamClient* CSteamClient::GetInstance()
{
    VLOG_DEBUG("CSteamClient::GetInstance called");

    VAPORCORE_LOCK_GUARD();

    if (!s_pInstance) {
        s_pInstance = new CSteamClient();
    }

    return s_pInstance;
}

void CSteamClient::ReleaseInstance()
{
    VLOG_DEBUG("CSteamClient::ReleaseInstance called");

    VAPORCORE_LOCK_GUARD();
    
    if (s_pInstance) {
        VLOG_INFO("Releasing CSteamClient singleton instance");
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

const char* CSteamClient::GetInterfaceVersion(const char* pchVersion, const char* pchDefaultVersion)
{
    VLOG_DEBUG("GetInterfaceVersion called with pchVersion=%s and pchDefaultVersion=%s", pchVersion, pchDefaultVersion);

    return pchVersion ? pchVersion : pchDefaultVersion;
}

// Creates a communication pipe to the Steam client
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
HSteamPipe CSteamClient::CreateSteamPipe()
{
    VLOG_DEBUG("CreateSteamPipe called");
    HSteamPipe hSteamPipe = m_unSteamPipeCounter++;
    m_mapSteamPipes[hSteamPipe] = ESteamPipe::k_ESteamPipeNone;
    VLOG_DEBUG("CreateSteamPipe completed with hSteamPipe=%u", hSteamPipe);

    return hSteamPipe;
}

// Releases a previously created communications pipe
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
bool CSteamClient::BReleaseSteamPipe( HSteamPipe hSteamPipe )
{
    VLOG_DEBUG("BReleaseSteamPipe called with hSteamPipe=%u", hSteamPipe);

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
    VLOG_DEBUG("ConnectToGlobalUser called with hSteamPipe=%u", hSteamPipe);

    if (!m_mapSteamPipes.count(hSteamPipe)) {
        return 0;
    }

    // Mark user as logged in when connecting to global user
    m_bUserLoggedIn = true;
    VLOG_INFO("User logged in through ConnectToGlobalUser");

    m_mapSteamPipes[hSteamPipe] = ESteamPipe::k_ESteamPipeClient;

    return DEFAULT_CLIENT_USER;
}

// used by game servers, create a steam user that won't be shared with anyone else
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
HSteamUser CSteamClient::CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType )
{
    // TODO: Implement local user creation
    VLOG_DEBUG("CreateLocalUser called with phSteamPipe=%u and eAccountType=%d", phSteamPipe, eAccountType);
    return DEFAULT_SERVER_USER;
}

// Changed from Steam SDK v1.04, backward compatibility
HSteamUser CSteamClient::CreateLocalUser( HSteamPipe *phSteamPipe )
{
    // TODO: Implement local user creation
    VLOG_DEBUG("CreateLocalUser called with phSteamPipe=%u", phSteamPipe);
    return DEFAULT_SERVER_USER;
}

// removes an allocated user
// NOT THREADSAFE - ensure that no other threads are accessing Steamworks API when calling
void CSteamClient::ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser )
{
    VLOG_DEBUG("ReleaseUser called with hSteamPipe=%u, hUser=%u", hSteamPipe, hUser);
    
    // Mark user as logged out when releasing user
    m_bUserLoggedIn = false;
    VLOG_INFO("User logged out through ReleaseUser");
}

// retrieves the ISteamUser interface associated with the handle
ISteamUser *CSteamClient::GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamUser called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamUser: Invalid version string (null)");
        return nullptr;
    }

    // Get the Steam user implementation instance
    if (!m_pSteamUser) {
        VLOG_ERROR("GetISteamUser: Steam user not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUser*
    if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamUser (latest) - %s", STEAMUSER_INTERFACE_VERSION);
        return m_pSteamUser;
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_018) == 0) {
        VLOG_DEBUG("Returning ISteamUser018");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser018*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_017) == 0) {
        VLOG_DEBUG("Returning ISteamUser017");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser017*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_016) == 0) {
        VLOG_DEBUG("Returning ISteamUser016");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser016*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_014) == 0) {
        VLOG_DEBUG("Returning ISteamUser014");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser014*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_013) == 0) {
        VLOG_DEBUG("Returning ISteamUser013");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser013*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_012) == 0) {
        VLOG_DEBUG("Returning ISteamUser012");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser012*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_010) == 0) {
        VLOG_DEBUG("Returning ISteamUser010");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser010*>(m_pSteamUser));
    } else if (strcmp(pchVersion, STEAMUSER_INTERFACE_VERSION_009) == 0) {
        VLOG_DEBUG("Returning ISteamUser009");
        return reinterpret_cast<ISteamUser*>(static_cast<ISteamUser009*>(m_pSteamUser));
    } else {
        VLOG_WARNING("GetISteamUser: Unknown interface version '%s', returning " STEAMUSER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUser*>(m_pSteamUser);
    }
}

// retrieves the ISteamGameServer interface associated with the handle
ISteamGameServer *CSteamClient::GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement game server interface
    VLOG_DEBUG("GetISteamGameServer called");
    return nullptr;
}

// set the local IP and Port to bind to
// this must be set before CreateLocalUser()
void CSteamClient::SetLocalIPBinding( uint32 unIP, uint16 usPort )
{
    // TODO: Implement IP binding
    VLOG_DEBUG("SetLocalIPBinding called");
}

// returns the ISteamFriends interface
ISteamFriends *CSteamClient::GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamFriends called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamFriends: Invalid version string (null)");
        return nullptr;
    }

    // Get the Steam friends implementation instance
    if (!m_pSteamFriends) {
        VLOG_ERROR("GetISteamFriends: Steam friends not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamFriends*
    if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamFriends (latest) - %s", STEAMFRIENDS_INTERFACE_VERSION);
        return static_cast<ISteamFriends*>(m_pSteamFriends);
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_014) == 0) {
        VLOG_DEBUG("Returning ISteamFriends014");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends014*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_013) == 0) {
        VLOG_DEBUG("Returning ISteamFriends013");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends013*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_011) == 0) {
        VLOG_DEBUG("Returning ISteamFriends011");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends011*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_009) == 0) {
        VLOG_DEBUG("Returning ISteamFriends009");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends009*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamFriends007");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends007*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_006) == 0) {
        VLOG_DEBUG("Returning ISteamFriends006");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends006*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamFriends005");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends005*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamFriends004");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends004*>(m_pSteamFriends));
    } else if (strcmp(pchVersion, STEAMFRIENDS_INTERFACE_VERSION_003) == 0) {
        VLOG_DEBUG("Returning ISteamFriends003");
        return reinterpret_cast<ISteamFriends*>(static_cast<ISteamFriends003*>(m_pSteamFriends));
    } else {
        VLOG_WARNING("GetISteamFriends: Unknown interface version '%s', returning " STEAMFRIENDS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamFriends*>(m_pSteamFriends);
    }
}

// returns the ISteamUtils interface
ISteamUtils *CSteamClient::GetISteamUtils(HSteamPipe hSteamPipe, const char *pchVersion)
{
    VLOG_DEBUG("GetISteamUtils called - hSteamPipe=%u, pchVersion=%s", hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamUtils: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamUtils) {
        VLOG_ERROR("GetISteamUtils: Steam utils not available");
        return nullptr;
    }

    // Return the appropriate interface version
    if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamUtils (latest) - %s", STEAMUTILS_INTERFACE_VERSION);
        return static_cast<ISteamUtils*>(m_pSteamUtils);
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamUtils007");
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils007*>(m_pSteamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamUtils005");
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils005*>(m_pSteamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamUtils004");
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils004*>(m_pSteamUtils));
    } else if (strcmp(pchVersion, STEAMUTILS_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamUtils002");
        return reinterpret_cast<ISteamUtils*>(static_cast<ISteamUtils002*>(m_pSteamUtils));
    } else {
        VLOG_WARNING("GetISteamUtils: Unknown interface version '%s', returning " STEAMUTILS_INTERFACE_VERSION, pchVersion);
        return static_cast<ISteamUtils*>(m_pSteamUtils);
    }
}

// returns the ISteamMatchmaking interface
ISteamMatchmaking *CSteamClient::GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamMatchmaking called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamMatchmaking: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamMatchmaking) {
        VLOG_ERROR("GetISteamMatchmaking: Steam matchmaking not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamMatchmaking*
    if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking (latest) - %s", STEAMMATCHMAKING_INTERFACE_VERSION);
        return static_cast<ISteamMatchmaking*>(m_pSteamMatchmaking);
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_008) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking008");
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking008*>(m_pSteamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking007");
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking007*>(m_pSteamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_006) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking006");
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking006*>(m_pSteamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking004");
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking004*>(m_pSteamMatchmaking));
    } else if (strcmp(pchVersion, STEAMMATCHMAKING_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmaking002");
        return reinterpret_cast<ISteamMatchmaking*>(static_cast<ISteamMatchmaking002*>(m_pSteamMatchmaking));
    } else {
        VLOG_WARNING("GetISteamMatchmaking: Unknown interface version '%s', returning " STEAMMATCHMAKING_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMatchmaking*>(m_pSteamMatchmaking);
    }
}

// returns the ISteamContentServer interface
// Removed from Steam SDK v1.04, backward compatibility
ISteamContentServer *CSteamClient::GetISteamContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamContentServer called - DEPRECATED INTERFACE");
    return nullptr;
}

// returns the ISteamMasterServerUpdater interface
// Removed from Steam SDK v1.17, backward compatibility
ISteamMasterServerUpdater *CSteamClient::GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamMasterServerUpdater called - DEPRECATED INTERFACE");
    return nullptr;
}

// returns the ISteamMatchmakingServers interface
ISteamMatchmakingServers *CSteamClient::GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamMatchmakingServers called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamMatchmakingServers: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamMatchmakingServers) {
        VLOG_ERROR("GetISteamMatchmakingServers: Steam matchmaking servers not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamMatchmakingServers*
    if (strcmp(pchVersion, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmakingServers (latest) - %s", STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION);
        return static_cast<ISteamMatchmakingServers*>(m_pSteamMatchmakingServers);
    } else if (strcmp(pchVersion, STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamMatchmakingServers001");
        return reinterpret_cast<ISteamMatchmakingServers*>(static_cast<ISteamMatchmakingServers001*>(m_pSteamMatchmakingServers));
    } else {
        VLOG_WARNING("GetISteamMatchmakingServers: Unknown interface version '%s', returning " STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMatchmakingServers*>(m_pSteamMatchmakingServers);
    }
}

// returns the a generic interface
void *CSteamClient::GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement generic interface lookup
    VLOG_DEBUG("GetISteamGenericInterface called");
    return nullptr;
}

// returns the ISteamUserStats interface
ISteamUserStats *CSteamClient::GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamUserStats called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamUserStats: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamUserStats) {
        VLOG_ERROR("GetISteamUserStats: Steam user stats not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUserStats*
    if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats (latest) - %s", STEAMUSERSTATS_INTERFACE_VERSION);
        return static_cast<ISteamUserStats*>(m_pSteamUserStats);
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_010) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats010");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats010*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_009) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats009");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats009*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats007");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats007*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_006) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats006");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats006*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats005");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats005*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats004");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats004*>(m_pSteamUserStats));
    } else if (strcmp(pchVersion, STEAMUSERSTATS_INTERFACE_VERSION_003) == 0) {
        VLOG_DEBUG("Returning ISteamUserStats003");
        return reinterpret_cast<ISteamUserStats*>(static_cast<ISteamUserStats003*>(m_pSteamUserStats));
    } else {
        VLOG_WARNING("GetISteamUserStats: Unknown interface version '%s', returning " STEAMUSERSTATS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUserStats*>(m_pSteamUserStats);
    }
}

// returns the ISteamGameServerStats interface
ISteamGameServerStats *CSteamClient::GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamGameServerStats called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);
    // Game server stats interface - typically used by dedicated servers
    return nullptr;
}

// returns apps interface
ISteamApps *CSteamClient::GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamApps called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamApps: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamApps) {
        VLOG_ERROR("GetISteamApps: Steam apps not available");
        return nullptr;
    }

    // Return the appropriate interface version
    if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamApps (latest) - %s", STEAMAPPS_INTERFACE_VERSION);
        return static_cast<ISteamApps*>(m_pSteamApps);
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamApps007");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps007*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_006) == 0) {
        VLOG_DEBUG("Returning ISteamApps006");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps006*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamApps005");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps005*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamApps004");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps004*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_003) == 0) {
        VLOG_DEBUG("Returning ISteamApps003");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps003*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamApps002");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps002*>(m_pSteamApps));
    } else if (strcmp(pchVersion, STEAMAPPS_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamApps001");
        return reinterpret_cast<ISteamApps*>(static_cast<ISteamApps001*>(m_pSteamApps));
    } else {
        VLOG_WARNING("GetISteamApps: Unknown interface version '%s', returning " STEAMAPPS_INTERFACE_VERSION, pchVersion);
        return static_cast<ISteamApps*>(m_pSteamApps);
    }
}

// networking
ISteamNetworking *CSteamClient::GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
    VLOG_DEBUG("GetISteamNetworking called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamNetworking: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamNetworking) {
        VLOG_ERROR("GetISteamNetworking: Steam networking not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamNetworking*
    if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamNetworking (latest) - %s", STEAMNETWORKING_INTERFACE_VERSION);
        return static_cast<ISteamNetworking*>(m_pSteamNetworking);
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamNetworking004");
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking004*>(m_pSteamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_003) == 0) {
        VLOG_DEBUG("Returning ISteamNetworking003");
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking003*>(m_pSteamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamNetworking002");
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking002*>(m_pSteamNetworking));
    } else if (strcmp(pchVersion, STEAMNETWORKING_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamNetworking001");
        return reinterpret_cast<ISteamNetworking*>(static_cast<ISteamNetworking001*>(m_pSteamNetworking));
    } else {
        VLOG_WARNING("GetISteamNetworking: Unknown interface version '%s', returning " STEAMNETWORKING_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamNetworking*>(m_pSteamNetworking);
    }
}

// remote storage
ISteamRemoteStorage *CSteamClient::GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamRemoteStorage called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamRemoteStorage: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamRemoteStorage) {
        VLOG_ERROR("GetISteamRemoteStorage: Steam remote storage not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamRemoteStorage*
    if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage (latest) - %s", STEAMREMOTESTORAGE_INTERFACE_VERSION);
        return static_cast<ISteamRemoteStorage*>(m_pSteamRemoteStorage);
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_012) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage012");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage012*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_011) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage011");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage011*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_010) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage010");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage010*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_008) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage008");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage008*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_006) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage006");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage006*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage005");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage005*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_004) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage004");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage004*>(m_pSteamRemoteStorage));
    } else if (strcmp(pchVersion, STEAMREMOTESTORAGE_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamRemoteStorage002");
        return reinterpret_cast<ISteamRemoteStorage*>(static_cast<ISteamRemoteStorage002*>(m_pSteamRemoteStorage));
    } else {
        VLOG_WARNING("GetISteamRemoteStorage: Unknown interface version '%s', returning " STEAMREMOTESTORAGE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamRemoteStorage*>(m_pSteamRemoteStorage);
    }
}

// user screenshots
ISteamScreenshots *CSteamClient::GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamScreenshots called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamScreenshots: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamScreenshots) {
        VLOG_ERROR("GetISteamScreenshots: Steam screenshots not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamScreenshots*
    if (strcmp(pchVersion, STEAMSCREENSHOTS_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamScreenshots (latest) - %s", STEAMSCREENSHOTS_INTERFACE_VERSION);
        return static_cast<ISteamScreenshots*>(m_pSteamScreenshots);
    } else if (strcmp(pchVersion, STEAMSCREENSHOTS_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamScreenshots001");
        return reinterpret_cast<ISteamScreenshots*>(static_cast<ISteamScreenshots001*>(m_pSteamScreenshots));
    } else {
        VLOG_WARNING("GetISteamScreenshots: Unknown interface version '%s', returning " STEAMSCREENSHOTS_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamScreenshots*>(m_pSteamScreenshots);
    }
}

// Deprecated. Applications should use SteamAPI_RunCallbacks() or SteamGameServer_RunCallbacks() instead.
// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::RunFrame()
{
    // TODO: Implement frame processing
}

// returns the number of IPC calls made since the last time this function was called
// Used for perf debugging so you can understand how many IPC calls your game makes per frame
// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
// control how often you do them.
uint32 CSteamClient::GetIPCCallCount()
{
    // TODO: Implement IPC call count
    return 1;
}


// API warning handling
// 'int' is the severity; 0 for msg, 1 for warning
// 'const char *' is the text of the message
// callbacks will occur directly after the API function is called that generated the warning or message
void CSteamClient::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
    // TODO: Implement warning message hook
    VLOG_DEBUG("SetWarningMessageHook called");
} 

// Trigger global shutdown for the DLL
bool CSteamClient::BShutdownIfAllPipesClosed()
{
    VLOG_DEBUG("BShutdownIfAllPipesClosed called");

    if (m_mapSteamPipes.size() == 0) {
        VLOG_DEBUG("BShutdownIfAllPipesClosed called but no pipes are open");
    }
    
    // TODO: Implement shutdown logic

    return true;
}

// Expose HTTP interface
ISteamHTTP *CSteamClient::GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    VLOG_DEBUG("GetISteamHTTP called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamHTTP: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamHTTP) {
        VLOG_ERROR("GetISteamHTTP: Steam HTTP not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamHTTP*
    if (strcmp(pchVersion, STEAMHTTP_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamHTTP (latest) - %s", STEAMHTTP_INTERFACE_VERSION);
        return static_cast<ISteamHTTP*>(m_pSteamHTTP);
    } else if (strcmp(pchVersion, STEAMHTTP_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamHTTP001");
        return reinterpret_cast<ISteamHTTP*>(static_cast<ISteamHTTP001*>(m_pSteamHTTP));
    } else {
        VLOG_WARNING("GetISteamHTTP: Unknown interface version '%s', returning " STEAMHTTP_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamHTTP*>(m_pSteamHTTP);
    }
}

// Exposes the ISteamUnifiedMessages interface
ISteamUnifiedMessages* CSteamClient::GetISteamUnifiedMessages(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamUnifiedMessages called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamUnifiedMessages: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamUnifiedMessages) {
        VLOG_ERROR("GetISteamUnifiedMessages: Steam unified messages not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMUNIFIEDMESSAGES_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamUnifiedMessages (latest) - %s", STEAMUNIFIEDMESSAGES_INTERFACE_VERSION);
        return static_cast<ISteamUnifiedMessages*>(m_pSteamUnifiedMessages);
    } else {
        VLOG_WARNING("GetISteamUnifiedMessages: Unknown interface version '%s', returning " STEAMUNIFIEDMESSAGES_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUnifiedMessages*>(m_pSteamUnifiedMessages);
    }
}


// Exposes the ISteamController interface
ISteamController* CSteamClient::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamController called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamController: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamController) {
        VLOG_ERROR("GetISteamController: Steam controller not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamController*
    if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamController (latest) - %s", STEAMCONTROLLER_INTERFACE_VERSION);
        return static_cast<ISteamController*>(m_pSteamController);
    } else if (strcmp(pchVersion, STEAMCONTROLLER_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamController001");
        return reinterpret_cast<ISteamController*>(static_cast<ISteamController001*>(m_pSteamController));
    } else {
        VLOG_WARNING("GetISteamController: Unknown interface version '%s', returning " STEAMCONTROLLER_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamController*>(m_pSteamController);
    }
}

// Exposes the ISteamUGC interface 
ISteamUGC* CSteamClient::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamUGC called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamUGC: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamUGC) {
        VLOG_ERROR("GetISteamUGC: Steam UGC not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamUGC*
    if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamUGC (latest) - %s", STEAMUGC_INTERFACE_VERSION);
        return static_cast<ISteamUGC*>(m_pSteamUGC);
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_007) == 0) {
        VLOG_DEBUG("Returning ISteamUGC007");
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC007*>(m_pSteamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_005) == 0) {
        VLOG_DEBUG("Returning ISteamUGC005");
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC005*>(m_pSteamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_003) == 0) {
        VLOG_DEBUG("Returning ISteamUGC003");
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC003*>(m_pSteamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamUGC002");
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC002*>(m_pSteamUGC));
    } else if (strcmp(pchVersion, STEAMUGC_INTERFACE_VERSION_001) == 0) {
        VLOG_DEBUG("Returning ISteamUGC001");
        return reinterpret_cast<ISteamUGC*>(static_cast<ISteamUGC001*>(m_pSteamUGC));
    } else {
        VLOG_WARNING("GetISteamUGC: Unknown interface version '%s', returning " STEAMUGC_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamUGC*>(m_pSteamUGC);
    }
}

// returns app list interface, only available on specially registered apps
ISteamAppList* CSteamClient::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamAppList called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamUser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamAppList: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamAppList) {
        VLOG_ERROR("GetISteamAppList: Steam app list not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMAPPLIST_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamAppList (latest) - %s", STEAMAPPLIST_INTERFACE_VERSION);
        return static_cast<ISteamAppList*>(m_pSteamAppList);
    } else {
        VLOG_WARNING("GetISteamAppList: Unknown interface version '%s', returning " STEAMAPPLIST_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamAppList*>(m_pSteamAppList);
    }
}

// Music Player
ISteamMusic* CSteamClient::GetISteamMusic(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamMusic called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamMusic: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamMusic) {
        VLOG_ERROR("GetISteamMusic: Steam music not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMMUSIC_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamMusic (latest) - %s", STEAMMUSIC_INTERFACE_VERSION);
        return static_cast<ISteamMusic*>(m_pSteamMusic);
    } else {
        VLOG_WARNING("GetISteamMusic: Unknown interface version '%s', returning " STEAMMUSIC_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMusic*>(m_pSteamMusic);
    }
}

// Music Player Remote
ISteamMusicRemote* CSteamClient::GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamMusicRemote called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamMusicRemote: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamMusicRemote) {
        VLOG_ERROR("GetISteamMusicRemote: Steam music remote not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (001)
    if (strcmp(pchVersion, STEAMMUSICREMOTE_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamMusicRemote (latest) - %s", STEAMMUSICREMOTE_INTERFACE_VERSION);
        return static_cast<ISteamMusicRemote*>(m_pSteamMusicRemote);
    } else {
        VLOG_WARNING("GetISteamMusicRemote: Unknown interface version '%s', returning " STEAMMUSICREMOTE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamMusicRemote*>(m_pSteamMusicRemote);
    }
}

// html page display
ISteamHTMLSurface* CSteamClient::GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamHTMLSurface called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamHTMLSurface: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamHTMLSurface) {
        VLOG_ERROR("GetISteamHTMLSurface: Steam HTML surface not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // Cast to specific interface first for proper vtable mapping, then to ISteamHTMLSurface*
    if (strcmp(pchVersion, STEAMHTMLSURFACE_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamHTMLSurface (latest) - %s", STEAMHTMLSURFACE_INTERFACE_VERSION);
        return static_cast<ISteamHTMLSurface*>(m_pSteamHTMLSurface);
    } else if (strcmp(pchVersion, STEAMHTMLSURFACE_INTERFACE_VERSION_002) == 0) {
        VLOG_DEBUG("Returning ISteamHTMLSurface002");
        return reinterpret_cast<ISteamHTMLSurface*>(static_cast<ISteamHTMLSurface002*>(m_pSteamHTMLSurface));
    } else {
        VLOG_WARNING("GetISteamHTMLSurface: Unknown interface version '%s', returning " STEAMHTMLSURFACE_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamHTMLSurface*>(m_pSteamHTMLSurface);
    }
}

// Helper functions for internal Steam usage
// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Set_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_DEBUG("Set_SteamAPI_CPostAPIResultInProcess called");
}

// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Remove_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
{
    VLOG_DEBUG("Remove_SteamAPI_CPostAPIResultInProcess called");
}

// Changed from Steam SDK v1.36, backward compatibility
void CSteamClient::Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t func)
{
    VLOG_DEBUG("Set_SteamAPI_CCheckCallbackRegisteredInProcess called");
}

// inventory
ISteamInventory* CSteamClient::GetISteamInventory(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamInventory called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamInventory: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamInventory) {
        VLOG_ERROR("GetISteamInventory: Steam inventory not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (V001)
    if (strcmp(pchVersion, STEAMINVENTORY_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamInventory (latest) - %s", STEAMINVENTORY_INTERFACE_VERSION);
        return static_cast<ISteamInventory*>(m_pSteamInventory);
    } else {
        VLOG_WARNING("GetISteamInventory: Unknown interface version '%s', returning " STEAMINVENTORY_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamInventory*>(m_pSteamInventory);
    }
}

// Video
ISteamVideo* CSteamClient::GetISteamVideo(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    VLOG_DEBUG("GetISteamVideo called - hSteamUser=%u, hSteamPipe=%u, pchVersion=%s", hSteamuser, hSteamPipe, pchVersion);

    if (!pchVersion) {
        VLOG_ERROR("GetISteamVideo: Invalid version string (null)");
        return nullptr;
    }

    if (!m_pSteamVideo) {
        VLOG_ERROR("GetISteamVideo: Steam video not available");
        return nullptr;
    }

    // Return the appropriate interface version based on the version string
    // This interface only has one version (V001)
    if (strcmp(pchVersion, STEAMVIDEO_INTERFACE_VERSION) == 0) {
        VLOG_DEBUG("Returning ISteamVideo (latest) - %s", STEAMVIDEO_INTERFACE_VERSION);
        return static_cast<ISteamVideo*>(m_pSteamVideo);
    } else {
        VLOG_WARNING("GetISteamVideo: Unknown interface version '%s', returning " STEAMVIDEO_INTERFACE_VERSION, pchVersion);
        // Return the latest interface as fallback
        return static_cast<ISteamVideo*>(m_pSteamVideo);
    }
}
