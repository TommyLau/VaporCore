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
#include <isteamremotestorage006.h>
#include <isteamremotestorage008.h>
#include <isteamremotestorage010.h>
#include <isteamremotestorage011.h>
#include <isteamremotestorage012.h>
#include <isteamremotestorage013.h>

#include "vapor_file_storage.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing, reading and writing files stored remotely 
//			and cached locally
//-----------------------------------------------------------------------------
class CSteamRemoteStorage :
    public ISteamRemoteStorage,
    public ISteamRemoteStorage002,
    public ISteamRemoteStorage004,
    public ISteamRemoteStorage005,
    public ISteamRemoteStorage006,
    public ISteamRemoteStorage008,
    public ISteamRemoteStorage010,
    public ISteamRemoteStorage011,
    public ISteamRemoteStorage012,
    public ISteamRemoteStorage013
{
public:
    // Singleton accessor
    static CSteamRemoteStorage& GetInstance()
    {
        static CSteamRemoteStorage instance;
        return instance;
    }
    
public:
	// NOTE
	//
	// Filenames are case-insensitive, and will be converted to lowercase automatically.
	// So "foo.bar" and "Foo.bar" are the same file, and if you write "Foo.bar" then
	// iterate the files, the filename returned will be "foo.bar".
	//

	// file operations
    bool FileWrite( const char *pchFile, const void *pvData, int32 cubData ) override;
    int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead ) override;

	STEAM_CALL_RESULT( RemoteStorageFileWriteAsyncComplete_t )
	SteamAPICall_t FileWriteAsync( const char *pchFile, const void *pvData, uint32 cubData ) override;
	
	STEAM_CALL_RESULT( RemoteStorageFileReadAsyncComplete_t )
	SteamAPICall_t FileReadAsync( const char *pchFile, uint32 nOffset, uint32 cubToRead ) override;
	bool FileReadAsyncComplete( SteamAPICall_t hReadCall, void *pvBuffer, uint32 cubToRead ) override;

    bool FileForget( const char *pchFile ) override;
    bool FileDelete( const char *pchFile ) override;
	STEAM_CALL_RESULT( RemoteStorageFileShareResult_t )
    SteamAPICall_t FileShare( const char *pchFile ) override;
    bool SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform ) override;

	// file operations that cause network IO
    UGCFileWriteStreamHandle_t FileWriteStreamOpen( const char *pchFile ) override;
    bool FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData ) override;
    bool FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle ) override;
    bool FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle ) override;

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
	bool GetQuota( uint64 *pnTotalBytes, uint64 *puAvailableBytes ) override;
    // Changed from Steam SDK v1.38a, backward compatibility
    bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes ) override;
    bool IsCloudEnabledForAccount() override;
    bool IsCloudEnabledForApp() override;
    void SetCloudEnabledForApp( bool bEnabled ) override;

	// user generated content

	// Downloads a UGC file.  A priority value of 0 will download the file immediately,
	// otherwise it will wait to download the file until all downloads with a lower priority
	// value are completed.  Downloads with equal priority will occur simultaneously.
	STEAM_CALL_RESULT( RemoteStorageDownloadUGCResult_t )
    SteamAPICall_t UGCDownload( UGCHandle_t hContent, uint32 unPriority ) override;
    // Changed from Steam SDK v1.22, backward compatibility
    SteamAPICall_t UGCDownload( UGCHandle_t hContent ) override;

	// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
	// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
	bool GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected ) override;

	// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
    bool GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, STEAM_OUT_STRING() char **ppchName, int32 *pnFileSizeInBytes, STEAM_OUT_STRUCT() CSteamID *pSteamIDOwner ) override;

	// After download, gets the content of the file.  
	// Small files can be read all at once by calling this function with an offset of 0 and cubDataToRead equal to the size of the file.
	// Larger files can be read in chunks to reduce memory usage (since both sides of the IPC client and the game itself must allocate
	// enough memory for each chunk).  Once the last byte is read, the file is implicitly closed and further calls to UGCRead will fail
	// unless UGCDownload is called again.
	// For especially large files (anything over 100MB) it is a requirement that the file is read in chunks.
	int32 UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction ) override;
    // Changed from Steam SDK v1.26, backward compatibility
	int32 UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset ) override;
    // Changed from Steam SDK v1.22, backward compatibility
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
	STEAM_CALL_RESULT( RemoteStoragePublishFileProgress_t )
	SteamAPICall_t PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType ) override;
	PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId ) override;
	bool UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile ) override;
	bool UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile ) override;
	bool UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle ) override;
	bool UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription ) override;
	bool UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility ) override;
	bool UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags ) override;
	STEAM_CALL_RESULT( RemoteStorageUpdatePublishedFileResult_t )
	SteamAPICall_t CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle ) override;
	// Gets published file details for the given publishedfileid.  If unMaxSecondsOld is greater than 0,
	// cached data may be returned, depending on how long ago it was cached.  A value of 0 will force a refresh.
	// A value of k_WorkshopForceLoadPublishedFileDetailsFromCache will use cached data if it exists, no matter how old it is.
	STEAM_CALL_RESULT( RemoteStorageGetPublishedFileDetailsResult_t )
	SteamAPICall_t GetPublishedFileDetails( PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld ) override;
	STEAM_CALL_RESULT( RemoteStorageDeletePublishedFileResult_t )
    SteamAPICall_t GetPublishedFileDetails( PublishedFileId_t unPublishedFileId ) override;
    SteamAPICall_t DeletePublishedFile( PublishedFileId_t unPublishedFileId ) override;
	// enumerate the files that the current user published with this app
	STEAM_CALL_RESULT( RemoteStorageEnumerateUserPublishedFilesResult_t )
    SteamAPICall_t EnumerateUserPublishedFiles( uint32 unStartIndex ) override;
	STEAM_CALL_RESULT( RemoteStorageSubscribePublishedFileResult_t )
    SteamAPICall_t SubscribePublishedFile( PublishedFileId_t unPublishedFileId ) override;
	STEAM_CALL_RESULT( RemoteStorageEnumerateUserSubscribedFilesResult_t )
    SteamAPICall_t EnumerateUserSubscribedFiles( uint32 unStartIndex ) override;
	STEAM_CALL_RESULT( RemoteStorageUnsubscribePublishedFileResult_t )
    SteamAPICall_t UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId ) override;
    bool UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription ) override;
	STEAM_CALL_RESULT( RemoteStorageGetPublishedItemVoteDetailsResult_t )
    SteamAPICall_t GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) override;
	STEAM_CALL_RESULT( RemoteStorageUpdateUserPublishedItemVoteResult_t )
    SteamAPICall_t UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp ) override;
	STEAM_CALL_RESULT( RemoteStorageGetPublishedItemVoteDetailsResult_t )
    SteamAPICall_t GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) override;
	STEAM_CALL_RESULT( RemoteStorageEnumerateUserPublishedFilesResult_t )
    SteamAPICall_t EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags ) override;
	STEAM_CALL_RESULT( RemoteStoragePublishFileProgress_t )
	SteamAPICall_t PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags ) override;
    // Changed from Steam SDK v1.20, backward compatibility
    SteamAPICall_t PublishVideo( const char *pchVideoURL, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags ) override;
	STEAM_CALL_RESULT( RemoteStorageSetUserPublishedFileActionResult_t )
    SteamAPICall_t SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction ) override;
    // Changed from Steam SDK v1.38a, return type changed and comment out
	// STEAM_CALL_RESULT( RemoteStorageEnumeratePublishedFilesByUserActionResult_t )
    // SteamAPICall_t SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction ) override;
	STEAM_CALL_RESULT( RemoteStorageEnumeratePublishedFilesByUserActionResult_t )
    SteamAPICall_t EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex ) override;
	// this method enumerates the public view of workshop files
	STEAM_CALL_RESULT( RemoteStorageEnumerateWorkshopFilesResult_t )
    SteamAPICall_t EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags ) override;

	STEAM_CALL_RESULT( RemoteStorageDownloadUGCResult_t )
	SteamAPICall_t UGCDownloadToLocation( UGCHandle_t hContent, const char *pchLocation, uint32 unPriority ) override;

private:
    // Private constructor and destructor for singleton
    CSteamRemoteStorage();
    ~CSteamRemoteStorage();

    // Delete copy constructor and assignment operator
    CSteamRemoteStorage(const CSteamRemoteStorage&) = delete;
    CSteamRemoteStorage& operator=(const CSteamRemoteStorage&) = delete;

private:
    // Cloud configuration
    bool m_bCloudEnabledForAccount;
    bool m_bCloudEnabledForApp;
    
    // File storage backend
    VaporCore::FileStorage m_fileStorage;
};

#endif // VAPORCORE_STEAM_REMOTE_STORAGE_H
