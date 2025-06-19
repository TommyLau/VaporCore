/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_networking.h"
#include "logger.h"

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

