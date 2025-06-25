/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_CALLBACK_MGR_H
#define VAPORCORE_CALLBACK_MGR_H
#ifdef _WIN32
#pragma once
#endif

#include <steam_api.h>

class CCallbackMgr {
public:
    static bool isGameServerCallback(const CCallbackBase* pCallback);
};

#endif // VAPORCORE_CALLBACK_MGR_H
