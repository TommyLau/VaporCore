/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include "vapor_base.h"
#include "vapor_callback_mgr.h"

bool CCallbackMgr::isGameServerCallback(const CCallbackBase* pCallback)
{
    VLOG_DEBUG("CCallbackMgr::isGameServerCallback called");

    if (!pCallback) {
        return false;
    }
    
    // Check the callback flags to determine if it's a game server callback
    return (pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsGameServer) != 0;
}
