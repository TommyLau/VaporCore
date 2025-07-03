/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_APPS_H
#define VAPORCORE_STEAM_APPS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamapps.h>
#include <isteamapps001.h>
#include <isteamapps002.h>
#include <isteamapps003.h>
#include <isteamapps004.h>
#include <isteamapps005.h>
#include <isteamapps006.h>
#include <isteamapps007.h>

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
class CSteamApps :
    public ISteamApps,
    public ISteamApps001,
    public ISteamApps002,
    public ISteamApps003,
    public ISteamApps004,
    public ISteamApps005,
    public ISteamApps006,
    public ISteamApps007
{
public:
	// Singleton accessor
    static CSteamApps& GetInstance()
	{
		static CSteamApps instance;
		return instance;
	}

public:
	// returns 0 if the key does not exist
	// this may be true on first call, since the app data may not be cached locally yet
	// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
    // Removed from Steam SDK v1.01, backward compatibility
	int GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax ) override;

    bool BIsSubscribed() override;
    bool BIsLowViolence() override;
    bool BIsCybercafe() override;
    bool BIsVACBanned() override;
    const char *GetCurrentGameLanguage() override;
    const char *GetAvailableGameLanguages() override;

	// only use this member if you need to check ownership of another game related to yours, a demo for example
    bool BIsSubscribedApp( AppId_t appID ) override;

	// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
	bool BIsDlcInstalled( AppId_t appID ) override;

	// returns the Unix time of the purchase of the app
	uint32 GetEarliestPurchaseUnixTime( AppId_t nAppID ) override;

	// Checks if the user is subscribed to the current app through a free weekend
	// This function will return false for users who have a retail or other type of license
	// Before using, please ask your Valve technical contact how to package and secure your free weekened
	bool BIsSubscribedFromFreeWeekend() override;

	// Returns the number of DLC pieces for the running app
	int GetDLCCount() override;

	// Returns metadata for DLC by index, of range [0, GetDLCCount()]
	bool BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize ) override;

	// Install/Uninstall control for optional DLC
	void InstallDLC( AppId_t nAppID ) override;
	void UninstallDLC( AppId_t nAppID ) override;

	// Request legacy cd-key for yourself or owned DLC. If you are interested in this
	// data then make sure you provide us with a list of valid keys to be distributed
	// to users when they purchase the game, before the game ships.
	// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
	// the key is available (which may be immediately).
	void RequestAppProofOfPurchaseKey( AppId_t nAppID ) override;

	bool GetCurrentBetaName( char *pchName, int cchNameBufferSize ) override; // returns current beta branch name, 'public' is the default branch
	bool MarkContentCorrupt( bool bMissingFilesOnly ) override; // signal Steam that game files seems corrupt or missing
	uint32 GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots ) override; // return installed depots in mount order
	// Changed from Steam SDK v1.26, backward compatibility
	uint32 GetInstalledDepots( DepotId_t *pvecDepots, uint32 cMaxDepots ) override; // return installed depots in mount order

	// returns current app install folder for AppID, returns folder name length
	uint32 GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize ) override;
	bool BIsAppInstalled( AppId_t appID ) override; // returns true if that app is installed (not necessarily owned)

	// returns the SteamID of the original owner. If this CSteamID is different from ISteamUser::GetSteamID(),
	// the user has a temporary license borrowed via Family Sharing
	CSteamID GetAppOwner() override;

	// Returns the associated launch param if the game is run via steam://run/<appid>//?param1=value1&param2=value2&param3=value3 etc.
	// Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
	// Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
	// but it is advised that you not param names beginning with an underscore for your own features.
	// Check for new launch parameters on callback NewUrlLaunchParameters_t
	const char *GetLaunchQueryParam( const char *pchKey ) override;

	// get download progress for optional DLC
	bool GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) override; 

	// return the buildid of this app, may change at any time based on backend updates to the game
	int GetAppBuildId() override;

	// Request all proof of purchase keys for the calling appid and asociated DLC.
	// A series of AppProofOfPurchaseKeyResponse_t callbacks will be sent with
	// appropriate appid values, ending with a final callback where the m_nAppId
	// member is k_uAppIdInvalid (zero).
	void RequestAllProofOfPurchaseKeys() override;

	STEAM_CALL_RESULT( FileDetailsResult_t )
	SteamAPICall_t GetFileDetails( const char* pszFileName ) override;

	// Get command line if game was launched via Steam URL, e.g. steam://run/<appid>//<command line>/.
	// This method of passing a connect string (used when joining via rich presence, accepting an
	// invite, etc) is preferable to passing the connect string on the operating system command
	// line, which is a security risk.  In order for rich presence joins to go through this
	// path and not be placed on the OS command line, you must set a value in your app's
	// configuration on Steam.  Ask Valve for help with this.
	//
	// If game was already running and launched again, the NewUrlLaunchParameters_t will be fired.
	int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine ) override;

	// Check if user borrowed this game via Family Sharing, If true, call GetAppOwner() to get the lender SteamID
	bool BIsSubscribedFromFamilySharing() override;

private:
    // Private constructor and destructor for singleton
    CSteamApps();
    ~CSteamApps();

    // Delete copy constructor and assignment operator
    CSteamApps(const CSteamApps&) = delete;
    CSteamApps& operator=(const CSteamApps&) = delete;
};

#endif // VAPORCORE_STEAM_APPS_H
