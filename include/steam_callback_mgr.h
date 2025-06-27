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
// Uses RAII wrapper for safer memory management while maintaining performance
//-----------------------------------------------------------------------------
struct CallbackEvent_t
{
    // Callback type enumeration for efficient dispatch
    enum class CallbackType : uint8_t {
        ClientCallback,     // Regular client callback
        ServerCallback,     // Game server callback  
        CallResult          // Call result (API call completion)
    };

    // Primary dispatch control (checked first in dispatch logic)
    CallbackType m_callbackType;              // Type of callback for efficient dispatch
    
    // Callback identifiers (mutually exclusive based on type)
    int m_iCallback;                          // Callback ID (for regular callbacks)
    SteamAPICall_t m_hAPICall;                // API call handle (for call results)
    
    // Additional metadata
    bool m_bIOFailure;                        // Whether there was an IO failure (call results only)
    
    // Payload data (processed last in dispatch logic)
    std::unique_ptr<char[]> m_pCallbackData;  // RAII-managed callback data
    size_t m_cubCallbackData;                 // Size of callback data in bytes
    
    // Move constructor/assignment for efficiency
    CallbackEvent_t(CallbackEvent_t&& other) noexcept = default;
    CallbackEvent_t& operator=(CallbackEvent_t&& other) noexcept = default;
    
    // Delete copy operations (move-only semantics)
    CallbackEvent_t(const CallbackEvent_t&) = delete;
    CallbackEvent_t& operator=(const CallbackEvent_t&) = delete;
};

//-----------------------------------------------------------------------------
// Purpose: CCallbackMgr - Steam API callback management system
// 
// This class manages Steam API callbacks and call results using a singleton pattern.
// It provides thread-safe registration/unregistration and asynchronous dispatching.
//
// Key Features:
// - Separate handling for client and server callbacks
// - Thread-safe callback registration/unregistration  
// - Asynchronous callback dispatching via event queue
// - RAII memory management for callback data
// - Support for both regular callbacks and call results
//
// Usage:
// 1. Register callbacks via RegisterCallback() or RegisterCallResult()
// 2. Post events via PostCallback() or PostCallResult() 
// 3. Process events via DispatchCallbacks() (typically in main loop)
// 4. Unregister when done via UnregisterCallback() or UnregisterCallResult()
//-----------------------------------------------------------------------------
class CCallbackMgr
{
public:
    // Singleton accessor
    static CCallbackMgr& GetInstance()
    {
        static CCallbackMgr instance;
        return instance;
    }

public:
    //-----------------------------------------------------------------------------
    // Callback Registration API
    //-----------------------------------------------------------------------------
    void RegisterCallback(class CCallbackBase* pCallback, int iCallback);
    void UnregisterCallback(class CCallbackBase* pCallback);
    void RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall);
    void UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall);
    
    //-----------------------------------------------------------------------------
    // Event Processing API  
    //-----------------------------------------------------------------------------
    void DispatchCallbacks();

    //-----------------------------------------------------------------------------
    // Event Posting API (Internal Use)
    //-----------------------------------------------------------------------------
    bool PostCallback(int iCallback, void *pvCallbackData, size_t cubCallbackData);
    bool PostCallback(int iCallback, void *pvCallbackData, size_t cubCallbackData, CallbackEvent_t::CallbackType callbackType);
    SteamAPICall_t PostCallResult(void *pvCallbackData, size_t cubCallbackData, bool bIOFailure = false);
    
    //-----------------------------------------------------------------------------
    // Utility API (Testing/Debugging)
    //-----------------------------------------------------------------------------
    void DispatchCallbackImmediate(int iCallback, void *pvCallbackData, size_t cubCallbackData);

private:
    // Private constructor and destructor for singleton
    CCallbackMgr();
    ~CCallbackMgr();

    // Delete copy constructor and assignment operator
    CCallbackMgr(const CCallbackMgr&) = delete;
    CCallbackMgr& operator=(const CCallbackMgr&) = delete;

    // Callback flag management
    inline void SetRegisterFlag(CCallbackBase* pCallback) noexcept { pCallback->m_nCallbackFlags |= CCallbackBase::k_ECallbackFlagsRegistered; }
    inline void ClearRegisterFlag(CCallbackBase* pCallback) noexcept { pCallback->m_nCallbackFlags &= ~CCallbackBase::k_ECallbackFlagsRegistered; }
    inline bool IsGameserverCallback(CCallbackBase* pCallback) const noexcept { return (pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsGameServer) != 0; }

    // Helper methods for DRY principle
    bool PostCallbackEvent(CallbackEvent_t::CallbackType callbackType, int iCallback, SteamAPICall_t hAPICall, 
                          void* pvCallbackData, size_t cubCallbackData, bool bIOFailure = false);

private:
    // Callback management
    std::unordered_map<int, std::vector<CCallbackBase*>> m_clientCallbacks;
    std::unordered_map<int, std::vector<CCallbackBase*>> m_serverCallbacks;
    std::unordered_map<SteamAPICall_t, CCallbackBase*> m_callResults;
    std::queue<CallbackEvent_t> m_eventQueue;
    std::mutex m_mutex;
};

#endif // VAPORCORE_CALLBACK_MGR_H
