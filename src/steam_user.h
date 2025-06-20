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

#include <sdk/isteamuser.h>
#include <sdk/isteamuser009.h>
#include <sdk/isteamuser010.h>
#include <sdk/isteamuser011.h>
#include <sdk/isteamuser012.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing and manipulating a steam account
//			associated with one client instance
//-----------------------------------------------------------------------------
class Steam_User :
    public ISteamUser,
    public ISteamUser009,
    public ISteamUser010,
    public ISteamUser011,
    public ISteamUser012
{
public:
    Steam_User();
    ~Steam_User();

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
	// Removed from Steam SDK v1.01, backward compatibility
	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) override;
	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure ) override;

	// notify of disconnect
	// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
	void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) override;

	// used by only a few games to track usage events
	void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" ) override;

	// legacy authentication support - need to be called if the game server rejects the user with a 'bad ticket' error
	// this is only needed under very specific circumstances
	// Removed from Steam SDK v1.01, backward compatibility
	void RefreshSteam2Login() override;

	// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
	// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
	bool GetUserDataFolder( char *pchBuffer, int cubBuffer ) override;

	// Starts voice recording. Once started, use GetCompressedVoice() to get the data
	void StartVoiceRecording( ) override;

	// Determine the amount of captured audio data that is available in bytes.
	// This provides both the compressed and uncompressed data. Please note that the uncompressed
	// data is not the raw feed from the microphone: data may only be available if audible 
	// levels of speech are detected.
	EVoiceResult GetAvailableVoice(uint32 *pcbCompressed, uint32 *pcbUncompressed) override;

	// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
	// a little bit after this function is called. GetCompressedVoice() should continue to be called until it returns
	// k_eVoiceResultNotRecording
	void StopVoiceRecording( ) override;

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
	EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten ) override;

	// Decompresses a chunk of compressed data produced by GetVoice().
	// nBytesWritten is set to the number of bytes written to pDestBuffer unless the return value is k_EVoiceResultBufferTooSmall.
	// In that case, nBytesWritten is set to the size of the buffer required to decompress the given
	// data. The suggested buffer size for the destination buffer is 22 kilobytes.
	// The output format of the data is 16-bit signed at 11025 samples per second.
	// Changed from Steam SDK v1.08, backward compatibility
	EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) override;
	EVoiceResult DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) override;

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

    // Helper methods
    static Steam_User* GetInstance();
    static void ReleaseInstance();

private:
    // Singleton instance
    static Steam_User* s_pInstance;
};

#endif // VAPORCORE_STEAM_USER_H

