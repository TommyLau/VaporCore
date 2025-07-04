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
#include "steam_input.h"

CSteamInput::CSteamInput()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamInput::~CSteamInput()
{
    VLOG_INFO(__FUNCTION__);
}

// Init and Shutdown must be called when starting/ending use of this interface
bool CSteamInput::Init()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

bool CSteamInput::Shutdown()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// Synchronize API state with the latest Steam Controller inputs available. This
// is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
// possible latency, you call this directly before reading controller state. This must
// be called from somewhere before GetConnectedControllers will return any handles
void CSteamInput::RunFrame()
{
    VLOG_INFO(__FUNCTION__);
}

// Enumerate currently connected Steam Input enabled devices - developers can opt in controller by type (ex: Xbox/Playstation/etc) via
// the Steam Input settings in the Steamworks site or users can opt-in in their controller settings in Steam.
// handlesOut should point to a STEAM_INPUT_MAX_COUNT sized array of InputHandle_t handles
// Returns the number of handles written to handlesOut
int CSteamInput::GetConnectedControllers( STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_COUNT, Receives list of connected controllers ) InputHandle_t *handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

//-----------------------------------------------------------------------------
// ACTION SETS
//-----------------------------------------------------------------------------

// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
InputActionSetHandle_t CSteamInput::GetActionSetHandle(const char* pszActionSetName)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
// your state loops, instead of trying to place it in all of your state transitions.
void CSteamInput::ActivateActionSet(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle)
{
    VLOG_INFO(__FUNCTION__);
}

InputActionSetHandle_t CSteamInput::GetCurrentActionSet(InputHandle_t inputHandle)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// ACTION SET LAYERS
void CSteamInput::ActivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle)
{
    VLOG_INFO(__FUNCTION__);
}

void CSteamInput::DeactivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle)
{
    VLOG_INFO(__FUNCTION__);
}

void CSteamInput::DeactivateAllActionSetLayers(InputHandle_t inputHandle)
{
    VLOG_INFO(__FUNCTION__);
}

// Enumerate currently active layers.
// handlesOut should point to a STEAM_INPUT_MAX_ACTIVE_LAYERS sized array of ControllerActionSetHandle_t handles
// Returns the number of handles written to handlesOut
int CSteamInput::GetActiveActionSetLayers( InputHandle_t inputHandle, STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_ACTIVE_LAYERS, Receives list of active layers ) InputActionSetHandle_t *handlesOut )
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

//-----------------------------------------------------------------------------
// ACTIONS
//-----------------------------------------------------------------------------

// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
InputDigitalActionHandle_t CSteamInput::GetDigitalActionHandle(const char* pszActionName)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Returns the current state of the supplied digital game action
InputDigitalActionData_t CSteamInput::GetDigitalActionData(InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle)
{
    VLOG_INFO(__FUNCTION__);
    InputDigitalActionData_t data = {};
    return data;
}

// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_INPUT_MAX_ORIGINS sized array of EInputActionOrigin handles. The EInputActionOrigin enum will get extended as support for new controller controllers gets added to
// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
int CSteamInput::GetDigitalActionOrigins(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin* originsOut)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
InputAnalogActionHandle_t CSteamInput::GetAnalogActionHandle(const char* pszActionName)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Returns the current state of these supplied analog game action
InputAnalogActionData_t CSteamInput::GetAnalogActionData(InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle)
{
    VLOG_INFO(__FUNCTION__);
    InputAnalogActionData_t data = {};
    return data;
}

// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_INPUT_MAX_ORIGINS sized array of EInputActionOrigin handles. The EInputActionOrigin enum will get extended as support for new controller controllers gets added to
// the Steam client and will exceed the values from this header, please check bounds if you are using a look up table.
int CSteamInput::GetAnalogActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, STEAM_OUT_ARRAY_COUNT( STEAM_INPUT_MAX_ORIGINS, Receives list of action origins ) EInputActionOrigin *originsOut )
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Get a local path to art for on-screen glyph for a particular origin - this call is cheap
const char* CSteamInput::GetGlyphForActionOrigin(EInputActionOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return "";
}

// Returns a localized string (from Steam's language setting) for the specified origin - this call is serialized
const char* CSteamInput::GetStringForActionOrigin(EInputActionOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return "";
}

// Stop analog momentum for the action if it is a mouse action in trackball mode
void CSteamInput::StopAnalogActionMomentum(InputHandle_t inputHandle, InputAnalogActionHandle_t eAction)
{
    VLOG_INFO(__FUNCTION__);
}

// Returns raw motion data from the specified device
InputMotionData_t CSteamInput::GetMotionData(InputHandle_t inputHandle)
{
    VLOG_INFO(__FUNCTION__);
    InputMotionData_t data = {};
    return data;
}

//-----------------------------------------------------------------------------
// OUTPUTS
//-----------------------------------------------------------------------------

// Trigger a vibration event on supported controllers - Steam will translate these commands into haptic pulses for Steam Controllers
void CSteamInput::TriggerVibration(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed)
{
    VLOG_INFO(__FUNCTION__);
}

// Set the controller LED color on supported controllers. nFlags is a bitmask of values from ESteamInputLEDFlag - 0 will default to setting a color. Steam will handle
// the behavior on exit of your program so you don't need to try restore the default as you are shutting down
void CSteamInput::SetLEDColor(InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags)
{
    VLOG_INFO(__FUNCTION__);
}

// Trigger a haptic pulse on a Steam Controller - if you are approximating rumble you may want to use TriggerVibration instead.
// Good uses for Haptic pulses include chimes, noises, or directional gameplay feedback (taking damage, footstep locations, etc).
void CSteamInput::TriggerHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
    VLOG_INFO(__FUNCTION__);
}

// Trigger a haptic pulse with a duty cycle of usDurationMicroSec / usOffMicroSec, unRepeat times. If you are approximating rumble you may want to use TriggerVibration instead.
// nFlags is currently unused and reserved for future use.
void CSteamInput::TriggerRepeatedHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags)
{
    VLOG_INFO(__FUNCTION__);
}

//-----------------------------------------------------------------------------
// Utility functions availible without using the rest of Steam Input API
//-----------------------------------------------------------------------------

// Invokes the Steam overlay and brings up the binding screen if the user is using Big Picture Mode
// If the user is not in Big Picture Mode it will open up the binding in a new window
bool CSteamInput::ShowBindingPanel(InputHandle_t inputHandle)
{
    VLOG_INFO(__FUNCTION__);
    return false;
}

// Returns the input type for a particular handle
ESteamInputType CSteamInput::GetInputTypeForHandle(InputHandle_t inputHandle)
{
    VLOG_INFO(__FUNCTION__);
    return k_ESteamInputType_Unknown;
}

// Returns the associated controller handle for the specified emulated gamepad - can be used with the above 2 functions
// to identify controllers presented to your game over Xinput. Returns 0 if the Xinput index isn't associated with Steam Input
InputHandle_t CSteamInput::GetControllerForGamepadIndex(int nIndex)
{
    VLOG_INFO(__FUNCTION__);
    return 0;
}

// Returns the associated gamepad index for the specified controller, if emulating a gamepad or -1 if not associated with an Xinput index
int CSteamInput::GetGamepadIndexForController(InputHandle_t ulinputHandle)
{
    VLOG_INFO(__FUNCTION__);
    return -1;
}

// Returns a localized string (from Steam's language setting) for the specified Xbox controller origin. This function is cheap.
const char* CSteamInput::GetStringForXboxOrigin(EXboxOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return "";
}

// Get a local path to art for on-screen glyph for a particular Xbox controller origin. This function is serialized.
const char* CSteamInput::GetGlyphForXboxOrigin(EXboxOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return "";
}

// Get the equivalent ActionOrigin for a given Xbox controller origin this can be chained with GetGlyphForActionOrigin to provide future proof glyphs for
// non-Steam Input API action games. Note - this only translates the buttons directly and doesn't take into account any remapping a user has made in their configuration
EInputActionOrigin CSteamInput::GetActionOriginFromXboxOrigin(InputHandle_t inputHandle, EXboxOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return k_EInputActionOrigin_None;
}

// Convert an origin to another controller type - for inputs not present on the other controller type this will return k_EInputActionOrigin_None
// When a new input type is added you will be able to pass in k_ESteamInputType_Unknown amd the closest origin that your version of the SDK regonized will be returned
// ex: if a Playstation 5 controller was released this function would return Playstation 4 origins.
EInputActionOrigin CSteamInput::TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin)
{
    VLOG_INFO(__FUNCTION__);
    return k_EInputActionOrigin_None;
}

// Get the binding revision for a given device. Returns false if the handle was not valid or if a mapping is not yet loaded for the device
bool CSteamInput::GetDeviceBindingRevision(InputHandle_t inputHandle, int *pMajor, int *pMinor)
{
    VLOG_INFO(__FUNCTION__);
    return false; // Return false since binding revision is not implemented
}
