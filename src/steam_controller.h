/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_CONTROLLER_H
#define VAPORCORE_STEAM_CONTROLLER_H
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <isteamcontroller.h>

//-----------------------------------------------------------------------------
// Purpose: Native Steam controller support API
//-----------------------------------------------------------------------------
class Steam_Controller :
    public ISteamController
{
private:
    // Singleton instance
    static Steam_Controller* s_pInstance;

public:
    Steam_Controller();
    ~Steam_Controller();

    // Helper methods
    static Steam_Controller* GetInstance();
    static void ReleaseInstance();

	//
	// Native controller support API
	//

	// Must call init and shutdown when starting/ending use of the interface
	bool Init(const char *pchAbsolutePathToControllerConfigVDF) override;
	bool Shutdown() override;

	// Pump callback/callresult events, SteamAPI_RunCallbacks will do this for you, 
	// normally never need to call directly.
	void RunFrame() override;

	// Get the state of the specified controller, returns false if that controller is not connected
	bool GetControllerState(uint32 unControllerIndex, SteamControllerState_t *pState) override;

	// Trigger a haptic pulse on the controller
	void TriggerHapticPulse(uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec) override;

	// Set the override mode which is used to choose to use different base/legacy bindings from your config file
	void SetOverrideMode(const char *pchMode) override;
};

#endif // VAPORCORE_STEAM_CONTROLLER_H
