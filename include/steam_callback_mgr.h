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

#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <chrono>
#include <algorithm>
#include <atomic>
#include <mutex>
#include <queue>
#include <unordered_map>

#include <steam_api.h>

//-----------------------------------------------------------------------------
// Purpose: Callback event data structure
//-----------------------------------------------------------------------------
struct CallbackEvent_t
{
    int m_iCallback;                // Callback ID
    void* m_pCallbackData;          // Pointer to callback data
    size_t m_cbCallbackData;        // Size of callback data in bytes
    SteamAPICall_t m_hAPICall;      // API call handle
    bool m_bIOFailure;              // Whether there was an IO failure
    bool m_bCallResult;             // Whether this is a call result
};

//-----------------------------------------------------------------------------
// Purpose: CCallbackMgr compatibility wrapper
//-----------------------------------------------------------------------------
class CCallbackMgr
{
public:
    // Helper methods
    static CCallbackMgr* GetInstance();
    static void ReleaseInstance();

    void RegisterCallback(class CCallbackBase* pCallback, int iCallback);
    void UnregisterCallback(class CCallbackBase* pCallback);
    void RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall);
    void UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall);
    void RunCallbacks();

    void AddCallback(int iCallback, void *pCallbackData, size_t cbCallbackData, SteamAPICall_t hAPICall = k_uAPICallInvalid);

private:
    // Singleton instance
    static CCallbackMgr* s_pInstance;

    // Callback management
    std::unordered_map<int, std::vector<CCallbackBase*>> m_clientCallbacks;
    std::unordered_map<int, std::vector<CCallbackBase*>> m_serverCallbacks;
    std::unordered_map<SteamAPICall_t, CCallbackBase*> m_callResults;
    std::queue<CallbackEvent_t> m_eventQueue;
    std::mutex m_mutex;

    // Callback flag management
    inline void SetRegisterFlag(CCallbackBase* pCallback) noexcept { pCallback->m_nCallbackFlags |= CCallbackBase::k_ECallbackFlagsRegistered; }
    inline void ClearRegisterFlag(CCallbackBase* pCallback) noexcept { pCallback->m_nCallbackFlags &= ~CCallbackBase::k_ECallbackFlagsRegistered; }
    inline bool BIsGameserverCallback(CCallbackBase* pCallback) const noexcept { return (pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsGameServer) != 0; }
};

#endif // VAPORCORE_CALLBACK_MGR_H
