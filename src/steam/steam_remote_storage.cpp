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
#include "steam_remote_storage.h"

// Static instance
CSteamRemoteStorage* CSteamRemoteStorage::s_pInstance = nullptr;

CSteamRemoteStorage::CSteamRemoteStorage()
{
    VLOG_INFO("CSteamRemoteStorage constructor called");
}

CSteamRemoteStorage::~CSteamRemoteStorage()
{
    VLOG_INFO("CSteamRemoteStorage destructor called");
}

// Helper methods
CSteamRemoteStorage* CSteamRemoteStorage::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamRemoteStorage();
    }
    return s_pInstance;
}

void CSteamRemoteStorage::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// NOTE
//
// Filenames are case-insensitive, and will be converted to lowercase automatically.
// So "foo.bar" and "Foo.bar" are the same file, and if you write "Foo.bar" then
// iterate the files, the filename returned will be "foo.bar".
//

// file operations
bool CSteamRemoteStorage::FileWrite( const char *pchFile, const void *pvData, int32 cubData )
{
    VLOG_DEBUG("FileWrite called - File: %s, DataSize: %d", pchFile, cubData);
    return false;
}

int32 CSteamRemoteStorage::FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
{
    VLOG_DEBUG("FileRead called - File: %s, DataSize: %d", pchFile, cubDataToRead);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::FileWriteAsync( const char *pchFile, const void *pvData, uint32 cubData )
{
    VLOG_DEBUG("FileWriteAsync called - File: %s, DataSize: %d", pchFile, cubData);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::FileReadAsync( const char *pchFile, uint32 nOffset, uint32 cubToRead )
{
    VLOG_DEBUG("FileReadAsync called - File: %s, Offset: %d, DataSize: %d", pchFile, nOffset, cubToRead);
    return 0;
}

bool CSteamRemoteStorage::FileReadAsyncComplete( SteamAPICall_t hReadCall, void *pvBuffer, uint32 cubToRead )
{
    VLOG_DEBUG("FileReadAsyncComplete called - Call: %llu, DataSize: %d", hReadCall, cubToRead);
    return false;
}

bool CSteamRemoteStorage::FileForget( const char *pchFile )
{
    VLOG_DEBUG("FileForget called - File: %s", pchFile);
    return false;
}

bool CSteamRemoteStorage::FileDelete( const char *pchFile )
{
    VLOG_DEBUG("FileDelete called - File: %s", pchFile);
    return false;
}

SteamAPICall_t CSteamRemoteStorage::FileShare( const char *pchFile )
{
    VLOG_DEBUG("FileShare called - File: %s", pchFile);
    return 0; // TODO: Implement
}

bool CSteamRemoteStorage::SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
{
    VLOG_DEBUG("SetSyncPlatforms called - File: %s, Platform: %d", pchFile, eRemoteStoragePlatform);
    return false;
}

// file operations that cause network IO
UGCFileWriteStreamHandle_t CSteamRemoteStorage::FileWriteStreamOpen( const char *pchFile )
{
    VLOG_DEBUG("FileWriteStreamOpen called - File: %s", pchFile);
    return 0;
}

bool CSteamRemoteStorage::FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData )
{
    VLOG_DEBUG("FileWriteStreamWriteChunk called - Handle: %llu, DataSize: %d", writeHandle, cubData);
    return false;
}

bool CSteamRemoteStorage::FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_DEBUG("FileWriteStreamClose called - Handle: %llu", writeHandle);
    return false;
}

bool CSteamRemoteStorage::FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_DEBUG("FileWriteStreamCancel called - Handle: %llu", writeHandle);
    return false;
}

// file information
bool CSteamRemoteStorage::FileExists( const char *pchFile )
{
    VLOG_DEBUG("FileExists called - File: %s", pchFile);
    return false;
}

bool CSteamRemoteStorage::FilePersisted( const char *pchFile )
{
    VLOG_DEBUG("FilePersisted called - File: %s", pchFile);
    return false;
}

int32 CSteamRemoteStorage::GetFileSize( const char *pchFile )
{
    VLOG_DEBUG("GetFileSize called - File: %s", pchFile);
    return 0;
}

int64 CSteamRemoteStorage::GetFileTimestamp( const char *pchFile )
{
    VLOG_DEBUG("GetFileTimestamp called - File: %s", pchFile);
    return 0;
}

ERemoteStoragePlatform CSteamRemoteStorage::GetSyncPlatforms( const char *pchFile )
{
    VLOG_DEBUG("GetSyncPlatforms called - File: %s", pchFile);
    return ERemoteStoragePlatform::k_ERemoteStoragePlatformNone;
}

// iteration
int32 CSteamRemoteStorage::GetFileCount()
{
    VLOG_DEBUG("GetFileCount called");
    return 0;
}

const char *CSteamRemoteStorage::GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
{
    VLOG_DEBUG("GetFileNameAndSize called - File: %d", iFile);
    return nullptr;
}

// configuration management
bool CSteamRemoteStorage::GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
{
    VLOG_DEBUG("GetQuota called");
    return false;
}

bool CSteamRemoteStorage::IsCloudEnabledForAccount()
{
    VLOG_DEBUG("IsCloudEnabledForAccount called");
    return false;
}

bool CSteamRemoteStorage::IsCloudEnabledForApp()
{
    VLOG_DEBUG("IsCloudEnabledForApp called");
    return false;
}

void CSteamRemoteStorage::SetCloudEnabledForApp( bool bEnabled )
{
    VLOG_DEBUG("SetCloudEnabledForApp called - Enabled: %d", bEnabled);
}

// user generated content

// Downloads a UGC file.  A priority value of 0 will download the file immediately,
// otherwise it will wait to download the file until all downloads with a lower priority
// value are completed.  Downloads with equal priority will occur simultaneously.
SteamAPICall_t CSteamRemoteStorage::UGCDownload( UGCHandle_t hContent, uint32 unPriority )
{
    VLOG_DEBUG("UGCDownload called - Content: %d, Priority: %d", hContent, unPriority);
    return 0;
}

// Changed from Steam SDK v1.22, backward compatibility
SteamAPICall_t CSteamRemoteStorage::UGCDownload( UGCHandle_t hContent )
{
    VLOG_DEBUG("UGCDownload called - Content: %d", hContent);
    return 0;
}

// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
bool CSteamRemoteStorage::GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected )
{
    VLOG_DEBUG("GetUGCDownloadProgress called - Content: %d", hContent);
    return false;
}

// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
bool CSteamRemoteStorage::GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, OUT_STRUCT() CSteamID *pSteamIDOwner )
{
    VLOG_DEBUG("GetUGCDetails called - Content: %d", hContent);
    return false;
}

// After download, gets the content of the file
// Small files can be read all at once by calling this function with an offset of 0 and cubDataToRead equal to the size of the file.
// Larger files can be read in chunks to reduce memory usage (since both sides of the IPC client and the game itself must allocate
// enough memory for each chunk).  Once the last byte is read, the file is implicitly closed and further calls to UGCRead will fail
// unless UGCDownload is called again.
// For especially large files (anything over 100MB) it is a requirement that the file is read in chunks.
int32 CSteamRemoteStorage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction )
{
    VLOG_DEBUG("UGCRead called - Content: %d, DataSize: %d, Offset: %d, Action: %d", hContent, cubDataToRead, cOffset, eAction);
    return 0;
}

// Changed from Steam SDK v1.26, backward compatibility
int32 CSteamRemoteStorage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset )
{
    VLOG_DEBUG("UGCRead called - Content: %d, DataSize: %d, Offset: %d", hContent, cubDataToRead, cOffset);
    return 0;
}

// Changed from Steam SDK v1.22, backward compatibility
int32 CSteamRemoteStorage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
{
    VLOG_DEBUG("UGCRead called - Content: %d, DataSize: %d", hContent, cubDataToRead);
    return 0;
}

// Functions to iterate through UGC that has finished downloading but has not yet been read via UGCRead()
int32 CSteamRemoteStorage::GetCachedUGCCount()
{
    VLOG_DEBUG("GetCachedUGCCount called");
    return 0;
}

UGCHandle_t CSteamRemoteStorage::GetCachedUGCHandle( int32 iCachedContent )
{
    VLOG_DEBUG("GetCachedUGCHandle called - Index: %d", iCachedContent);
    return 0;
}

// publishing UGC
// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishWorkshopFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::UpdatePublishedFile( RemoteStorageUpdatePublishedFileRequest_t updatePublishedFileRequest )
{
    VLOG_DEBUG("UpdatePublishedFile called - Request: %d", updatePublishedFileRequest);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType )
{
    VLOG_DEBUG("PublishWorkshopFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d, FileType: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, eWorkshopFileType);
    return 0;
}

PublishedFileUpdateHandle_t CSteamRemoteStorage::CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("CreatePublishedFileUpdateRequest called - FileId: %d", unPublishedFileId);
    return 0;
}

bool CSteamRemoteStorage::UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile )
{
    VLOG_DEBUG("UpdatePublishedFileFile called - Handle: %d, File: %s", updateHandle, pchFile);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile )
{
    VLOG_DEBUG("UpdatePublishedFilePreviewFile called - Handle: %d, PreviewFile: %s", updateHandle, pchPreviewFile);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle )
{
    VLOG_DEBUG("UpdatePublishedFileTitle called - Handle: %d, Title: %s", updateHandle, pchTitle);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription )
{
    VLOG_DEBUG("UpdatePublishedFileDescription called - Handle: %d, Description: %s", updateHandle, pchDescription);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_DEBUG("UpdatePublishedFileVisibility called - Handle: %d, Visibility: %d", updateHandle, eVisibility);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("UpdatePublishedFileTags called - Handle: %d", updateHandle);
    return false;
}

SteamAPICall_t CSteamRemoteStorage::CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle )
{
    VLOG_DEBUG("CommitPublishedFileUpdate called - Handle: %d", updateHandle);
    return 0;
}

// Gets published file details for the given publishedfileid.  If unMaxSecondsOld is greater than 0,
// cached data may be returned, depending on how long ago it was cached.  A value of 0 will force a refresh.
// A value of k_WorkshopForceLoadPublishedFileDetailsFromCache will use cached data if it exists, no matter how old it is.
SteamAPICall_t CSteamRemoteStorage::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld )
{
    VLOG_DEBUG("GetPublishedFileDetails called - FileId: %d, MaxSecondsOld: %u", unPublishedFileId, unMaxSecondsOld);
    return 0;
}

// Changed from Steam SDK v1.25, backward compatibility
SteamAPICall_t CSteamRemoteStorage::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetPublishedFileDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::DeletePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("DeletePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

// enumerate the files that the current user published with this app
SteamAPICall_t CSteamRemoteStorage::EnumerateUserPublishedFiles( uint32 unStartIndex )
{
    VLOG_DEBUG("EnumerateUserPublishedFiles called - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::SubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("SubscribePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumerateUserSubscribedFiles( uint32 unStartIndex )
{
    VLOG_DEBUG("EnumerateUserSubscribedFiles called - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("UnsubscribePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

bool CSteamRemoteStorage::UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription )
{
    VLOG_DEBUG("UpdatePublishedFileSetChangeDescription called - Handle: %d, Description: %s", updateHandle, pchChangeDescription);
    return false;
}

SteamAPICall_t CSteamRemoteStorage::GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetPublishedItemVoteDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp )
{
    VLOG_DEBUG("UpdateUserPublishedItemVote called - FileId: %d, VoteUp: %s", unPublishedFileId, bVoteUp ? "true" : "false");
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetUserPublishedItemVoteDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags )
{
    VLOG_DEBUG("EnumerateUserSharedWorkshopFiles called - SteamID: %s, StartIndex: %d", steamId.GetAccountID(), unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishVideo called - Provider: %d, Account: %s, Identifier: %s, PreviewFile: %s, AppId: %d, Title: %s", 
               eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

// Changed from Steam SDK v1.20, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishVideo( const char *pchVideoURL, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishVideo called - URL: %s, PreviewFile: %s, AppId: %d, Title: %s", pchVideoURL, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction )
{
    VLOG_DEBUG("SetUserPublishedFileAction called - FileId: %d, Action: %d", unPublishedFileId, eAction);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex )
{
    VLOG_DEBUG("EnumeratePublishedFilesByUserAction called - Action: %d, StartIndex: %d", eAction, unStartIndex);
    return 0;
}

// this method enumerates the public view of workshop files
SteamAPICall_t CSteamRemoteStorage::EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags )
{
    VLOG_DEBUG("EnumeratePublishedWorkshopFiles called - Type: %d, StartIndex: %d, Count: %d, Days: %d", eEnumerationType, unStartIndex, unCount, unDays);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UGCDownloadToLocation( UGCHandle_t hContent, const char *pchLocation, uint32 unPriority )
{
    VLOG_DEBUG("UGCDownloadToLocation called - Content: %llu, Location: %s, Priority: %d", hContent, pchLocation, unPriority);
    return 0;
}
