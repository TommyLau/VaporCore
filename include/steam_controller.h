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

#include <isteamcontroller.h>
#include <isteamcontroller001.h>
#include <isteamcontroller003.h>
#include <isteamcontroller004.h>
#include <isteamcontroller005.h>
#include <isteamcontroller006.h>


//-----------------------------------------------------------------------------
// Purpose: Steam Input API
//-----------------------------------------------------------------------------
class CSteamController :
    public ISteamController,
    public ISteamController001,
    public ISteamController003,
    public ISteamController004,
    public ISteamController005,
    public ISteamController006
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
	// possible latency, you call this directly before reading controller state. This must
	// be called from somewhere before GetConnectedControllers will return any handles
	void RunFrame() override;

	// Get the state of the specified controller, returns false if that controller is not connected
	// Removed from Steam SDK v1.35a, backward compatibility
	bool GetControllerState(uint32 unControllerIndex, SteamControllerState_t *pState) override;

	// Enumerate currently connected controllers
	// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
	// Returns the number of handles written to handlesOut
	int GetConnectedControllers( STEAM_OUT_ARRAY_COUNT( STEAM_CONTROLLER_MAX_COUNT, Receives list of connected controllers ) ControllerHandle_t *handlesOut ) override;

	//-----------------------------------------------------------------------------
	// ACTION SETS
	//-----------------------------------------------------------------------------

	// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
	ControllerActionSetHandle_t GetActionSetHandle( const char *pszActionSetName ) override;

	// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
	// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
	// your state loops, instead of trying to place it in all of your state transitions.
	void ActivateActionSet( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle ) override;
	ControllerActionSetHandle_t GetCurrentActionSet( ControllerHandle_t controllerHandle ) override;

	// ACTION SET LAYERS
	void ActivateActionSetLayer( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle ) override;
	void DeactivateActionSetLayer( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle ) override;
	void DeactivateAllActionSetLayers( ControllerHandle_t controllerHandle ) override;
	// Enumerate currently active layers
	// handlesOut should point to a STEAM_CONTROLLER_MAX_ACTIVE_LAYERS sized array of ControllerActionSetHandle_t handles.
	// Returns the number of handles written to handlesOut
	int GetActiveActionSetLayers( ControllerHandle_t controllerHandle, STEAM_OUT_ARRAY_COUNT( STEAM_CONTROLLER_MAX_ACTIVE_LAYERS, Receives list of active layers ) ControllerActionSetHandle_t *handlesOut ) override;

	//-----------------------------------------------------------------------------
	// ACTIONS
	//-----------------------------------------------------------------------------

	// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
	ControllerDigitalActionHandle_t GetDigitalActionHandle( const char *pszActionName ) override;

	// Returns the current state of the supplied digital game action
	ControllerDigitalActionData_t GetDigitalActionData( ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle ) override;

	// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles. The EControllerActionOrigin enum will get extended as support for new controller controllers gets added to
	// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
	int GetDigitalActionOrigins( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, STEAM_OUT_ARRAY_COUNT( STEAM_CONTROLLER_MAX_ORIGINS, Receives list of aciton origins ) EControllerActionOrigin *originsOut ) override;

	// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
	ControllerAnalogActionHandle_t GetAnalogActionHandle( const char *pszActionName ) override;

	// Returns the current state of these supplied analog game action
	ControllerAnalogActionData_t GetAnalogActionData( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle ) override;

	// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles. The EControllerActionOrigin enum will get extended as support for new controller controllers gets added to
	// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
	int GetAnalogActionOrigins( ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, STEAM_OUT_ARRAY_COUNT( STEAM_CONTROLLER_MAX_ORIGINS, Receives list of action origins ) EControllerActionOrigin *originsOut ) override;

	// Get a local path to art for on-screen glyph for a particular origin - this call is cheap
	const char *GetGlyphForActionOrigin( EControllerActionOrigin eOrigin ) override;
	
	// Returns a localized string (from Steam's language setting) for the specified origin - this call is serialized
	const char *GetStringForActionOrigin( EControllerActionOrigin eOrigin ) override;

	void StopAnalogActionMomentum( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction ) override;

	// Returns raw motion data from the specified controller
	ControllerMotionData_t GetMotionData( ControllerHandle_t controllerHandle ) override;

	//-----------------------------------------------------------------------------
	// OUTPUTS
	//-----------------------------------------------------------------------------

	// Trigger a haptic pulse on a controller
	void TriggerHapticPulse( ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) override;
	// Trigger a haptic pulse on the controller
	// Changed from Steam SDK v1.35a, backward compatibility
	void TriggerHapticPulse(uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec) override;

	// Trigger a pulse with a duty cycle of usDurationMicroSec / usOffMicroSec, unRepeat times.
	// nFlags is currently unused and reserved for future use.
	void TriggerRepeatedHapticPulse( ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags ) override;

	// Trigger a vibration event on supported controllers.
	void TriggerVibration( ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed ) override;

	// Set the controller LED color on supported controllers.  
	void SetLEDColor( ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags ) override;

	// Set the override mode which is used to choose to use different base/legacy bindings from your config file
	// Removed from Steam SDK v1.35a, backward compatibility
	void SetOverrideMode(const char *pchMode) override;

	//-----------------------------------------------------------------------------
	// Utility functions availible without using the rest of Steam Input API
	//-----------------------------------------------------------------------------

	// Invokes the Steam overlay and brings up the binding screen if the user is using Big Picture Mode
	// If the user is not in Big Picture Mode it will open up the binding in a new window
	bool ShowBindingPanel( ControllerHandle_t controllerHandle ) override;

	// Returns the input type for a particular handle
	ESteamInputType GetInputTypeForHandle( ControllerHandle_t controllerHandle ) override;

	// Returns the associated controller handle for the specified emulated gamepad - can be used with the above 2 functions
	// to identify controllers presented to your game over Xinput. Returns 0 if the Xinput index isn't associated with Steam Input
	ControllerHandle_t GetControllerForGamepadIndex( int nIndex ) override;

	// Returns the associated gamepad index for the specified controller, if emulating a gamepad or -1 if not associated with an Xinput index
	int GetGamepadIndexForController( ControllerHandle_t ulControllerHandle ) override;

	// Returns a localized string (from Steam's language setting) for the specified Xbox controller origin. This function is cheap.
	const char *GetStringForXboxOrigin( EXboxOrigin eOrigin ) override;

	// Get a local path to art for on-screen glyph for a particular Xbox controller origin. This function is serialized.
	const char *GetGlyphForXboxOrigin( EXboxOrigin eOrigin ) override;

	// Get the equivalent ActionOrigin for a given Xbox controller origin this can be chained with GetGlyphForActionOrigin to provide future proof glyphs for
	// non-Steam Input API action games. Note - this only translates the buttons directly and doesn't take into account any remapping a user has made in their configuration
	EControllerActionOrigin GetActionOriginFromXboxOrigin( ControllerHandle_t controllerHandle, EXboxOrigin eOrigin ) override;

	// Convert an origin to another controller type - for inputs not present on the other controller type this will return k_EControllerActionOrigin_None
	EControllerActionOrigin TranslateActionOrigin( ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin ) override;

	// Attempt to display origins of given action in the controller HUD, for the currently active action set
	// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
	// Removed from Steam SDK v1.43, backward compatibility
	bool ShowDigitalActionOrigins( ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition ) override;
	// Removed from Steam SDK v1.43, backward compatibility
	bool ShowAnalogActionOrigins( ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition ) override;

	// Get the binding revision for a given device. Returns false if the handle was not valid or if a mapping is not yet loaded for the device
	bool GetControllerBindingRevision( ControllerHandle_t controllerHandle, int *pMajor, int *pMinor ) override;

private:
    // Private constructor and destructor for singleton
    CSteamController();
    ~CSteamController();

    // Delete copy constructor and assignment operator
    CSteamController(const CSteamController&) = delete;
    CSteamController& operator=(const CSteamController&) = delete;
};

#endif // VAPORCORE_STEAM_CONTROLLER_H
