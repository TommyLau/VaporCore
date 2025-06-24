/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_HTTP_H
#define VAPORCORE_STEAM_HTTP_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamhttp.h>
#include <isteamhttp001.h>

//-----------------------------------------------------------------------------
// Purpose: interface to building depots
//-----------------------------------------------------------------------------
class Steam_HTTP :
    public ISteamHTTP,
    public ISteamHTTP001
{
private:
    // Singleton instance
    static Steam_HTTP* s_pInstance;

public:
    Steam_HTTP();
    ~Steam_HTTP();

    // Helper methods
    static Steam_HTTP* GetInstance();
    static void ReleaseInstance();

	// Initializes a new HTTP request, returning a handle to use in further operations on it.  Requires
	// the method (GET or POST) and the absolute URL for the request.  Only http requests (ie, not https) are
	// currently supported, so this string must start with http:// or https:// and should look like http://store.steampowered.com/app/250/ 
	// or such.
	HTTPRequestHandle CreateHTTPRequest( EHTTPMethod eHTTPRequestMethod, const char *pchAbsoluteURL ) override;

	// Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
	// sending the request.  This is just so the caller can easily keep track of which callbacks go with which request data.
	bool SetHTTPRequestContextValue( HTTPRequestHandle hRequest, uint64 ulContextValue ) override;

	// Set a timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
	// timeout is 60 seconds if you don't call this.  Returns false if the handle is invalid, or the request
	// has already been sent.
	bool SetHTTPRequestNetworkActivityTimeout( HTTPRequestHandle hRequest, uint32 unTimeoutSeconds ) override;

	// Set a request header value for the request, must be called prior to sending the request.  Will 
	// return false if the handle is invalid or the request is already sent.
	bool SetHTTPRequestHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue ) override;

	// Set a GET or POST parameter value on the request, which is set will depend on the EHTTPMethod specified
	// when creating the request.  Must be called prior to sending the request.  Will return false if the 
	// handle is invalid or the request is already sent.
	bool SetHTTPRequestGetOrPostParameter( HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue ) override;

	// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
	// asynchronous response via callback.
	//
	// Note: If the user is in offline mode in Steam, then this will add a only-if-cached cache-control 
	// header and only do a local cache lookup rather than sending any actual remote request.
	bool SendHTTPRequest( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle ) override;

	// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
	// asynchronous response via callback for completion, and listen for HTTPRequestHeadersReceived_t and 
	// HTTPRequestDataReceived_t callbacks while streaming.
	bool SendHTTPRequestAndStreamResponse( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle ) override;

	// Defers a request you have sent, the actual HTTP client code may have many requests queued, and this will move
	// the specified request to the tail of the queue.  Returns false on invalid handle, or if the request is not yet sent.
	bool DeferHTTPRequest( HTTPRequestHandle hRequest ) override;

	// Prioritizes a request you have sent, the actual HTTP client code may have many requests queued, and this will move
	// the specified request to the head of the queue.  Returns false on invalid handle, or if the request is not yet sent.
	bool PrioritizeHTTPRequest( HTTPRequestHandle hRequest ) override;

	// Checks if a response header is present in a HTTP response given a handle from HTTPRequestCompleted_t, also 
	// returns the size of the header value if present so the caller and allocate a correctly sized buffer for
	// GetHTTPResponseHeaderValue.
	bool GetHTTPResponseHeaderSize( HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize ) override;

	// Gets header values from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the
	// header is not present or if your buffer is too small to contain it's value.  You should first call 
	// BGetHTTPResponseHeaderSize to check for the presence of the header and to find out the size buffer needed.
	bool GetHTTPResponseHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize ) override;

	// Gets the size of the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
	// handle is invalid.
	bool GetHTTPResponseBodySize( HTTPRequestHandle hRequest, uint32 *unBodySize ) override;

	// Gets the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
	// handle is invalid or is to a streaming response, or if the provided buffer is not the correct size.  Use BGetHTTPResponseBodySize first to find out
	// the correct buffer size to use.
	bool GetHTTPResponseBodyData( HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize ) override;

	// Gets the body data from a streaming HTTP response given a handle from HTTPRequestDataReceived_t. Will return false if the 
	// handle is invalid or is to a non-streaming response (meaning it wasn't sent with SendHTTPRequestAndStreamResponse), or if the buffer size and offset 
	// do not match the size and offset sent in HTTPRequestDataReceived_t.
	bool GetHTTPStreamingResponseBodyData( HTTPRequestHandle hRequest, uint32 cOffset, uint8 *pBodyDataBuffer, uint32 unBufferSize ) override;

	// Releases an HTTP response handle, should always be called to free resources after receiving a HTTPRequestCompleted_t
	// callback and finishing using the response.
	bool ReleaseHTTPRequest( HTTPRequestHandle hRequest ) override;

	// Gets progress on downloading the body for the request.  This will be zero unless a response header has already been
	// received which included a content-length field.  For responses that contain no content-length it will report
	// zero for the duration of the request as the size is unknown until the connection closes.
	bool GetHTTPDownloadProgressPct( HTTPRequestHandle hRequest, float *pflPercentOut ) override;

	// Sets the body for an HTTP Post request.  Will fail and return false on a GET request, and will fail if POST params
	// have already been set for the request.  Setting this raw body makes it the only contents for the post, the pchContentType
	// parameter will set the content-type header for the request so the server may know how to interpret the body.
	bool SetHTTPRequestRawPostBody( HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBody, uint32 unBodyLen ) override;

	// Creates a cookie container handle which you must later free with ReleaseCookieContainer().  If bAllowResponsesToModify=true
	// than any response to your requests using this cookie container may add new cookies which may be transmitted with
	// future requests.  If bAllowResponsesToModify=false than only cookies you explicitly set will be sent.  This API is just for
	// during process lifetime, after steam restarts no cookies are persisted and you have no way to access the cookie container across
	// repeat executions of your process.
	HTTPCookieContainerHandle CreateCookieContainer( bool bAllowResponsesToModify ) override;

	// Release a cookie container you are finished using, freeing it's memory
	bool ReleaseCookieContainer( HTTPCookieContainerHandle hCookieContainer ) override;

	// Adds a cookie to the specified cookie container that will be used with future requests.
	bool SetCookie( HTTPCookieContainerHandle hCookieContainer, const char *pchHost, const char *pchUrl, const char *pchCookie ) override;

	// Set the cookie container to use for a HTTP request
	bool SetHTTPRequestCookieContainer( HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer ) override;

	// Set the extra user agent info for a request, this doesn't clobber the normal user agent, it just adds the extra info on the end
	bool SetHTTPRequestUserAgentInfo( HTTPRequestHandle hRequest, const char *pchUserAgentInfo ) override;

	// Set that https request should require verified SSL certificate via machines certificate trust store
	bool SetHTTPRequestRequiresVerifiedCertificate( HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate ) override;

	// Set an absolute timeout on the HTTP request, this is just a total time timeout different than the network activity timeout
	// which can bump everytime we get more data
	bool SetHTTPRequestAbsoluteTimeoutMS( HTTPRequestHandle hRequest, uint32 unMilliseconds ) override;

	// Check if the reason the request failed was because we timed it out (rather than some harder failure)
	bool GetHTTPRequestWasTimedOut( HTTPRequestHandle hRequest, bool *pbWasTimedOut ) override;
};

#endif // VAPORCORE_STEAM_HTTP_H
