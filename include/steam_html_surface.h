/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_HTML_SURFACE_H
#define VAPORCORE_STEAM_HTML_SURFACE_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamhtmlsurface.h>
#include <isteamhtmlsurface002.h>
#include <isteamhtmlsurface003.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for displaying HTML pages and interacting with them
//-----------------------------------------------------------------------------
class CSteamHTMLSurface :
	public ISteamHTMLSurface,
    public ISteamHTMLSurface002,
    public ISteamHTMLSurface003
{
public:
	// Singleton accessor
    static CSteamHTMLSurface& GetInstance()
    {
		static CSteamHTMLSurface instance;
		return instance;
    }

public:
	// Must call init and shutdown when starting/ending use of the interface
	bool Init() override;
	bool Shutdown() override;

	// Create a browser object for display of a html page, when creation is complete the call handle
	// will return a HTML_BrowserReady_t callback for the HHTMLBrowser of your new browser.
	//   The user agent string is a substring to be added to the general user agent string so you can
	// identify your client on web servers.
	//   The userCSS string lets you apply a CSS style sheet to every displayed page, leave null if
	// you do not require this functionality.
	//
	// YOU MUST HAVE IMPLEMENTED HANDLERS FOR HTML_BrowserReady_t, HTML_StartRequest_t,
	// HTML_JSAlert_t, HTML_JSConfirm_t, and HTML_FileOpenDialog_t! See the CALLBACKS
	// section of this interface (AllowStartRequest, etc) for more details. If you do
	// not implement these callback handlers, the browser may appear to hang instead of
	// navigating to new pages or triggering javascript popups.
	//
	CALL_RESULT( HTML_BrowserReady_t )
	SteamAPICall_t CreateBrowser( const char *pchUserAgent, const char *pchUserCSS ) override;

	// Call this when you are done with a html surface, this lets us free the resources being used by it
	void RemoveBrowser( HHTMLBrowser unBrowserHandle ) override;

	// Navigate to this URL, results in a HTML_StartRequest_t as the request commences 
	void LoadURL( HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData ) override;

	// Tells the surface the size in pixels to display the surface
	void SetSize( HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight ) override;

	// Stop the load of the current html page
	void StopLoad( HHTMLBrowser unBrowserHandle ) override;
	// Reload (most likely from local cache) the current page
	void Reload( HHTMLBrowser unBrowserHandle ) override;
	// navigate back in the page history
	void GoBack( HHTMLBrowser unBrowserHandle ) override;
	// navigate forward in the page history
	void GoForward( HHTMLBrowser unBrowserHandle ) override;

	// add this header to any url requests from this browser
	void AddHeader( HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue ) override;
	// run this javascript script in the currently loaded page
	void ExecuteJavascript( HHTMLBrowser unBrowserHandle, const char *pchScript ) override;

	// Mouse click and mouse movement commands
	void MouseUp( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) override;
	void MouseDown( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) override;
	void MouseDoubleClick( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) override;
	// x and y are relative to the HTML bounds
	void MouseMove( HHTMLBrowser unBrowserHandle, int x, int y ) override;
	// nDelta is pixels of scroll
	void MouseWheel( HHTMLBrowser unBrowserHandle, int32 nDelta ) override;

	// keyboard interactions, native keycode is the virtual key code value from your OS
	void KeyDown( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers ) override;
	void KeyUp( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers ) override;
	// cUnicodeChar is the unicode character point for this keypress (and potentially multiple chars per press)
	void KeyChar( HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers ) override;

	// programmatically scroll this many pixels on the page
	void SetHorizontalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll ) override;
	void SetVerticalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll ) override;

	// tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
	void SetKeyFocus( HHTMLBrowser unBrowserHandle, bool bHasKeyFocus ) override;

	// open the current pages html code in the local editor of choice, used for debugging
	void ViewSource( HHTMLBrowser unBrowserHandle ) override;
	// copy the currently selected text on the html page to the local clipboard
	void CopyToClipboard( HHTMLBrowser unBrowserHandle ) override;
	// paste from the local clipboard to the current html page
	void PasteFromClipboard( HHTMLBrowser unBrowserHandle ) override;

	// find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
	void Find( HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse ) override;
	// cancel a currently running find
	void StopFind( HHTMLBrowser unBrowserHandle ) override;

	// return details about the link at position x,y on the current page
	void GetLinkAtPosition( HHTMLBrowser unBrowserHandle, int x, int y ) override;

	// set a webcookie for the hostname in question
	void SetCookie( const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath = "/", RTime32 nExpires = 0, bool bSecure = false, bool bHTTPOnly = false ) override;

	// Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
	void SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY ) override;

	// Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
	// more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
	// all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
	// When background mode is disabled, any video or audio objects with that property will resume with ".play()".
	void SetBackgroundMode( HHTMLBrowser unBrowserHandle, bool bBackgroundMode ) override;

	// Scale the output display space by this factor, this is useful when displaying content on high dpi devices.
	// Specifies the ratio between physical and logical pixels.
	void SetDPIScalingFactor( HHTMLBrowser unBrowserHandle, float flDPIScaling ) override;

	// CALLBACKS
	//
	//  These set of functions are used as responses to callback requests
	//

	// You MUST call this in response to a HTML_StartRequest_t callback
	//  Set bAllowed to true to allow this navigation, false to cancel it and stay 
	// on the current page. You can use this feature to limit the valid pages
	// allowed in your HTML surface.
	void AllowStartRequest( HHTMLBrowser unBrowserHandle, bool bAllowed ) override;

	// You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
	//  Set bResult to true for the OK option of a confirm, use false otherwise
	void JSDialogResponse( HHTMLBrowser unBrowserHandle, bool bResult ) override;

	// You MUST call this in response to a HTML_FileOpenDialog_t callback
	IGNOREATTR()
	void FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles ) override;

private:
    // Private constructor and destructor for singleton
    CSteamHTMLSurface();
    ~CSteamHTMLSurface();

    // Delete copy constructor and assignment operator
    CSteamHTMLSurface(const CSteamHTMLSurface&) = delete;
    CSteamHTMLSurface& operator=(const CSteamHTMLSurface&) = delete;
};

#endif // VAPORCORE_STEAM_HTML_SURFACE_H
