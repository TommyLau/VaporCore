/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_NETWORKING_H
#define VAPORCORE_STEAM_NETWORKING_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamnetworking.h>
#include <isteamnetworking001.h>
#include <isteamnetworking002.h>
#include <isteamnetworking003.h>
#include <isteamnetworking004.h>
#include <isteamnetworking005.h>

//-----------------------------------------------------------------------------
// Purpose: Functions for making connections and sending data between clients,
//			traversing NAT's where possible
//-----------------------------------------------------------------------------
class CSteamNetworking :
	public ISteamNetworking,
	public ISteamNetworking001,
	public ISteamNetworking002,
	public ISteamNetworking003,
	public ISteamNetworking004,
    public ISteamNetworking005
{
public:
	// Singleton accessor
    static CSteamNetworking& GetInstance()
    {
		static CSteamNetworking instance;
		return instance;
    }

public:
	////////////////////////////////////////////////////////////////////////////////////////////
	//
	// UDP-style (connectionless) networking interface.  These functions send messages using
	// an API organized around the destination.  Reliable and unreliable messages are supported.
	//
	// For a more TCP-style interface (meaning you have a connection handle), see the functions below.
	// Both interface styles can send both reliable and unreliable messages.
	//
	// Automatically establishes NAT-traversing or Relay server connections

	// Sends a P2P packet to the specified user
	// UDP-like, unreliable and a max packet size of 1200 bytes
	// the first packet send may be delayed as the NAT-traversal code runs
	// if we can't get through to the user, an error will be posted via the callback P2PSessionConnectFail_t
	// see EP2PSend enum above for the descriptions of the different ways of sending packets
	//
	// nChannel is a routing number you can use to help route message to different systems 	- you'll have to call ReadP2PPacket() 
	// with the same channel number in order to retrieve the data on the other end
	// using different channels to talk to the same user will still use the same underlying p2p connection, saving on resources
	bool SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel = 0 ) override;
	// Changed from Steam SDK v1.11, backward compatibility
	bool SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType ) override;

	// returns true if any data is available for read, and the amount of data that will need to be read
	bool IsP2PPacketAvailable( uint32 *pcubMsgSize, int nChannel = 0 ) override;
	// Changed from Steam SDK v1.11, backward compatibility
	bool IsP2PPacketAvailable( uint32 *pcubMsgSize ) override;

	// reads in a packet that has been sent from another user via SendP2PPacket()
	// returns the size of the message and the steamID of the user who sent it in the last two parameters
	// if the buffer passed in is too small, the message will be truncated
	// this call is not blocking, and will return false if no data is available
	bool ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int nChannel = 0 ) override;
	// Changed from Steam SDK v1.11, backward compatibility
	bool ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote ) override;

	// AcceptP2PSessionWithUser() should only be called in response to a P2PSessionRequest_t callback
	// P2PSessionRequest_t will be posted if another user tries to send you a packet that you haven't talked to yet
	// if you don't want to talk to the user, just ignore the request
	// if the user continues to send you packets, another P2PSessionRequest_t will be posted periodically
	// this may be called multiple times for a single user
	// (if you've called SendP2PPacket() on the other user, this implicitly accepts the session request)
	bool AcceptP2PSessionWithUser( CSteamID steamIDRemote ) override;

	// call CloseP2PSessionWithUser() when you're done talking to a user, will free up resources under-the-hood
	// if the remote user tries to send data to you again, another P2PSessionRequest_t callback will be posted
	bool CloseP2PSessionWithUser( CSteamID steamIDRemote ) override;

	// call CloseP2PChannelWithUser() when you're done talking to a user on a specific channel. Once all channels
	// open channels to a user have been closed, the open session to the user will be closed and new data from this
	// user will trigger a P2PSessionRequest_t callback
	bool CloseP2PChannelWithUser( CSteamID steamIDRemote, int nChannel ) override;

	// fills out P2PSessionState_t structure with details about the underlying connection to the user
	// should only needed for debugging purposes
	// returns false if no connection exists to the specified user
	bool GetP2PSessionState( CSteamID steamIDRemote, P2PSessionState_t *pConnectionState ) override;

	// Allow P2P connections to fall back to being relayed through the Steam servers if a direct connection
	// or NAT-traversal cannot be established. Only applies to connections created after setting this value,
	// or to existing connections that need to automatically reconnect after this value is set.
	//
	// P2P packet relay is allowed by default
	bool AllowP2PPacketRelay( bool bAllow ) override;


	////////////////////////////////////////////////////////////////////////////////////////////
	//
	// LISTEN / CONNECT connection-oriented interface functions
	//
	// These functions are more like a client-server TCP API.  One side is the "server"
	// and "listens" for incoming connections, which then must be "accepted."  The "client"
	// initiates a connection by "connecting."  Sending and receiving is done through a
	// connection handle.
	//
	// For a more UDP-style interface, where you do not track connection handles but
	// simply send messages to a SteamID, use the UDP-style functions above.
	//
	// Both methods can send both reliable and unreliable methods.
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
	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, SteamIPAddress_t nIP, uint16 nPort, bool bAllowUseOfPacketRelay ) override;
	// Changed from Steam SDK v1.47, backward compatibility
	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay ) override;
	// Changed from Steam SDK v1.03, backward compatibility
	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort ) override;

	// creates a socket and begin connection to a remote destination
	// can connect via a known steamID (client or game server), or directly to an IP
	// on success will trigger a SocketStatusCallback_t callback
	// on failure or timeout will trigger a SocketStatusCallback_t callback with a failure code in m_eSNetSocketState
	SNetSocket_t CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay ) override;
	// Changed from Steam SDK v1.03, backward compatibility
	SNetSocket_t CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec ) override;
	SNetSocket_t CreateConnectionSocket( SteamIPAddress_t nIP, uint16 nPort, int nTimeoutSec ) override;
	// Changed from Steam SDK v1.47, backward compatibility
	SNetSocket_t CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec ) override;

	// disconnects the connection to the socket, if any, and invalidates the handle
	// any unread data on the socket will be thrown away
	// if bNotifyRemoteEnd is set, socket will not be completely destroyed until the remote end acknowledges the disconnect
	bool DestroySocket( SNetSocket_t hSocket, bool bNotifyRemoteEnd ) override;
	// destroying a listen socket will automatically kill all the regular sockets generated from it
	bool DestroyListenSocket( SNetListenSocket_t hSocket, bool bNotifyRemoteEnd ) override;

	// sending data
	// must be a handle to a connected socket
	// data is all sent via UDP, and thus send sizes are limited to 1200 bytes; after this, many routers will start dropping packets
	// use the reliable flag with caution; although the resend rate is pretty aggressive,
	// it can still cause stalls in receiving data (like TCP)
	bool SendDataOnSocket( SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable ) override;

	// receiving data
	// returns false if there is no data remaining
	// fills out *pcubMsgSize with the size of the next message, in bytes
	bool IsDataAvailableOnSocket( SNetSocket_t hSocket, uint32 *pcubMsgSize ) override; 

	// fills in pubDest with the contents of the message
	// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
	// if *pcubMsgSize < cubDest, only partial data is written
	// returns false if no data is available
	bool RetrieveDataFromSocket( SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize ) override; 

	// checks for data from any socket that has been connected off this listen socket
	// returns false if there is no data remaining
	// fills out *pcubMsgSize with the size of the next message, in bytes
	// fills out *phSocket with the socket that data is available on
	bool IsDataAvailable( SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket ) override;

	// retrieves data from any socket that has been connected off this listen socket
	// fills in pubDest with the contents of the message
	// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
	// if *pcubMsgSize < cubDest, only partial data is written
	// returns false if no data is available
	// fills out *phSocket with the socket that data is available on
	bool RetrieveData( SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket ) override;

	// returns information about the specified socket, filling out the contents of the pointers
	bool GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, SteamIPAddress_t *punIPRemote, uint16 *punPortRemote ) override;
	// Changed from Steam SDK v1.47, backward compatibility
	bool GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote ) override;

	// returns which local port the listen socket is bound to
	// *pnIP and *pnPort will be 0 if the socket is set to listen for P2P connections only
	bool GetListenSocketInfo( SNetListenSocket_t hListenSocket, SteamIPAddress_t *pnIP, uint16 *pnPort ) override;
	// Changed from Steam SDK v1.47, backward compatibility
	bool GetListenSocketInfo( SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort ) override;

	// returns true to describe how the socket ended up connecting
	ESNetSocketConnectionType GetSocketConnectionType( SNetSocket_t hSocket ) override;

	// max packet size, in bytes
	int GetMaxPacketSize( SNetSocket_t hSocket ) override;

private:
    // Private constructor and destructor for singleton
    CSteamNetworking();
    ~CSteamNetworking();

    // Delete copy constructor and assignment operator
    CSteamNetworking(const CSteamNetworking&) = delete;
    CSteamNetworking& operator=(const CSteamNetworking&) = delete;
};

#endif // VAPORCORE_STEAM_NETWORKING_H

