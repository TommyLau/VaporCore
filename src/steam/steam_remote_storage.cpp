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

CSteamRemoteStorage::CSteamRemoteStorage()
    : m_bCloudEnabledForAccount(true),
      m_bCloudEnabledForApp(true),
      m_fileStorage()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamRemoteStorage::~CSteamRemoteStorage()
{
    VLOG_INFO(__FUNCTION__);
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
    VLOG_INFO(__FUNCTION__ " - File: %s, DataSize: %d", pchFile, cubData);

    VAPORCORE_LOCK_GUARD();
    
    if (!pchFile || !pvData || cubData < 0) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid parameters for FileWrite");
        return false;
    }
    
    return m_fileStorage.WriteFile(pchFile, pvData, static_cast<size_t>(cubData));
}

int32 CSteamRemoteStorage::FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
{
    VLOG_INFO(__FUNCTION__ " - File: %s, DataSize: %d", pchFile, cubDataToRead);
    
    VAPORCORE_LOCK_GUARD();

    if (!pchFile || !pvData || cubDataToRead < 0) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid parameters for FileRead");
        return 0;
    }
    
    return m_fileStorage.ReadFile(pchFile, pvData, static_cast<size_t>(cubDataToRead));
}

SteamAPICall_t CSteamRemoteStorage::FileWriteAsync( const char *pchFile, const void *pvData, uint32 cubData )
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - File: %s, DataSize: %d", pchFile, cubData);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::FileReadAsync( const char *pchFile, uint32 nOffset, uint32 cubToRead )
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - File: %s, Offset: %d, DataSize: %d", pchFile, nOffset, cubToRead);
    return 0;
}

bool CSteamRemoteStorage::FileReadAsyncComplete( SteamAPICall_t hReadCall, void *pvBuffer, uint32 cubToRead )
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - Call: %llu, DataSize: %d", hReadCall, cubToRead);
    return false;
}

bool CSteamRemoteStorage::FileForget( const char *pchFile )
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    return false;
}

bool CSteamRemoteStorage::FileDelete( const char *pchFile )
{
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    
    VAPORCORE_LOCK_GUARD();

    if (!pchFile) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid filename for FileDelete");
        return false;
    }
    
    return m_fileStorage.DeleteFile(pchFile);
}

SteamAPICall_t CSteamRemoteStorage::FileShare( const char *pchFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    return 0;
}

bool CSteamRemoteStorage::SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s, Platform: %d", pchFile, eRemoteStoragePlatform);
    return false;
}

// file operations that cause network IO
UGCFileWriteStreamHandle_t CSteamRemoteStorage::FileWriteStreamOpen( const char *pchFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    return 0;
}

bool CSteamRemoteStorage::FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %llu, DataSize: %d", writeHandle, cubData);
    return false;
}

bool CSteamRemoteStorage::FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %llu", writeHandle);
    return false;
}

bool CSteamRemoteStorage::FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %llu", writeHandle);
    return false;
}

// file information
bool CSteamRemoteStorage::FileExists( const char *pchFile )
{
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    
    VAPORCORE_LOCK_GUARD();

    if (!pchFile) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid filename for FileExists");
        return false;
    }
    
    return m_fileStorage.FileExists(pchFile);
}

bool CSteamRemoteStorage::FilePersisted( const char *pchFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    return false;
}

int32 CSteamRemoteStorage::GetFileSize( const char *pchFile )
{
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    
    VAPORCORE_LOCK_GUARD();

    if (!pchFile) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid filename for GetFileSize");
        return 0;
    }
    
    return static_cast<int32>(m_fileStorage.GetFileSize(pchFile));
}

int64 CSteamRemoteStorage::GetFileTimestamp( const char *pchFile )
{
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    
    VAPORCORE_LOCK_GUARD();

    if (!pchFile) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid filename for GetFileTimestamp");
        return 0;
    }
    
    return m_fileStorage.GetFileTimestamp(pchFile);
}

ERemoteStoragePlatform CSteamRemoteStorage::GetSyncPlatforms( const char *pchFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s", pchFile);
    return ERemoteStoragePlatform::k_ERemoteStoragePlatformNone;
}

// iteration
int32 CSteamRemoteStorage::GetFileCount()
{
    VLOG_INFO(__FUNCTION__);
    
    VAPORCORE_LOCK_GUARD();

    return m_fileStorage.GetFileCount();
}

const char *CSteamRemoteStorage::GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
{
    VLOG_INFO(__FUNCTION__ " - File index: %d", iFile);
    
    VAPORCORE_LOCK_GUARD();
    
    return m_fileStorage.GetFileNameAndSize(iFile, pnFileSizeInBytes).c_str();
}

// configuration management
bool CSteamRemoteStorage::GetQuota( uint64 *pnTotalBytes, uint64 *puAvailableBytes )
{
    VLOG_INFO(__FUNCTION__);

    VAPORCORE_LOCK_GUARD();

    if (!pnTotalBytes || !puAvailableBytes) {
        return false;
    }

    return m_fileStorage.GetQuota(pnTotalBytes, puAvailableBytes);
}

// Changed from Steam SDK v1.38a, backward compatibility
bool CSteamRemoteStorage::GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
{
    VLOG_INFO(__FUNCTION__);

    uint64 totalBytes64 = 0;
    uint64 availableBytes64 = 0;
    
    bool result = GetQuota(&totalBytes64, &availableBytes64);
    
    // Convert uint64 values to int32, clamping to int32 max if necessary
    *pnTotalBytes = (totalBytes64 > INT32_MAX) ? INT32_MAX : static_cast<int32>(totalBytes64);
    *puAvailableBytes = (availableBytes64 > INT32_MAX) ? INT32_MAX : static_cast<int32>(availableBytes64);
    
    return result;
}

bool CSteamRemoteStorage::IsCloudEnabledForAccount()
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - Returning: %s", m_bCloudEnabledForAccount ? "true" : "false");
    return m_bCloudEnabledForAccount;
}

bool CSteamRemoteStorage::IsCloudEnabledForApp()
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - Returning: %s", m_bCloudEnabledForApp ? "true" : "false");
    return m_bCloudEnabledForApp;
}

void CSteamRemoteStorage::SetCloudEnabledForApp( bool bEnabled )
{
    VAPORCORE_LOCK_GUARD();
    VLOG_INFO(__FUNCTION__ " - Setting to: %s", bEnabled ? "true" : "false");
    m_bCloudEnabledForApp = bEnabled;
}

// user generated content

// Downloads a UGC file.  A priority value of 0 will download the file immediately,
// otherwise it will wait to download the file until all downloads with a lower priority
// value are completed.  Downloads with equal priority will occur simultaneously.
SteamAPICall_t CSteamRemoteStorage::UGCDownload( UGCHandle_t hContent, uint32 unPriority )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d, Priority: %d", hContent, unPriority);
    return 0;
}

// Changed from Steam SDK v1.22, backward compatibility
SteamAPICall_t CSteamRemoteStorage::UGCDownload( UGCHandle_t hContent )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d", hContent);
    return 0;
}

// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
bool CSteamRemoteStorage::GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d", hContent);
    return false;
}

// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
bool CSteamRemoteStorage::GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, STEAM_OUT_STRUCT() CSteamID *pSteamIDOwner )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d", hContent);
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
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d, DataSize: %d, Offset: %d, Action: %d", hContent, cubDataToRead, cOffset, eAction);
    return 0;
}

// Changed from Steam SDK v1.26, backward compatibility
int32 CSteamRemoteStorage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d, DataSize: %d, Offset: %d", hContent, cubDataToRead, cOffset);
    return 0;
}

// Changed from Steam SDK v1.22, backward compatibility
int32 CSteamRemoteStorage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %d, DataSize: %d", hContent, cubDataToRead);
    return 0;
}

// Functions to iterate through UGC that has finished downloading but has not yet been read via UGCRead()
int32 CSteamRemoteStorage::GetCachedUGCCount()
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__);
    return 0;
}

UGCHandle_t CSteamRemoteStorage::GetCachedUGCHandle( int32 iCachedContent )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Index: %d", iCachedContent);
    return 0;
}

// publishing UGC
// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, SteamParamStringArray_t *pTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription);
    return 0;
}

// Removed from Steam SDK v1.18, backward compatibility
SteamAPICall_t CSteamRemoteStorage::UpdatePublishedFile( RemoteStorageUpdatePublishedFileRequest_t updatePublishedFileRequest )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Request: %d", updatePublishedFileRequest);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d, FileType: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, eWorkshopFileType);
    return 0;
}

PublishedFileUpdateHandle_t CSteamRemoteStorage::CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

bool CSteamRemoteStorage::UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, File: %s", updateHandle, pchFile);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, PreviewFile: %s", updateHandle, pchPreviewFile);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, Title: %s", updateHandle, pchTitle);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, Description: %s", updateHandle, pchDescription);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, Visibility: %d", updateHandle, eVisibility);
    return false;
}

bool CSteamRemoteStorage::UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d", updateHandle);
    return false;
}

SteamAPICall_t CSteamRemoteStorage::CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d", updateHandle);
    return 0;
}

// Gets published file details for the given publishedfileid.  If unMaxSecondsOld is greater than 0,
// cached data may be returned, depending on how long ago it was cached.  A value of 0 will force a refresh.
// A value of k_WorkshopForceLoadPublishedFileDetailsFromCache will use cached data if it exists, no matter how old it is.
SteamAPICall_t CSteamRemoteStorage::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d, MaxSecondsOld: %u", unPublishedFileId, unMaxSecondsOld);
    return 0;
}

// Changed from Steam SDK v1.25, backward compatibility
SteamAPICall_t CSteamRemoteStorage::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::DeletePublishedFile( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

// enumerate the files that the current user published with this app
SteamAPICall_t CSteamRemoteStorage::EnumerateUserPublishedFiles( uint32 unStartIndex )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::SubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumerateUserSubscribedFiles( uint32 unStartIndex )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - StartIndex: %d", unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

bool CSteamRemoteStorage::UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Handle: %d, Description: %s", updateHandle, pchChangeDescription);
    return false;
}

SteamAPICall_t CSteamRemoteStorage::GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d, VoteUp: %s", unPublishedFileId, bVoteUp ? "true" : "false");
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d", unPublishedFileId);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - SteamID: %s, StartIndex: %d", steamId.GetAccountID(), unStartIndex);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Provider: %d, Account: %s, Identifier: %s, PreviewFile: %s, AppId: %d, Title: %s", 
               eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

// Changed from Steam SDK v1.20, backward compatibility
SteamAPICall_t CSteamRemoteStorage::PublishVideo( const char *pchVideoURL, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - URL: %s, PreviewFile: %s, AppId: %d, Title: %s", pchVideoURL, pchPreviewFile, nConsumerAppId, pchTitle);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - FileId: %d, Action: %d", unPublishedFileId, eAction);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Action: %d, StartIndex: %d", eAction, unStartIndex);
    return 0;
}

// this method enumerates the public view of workshop files
SteamAPICall_t CSteamRemoteStorage::EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Type: %d, StartIndex: %d, Count: %d, Days: %d", eEnumerationType, unStartIndex, unCount, unDays);
    return 0;
}

SteamAPICall_t CSteamRemoteStorage::UGCDownloadToLocation( UGCHandle_t hContent, const char *pchLocation, uint32 unPriority )
{
    // TODO: Implement
    VLOG_INFO(__FUNCTION__ " - Content: %llu, Location: %s, Priority: %d", hContent, pchLocation, unPriority);
    return 0;
}
