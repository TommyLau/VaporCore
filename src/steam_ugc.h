/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_UGC_H
#define VAPORCORE_STEAM_UGC_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamremotestorage.h>
#include <isteamugc.h>

//-----------------------------------------------------------------------------
// Purpose: Steam UGC support API
//-----------------------------------------------------------------------------
class Steam_UGC :
    public ISteamUGC
{
private:
    // Singleton instance
    static Steam_UGC* s_pInstance;

public:
    Steam_UGC();
    ~Steam_UGC();

    // Helper methods
    static Steam_UGC* GetInstance();
    static void ReleaseInstance();

	// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app.
	UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) override;

	// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app.
	UGCQueryHandle_t CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) override;

	// Send the query to Steam
	SteamAPICall_t SendQueryUGCRequest( UGCQueryHandle_t handle ) override;

	// Retrieve an individual result after receiving the callback for querying UGC
	bool GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails ) override;

	// Release the request to free up memory, after retrieving results
	bool ReleaseQueryUGCRequest( UGCQueryHandle_t handle ) override;

	// Options to set for querying UGC
	bool AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName ) override;
	bool AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName ) override;
	bool SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription ) override;
	bool SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly ) override;

	// Options only for querying user UGC
	bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) override;

	// Options only for querying all UGC
	bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) override;
	bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) override;
	bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) override;

	// Request full details for one piece of UGC
	SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID ) override;

};

#endif // VAPORCORE_STEAM_UGC_H
