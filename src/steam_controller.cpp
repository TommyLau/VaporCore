/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "steam_controller.h"
#include "logger.h"

// Static instance
Steam_Controller* Steam_Controller::s_pInstance = nullptr;

Steam_Controller::Steam_Controller()
{
    VLOG_INFO("Steam_Controller constructor called");
}

Steam_Controller::~Steam_Controller()
{
    VLOG_INFO("Steam_Controller destructor called");
}

// Helper methods
Steam_Controller* Steam_Controller::GetInstance()
{
    if (!s_pInstance)
    {
        s_pInstance = new Steam_Controller();
    }
    return s_pInstance;
}

void Steam_Controller::ReleaseInstance()
{
    if (s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

//
// Native controller support API
//

// Must call init and shutdown when starting/ending use of the interface
bool Steam_Controller::Init(const char *pchAbsolutePathToControllerConfigVDF)
{
    VLOG_DEBUG("Steam_Controller::Init called with config path: %s", pchAbsolutePathToControllerConfigVDF);
    return true;
}

bool Steam_Controller::Shutdown()
{
    VLOG_DEBUG("Steam_Controller::Shutdown called");
    return true;
}

// Pump callback/callresult events, SteamAPI_RunCallbacks will do this for you, 
// normally never need to call directly.
void Steam_Controller::RunFrame()
{
    // No implementation needed since SteamAPI_RunCallbacks handles this
}

// Get the state of the specified controller, returns false if that controller is not connected
bool Steam_Controller::GetControllerState(uint32 unControllerIndex, SteamControllerState_t *pState)
{
    VLOG_DEBUG("Steam_Controller::GetControllerState called for controller %u", unControllerIndex);
    if (!pState) {
        return false;
    }
    // Clear the state struct
    memset(pState, 0, sizeof(SteamControllerState_t));
    return false; // Return false since no controller is connected
}

// Trigger a haptic pulse on the controller
void Steam_Controller::TriggerHapticPulse(uint32 unControllerIndex, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
    VLOG_DEBUG("Steam_Controller::TriggerHapticPulse called - Controller: %u, Pad: %d, Duration: %u", 
               unControllerIndex, eTargetPad, usDurationMicroSec);
}

// Set the override mode which is used to choose to use different base/legacy bindings from your config file
void Steam_Controller::SetOverrideMode(const char *pchMode)
{
    VLOG_DEBUG("Steam_Controller::SetOverrideMode called with mode: %s", pchMode);
}
