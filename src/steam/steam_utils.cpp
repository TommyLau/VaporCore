/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>
#include <ctime>

#include "vapor_base.h"
#include "steam_utils.h"

CSteamUtils::CSteamUtils()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamUtils::~CSteamUtils()
{
    VLOG_INFO(__FUNCTION__);
}

// return the number of seconds since the user 
uint32 CSteamUtils::GetSecondsSinceAppActive()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

uint32 CSteamUtils::GetSecondsSinceComputerActive()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// the universe this client is connecting to
EUniverse CSteamUtils::GetConnectedUniverse()
{
    VLOG_INFO(__FUNCTION__);
    return k_EUniversePublic;
}

// Steam server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
uint32 CSteamUtils::GetServerRealTime()
{
    VLOG_INFO(__FUNCTION__);
    return static_cast<uint32>(time(nullptr));
}

// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
// e.g "US" or "UK".
const char *CSteamUtils::GetIPCountry()
{
    VLOG_INFO(__FUNCTION__);
    return "US";
}

// returns true if the image exists, and valid sizes were filled out
bool CSteamUtils::GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight )
{
    VLOG_INFO(__FUNCTION__ " - image: %d, ", iImage);
    if (pnWidth) *pnWidth = 0;
    if (pnHeight) *pnHeight = 0;
    return false;
}

// returns true if the image exists, and the buffer was successfully filled out
// results are returned in RGBA format
// the destination buffer size should be 4 * height * width * sizeof(char)
bool CSteamUtils::GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize )
{
    VLOG_INFO(__FUNCTION__ " - image: %d, buffer size: %d", iImage, nDestBufferSize);
    return false;
}

// returns the IP of the reporting server for valve - currently only used in Source engine games
bool CSteamUtils::GetCSERIPPort( uint32 *unIP, uint16 *usPort )
{
    VLOG_INFO(__FUNCTION__);
    if (unIP) *unIP = 0;
    if (usPort) *usPort = 0;
    return false;
}

// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
uint8 CSteamUtils::GetCurrentBatteryPower()
{
    VLOG_INFO(__FUNCTION__);
    return 255; // Assume on AC power
}

// returns the appID of the current process
uint32 CSteamUtils::GetAppID()
{
    VLOG_INFO(__FUNCTION__);
    return VaporCore::Config::GetInstance().GetGameId().AppID();
}

// Sets the position where the overlay instance for the currently calling game should show notifications.
// This position is per-game and if this function is called from outside of a game context it will do nothing.
void CSteamUtils::SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
{
    VLOG_INFO(__FUNCTION__ " - position: %d", eNotificationPosition);
}

// API asynchronous call results
// can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
bool CSteamUtils::IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed )
{
    VLOG_INFO(__FUNCTION__ " - call: %u", hSteamAPICall);
    return false;
}

ESteamAPICallFailure CSteamUtils::GetAPICallFailureReason( SteamAPICall_t hSteamAPICall )
{
    VLOG_INFO(__FUNCTION__ " - call: %u", hSteamAPICall);
    return k_ESteamAPICallFailureNone;
}

bool CSteamUtils::GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed )
{
    VLOG_INFO(__FUNCTION__ " - call: %u", hSteamAPICall);
    return false;
}

// Deprecated. Applications should use SteamAPI_RunCallbacks() instead. Game servers do not need to call this function.
// Changed from Steam SDK v1.36, backward compatibility
void CSteamUtils::RunFrame()
{
    VLOG_INFO(__FUNCTION__);
}

// returns the number of IPC calls made since the last time this function was called
// Used for perf debugging so you can understand how many IPC calls your game makes per frame
// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
// control how often you do them.
uint32 CSteamUtils::GetIPCCallCount()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// API warning handling
// 'int' is the severity; 0 for msg, 1 for warning
// 'const char *' is the text of the message
// callbacks will occur directly after the API function is called that generated the warning or message
void CSteamUtils::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
    VLOG_INFO(__FUNCTION__ " - function: %p", pFunction);
}

// Returns true if the overlay is running & the user can access it. The overlay process could take a few seconds to
// start & hook the game process, so this function will initially return false while the overlay is loading.
bool CSteamUtils::IsOverlayEnabled()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Normally this call is unneeded if your game has a constantly running frame loop that calls the 
// D3D Present API, or OGL SwapBuffers API every frame.
//
// However, if you have a game that only refreshes the screen on an event driven basis then that can break 
// the overlay, as it uses your Present/SwapBuffers calls to drive it's internal frame loop and it may also
// need to Present() to the screen any time an even needing a notification happens or when the overlay is
// brought up over the game by a user.  You can use this API to ask the overlay if it currently need a present
// in that case, and then you can check for this periodically (roughly 33hz is desirable) and make sure you
// refresh the screen with Present or SwapBuffers to allow the overlay to do it's work.
bool CSteamUtils::BOverlayNeedsPresent()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Asynchronous call to check if an executable file has been signed using the public key set on the signing tab
// of the partner site, for example to refuse to load modified executable files.  
// The result is returned in CheckFileSignature_t.
//   k_ECheckFileSignatureNoSignaturesFoundForThisApp - This app has not been configured on the signing tab of the partner site to enable this function.
//   k_ECheckFileSignatureNoSignaturesFoundForThisFile - This file is not listed on the signing tab for the partner site.
//   k_ECheckFileSignatureFileNotFound - The file does not exist on disk.
//   k_ECheckFileSignatureInvalidSignature - The file exists, and the signing tab has been set for this file, but the file is either not signed or the signature does not match.
//   k_ECheckFileSignatureValidSignature - The file is signed and the signature is valid.
SteamAPICall_t CSteamUtils::CheckFileSignature( const char *szFileName )
{
    VLOG_INFO(__FUNCTION__ " - file: %s", szFileName ? szFileName : "null");
    return k_uAPICallInvalid;
}

// Activates the Big Picture text input dialog which only supports gamepad input
bool CSteamUtils::ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText)
{
    VLOG_INFO(__FUNCTION__ " - mode: %d, line mode: %d, desc: %s, max chars: %u, existing text: %s",
              eInputMode, eLineInputMode, pchDescription ? pchDescription : "null", unCharMax,
              pchExistingText ? pchExistingText : "null");
    return false;
}

// Changed from Steam SDK v1.29a, backward compatibility
bool CSteamUtils::ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax)
{
    VLOG_INFO(__FUNCTION__ " - mode: %d, line mode: %d, desc: %s, max chars: %u",
              eInputMode, eLineInputMode, pchDescription ? pchDescription : "null", unCharMax);
    return false;
}

// Returns previously entered text & length
uint32 CSteamUtils::GetEnteredGamepadTextLength()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

bool CSteamUtils::GetEnteredGamepadTextInput(char *pchText, uint32 cchText)
{
    VLOG_INFO(__FUNCTION__ " - buffer size: %u", cchText);
    if (pchText && cchText > 0)
    {
        pchText[0] = '\0';
    }
    return false;
}

// returns the language the steam client is running in, you probably want ISteamApps::GetCurrentGameLanguage instead, this is for very special usage cases
const char *CSteamUtils::GetSteamUILanguage()
{
    VLOG_INFO(__FUNCTION__);
    return VaporCore::Config::GetInstance().GetLanguage().c_str();
}

// returns true if Steam itself is running in VR mode
bool CSteamUtils::IsSteamRunningInVR()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Sets the inset of the overlay notification from the corner specified by SetOverlayNotificationPosition.
void CSteamUtils::SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset)
{
    VLOG_INFO(__FUNCTION__ " - horizontal: %d, vertical: %d", nHorizontalInset, nVerticalInset);
}

// returns true if Steam & the Steam Overlay are running in Big Picture mode
// Games much be launched through the Steam client to enable the Big Picture overlay. During development,
// a game can be added as a non-steam game to the developers library to test this feature
bool CSteamUtils::IsSteamInBigPictureMode()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// ask SteamUI to create and render its OpenVR dashboard
void CSteamUtils::StartVRDashboard()
{
    VLOG_INFO(__FUNCTION__);
}

// Returns true if the HMD content will be streamed via Steam In-Home Streaming
bool CSteamUtils::IsVRHeadsetStreamingEnabled()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Set whether the HMD content will be streamed via Steam In-Home Streaming
// If this is set to true, then the scene in the HMD headset will be streamed, and remote input will not be allowed.
// If this is set to false, then the application window will be streamed instead, and remote input will be allowed.
// The default is true unless "VRHeadsetStreaming" "0" is in the extended appinfo for a game.
// (this is useful for games that have asymmetric multiplayer gameplay)
void CSteamUtils::SetVRHeadsetStreamingEnabled(bool bEnabled)
{
    VLOG_INFO(__FUNCTION__ " - enabled: %d", bEnabled);
}
