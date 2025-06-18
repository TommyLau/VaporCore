/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: Base utilities and global synchronization for VaporCore
 */

#ifndef VAPORCORE_BASE_H
#define VAPORCORE_BASE_H
#ifdef _WIN32
#pragma once
#endif

#include <mutex>

#include "../include/sdk/100/steam_api.h"

namespace VaporCore {
    
    // Global synchronization for thread-safe operations
    extern std::mutex g_GlobalMutex;
    
    // Default Steam user handles
    const HSteamUser DEFAULT_CLIENT_USER = 1;
    const HSteamUser DEFAULT_SERVER_USER = 2;
    
    // Utility macros for thread-safe operations
    #define VAPORCORE_LOCK_GUARD() std::lock_guard<std::mutex> lock(VaporCore::g_GlobalMutex)
    #define VAPORCORE_LOCK() VaporCore::g_GlobalMutex.lock()
    #define VAPORCORE_UNLOCK() VaporCore::g_GlobalMutex.unlock()

} // namespace VaporCore

#endif // VAPORCORE_BASE_H 
