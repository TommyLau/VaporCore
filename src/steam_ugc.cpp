
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
#include "steam_ugc.h"

// Static instance
CSteamUGC* CSteamUGC::s_pInstance = nullptr;

CSteamUGC::CSteamUGC()
{
    VLOG_INFO("CSteamUGC constructor called");
}

CSteamUGC::~CSteamUGC()
{
    VLOG_INFO("CSteamUGC destructor called");
}

// Helper methods
CSteamUGC* CSteamUGC::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamUGC();
    }
    return s_pInstance;
}

void CSteamUGC::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t CSteamUGC::CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_DEBUG("CreateQueryUserUGCRequest called");
    return k_UGCQueryHandleInvalid;
}

// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t CSteamUGC::CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_DEBUG("CreateQueryAllUGCRequest called");
    return k_UGCQueryHandleInvalid;
}

// Query for the details of the given published file ids (the RequestUGCDetails call is deprecated and replaced with this)
UGCQueryHandle_t CSteamUGC::CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_DEBUG("CreateQueryUGCDetailsRequest called");
    return k_UGCQueryHandleInvalid;
}

// Send the query to Steam
SteamAPICall_t CSteamUGC::SendQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_DEBUG("SendQueryUGCRequest called");
    return 0;
}

// Retrieve an individual result after receiving the callback for querying UGC
bool CSteamUGC::GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails )
{
    VLOG_DEBUG("GetQueryUGCResult called");
    return false;
}

bool CSteamUGC::GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, char *pchURL, uint32 cchURLSize )
{
    VLOG_DEBUG("GetQueryUGCPreviewURL called");
    return false;
}

bool CSteamUGC::GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, char *pchMetadata, uint32 cchMetadatasize )
{
    VLOG_DEBUG("GetQueryUGCMetadata called");
    return false;
}

bool CSteamUGC::GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_DEBUG("GetQueryUGCChildren called");
    return false;
}

bool CSteamUGC::GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint32 *pStatValue )
{
    VLOG_DEBUG("GetQueryUGCStatistic called");
    return false;
}

uint32 CSteamUGC::GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_DEBUG("GetQueryUGCNumAdditionalPreviews called");
    return 0;
}

bool CSteamUGC::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char *pchURLOrVideoID, uint32 cchURLSize, char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType )
{
    VLOG_DEBUG("GetQueryUGCAdditionalPreview called");
    return false;
}

// Changed from Steam SDK v1.37, backward compatibility
bool CSteamUGC::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char *pchURLOrVideoID, uint32 cchURLSize, bool *pbIsImage )
{
    VLOG_DEBUG("GetQueryUGCAdditionalPreview called");
    return false;
}

uint32 CSteamUGC::GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_DEBUG("GetQueryUGCNumKeyValueTags called");
    return 0;
}

bool CSteamUGC::GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, char *pchKey, uint32 cchKeySize, char *pchValue, uint32 cchValueSize )
{
    VLOG_DEBUG("GetQueryUGCKeyValueTag called");
    return false;
}

// Release the request to free up memory, after retrieving results
bool CSteamUGC::ReleaseQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_DEBUG("ReleaseQueryUGCRequest called");
    return false;
}

// Options to set for querying UGC
bool CSteamUGC::AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_DEBUG("AddRequiredTag called");
    return false;
}

bool CSteamUGC::AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_DEBUG("AddExcludedTag called");
    return false;
}

bool CSteamUGC::SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags )
{
    VLOG_DEBUG("SetReturnKeyValueTags called");
    return false;
}

bool CSteamUGC::SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription )
{
    VLOG_DEBUG("SetReturnLongDescription called");
    return false;
}

bool CSteamUGC::SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata )
{
    VLOG_DEBUG("SetReturnMetadata called");
    return false;
}

bool CSteamUGC::SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren )
{
    VLOG_DEBUG("SetReturnChildren called");
    return false;
}

bool CSteamUGC::SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews )
{
    VLOG_DEBUG("SetReturnAdditionalPreviews called");
    return false;
}

bool CSteamUGC::SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
    VLOG_DEBUG("SetReturnTotalOnly called");
    return false;
}

bool CSteamUGC::SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage )
{
    VLOG_DEBUG("SetLanguage called");
    return false;
}

bool CSteamUGC::SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds )
{
    VLOG_DEBUG("SetAllowCachedResponse called");
    return false;
}

// Options only for querying user UGC
bool CSteamUGC::SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName )
{
    VLOG_DEBUG("SetCloudFileNameFilter called");
    return false;
}

// Options only for querying all UGC
bool CSteamUGC::SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag )
{
    VLOG_DEBUG("SetMatchAnyTag called");
    return false;
}

bool CSteamUGC::SetSearchText( UGCQueryHandle_t handle, const char *pSearchText )
{
    VLOG_DEBUG("SetSearchText called");
    return false;
}

bool CSteamUGC::SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_DEBUG("SetRankedByTrendDays called");
    return false;
}

bool CSteamUGC::AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue )
{
    VLOG_DEBUG("AddRequiredKeyValueTag called");
    return false;
}

// Request full details for one piece of UGC
// DEPRECATED - Use CreateQueryUGCDetailsRequest call above instead!
SteamAPICall_t CSteamUGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds )
{
    VLOG_DEBUG("RequestUGCDetails called");
    return 0;
}

// Changed from Steam SDK v1.29a, backward compatibility
SteamAPICall_t CSteamUGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("RequestUGCDetails called");
    return 0;
}


// Steam Workshop Creator API

// create new item for this app with no content attached yet
SteamAPICall_t CSteamUGC::CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType )
{
    VLOG_DEBUG("CreateItem called");
    return 0;
}

// start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()
UGCUpdateHandle_t CSteamUGC::StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("StartItemUpdate called");
    return k_UGCUpdateHandleInvalid;
}

// change the title of an UGC item
bool CSteamUGC::SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle )
{
    VLOG_DEBUG("SetItemTitle called");
    return false;
}

// change the description of an UGC item
bool CSteamUGC::SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription )
{
    VLOG_DEBUG("SetItemDescription called");
    return false;
}

// specify the language of the title or description that will be set
bool CSteamUGC::SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage )
{
    VLOG_DEBUG("SetItemUpdateLanguage called");
    return false;
}

// change the metadata of an UGC item (max = k_cchDeveloperMetadataMax)
bool CSteamUGC::SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData )
{
    VLOG_DEBUG("SetItemMetadata called");
    return false;
}

// change the visibility of an UGC item
bool CSteamUGC::SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_DEBUG("SetItemVisibility called");
    return false;
}

// change the tags of an UGC item
bool CSteamUGC::SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("SetItemTags called");
    return false;
}

// update item content from this local folder
bool CSteamUGC::SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder )
{
    VLOG_DEBUG("SetItemContent called");
    return false;
}

// change preview image file for this item. pszPreviewFile points to local image file, which must be under 1MB in size
bool CSteamUGC::SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile )
{
    VLOG_DEBUG("SetItemPreview called");
    return false;
}

// remove any existing key-value tags with the specified key
bool CSteamUGC::RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey )
{
    VLOG_DEBUG("RemoveItemKeyValueTags called");
    return false;
}

// add new key-value tags for the item. Note that there can be multiple values for a tag.
bool CSteamUGC::AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("AddItemKeyValueTag called");
    return false;
}

// add preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
bool CSteamUGC::AddItemPreviewFile( UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type )
{
    VLOG_DEBUG("AddItemPreviewFile called");
    return false;
}

// add preview video for this item
bool CSteamUGC::AddItemPreviewVideo( UGCUpdateHandle_t handle, const char *pszVideoID )
{
    VLOG_DEBUG("AddItemPreviewVideo called");
    return false;
}

// updates an existing preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
bool CSteamUGC::UpdateItemPreviewFile( UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile )
{
    VLOG_DEBUG("UpdateItemPreviewFile called");
    return false;
}

// updates an existing preview video for this item
bool CSteamUGC::UpdateItemPreviewVideo( UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID )
{
    VLOG_DEBUG("UpdateItemPreviewVideo called");
    return false;
}

// remove a preview by index starting at 0 (previews are sorted)
bool CSteamUGC::RemoveItemPreview( UGCUpdateHandle_t handle, uint32 index )
{
    VLOG_DEBUG("RemoveItemPreview called");
    return false;
}

// commit update process started with StartItemUpdate()
SteamAPICall_t CSteamUGC::SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote )
{
    VLOG_DEBUG("SubmitItemUpdate called");
    return 0;
}

EItemUpdateStatus CSteamUGC::GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal )
{
    VLOG_DEBUG("GetItemUpdateProgress called");
    return k_EItemUpdateStatusInvalid;
}

// Steam Workshop Consumer API

SteamAPICall_t CSteamUGC::SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp )
{
    VLOG_DEBUG("SetUserItemVote called");
    return 0;
}

SteamAPICall_t CSteamUGC::GetUserItemVote( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("GetUserItemVote called");
    return 0;
}

SteamAPICall_t CSteamUGC::AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("AddItemToFavorites called");
    return 0;
}

SteamAPICall_t CSteamUGC::RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("RemoveItemFromFavorites called");
    return 0;
}

// subscribe to this item, will be installed ASAP
SteamAPICall_t CSteamUGC::SubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("SubscribeItem called");
    return 0;
}

// unsubscribe from this item, will be uninstalled after game quits
SteamAPICall_t CSteamUGC::UnsubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("UnsubscribeItem called");
    return 0;
}

// number of subscribed items
uint32 CSteamUGC::GetNumSubscribedItems()
{
    VLOG_DEBUG("GetNumSubscribedItems called");
    return 0;
}

// all subscribed item PublishFileIDs
uint32 CSteamUGC::GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_DEBUG("GetSubscribedItems called");
    return 0;
}

// get EItemState flags about item on this client
uint32 CSteamUGC::GetItemState( PublishedFileId_t nPublishedFileID )
{
    VLOG_DEBUG("GetItemState called");
    return 0;
}

// get info about currently installed content on disc for items that have k_EItemStateInstalled set
// if k_EItemStateLegacyItem is set, pchFolder contains the path to the legacy file itself (not a folder)
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// Get info about the item on disk.  If you are supporting items published through the legacy RemoteStorage APIs then *pbLegacyItem will be set to true
// and pchFolder will contain the full path to the file rather than the containing folder.
// Changed from Steam SDK v1.33, backward compatibility
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, bool *pbLegacyItem )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// Changed from Steam SDK v1.31, backward compatibility
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize )
{
    VLOG_DEBUG("GetItemInstallInfo called");
    return false;
}

// get info about pending update for items that have k_EItemStateNeedsUpdate set. punBytesTotal will be valid after download started once
bool CSteamUGC::GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_DEBUG("GetItemDownloadInfo called");
    return false;
}

// Removed from Steam SDK v1.31, backward compatibility
bool CSteamUGC::GetItemUpdateInfo( PublishedFileId_t nPublishedFileID, bool *pbNeedsUpdate, bool *pbIsDownloading, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_DEBUG("GetItemUpdateInfo called");
    return false;
}

// download new or update already installed item. If function returns true, wait for DownloadItemResult_t. If the item is already installed,
// then files on disk should not be used until callback received. If item is not subscribed to, it will be cached for some time.
// If bHighPriority is set, any other item download will be suspended and this item downloaded ASAP.
bool CSteamUGC::DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority )
{
    VLOG_DEBUG("DownloadItem called");
    return false;
}

// game servers can set a specific workshop folder before issuing any UGC commands.
// This is helpful if you want to support multiple game servers running out of the same install folder
bool CSteamUGC::BInitWorkshopForGameServer( DepotId_t unWorkshopDepotID, const char *pszFolder )
{
    VLOG_DEBUG("BInitWorkshopForGameServer called");
    return false;
}

// SuspendDownloads( true ) will suspend all workshop downloads until SuspendDownloads( false ) is called or the game ends
void CSteamUGC::SuspendDownloads( bool bSuspend )
{
    VLOG_DEBUG("SuspendDownloads called");
}
