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
#include "steam_unified_messages.h"

// Static instance
CSteamUnifiedMessages* CSteamUnifiedMessages::s_pInstance = nullptr;

CSteamUnifiedMessages::CSteamUnifiedMessages()
{
    VLOG_INFO("CSteamUnifiedMessages constructor called");
}

CSteamUnifiedMessages::~CSteamUnifiedMessages()
{
    VLOG_INFO("CSteamUnifiedMessages destructor called");
}

// Helper methods
CSteamUnifiedMessages* CSteamUnifiedMessages::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new CSteamUnifiedMessages();
    }
    return s_pInstance;
}

void CSteamUnifiedMessages::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Sends a service method (in binary serialized form) using the Steam Client.
// Returns a unified message handle (k_InvalidUnifiedMessageHandle if could not send the message).
ClientUnifiedMessageHandle CSteamUnifiedMessages::SendMethod(const char *pchServiceMethod, const void *pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext)
{
    VLOG_DEBUG("SendMethod called - Service Method: %s, Buffer Size: %d", pchServiceMethod, unRequestBufferSize);
     return ISteamUnifiedMessages::k_InvalidUnifiedMessageHandle;
}

// Gets the size of the response and the EResult. Returns false if the response is not ready yet.
bool CSteamUnifiedMessages::GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, uint32 *punResponseSize, EResult *peResult)
{
    VLOG_DEBUG("GetMethodResponseInfo called - Handle: %llu", hHandle);
    if (peResult) *peResult = k_EResultFail;
    return false;
}

// Gets a response in binary serialized form (and optionally release the corresponding allocated memory).
bool CSteamUnifiedMessages::GetMethodResponseData(ClientUnifiedMessageHandle hHandle, void *pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease)
{
    VLOG_DEBUG("GetMethodResponseData called - Handle: %llu, Buffer Size: %d", hHandle, unResponseBufferSize);
    return false;
}
// Releases the message and its corresponding allocated memory.
bool CSteamUnifiedMessages::ReleaseMethod(ClientUnifiedMessageHandle hHandle)
{
    VLOG_DEBUG("ReleaseMethod called - Handle: %llu", hHandle);
    return false;
}

// Sends a service notification (in binary serialized form) using the Steam Client.
// Returns true if the notification was sent successfully.
bool CSteamUnifiedMessages::SendNotification(const char *pchServiceNotification, const void *pNotificationBuffer, uint32 unNotificationBufferSize)
{
    VLOG_DEBUG("SendNotification called - Service Notification: %s, Buffer Size: %d", pchServiceNotification, unNotificationBufferSize);
    return false;
}
