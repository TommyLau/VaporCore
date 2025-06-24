/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef ISTEAMAPPS001_H
#define ISTEAMAPPS001_H
#ifdef _WIN32
#pragma once
#endif

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
class ISteamApps001
{
public:
	// returns 0 if the key does not exist
	// this may be true on first call, since the app data may not be cached locally yet
	// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
	virtual int GetAppData( AppId_t nAppID, const char *pchKey, char *pchValue, int cchValueMax ) = 0;
};

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"

//-----------------------------------------------------------------------------
// Purpose: called when new information about an app has arrived
//-----------------------------------------------------------------------------
struct AppDataChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 1 };
	uint32	m_nAppID;		// appid that changed
	bool	m_bBySteamUI;	// change came from SteamUI
	bool	m_bCDDBUpdate;	// the cddb entry for this app changed
};

#endif // ISTEAMAPPS001_H
