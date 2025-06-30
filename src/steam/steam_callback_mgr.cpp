/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <random>
#include <cstring>
#include <cassert>
#include <atomic>

#include "vapor_base.h"

CCallbackMgr::CCallbackMgr()
{
    VLOG_INFO(__FUNCTION__);
}

CCallbackMgr::~CCallbackMgr()
{
    VLOG_INFO(__FUNCTION__);
}

void CCallbackMgr::RegisterCallback(class CCallbackBase* pCallback, int iCallback)
{
    VLOG_INFO(__FUNCTION__ " - Registering callback %p for iCallback: %d", pCallback, iCallback);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Null callback pointer");
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutex);

    auto& callbacks = IsGameserverCallback(pCallback) ? m_serverCallbacks : m_clientCallbacks;
    pCallback->m_iCallback = iCallback;

    if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
        // Special handling for API call completed callbacks
        SetRegisterFlag(pCallback);
        VLOG_DEBUG(__FUNCTION__ " - Registered SteamAPICallCompleted_t callback");
        return;
    }

    // Check if callback is already registered
    auto& callbackVector = callbacks[iCallback];
    if (std::find(callbackVector.begin(), callbackVector.end(), pCallback) != callbackVector.end()) {
        VLOG_WARNING(__FUNCTION__ " - Callback %p already registered for iCallback: %d", pCallback, iCallback);
        return;
    }

    // Add callback to the list
    callbackVector.push_back(pCallback);
    SetRegisterFlag(pCallback);
    VLOG_DEBUG(__FUNCTION__ " - Successfully registered callback %p for iCallback: %d", pCallback, iCallback);
}

void CCallbackMgr::UnregisterCallback(class CCallbackBase* pCallback)
{
    VLOG_INFO(__FUNCTION__ " - Unregistering callback %p", pCallback);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Null callback pointer");
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutex);

    auto& callbacks = IsGameserverCallback(pCallback) ? m_serverCallbacks : m_clientCallbacks;
    int iCallback = pCallback->GetICallback();

    if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
        // Special handling for API call completed callbacks
        ClearRegisterFlag(pCallback);
        VLOG_DEBUG(__FUNCTION__ " - Unregistered SteamAPICallCompleted_t callback");
        return;
    }

    // Find and remove the callback
    auto callbackIt = callbacks.find(iCallback);
    if (callbackIt == callbacks.end()) {
        VLOG_WARNING(__FUNCTION__ " - No callbacks registered for iCallback: %d", iCallback);
        return;
    }

    auto& callbackVector = callbackIt->second;
    auto it = std::find(callbackVector.begin(), callbackVector.end(), pCallback);

    if (it != callbackVector.end()) {
        callbackVector.erase(it);
        ClearRegisterFlag(pCallback);
        VLOG_DEBUG(__FUNCTION__ " - Successfully unregistered callback %p for iCallback: %d", pCallback, iCallback);
        
        // Clean up empty vector to save memory
        if (callbackVector.empty()) {
            callbacks.erase(callbackIt);
        }
    } else {
        VLOG_WARNING(__FUNCTION__ " - Callback %p not found for iCallback: %d", pCallback, iCallback);
    }
}

void CCallbackMgr::RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    VLOG_INFO(__FUNCTION__ " - Registering call result %p for hAPICall: %llu", pCallback, hAPICall);
    
    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Null callback pointer");
        return;
    }
    
    if (hAPICall == k_uAPICallInvalid) {
        VLOG_ERROR(__FUNCTION__ " - Invalid API call handle");
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutex);
    
    // Check if already registered
    auto existing = m_callResults.find(hAPICall);
    if (existing != m_callResults.end()) {
        VLOG_WARNING(__FUNCTION__ " - API call %llu already has registered callback %p, replacing with %p", 
                     hAPICall, existing->second, pCallback);
    }
    
    m_callResults[hAPICall] = pCallback;
    VLOG_DEBUG(__FUNCTION__ " - Successfully registered call result %p for hAPICall: %llu", pCallback, hAPICall);
}

void CCallbackMgr::UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    VLOG_INFO(__FUNCTION__ " - Unregistering call result %p for hAPICall: %llu", pCallback, hAPICall);

    if (!pCallback) {
        VLOG_ERROR(__FUNCTION__ " - Null callback pointer");
        return;
    }
    
    if (hAPICall == k_uAPICallInvalid) {
        VLOG_ERROR(__FUNCTION__ " - Invalid API call handle");
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = m_callResults.find(hAPICall);
    if (it != m_callResults.end()) {
        if (it->second == pCallback) {
            m_callResults.erase(it);
            VLOG_DEBUG(__FUNCTION__ " - Successfully unregistered call result %p for hAPICall: %llu", pCallback, hAPICall);
        } else {
            VLOG_WARNING(__FUNCTION__ " - Call result for hAPICall: %llu belongs to different callback (%p vs %p)", 
                         hAPICall, it->second, pCallback);
        }
    } else {
        VLOG_WARNING(__FUNCTION__ " - No call result registered for hAPICall: %llu", hAPICall);
    }
}

void CCallbackMgr::DispatchCallbacks()
{
    // Swap the event queue with a temporary queue to avoid deadlocks
    std::queue<CallbackEvent_t> eventQueue;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        eventQueue.swap(m_eventQueue);
    }

    while (!eventQueue.empty()) {
        CallbackEvent_t event = std::move(eventQueue.front());
        eventQueue.pop();
        VLOG_DEBUG(__FUNCTION__ " - iCallback: %d, hAPICall: %llu", event.m_iCallback, event.m_hAPICall);

        if (event.m_callbackType == CallbackEvent_t::CallbackType::CallResult) {
            // Find the callback handler while holding the lock
            CCallbackBase* pCallbackHandler = nullptr;
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                auto it = m_callResults.find(event.m_hAPICall);
                if (it != m_callResults.end()) {
                    pCallbackHandler = it->second;
                }
            }

            // Execute callback WITHOUT holding the lock to prevent deadlocks
            if (pCallbackHandler) {
                VLOG_DEBUG(__FUNCTION__ " - Executing CallResult for hAPICall: %llu", event.m_hAPICall);
                pCallbackHandler->Run(event.m_pCallbackData.get(), event.m_bIOFailure, event.m_hAPICall);
            } else {
                VLOG_ERROR(__FUNCTION__ " - CallResult not found for hAPICall: %llu", event.m_hAPICall);
            }
        } else {
            // Copy callback list while holding the lock
            std::vector<CCallbackBase*> callbackList;
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                
                // Use callback type to determine which map to check
                auto& callbacks = (event.m_callbackType == CallbackEvent_t::CallbackType::ServerCallback) 
                                    ? m_serverCallbacks : m_clientCallbacks;
                
                auto it = callbacks.find(event.m_iCallback);
                if (it != callbacks.end()) {
                    callbackList = it->second;  // Copy the vector
                }
            }

            // Execute callbacks WITHOUT holding the lock to prevent deadlocks
            if (!callbackList.empty()) {
                for (auto* callback : callbackList) {
                    VLOG_DEBUG(__FUNCTION__ " - Executing %s callback for iCallback: %d", 
                               (event.m_callbackType == CallbackEvent_t::CallbackType::ServerCallback) ? "server" : "client",
                               event.m_iCallback);
                    callback->Run(event.m_pCallbackData.get());
                }
            } else {
                VLOG_ERROR(__FUNCTION__ " - %s callback not found for iCallback: %d", 
                           (event.m_callbackType == CallbackEvent_t::CallbackType::ServerCallback) ? "Server" : "Client",
                           event.m_iCallback);
            }
        }
    }
}

//-----------------------------------------------------------------------------
// Unified Internal Event Posting Function
//-----------------------------------------------------------------------------

bool CCallbackMgr::PostCallbackEvent(CallbackEvent_t::CallbackType callbackType, int iCallback, SteamAPICall_t hAPICall, 
                                     void* pvCallbackData, size_t cubCallbackData, bool bIOFailure)
{
    // Validate input parameters
    if (!pvCallbackData || cubCallbackData == 0) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback data: pvCallbackData=%p, cubCallbackData=%zu", 
                   pvCallbackData, cubCallbackData);
        return false;
    }

    std::lock_guard<std::mutex> lock(m_mutex);

    // Create RAII-managed copy of callback data
    auto copiedCallbackData = std::make_unique<char[]>(cubCallbackData);
    memcpy(copiedCallbackData.get(), pvCallbackData, cubCallbackData);

    // For auto-detection of callback type (when callbackType is ClientCallback by default)
    if (callbackType == CallbackEvent_t::CallbackType::ClientCallback && iCallback != 0) {
        // Check if this is actually a server callback
        if (m_serverCallbacks.find(iCallback) != m_serverCallbacks.end()) {
            callbackType = CallbackEvent_t::CallbackType::ServerCallback;
        }
    }

    // Create and enqueue event
    CallbackEvent_t callbackEvent = {
        callbackType,
        iCallback,
        hAPICall,
        bIOFailure,
        std::move(copiedCallbackData),
        cubCallbackData
    };

    m_eventQueue.emplace(std::move(callbackEvent));
    return true;
}

//-----------------------------------------------------------------------------
// Public API Methods
//-----------------------------------------------------------------------------

bool CCallbackMgr::PostCallback(int iCallback, void *pvCallbackData, size_t cubCallbackData)
{
    VLOG_INFO(__FUNCTION__ " - iCallback: %d, cubCallbackData: %zu", iCallback, cubCallbackData);
    return PostCallbackEvent(CallbackEvent_t::CallbackType::ClientCallback, iCallback, k_uAPICallInvalid, 
                            pvCallbackData, cubCallbackData, false);
}

bool CCallbackMgr::PostCallback(int iCallback, void *pvCallbackData, size_t cubCallbackData, CallbackEvent_t::CallbackType callbackType)
{
    VLOG_INFO(__FUNCTION__ " - iCallback: %d, cubCallbackData: %zu, callbackType: %d", 
               iCallback, cubCallbackData, static_cast<int>(callbackType));
    return PostCallbackEvent(callbackType, iCallback, k_uAPICallInvalid, 
                            pvCallbackData, cubCallbackData, false);
}

SteamAPICall_t CCallbackMgr::PostCallResult(void *pvCallbackData, size_t cubCallbackData, bool bIOFailure)
{
    VLOG_INFO(__FUNCTION__ " - cubCallbackData: %zu, bIOFailure: %d", cubCallbackData, bIOFailure);
    
    // Generate unique API call handle for this call result
    static std::atomic<SteamAPICall_t> s_hNextAPICall(k_uAPICallInvalid + 1);
    SteamAPICall_t hAPICall = s_hNextAPICall.fetch_add(1);
    
    bool success = PostCallbackEvent(CallbackEvent_t::CallbackType::CallResult, 0, hAPICall, 
                                    pvCallbackData, cubCallbackData, bIOFailure);
    return success ? hAPICall : k_uAPICallInvalid;
}

void CCallbackMgr::DispatchCallbackImmediate(int iCallback, void *pvCallbackData, size_t cubCallbackData)
{
    VLOG_INFO(__FUNCTION__ " - iCallback: %d, cubCallbackData: %zu", iCallback, cubCallbackData);

    if (!pvCallbackData || cubCallbackData == 0) {
        VLOG_ERROR(__FUNCTION__ " - Invalid callback data");
        return;
    }

    // Create callback data copy for safety
    auto copiedData = std::make_unique<char[]>(cubCallbackData);
    memcpy(copiedData.get(), pvCallbackData, cubCallbackData);

    // Copy callback list while holding the lock
    std::vector<CCallbackBase*> callbackList;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        
        // Check both client and server callbacks
        auto clientIt = m_clientCallbacks.find(iCallback);
        if (clientIt != m_clientCallbacks.end()) {
            callbackList.insert(callbackList.end(), clientIt->second.begin(), clientIt->second.end());
        }
        
        auto serverIt = m_serverCallbacks.find(iCallback);
        if (serverIt != m_serverCallbacks.end()) {
            callbackList.insert(callbackList.end(), serverIt->second.begin(), serverIt->second.end());
        }
    }

    // Execute callbacks immediately WITHOUT holding the lock
    if (!callbackList.empty()) {
        for (auto* callback : callbackList) {
            VLOG_DEBUG(__FUNCTION__ " - Executing immediate callback for iCallback: %d", iCallback);
            callback->Run(copiedData.get());
        }
        VLOG_DEBUG(__FUNCTION__ " - Executed %zu callbacks for iCallback: %d", callbackList.size(), iCallback);
    } else {
        VLOG_WARNING(__FUNCTION__ " - No callbacks registered for iCallback: %d", iCallback);
    }
}
