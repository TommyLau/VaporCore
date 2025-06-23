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
