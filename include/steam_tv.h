/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_TV_H
#define VAPORCORE_STEAM_TV_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamtv.h>

class CSteamTV :
    public ISteamTV
{
public:
	// Singleton accessor
    static CSteamTV& GetInstance()
    {
		static CSteamTV instance;
		return instance;
    }

public:
    bool IsBroadcasting(int *pnNumViewers) override;
    void AddBroadcastGameData(const char *pchKey, const char *pchValue) override;
    void RemoveBroadcastGameData(const char *pchKey) override;
    void AddTimelineMarker(const char *pchTemplateName, bool bPersistent, uint8 nColorR, uint8 nColorG, uint8 nColorB) override;
    void RemoveTimelineMarker() override;
    uint32 AddRegion(const char *pchElementName, const char *pchTimelineDataSection, const SteamTVRegion_t *pSteamTVRegion, ESteamTVRegionBehavior eSteamTVRegionBehavior) override;
    void RemoveRegion(uint32 unRegionHandle) override;

private:
    // Private constructor and destructor for singleton
    CSteamTV();
    ~CSteamTV();

    // Delete copy constructor and assignment operator
    CSteamTV(const CSteamTV&) = delete;
    CSteamTV& operator=(const CSteamTV&) = delete;
};

#endif // VAPORCORE_STEAM_APP_TICKET_H
