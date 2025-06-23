/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_remote_storage.h"
#include "logger.h"

// Static instance
Steam_Remote_Storage* Steam_Remote_Storage::s_pInstance = nullptr;

Steam_Remote_Storage::Steam_Remote_Storage()
{
    VLOG_INFO("Steam_RemoteStorage constructor called");
}

Steam_Remote_Storage::~Steam_Remote_Storage()
{
    VLOG_INFO("Steam_RemoteStorage destructor called");
}

// Helper methods
Steam_Remote_Storage* Steam_Remote_Storage::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Remote_Storage();
    }
    return s_pInstance;
}

void Steam_Remote_Storage::ReleaseInstance()
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
bool Steam_Remote_Storage::FileWrite( const char *pchFile, const void *pvData, int32 cubData )
{
    VLOG_DEBUG("FileWrite called - File: %s, DataSize: %d", pchFile, cubData);
    return false;
}

int32 Steam_Remote_Storage::FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
{
    VLOG_DEBUG("FileRead called - File: %s, DataSize: %d", pchFile, cubDataToRead);
    return 0;
}

bool Steam_Remote_Storage::FileForget( const char *pchFile )
{
    VLOG_DEBUG("FileForget called - File: %s", pchFile);
    return false;
}

bool Steam_Remote_Storage::FileDelete( const char *pchFile )
{
    VLOG_DEBUG("FileDelete called - File: %s", pchFile);
    return false;
}

SteamAPICall_t Steam_Remote_Storage::FileShare( const char *pchFile )
{
    VLOG_DEBUG("FileShare called - File: %s", pchFile);
    return 0; // TODO: Implement
}

bool Steam_Remote_Storage::SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
{
    VLOG_DEBUG("SetSyncPlatforms called - File: %s, Platform: %d", pchFile, eRemoteStoragePlatform);
    return false;
}

// file operations that cause network IO
UGCFileWriteStreamHandle_t Steam_Remote_Storage::FileWriteStreamOpen( const char *pchFile )
{
    VLOG_DEBUG("FileWriteStreamOpen called - File: %s", pchFile);
    return 0;
}

bool Steam_Remote_Storage::FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData )
{
    VLOG_DEBUG("FileWriteStreamWriteChunk called - Handle: %llu, DataSize: %d", writeHandle, cubData);
    return false;
}

bool Steam_Remote_Storage::FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_DEBUG("FileWriteStreamClose called - Handle: %llu", writeHandle);
    return false;
}

bool Steam_Remote_Storage::FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle )
{
    VLOG_DEBUG("FileWriteStreamCancel called - Handle: %llu", writeHandle);
    return false;
}

// file information
bool Steam_Remote_Storage::FileExists( const char *pchFile )
{
    VLOG_DEBUG("FileExists called - File: %s", pchFile);
    return false;
}

bool Steam_Remote_Storage::FilePersisted( const char *pchFile )
{
    VLOG_DEBUG("FilePersisted called - File: %s", pchFile);
    return false;
}

int32 Steam_Remote_Storage::GetFileSize( const char *pchFile )
{
    VLOG_DEBUG("GetFileSize called - File: %s", pchFile);
    return 0;
}

int64 Steam_Remote_Storage::GetFileTimestamp( const char *pchFile )
{
    VLOG_DEBUG("GetFileTimestamp called - File: %s", pchFile);
    return 0;
}

ERemoteStoragePlatform Steam_Remote_Storage::GetSyncPlatforms( const char *pchFile )
{
    VLOG_DEBUG("GetSyncPlatforms called - File: %s", pchFile);
    return ERemoteStoragePlatform::k_ERemoteStoragePlatformNone;
}

// iteration
int32 Steam_Remote_Storage::GetFileCount()
{
    VLOG_DEBUG("GetFileCount called");
    return 0;
}

const char *Steam_Remote_Storage::GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
{
    VLOG_DEBUG("GetFileNameAndSize called - File: %d", iFile);
    return nullptr;
}

// configuration management
bool Steam_Remote_Storage::GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
{
    VLOG_DEBUG("GetQuota called");
    return false;
}

bool Steam_Remote_Storage::IsCloudEnabledForAccount()
{
    VLOG_DEBUG("IsCloudEnabledForAccount called");
    return false;
}

bool Steam_Remote_Storage::IsCloudEnabledForApp()
{
    VLOG_DEBUG("IsCloudEnabledForApp called");
    return false;
}

void Steam_Remote_Storage::SetCloudEnabledForApp( bool bEnabled )
{
    VLOG_DEBUG("SetCloudEnabledForApp called - Enabled: %d", bEnabled);
}

// user generated content
// Downloads a UGC file
SteamAPICall_t Steam_Remote_Storage::UGCDownload( UGCHandle_t hContent )
{
    VLOG_DEBUG("UGCDownload called - Content: %d", hContent);
    return 0;
}

// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
bool Steam_Remote_Storage::GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected )
{
    VLOG_DEBUG("GetUGCDownloadProgress called - Content: %d", hContent);
    return false;
}

// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
bool Steam_Remote_Storage::GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner )
{
    VLOG_DEBUG("GetUGCDetails called - Content: %d", hContent);
    return false;
}

// After download, gets the content of the file
int32 Steam_Remote_Storage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
{
    VLOG_DEBUG("UGCRead called - Content: %d, DataSize: %d", hContent, cubDataToRead);
    return 0;
}

// Functions to iterate through UGC that has finished downloading but has not yet been read via UGCRead()
int32 Steam_Remote_Storage::GetCachedUGCCount()
{
    VLOG_DEBUG("GetCachedUGCCount called");
    return 0;
}

UGCHandle_t Steam_Remote_Storage::GetCachedUGCHandle( int32 iCachedContent )
{
    VLOG_DEBUG("GetCachedUGCHandle called - Index: %d", iCachedContent);
    return 0;
}

// publishing UGC
// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t Steam_Remote_Storage::PublishFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t Steam_Remote_Storage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishWorkshopFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t Steam_Remote_Storage::UpdatePublishedFile( RemoteStorageUpdatePublishedFileRequest_t updatePublishedFileRequest )
{
    VLOG_DEBUG("UpdatePublishedFile called - Request: %d", updatePublishedFileRequest);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType )
{
    VLOG_DEBUG("PublishWorkshopFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d, FileType: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, eWorkshopFileType);
    return 0;
}

PublishedFileUpdateHandle_t Steam_Remote_Storage::CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("CreatePublishedFileUpdateRequest called - FileId: %d", unPublishedFileId);
    return 0;
}

bool Steam_Remote_Storage::UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile )
{
    VLOG_DEBUG("UpdatePublishedFileFile called - Handle: %d, File: %s", updateHandle, pchFile);
    return false;
}

bool Steam_Remote_Storage::UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile )
{
    VLOG_DEBUG("UpdatePublishedFilePreviewFile called - Handle: %d, PreviewFile: %s", updateHandle, pchPreviewFile);
    return false;
}

bool Steam_Remote_Storage::UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle )
{
    VLOG_DEBUG("UpdatePublishedFileTitle called - Handle: %d, Title: %s", updateHandle, pchTitle);
    return false;
}

bool Steam_Remote_Storage::UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription )
{
    VLOG_DEBUG("UpdatePublishedFileDescription called - Handle: %d, Description: %s", updateHandle, pchDescription);
    return false;
}

bool Steam_Remote_Storage::UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    VLOG_DEBUG("UpdatePublishedFileVisibility called - Handle: %d, Visibility: %d", updateHandle, eVisibility);
    return false;
}

bool Steam_Remote_Storage::UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("UpdatePublishedFileTags called - Handle: %d", updateHandle);
    return false;
}

SteamAPICall_t Steam_Remote_Storage::CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle )
{
    VLOG_DEBUG("CommitPublishedFileUpdate called - Handle: %d", updateHandle);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetPublishedFileDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::DeletePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("DeletePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

// enumerate the files that the current user published with this app
SteamAPICall_t Steam_Remote_Storage::EnumerateUserPublishedFiles( uint32 unStartIndex )
{
    VLOG_DEBUG("EnumerateUserPublishedFiles called - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::SubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("SubscribePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::EnumerateUserSubscribedFiles( uint32 unStartIndex )
{
    VLOG_DEBUG("EnumerateUserSubscribedFiles called - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("UnsubscribePublishedFile called - FileId: %d", unPublishedFileId);
    return 0;
}

bool Steam_Remote_Storage::UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription )
{
    VLOG_DEBUG("UpdatePublishedFileSetChangeDescription called - Handle: %d, Description: %s", updateHandle, pchChangeDescription);
    return false;
}

SteamAPICall_t Steam_Remote_Storage::GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetPublishedItemVoteDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp )
{
    VLOG_DEBUG("UpdateUserPublishedItemVote called - FileId: %d, VoteUp: %s", unPublishedFileId, bVoteUp ? "true" : "false");
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    VLOG_DEBUG("GetUserPublishedItemVoteDetails called - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags )
{
    VLOG_DEBUG("EnumerateUserSharedWorkshopFiles called - SteamID: %s, StartIndex: %d", steamId.GetAccountID(), unStartIndex);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishVideo called - Provider: %d, Account: %s, Identifier: %s, PreviewFile: %s, AppId: %d, Title: %s", 
               eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

// Changed from Steam SDK v1.20, backward compatibility
SteamAPICall_t Steam_Remote_Storage::PublishVideo( const char *pchVideoURL, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishVideo called - URL: %s, PreviewFile: %s, AppId: %d, Title: %s", pchVideoURL, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction )
{
    VLOG_DEBUG("SetUserPublishedFileAction called - FileId: %d, Action: %d", unPublishedFileId, eAction);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex )
{
    VLOG_DEBUG("EnumeratePublishedFilesByUserAction called - Action: %d, StartIndex: %d", eAction, unStartIndex);
    return 0;
}

// this method enumerates the public view of workshop files
SteamAPICall_t Steam_Remote_Storage::EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags )
{
    VLOG_DEBUG("EnumeratePublishedWorkshopFiles called - Type: %d, StartIndex: %d, Count: %d, Days: %d", eEnumerationType, unStartIndex, unCount, unDays);
    return 0;
}