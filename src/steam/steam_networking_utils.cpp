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
#include "steam_networking_utils.h"

CSteamNetworkingUtils::CSteamNetworkingUtils()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamNetworkingUtils::~CSteamNetworkingUtils()
{
    VLOG_INFO(__FUNCTION__);
}

//
// Efficient message sending
//

/// Allocate and initialize a message object.  Usually the reason
/// you call this is to pass it to ISteamNetworkingSockets::SendMessages.
/// The returned object will have all of the relevant fields cleared to zero.
///
/// Optionally you can also request that this system allocate space to
/// hold the payload itself.  If cbAllocateBuffer is nonzero, the system
/// will allocate memory to hold a payload of at least cbAllocateBuffer bytes.
/// m_pData will point to the allocated buffer, m_cbSize will be set to the
/// size, and m_pfnFreeData will be set to the proper function to free up
/// the buffer.
///
/// If cbAllocateBuffer=0, then no buffer is allocated.  m_pData will be NULL,
/// m_cbSize will be zero, and m_pfnFreeData will be NULL.  You will need to
/// set each of these.
SteamNetworkingMessage_t *CSteamNetworkingUtils::AllocateMessage( int cbAllocateBuffer )
{
    VLOG_INFO(__FUNCTION__ " - cbAllocateBuffer: %d", cbAllocateBuffer);
    return nullptr;
}

//
// Access to Steam Datagram Relay (SDR) network
//

#ifdef STEAMNETWORKINGSOCKETS_ENABLE_SDR

/// Fetch current status of the relay network.
///
/// SteamRelayNetworkStatus_t is also a callback.  It will be triggered on
/// both the user and gameserver interfaces any time the status changes, or
/// ping measurement starts or stops.
///
/// SteamRelayNetworkStatus_t::m_eAvail is returned.  If you want
/// more details, you can pass a non-NULL value.
ESteamNetworkingAvailability CSteamNetworkingUtils::GetRelayNetworkStatus(SteamRelayNetworkStatus_t *pDetails)
{
    VLOG_INFO(__FUNCTION__ " pDetails: %p", pDetails);
    return k_ESteamNetworkingAvailability_Failed;
}

//
// "Ping location" functions
//
// We use the ping times to the valve relays deployed worldwide to
// generate a "marker" that describes the location of an Internet host.
// Given two such markers, we can estimate the network latency between
// two hosts, without sending any packets.  The estimate is based on the
// optimal route that is found through the Valve network.  If you are
// using the Valve network to carry the traffic, then this is precisely
// the ping you want.  If you are not, then the ping time will probably
// still be a reasonable estimate.
//
// This is extremely useful to select peers for matchmaking!
//
// The markers can also be converted to a string, so they can be transmitted.
// We have a separate library you can use on your app's matchmaking/coordinating
// server to manipulate these objects.  (See steamdatagram_gamecoordinator.h)

/// Return location info for the current host.  Returns the approximate
/// age of the data, in seconds, or -1 if no data is available.
///
/// It takes a few seconds to initialize access to the relay network.  If
/// you call this very soon after calling InitRelayNetworkAccess,
/// the data may not be available yet.
///
/// This always return the most up-to-date information we have available
/// right now, even if we are in the middle of re-calculating ping times.
float CSteamNetworkingUtils::GetLocalPingLocation(SteamNetworkPingLocation_t &result)
{
    VLOG_INFO(__FUNCTION__);
    return -1;
}

/// Estimate the round-trip latency between two arbitrary locations, in
/// milliseconds.  This is a conservative estimate, based on routing through
/// the relay network.  For most basic relayed connections, this ping time
/// will be pretty accurate, since it will be based on the route likely to
/// be actually used.
///
/// If a direct IP route is used (perhaps via NAT traversal), then the route
/// will be different, and the ping time might be better.  Or it might actually
/// be a bit worse!  Standard IP routing is frequently suboptimal!
///
/// But even in this case, the estimate obtained using this method is a
/// reasonable upper bound on the ping time.  (Also it has the advantage
/// of returning immediately and not sending any packets.)
///
/// In a few cases we might not able to estimate the route.  In this case
/// a negative value is returned.  k_nSteamNetworkingPing_Failed means
/// the reason was because of some networking difficulty.  (Failure to
/// ping, etc)  k_nSteamNetworkingPing_Unknown is returned if we cannot
/// currently answer the question for some other reason.
///
/// Do you need to be able to do this from a backend/matchmaking server?
/// You are looking for the "ticketgen" library.
int CSteamNetworkingUtils::EstimatePingTimeBetweenTwoLocations(const SteamNetworkPingLocation_t &location1, const SteamNetworkPingLocation_t &location2)
{
    VLOG_INFO(__FUNCTION__);
    return k_nSteamNetworkingPing_Unknown;
}

/// Same as EstimatePingTime, but assumes that one location is the local host.
/// This is a bit faster, especially if you need to calculate a bunch of
/// these in a loop to find the fastest one.
///
/// In rare cases this might return a slightly different estimate than combining
/// GetLocalPingLocation with EstimatePingTimeBetweenTwoLocations.  That's because
/// this function uses a slightly more complete set of information about what
/// route would be taken.
int CSteamNetworkingUtils::EstimatePingTimeFromLocalHost(const SteamNetworkPingLocation_t &remoteLocation)
{
    VLOG_INFO(__FUNCTION__);
    return k_nSteamNetworkingPing_Unknown;
}

/// Convert a ping location into a text format suitable for sending over the wire.
/// The format is a compact and human readable.  However, it is subject to change
/// so please do not parse it yourself.  Your buffer must be at least
/// k_cchMaxSteamNetworkingPingLocationString bytes.
void CSteamNetworkingUtils::ConvertPingLocationToString(const SteamNetworkPingLocation_t &location, char *pszBuf, int cchBufSize)
{
    VLOG_INFO(__FUNCTION__);
}

/// Parse back SteamNetworkPingLocation_t string.  Returns false if we couldn't understand
/// the string.
bool CSteamNetworkingUtils::ParsePingLocationString(const char *pszString, SteamNetworkPingLocation_t &result)
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

/// Check if the ping data of sufficient recency is available, and if
/// it's too old, start refreshing it.
///
/// Please only call this function when you *really* do need to force an
/// immediate refresh of the data.  (For example, in response to a specific
/// user input to refresh this information.)  Don't call it "just in case",
/// before every connection, etc.  That will cause extra traffic to be sent
/// for no benefit. The library will automatically refresh the information
/// as needed.
///
/// Returns true if sufficiently recent data is already available.
///
/// Returns false if sufficiently recent data is not available.  In this
/// case, ping measurement is initiated, if it is not already active.
/// (You cannot restart a measurement already in progress.)
///
/// You can use GetRelayNetworkStatus or listen for SteamRelayNetworkStatus_t
/// to know when ping measurement completes.
bool CSteamNetworkingUtils::CheckPingDataUpToDate(float flMaxAgeSeconds)
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

/// Return true if we are taking ping measurements to update our ping
/// location or select optimal routing.  Ping measurement typically takes
/// a few seconds, perhaps up to 10 seconds.
// Removed from Steam SDK v1.45, backward compatibility
bool CSteamNetworkingUtils::IsPingMeasurementInProgress()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

//
// List of Valve data centers, and ping times to them.  This might
// be useful to you if you are use our hosting, or just need to measure
// latency to a cloud data center where we are running relays.
//

/// Fetch ping time of best available relayed route from this host to
/// the specified data center.
int CSteamNetworkingUtils::GetPingToDataCenter(SteamNetworkingPOPID popID, SteamNetworkingPOPID *pViaRelayPoP)
{
    VLOG_INFO(__FUNCTION__);
    return -1;
}

/// Get *direct* ping time to the relays at the data center.
int CSteamNetworkingUtils::GetDirectPingToPOP(SteamNetworkingPOPID popID)
{
    VLOG_INFO(__FUNCTION__);
    return -1;
}

/// Get number of network points of presence in the config
int CSteamNetworkingUtils::GetPOPCount()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

/// Get list of all POP IDs.  Returns the number of entries that were filled into
/// your list.
int CSteamNetworkingUtils::GetPOPList(SteamNetworkingPOPID *list, int nListSz)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}
#endif // #ifdef STEAMNETWORKINGSOCKETS_ENABLE_SDR

//
// Misc
//

/// Fetch current timestamp.  This timer has the following properties:
///
/// - Monotonicity is guaranteed.
/// - The initial value will be at least 24*3600*30*1e6, i.e. about
///   30 days worth of microseconds.  In this way, the timestamp value of
///   0 will always be at least "30 days ago".  Also, negative numbers
///   will never be returned.
/// - Wraparound / overflow is not a practical concern.
///
/// If you are running under the debugger and stop the process, the clock
/// might not advance the full wall clock time that has elapsed between
/// calls.  If the process is not blocked from normal operation, the
/// timestamp values will track wall clock time, even if you don't call
/// the function frequently.
///
/// The value is only meaningful for this run of the process.  Don't compare
/// it to values obtained on another computer, or other runs of the same process.
SteamNetworkingMicroseconds CSteamNetworkingUtils::GetLocalTimestamp()
{
    VLOG_INFO(__FUNCTION__);
    return 0; // TODO: Implement actual timestamp logic
}

/// Set a function to receive network-related information that is useful for debugging.
/// This can be very useful during development, but it can also be useful for troubleshooting
/// problems with tech savvy end users.  If you have a console or other log that customers
/// can examine, these log messages can often be helpful to troubleshoot network issues.
/// (Especially any warning/error messages.)
///
/// The detail level indicates what message to invoke your callback on.  Lower numeric
/// value means more important, and the value you pass is the lowest priority (highest
/// numeric value) you wish to receive callbacks for.
///
/// Except when debugging, you should only use k_ESteamNetworkingSocketsDebugOutputType_Msg
/// or k_ESteamNetworkingSocketsDebugOutputType_Warning.  For best performance, do NOT
/// request a high detail level and then filter out messages in your callback.  This incurs
/// all of the expense of formatting the messages, which are then discarded.  Setting a high
/// priority value (low numeric value) here allows the library to avoid doing this work.
///
/// IMPORTANT: This may be called from a service thread, while we own a mutex, etc.
/// Your output function must be threadsafe and fast!  Do not make any other
/// Steamworks calls from within the handler.
void CSteamNetworkingUtils::SetDebugOutputFunction(ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pfnFunc)
{
    VLOG_INFO(__FUNCTION__ " eDetailLevel: %d, pfnFunc: %p", eDetailLevel, pfnFunc);
    // TODO: Implement debug output function setting
}

/// Set a configuration value.
/// - eValue: which value is being set
/// - eScope: Onto what type of object are you applying the setting?
/// - scopeArg: Which object you want to change?  (Ignored for global scope).  E.g. connection handle, listen socket handle, interface pointer, etc.
/// - eDataType: What type of data is in the buffer at pValue?  This must match the type of the variable exactly!
/// - pArg: Value to set it to.  You can pass NULL to remove a non-global setting at this scope,
///   causing the value for that object to use global defaults.  Or at global scope, passing NULL
///   will reset any custom value and restore it to the system default.
///   NOTE: When setting callback functions, do not pass the function pointer directly.
///   Your argument should be a pointer to a function pointer.
bool CSteamNetworkingUtils::SetConfigValue(ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, intptr_t scopeObj,
    ESteamNetworkingConfigDataType eDataType, const void *pArg)
{
    VLOG_INFO(__FUNCTION__ " eValue: %d, eScopeType: %d, scopeObj: %d, eDataType: %d, pArg: %p", eValue, eScopeType, scopeObj, eDataType, pArg);
    return false; // TODO: Implement config value setting
}

/// Get a configuration value.
/// - eValue: which value to fetch
/// - eScopeType: query setting on what type of object
/// - eScopeArg: the object to query the setting for
/// - pOutDataType: If non-NULL, the data type of the value is returned.
/// - pResult: Where to put the result.  Pass NULL to query the required buffer size.  (k_ESteamNetworkingGetConfigValue_BufferTooSmall will be returned.)
/// - cbResult: IN: the size of your buffer.  OUT: the number of bytes filled in or required.
ESteamNetworkingGetConfigValueResult CSteamNetworkingUtils::GetConfigValue(ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, intptr_t scopeObj,
    ESteamNetworkingConfigDataType *pOutDataType, void *pResult, size_t *cbResult)
{
    VLOG_INFO(__FUNCTION__ " eValue: %d, eScopeType: %d, scopeObj: %d, pOutDataType: %d, pResult: %p, cbResult: %zu", eValue, eScopeType, scopeObj, pOutDataType, pResult, cbResult);
    return k_ESteamNetworkingGetConfigValue_BadValue; // TODO: Implement config value getting
}

/// Returns info about a configuration value.  Returns false if the value does not exist.
/// pOutNextValue can be used to iterate through all of the known configuration values.
/// (Use GetFirstConfigValue() to begin the iteration, will be k_ESteamNetworkingConfig_Invalid on the last value)
/// Any of the output parameters can be NULL if you do not need that information.
///
/// See k_ESteamNetworkingConfig_EnumerateDevVars for some more info about "dev" variables,
/// which are usually excluded from the set of variables enumerated using this function.
bool CSteamNetworkingUtils::GetConfigValueInfo(ESteamNetworkingConfigValue eValue, const char **pOutName, ESteamNetworkingConfigDataType *pOutDataType, ESteamNetworkingConfigScope *pOutScope, ESteamNetworkingConfigValue *pOutNextValue)
{
    VLOG_INFO(__FUNCTION__ " eValue: %d, pOutName: %p, pOutDataType: %d, pOutScope: %d, pOutNextValue: %d", eValue, pOutName, pOutDataType, pOutScope, pOutNextValue);
    return false; // TODO: Implement config value info getting
}

/// Return the lowest numbered configuration value available in the current environment.
ESteamNetworkingConfigValue CSteamNetworkingUtils::GetFirstConfigValue()
{
    VLOG_INFO(__FUNCTION__);
    return k_ESteamNetworkingConfig_Invalid; // TODO: Implement first config value getting
}

// String conversions.  You'll usually access these using the respective
// inline methods.
void CSteamNetworkingUtils::SteamNetworkingIPAddr_ToString(const SteamNetworkingIPAddr &addr, char *buf, size_t cbBuf, bool bWithPort)
{
    VLOG_INFO(__FUNCTION__ " addr: %s, buf: %p, cbBuf: %zu, bWithPort: %d", addr, buf, cbBuf, bWithPort);
    // TODO: Implement IP address to string conversion
}

bool CSteamNetworkingUtils::SteamNetworkingIPAddr_ParseString(SteamNetworkingIPAddr *pAddr, const char *pszStr)
{
    VLOG_INFO(__FUNCTION__ " pAddr: %p, pszStr: %s", pAddr, pszStr);
    return false; // TODO: Implement IP address string parsing
}

void CSteamNetworkingUtils::SteamNetworkingIdentity_ToString(const SteamNetworkingIdentity &identity, char *buf, size_t cbBuf)
{
    VLOG_INFO(__FUNCTION__ " identity: %s, buf: %p, cbBuf: %zu", identity, buf, cbBuf);
    // TODO: Implement identity to string conversion
}

bool CSteamNetworkingUtils::SteamNetworkingIdentity_ParseString(SteamNetworkingIdentity *pIdentity, const char *pszStr)
{
    VLOG_INFO(__FUNCTION__ " pIdentity: %p, pszStr: %s", pIdentity, pszStr);
    return false; // TODO: Implement identity string parsing
}
