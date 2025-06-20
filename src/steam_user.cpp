/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_user.h"
#include "logger.h"

// Static instance
Steam_User* Steam_User::s_pInstance = nullptr;

Steam_User::Steam_User()
{
    VLOG_INFO("Steam_User constructor called");
}

Steam_User::~Steam_User()
{
    VLOG_INFO("Steam_User destructor called");
}

// returns the HSteamUser this interface represents
// this is only used internally by the API, and by a few select interfaces that support multi-user
HSteamUser Steam_User::GetHSteamUser()
{
    VLOG_DEBUG("GetHSteamUser called");
    return 1;
}

// returns true if the Steam client current has a live connection to the Steam servers. 
// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
// The Steam client will automatically be trying to recreate the connection as often as possible.
bool Steam_User::BLoggedOn()
{
    VLOG_DEBUG("BLoggedOn called");
    return true;
}

// returns the CSteamID of the account currently logged into the Steam client
// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
CSteamID Steam_User::GetSteamID()
{
    VLOG_DEBUG("GetSteamID called");
    return CSteamID();
}

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
int Steam_User::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_DEBUG("InitiateGameConnection called - GameServer: %llu, GameID: %llu, Server: %u:%u, Secure: %s", 
               steamIDGameServer.ConvertToUint64(), gameID.ToUint64(), unIPServer, usPortServer, bSecure ? "true" : "false");
    
    if (!pAuthBlob || cbMaxAuthBlob < 64)
    {
        return 0;
    }
    
    // Fill with dummy auth token
    memset(pAuthBlob, 0, cbMaxAuthBlob);
    return 64;
}

int Steam_User::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_DEBUG("InitiateGameConnection called - GameServer: %llu, Server: %u:%u, Secure: %s", 
               steamIDGameServer.ConvertToUint64(), unIPServer, usPortServer, bSecure ? "true" : "false");
    
    return 0;
}

// notify of disconnect
// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
void Steam_User::TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
{
    VLOG_DEBUG("TerminateGameConnection called - Server: %u:%u", unIPServer, usPortServer);
}

// used by only a few games to track usage events
void Steam_User::TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo )
{
    VLOG_DEBUG("TrackAppUsageEvent called - GameID: %llu, Event: %d, ExtraInfo: %s", 
               gameID.ToUint64(), eAppUsageEvent, pchExtraInfo ? pchExtraInfo : "null");
}

// legacy authentication support - need to be called if the game server rejects the user with a 'bad ticket' error
// this is only needed under very specific circumstances
void Steam_User::RefreshSteam2Login()
{
    VLOG_DEBUG("RefreshSteam2Login called");
}

// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
bool Steam_User::GetUserDataFolder( char *pchBuffer, int cubBuffer )
{
    VLOG_DEBUG("GetUserDataFolder called - Buffer: %s, Size: %d", pchBuffer, cubBuffer);
    strcpy(pchBuffer, "C:\\Progam Files\\Steam\\userdata\\1234567890\\1234567890\\local");
    return false;
}

// Starts voice recording. Once started, use GetCompressedVoice() to get the data
void Steam_User::StartVoiceRecording( )
{
    VLOG_DEBUG("StartVoiceRecording called");
}

// Determine the amount of captured audio data that is available in bytes.
// This provides both the compressed and uncompressed data. Please note that the uncompressed
// data is not the raw feed from the microphone: data may only be available if audible 
// levels of speech are detected.
EVoiceResult Steam_User::GetAvailableVoice(uint32 *pcbCompressed, uint32 *pcbUncompressed)
{
    VLOG_DEBUG("GetAvailableVoice called - Compressed: %d, Uncompressed: %d", pcbCompressed, pcbUncompressed);
    return EVoiceResult::k_EVoiceResultOK;
}

// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
// a little bit after this function is called. GetCompressedVoice() should continue to be called until it returns
// k_eVoiceResultNotRecording
void Steam_User::StopVoiceRecording( )
{
    VLOG_DEBUG("StopVoiceRecording called");
}

// Gets the latest voice data. It should be called as often as possible once recording has started.
// nBytesWritten is set to the number of bytes written to pDestBuffer. 
EVoiceResult Steam_User::GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    VLOG_DEBUG("GetCompressedVoice called - Buffer: %s, Size: %d", pDestBuffer, cbDestBufferSize);
    return EVoiceResult::k_EVoiceResultOK;
}

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
EVoiceResult Steam_User::GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten )
{
    VLOG_DEBUG("GetVoice called - WantCompressed: %s, DestBuffer: %s, DestBufferSize: %d, WantUncompressed: %s, UncompressedDestBuffer: %s, UncompressedDestBufferSize: %d", bWantCompressed ? "true" : "false", pDestBuffer, cbDestBufferSize, bWantUncompressed ? "true" : "false", pUncompressedDestBuffer, cbUncompressedDestBufferSize);
    return EVoiceResult::k_EVoiceResultOK;
}

// Decompresses a chunk of compressed data produced by GetVoice().
// nBytesWritten is set to the number of bytes written to pDestBuffer unless the return value is k_EVoiceResultBufferTooSmall.
// In that case, nBytesWritten is set to the size of the buffer required to decompress the given
// data. The suggested buffer size for the destination buffer is 22 kilobytes.
// The output format of the data is 16-bit signed at 11025 samples per second.
// Changed from Steam SDK v1.08, backward compatibility
EVoiceResult Steam_User::DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    return DecompressVoice((const void *)pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten);
}

EVoiceResult Steam_User::DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    VLOG_DEBUG("DecompressVoice called - Compressed: %s, Size: %d, DestBuffer: %s, DestBufferSize: %d", pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize);
    return EVoiceResult::k_EVoiceResultOK;
}

// Retrieve ticket to be sent to the entity who wishes to authenticate you. 
// pcbTicket retrieves the length of the actual ticket.
HAuthTicket Steam_User::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
    VLOG_DEBUG("GetAuthSessionTicket called - Ticket: %s, MaxTicket: %d, pcbTicket: %d", pTicket, cbMaxTicket, pcbTicket);
    return 0;
}

// Authenticate ticket from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
EBeginAuthSessionResult Steam_User::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
    VLOG_DEBUG("BeginAuthSession called - Ticket: %s, cbAuthTicket: %d, steamID: %llu", pAuthTicket, cbAuthTicket, steamID.GetAccountID());
    return EBeginAuthSessionResult::k_EBeginAuthSessionResultOK;
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
void Steam_User::EndAuthSession( CSteamID steamID )
{
    VLOG_DEBUG("EndAuthSession called - steamID: %llu", steamID.GetAccountID());
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
void Steam_User::CancelAuthTicket( HAuthTicket hAuthTicket )
{
    VLOG_DEBUG("CancelAuthTicket called - hAuthTicket: %d", hAuthTicket);
}

// After receiving a user's authentication data, and passing it to BeginAuthSession, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
EUserHasLicenseForAppResult Steam_User::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
    VLOG_DEBUG("UserHasLicenseForApp called - steamID: %llu, appID: %d", steamID.GetAccountID(), appID);
    return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
}

// Helper methods
Steam_User* Steam_User::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_User();
    }
    return s_pInstance;
}

void Steam_User::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

