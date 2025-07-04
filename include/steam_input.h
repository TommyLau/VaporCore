/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_STEAM_INPUT_H
#define VAPORCORE_STEAM_INPUT_H
#ifdef _WIN32
#pragma once
#endif

#include <isteaminput.h>

//-----------------------------------------------------------------------------
// Steam Input API
//-----------------------------------------------------------------------------
class CSteamInput :
    public ISteamInput
{
public:
	// Singleton accessor
    static CSteamInput& GetInstance()
    {
		static CSteamInput instance;
		return instance;
    }

public:
	// Init and Shutdown must be called when starting/ending use of this interface
	bool Init() override;
	bool Shutdown() override;
	
	// Synchronize API state with the latest Steam Controller inputs available. This
	// is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
	// possible latency, you call this directly before reading controller state. This must
	// be called from somewhere before GetConnectedControllers will return any handles
	void RunFrame() override;

	// Enumerate currently connected Steam Input enabled devices - developers can opt in controller by type (ex: Xbox/Playstation/etc) via
	// the Steam Input settings in the Steamworks site or users can opt-in in their controller settings in Steam.
	// handlesOut should point to a STEAM_INPUT_MAX_COUNT sized array of InputHandle_t handles
	// Returns the number of handles written to handlesOut
	int GetConnectedControllers( STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_COUNT, Receives list of connected controllers ) InputHandle_t *handlesOut ) override;
	
	//-----------------------------------------------------------------------------
	// ACTION SETS
	//-----------------------------------------------------------------------------

	// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
	InputActionSetHandle_t GetActionSetHandle( const char *pszActionSetName ) override;
	
	// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
	// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
	// your state loops, instead of trying to place it in all of your state transitions.
	void ActivateActionSet( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle ) override;
	InputActionSetHandle_t GetCurrentActionSet( InputHandle_t inputHandle ) override;

	// ACTION SET LAYERS
	void ActivateActionSetLayer( InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle ) override;
	void DeactivateActionSetLayer( InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle ) override;
	void DeactivateAllActionSetLayers( InputHandle_t inputHandle ) override;
	// Enumerate currently active layers.
	// handlesOut should point to a STEAM_INPUT_MAX_ACTIVE_LAYERS sized array of ControllerActionSetHandle_t handles
	// Returns the number of handles written to handlesOut
	int GetActiveActionSetLayers( InputHandle_t inputHandle, STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_ACTIVE_LAYERS, Receives list of active layers ) InputActionSetHandle_t *handlesOut ) override;

	//-----------------------------------------------------------------------------
	// ACTIONS
	//-----------------------------------------------------------------------------

	// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
	InputDigitalActionHandle_t GetDigitalActionHandle( const char *pszActionName ) override;
	
	// Returns the current state of the supplied digital game action
	InputDigitalActionData_t GetDigitalActionData( InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle ) override;
	
	// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_INPUT_MAX_ORIGINS sized array of EInputActionOrigin handles. The EInputActionOrigin enum will get extended as support for new controller controllers gets added to
	// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
	int GetDigitalActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin *originsOut ) override;
	
	// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
	InputAnalogActionHandle_t GetAnalogActionHandle( const char *pszActionName ) override;
	
	// Returns the current state of these supplied analog game action
	InputAnalogActionData_t GetAnalogActionData( InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle ) override;

	// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
	// originsOut should point to a STEAM_INPUT_MAX_ORIGINS sized array of EInputActionOrigin handles. The EInputActionOrigin enum will get extended as support for new controller controllers gets added to
	// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
	int GetAnalogActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_ORIGINS, Receives list of action origins ) EInputActionOrigin *originsOut ) override;
	
	// Get a local path to art for on-screen glyph for a particular origin
	const char *GetGlyphForActionOrigin( EInputActionOrigin eOrigin ) override;
	
	// Returns a localized string (from Steam's language setting) for the specified origin.
	const char *GetStringForActionOrigin( EInputActionOrigin eOrigin ) override;

	// Stop analog momentum for the action if it is a mouse action in trackball mode
	void StopAnalogActionMomentum( InputHandle_t inputHandle, InputAnalogActionHandle_t eAction ) override;

	// Returns raw motion data from the specified device
	InputMotionData_t GetMotionData( InputHandle_t inputHandle ) override;

	//-----------------------------------------------------------------------------
	// OUTPUTS
	//-----------------------------------------------------------------------------

	// Trigger a vibration event on supported controllers - Steam will translate these commands into haptic pulses for Steam Controllers
	void TriggerVibration( InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed ) override;

	// Set the controller LED color on supported controllers. nFlags is a bitmask of values from ESteamInputLEDFlag - 0 will default to setting a color. Steam will handle
	// the behavior on exit of your program so you don't need to try restore the default as you are shutting down
	void SetLEDColor( InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags ) override;

	// Trigger a haptic pulse on a Steam Controller - if you are approximating rumble you may want to use TriggerVibration instead.
	// Good uses for Haptic pulses include chimes, noises, or directional gameplay feedback (taking damage, footstep locations, etc).
	void TriggerHapticPulse( InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) override;

	// Trigger a haptic pulse with a duty cycle of usDurationMicroSec / usOffMicroSec, unRepeat times. If you are approximating rumble you may want to use TriggerVibration instead.
	// nFlags is currently unused and reserved for future use.
	void TriggerRepeatedHapticPulse( InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags ) override;

	//-----------------------------------------------------------------------------
	// Utility functions availible without using the rest of Steam Input API
	//-----------------------------------------------------------------------------

	// Invokes the Steam overlay and brings up the binding screen if the user is using Big Picture Mode
	// If the user is not in Big Picture Mode it will open up the binding in a new window
	bool ShowBindingPanel( InputHandle_t inputHandle ) override;

	// Returns the input type for a particular handle
	ESteamInputType GetInputTypeForHandle( InputHandle_t inputHandle ) override;

	// Returns the associated controller handle for the specified emulated gamepad - can be used with the above 2 functions
	// to identify controllers presented to your game over Xinput. Returns 0 if the Xinput index isn't associated with Steam Input
	InputHandle_t GetControllerForGamepadIndex( int nIndex ) override;

	// Returns the associated gamepad index for the specified controller, if emulating a gamepad or -1 if not associated with an Xinput index
	int GetGamepadIndexForController( InputHandle_t ulinputHandle ) override;
	
	// Returns a localized string (from Steam's language setting) for the specified Xbox controller origin.
	const char *GetStringForXboxOrigin( EXboxOrigin eOrigin ) override;

	// Get a local path to art for on-screen glyph for a particular Xbox controller origin
	const char *GetGlyphForXboxOrigin( EXboxOrigin eOrigin ) override;

	// Get the equivalent ActionOrigin for a given Xbox controller origin this can be chained with GetGlyphForActionOrigin to provide future proof glyphs for
	// non-Steam Input API action games. Note - this only translates the buttons directly and doesn't take into account any remapping a user has made in their configuration
	EInputActionOrigin GetActionOriginFromXboxOrigin( InputHandle_t inputHandle, EXboxOrigin eOrigin ) override;

	// Convert an origin to another controller type - for inputs not present on the other controller type this will return k_EInputActionOrigin_None
	// When a new input type is added you will be able to pass in k_ESteamInputType_Unknown and the closest origin that your version of the SDK recognized will be returned
	// ex: if a Playstation 5 controller was released this function would return Playstation 4 origins.
	EInputActionOrigin TranslateActionOrigin( ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin ) override;

	// Get the binding revision for a given device. Returns false if the handle was not valid or if a mapping is not yet loaded for the device
	bool GetDeviceBindingRevision( InputHandle_t inputHandle, int *pMajor, int *pMinor ) override;

	// Get the Steam Remote Play session ID associated with a device, or 0 if there is no session associated with it
	// See isteamremoteplay.h for more information on Steam Remote Play sessions
	uint32 GetRemotePlaySessionID( InputHandle_t inputHandle ) override;

private:
    // Private constructor and destructor for singleton
    CSteamInput();
    ~CSteamInput();

    // Delete copy constructor and assignment operator
    CSteamInput(const CSteamInput&) = delete;
    CSteamInput& operator=(const CSteamInput&) = delete;
};

#endif // VAPORCORE_STEAM_INPUT_H
