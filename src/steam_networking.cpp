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
#include "steam_networking.h"

#define DEFAULT_VIRTUAL_PORT 1

// Static instance
Steam_Networking* Steam_Networking::s_pInstance = nullptr;

Steam_Networking::Steam_Networking()
{
    VLOG_INFO("Steam_Networking constructor called");
}

Steam_Networking::~Steam_Networking()
{
    VLOG_INFO("Steam_Networking destructor called");
}

////////////////////////////////////////////////////////////////////////////////////////////
// Session-less connection functions
//    automatically establishes NAT-traversing or Relay server connections

// Sends a P2P packet to the specified user
// UDP-like, unreliable and a max packet size of 1200 bytes
// the first packet send may be delayed as the NAT-traversal code runs
// if we can't get through to the user, an error will be posted via the callback P2PSessionConnectFail_t
// see EP2PSend enum above for the descriptions of the different ways of sending packets
// Changed from Steam SDK v1.11, backward compatibility
bool Steam_Networking::SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType )
{
    return SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, DEFAULT_VIRTUAL_PORT);
}

// nChannel is a routing number you can use to help route message to different systems 	- you'll have to call ReadP2PPacket() 
// with the same channel number in order to retrieve the data on the other end
// using different channels to talk to the same user will still use the same underlying p2p connection, saving on resources
bool Steam_Networking::SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel )
{
    VLOG_DEBUG("SendP2PPacket called - Remote: %llu, DataSize: %u, SendType: %d, Channel: %d", 
               steamIDRemote.GetAccountID(), cubData, eP2PSendType, nChannel);
    return false;
}

// returns true if any data is available for read, and the amount of data that will need to be read
// Changed from Steam SDK v1.11, backward compatibility
bool Steam_Networking::IsP2PPacketAvailable( uint32 *pcubMsgSize )
{
    return IsP2PPacketAvailable(pcubMsgSize, DEFAULT_VIRTUAL_PORT);
}

bool Steam_Networking::IsP2PPacketAvailable( uint32 *pcubMsgSize, int nChannel )
{
    VLOG_DEBUG("IsP2PPacketAvailable called - DataSize: %u, Channel: %d", *pcubMsgSize, nChannel);
    return false;
}

// reads in a packet that has been sent from another user via SendP2PPacket()
// returns the size of the message and the steamID of the user who sent it in the last two parameters
// if the buffer passed in is too small, the message will be truncated
// this call is not blocking, and will return false if no data is available
// Changed from Steam SDK v1.11, backward compatibility
bool Steam_Networking::ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote )
{
    return ReadP2PPacket(pubDest, cubDest, pcubMsgSize, psteamIDRemote, DEFAULT_VIRTUAL_PORT);
}

bool Steam_Networking::ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int nChannel )
{
    VLOG_DEBUG("ReadP2PPacket called - DestSize: %u, DataSize: %u, Channel: %d", cubDest, *pcubMsgSize, nChannel);
    return false;
}

// AcceptP2PSessionWithUser() should only be called in response to a P2PSessionRequest_t callback
// P2PSessionRequest_t will be posted if another user tries to send you a packet that you haven't talked to yet
// if you don't want to talk to the user, just ignore the request
// if the user continues to send you packets, another P2PSessionRequest_t will be posted periodically
// this may be called multiple times for a single user
// (if you've called SendP2PPacket() on the other user, this implicitly accepts the session request)
bool Steam_Networking::AcceptP2PSessionWithUser( CSteamID steamIDRemote )
{
    VLOG_DEBUG("AcceptP2PSessionWithUser called - Remote: %llu", steamIDRemote.GetAccountID());
    return false;
}

// call CloseP2PSessionWithUser() when you're done talking to a user, will free up resources under-the-hood
// if the remote user tries to send data to you again, another P2PSessionRequest_t callback will be posted
bool Steam_Networking::CloseP2PSessionWithUser( CSteamID steamIDRemote )
{
    VLOG_DEBUG("CloseP2PSessionWithUser called - Remote: %llu", steamIDRemote.GetAccountID());
    return false;
}

// call CloseP2PChannelWithUser() when you're done talking to a user on a specific channel. Once all channels
// open channels to a user have been closed, the open session to the user will be closed and new data from this
// user will trigger a P2PSessionRequest_t callback
bool Steam_Networking::CloseP2PChannelWithUser( CSteamID steamIDRemote, int nChannel )
{
    VLOG_DEBUG("CloseP2PChannelWithUser called - Remote: %llu, Channel: %d", steamIDRemote.GetAccountID(), nChannel);
    return false;
}

// fills out P2PSessionState_t structure with details about the underlying connection to the user
// should only needed for debugging purposes
// returns false if no connection exists to the specified user
bool Steam_Networking::GetP2PSessionState( CSteamID steamIDRemote, P2PSessionState_t *pConnectionState )
{
    VLOG_DEBUG("GetP2PSessionState called - Remote: %llu", steamIDRemote.GetAccountID());
    return false;
}

// Allow P2P connections to fall back to being relayed through the Steam servers if a direct connection
// or NAT-traversal cannot be established. Only applies to connections created after setting this value,
// or to existing connections that need to automatically reconnect after this value is set.
//
// P2P packet relay is allowed by default
bool Steam_Networking::AllowP2PPacketRelay( bool bAllow )
{
    VLOG_DEBUG("AllowP2PPacketRelay called - Allow: %s", bAllow ? "true" : "false");
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////
// LISTEN / CONNECT style interface functions
//
// This is an older set of functions designed around the Berkeley TCP sockets model
// it's preferential that you use the above P2P functions, they're more robust
// and these older functions will be removed eventually
//
////////////////////////////////////////////////////////////////////////////////////////////


// creates a socket and listens others to connect
// will trigger a SocketStatusCallback_t callback on another client connecting
// nVirtualP2PPort is the unique ID that the client will connect to, in case you have multiple ports
//		this can usually just be 0 unless you want multiple sets of connections
// unIP is the local IP address to bind to
//		pass in 0 if you just want the default local IP
// unPort is the port to use
//		pass in 0 if you don't want users to be able to connect via IP/Port, but expect to be always peer-to-peer connections only
// Removed from Steam SDK v1.03, backward compatibility
SNetListenSocket_t Steam_Networking::CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort )
{
    VLOG_DEBUG("CreateListenSocket called - VirtualPort: %d, IP: %u, Port: %u", nVirtualP2PPort, nIP, nPort);
    return 0;
}

SNetListenSocket_t Steam_Networking::CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
{
    VLOG_DEBUG("CreateListenSocket called - VirtualPort: %d, IP: %u, Port: %u, AllowPacketRelay: %s", nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay ? "true" : "false");
    return 0;
}

// creates a socket and begin connection to a remote destination
// can connect via a known steamID (client or game server), or directly to an IP
// on success will trigger a SocketConnectCallback_t callback
// on failure or timeout will trigger a SocketConnectionFailureCallback_t callback
// Removed from Steam SDK v1.03, backward compatibility
SNetSocket_t Steam_Networking::CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec )
{
    VLOG_DEBUG("CreateP2PConnectionSocket called - Target: %llu, VirtualPort: %d, Timeout: %d", 
               steamIDTarget.ConvertToUint64(), nVirtualPort, nTimeoutSec);
    return 0;
}

SNetSocket_t Steam_Networking::CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
{
    VLOG_DEBUG("CreateP2PConnectionSocket called - Target: %llu, VirtualPort: %d, Timeout: %d, AllowPacketRelay: %s", 
               steamIDTarget.ConvertToUint64(), nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay ? "true" : "false");
    return 0;
}

SNetSocket_t Steam_Networking::CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec )
{
    VLOG_DEBUG("CreateConnectionSocket called - IP: %u, Port: %u, Timeout: %d", nIP, nPort, nTimeoutSec);
    return 0;
}

// disconnects the connection to the socket, if any, and invalidates the handle
// any unread data on the socket will be thrown away
// if bNotifyRemoteEnd is set, socket will not be completely destroyed until the remote end acknowledges the disconnect
bool Steam_Networking::DestroySocket( SNetSocket_t hSocket, bool bNotifyRemoteEnd )
{
    VLOG_DEBUG("DestroySocket called - Socket: %u, NotifyRemote: %s", hSocket, bNotifyRemoteEnd ? "true" : "false");
    return true;
}

// destroying a listen socket will automatically kill all the regular sockets generated from it
bool Steam_Networking::DestroyListenSocket( SNetListenSocket_t hSocket, bool bNotifyRemoteEnd )
{
    VLOG_DEBUG("DestroyListenSocket called - Socket: %u, NotifyRemote: %s", hSocket, bNotifyRemoteEnd ? "true" : "false");
    return true;
}

// sending data
// must be a handle to a connected socket
// data size cannot be more than 8k, although in UDP mode (default),
// it's recommended packets be no larger than 1300 bytes
// use the reliable flag with caution; although the resend rate is pretty aggressive,
// it can still cause stalls in receiving data (like TCP)
bool Steam_Networking::SendDataOnSocket( SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable )
{
    VLOG_DEBUG("SendDataOnSocket called - Socket: %u, DataSize: %u, Reliable: %s", 
               hSocket, cubData, bReliable ? "true" : "false");
    return false;
}

// receiving data
// returns false if there is no data remaining
// fills out *pcubMsgSize with the size of the next message, in bytes
bool Steam_Networking::IsDataAvailableOnSocket( SNetSocket_t hSocket, uint32 *pcubMsgSize )
{
    VLOG_DEBUG("IsDataAvailableOnSocket called - Socket: %u", hSocket);
    if (pcubMsgSize) *pcubMsgSize = 0;
    return false;
}

// fills in pubDest with the contents of the message
// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
// if *pcubMsgSize < cubDest, only partial data is written
// returns false if no data is available
bool Steam_Networking::RetrieveDataFromSocket( SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
{
    VLOG_DEBUG("RetrieveDataFromSocket called - Socket: %u, DestSize: %u", hSocket, cubDest);
    if (pcubMsgSize) *pcubMsgSize = 0;
    return false;
}

// checks for data from any socket that has been connected off this listen socket
// returns false if there is no data remaining
// fills out *pcubMsgSize with the size of the next message, in bytes
// fills out *phSocket with the socket that data is available on
bool Steam_Networking::IsDataAvailable( SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
{
    VLOG_DEBUG("IsDataAvailable called - ListenSocket: %u", hListenSocket);
    if (pcubMsgSize) *pcubMsgSize = 0;
    if (phSocket) *phSocket = 0;
    return false;
}

// retrieves data from any socket that has been connected off this listen socket
// fills in pubDest with the contents of the message
// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
// if *pcubMsgSize < cubDest, only partial data is written
// returns false if no data is available
// fills out *phSocket with the socket that data is available on
bool Steam_Networking::RetrieveData( SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
{
    VLOG_DEBUG("RetrieveData called - ListenSocket: %u, DestSize: %u", hListenSocket, cubDest);
    if (pcubMsgSize) *pcubMsgSize = 0;
    if (phSocket) *phSocket = 0;
    return false;
}

// returns information about the specified socket, filling out the contents of the pointers
bool Steam_Networking::GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote )
{
    VLOG_DEBUG("GetSocketInfo called - Socket: %u", hSocket);
    if (pSteamIDRemote) *pSteamIDRemote = CSteamID();
    if (peSocketStatus) *peSocketStatus = 0;
    if (punIPRemote) *punIPRemote = 0;
    if (punPortRemote) *punPortRemote = 0;
    return false;
}

// returns which local port the listen socket is bound to
// *pnIP and *pnPort will be 0 if the socket is set to listen for P2P connections only
bool Steam_Networking::GetListenSocketInfo( SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort )
{
    VLOG_DEBUG("GetListenSocketInfo called - ListenSocket: %u", hListenSocket);
    if (pnIP) *pnIP = 0;
    if (pnPort) *pnPort = 0;
    return false;
}

// returns true to describe how the socket ended up connecting
ESNetSocketConnectionType Steam_Networking::GetSocketConnectionType( SNetSocket_t hSocket )
{
    VLOG_DEBUG("GetSocketConnectionType called - Socket: %u", hSocket);
    return k_ESNetSocketConnectionTypeNotConnected;
}

// max packet size, in bytes
int Steam_Networking::GetMaxPacketSize( SNetSocket_t hSocket )
{
    VLOG_DEBUG("GetMaxPacketSize called - Socket: %u", hSocket);
    return 0;
}

// Helper methods
Steam_Networking* Steam_Networking::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Networking();
    }
    return s_pInstance;
}

void Steam_Networking::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

