
/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_ugc.h"
#include "logger.h"

// Static instance
Steam_UGC* Steam_UGC::s_pInstance = nullptr;

Steam_UGC::Steam_UGC()
{
    VLOG_INFO("Steam_UGC constructor called");
}

Steam_UGC::~Steam_UGC()
{
    VLOG_INFO("Steam_UGC destructor called");
}

// Helper methods
Steam_UGC* Steam_UGC::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_UGC();
    }
    return s_pInstance;
}

void Steam_UGC::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t Steam_UGC::CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_DEBUG("CreateQueryUserUGCRequest called");
    return k_UGCQueryHandleInvalid;
}

// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t Steam_UGC::CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_DEBUG("CreateQueryAllUGCRequest called");
    return k_UGCQueryHandleInvalid;
}

// Query for the details of the given published file ids (the RequestUGCDetails call is deprecated and replaced with this)
UGCQueryHandle_t Steam_UGC::CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_DEBUG("CreateQueryUGCDetailsRequest called");
    return k_UGCQueryHandleInvalid;
}

// Send the query to Steam
SteamAPICall_t Steam_UGC::SendQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_DEBUG("SendQueryUGCRequest called");
    return 0;
}

// Retrieve an individual result after receiving the callback for querying UGC
bool Steam_UGC::GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails )
{
    VLOG_DEBUG("GetQueryUGCResult called");
    return false;
}

bool Steam_UGC::GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, char *pchURL, uint32 cchURLSize )
{
    VLOG_DEBUG("GetQueryUGCPreviewURL called");
    return false;
}

bool Steam_UGC::GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, char *pchMetadata, uint32 cchMetadatasize )
{
    VLOG_DEBUG("GetQueryUGCMetadata called");
    return false;
}

bool Steam_UGC::GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_DEBUG("GetQueryUGCChildren called");
    return false;
}

bool Steam_UGC::GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint32 *pStatValue )
{
    VLOG_DEBUG("GetQueryUGCStatistic called");
    return false;
}

uint32 Steam_UGC::GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_DEBUG("GetQueryUGCNumAdditionalPreviews called");
    return 0;
}

bool Steam_UGC::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char *pchURLOrVideoID, uint32 cchURLSize, bool *pbIsImage )
{
    VLOG_DEBUG("GetQueryUGCAdditionalPreview called");
    return false;
}

uint32 Steam_UGC::GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_DEBUG("GetQueryUGCNumKeyValueTags called");
    return 0;
}

bool Steam_UGC::GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, char *pchKey, uint32 cchKeySize, char *pchValue, uint32 cchValueSize )
{
    VLOG_DEBUG("GetQueryUGCKeyValueTag called");
    return false;
}

// Release the request to free up memory, after retrieving results
bool Steam_UGC::ReleaseQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_DEBUG("ReleaseQueryUGCRequest called");
    return false;
}

// Options to set for querying UGC
bool Steam_UGC::AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_DEBUG("AddRequiredTag called");
    return false;
}

bool Steam_UGC::AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_DEBUG("AddExcludedTag called");
    return false;
}

bool Steam_UGC::SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags )
{
    VLOG_DEBUG("SetReturnKeyValueTags called");
    return false;
}

bool Steam_UGC::SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription )
{
    VLOG_DEBUG("SetReturnLongDescription called");
    return false;
}

bool Steam_UGC::SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata )
{
    VLOG_DEBUG("SetReturnMetadata called");
    return false;
}

bool Steam_UGC::SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren )
{
    VLOG_DEBUG("SetReturnChildren called");
    return false;
}

bool Steam_UGC::SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews )
{
    VLOG_DEBUG("SetReturnAdditionalPreviews called");
    return false;
}

bool Steam_UGC::SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
    VLOG_DEBUG("SetReturnTotalOnly called");
    return false;
}

bool Steam_UGC::SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage )
{
    VLOG_DEBUG("SetLanguage called");
    return false;
}

bool Steam_UGC::SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds )
{
    VLOG_DEBUG("SetAllowCachedResponse called");
    return false;
}

// Options only for querying user UGC
bool Steam_UGC::SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName )
{
    VLOG_DEBUG("SetCloudFileNameFilter called");
    return false;
}

// Options only for querying all UGC
bool Steam_UGC::SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag )
{
    VLOG_DEBUG("SetMatchAnyTag called");
    return false;
}

bool Steam_UGC::SetSearchText( UGCQueryHandle_t handle, const char *pSearchText )
{
    VLOG_DEBUG("SetSearchText called");
    return false;
}

bool Steam_UGC::SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_DEBUG("SetRankedByTrendDays called");
    return false;
}

bool Steam_UGC::AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue )
{
    VLOG_DEBUG("AddRequiredKeyValueTag called");
    return false;
}

// Request full details for one piece of UGC
// DEPRECATED - Use CreateQueryUGCDetailsRequest call above instead!
SteamAPICall_t Steam_UGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds )
{
    VLOG_DEBUG("RequestUGCDetails called");
    return 0;
}

// Changed from Steam SDK v1.29a, backward compatibility
SteamAPICall_t Steam_UGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("RequestUGCDetails called");
    return 0;
}


// Steam Workshop Creator API

// create new item for this app with no content attached yet
SteamAPICall_t Steam_UGC::CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType )
{
    VLOG_DEBUG("CreateItem called");
    return 0;
}

// start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()
UGCUpdateHandle_t Steam_UGC::StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("StartItemUpdate called");
    return k_UGCUpdateHandleInvalid;
}

// change the title of an UGC item
bool Steam_UGC::SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle )
{
    VLOG_DEBUG("SetItemTitle called");
    return false;
}

// change the description of an UGC item
bool Steam_UGC::SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription )
{
    VLOG_DEBUG("SetItemDescription called");
    return false;
}

// specify the language of the title or description that will be set
bool Steam_UGC::SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage )
{
    VLOG_DEBUG("SetItemUpdateLanguage called");
    return false;
}

// change the metadata of an UGC item (max = k_cchDeveloperMetadataMax)
bool Steam_UGC::SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData )
{
    VLOG_DEBUG("SetItemMetadata called");
    return false;
}

// change the visibility of an UGC item
bool Steam_UGC::SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_DEBUG("SetItemVisibility called");
    return false;
}

// change the tags of an UGC item
bool Steam_UGC::SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("SetItemTags called");
    return false;
}

// update item content from this local folder
bool Steam_UGC::SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder )
{
    VLOG_DEBUG("SetItemContent called");
    return false;
}

// change preview image file for this item. pszPreviewFile points to local image file, which must be under 1MB in size
bool Steam_UGC::SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile )
{
    VLOG_DEBUG("SetItemPreview called");
    return false;
}

// remove any existing key-value tags with the specified key
bool Steam_UGC::RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey )
{
    VLOG_DEBUG("RemoveItemKeyValueTags called");
    return false;
}

// add new key-value tags for the item. Note that there can be multiple values for a tag.
bool Steam_UGC::AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("AddItemKeyValueTag called");
    return false;
}

// commit update process started with StartItemUpdate()
SteamAPICall_t Steam_UGC::SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote )
{
    VLOG_DEBUG("SubmitItemUpdate called");
    return 0;
}

EItemUpdateStatus Steam_UGC::GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal )
{
    VLOG_DEBUG("GetItemUpdateProgress called");
    return k_EItemUpdateStatusInvalid;
}

// Steam Workshop Consumer API

SteamAPICall_t Steam_UGC::SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp )
{
    VLOG_DEBUG("SetUserItemVote called");
    return 0;
}

SteamAPICall_t Steam_UGC::GetUserItemVote( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("GetUserItemVote called");
    return 0;
}

SteamAPICall_t Steam_UGC::AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("AddItemToFavorites called");
    return 0;
}

SteamAPICall_t Steam_UGC::RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("RemoveItemFromFavorites called");
    return 0;
}

// subscribe to this item, will be installed ASAP
SteamAPICall_t Steam_UGC::SubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("SubscribeItem called");
    return 0;
}

// unsubscribe from this item, will be uninstalled after game quits
SteamAPICall_t Steam_UGC::UnsubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("UnsubscribeItem called");
    return 0;
}

// number of subscribed items
uint32 Steam_UGC::GetNumSubscribedItems()
{
    VLOG_DEBUG("GetNumSubscribedItems called");
    return 0;
}

// all subscribed item PublishFileIDs
uint32 Steam_UGC::GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_DEBUG("GetSubscribedItems called");
    return 0;
}

// get EItemState flags about item on this client
uint32 Steam_UGC::GetItemState( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("GetItemState called");
    return 0;
}

// get info about currently installed content on disc for items that have k_EItemStateInstalled set
// if k_EItemStateLegacyItem is set, pchFolder contains the path to the legacy file itself (not a folder)
bool Steam_UGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// Get info about the item on disk.  If you are supporting items published through the legacy RemoteStorage APIs then *pbLegacyItem will be set to true
// and pchFolder will contain the full path to the file rather than the containing folder.
// Changed from Steam SDK v1.33, backward compatibility
bool Steam_UGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, bool *pbLegacyItem )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// Changed from Steam SDK v1.31, backward compatibility
bool Steam_UGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// get info about pending update for items that have k_EItemStateNeedsUpdate set. punBytesTotal will be valid after download started once
bool Steam_UGC::GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_DEBUG("GetItemDownloadInfo called");
    return false;
}

// Removed from Steam SDK v1.31, backward compatibility
bool Steam_UGC::GetItemUpdateInfo( PublishedFileId_t nPublishedFileID, bool *pbNeedsUpdate, bool *pbIsDownloading, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_DEBUG("GetItemUpdateInfo called");
    return false;
}

// download new or update already installed item. If function returns true, wait for DownloadItemResult_t. If the item is already installed,
// then files on disk should not be used until callback received. If item is not subscribed to, it will be cached for some time.
// If bHighPriority is set, any other item download will be suspended and this item downloaded ASAP.
bool Steam_UGC::DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority )
{
    VLOG_DEBUG("DownloadItem called");
    return false;
}
