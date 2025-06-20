/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_http.h"
#include "logger.h"

// Static instance
Steam_HTTP* Steam_HTTP::s_pInstance = nullptr;

Steam_HTTP::Steam_HTTP()
{
    VLOG_INFO("Steam_HTTP constructor called");
}

Steam_HTTP::~Steam_HTTP()
{
    VLOG_INFO("Steam_HTTP destructor called");
}

// Initializes a new HTTP request, returning a handle to use in further operations on it.  Requires
// the method (GET or POST) and the absolute URL for the request.  Only http requests (ie, not https) are
// currently supported, so this string must start with http:// or https:// and should look like http://store.steampowered.com/app/250/ 
// or such.
HTTPRequestHandle Steam_HTTP::CreateHTTPRequest( EHTTPMethod eHTTPRequestMethod, const char *pchAbsoluteURL )
{
    VLOG_INFO("CreateHTTPRequest called - Method: %d, URL: %s", eHTTPRequestMethod, pchAbsoluteURL);
    return 0;
}

// Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
// sending the request.  This is just so the caller can easily keep track of which callbacks go with which request data.
bool Steam_HTTP::SetHTTPRequestContextValue( HTTPRequestHandle hRequest, uint64 ulContextValue )
{
    VLOG_INFO("SetHTTPRequestContextValue called - Request: %u, Context: %u", hRequest, ulContextValue);
    return true;
}

// Set a timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
// timeout is 60 seconds if you don't call this.  Returns false if the handle is invalid, or the request
// has already been sent.
bool Steam_HTTP::SetHTTPRequestNetworkActivityTimeout( HTTPRequestHandle hRequest, uint32 unTimeoutSeconds )
{
    VLOG_INFO("SetHTTPRequestNetworkActivityTimeout called - Request: %u, Timeout: %u", hRequest, unTimeoutSeconds);
    return true;
}

// Set a request header value for the request, must be called prior to sending the request.  Will 
// return false if the handle is invalid or the request is already sent.
bool Steam_HTTP::SetHTTPRequestHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue )
{
    VLOG_INFO("SetHTTPRequestHeaderValue called - Request: %u, Header: %s, Value: %s", hRequest, pchHeaderName, pchHeaderValue);
    return true;
}

// Set a GET or POST parameter value on the request, which is set will depend on the EHTTPMethod specified
// when creating the request.  Must be called prior to sending the request.  Will return false if the 
// handle is invalid or the request is already sent.
bool Steam_HTTP::SetHTTPRequestGetOrPostParameter( HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue )
{
    VLOG_INFO("SetHTTPRequestGetOrPostParameter called - Request: %u, Param: %s, Value: %s", hRequest, pchParamName, pchParamValue);
    return true;
}

// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
// asyncronous response via callback.
//
// Note: If the user is in offline mode in Steam, then this will add a only-if-cached cache-control 
// header and only do a local cache lookup rather than sending any actual remote request.
bool Steam_HTTP::SendHTTPRequest( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle )
{
    VLOG_INFO("SendHTTPRequest called - Request: %u, Call Handle: %u", hRequest, pCallHandle);
    return true;
}

// Defers a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the tail of the queue.  Returns false on invalid handle, or if the request is not yet sent.
bool Steam_HTTP::DeferHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO("DeferHTTPRequest called - Request: %u", hRequest);
    return true;
}

// Prioritizes a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the head of the queue.  Returns false on invalid handle, or if the request is not yet sent.
bool Steam_HTTP::PrioritizeHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO("PrioritizeHTTPRequest called - Request: %u", hRequest);
    return true;
}

// Checks if a response header is present in a HTTP response given a handle from HTTPRequestCompleted_t, also 
// returns the size of the header value if present so the caller and allocate a correctly sized buffer for
// GetHTTPResponseHeaderValue.
bool Steam_HTTP::GetHTTPResponseHeaderSize( HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize )
{
    VLOG_INFO("GetHTTPResponseHeaderSize called - Request: %u, Header: %s", hRequest, pchHeaderName);
    return true;
}

// Gets header values from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the
// header is not present or if your buffer is too small to contain it's value.  You should first call 
// BGetHTTPResponseHeaderSize to check for the presence of the header and to find out the size buffer needed.
bool Steam_HTTP::GetHTTPResponseHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize )
{
    VLOG_INFO("GetHTTPResponseHeaderValue called - Request: %u, Header: %s, Buffer: %p, Size: %u", hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
    return true;
}

// Gets the size of the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid.
bool Steam_HTTP::GetHTTPResponseBodySize( HTTPRequestHandle hRequest, uint32 *unBodySize )
{
    VLOG_INFO("GetHTTPResponseBodySize called - Request: %u, Body Size: %p", hRequest, unBodySize);
    return true;
}

// Gets the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid or if the provided buffer is not the correct size.  Use BGetHTTPResponseBodySize first to find out
// the correct buffer size to use.
bool Steam_HTTP::GetHTTPResponseBodyData( HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize )
{
    VLOG_INFO("GetHTTPResponseBodyData called - Request: %u, Buffer: %p, Size: %u", hRequest, pBodyDataBuffer, unBufferSize);
    return true;
}

// Releases an HTTP response handle, should always be called to free resources after receiving a HTTPRequestCompleted_t
// callback and finishing using the response.
bool Steam_HTTP::ReleaseHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO("ReleaseHTTPRequest called - Request: %u", hRequest);
    return true;
}

// Gets progress on downloading the body for the request.  This will be zero unless a response header has already been
// received which included a content-length field.  For responses that contain no content-length it will report
// zero for the duration of the request as the size is unknown until the connection closes.
bool Steam_HTTP::GetHTTPDownloadProgressPct( HTTPRequestHandle hRequest, float *pflPercentOut )
{
    VLOG_INFO("GetHTTPDownloadProgressPct called - Request: %u, Percent: %f", hRequest, pflPercentOut);
    return true;
}

// Helper methods
Steam_HTTP* Steam_HTTP::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_HTTP();
    }
    return s_pInstance;
}

void Steam_HTTP::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}
