/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_html_surface.h"
#include "logger.h"

// Static instance
Steam_HTML_Surface* Steam_HTML_Surface::s_pInstance = nullptr;

Steam_HTML_Surface::Steam_HTML_Surface()
{
    VLOG_INFO("Steam_HTML_Surface constructor called");
}

Steam_HTML_Surface::~Steam_HTML_Surface()
{
    VLOG_INFO("Steam_HTML_Surface destructor called");
}

// Helper methods
Steam_HTML_Surface* Steam_HTML_Surface::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_HTML_Surface();
    }
    return s_pInstance;
}

void Steam_HTML_Surface::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

// Must call init and shutdown when starting/ending use of the interface
bool Steam_HTML_Surface::Init()
{
    VLOG_DEBUG("Steam_HTML_Surface::Init called");
    return true;
}

bool Steam_HTML_Surface::Shutdown()
{
    VLOG_DEBUG("Steam_HTML_Surface::Shutdown called");
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
SteamAPICall_t Steam_HTML_Surface::CreateBrowser( const char *pchUserAgent, const char *pchUserCSS )
{
    VLOG_DEBUG("Steam_HTML_Surface::CreateBrowser called - UserAgent: %s", pchUserAgent ? pchUserAgent : "null");
    return 0;
}

// Call this when you are done with a html surface, this lets us free the resources being used by it
void Steam_HTML_Surface::RemoveBrowser( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::RemoveBrowser called - Handle: %u", unBrowserHandle);
}

// Navigate to this URL, results in a HTML_StartRequest_t as the request commences 
void Steam_HTML_Surface::LoadURL( HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData )
{
    VLOG_DEBUG("Steam_HTML_Surface::LoadURL called - Handle: %u, URL: %s", unBrowserHandle, pchURL ? pchURL : "null");
}

// Tells the surface the size in pixels to display the surface
void Steam_HTML_Surface::SetSize( HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetSize called - Handle: %u, Size: %ux%u", unBrowserHandle, unWidth, unHeight);
}

// Stop the load of the current html page
void Steam_HTML_Surface::StopLoad( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::StopLoad called - Handle: %u", unBrowserHandle);
}

// Reload (most likely from local cache) the current page
void Steam_HTML_Surface::Reload( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::Reload called - Handle: %u", unBrowserHandle);
}

// navigate back in the page history
void Steam_HTML_Surface::GoBack( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::GoBack called - Handle: %u", unBrowserHandle);
}

// navigate forward in the page history
void Steam_HTML_Surface::GoForward( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::GoForward called - Handle: %u", unBrowserHandle);
}

// add this header to any url requests from this browser
void Steam_HTML_Surface::AddHeader( HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue )
{
    VLOG_DEBUG("Steam_HTML_Surface::AddHeader called - Handle: %u, Key: %s, Value: %s", 
               unBrowserHandle, pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// run this javascript script in the currently loaded page
void Steam_HTML_Surface::ExecuteJavascript( HHTMLBrowser unBrowserHandle, const char *pchScript )
{
    VLOG_DEBUG("Steam_HTML_Surface::ExecuteJavascript called - Handle: %u, Script: %s", 
               unBrowserHandle, pchScript ? pchScript : "null");
}

// Mouse click and mouse movement commands
void Steam_HTML_Surface::MouseUp( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_DEBUG("Steam_HTML_Surface::MouseUp called - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

void Steam_HTML_Surface::MouseDown( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_DEBUG("Steam_HTML_Surface::MouseDown called - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

void Steam_HTML_Surface::MouseDoubleClick( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
    VLOG_DEBUG("Steam_HTML_Surface::MouseDoubleClick called - Handle: %u, Button: %d", unBrowserHandle, eMouseButton);
}

// x and y are relative to the HTML bounds
void Steam_HTML_Surface::MouseMove( HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_DEBUG("Steam_HTML_Surface::MouseMove called - Handle: %u, Position: %d,%d", unBrowserHandle, x, y);
}

// nDelta is pixels of scroll
void Steam_HTML_Surface::MouseWheel( HHTMLBrowser unBrowserHandle, int32 nDelta )
{
    VLOG_DEBUG("Steam_HTML_Surface::MouseWheel called - Handle: %u, Delta: %d", unBrowserHandle, nDelta);
}

// keyboard interactions, native keycode is the virtual key code value from your OS
void Steam_HTML_Surface::KeyDown( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_DEBUG("Steam_HTML_Surface::KeyDown called - Handle: %u, KeyCode: %u, Modifiers: %d", 
               unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

void Steam_HTML_Surface::KeyUp( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_DEBUG("Steam_HTML_Surface::KeyUp called - Handle: %u, KeyCode: %u, Modifiers: %d", 
               unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

// cUnicodeChar is the unicode character point for this keypress (and potentially multiple chars per press)
void Steam_HTML_Surface::KeyChar( HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers )
{
    VLOG_DEBUG("Steam_HTML_Surface::KeyChar called - Handle: %u, Char: %u, Modifiers: %d", 
               unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

// programmatically scroll this many pixels on the page
void Steam_HTML_Surface::SetHorizontalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetHorizontalScroll called - Handle: %u, Scroll: %u", 
               unBrowserHandle, nAbsolutePixelScroll);
}

void Steam_HTML_Surface::SetVerticalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetVerticalScroll called - Handle: %u, Scroll: %u", 
               unBrowserHandle, nAbsolutePixelScroll);
}

// tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
void Steam_HTML_Surface::SetKeyFocus( HHTMLBrowser unBrowserHandle, bool bHasKeyFocus )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetKeyFocus called - Handle: %u, HasFocus: %s", 
               unBrowserHandle, bHasKeyFocus ? "true" : "false");
}

// open the current pages html code in the local editor of choice, used for debugging
void Steam_HTML_Surface::ViewSource( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::ViewSource called - Handle: %u", unBrowserHandle);
}

// copy the currently selected text on the html page to the local clipboard
void Steam_HTML_Surface::CopyToClipboard( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::CopyToClipboard called - Handle: %u", unBrowserHandle);
}

// paste from the local clipboard to the current html page
void Steam_HTML_Surface::PasteFromClipboard( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::PasteFromClipboard called - Handle: %u", unBrowserHandle);
}

// find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
void Steam_HTML_Surface::Find( HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse )
{
    VLOG_DEBUG("Steam_HTML_Surface::Find called - Handle: %u, SearchStr: %s, InFind: %s, Reverse: %s", 
               unBrowserHandle, pchSearchStr ? pchSearchStr : "null", 
               bCurrentlyInFind ? "true" : "false", bReverse ? "true" : "false");
}

// cancel a currently running find
void Steam_HTML_Surface::StopFind( HHTMLBrowser unBrowserHandle )
{
    VLOG_DEBUG("Steam_HTML_Surface::StopFind called - Handle: %u", unBrowserHandle);
}

// return details about the link at position x,y on the current page
void Steam_HTML_Surface::GetLinkAtPosition( HHTMLBrowser unBrowserHandle, int x, int y )
{
    VLOG_DEBUG("Steam_HTML_Surface::GetLinkAtPosition called - Handle: %u, Position: %d,%d", unBrowserHandle, x, y);
}

// set a webcookie for the hostname in question
void Steam_HTML_Surface::SetCookie( const char *pchHostname, const char *pchKey, const char *pchValue, 
                                   const char *pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetCookie called - Hostname: %s, Key: %s, Value: %s", 
               pchHostname ? pchHostname : "null", pchKey ? pchKey : "null", pchValue ? pchValue : "null");
}

// Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
void Steam_HTML_Surface::SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY )
{
    VLOG_DEBUG("Steam_HTML_Surface::SetPageScaleFactor called - Handle: %u, Zoom: %f, Point: %d,%d", 
               unBrowserHandle, flZoom, nPointX, nPointY);
}

// Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
// more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
// all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
// When background mode is disabled, any video or audio objects with that property will resume with ".play()".
void Steam_HTML_Surface::SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode)
{
    VLOG_DEBUG("Steam_HTML_Surface::SetBackgroundMode called - Handle: %u, BackgroundMode: %s",
               unBrowserHandle, bBackgroundMode ? "true" : "false");
}

//
//  These set of functions are used as responses to callback requests
//

// You MUST call this in response to a HTML_StartRequest_t callback
//  Set bAllowed to true to allow this navigation, false to cancel it and stay 
// on the current page. You can use this feature to limit the valid pages
// allowed in your HTML surface.
void Steam_HTML_Surface::AllowStartRequest( HHTMLBrowser unBrowserHandle, bool bAllowed )
{
    VLOG_DEBUG("Steam_HTML_Surface::AllowStartRequest called - Handle: %u, Allowed: %s", 
               unBrowserHandle, bAllowed ? "true" : "false");
}

// You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
//  Set bResult to true for the OK option of a confirm, use false otherwise
void Steam_HTML_Surface::JSDialogResponse( HHTMLBrowser unBrowserHandle, bool bResult )
{
    VLOG_DEBUG("Steam_HTML_Surface::JSDialogResponse called - Handle: %u, Result: %s", 
               unBrowserHandle, bResult ? "true" : "false");
}

// You MUST call this in response to a HTML_FileOpenDialog_t callback
void Steam_HTML_Surface::FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles )
{
    VLOG_DEBUG("Steam_HTML_Surface::FileLoadDialogResponse called - Handle: %u", unBrowserHandle);
}
