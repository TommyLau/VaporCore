
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

bool Steam_UGC::SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription )
{
    VLOG_DEBUG("SetReturnLongDescription called");
    return false;
}

bool Steam_UGC::SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
    VLOG_DEBUG("SetReturnTotalOnly called");
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

// Request full details for one piece of UGC
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

