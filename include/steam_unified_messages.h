/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_UNIFIED_MESSAGES_H
#define VAPORCORE_STEAM_UNIFIED_MESSAGES_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamunifiedmessages.h>

class CSteamUnifiedMessages :
    public ISteamUnifiedMessages
{
public:
	// Singleton accessor
    static CSteamUnifiedMessages& GetInstance()
    {
		static CSteamUnifiedMessages instance;
		return instance;
    }

public:
	static const ClientUnifiedMessageHandle k_InvalidUnifiedMessageHandle = 0;

	// Sends a service method (in binary serialized form) using the Steam Client.
	// Returns a unified message handle (k_InvalidUnifiedMessageHandle if could not send the message).
	ClientUnifiedMessageHandle SendMethod( const char *pchServiceMethod, const void *pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext ) override;

	// Gets the size of the response and the EResult. Returns false if the response is not ready yet.
	bool GetMethodResponseInfo( ClientUnifiedMessageHandle hHandle, uint32 *punResponseSize, EResult *peResult ) override;

	// Gets a response in binary serialized form (and optionally release the corresponding allocated memory).
	bool GetMethodResponseData( ClientUnifiedMessageHandle hHandle, void *pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease ) override;

	// Releases the message and its corresponding allocated memory.
	bool ReleaseMethod( ClientUnifiedMessageHandle hHandle ) override;

	// Sends a service notification (in binary serialized form) using the Steam Client.
	// Returns true if the notification was sent successfully.
	bool SendNotification( const char *pchServiceNotification, const void *pNotificationBuffer, uint32 unNotificationBufferSize ) override;

private:
    // Private constructor and destructor for singleton
    CSteamUnifiedMessages();
    ~CSteamUnifiedMessages();

    // Delete copy constructor and assignment operator
    CSteamUnifiedMessages(const CSteamUnifiedMessages&) = delete;
    CSteamUnifiedMessages& operator=(const CSteamUnifiedMessages&) = delete;
};

#endif // VAPORCORE_STEAM_UNIFIED_MESSAGES_H
