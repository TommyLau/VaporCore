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
#include "steam_http.h"

CSteamHTTP::CSteamHTTP()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamHTTP::~CSteamHTTP()
{
    VLOG_INFO(__FUNCTION__);
}

// Initializes a new HTTP request, returning a handle to use in further operations on it.  Requires
// the method (GET or POST) and the absolute URL for the request.  Both http and https are supported,
// so this string must start with http:// or https:// and should look like http://store.steampowered.com/app/250/ 
// or such.
HTTPRequestHandle CSteamHTTP::CreateHTTPRequest( EHTTPMethod eHTTPRequestMethod, const char *pchAbsoluteURL )
{
    VLOG_INFO(__FUNCTION__ " - Method: %d, URL: %s", eHTTPRequestMethod, pchAbsoluteURL);
    return 0;
}

// Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
// sending the request.  This is just so the caller can easily keep track of which callbacks go with which request data.
bool CSteamHTTP::SetHTTPRequestContextValue( HTTPRequestHandle hRequest, uint64 ulContextValue )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Context: %u", hRequest, ulContextValue);
    return true;
}

// Set a timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
// timeout is 60 seconds if you don't call this.  Returns false if the handle is invalid, or the request
// has already been sent.
bool CSteamHTTP::SetHTTPRequestNetworkActivityTimeout( HTTPRequestHandle hRequest, uint32 unTimeoutSeconds )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Timeout: %u", hRequest, unTimeoutSeconds);
    return true;
}

// Set a request header value for the request, must be called prior to sending the request.  Will 
// return false if the handle is invalid or the request is already sent.
bool CSteamHTTP::SetHTTPRequestHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Header: %s, Value: %s", hRequest, pchHeaderName, pchHeaderValue);
    return true;
}

// Set a GET or POST parameter value on the request, which is set will depend on the EHTTPMethod specified
// when creating the request.  Must be called prior to sending the request.  Will return false if the 
// handle is invalid or the request is already sent.
bool CSteamHTTP::SetHTTPRequestGetOrPostParameter( HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Param: %s, Value: %s", hRequest, pchParamName, pchParamValue);
    return true;
}

// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
// asynchronous response via callback.
//
// Note: If the user is in offline mode in Steam, then this will add a only-if-cached cache-control 
// header and only do a local cache lookup rather than sending any actual remote request.
bool CSteamHTTP::SendHTTPRequest( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Call Handle: %u", hRequest, pCallHandle);
    return true;
}

// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
// asynchronous response via callback for completion, and listen for HTTPRequestHeadersReceived_t and 
// HTTPRequestDataReceived_t callbacks while streaming.
bool CSteamHTTP::SendHTTPRequestAndStreamResponse( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Call Handle: %u", hRequest, pCallHandle);
    return true;
}

// Defers a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the tail of the queue.  Returns false on invalid handle, or if the request is not yet sent.
bool CSteamHTTP::DeferHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u", hRequest);
    return true;
}

// Prioritizes a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the head of the queue.  Returns false on invalid handle, or if the request is not yet sent.
bool CSteamHTTP::PrioritizeHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u", hRequest);
    return true;
}

// Checks if a response header is present in a HTTP response given a handle from HTTPRequestCompleted_t, also 
// returns the size of the header value if present so the caller and allocate a correctly sized buffer for
// GetHTTPResponseHeaderValue.
bool CSteamHTTP::GetHTTPResponseHeaderSize( HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Header: %s", hRequest, pchHeaderName);
    return true;
}

// Gets header values from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the
// header is not present or if your buffer is too small to contain it's value.  You should first call 
// BGetHTTPResponseHeaderSize to check for the presence of the header and to find out the size buffer needed.
bool CSteamHTTP::GetHTTPResponseHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Header: %s, Buffer: %p, Size: %u", hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
    return true;
}

// Gets the size of the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid.
bool CSteamHTTP::GetHTTPResponseBodySize( HTTPRequestHandle hRequest, uint32 *unBodySize )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Body Size: %p", hRequest, unBodySize);
    return true;
}

// Gets the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid or is to a streaming response, or if the provided buffer is not the correct size.  Use BGetHTTPResponseBodySize first to find out
// the correct buffer size to use.
bool CSteamHTTP::GetHTTPResponseBodyData( HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Buffer: %p, Size: %u", hRequest, pBodyDataBuffer, unBufferSize);
    return true;
}

// Gets the body data from a streaming HTTP response given a handle from HTTPRequestDataReceived_t. Will return false if the 
// handle is invalid or is to a non-streaming response (meaning it wasn't sent with SendHTTPRequestAndStreamResponse), or if the buffer size and offset 
// do not match the size and offset sent in HTTPRequestDataReceived_t.
bool CSteamHTTP::GetHTTPStreamingResponseBodyData( HTTPRequestHandle hRequest, uint32 cOffset, uint8 *pBodyDataBuffer, uint32 unBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Offset: %u, Buffer: %p, Size: %u", 
              hRequest, cOffset, pBodyDataBuffer, unBufferSize);
    return true;
}

// Releases an HTTP response handle, should always be called to free resources after receiving a HTTPRequestCompleted_t
// callback and finishing using the response.
bool CSteamHTTP::ReleaseHTTPRequest( HTTPRequestHandle hRequest )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u", hRequest);
    return true;
}

// Gets progress on downloading the body for the request.  This will be zero unless a response header has already been
// received which included a content-length field.  For responses that contain no content-length it will report
// zero for the duration of the request as the size is unknown until the connection closes.
bool CSteamHTTP::GetHTTPDownloadProgressPct( HTTPRequestHandle hRequest, float *pflPercentOut )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Percent: %f", hRequest, pflPercentOut);
    return true;
}

// Sets the body for an HTTP Post request.  Will fail and return false on a GET request, and will fail if POST params
// have already been set for the request.  Setting this raw body makes it the only contents for the post, the pchContentType
// parameter will set the content-type header for the request so the server may know how to interpret the body.
bool CSteamHTTP::SetHTTPRequestRawPostBody( HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBody, uint32 unBodyLen )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Content Type: %s, Body: %p, Length: %u", hRequest, pchContentType, pubBody, unBodyLen);
    return true;
}

// Creates a cookie container handle which you must later free with ReleaseCookieContainer().  If bAllowResponsesToModify=true
// than any response to your requests using this cookie container may add new cookies which may be transmitted with
// future requests.  If bAllowResponsesToModify=false than only cookies you explicitly set will be sent.  This API is just for
// during process lifetime, after steam restarts no cookies are persisted and you have no way to access the cookie container across
// repeat executions of your process.
HTTPCookieContainerHandle CSteamHTTP::CreateCookieContainer( bool bAllowResponsesToModify )
{
    VLOG_INFO(__FUNCTION__ " - AllowResponsesToModify: %s", bAllowResponsesToModify ? "true" : "false");
    return 0;
}

// Release a cookie container you are finished using, freeing it's memory
bool CSteamHTTP::ReleaseCookieContainer( HTTPCookieContainerHandle hCookieContainer )
{
    VLOG_INFO(__FUNCTION__ " - Container: %u", hCookieContainer);
    return true;
}

// Adds a cookie to the specified cookie container that will be used with future requests.
bool CSteamHTTP::SetCookie( HTTPCookieContainerHandle hCookieContainer, const char *pchHost, const char *pchUrl, const char *pchCookie )
{
    VLOG_INFO(__FUNCTION__ " - Container: %u, Host: %s, URL: %s, Cookie: %s", 
              hCookieContainer, pchHost, pchUrl, pchCookie);
    return true;
}

// Set the cookie container to use for a HTTP request
bool CSteamHTTP::SetHTTPRequestCookieContainer( HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Container: %u", hRequest, hCookieContainer);
    return true;
}

// Set the extra user agent info for a request, this doesn't clobber the normal user agent, it just adds the extra info on the end
bool CSteamHTTP::SetHTTPRequestUserAgentInfo( HTTPRequestHandle hRequest, const char *pchUserAgentInfo )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, User Agent: %s", hRequest, pchUserAgentInfo);
    return true;
}

// Set that https request should require verified SSL certificate via machines certificate trust store
bool CSteamHTTP::SetHTTPRequestRequiresVerifiedCertificate( HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Require Verified: %s", 
              hRequest, bRequireVerifiedCertificate ? "true" : "false");
    return true;
}

// Set an absolute timeout on the HTTP request, this is just a total time timeout different than the network activity timeout
// which can bump everytime we get more data
bool CSteamHTTP::SetHTTPRequestAbsoluteTimeoutMS( HTTPRequestHandle hRequest, uint32 unMilliseconds )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u, Timeout: %u ms", hRequest, unMilliseconds);
    return true;
}

// Check if the reason the request failed was because we timed it out (rather than some harder failure)
bool CSteamHTTP::GetHTTPRequestWasTimedOut( HTTPRequestHandle hRequest, bool *pbWasTimedOut )
{
    VLOG_INFO(__FUNCTION__ " - Request: %u", hRequest);
    return true;
}
