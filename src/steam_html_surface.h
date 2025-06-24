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

enum EHTMLMouseButton
{
	eHTMLMouseButton_Left = 0,
	eHTMLMouseButton_Right = 1,
	eHTMLMouseButton_Middle = 2,
};

enum EMouseCursor
{
	dc_user = 0,
	dc_none,
	dc_arrow,
	dc_ibeam,
	dc_hourglass,
	dc_waitarrow,
	dc_crosshair,
	dc_up,
	dc_sizenw,
	dc_sizese,
	dc_sizene,
	dc_sizesw,
	dc_sizew,
	dc_sizee,
	dc_sizen,
	dc_sizes,
	dc_sizewe,
	dc_sizens,
	dc_sizeall,
	dc_no,
	dc_hand,
	dc_blank, // don't show any custom cursor, just use your default
	dc_middle_pan,
	dc_north_pan,
	dc_north_east_pan,
	dc_east_pan,
	dc_south_east_pan,
	dc_south_pan,
	dc_south_west_pan,
	dc_west_pan,
	dc_north_west_pan,
	dc_alias,
	dc_cell,
	dc_colresize,
	dc_copycur,
	dc_verticaltext,
	dc_rowresize,
	dc_zoomin,
	dc_zoomout,
	dc_help,
	dc_custom,

	dc_last, // custom cursors start from this value and up
};

enum EHTMLKeyModifiers
{
	eHTMLKeyModifier_None = 0,
	eHTMLKeyModifier_AltDown = 1 << 0,
	eHTMLKeyModifier_CrtlDown = 1 << 1,
	eHTMLKeyModifier_ShiftDown = 1 << 2,
};

//-----------------------------------------------------------------------------
// Purpose: Functions for displaying HTML pages and interacting with them
//-----------------------------------------------------------------------------
class Steam_HTML_Surface :
	public ISteamHTMLSurface
{
private:
    // Singleton instance
    static Steam_HTML_Surface* s_pInstance;

public:
    Steam_HTML_Surface();
    ~Steam_HTML_Surface();

    // Helper methods
    static Steam_HTML_Surface* GetInstance();
    static void ReleaseInstance();

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

	// Zoom the current page by flZoom ( from 0.0 to 4.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
	void SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY ) override;

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
	void FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles ) override;
};

#endif // VAPORCORE_STEAM_HTML_SURFACE_H
