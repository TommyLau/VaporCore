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

CSteamScreenshots::CSteamScreenshots()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamScreenshots::~CSteamScreenshots()
{
    VLOG_INFO(__FUNCTION__);
}

// Writes a screenshot to the user's screenshot library given the raw image data, which must be in RGB format.
// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
ScreenshotHandle CSteamScreenshots::WriteScreenshot( void *pubRGB, uint32 cubRGB, int nWidth, int nHeight )
{
    VLOG_INFO(__FUNCTION__ " - Width: %d, Height: %d", nWidth, nHeight);
    return 0;
}

// Adds a screenshot to the user's screenshot library from disk.  If a thumbnail is provided, it must be 200 pixels wide and the same aspect ratio
// as the screenshot, otherwise a thumbnail will be generated if the user uploads the screenshot.  The screenshots must be in either JPEG or TGA format.
// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
// JPEG, TGA, and PNG formats are supported.
ScreenshotHandle CSteamScreenshots::AddScreenshotToLibrary( const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight )
{
    VLOG_INFO(__FUNCTION__ " - Width: %d, Height: %d", nWidth, nHeight);
    return 0;
}

// Causes the Steam overlay to take a screenshot.  If screenshots are being hooked by the game then a ScreenshotRequested_t callback is sent back to the game instead. 
void CSteamScreenshots::TriggerScreenshot()
{
    VLOG_INFO(__FUNCTION__);

    VAPORCORE_LOCK_GUARD();

    if (m_bHook)
    {
        // TODO: Return ScreenshotRequested_t callback?
        VLOG_DEBUG(__FUNCTION__ " - Screenshot requested, and hooked");
    }
    else
    {
        // TODO: Overlay take screenshot?
        VLOG_DEBUG(__FUNCTION__ " - Screenshot requested, but not hooked");
    }

    return;
}

// Toggles whether the overlay handles screenshots when the user presses the screenshot hotkey, or the game handles them.  If the game is hooking screenshots,
// then the ScreenshotRequested_t callback will be sent if the user presses the hotkey, and the game is expected to call WriteScreenshot or AddScreenshotToLibrary
// in response.
void CSteamScreenshots::HookScreenshots( bool bHook )
{
    VLOG_INFO(__FUNCTION__ " - bHook: %d", bHook);

    VAPORCORE_LOCK_GUARD();

    m_bHook = bHook;

    return;
}

// Sets metadata about a screenshot's location (for example, the name of the map)
bool CSteamScreenshots::SetLocation( ScreenshotHandle hScreenshot, const char *pchLocation )
{
    VLOG_INFO(__FUNCTION__ " - hScreenshot: %d, pchLocation: %s", hScreenshot, pchLocation);
    return true;
}

// Tags a user as being visible in the screenshot
bool CSteamScreenshots::TagUser( ScreenshotHandle hScreenshot, CSteamID steamID )
{
    VLOG_INFO(__FUNCTION__ " - hScreenshot: %d, steamID: %d", hScreenshot, steamID);
    return true;
}

// Tags a published file as being visible in the screenshot
bool CSteamScreenshots::TagPublishedFile( ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID )
{
    VLOG_INFO(__FUNCTION__ " - hScreenshot: %d, unPublishedFileID: %d", hScreenshot, unPublishedFileID);
    return true;
}

// Returns true if the app has hooked the screenshot
bool CSteamScreenshots::IsScreenshotsHooked()
{
    VAPORCORE_LOCK_GUARD();

    VLOG_INFO(__FUNCTION__ " - Returning: %s", m_bHook ? "true" : "false");

    return m_bHook;
}

// Adds a VR screenshot to the user's screenshot library from disk in the supported type.
// pchFilename should be the normal 2D image used in the library view
// pchVRFilename should contain the image that matches the correct type
// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
// JPEG, TGA, and PNG formats are supported.
ScreenshotHandle CSteamScreenshots::AddVRScreenshotToLibrary( EVRScreenshotType eType, const char *pchFilename, const char *pchVRFilename )
{
    VLOG_INFO(__FUNCTION__ " - eType: %d, pchFilename: %s, pchVRFilename: %s", eType, pchFilename, pchVRFilename);
    return INVALID_SCREENSHOT_HANDLE;
}
