/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef ISTEAMCONTROLLER001_H
#define ISTEAMCONTROLLER001_H
#ifdef _WIN32
#pragma once
#endif

#pragma pack( push, 1 )

struct SteamControllerState001_t
{
	// If packet num matches that on your prior call, then the controller state hasn't been changed since 
	// your last call and there is no need to process it
	uint32 unPacketNum;
	
	// bit flags for each of the buttons
	uint64 ulButtons;
	
	// Left pad coordinates
	short sLeftPadX;
	short sLeftPadY;
	
	// Right pad coordinates
	short sRightPadX;
	short sRightPadY;
	
};

#pragma pack( pop )

#define SteamControllerState_t SteamControllerState001_t

//-----------------------------------------------------------------------------
// Purpose: Native Steam controller support API
//-----------------------------------------------------------------------------
class ISteamController001
{
public:

	//
	// Native controller support API
	//

	// Must call init and shutdown when starting/ending use of the interface
	virtual bool Init( const char *pchAbsolutePathToControllerConfigVDF ) = 0;
	virtual bool Shutdown() = 0;

	// Pump callback/callresult events, SteamAPI_RunCallbacks will do this for you, 
	// normally never need to call directly.
	virtual void RunFrame() = 0;

	// Get the state of the specified controller, returns false if that controller is not connected
	virtual bool GetControllerState( uint32 unControllerIndex, SteamControllerState_t *pState ) = 0;

	// Trigger a haptic pulse on the controller
	virtual void TriggerHapticPulse( uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) = 0;

	// Set the override mode which is used to choose to use different base/legacy bindings from your config file
	virtual void SetOverrideMode( const char *pchMode ) = 0;
};

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"

#endif // ISTEAMCONTROLLER001_H
