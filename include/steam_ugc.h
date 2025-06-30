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
#include <isteamugc002.h>
#include <isteamugc003.h>
#include <isteamugc005.h>
#include <isteamugc007.h>
#include <isteamugc008.h>

//-----------------------------------------------------------------------------
// Purpose: Steam UGC support API
//-----------------------------------------------------------------------------
class CSteamUGC :
    public ISteamUGC,
    public ISteamUGC001,
    public ISteamUGC002,
    public ISteamUGC003,
    public ISteamUGC005,
    public ISteamUGC007,
    public ISteamUGC008
{
public:
	// Singleton accessor
    static CSteamUGC& GetInstance()
	{
		static CSteamUGC instance;
		return instance;
	}

public:
	// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
	UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) override;

	// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
	UGCQueryHandle_t CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) override;

	// Query for the details of the given published file ids (the RequestUGCDetails call is deprecated and replaced with this)
	UGCQueryHandle_t CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) override;

	// Send the query to Steam
	CALL_RESULT( SteamUGCQueryCompleted_t )
	SteamAPICall_t SendQueryUGCRequest( UGCQueryHandle_t handle ) override;

	// Retrieve an individual result after receiving the callback for querying UGC
	bool GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails ) override;
	bool GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchURLSize) char *pchURL, uint32 cchURLSize ) override;
	bool GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchMetadatasize) char *pchMetadata, uint32 cchMetadatasize ) override;
	bool GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) override;
	bool GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 *pStatValue ) override;
	// Changed from Steam SDK v1.38a, backward compatibility
	bool GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint32 *pStatValue ) override;
	uint32 GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index ) override;
	bool GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, OUT_STRING_COUNT(cchURLSize) char *pchURLOrVideoID, uint32 cchURLSize, OUT_STRING_COUNT(cchURLSize) char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType ) override;
	// Changed from Steam SDK v1.37, backward compatibility
	bool GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, OUT_STRING_COUNT(cchURLSize) char *pchURLOrVideoID, uint32 cchURLSize, bool *pbIsImage ) override;
	uint32 GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index ) override;
	bool GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, OUT_STRING_COUNT(cchKeySize) char *pchKey, uint32 cchKeySize, OUT_STRING_COUNT(cchValueSize) char *pchValue, uint32 cchValueSize ) override;

	// Release the request to free up memory, after retrieving results
	bool ReleaseQueryUGCRequest( UGCQueryHandle_t handle ) override;

	// Options to set for querying UGC
	bool AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName ) override;
	bool AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName ) override;
	bool SetReturnOnlyIDs( UGCQueryHandle_t handle, bool bReturnOnlyIDs ) override;
	bool SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags ) override;
	bool SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription ) override;
	bool SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata ) override;
	bool SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren ) override;
	bool SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews ) override;
	bool SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly ) override;
	bool SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage ) override;
	bool SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds ) override;

	// Options only for querying user UGC
	bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) override;

	// Options only for querying all UGC
	bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) override;
	bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) override;
	bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) override;
	bool AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue ) override;

	// Request full details for one piece of UGC
	// DEPRECATED - Use CreateQueryUGCDetailsRequest call above instead!
	SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds ) override;
	// Changed from Steam SDK v1.29a, backward compatibility
	SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID ) override;

	// Steam Workshop Creator API
	CALL_RESULT( CreateItemResult_t )
	SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType ) override; // create new item for this app with no content attached yet

	UGCUpdateHandle_t StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID ) override; // start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()

	bool SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle ) override; // change the title of an UGC item
	bool SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription ) override; // change the description of an UGC item
	bool SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage ) override; // specify the language of the title or description that will be set
	bool SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData ) override; // change the metadata of an UGC item (max = k_cchDeveloperMetadataMax)
	bool SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility ) override; // change the visibility of an UGC item
	bool SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags ) override; // change the tags of an UGC item
	bool SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder ) override; // update item content from this local folder
	bool SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile ) override; //  change preview image file for this item. pszPreviewFile points to local image file, which must be under 1MB in size
	bool RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey ) override; // remove any existing key-value tags with the specified key
	bool AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue ) override; // add new key-value tags for the item. Note that there can be multiple values for a tag.
	bool AddItemPreviewFile( UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type ) override; //  add preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
	bool AddItemPreviewVideo( UGCUpdateHandle_t handle, const char *pszVideoID ) override; //  add preview video for this item
	bool UpdateItemPreviewFile( UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile ) override; //  updates an existing preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
	bool UpdateItemPreviewVideo( UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID ) override; //  updates an existing preview video for this item
	bool RemoveItemPreview( UGCUpdateHandle_t handle, uint32 index ) override; // remove a preview by index starting at 0 (previews are sorted)

	CALL_RESULT( SubmitItemUpdateResult_t )
	SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote ) override; // commit update process started with StartItemUpdate()
	EItemUpdateStatus GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal ) override;

	// Steam Workshop Consumer API
	CALL_RESULT( SetUserItemVoteResult_t )
	SteamAPICall_t SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp ) override;
	CALL_RESULT( GetUserItemVoteResult_t )
	SteamAPICall_t GetUserItemVote( PublishedFileId_t nPublishedFileID ) override;
	CALL_RESULT( UserFavoriteItemsListChanged_t )
	SteamAPICall_t AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID ) override;
	CALL_RESULT( UserFavoriteItemsListChanged_t )
	SteamAPICall_t RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID ) override;
	CALL_RESULT( RemoteStorageSubscribePublishedFileResult_t )
	SteamAPICall_t SubscribeItem( PublishedFileId_t nPublishedFileID ) override; // subscribe to this item, will be installed ASAP
	CALL_RESULT( RemoteStorageUnsubscribePublishedFileResult_t )
	SteamAPICall_t UnsubscribeItem( PublishedFileId_t nPublishedFileID ) override; // unsubscribe from this item, will be uninstalled after game quits
	uint32 GetNumSubscribedItems() override; // number of subscribed items 
	uint32 GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) override; // all subscribed item PublishFileIDs

	// get EItemState flags about item on this client
	uint32 GetItemState( PublishedFileId_t nPublishedFileID ) override;

	// get info about currently installed content on disc for items that have k_EItemStateInstalled set
	// if k_EItemStateLegacyItem is set, pchFolder contains the path to the legacy file itself (not a folder)
	bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, OUT_STRING_COUNT( cchFolderSize ) char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp ) override;
	// Get info about the item on disk.  If you are supporting items published through the legacy RemoteStorage APIs then *pbLegacyItem will be set to true
	// and pchFolder will contain the full path to the file rather than the containing folder.
	// Changed from Steam SDK v1.33, backward compatibility
	bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, bool *pbLegacyItem ) override; // returns true if item is installed
	// Changed from Steam SDK v1.31, backward compatibility
	bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize ) override; // returns true if item is installed

	// get info about pending update for items that have k_EItemStateNeedsUpdate set. punBytesTotal will be valid after download started once
	bool GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) override;

	// Removed from Steam SDK v1.31, backward compatibility
	bool GetItemUpdateInfo( PublishedFileId_t nPublishedFileID, bool *pbNeedsUpdate, bool *pbIsDownloading, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) override;

	// download new or update already installed item. If function returns true, wait for DownloadItemResult_t. If the item is already installed,
	// then files on disk should not be used until callback received. If item is not subscribed to, it will be cached for some time.
	// If bHighPriority is set, any other item download will be suspended and this item downloaded ASAP.
	bool DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority ) override;

	// game servers can set a specific workshop folder before issuing any UGC commands.
	// This is helpful if you want to support multiple game servers running out of the same install folder
	bool BInitWorkshopForGameServer( DepotId_t unWorkshopDepotID, const char *pszFolder ) override;

	// SuspendDownloads( true ) will suspend all workshop downloads until SuspendDownloads( false ) is called or the game ends
	void SuspendDownloads( bool bSuspend ) override;

	// usage tracking
	CALL_RESULT( StartPlaytimeTrackingResult_t )
	SteamAPICall_t StartPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) override;
	CALL_RESULT( StopPlaytimeTrackingResult_t )
	SteamAPICall_t StopPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) override;
	CALL_RESULT( StopPlaytimeTrackingResult_t )
	SteamAPICall_t StopPlaytimeTrackingForAllItems() override;

private:
    // Private constructor and destructor for singleton
    CSteamUGC();
    ~CSteamUGC();

    // Delete copy constructor and assignment operator
    CSteamUGC(const CSteamUGC&) = delete;
    CSteamUGC& operator=(const CSteamUGC&) = delete;
};

#endif // VAPORCORE_STEAM_UGC_H
