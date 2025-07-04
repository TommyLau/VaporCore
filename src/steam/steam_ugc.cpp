
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

CSteamUGC::CSteamUGC()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamUGC::~CSteamUGC()
{
    VLOG_INFO(__FUNCTION__);
}

// Query UGC associated with a user. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t CSteamUGC::CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_INFO(__FUNCTION__ " - unAccountID: %d, eListType: %d, eMatchingUGCType: %d, eSortOrder: %d, nCreatorAppID: %d, nConsumerAppID: %d, unPage: %d", unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
    return k_UGCQueryHandleInvalid;
}

// Query for all matching UGC. Creator app id or consumer app id must be valid and be set to the current running app. unPage should start at 1.
UGCQueryHandle_t CSteamUGC::CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
    VLOG_INFO(__FUNCTION__ " - eQueryType: %d, eMatchingeMatchingUGCTypeFileType: %d, nCreatorAppID: %d, nConsumerAppID: %d, unPage: %d", eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
    return k_UGCQueryHandleInvalid;
}

// Query for all matching UGC using the new deep paging interface. Creator app id or consumer app id must be valid and be set to the current running app. pchCursor should be set to NULL or "*" to get the first result set.
UGCQueryHandle_t CSteamUGC::CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, const char* pchCursor)
{
    VLOG_INFO(__FUNCTION__ " - eQueryType: %d, eMatchingeMatchingUGCTypeFileType: %d, nCreatorAppID: %d, nConsumerAppID: %d, pchCursor: %s", eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, pchCursor ? pchCursor : "NULL");
    return k_UGCQueryHandleInvalid;
}

// Query for the details of the given published file ids (the RequestUGCDetails call is deprecated and replaced with this)
UGCQueryHandle_t CSteamUGC::CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__ " - pvecPublishedFileID: %p, unNumPublishedFileIDs: %d", pvecPublishedFileID, unNumPublishedFileIDs);
    return k_UGCQueryHandleInvalid;
}

// Send the query to Steam
STEAM_CALL_RESULT( SteamUGCQueryCompleted_t )
SteamAPICall_t CSteamUGC::SendQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d", handle);
    return 0;
}

// Retrieve an individual result after receiving the callback for querying UGC
bool CSteamUGC::GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, pDetails: %p", handle, index, pDetails);
    return false;
}

bool CSteamUGC::GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, char *pchURL, uint32 cchURLSize )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, pchURL: %p, cchURLSize: %d", handle, index, pchURL, cchURLSize);
    return false;
}

bool CSteamUGC::GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, char *pchMetadata, uint32 cchMetadatasize )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, pchMetadata: %p, cchMetadatasize: %d", handle, index, pchMetadata, cchMetadatasize);
    return false;
}

bool CSteamUGC::GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, pvecPublishedFileID: %p, cMaxEntries: %d", handle, index, pvecPublishedFileID, cMaxEntries);
    return false;
}

bool CSteamUGC::GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 *pStatValue )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, eStatType: %d, pStatValue: %p", handle, index, eStatType, pStatValue);
    return false;
}

// Changed from Steam SDK v1.38a, backward compatibility
bool CSteamUGC::GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint32 *pStatValue )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, eStatType: %d, pStatValue: %p", handle, index, eStatType, pStatValue);
    return false;
}

uint32 CSteamUGC::GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d", handle, index);
    return 0;
}

bool CSteamUGC::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char *pchURLOrVideoID, uint32 cchURLSize, char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, previewIndex: %d", handle, index, previewIndex);
    return false;
}

// Changed from Steam SDK v1.37, backward compatibility
bool CSteamUGC::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char *pchURLOrVideoID, uint32 cchURLSize, bool *pbIsImage )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, previewIndex: %d", handle, index, previewIndex);
    return false;
}

uint32 CSteamUGC::GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d", handle, index);
    return 0;
}

bool CSteamUGC::GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, char *pchKey, uint32 cchKeySize, char *pchValue, uint32 cchValueSize )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, keyValueTagIndex: %d", handle, index, keyValueTagIndex);
    return false;
}

// Return the first value matching the pchKey. Note that a key may map to multiple values.  Returns false if there was an error or no matching value was found.
bool CSteamUGC::GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, const char *pchKey, STEAM_OUT_STRING_COUNT(cchValueSize) char *pchValue, uint32 cchValueSize )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, index: %d, pchKey: %s, cchValueSize: %d", handle, index, pchKey ? pchKey : "NULL", cchValueSize);
    return false;
}

// Release the request to free up memory, after retrieving results
bool CSteamUGC::ReleaseQueryUGCRequest( UGCQueryHandle_t handle )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d", handle);
    return false;
}

// Options to set for querying UGC
bool CSteamUGC::AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pTagName: %s", handle, pTagName ? pTagName : "NULL");
    return false;
}

// match any of the tags in this group
bool CSteamUGC::AddRequiredTagGroup( UGCQueryHandle_t handle, const SteamParamStringArray_t *pTagGroups )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pTagGroups: %p", handle, pTagGroups);
    return false;
}

bool CSteamUGC::AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pTagName: %s", handle, pTagName ? pTagName : "NULL");
    return false;
}

bool CSteamUGC::SetReturnOnlyIDs( UGCQueryHandle_t handle, bool bReturnOnlyIDs )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnOnlyIDs: %s", handle, bReturnOnlyIDs ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnKeyValueTags: %s", handle, bReturnKeyValueTags ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnLongDescription: %s", handle, bReturnLongDescription ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnMetadata: %s", handle, bReturnMetadata ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnChildren: %s", handle, bReturnChildren ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnAdditionalPreviews: %s", handle, bReturnAdditionalPreviews ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bReturnTotalOnly: %s", handle, bReturnTotalOnly ? "true" : "false");
    return false;
}

bool CSteamUGC::SetReturnPlaytimeStats( UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, unDays: %d", handle, unDays);
    return false;
}

bool CSteamUGC::SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pchLanguage: %s", handle, pchLanguage ? pchLanguage : "NULL");
    return false;
}

bool CSteamUGC::SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, unMaxAgeSeconds: %d", handle, unMaxAgeSeconds);
    return false;
}

// Options only for querying user UGC
bool CSteamUGC::SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pMatchCloudFileName: %s", handle, pMatchCloudFileName ? pMatchCloudFileName : "NULL");
    return false;
}

// Options only for querying all UGC
bool CSteamUGC::SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, bMatchAnyTag: %s", handle, bMatchAnyTag ? "true" : "false");
    return false;
}

bool CSteamUGC::SetSearchText( UGCQueryHandle_t handle, const char *pSearchText )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pSearchText: %s", handle, pSearchText ? pSearchText : "NULL");
    return false;
}

bool CSteamUGC::SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, unDays: %d", handle, unDays);
    return false;
}

bool CSteamUGC::AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue )
{
    VLOG_INFO(__FUNCTION__ " - handle: %d, pKey: %s, pValue: %s", handle, pKey ? pKey : "NULL", pValue ? pValue : "NULL");
    return false;
}

// Request full details for one piece of UGC
// DEPRECATED - Use CreateQueryUGCDetailsRequest call above instead!
SteamAPICall_t CSteamUGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, unMaxAgeSeconds: %d", nPublishedFileID, unMaxAgeSeconds);
    return 0;
}

// Changed from Steam SDK v1.29a, backward compatibility
SteamAPICall_t CSteamUGC::RequestUGCDetails( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}


// Steam Workshop Creator API

// create new item for this app with no content attached yet
STEAM_CALL_RESULT( CreateItemResult_t )
SteamAPICall_t CSteamUGC::CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType )
{
    VLOG_INFO(__FUNCTION__ " - nConsumerAppId: %d, eFileType: %d", nConsumerAppId, eFileType);
    return 0;
}

// start an UGC item update. Set changed properties before commiting update with CommitItemUpdate()
UGCUpdateHandle_t CSteamUGC::StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nConsumerAppId: %d, nPublishedFileID: %llu", nConsumerAppId, nPublishedFileID);
    return k_UGCUpdateHandleInvalid;
}

// change the title of an UGC item
bool CSteamUGC::SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchTitle: %s", handle, pchTitle ? pchTitle : "NULL");
    return false;
}

// change the description of an UGC item
bool CSteamUGC::SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchDescription: %s", handle, pchDescription ? pchDescription : "NULL");
    return false;
}

// specify the language of the title or description that will be set
bool CSteamUGC::SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchLanguage: %s", handle, pchLanguage ? pchLanguage : "NULL");
    return false;
}

// change the metadata of an UGC item (max = k_cchDeveloperMetadataMax)
bool CSteamUGC::SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchMetaData: %s", handle, pchMetaData ? pchMetaData : "NULL");
    return false;
}

// change the visibility of an UGC item
bool CSteamUGC::SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, eVisibility: %d", handle, eVisibility);
    return false;
}

// change the tags of an UGC item
bool CSteamUGC::SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags )
{
    VLOG_INFO(__FUNCTION__ " - updateHandle: %llu, pTags: %p", updateHandle, pTags);
    return false;
}

// update item content from this local folder
bool CSteamUGC::SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pszContentFolder: %s", handle, pszContentFolder ? pszContentFolder : "NULL");
    return false;
}

// change preview image file for this item. pszPreviewFile points to local image file, which must be under 1MB in size
bool CSteamUGC::SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pszPreviewFile: %s", handle, pszPreviewFile ? pszPreviewFile : "NULL");
    return false;
}

//  use legacy upload for a single small file. The parameter to SetItemContent() should either be a directory with one file or the full path to the file.  The file must also be less than 10MB in size.
bool CSteamUGC::SetAllowLegacyUpload( UGCUpdateHandle_t handle, bool bAllowLegacyUpload )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, bAllowLegacyUpload: %d", handle, bAllowLegacyUpload);
    return false;
}

// remove all existing key-value tags (you can add new ones via the AddItemKeyValueTag function)
bool CSteamUGC::RemoveAllItemKeyValueTags( UGCUpdateHandle_t handle )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu", handle);
    return false;
}

// remove any existing key-value tags with the specified key
bool CSteamUGC::RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchKey: %s", handle, pchKey ? pchKey : "NULL");
    return false;
}

// add new key-value tags for the item. Note that there can be multiple values for a tag.
bool CSteamUGC::AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchKey: %s, pchValue: %s", handle, pchKey ? pchKey : "NULL", pchValue ? pchValue : "NULL");
    return false;
}

// add preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
bool CSteamUGC::AddItemPreviewFile( UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pszPreviewFile: %s, type: %d", handle, pszPreviewFile ? pszPreviewFile : "NULL", type);
    return false;
}

// add preview video for this item
bool CSteamUGC::AddItemPreviewVideo( UGCUpdateHandle_t handle, const char *pszVideoID )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pszVideoID: %s", handle, pszVideoID ? pszVideoID : "NULL");
    return false;
}

// updates an existing preview file for this item. pszPreviewFile points to local file, which must be under 1MB in size
bool CSteamUGC::UpdateItemPreviewFile( UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, index: %d, pszPreviewFile: %s", handle, index, pszPreviewFile ? pszPreviewFile : "NULL");
    return false;
}

// updates an existing preview video for this item
bool CSteamUGC::UpdateItemPreviewVideo( UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, index: %d, pszVideoID: %s", handle, index, pszVideoID ? pszVideoID : "NULL");
    return false;
}

// remove a preview by index starting at 0 (previews are sorted)
bool CSteamUGC::RemoveItemPreview( UGCUpdateHandle_t handle, uint32 index )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, index: %d", handle, index);
    return false;
}

// commit update process started with StartItemUpdate()
STEAM_CALL_RESULT( SubmitItemUpdateResult_t )
SteamAPICall_t CSteamUGC::SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, pchChangeNote: %s", handle, pchChangeNote ? pchChangeNote : "NULL");
    return 0;
}

EItemUpdateStatus CSteamUGC::GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal )
{
    VLOG_INFO(__FUNCTION__ " - handle: %llu, punBytesProcessed: %p, punBytesTotal: %p", handle, punBytesProcessed, punBytesTotal);
    return k_EItemUpdateStatusInvalid;
}

// Steam Workshop Consumer API
STEAM_CALL_RESULT( SetUserItemVoteResult_t )
SteamAPICall_t CSteamUGC::SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, bVoteUp: %s", nPublishedFileID, bVoteUp ? "true" : "false");
    return 0;
}

STEAM_CALL_RESULT( GetUserItemVoteResult_t )
SteamAPICall_t CSteamUGC::GetUserItemVote( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}

STEAM_CALL_RESULT( UserFavoriteItemsListChanged_t )
SteamAPICall_t CSteamUGC::AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nAppId: %d, nPublishedFileID: %llu", nAppId, nPublishedFileID);
    return 0;
}

STEAM_CALL_RESULT( UserFavoriteItemsListChanged_t )
SteamAPICall_t CSteamUGC::RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nAppId: %d, nPublishedFileID: %llu", nAppId, nPublishedFileID);
    return 0;
}

// subscribe to this item, will be installed ASAP
STEAM_CALL_RESULT( RemoteStorageSubscribePublishedFileResult_t )
SteamAPICall_t CSteamUGC::SubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}

// unsubscribe from this item, will be uninstalled after game quits
STEAM_CALL_RESULT( RemoteStorageUnsubscribePublishedFileResult_t )
SteamAPICall_t CSteamUGC::UnsubscribeItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}

// number of subscribed items
uint32 CSteamUGC::GetNumSubscribedItems()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// all subscribed item PublishFileIDs
uint32 CSteamUGC::GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
    VLOG_INFO(__FUNCTION__ " - pvecPublishedFileID: %p, cMaxEntries: %d", pvecPublishedFileID, cMaxEntries);
    return 0;
}

// get EItemState flags about item on this client
uint32 CSteamUGC::GetItemState( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}

// get info about currently installed content on disc for items that have k_EItemStateInstalled set
// if k_EItemStateLegacyItem is set, pchFolder contains the path to the legacy file itself (not a folder)
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, punSizeOnDisk: %p, pchFolder: %p, cchFolderSize: %d, punTimeStamp: %p", nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
    return false;
}

// Get info about the item on disk.  If you are supporting items published through the legacy RemoteStorage APIs then *pbLegacyItem will be set to true
// and pchFolder will contain the full path to the file rather than the containing folder.
// Changed from Steam SDK v1.33, backward compatibility
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, bool *pbLegacyItem )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, punSizeOnDisk: %p, pchFolder: %p, cchFolderSize: %d, pbLegacyItem: %p", nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, pbLegacyItem);
    return false;
}

// Changed from Steam SDK v1.31, backward compatibility
bool CSteamUGC::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, punSizeOnDisk: %p, pchFolder: %p, cchFolderSize: %d", nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize);
    return false;
}

// get info about pending update for items that have k_EItemStateNeedsUpdate set. punBytesTotal will be valid after download started once
bool CSteamUGC::GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, punBytesDownloaded: %p, punBytesTotal: %p", nPublishedFileID, punBytesDownloaded, punBytesTotal);
    return false;
}

// Removed from Steam SDK v1.31, backward compatibility
bool CSteamUGC::GetItemUpdateInfo( PublishedFileId_t nPublishedFileID, bool *pbNeedsUpdate, bool *pbIsDownloading, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, pbNeedsUpdate: %p, pbIsDownloading: %p, punBytesDownloaded: %p, punBytesTotal: %p", nPublishedFileID, pbNeedsUpdate, pbIsDownloading, punBytesDownloaded, punBytesTotal);
    return false;
}

// download new or update already installed item. If function returns true, wait for DownloadItemResult_t. If the item is already installed,
// then files on disk should not be used until callback received. If item is not subscribed to, it will be cached for some time.
// If bHighPriority is set, any other item download will be suspended and this item downloaded ASAP.
bool CSteamUGC::DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, bHighPriority: %s", nPublishedFileID, bHighPriority ? "true" : "false");
    return false;
}

// game servers can set a specific workshop folder before issuing any UGC commands.
// This is helpful if you want to support multiple game servers running out of the same install folder
bool CSteamUGC::BInitWorkshopForGameServer( DepotId_t unWorkshopDepotID, const char *pszFolder )
{
    VLOG_INFO(__FUNCTION__ " - unWorkshopDepotID: %d, pszFolder: %s", unWorkshopDepotID, pszFolder ? pszFolder : "NULL");
    return false;
}

// SuspendDownloads( true ) will suspend all workshop downloads until SuspendDownloads( false ) is called or the game ends
void CSteamUGC::SuspendDownloads( bool bSuspend )
{
    VLOG_INFO(__FUNCTION__ " - bSuspend: %s", bSuspend ? "true" : "false");
}

// usage tracking
STEAM_CALL_RESULT( StartPlaytimeTrackingResult_t )
SteamAPICall_t CSteamUGC::StartPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__ " - pvecPublishedFileID: %p, unNumPublishedFileIDs: %d", pvecPublishedFileID, unNumPublishedFileIDs);
    return 0;
}

STEAM_CALL_RESULT( StopPlaytimeTrackingResult_t )
SteamAPICall_t CSteamUGC::StopPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
    VLOG_INFO(__FUNCTION__ " - pvecPublishedFileID: %p, unNumPublishedFileIDs: %d", pvecPublishedFileID, unNumPublishedFileIDs);
    return 0;
}

STEAM_CALL_RESULT( StopPlaytimeTrackingResult_t )
SteamAPICall_t CSteamUGC::StopPlaytimeTrackingForAllItems()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// parent-child relationship or dependency management
STEAM_CALL_RESULT( AddUGCDependencyResult_t )
SteamAPICall_t CSteamUGC::AddDependency( PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nParentPublishedFileID: %llu, nChildPublishedFileID: %llu", nParentPublishedFileID, nChildPublishedFileID);
    return 0;
}

STEAM_CALL_RESULT( RemoveUGCDependencyResult_t )
SteamAPICall_t CSteamUGC::RemoveDependency( PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nParentPublishedFileID: %llu, nChildPublishedFileID: %llu", nParentPublishedFileID, nChildPublishedFileID);
    return 0;
}

// add/remove app dependence/requirements (usually DLC)
STEAM_CALL_RESULT( AddAppDependencyResult_t )
SteamAPICall_t CSteamUGC::AddAppDependency( PublishedFileId_t nPublishedFileID, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, nAppID: %u", nPublishedFileID, nAppID);
    return 0;
}

STEAM_CALL_RESULT( RemoveAppDependencyResult_t )
SteamAPICall_t CSteamUGC::RemoveAppDependency( PublishedFileId_t nPublishedFileID, AppId_t nAppID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu, nAppID: %u", nPublishedFileID, nAppID);
    return 0;
}

// request app dependencies. note that whatever callback you register for GetAppDependenciesResult_t may be called multiple times
// until all app dependencies have been returned	STEAM_CALL_RESULT( GetAppDependenciesResult_t )
SteamAPICall_t CSteamUGC::GetAppDependencies( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}

// delete the item without prompting the user
STEAM_CALL_RESULT( DeleteItemResult_t )
SteamAPICall_t CSteamUGC::DeleteItem( PublishedFileId_t nPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - nPublishedFileID: %llu", nPublishedFileID);
    return 0;
}
