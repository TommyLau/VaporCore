/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_unified_messages.h"
#include "logger.h"

// Static instance
Steam_Unified_Messages* Steam_Unified_Messages::s_pInstance = nullptr;

Steam_Unified_Messages::Steam_Unified_Messages()
{
    VLOG_INFO("Steam_Unified_Messages constructor called");
}

Steam_Unified_Messages::~Steam_Unified_Messages()
{
    VLOG_INFO("Steam_Unified_Messages destructor called");
}

// Helper methods
Steam_Unified_Messages* Steam_Unified_Messages::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Unified_Messages();
    }
    return s_pInstance;
}

void Steam_Unified_Messages::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Sends a service method (in binary serialized form) using the Steam Client.
// Returns a unified message handle (k_InvalidUnifiedMessageHandle if could not send the message).
ClientUnifiedMessageHandle Steam_Unified_Messages::SendMethod(const char *pchServiceMethod, const void *pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext)
{
    VLOG_DEBUG("SendMethod called - Service Method: %s, Buffer Size: %d", pchServiceMethod, unRequestBufferSize);
     return ISteamUnifiedMessages::k_InvalidUnifiedMessageHandle;
}

// Gets the size of the response and the EResult. Returns false if the response is not ready yet.
bool Steam_Unified_Messages::GetMethodResponseInfo(ClientUnifiedMessageHandle hHandle, uint32 *punResponseSize, EResult *peResult)
{
    VLOG_DEBUG("GetMethodResponseInfo called - Handle: %llu", hHandle);
    if (peResult) *peResult = k_EResultFail;
    return false;
}

// Gets a response in binary serialized form (and optionally release the corresponding allocated memory).
bool Steam_Unified_Messages::GetMethodResponseData(ClientUnifiedMessageHandle hHandle, void *pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease)
{
    VLOG_DEBUG("GetMethodResponseData called - Handle: %llu, Buffer Size: %d", hHandle, unResponseBufferSize);
    return false;
}
// Releases the message and its corresponding allocated memory.
bool Steam_Unified_Messages::ReleaseMethod(ClientUnifiedMessageHandle hHandle)
{
    VLOG_DEBUG("ReleaseMethod called - Handle: %llu", hHandle);
    return false;
}

// Sends a service notification (in binary serialized form) using the Steam Client.
// Returns true if the notification was sent successfully.
bool Steam_Unified_Messages::SendNotification(const char *pchServiceNotification, const void *pNotificationBuffer, uint32 unNotificationBufferSize)
{
    VLOG_DEBUG("SendNotification called - Service Notification: %s, Buffer Size: %d", pchServiceNotification, unNotificationBufferSize);
    return false;
}
