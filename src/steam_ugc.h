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
#include <isteamugc001.h>

//-----------------------------------------------------------------------------
// Purpose: Steam UGC support API
//-----------------------------------------------------------------------------
class Steam_UGC :
    public ISteamUGC,
    public ISteamUGC001
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

	// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
	UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) override;

	// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
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
	bool SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds ) override;

	// Options only for querying user UGC
	bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) override;

	// Options only for querying all UGC
	bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) override;
	bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) override;
	bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) override;

	// Request full details for one piece of UGC
	SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds ) override;
	// Changed from Steam SDK v1.29a, backward compatibility
	SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID ) override;

	// Steam Workshop Creator API
	SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType ) override; // create new item for this app with no content attached yet

	UGCUpdateHandle_t StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID ) override; // start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()

	bool SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle ) override; // change the title of an UGC item
	bool SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription ) override; // change the description of an UGC item
	bool SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility ) override; // change the visibility of an UGC item
	bool SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags ) override; // change the tags of an UGC item
	bool SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder ) override; // update item content from this local folder
	bool SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile ) override; //  change preview image file for this item. pszPreviewFile points to local image file 

	SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote ) override; // commit update process started with StartItemUpdate()
	EItemUpdateStatus GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal ) override;

	// Steam Workshop Consumer API
	SteamAPICall_t SubscribeItem( PublishedFileId_t nPublishedFileID ) override; // subscript to this item, will be installed ASAP
	SteamAPICall_t UnsubscribeItem( PublishedFileId_t nPublishedFileID ) override; // unsubscribe from this item, will be uninstalled after game quits
	uint32 GetNumSubscribedItems() override; // number of subscribed items 
	uint32 GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) override; // all subscribed item PublishFileIDs

	bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize ) override; // returns true if item is installed
	bool GetItemUpdateInfo( PublishedFileId_t nPublishedFileID, bool *pbNeedsUpdate, bool *pbIsDownloading, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) override;
};

#endif // VAPORCORE_STEAM_UGC_H
