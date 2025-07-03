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
#include "steam_user.h"

CSteamUser::CSteamUser()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamUser::~CSteamUser()
{
    VLOG_INFO(__FUNCTION__);
}

// returns the HSteamUser this interface represents
// this is only used internally by the API, and by a few select interfaces that support multi-user
HSteamUser CSteamUser::GetHSteamUser()
{
    VLOG_INFO(__FUNCTION__);
    return 1;
}

// returns true if the Steam client current has a live connection to the Steam servers. 
// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
// The Steam client will automatically be trying to recreate the connection as often as possible.
bool CSteamUser::BLoggedOn()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// returns the CSteamID of the account currently logged into the Steam client
// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
CSteamID CSteamUser::GetSteamID()
{
    VLOG_INFO(__FUNCTION__);
    return VaporCore::Config::GetInstance().SteamID();
}

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
int CSteamUser::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_INFO(__FUNCTION__ " - GameServer: %llu, Server: %u:%u, Secure: %s", 
               steamIDGameServer.ConvertToUint64(), unIPServer, usPortServer, bSecure ? "true" : "false");

    if (!pAuthBlob || cbMaxAuthBlob < 64)
    {
        return 0;
    }
    
    // Fill with dummy auth token
    return 0;
}

// Changed from Steam SDK v1.01, backward compatibility
int CSteamUser::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
    VLOG_INFO(__FUNCTION__ " - GameServer: %llu, GameID: %llu, Server: %u:%u, Secure: %s", 
               steamIDGameServer.ConvertToUint64(), gameID.ToUint64(), unIPServer, usPortServer, bSecure ? "true" : "false");
    
    if (!pAuthBlob || cbMaxAuthBlob < 64)
    {
        return 0;
    }
    
    // Fill with dummy auth token
    memset(pAuthBlob, 0, cbMaxAuthBlob);
    return 64;
}

// notify of disconnect
// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
void CSteamUser::TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
{
    VLOG_INFO(__FUNCTION__ " - Server: %u:%u", unIPServer, usPortServer);
}

// Legacy functions

// used by only a few games to track usage events
void CSteamUser::TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo )
{
    VLOG_INFO(__FUNCTION__ " - GameID: %llu, Event: %d, ExtraInfo: %s", 
               gameID.ToUint64(), eAppUsageEvent, pchExtraInfo ? pchExtraInfo : "null");
}

// legacy authentication support - need to be called if the game server rejects the user with a 'bad ticket' error
// this is only needed under very specific circumstances
// Removed from Steam SDK v1.01, backward compatibility
void CSteamUser::RefreshSteam2Login()
{
    VLOG_INFO(__FUNCTION__);
}

// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
bool CSteamUser::GetUserDataFolder( char *pchBuffer, int cubBuffer )
{
    VLOG_INFO(__FUNCTION__ " - Buffer: %s, Size: %d", pchBuffer, cubBuffer);
    strcpy(pchBuffer, "C:\\Progam Files\\Steam\\userdata\\1234567890\\1234567890\\local");
    return false;
}

// Starts voice recording. Once started, use GetVoice() to get the data
void CSteamUser::StartVoiceRecording( )
{
    VLOG_INFO(__FUNCTION__);
}

// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
// a little bit after this function is called. GetVoice() should continue to be called until it returns
// k_eVoiceResultNotRecording
void CSteamUser::StopVoiceRecording( )
{
    VLOG_INFO(__FUNCTION__);
}

// Determine the size of captured audio data that is available from GetVoice.
// Most applications will only use compressed data and should ignore the other
// parameters, which exist primarily for backwards compatibility. See comments
// below for further explanation of "uncompressed" data.
EVoiceResult CSteamUser::GetAvailableVoice( uint32 *pcbCompressed, uint32 *pcbUncompressed_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated )
{
    VLOG_INFO(__FUNCTION__ " - Compressed: %d, Uncompressed: %d, DesiredSampleRate: %d", pcbCompressed, pcbUncompressed_Deprecated, nUncompressedVoiceDesiredSampleRate_Deprecated);
    return EVoiceResult::k_EVoiceResultOK;
}

// Changed from Steam SDK v1.13, backward compatibility
EVoiceResult CSteamUser::GetAvailableVoice( uint32 *pcbCompressed, uint32 *pcbUncompressed )
{
    VLOG_INFO(__FUNCTION__ " - Compressed: %d, Uncompressed: %d", pcbCompressed, pcbUncompressed);
    return EVoiceResult::k_EVoiceResultOK;
}

// Gets the latest voice data. It should be called as often as possible once recording has started.
// nBytesWritten is set to the number of bytes written to pDestBuffer. 
// Removed from Steam SDK v1.06, backward compatibility
EVoiceResult CSteamUser::GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    VLOG_INFO(__FUNCTION__ " - Buffer: %s, Size: %d, nBytesWritten: %d", pDestBuffer, cbDestBufferSize, nBytesWritten);
    return EVoiceResult::k_EVoiceResultOK;
}

// ---------------------------------------------------------------------------
// NOTE: "uncompressed" audio is a deprecated feature and should not be used
// by most applications. It is raw single-channel 16-bit PCM wave data which
// may have been run through preprocessing filters and/or had silence removed,
// so the uncompressed audio could have a shorter duration than you expect.
// There may be no data at all during long periods of silence. Also, fetching
// uncompressed audio will cause GetVoice to discard any leftover compressed
// audio, so you must fetch both types at once. Finally, GetAvailableVoice is
// not precisely accurate when the uncompressed size is requested. So if you
// really need to use uncompressed audio, you should call GetVoice frequently
// with two very large (20kb+) output buffers instead of trying to allocate
// perfectly-sized buffers. But most applications should ignore all of these
// details and simply leave the "uncompressed" parameters as NULL/zero.
// ---------------------------------------------------------------------------

// Read captured audio data from the microphone buffer. This should be called
// at least once per frame, and preferably every few milliseconds, to keep the
// microphone input delay as low as possible. Most applications will only use
// compressed data and should pass NULL/zero for the "uncompressed" parameters.
// Compressed data can be transmitted by your application and decoded into raw
// using the DecompressVoice function below.
EVoiceResult CSteamUser::GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed_Deprecated, void *pUncompressedDestBuffer_Deprecated, uint32 cbUncompressedDestBufferSize_Deprecated, uint32 *nUncompressBytesWritten_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated )
{
    VLOG_INFO(__FUNCTION__ " - WantCompressed: %s, DestBuffer: %s, DestBufferSize: %d, nBytesWritten: %d, WantUncompressed: %s, UncompressedDestBuffer: %s, UncompressedDestBufferSize: %d, UncompressBytesWritten: %d, UncompressedVoiceDesiredSampleRate: %d", bWantCompressed ? "true" : "false", pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed_Deprecated ? "true" : "false", pUncompressedDestBuffer_Deprecated, cbUncompressedDestBufferSize_Deprecated, nUncompressBytesWritten_Deprecated, nUncompressedVoiceDesiredSampleRate_Deprecated);

    return EVoiceResult::k_EVoiceResultOK;
}

// Changed from Steam SDK v1.13, backward compatibility
EVoiceResult CSteamUser::GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten )
{
    VLOG_INFO(__FUNCTION__ " - WantCompressed: %s, DestBuffer: %s, DestBufferSize: %d, nBytesWritten: %d, WantUncompressed: %s, UncompressedDestBuffer: %s, UncompressedDestBufferSize: %d, UncompressBytesWritten: %d", bWantCompressed ? "true" : "false", pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed ? "true" : "false", pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten);

    return EVoiceResult::k_EVoiceResultOK;
}

// Decodes the compressed voice data returned by GetVoice. The output data is
// raw single-channel 16-bit PCM audio. The decoder supports any sample rate
// from 11025 to 48000; see GetVoiceOptimalSampleRate() below for details.
// If the output buffer is not large enough, then *nBytesWritten will be set
// to the required buffer size, and k_EVoiceResultBufferTooSmall is returned.
// It is suggested to start with a 20kb buffer and reallocate as necessary.
EVoiceResult CSteamUser::DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, uint32 nDesiredSampleRate )
{
    VLOG_INFO(__FUNCTION__ " - Compressed: %s, Size: %d, DestBuffer: %s, DestBufferSize: %d, nBytesWritten: %d, DesiredSampleRate: %d", pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
    return EVoiceResult::k_EVoiceResultOK;
}

// The output format of the data is 16-bit signed at 11025 samples per second.
// Changed from Steam SDK v1.13, backward compatibility
EVoiceResult CSteamUser::DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    VLOG_INFO(__FUNCTION__ " - Compressed: %s, Size: %d, DestBuffer: %s, DestBufferSize: %d, nBytesWritten: %d", pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten);
    return EVoiceResult::k_EVoiceResultOK;
}
    
// Changed from Steam SDK v1.08, backward compatibility
EVoiceResult CSteamUser::DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
    return DecompressVoice((const void *)pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten);
}

// This returns the native sample rate of the Steam voice decompressor; using
// this sample rate for DecompressVoice will perform the least CPU processing.
// However, the final audio quality will depend on how well the audio device
// (and/or your application's audio output SDK) deals with lower sample rates.
// You may find that you get the best audio output quality when you ignore
// this function and use the native sample rate of your audio output device,
// which is usually 48000 or 44100.
uint32 CSteamUser::GetVoiceOptimalSampleRate()
{
    VLOG_INFO(__FUNCTION__);
    return 11025;
}

// Retrieve ticket to be sent to the entity who wishes to authenticate you. 
// pcbTicket retrieves the length of the actual ticket.
HAuthTicket CSteamUser::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
    VLOG_INFO(__FUNCTION__ " - Ticket: %s, MaxTicket: %d, pcbTicket: %d", pTicket, cbMaxTicket, pcbTicket);
    return 0;
}

// Authenticate ticket from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
EBeginAuthSessionResult CSteamUser::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
    VLOG_INFO(__FUNCTION__ " - Ticket: %s, cbAuthTicket: %d, steamID: %llu", pAuthTicket, cbAuthTicket, steamID.ConvertToUint64());
    return EBeginAuthSessionResult::k_EBeginAuthSessionResultOK;
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
void CSteamUser::EndAuthSession( CSteamID steamID )
{
    VLOG_INFO(__FUNCTION__ " - steamID: %llu", steamID.ConvertToUint64());
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
void CSteamUser::CancelAuthTicket( HAuthTicket hAuthTicket )
{
    VLOG_INFO(__FUNCTION__ " - hAuthTicket: %d", hAuthTicket);
}

// After receiving a user's authentication data, and passing it to BeginAuthSession, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
EUserHasLicenseForAppResult CSteamUser::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
    VLOG_INFO(__FUNCTION__ " - steamID: %llu, appID: %d", steamID.ConvertToUint64(), appID);
    return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
}

// returns true if this users looks like they are behind a NAT device. Only valid once the user has connected to steam 
// (i.e a SteamServersConnected_t has been issued) and may not catch all forms of NAT.
bool CSteamUser::BIsBehindNAT()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// set data to be replicated to friends so that they can join your game
// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
void CSteamUser::AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer )
{
    VLOG_INFO(__FUNCTION__ " - GameServer: %llu, Server: %u:%u", steamIDGameServer.ConvertToUint64(), unIPServer, usPortServer);
}

// Requests a ticket encrypted with an app specific shared key
// pDataToInclude, cbDataToInclude will be encrypted into the ticket
// ( This is asynchronous, you must wait for the ticket to be completed by the server )
STEAM_CALL_RESULT( EncryptedAppTicketResponse_t )
SteamAPICall_t CSteamUser::RequestEncryptedAppTicket( void *pDataToInclude, int cbDataToInclude )
{
    VLOG_INFO(__FUNCTION__ " - Data: %s, Size: %d", pDataToInclude, cbDataToInclude);
    return 0;
}

// retrieve a finished ticket
bool CSteamUser::GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
    VLOG_INFO(__FUNCTION__ " - Ticket: %s, MaxTicket: %d, pcbTicket: %d", pTicket, cbMaxTicket, pcbTicket);
    return false;
}

// Trading Card badges data access
// if you only have one set of cards, the series will be 1
// the user has can have two different badges for a series; the regular (max level 5) and the foil (max level 1)
int CSteamUser::GetGameBadgeLevel( int nSeries, bool bFoil )
{
    VLOG_INFO(__FUNCTION__ " - Series: %d, Foil: %d", nSeries, bFoil);
    return 0;
}

// gets the Steam Level of the user, as shown on their profile
int CSteamUser::GetPlayerSteamLevel()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Requests a URL which authenticates an in-game browser for store check-out,
// and then redirects to the specified URL. As long as the in-game browser
// accepts and handles session cookies, Steam microtransaction checkout pages
// will automatically recognize the user instead of presenting a login page.
// The result of this API call will be a StoreAuthURLResponse_t callback.
// NOTE: The URL has a very short lifetime to prevent history-snooping attacks,
// so you should only call this API when you are about to launch the browser,
// or else immediately navigate to the result URL using a hidden browser window.
// NOTE 2: The resulting authorization cookie has an expiration time of one day,
// so it would be a good idea to request and visit a new auth URL every 12 hours.
STEAM_CALL_RESULT( StoreAuthURLResponse_t )
SteamAPICall_t CSteamUser::RequestStoreAuthURL( const char *pchRedirectURL )
{
    VLOG_INFO(__FUNCTION__ " - RedirectURL: %s", pchRedirectURL);
    return 0;
}

// gets whether the users phone number is verified 
bool CSteamUser::BIsPhoneVerified()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// gets whether the user has two factor enabled on their account
bool CSteamUser::BIsTwoFactorEnabled()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// gets whether the users phone number is identifying
bool CSteamUser::BIsPhoneIdentifying()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// gets whether the users phone number is awaiting (re)verification
bool CSteamUser::BIsPhoneRequiringVerification()
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

STEAM_CALL_RESULT( MarketEligibilityResponse_t )
SteamAPICall_t CSteamUser::GetMarketEligibility()
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}
