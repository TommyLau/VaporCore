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
#include "steam_controller.h"

CSteamController::CSteamController()
{
    VLOG_INFO(__FUNCTION__);
}

CSteamController::~CSteamController()
{
    VLOG_INFO(__FUNCTION__);
}

// Init and Shutdown must be called when starting/ending use of this interface
bool CSteamController::Init()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// Must call init and shutdown when starting/ending use of the interface
// Changed from Steam SDK v1.35a, backward compatibility
bool CSteamController::Init(const char *pchAbsolutePathToControllerConfigVDF)
{
    VLOG_INFO(__FUNCTION__ " - config path: %s", pchAbsolutePathToControllerConfigVDF);
    return true;
}

bool CSteamController::Shutdown()
{
    VLOG_INFO(__FUNCTION__);
    return true;
}

// Synchronize API state with the latest Steam Controller inputs available. This
// is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest
// possible latency, you call this directly before reading controller state.
void CSteamController::RunFrame()
{
    // No implementation needed since SteamAPI_RunCallbacks handles this
}

// Get the state of the specified controller, returns false if that controller is not connected
// Removed from Steam SDK v1.35a, backward compatibility
bool CSteamController::GetControllerState(uint32 unControllerIndex, SteamControllerState_t *pState)
{
    VLOG_INFO(__FUNCTION__ " - controller %u", unControllerIndex);
    if (!pState) {
        return false;
    }
    // Clear the state struct
    memset(pState, 0, sizeof(SteamControllerState_t));
    return false; // Return false since no controller is connected
}

// Enumerate currently connected controllers
// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
// Returns the number of handles written to handlesOut
int CSteamController::GetConnectedControllers(ControllerHandle_t *handlesOut)
{
    VLOG_INFO(__FUNCTION__);
    return 0; // Return 0 since no controllers are connected
}

// Invokes the Steam overlay and brings up the binding screen
// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
bool CSteamController::ShowBindingPanel(ControllerHandle_t controllerHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return false; // Return false since overlay is not available
}

// ACTION SETS
// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
ControllerActionSetHandle_t CSteamController::GetActionSetHandle(const char *pszActionSetName)
{
    VLOG_INFO(__FUNCTION__ " - action set: %s", pszActionSetName);
    return 0; // Return invalid handle
}

// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
// your state loops, instead of trying to place it in all of your state transitions.
void CSteamController::ActivateActionSet(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, action set %llu", controllerHandle, actionSetHandle);
}

ControllerActionSetHandle_t CSteamController::GetCurrentActionSet(ControllerHandle_t controllerHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return 0; // Return invalid handle
}

// ACTIONS
// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
ControllerDigitalActionHandle_t CSteamController::GetDigitalActionHandle(const char *pszActionName)
{
    VLOG_INFO(__FUNCTION__ " - action: %s", pszActionName);
    return 0; // Return invalid handle
}

// Returns the current state of the supplied digital game action
ControllerDigitalActionData_t CSteamController::GetDigitalActionData(ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, action %llu", controllerHandle, digitalActionHandle);
    ControllerDigitalActionData_t data = {};
    data.bState = false;
    data.bActive = false;
    return data;
}

// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
int CSteamController::GetDigitalActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin *originsOut)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return 0; // Return 0 since no origins are available
}

// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
ControllerAnalogActionHandle_t CSteamController::GetAnalogActionHandle(const char *pszActionName)
{
    VLOG_INFO(__FUNCTION__ " - action: %s", pszActionName);
    ControllerAnalogActionHandle_t handle = {}; // Init empty struct
    return handle;
}

// Returns the current state of these supplied analog game action
ControllerAnalogActionData_t CSteamController::GetAnalogActionData(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, action %llu", controllerHandle, analogActionHandle);
    ControllerAnalogActionData_t data = {};
    data.eMode = k_EControllerSourceMode_None;
    data.x = 0.0f;
    data.y = 0.0f;
    data.bActive = false;
    return data;
}

// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
int CSteamController::GetAnalogActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin *originsOut)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return 0; // Return 0 since no origins are available
}

void CSteamController::StopAnalogActionMomentum(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, action %llu", controllerHandle, eAction);
}

// Trigger a haptic pulse on a controller
void CSteamController::TriggerHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, pad %d, duration %u", controllerHandle, eTargetPad, usDurationMicroSec);
}

// Trigger a haptic pulse on the controller
// Changed from Steam SDK v1.35a, backward compatibility
void CSteamController::TriggerHapticPulse(uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
    VLOG_INFO(__FUNCTION__ " - controller %u, pad %d, duration %u", unControllerIndex, eTargetPad, usDurationMicroSec);
}

void CSteamController::TriggerRepeatedHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, pad %d, duration %u, off duration %u, repeat %u, flags %u",
               controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
}

// Trigger a vibration event on supported controllers.  
void CSteamController::TriggerVibration(ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, left speed %u, right speed %u", controllerHandle, usLeftSpeed, usRightSpeed);
}

// Set the controller LED color on supported controllers.  
void CSteamController::SetLEDColor(ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu, R:%u G:%u B:%u flags:%u", controllerHandle, nColorR, nColorG, nColorB, nFlags);
}

// Set the override mode which is used to choose to use different base/legacy bindings from your config file
void CSteamController::SetOverrideMode(const char *pchMode)
{
    VLOG_INFO(__FUNCTION__ " - mode: %s", pchMode);
}
	
// Returns the associated gamepad index for the specified controller, if emulating a gamepad
int CSteamController::GetGamepadIndexForController(ControllerHandle_t ulControllerHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", ulControllerHandle);
    return -1; // Return -1 to indicate no gamepad emulation
}

// Returns the associated controller handle for the specified emulated gamepad
ControllerHandle_t CSteamController::GetControllerForGamepadIndex(int nIndex)
{
    VLOG_INFO(__FUNCTION__ " - index %d", nIndex);
    return 0; // Return 0 to indicate no controller found
}

// Returns raw motion data from the specified controller
ControllerMotionData_t CSteamController::GetMotionData(ControllerHandle_t controllerHandle)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    ControllerMotionData_t data = {};
    return data;
}

// Attempt to display origins of given action in the controller HUD, for the currently active action set
// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
bool CSteamController::ShowDigitalActionOrigins(ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return false; // Return false since overlay functionality is not implemented
}

bool CSteamController::ShowAnalogActionOrigins(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition)
{
    VLOG_INFO(__FUNCTION__ " - controller %llu", controllerHandle);
    return false; // Return false since overlay functionality is not implemented
}

// Returns a localized string (from Steam's language setting) for the specified origin
const char* CSteamController::GetStringForActionOrigin(EControllerActionOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__ " - origin %d", eOrigin);
    return ""; // Return empty string since localization is not implemented
}

// Get a local path to art for on-screen glyph for a particular origin 
const char* CSteamController::GetGlyphForActionOrigin(EControllerActionOrigin eOrigin)
{
    VLOG_INFO(__FUNCTION__ " - origin %d", eOrigin);
    return ""; // Return empty string since glyph paths are not implemented
}
