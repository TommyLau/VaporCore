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
SteamAPICall_t Steam_Remote_Storage::UGCDownload( UGCHandle_t hContent )
{
    VLOG_DEBUG("UGCDownload called - Content: %d", hContent);
    return 0;
}

bool Steam_Remote_Storage::GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner )
{
    VLOG_DEBUG("GetUGCDetails called - Content: %d", hContent);
    return false;
}

int32 Steam_Remote_Storage::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
{
    VLOG_DEBUG("UGCRead called - Content: %d, DataSize: %d", hContent, cubDataToRead);
    return 0;
}

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
SteamAPICall_t Steam_Remote_Storage::PublishFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s, Visibility: %d", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, SteamParamStringArray_t *pTags )
{
    VLOG_DEBUG("PublishWorkshopFile called - File: %s, PreviewFile: %s, ConsumerAppId: %d, Title: %s, Description: %s", pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription);
    return 0;
}

SteamAPICall_t Steam_Remote_Storage::UpdatePublishedFile( RemoteStorageUpdatePublishedFileRequest_t updatePublishedFileRequest )
{
    VLOG_DEBUG("UpdatePublishedFile called - Request: %d", updatePublishedFileRequest);
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
