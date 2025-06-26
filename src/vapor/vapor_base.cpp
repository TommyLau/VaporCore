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

#include "vapor_base.h"

// Global synchronization mutex
std::recursive_mutex g_GlobalMutex; 
