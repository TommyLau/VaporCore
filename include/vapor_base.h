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

// Steam API headers with steam_ prefix from src folder
#include "steam_apps.h"
#include "steam_app_list.h"
#include "steam_app_ticket.h"
#include "steam_callback_mgr.h"
#include "steam_client.h"
#include "steam_controller.h"
#include "steam_friends.h"
#include "steam_game_coordinator.h"
#include "steam_game_server.h"
#include "steam_game_server_stats.h"
#include "steam_game_stats.h"
#include "steam_html_surface.h"
#include "steam_http.h"
#include "steam_inventory.h"
#include "steam_master_server_updater.h"
#include "steam_matchmaking.h"
#include "steam_music.h"
#include "steam_music_remote.h"
#include "steam_networking.h"
#include "steam_remote_storage.h"
#include "steam_screenshots.h"
#include "steam_ugc.h"
#include "steam_unified_messages.h"
#include "steam_user.h"
#include "steam_user_stats.h"
#include "steam_utils.h"
#include "steam_video.h"

// VaporCore callback manager
#include "vapor_logger.h"
#include "vapor_config.h"

// Global synchronization for thread-safe operations
extern std::recursive_mutex g_GlobalMutex;

// Utility macros for thread-safe operations (global scope)
#define VAPORCORE_LOCK_GUARD() std::lock_guard<std::recursive_mutex> lock(g_GlobalMutex)
#define VAPORCORE_LOCK() g_GlobalMutex.lock()
#define VAPORCORE_UNLOCK() g_GlobalMutex.unlock()

namespace VaporCore {

// Default Steam user handles
const HSteamUser DEFAULT_CLIENT_USER = 1;
const HSteamUser DEFAULT_SERVER_USER = 2;

} // namespace VaporCore

#endif // VAPORCORE_BASE_H 
