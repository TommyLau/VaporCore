/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_UTILS_H
#define VAPORCORE_STEAM_UTILS_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamutils.h>
#include <isteamutils002.h>
#include <isteamutils004.h>
#include <isteamutils005.h>
#include <isteamutils007.h>
#include <isteamutils008.h>

//-----------------------------------------------------------------------------
// Purpose: interface to user independent utility functions
//-----------------------------------------------------------------------------
class CSteamUtils :
	public ISteamUtils,
	public ISteamUtils002,
	public ISteamUtils004,
	public ISteamUtils005,
    public ISteamUtils007,
    public ISteamUtils008
{
public:
	// Singleton accessor
    static CSteamUtils& GetInstance()
	{
		static CSteamUtils instance;
		return instance;
	}

public:
	// return the number of seconds since the user 
	uint32 GetSecondsSinceAppActive() override;
	uint32 GetSecondsSinceComputerActive() override;

	// the universe this client is connecting to
	EUniverse GetConnectedUniverse() override;

	// Steam server time.  Number of seconds since January 1, 1970, GMT (i.e unix time)
	uint32 GetServerRealTime() override;

	// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
	// e.g "US" or "UK".
	const char *GetIPCountry() override;

	// returns true if the image exists, and valid sizes were filled out
	bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight ) override;

	// returns true if the image exists, and the buffer was successfully filled out
	// results are returned in RGBA format
	// the destination buffer size should be 4 * height * width * sizeof(char)
	bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize ) override;

	// returns the IP of the reporting server for valve - currently only used in Source engine games
	bool GetCSERIPPort( uint32 *unIP, uint16 *usPort ) override;

	// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
	uint8 GetCurrentBatteryPower() override;

	// returns the appID of the current process
	uint32 GetAppID() override;

	// Sets the position where the overlay instance for the currently calling game should show notifications.
	// This position is per-game and if this function is called from outside of a game context it will do nothing.
	void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition ) override;

	// API asynchronous call results
	// can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
	bool IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed ) override;
	ESteamAPICallFailure GetAPICallFailureReason( SteamAPICall_t hSteamAPICall ) override;
	bool GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed ) override;

	// Deprecated. Applications should use SteamAPI_RunCallbacks() instead. Game servers do not need to call this function.
	// Changed from Steam SDK v1.36, backward compatibility
	STEAM_PRIVATE_API( void RunFrame() override; )

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	uint32 GetIPCCallCount() override;

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction ) override;

	// Returns true if the overlay is running & the user can access it. The overlay process could take a few seconds to
	// start & hook the game process, so this function will initially return false while the overlay is loading.
	bool IsOverlayEnabled() override;

	// Normally this call is unneeded if your game has a constantly running frame loop that calls the 
	// D3D Present API, or OGL SwapBuffers API every frame.
	//
	// However, if you have a game that only refreshes the screen on an event driven basis then that can break 
	// the overlay, as it uses your Present/SwapBuffers calls to drive it's internal frame loop and it may also
	// need to Present() to the screen any time an even needing a notification happens or when the overlay is
	// brought up over the game by a user.  You can use this API to ask the overlay if it currently need a present
	// in that case, and then you can check for this periodically (roughly 33hz is desirable) and make sure you
	// refresh the screen with Present or SwapBuffers to allow the overlay to do it's work.
	bool BOverlayNeedsPresent() override;

	// Asynchronous call to check if an executable file has been signed using the public key set on the signing tab
	// of the partner site, for example to refuse to load modified executable files.  
	// The result is returned in CheckFileSignature_t.
	//   k_ECheckFileSignatureNoSignaturesFoundForThisApp - This app has not been configured on the signing tab of the partner site to enable this function.
	//   k_ECheckFileSignatureNoSignaturesFoundForThisFile - This file is not listed on the signing tab for the partner site.
	//   k_ECheckFileSignatureFileNotFound - The file does not exist on disk.
	//   k_ECheckFileSignatureInvalidSignature - The file exists, and the signing tab has been set for this file, but the file is either not signed or the signature does not match.
	//   k_ECheckFileSignatureValidSignature - The file is signed and the signature is valid.
	STEAM_CALL_RESULT( CheckFileSignature_t )
	SteamAPICall_t CheckFileSignature( const char *szFileName ) override;

	// Activates the Big Picture text input dialog which only supports gamepad input
	bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText ) override;
	// Changed from Steam SDK v1.29a, backward compatibility
	bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax ) override;

	// Returns previously entered text & length
	uint32 GetEnteredGamepadTextLength() override;
	bool GetEnteredGamepadTextInput( char *pchText, uint32 cchText ) override;

	// returns the language the steam client is running in, you probably want ISteamApps::GetCurrentGameLanguage instead, this is for very special usage cases
	const char *GetSteamUILanguage() override;

	// returns true if Steam itself is running in VR mode
	bool IsSteamRunningInVR() override;
	
	// Sets the inset of the overlay notification from the corner specified by SetOverlayNotificationPosition.
	void SetOverlayNotificationInset( int nHorizontalInset, int nVerticalInset ) override;

	// returns true if Steam & the Steam Overlay are running in Big Picture mode
	// Games much be launched through the Steam client to enable the Big Picture overlay. During development,
	// a game can be added as a non-steam game to the developers library to test this feature
	bool IsSteamInBigPictureMode() override;

	// ask SteamUI to create and render its OpenVR dashboard
	void StartVRDashboard() override;

	// Returns true if the HMD content will be streamed via Steam Remote Play
	bool IsVRHeadsetStreamingEnabled() override;

	// Set whether the HMD content will be streamed via Steam Remote Play
	// If this is set to true, then the scene in the HMD headset will be streamed, and remote input will not be allowed.
	// If this is set to false, then the application window will be streamed instead, and remote input will be allowed.
	// The default is true unless "VRHeadsetStreaming" "0" is in the extended appinfo for a game.
	// (this is useful for games that have asymmetric multiplayer gameplay)
	void SetVRHeadsetStreamingEnabled( bool bEnabled ) override;

	// Returns whether this steam client is a Steam China specific client, vs the global client.
	bool IsSteamChinaLauncher() override;

	// Initializes text filtering.
	//   Returns false if filtering is unavailable for the language the user is currently running in.
	bool InitFilterText() override; 

	// Filters the provided input message and places the filtered result into pchOutFilteredText.
	//   pchOutFilteredText is where the output will be placed, even if no filtering or censoring is performed
	//   nByteSizeOutFilteredText is the size (in bytes) of pchOutFilteredText
	//   pchInputText is the input string that should be filtered, which can be ASCII or UTF-8
	//   bLegalOnly should be false if you want profanity and legally required filtering (where required) and true if you want legally required filtering only
	//   Returns the number of characters (not bytes) filtered.
	int FilterText( char* pchOutFilteredText, uint32 nByteSizeOutFilteredText, const char * pchInputMessage, bool bLegalOnly ) override;

	// Return what we believe your current ipv6 connectivity to "the internet" is on the specified protocol.
	// This does NOT tell you if the Steam client is currently connected to Steam via ipv6.
	ESteamIPv6ConnectivityState GetIPv6ConnectivityState( ESteamIPv6ConnectivityProtocol eProtocol ) override;

private:
    // Private constructor and destructor for singleton
    CSteamUtils();
    ~CSteamUtils();

    // Delete copy constructor and assignment operator
    CSteamUtils(const CSteamUtils&) = delete;
    CSteamUtils& operator=(const CSteamUtils&) = delete;
};

#endif // VAPORCORE_STEAM_UTILS_H
