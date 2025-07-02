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
#include "steam_html_surface.h"

CSteamHTMLSurface::CSteamHTMLSurface()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamHTMLSurface::~CSteamHTMLSurface()
{
    VLOG_INFO(__FUNCTION__);
}

// Must call init and shutdown when starting/ending use of the interface
bool CSteamHTMLSurface::Init()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

bool CSteamHTMLSurface::Shutdown()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

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
SteamAPICall_t CSteamHTMLSurface::CreateBrowser( const char *pchUserAgent, const char *pchUserCSS )
{
    VLOG_INFO(__FUNCTION__ " - UserAgent: %s", pchUserAgent ? pchUserAgent : "null");
    return 0;
}

// Call this when you are done with a html surface, this lets us free the resources being used by it
void CSteamHTMLSurface::RemoveBrowser( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// Navigate to this URL, results in a HTML_StartRequest_t as the request commences 
void CSteamHTMLSurface::LoadURL( HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, URL: %s", unBrowserHandle, pchURL ? pchURL : "null");
}

// Tells the surface the size in pixels to display the surface
void CSteamHTMLSurface::SetSize( HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Size: %ux%u", unBrowserHandle, unWidth, unHeight);
}

// Stop the load of the current html page
void CSteamHTMLSurface::StopLoad( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// Reload (most likely from local cache) the current page
void CSteamHTMLSurface::Reload( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// navigate back in the page history
void CSteamHTMLSurface::GoBack( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// navigate forward in the page history
void CSteamHTMLSurface::GoForward( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// add this header to any url requests from this browser
void CSteamHTMLSurface::AddHeader( HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Key: %s, Value: %s", 
               unBrowserHandle, pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// run this javascript script in the currently loaded page
void CSteamHTMLSurface::ExecuteJavascript( HHTMLBrowser unBrowserHandle, const char *pchScript )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Script: %s", 
               unBrowserHandle, pchScript ? pchScript : "null");
}

// Mouse click and mouse movement commands
void CSteamHTMLSurface::MouseUp( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

void CSteamHTMLSurface::MouseDown( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

void CSteamHTMLSurface::MouseDoubleClick( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

// x and y are relative to the HTML bounds
void CSteamHTMLSurface::MouseMove( HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Position: %d,%d", unBrowserHandle, x, y);
}

// nDelta is pixels of scroll
void CSteamHTMLSurface::MouseWheel( HHTMLBrowser unBrowserHandle, int32 nDelta )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Delta: %d", unBrowserHandle, nDelta);
}

// keyboard interactions, native keycode is the virtual key code value from your OS
void CSteamHTMLSurface::KeyDown( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, KeyCode: %u, Modifiers: %d", 
               unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

void CSteamHTMLSurface::KeyUp( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, KeyCode: %u, Modifiers: %d", 
               unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

// cUnicodeChar is the unicode character point for this keypress (and potentially multiple chars per press)
void CSteamHTMLSurface::KeyChar( HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Char: %u, Modifiers: %d", 
               unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

// programmatically scroll this many pixels on the page
void CSteamHTMLSurface::SetHorizontalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Scroll: %u", 
               unBrowserHandle, nAbsolutePixelScroll);
}

void CSteamHTMLSurface::SetVerticalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Scroll: %u", 
               unBrowserHandle, nAbsolutePixelScroll);
}

// tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
void CSteamHTMLSurface::SetKeyFocus( HHTMLBrowser unBrowserHandle, bool bHasKeyFocus )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, HasFocus: %s", 
               unBrowserHandle, bHasKeyFocus ? "true" : "false");
}

// open the current pages html code in the local editor of choice, used for debugging
void CSteamHTMLSurface::ViewSource( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// copy the currently selected text on the html page to the local clipboard
void CSteamHTMLSurface::CopyToClipboard( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// paste from the local clipboard to the current html page
void CSteamHTMLSurface::PasteFromClipboard( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
void CSteamHTMLSurface::Find( HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, SearchStr: %s, InFind: %s, Reverse: %s", 
               unBrowserHandle, pchSearchStr ? pchSearchStr : "null", 
               bCurrentlyInFind ? "true" : "false", bReverse ? "true" : "false");
}

// cancel a currently running find
void CSteamHTMLSurface::StopFind( HHTMLBrowser unBrowserHandle )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}

// return details about the link at position x,y on the current page
void CSteamHTMLSurface::GetLinkAtPosition( HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Position: %d,%d", unBrowserHandle, x, y);
}

// set a webcookie for the hostname in question
void CSteamHTMLSurface::SetCookie( const char *pchHostname, const char *pchKey, const char *pchValue, 
                                   const char *pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly )
{
    VLOG_INFO(__FUNCTION__ " - Hostname: %s, Key: %s, Value: %s", 
               pchHostname ? pchHostname : "null", pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
void CSteamHTMLSurface::SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Zoom: %f, Point: %d,%d", 
               unBrowserHandle, flZoom, nPointX, nPointY);
}

// Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
// more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
// all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
// When background mode is disabled, any video or audio objects with that property will resume with ".play()".
void CSteamHTMLSurface::SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode)
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, BackgroundMode: %s",
               unBrowserHandle, bBackgroundMode ? "true" : "false");
}

// Scale the output display space by this factor, this is useful when displaying content on high dpi devices.
// Specifies the ratio between physical and logical pixels.
void CSteamHTMLSurface::SetDPIScalingFactor(HHTMLBrowser unBrowserHandle, float flDPIScaling)
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, DPIScaling: %f", unBrowserHandle, flDPIScaling);
}

//
//  These set of functions are used as responses to callback requests
//

// You MUST call this in response to a HTML_StartRequest_t callback
//  Set bAllowed to true to allow this navigation, false to cancel it and stay 
// on the current page. You can use this feature to limit the valid pages
// allowed in your HTML surface.
void CSteamHTMLSurface::AllowStartRequest( HHTMLBrowser unBrowserHandle, bool bAllowed )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Allowed: %s", 
               unBrowserHandle, bAllowed ? "true" : "false");
}

// You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
//  Set bResult to true for the OK option of a confirm, use false otherwise
void CSteamHTMLSurface::JSDialogResponse( HHTMLBrowser unBrowserHandle, bool bResult )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u, Result: %s", 
               unBrowserHandle, bResult ? "true" : "false");
}

// You MUST call this in response to a HTML_FileOpenDialog_t callback
void CSteamHTMLSurface::FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles )
{
    VLOG_INFO(__FUNCTION__ " - Handle: %u", unBrowserHandle);
}
