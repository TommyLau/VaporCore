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
#include "steam_apps.h"

// Static instance
CSteamApps* CSteamApps::s_pInstance = nullptr;

CSteamApps::CSteamApps()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamApps::~CSteamApps()
{
    VLOG_INFO(__FUNCTION__);
}

// Helper methods
CSteamApps* CSteamApps::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamApps();
    }
    return s_pInstance;
}

void CSteamApps::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// returns 0 if the key does not exist
// this may be true on first call, since the app data may not be cached locally yet
// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
// Removed from Steam SDK v1.01, backward compatibility
int CSteamApps::GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Key: %s", nAppID, pchKey ? pchKey : "null");
    
    if (!pchKey || !pchValue || cchValueMax <= 0)
    {
        return 0;
    }
    
    // Return empty string for now - can be extended later
    pchValue[0] = '\0';
    return 0;
}

bool CSteamApps::BIsSubscribed()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamApps::BIsLowViolence()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamApps::BIsCybercafe()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

bool CSteamApps::BIsVACBanned()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

const char *CSteamApps::GetCurrentGameLanguage()
{
    VLOG_INFO(__FUNCTION__);
    return VaporCore::Config::GetInstance()->GetLanguage().c_str();
}

const char *CSteamApps::GetAvailableGameLanguages()
{
    VLOG_INFO(__FUNCTION__);
    return nullptr;
}

// only use this member if you need to check ownership of another game related to yours, a demo for example
bool CSteamApps::BIsSubscribedApp( AppId_t appID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", appID);
    return false;
}

// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
bool CSteamApps::BIsDlcInstalled( AppId_t appID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", appID);
    return false;
}

// returns the Unix time of the purchase of the app
uint32 CSteamApps::GetEarliestPurchaseUnixTime( AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", nAppID);
    return 0;
}

// Checks if the user is subscribed to the current app through a free weekend
// This function will return false for users who have a retail or other type of license
// Before using, please ask your Valve technical contact how to package and secure your free weekened
bool CSteamApps::BIsSubscribedFromFreeWeekend()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Returns the number of DLC pieces for the running app
int CSteamApps::GetDLCCount()
{
    return 0;
}

// Returns metadata for DLC by index, of range [0, GetDLCCount()]
bool CSteamApps::BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - DLC Index: %d, AppID: %p, Available: %p, Name: %p, NameBufferSize: %d", 
               iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
    return false;
}

// Install/Uninstall control for optional DLC
void CSteamApps::InstallDLC( AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", nAppID);
}

void CSteamApps::UninstallDLC( AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", nAppID);
}

// Request legacy cd-key for yourself or owned DLC. If you are interested in this
// data then make sure you provide us with a list of valid keys to be distributed
// to users when they purchase the game, before the game ships.
// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
// the key is available (which may be immediately).
void CSteamApps::RequestAppProofOfPurchaseKey( AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", nAppID);
}

bool CSteamApps::GetCurrentBetaName( char *pchName, int cchNameBufferSize ) // returns current beta branch name, 'public' is the default branch
{
    VLOG_INFO(__FUNCTION__ " - Name: %p, NameBufferSize: %d", pchName, cchNameBufferSize);
    if (pchName && cchNameBufferSize > 0)
    {
        strncpy(pchName, "public", cchNameBufferSize);
        return true;
    }
    return false;
}

bool CSteamApps::MarkContentCorrupt( bool bMissingFilesOnly ) // signal Steam that game files seems corrupt or missing
{
    VLOG_INFO(__FUNCTION__ " - MissingFilesOnly: %d", bMissingFilesOnly);
    return false;
}
	
// return installed depots in mount order
uint32 CSteamApps::GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Depots: %p, MaxDepots: %u", appID, pvecDepots, cMaxDepots);
    return 0;
}

// Changed from Steam SDK v1.26, backward compatibility
uint32 CSteamApps::GetInstalledDepots( DepotId_t *pvecDepots, uint32 cMaxDepots )
{
    VLOG_INFO(__FUNCTION__ " - Depots: %p, MaxDepots: %u", pvecDepots, cMaxDepots);
    return 0;
}

// returns current app install folder for AppID, returns folder name length
uint32 CSteamApps::GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, Folder: %p, FolderBufferSize: %u", appID, pchFolder, cchFolderBufferSize);
    return 0;
}

bool CSteamApps::BIsAppInstalled( AppId_t appID )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u", appID);
    return false;
}

// returns the SteamID of the original owner. If different from current user, it's borrowed
CSteamID CSteamApps::GetAppOwner()
{
    VLOG_INFO(__FUNCTION__);
    return CSteamID();
}

// Returns the associated launch param if the game is run via steam://run/<appid>//?param1=value1;param2=value2;param3=value3 etc.
// Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
// Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
// but it is advised that you not param names beginning with an underscore for your own features.
const char *CSteamApps::GetLaunchQueryParam( const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - Key: %s", pchKey);
    return "";
}

// get download progress for optional DLC
bool CSteamApps::GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_INFO(__FUNCTION__ " - AppID: %u, BytesDownloaded: %p, BytesTotal: %p", nAppID, punBytesDownloaded, punBytesTotal);
    return false;
}

// return the buildid of this app, may change at any time based on backend updates to the game
int CSteamApps::GetAppBuildId()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Request all proof of purchase keys for the calling appid and asociated DLC.
// A series of AppProofOfPurchaseKeyResponse_t callbacks will be sent with
// appropriate appid values, ending with a final callback where the m_nAppId
// member is k_uAppIdInvalid (zero).
void CSteamApps::RequestAllProofOfPurchaseKeys()
{
    VLOG_INFO(__FUNCTION__);
}
