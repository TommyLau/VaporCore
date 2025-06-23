/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_USER_H
#define VAPORCORE_STEAM_USER_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamuser.h>
#include <isteamuser009.h>
#include <isteamuser010.h>
#include <isteamuser011.h>
#include <isteamuser012.h>
#include <isteamuser013.h>
#include <isteamuser014.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing and manipulating a steam account
//			associated with one client instance
//-----------------------------------------------------------------------------
class Steam_User :
    public ISteamUser,
    public ISteamUser009,
    public ISteamUser010,
    public ISteamUser011,
    public ISteamUser012,
    public ISteamUser013,
    public ISteamUser014
{
private:
    // Singleton instance
    static Steam_User* s_pInstance;
	
public:
    Steam_User();
    ~Steam_User();

    // Helper methods
    static Steam_User* GetInstance();
    static void ReleaseInstance();

	// returns the HSteamUser this interface represents
	// this is only used internally by the API, and by a few select interfaces that support multi-user
	HSteamUser GetHSteamUser() override;

	// returns true if the Steam client current has a live connection to the Steam servers. 
	// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
	// The Steam client will automatically be trying to recreate the connection as often as possible.
	bool BLoggedOn() override;

	// returns the CSteamID of the account currently logged into the Steam client
	// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
	CSteamID GetSteamID() override;

	// Multiplayer Authentication functions

	// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
	// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
	//
	// Parameters:
	// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
	// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
	// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
	// CGameID gameID - the ID of the current game. For games without mods, this is just CGameID( <appID> )
	// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
	// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
	//
	// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
	// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure ) override;
	// Changed from Steam SDK v1.01, backward compatibility
	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) override;

	// notify of disconnect
	// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
	void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) override;

	// Legacy functions

	// used by only a few games to track usage events
	void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" ) override;

	// legacy authentication support - need to be called if the game server rejects the user with a 'bad ticket' error
	// this is only needed under very specific circumstances
	// Removed from Steam SDK v1.01, backward compatibility
	void RefreshSteam2Login() override;

	// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
	// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
	bool GetUserDataFolder( char *pchBuffer, int cubBuffer ) override;

	// Starts voice recording. Once started, use GetVoice() to get the data
	void StartVoiceRecording( ) override;

	// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
	// a little bit after this function is called. GetVoice() should continue to be called until it returns
	// k_eVoiceResultNotRecording
	void StopVoiceRecording( ) override;

	// Determine the amount of captured audio data that is available in bytes.
	// This provides both the compressed and uncompressed data. Please note that the uncompressed
	// data is not the raw feed from the microphone: data may only be available if audible 
	// levels of speech are detected.
	// nUncompressedVoiceDesiredSampleRate is necessary to know the number of bytes to return in pcbUncompressed - can be set to 0 if you don't need uncompressed (the usual case)
	// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nUncompressedVoiceDesiredSampleRate
	EVoiceResult GetAvailableVoice(uint32 *pcbCompressed, uint32 *pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate) override;
	// Changed from Steam SDK v1.13, backward compatibility
	EVoiceResult GetAvailableVoice(uint32 *pcbCompressed, uint32 *pcbUncompressed) override;

	// Gets the latest voice data. It should be called as often as possible once recording has started.
	// nBytesWritten is set to the number of bytes written to pDestBuffer. 
	// Removed from Steam SDK v1.06, backward compatibility
	EVoiceResult GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) override;

	// Gets the latest voice data from the microphone. Compressed data is an arbitrary format, and is meant to be handed back to 
	// DecompressVoice() for playback later as a binary blob. Uncompressed data is 16-bit, signed integer, 11025Hz PCM format.
	// Please note that the uncompressed data is not the raw feed from the microphone: data may only be available if audible 
	// levels of speech are detected, and may have passed through denoising filters, etc.
	// This function should be called as often as possible once recording has started; once per frame at least.
	// nBytesWritten is set to the number of bytes written to pDestBuffer. 
	// nUncompressedBytesWritten is set to the number of bytes written to pUncompressedDestBuffer. 
	// You must grab both compressed and uncompressed here at the same time, if you want both.
	// Matching data that is not read during this call will be thrown away.
	// GetAvailableVoice() can be used to determine how much data is actually available.
	// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nUncompressedVoiceDesiredSampleRate
	EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate ) override;
	// Changed from Steam SDK v1.13, backward compatibility
	EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten ) override;

	// Decompresses a chunk of compressed data produced by GetVoice().
	// nBytesWritten is set to the number of bytes written to pDestBuffer unless the return value is k_EVoiceResultBufferTooSmall.
	// In that case, nBytesWritten is set to the size of the buffer required to decompress the given
	// data. The suggested buffer size for the destination buffer is 22 kilobytes.
	// The output format of the data is 16-bit signed at the requested samples per second.
	// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nDesiredSampleRate
	EVoiceResult DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, uint32 nDesiredSampleRate ) override;
	// The output format of the data is 16-bit signed at 11025 samples per second.
	// Changed from Steam SDK v1.13, backward compatibility
	EVoiceResult DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) override;
	// Changed from Steam SDK v1.08, backward compatibility
	EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) override;

	// This returns the frequency of the voice data as it's stored internally; calling DecompressVoice() with this size will yield the best results
	uint32 GetVoiceOptimalSampleRate() override;

	// Retrieve ticket to be sent to the entity who wishes to authenticate you. 
	// pcbTicket retrieves the length of the actual ticket.
	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ) override;

	// Authenticate ticket from entity steamID to be sure it is valid and isnt reused
	// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID ) override;

	// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
	void EndAuthSession( CSteamID steamID ) override;

	// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
	void CancelAuthTicket( HAuthTicket hAuthTicket ) override;

	// After receiving a user's authentication data, and passing it to BeginAuthSession, use this function
	// to determine if the user owns downloadable content specified by the provided AppID.
	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID ) override;
	
	// returns true if this users looks like they are behind a NAT device. Only valid once the user has connected to steam 
	// (i.e a SteamServersConnected_t has been issued) and may not catch all forms of NAT.
	bool BIsBehindNAT() override;

	// set data to be replicated to friends so that they can join your game
	// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
	// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
	void AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer ) override;

	// Requests a ticket encrypted with an app specific shared key
	// pDataToInclude, cbDataToInclude will be encrypted into the ticket
	// ( This is asynchronous, you must wait for the ticket to be completed by the server )
	SteamAPICall_t RequestEncryptedAppTicket( void *pDataToInclude, int cbDataToInclude ) override;

	// retrieve a finished ticket
	bool GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ) override;

#ifdef _PS3
	// Initiates PS3 Logon request using just PSN ticket.  
	//
	// PARAMS: bInteractive - If set tells Steam to go ahead and show the PS3 NetStart dialog if needed to
	// prompt the user for network setup/PSN logon before initiating the Steam side of the logon.
	//
	// Listen for SteamServersConnected_t or SteamServerConnectFailure_t for status.  SteamServerConnectFailure_t
	// may return with EResult k_EResultExternalAccountUnlinked if the PSN account is unknown to Steam.  You should
	// then call LogOnAndLinkSteamAccountToPSN() after prompting the user for credentials to establish a link. 
	// Future calls to LogOn() after the one time link call should succeed as long as the user is connected to PSN.
	void LogOn( bool bInteractive ) override;

	// Initiates a request to logon with a specific steam username/password and create a PSN account link at 
	// the same time.  Should call this only if LogOn() has failed and indicated the PSN account is unlinked.
	//
	// PARAMS: bInteractive - If set tells Steam to go ahead and show the PS3 NetStart dialog if needed to
	// prompt the user for network setup/PSN logon before initiating the Steam side of the logon.  pchUserName 
	// should be the users Steam username, and pchPassword should be the users Steam password.
	// 
	// Listen for SteamServersConnected_t or SteamServerConnectFailure_t for status.  SteamServerConnectFailure_t
	// may return with EResult k_EResultOtherAccountAlreadyLinked if already linked to another account. 
	void LogOnAndLinkSteamAccountToPSN( bool bInteractive, const char *pchUserName, const char *pchPassword ) override;

	// Final logon option for PS3, this logs into an existing account if already linked, but if not already linked
	// creates a new account using the info in the PSN ticket to generate a unique account name.  The new account is
	// then linked to the PSN ticket.  This is the faster option for new users who don't have an existing Steam account
	// to get into multiplayer.
	//
	// PARAMS: bInteractive - If set tells Steam to go ahead and show the PS3 NetStart dialog if needed to
	// prompt the user for network setup/PSN logon before initiating the Steam side of the logon.
	void LogOnAndCreateNewSteamAccountIfNeeded( bool bInteractive ) override;

	// Returns a special SteamID that represents the user's PSN information. Can be used to query the user's PSN avatar,
	// online name, etc. through the standard Steamworks interfaces.
	CSteamID GetConsoleSteamID() override;
#endif

};

#endif // VAPORCORE_STEAM_USER_H
