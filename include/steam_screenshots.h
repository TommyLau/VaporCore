/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_SCREENSHOTS_H
#define VAPORCORE_STEAM_SCREENSHOTS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamremotestorage.h>
#include <isteamscreenshots.h>
#include <isteamscreenshots001.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for adding screenshots to the user's screenshot library
//-----------------------------------------------------------------------------
class CSteamScreenshots :
    public ISteamScreenshots,
    public ISteamScreenshots001
{
public:
	// Singleton accessor
    static CSteamScreenshots& GetInstance()
	{
		static CSteamScreenshots instance;
		return instance;
	}

	// Writes a screenshot to the user's screenshot library given the raw image data, which must be in RGB format.
	// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
	ScreenshotHandle WriteScreenshot( void *pubRGB, uint32 cubRGB, int nWidth, int nHeight ) override;

	// Adds a screenshot to the user's screenshot library from disk.  If a thumbnail is provided, it must be 200 pixels wide and the same aspect ratio
	// as the screenshot, otherwise a thumbnail will be generated if the user uploads the screenshot.  The screenshots must be in either JPEG or TGA format.
	// The return value is a handle that is valid for the duration of the game process and can be used to apply tags.
	// JPEG, TGA, and PNG formats are supported.
	ScreenshotHandle AddScreenshotToLibrary( const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight ) override;

	// Causes the Steam overlay to take a screenshot.  If screenshots are being hooked by the game then a ScreenshotRequested_t callback is sent back to the game instead. 
	void TriggerScreenshot() override;

	// Toggles whether the overlay handles screenshots when the user presses the screenshot hotkey, or the game handles them.  If the game is hooking screenshots,
	// then the ScreenshotRequested_t callback will be sent if the user presses the hotkey, and the game is expected to call WriteScreenshot or AddScreenshotToLibrary
	// in response.
	void HookScreenshots( bool bHook ) override;

	// Sets metadata about a screenshot's location (for example, the name of the map)
	bool SetLocation( ScreenshotHandle hScreenshot, const char *pchLocation ) override;
	
	// Tags a user as being visible in the screenshot
	bool TagUser( ScreenshotHandle hScreenshot, CSteamID steamID ) override;

	// Tags a published file as being visible in the screenshot
	bool TagPublishedFile( ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID ) override;

private:
    // Private constructor and destructor for singleton
    CSteamScreenshots();
    ~CSteamScreenshots();

    // Delete copy constructor and assignment operator
    CSteamScreenshots(const CSteamScreenshots&) = delete;
    CSteamScreenshots& operator=(const CSteamScreenshots&) = delete;

private:
    bool m_bHook;
};

#endif // VAPORCORE_STEAM_SCREENSHOTS_H
