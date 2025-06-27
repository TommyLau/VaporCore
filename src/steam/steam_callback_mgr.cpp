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

#include "vapor_base.h"

// Static instance
CCallbackMgr* CCallbackMgr::s_pInstance = nullptr;

CCallbackMgr* CCallbackMgr::GetInstance()
{
    VLOG_INFO(__FUNCTION__);

    if (!s_pInstance) {
        s_pInstance = new CCallbackMgr();
    }
    return s_pInstance;
}

void CCallbackMgr::ReleaseInstance()
{
    VLOG_INFO(__FUNCTION__);

    if (s_pInstance) {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

void CCallbackMgr::RegisterCallback(class CCallbackBase* pCallback, int iCallback)
{
    VLOG_INFO(__FUNCTION__);

    std::lock_guard<std::mutex> lock(m_mutex);

    auto& callbacks = BIsGameserverCallback(pCallback) ? m_serverCallbacks : m_clientCallbacks;
    pCallback->m_iCallback = iCallback;

    if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
        // TODO: Results add call completed?
        // TODO: Mark callback as completed?
        SetRegisterFlag(pCallback);
        VLOG_DEBUG("CCallbackMgr::RegisterCallback: SteamAPICallCompleted_t callback");
        return;
    }

    if (std::find(callbacks[iCallback].begin(), callbacks[iCallback].end(), pCallback) == callbacks[iCallback].end()) {
        // Add callback to the list
        callbacks[iCallback].push_back(pCallback);
        SetRegisterFlag(pCallback);
        // TODO: Add callback to the list
    }
}

void CCallbackMgr::UnregisterCallback(class CCallbackBase* pCallback)
{
    VLOG_INFO(__FUNCTION__);

    std::lock_guard<std::mutex> lock(m_mutex);

    auto& callbacks = BIsGameserverCallback(pCallback) ? m_serverCallbacks : m_clientCallbacks;
    int iCallback = pCallback->GetICallback();

    if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
        // TODO: Remove from completed callbacks?
        ClearRegisterFlag(pCallback);
        VLOG_DEBUG("CCallbackMgr::UnregisterCallback: SteamAPICallCompleted_t callback");
        return;
    }

    auto it = std::find(callbacks[iCallback].begin(), callbacks[iCallback].end(), pCallback);

    if (it != callbacks[iCallback].end()) {
        callbacks[iCallback].erase(it);
        ClearRegisterFlag(pCallback);
        // TODO: Remove from completed callbacks?
    }
}

void CCallbackMgr::RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    VLOG_INFO(__FUNCTION__);
    std::lock_guard<std::mutex> lock(m_mutex);
    m_callResults[hAPICall] = pCallback;
}

void CCallbackMgr::UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    VLOG_INFO(__FUNCTION__);

    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_callResults.count(hAPICall) && m_callResults[hAPICall] == pCallback) {
        m_callResults.erase(hAPICall);
    }
}

void CCallbackMgr::RunCallbacks()
{
    VLOG_INFO(__FUNCTION__);

    // Swap the event queue with a temporary queue to avoid deadlocks
    std::queue<CallbackEvent_t> eventQueue;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        eventQueue.swap(m_eventQueue);
    }

    while (!eventQueue.empty()) {
        CallbackEvent_t event = eventQueue.front();
        eventQueue.pop();
        VLOG_DEBUG("Processing event, iCallback=%d, isCallResult=%d", event.m_iCallback, event.m_bCallResult);

        if (event.m_bCallResult) {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto it = m_callResults.find(event.m_hAPICall);
            if (it != m_callResults.end()) {
                VLOG_DEBUG("Executing CallResult for hAPICall=%llu", event.m_hAPICall);
                it->second->Run(event.m_pCallbackData, event.m_bIOFailure, event.m_hAPICall);
                delete static_cast<char*>(event.m_pCallbackData);
            } else {
                VLOG_DEBUG("CallResult not found for hAPICall=%llu", event.m_hAPICall);
            }
        } else {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto& callbacks = (event.m_iCallback & CCallbackBase::k_ECallbackFlagsGameServer) ? m_serverCallbacks : m_clientCallbacks;
            auto it = callbacks.find(event.m_iCallback);
            if (it != callbacks.end()) {
                for (auto* callback : it->second) {
                    VLOG_DEBUG("Executing callback for iCallback=%d", event.m_iCallback);
                    callback->Run(event.m_pCallbackData);
                }
            } else {
                VLOG_DEBUG("Callback not found for iCallback=%d", event.m_iCallback);
            }
            delete static_cast<char*>(event.m_pCallbackData);
        }
    }
}

void CCallbackMgr::AddCallback(int iCallback, void *pCallbackData, size_t cbCallbackData, SteamAPICall_t hAPICall)
{
    VLOG_INFO(__FUNCTION__);

    std::lock_guard<std::mutex> lock(m_mutex);

    auto callbackData = new char[cbCallbackData];
    memcpy(callbackData, pCallbackData, cbCallbackData);

    CallbackEvent_t event = { iCallback, callbackData, cbCallbackData, hAPICall, false, hAPICall != k_uAPICallInvalid };
    m_eventQueue.push(event);

    VLOG_DEBUG("CCallbackMgr::AddCallback: iCallback = %d, hAPICall = %llu, cbCallbackData = %zu", iCallback, hAPICall, cbCallbackData);
}
