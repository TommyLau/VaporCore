/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: Base utilities and global synchronization implementation
 */

#include "vaporcore_base.h"

namespace VaporCore {
    
    // Global synchronization mutex
    std::mutex g_GlobalMutex;
    
} // namespace VaporCore 
