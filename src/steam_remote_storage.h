/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_REMOTE_STORAGE_H
#define VAPORCORE_STEAM_REMOTE_STORAGE_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamremotestorage.h>
#include <isteamremotestorage002.h>
#include <isteamremotestorage004.h>
#include <isteamremotestorage005.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing, reading and writing files stored remotely 
//			and cached locally
//-----------------------------------------------------------------------------
class Steam_Remote_Storage :
    public ISteamRemoteStorage,
    public ISteamRemoteStorage002,
    public ISteamRemoteStorage004,
    public ISteamRemoteStorage005
{
private:
    // Singleton instance
    static Steam_Remote_Storage* s_pInstance;

public:
    Steam_Remote_Storage();
    ~Steam_Remote_Storage();

    // Helper methods
    static Steam_Remote_Storage* GetInstance();
    static void ReleaseInstance();

    // NOTE
    //
    // Filenames are case-insensitive, and will be converted to lowercase automatically.
    // So "foo.bar" and "Foo.bar" are the same file, and if you write "Foo.bar" then
    // iterate the files, the filename returned will be "foo.bar".
    //

    // file operations
    bool FileWrite( const char *pchFile, const void *pvData, int32 cubData ) override;
    int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead ) override;
    bool FileForget( const char *pchFile ) override;
    bool FileDelete( const char *pchFile ) override;
    SteamAPICall_t FileShare( const char *pchFile ) override;
    bool SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform ) override;

	// file information
    bool FileExists( const char *pchFile ) override;
    bool FilePersisted( const char *pchFile ) override;
    int32 GetFileSize( const char *pchFile ) override;
    int64 GetFileTimestamp( const char *pchFile ) override;
    ERemoteStoragePlatform GetSyncPlatforms( const char *pchFile ) override;

    // iteration
    int32 GetFileCount() override;
    const char *GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes ) override;

    // configuration management
    bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes ) override;
    bool IsCloudEnabledForAccount() override;
    bool IsCloudEnabledForApp() override;
    void SetCloudEnabledForApp( bool bEnabled ) override;

	// user generated content
	// Downloads a UGC file
    SteamAPICall_t UGCDownload( UGCHandle_t hContent ) override;

	// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
	// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
	bool GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected ) override;

	// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
    bool GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner ) override;
	// After download, gets the content of the file
    int32 UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead ) override;

	// Functions to iterate through UGC that has finished downloading but has not yet been read via UGCRead()
    int32 GetCachedUGCCount() override;
    UGCHandle_t GetCachedUGCHandle( int32 iCachedContent ) override;

    // The following functions are only necessary on the Playstation 3. On PC & Mac, the Steam client will handle these operations for you
    // On Playstation 3, the game controls which files are stored in the cloud, via FilePersist, FileFetch, and FileForget.
			
#if defined(_PS3) || defined(_SERVER)
    // Connect to Steam and get a list of files in the Cloud - results in a RemoteStorageAppSyncStatusCheck_t callback
    void GetFileListFromServer() override;
    // Indicate this file should be downloaded in the next sync
    bool FileFetch( const char *pchFile ) override;
    // Indicate this file should be persisted in the next sync
    bool FilePersist( const char *pchFile ) override;
    // Pull any requested files down from the Cloud - results in a RemoteStorageAppSyncedClient_t callback
    bool SynchronizeToClient() override;
    // Upload any requested files to the Cloud - results in a RemoteStorageAppSyncedServer_t callback
    bool SynchronizeToServer() override;
    // Reset any fetch/persist/etc requests
    bool ResetFileRequestState() override;
#endif

    // publishing UGC
    // Removed from Steam SDK v1.18, backward compatibility
    SteamAPICall_t PublishFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags ) override;
    // Removed from Steam SDK v1.18, backward compatibility
    SteamAPICall_t PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, SteamParamStringArray_t *pTags ) override;
    // Removed from Steam SDK v1.18, backward compatibility
    SteamAPICall_t UpdatePublishedFile( RemoteStorageUpdatePublishedFileRequest_t updatePublishedFileRequest ) override;
	SteamAPICall_t PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType ) override;
	PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId ) override;
	bool UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile ) override;
	bool UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile ) override;
	bool UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle ) override;
	bool UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription ) override;
	bool UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility ) override;
	bool UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags ) override;
	SteamAPICall_t CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle ) override;
    SteamAPICall_t GetPublishedFileDetails( PublishedFileId_t unPublishedFileId ) override;
    SteamAPICall_t DeletePublishedFile( PublishedFileId_t unPublishedFileId ) override;
	// enumerate the files that the current user published with this app
    SteamAPICall_t EnumerateUserPublishedFiles( uint32 unStartIndex ) override;
    SteamAPICall_t SubscribePublishedFile( PublishedFileId_t unPublishedFileId ) override;
    SteamAPICall_t EnumerateUserSubscribedFiles( uint32 unStartIndex ) override;
    SteamAPICall_t UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId ) override;
    bool UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription ) override;
    SteamAPICall_t GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) override;
    SteamAPICall_t UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp ) override;
    SteamAPICall_t GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) override;
    SteamAPICall_t EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags ) override;
    SteamAPICall_t PublishVideo( const char *pchVideoURL, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags ) override;
    SteamAPICall_t SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction ) override;
    SteamAPICall_t EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex ) override;
    // this method enumerates the public view of workshop files
    SteamAPICall_t EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags ) override;
};

#endif // VAPORCORE_STEAM_REMOTE_STORAGE_H
