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
#include <isteamcontroller001.h>
#include <isteamcontroller003.h>
#include <isteamcontroller004.h>

//-----------------------------------------------------------------------------
// Purpose: Native Steam controller support API
//-----------------------------------------------------------------------------
class CSteamController :
    public ISteamController,
    public ISteamController001,
    public ISteamController003,
    public ISteamController004
{
public:
	// Singleton accessor
    static CSteamController& GetInstance()
    {
		static CSteamController instance;
		return instance;
    }

public:
	// Init and Shutdown must be called when starting/ending use of this interface
	bool Init() override;
	// Must call init and shutdown when starting/ending use of the interface
	// Changed from Steam SDK v1.35a, backward compatibility
	bool Init(const char *pchAbsolutePathToControllerConfigVDF) override;
	bool Shutdown() override;

	// Synchronize API state with the latest Steam Controller inputs available. This
	// is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
	// possible latency, you call this directly before reading controller state.
	void RunFrame() override;

	// Get the state of the specified controller, returns false if that controller is not connected
	// Removed from Steam SDK v1.35a, backward compatibility
	bool GetControllerState(uint32 unControllerIndex, SteamControllerState_t *pState) override;

	// Enumerate currently connected controllers
	// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
	// Returns the number of handles written to handlesOut
	int GetConnectedControllers( ControllerHandle_t *handlesOut ) override;

	// Invokes the Steam overlay and brings up the binding screen
	// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
	bool ShowBindingPanel( ControllerHandle_t controllerHandle ) override;

	// ACTION SETS
	// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
	ControllerActionSetHandle_t GetActionSetHandle( const char *pszActionSetName ) override;

	// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
	// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
	// your state loops, instead of trying to place it in all of your state transitions.
	void ActivateActionSet( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle ) override;
	ControllerActionSetHandle_t GetCurrentActionSet( ControllerHandle_t controllerHandle ) override;

	// ACTIONS
	// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
	ControllerDigitalActionHandle_t GetDigitalActionHandle( const char *pszActionName ) override;

	// Returns the current state of the supplied digital game action
	ControllerDigitalActionData_t GetDigitalActionData( ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle ) override;

	// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
	int GetDigitalActionOrigins( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin *originsOut ) override;

	// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
	ControllerAnalogActionHandle_t GetAnalogActionHandle( const char *pszActionName ) override;

	// Returns the current state of these supplied analog game action
	ControllerAnalogActionData_t GetAnalogActionData( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle ) override;

	// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
	int GetAnalogActionOrigins( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin *originsOut ) override;

	void StopAnalogActionMomentum( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction ) override;

	// Trigger a haptic pulse on a controller
	void TriggerHapticPulse( ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) override;
	// Trigger a haptic pulse on the controller
	// Changed from Steam SDK v1.35a, backward compatibility
	void TriggerHapticPulse(uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec) override;

	// Trigger a pulse with a duty cycle of usDurationMicroSec / usOffMicroSec, unRepeat times.
	// nFlags is currently unused and reserved for future use.
	void TriggerRepeatedHapticPulse( ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags ) override;

	// Tigger a vibration event on supported controllers.  
	void TriggerVibration( ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed ) override;

	// Set the controller LED color on supported controllers.  
	void SetLEDColor( ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags ) override;

	// Set the override mode which is used to choose to use different base/legacy bindings from your config file
	// Removed from Steam SDK v1.35a, backward compatibility
	void SetOverrideMode(const char *pchMode) override;

	// Returns the associated gamepad index for the specified controller, if emulating a gamepad
	int GetGamepadIndexForController( ControllerHandle_t ulControllerHandle ) override;

	// Returns the associated controller handle for the specified emulated gamepad
	ControllerHandle_t GetControllerForGamepadIndex( int nIndex ) override;

	// Returns raw motion data from the specified controller
	ControllerMotionData_t GetMotionData( ControllerHandle_t controllerHandle ) override;

	// Attempt to display origins of given action in the controller HUD, for the currently active action set
	// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
	bool ShowDigitalActionOrigins( ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition ) override;
	bool ShowAnalogActionOrigins( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition ) override;

	// Returns a localized string (from Steam's language setting) for the specified origin
	const char *GetStringForActionOrigin( EControllerActionOrigin eOrigin ) override;

	// Get a local path to art for on-screen glyph for a particular origin 
	const char *GetGlyphForActionOrigin( EControllerActionOrigin eOrigin ) override;

private:
    // Private constructor and destructor for singleton
    CSteamController();
    ~CSteamController();

    // Delete copy constructor and assignment operator
    CSteamController(const CSteamController&) = delete;
    CSteamController& operator=(const CSteamController&) = delete;
};

#endif // VAPORCORE_STEAM_CONTROLLER_H
