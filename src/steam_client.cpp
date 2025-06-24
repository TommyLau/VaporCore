/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "vaporcore_base.h"
#include "logger.h"
#include "steam_client.h"

// Static instance
Steam_Client* Steam_Client::s_pInstance = nullptr;

Steam_Client::Steam_Client()
    : m_hSteamUser(1) // Start with user ID 1
    , m_unSteamPipeCounter(0)
    , m_pWarningMessageHook(nullptr)
    , m_pSteamUser(nullptr)
    , m_pSteamFriends(nullptr)
    , m_pSteamUtils(nullptr)
    , m_pSteamMatchmaking(nullptr)
    , m_pSteamMatchmakingServers(nullptr)
    , m_pSteamUserStats(nullptr)
    , m_pSteamApps(nullptr)
    , m_pSteamNetworking(nullptr)
    , m_pSteamContentServer(nullptr)
    , m_pSteamMasterServerUpdater(nullptr)
{
    VLOG_INFO("Steam_Client constructor called");
}

Steam_Client::~Steam_Client()
{
    VLOG_INFO("Steam_Client destructor called");
}

Steam_Client* Steam_Client::GetInstance()
{
    VAPORCORE_LOCK_GUARD();

    if (!s_pInstance) {
        s_pInstance = new Steam_Client();
    }

    return s_pInstance;
}

void Steam_Client::ReleaseInstance()
{
    VAPORCORE_LOCK_GUARD();
    
    if (s_pInstance) {
        VLOG_INFO("Releasing Steam_Client singleton instance");
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

const char* Steam_Client::GetInterfaceVersion(const char* pchVersion, const char* pchDefaultVersion)
{
    return pchVersion ? pchVersion : pchDefaultVersion;
}

// Creates a communication pipe to the Steam client
HSteamPipe Steam_Client::CreateSteamPipe()
{
    VLOG_DEBUG("CreateSteamPipe called");
    HSteamPipe hSteamPipe = m_unSteamPipeCounter++;
    m_mapSteamPipes[hSteamPipe] = Steam_Pipe::STEAM_PIPE_NONE;
    VLOG_DEBUG("CreateSteamPipe completed with hSteamPipe=%u", hSteamPipe);

    return hSteamPipe;
}

// Releases a previously created communications pipe
bool Steam_Client::BReleaseSteamPipe( HSteamPipe hSteamPipe )
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
HSteamUser Steam_Client::ConnectToGlobalUser( HSteamPipe hSteamPipe )
{
    VLOG_DEBUG("ConnectToGlobalUser called with hSteamPipe=%u", hSteamPipe);

    if (!m_mapSteamPipes.count(hSteamPipe)) {
        return 0;
    }

    // TODO: User Login

    m_mapSteamPipes[hSteamPipe] = Steam_Pipe::STEAM_PIPE_CLIENT;

    return VaporCore::DEFAULT_CLIENT_USER;
}

// used by game servers, create a steam user that won't be shared with anyone else
HSteamUser Steam_Client::CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType )
{
    // TODO: Implement local user creation
    VLOG_DEBUG("CreateLocalUser called with phSteamPipe=%u and eAccountType=%d", phSteamPipe, eAccountType);
    return VaporCore::DEFAULT_SERVER_USER;
}

// Changed from Steam SDK v1.04, backward compatibility
HSteamUser Steam_Client::CreateLocalUser( HSteamPipe *phSteamPipe )
{
    // TODO: Implement local user creation
    VLOG_DEBUG("CreateLocalUser called with phSteamPipe=%u", phSteamPipe);
    return VaporCore::DEFAULT_SERVER_USER;
}

// removes an allocated user
void Steam_Client::ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser )
{
    // TODO: Implement user release logic
    VLOG_DEBUG("ReleaseUser called");
}

// retrieves the ISteamUser interface associated with the handle
ISteamUser *Steam_Client::GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement user retrieval logic
    VLOG_DEBUG("GetISteamUser called");
    return nullptr;
}

// retrieves the ISteamGameServer interface associated with the handle
ISteamGameServer *Steam_Client::GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement game server interface
    VLOG_DEBUG("GetISteamGameServer called");
    return nullptr;
}

// set the local IP and Port to bind to
// this must be set before CreateLocalUser()
void Steam_Client::SetLocalIPBinding( uint32 unIP, uint16 usPort )
{
    // TODO: Implement IP binding
    VLOG_DEBUG("SetLocalIPBinding called");
}

// returns the ISteamFriends interface
ISteamFriends *Steam_Client::GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement friends interface
    VLOG_DEBUG("GetISteamFriends called");
    return nullptr;
}

// returns the ISteamUtils interface
ISteamUtils *Steam_Client::GetISteamUtils(HSteamPipe hSteamPipe, const char *pchVersion)
{
    // TODO: Implement utils interface
    VLOG_DEBUG("GetISteamUtils called");
    return nullptr;
}

// returns the ISteamMatchmaking interface
ISteamMatchmaking *Steam_Client::GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement matchmaking interface
    VLOG_DEBUG("GetISteamMatchmaking called");
    return nullptr;
}

// returns the ISteamContentServer interface
// Removed from Steam SDK v1.04, backward compatibility
ISteamContentServer *Steam_Client::GetISteamContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement content server interface
    VLOG_DEBUG("GetISteamContentServer called");
    return nullptr;
}

// returns the ISteamMasterServerUpdater interface
// Removed from Steam SDK v1.17, backward compatibility
ISteamMasterServerUpdater *Steam_Client::GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement master server updater interface
    VLOG_DEBUG("GetISteamMasterServerUpdater called");
    return nullptr;
}

// returns the ISteamMatchmakingServers interface
ISteamMatchmakingServers *Steam_Client::GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement matchmaking servers interface
    VLOG_DEBUG("GetISteamMatchmakingServers called");
    return nullptr;
}

// returns the a generic interface
void *Steam_Client::GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement generic interface lookup
    VLOG_DEBUG("GetISteamGenericInterface called");
    return nullptr;
}

// returns the ISteamUserStats interface
ISteamUserStats *Steam_Client::GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement user stats interface
    VLOG_DEBUG("GetISteamUserStats called");
    return nullptr;
}

// returns the ISteamGameServerStats interface
ISteamGameServerStats *Steam_Client::GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement game server stats interface
    VLOG_DEBUG("GetISteamGameServerStats called");
    return nullptr;
}

// returns apps interface
ISteamApps *Steam_Client::GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement apps interface
    VLOG_DEBUG("GetISteamApps called");
    return nullptr;
}

// networking
ISteamNetworking *Steam_Client::GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
    // TODO: Implement networking interface
    VLOG_DEBUG("GetISteamNetworking called");
    return nullptr;
}

// remote storage
ISteamRemoteStorage *Steam_Client::GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement remote storage interface
    VLOG_DEBUG("GetISteamRemoteStorage called");
    return nullptr;
}

// user screenshots
ISteamScreenshots *Steam_Client::GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement screenshots interface
    VLOG_DEBUG("GetISteamScreenshots called");
    return nullptr;
}

// this needs to be called every frame to process matchmaking results
// redundant if you're already calling SteamAPI_RunCallbacks()
void Steam_Client::RunFrame()
{
    // TODO: Implement frame processing
}

// returns the number of IPC calls made since the last time this function was called
// Used for perf debugging so you can understand how many IPC calls your game makes per frame
// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
// control how often you do them.
uint32 Steam_Client::GetIPCCallCount()
{
    // TODO: Implement IPC call count
    return 1;
}


// API warning handling
// 'int' is the severity; 0 for msg, 1 for warning
// 'const char *' is the text of the message
// callbacks will occur directly after the API function is called that generated the warning or message
void Steam_Client::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
    // TODO: Implement warning message hook
    VLOG_DEBUG("SetWarningMessageHook called");
} 

// Trigger global shutdown for the DLL
bool Steam_Client::BShutdownIfAllPipesClosed()
{
    // TODO: Implement shutdown logic
    VLOG_DEBUG("BShutdownIfAllPipesClosed called");
    return true;
}

// Expose HTTP interface
ISteamHTTP *Steam_Client::GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
    // TODO: Implement HTTP interface
    VLOG_DEBUG("GetISteamHTTP called");
    return nullptr;
}

// Exposes the ISteamUnifiedMessages interface
ISteamUnifiedMessages* Steam_Client::GetISteamUnifiedMessages(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement unified messages interface
    VLOG_DEBUG("GetISteamUnifiedMessages called");
    return nullptr;
}


// Exposes the ISteamController interface
ISteamController* Steam_Client::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement controller interface
    VLOG_DEBUG("GetISteamController called");
    return nullptr;
}

// Exposes the ISteamUGC interface 
ISteamUGC* Steam_Client::GetISteamUGC(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement UGC interface
    VLOG_DEBUG("GetISteamUGC called");
    return nullptr;
}

// returns app list interface, only available on specially registered apps
ISteamAppList* Steam_Client::GetISteamAppList(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement app list interface
    VLOG_DEBUG("GetISteamAppList called");
    return nullptr;
}

// Music Player
ISteamMusic* Steam_Client::GetISteamMusic(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement music interface
    VLOG_DEBUG("GetISteamMusic called");
    return nullptr;
}

// Music Player Remote
ISteamMusicRemote* Steam_Client::GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
{
    // TODO: Implement music remote interface
    VLOG_DEBUG("GetISteamMusicRemote called");
    return nullptr;
}
