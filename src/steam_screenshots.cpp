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
#include "steam_screenshots.h"

// Static instance
Steam_Screenshots* Steam_Screenshots::s_pInstance = nullptr;

Steam_Screenshots::Steam_Screenshots()
{
    VLOG_INFO("Steam_Screenshots constructor called");
}

Steam_Screenshots::~Steam_Screenshots()
{
    VLOG_INFO("Steam_Screenshots destructor called");
}

// Helper methods
Steam_Screenshots* Steam_Screenshots::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Screenshots();
    }
    return s_pInstance;
}

void Steam_Screenshots::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Writes a screenshot to the user's screenshot library given the raw image data, which must be in RGB format.
// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
ScreenshotHandle Steam_Screenshots::WriteScreenshot( void *pubRGB, uint32 cubRGB, int nWidth, int nHeight )
{
    VLOG_DEBUG("WriteScreenshot called - Width: %d, Height: %d", nWidth, nHeight);
    return 0;
}

// Adds a screenshot to the user's screenshot library from disk.  If a thumbnail is provided, it must be 200 pixels wide and the same aspect ratio
// as the screenshot, otherwise a thumbnail will be generated if the user uploads the screenshot.  The screenshots must be in either JPEG or TGA format.
// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
// JPEG, TGA, and PNG formats are supported.
ScreenshotHandle Steam_Screenshots::AddScreenshotToLibrary( const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight )
{
    VLOG_DEBUG("AddScreenshotToLibrary called - Width: %d, Height: %d", nWidth, nHeight);
    return 0;
}

// Causes the Steam overlay to take a screenshot.  If screenshots are being hooked by the game then a ScreenshotRequested_t callback is sent back to the game instead. 
void Steam_Screenshots::TriggerScreenshot()
{
    VLOG_DEBUG("TriggerScreenshot called");
}

// Toggles whether the overlay handles screenshots when the user presses the screenshot hotkey, or the game handles them.  If the game is hooking screenshots,
// then the ScreenshotRequested_t callback will be sent if the user presses the hotkey, and the game is expected to call WriteScreenshot or AddScreenshotToLibrary
// in response.
void Steam_Screenshots::HookScreenshots( bool bHook )
{
    VLOG_DEBUG("HookScreenshots called - bHook: %d", bHook);
}

// Sets metadata about a screenshot's location (for example, the name of the map)
bool Steam_Screenshots::SetLocation( ScreenshotHandle hScreenshot, const char *pchLocation )
{
    VLOG_DEBUG("SetLocation called - hScreenshot: %d, pchLocation: %s", hScreenshot, pchLocation);
    return true;
}

// Tags a user as being visible in the screenshot
bool Steam_Screenshots::TagUser( ScreenshotHandle hScreenshot, CSteamID steamID )
{
    VLOG_DEBUG("TagUser called - hScreenshot: %d, steamID: %d", hScreenshot, steamID);
    return true;
}

// Tags a published file as being visible in the screenshot
bool Steam_Screenshots::TagPublishedFile( ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID )
{
    VLOG_DEBUG("TagPublishedFile called - hScreenshot: %d, unPublishedFileID: %d", hScreenshot, unPublishedFileID);
    return true;
}
