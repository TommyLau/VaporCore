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
#include "steam_tv.h"

CSteamTV::CSteamTV()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamTV::~CSteamTV()
{
    VLOG_INFO(__FUNCTION__);
}

bool CSteamTV::IsBroadcasting(int *pnNumViewers)
{
    VLOG_INFO(__FUNCTION__ " - NumViewers: %p", pnNumViewers);
    return false;
}

void CSteamTV::AddBroadcastGameData(const char *pchKey, const char *pchValue)
{
    VLOG_INFO(__FUNCTION__ " - Key: %s, Value: %s", pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

void CSteamTV::RemoveBroadcastGameData(const char *pchKey)
{
    VLOG_INFO(__FUNCTION__ " - Key: %s", pchKey ? pchKey : "null");
}

void CSteamTV::AddTimelineMarker(const char *pchTemplateName, bool bPersistent, uint8 nColorR, uint8 nColorG, uint8 nColorB)
{
    VLOG_INFO(__FUNCTION__ " - TemplateName: %s, Persistent: %d, Color: (%d,%d,%d)", 
              pchTemplateName ? pchTemplateName : "null", bPersistent, nColorR, nColorG, nColorB);
}

void CSteamTV::RemoveTimelineMarker()
{
    VLOG_INFO(__FUNCTION__);
}

uint32 CSteamTV::AddRegion(const char *pchElementName, const char *pchTimelineDataSection, 
                          const SteamTVRegion_t *pSteamTVRegion, ESteamTVRegionBehavior eSteamTVRegionBehavior)
{
    VLOG_INFO(__FUNCTION__ " - ElementName: %s, TimelineDataSection: %s, Region: %p, Behavior: %d",
              pchElementName ? pchElementName : "null", 
              pchTimelineDataSection ? pchTimelineDataSection : "null",
              pSteamTVRegion, eSteamTVRegionBehavior);
    return 0;
}

void CSteamTV::RemoveRegion(uint32 unRegionHandle)
{
    VLOG_INFO(__FUNCTION__ " - RegionHandle: %u", unRegionHandle);
}
