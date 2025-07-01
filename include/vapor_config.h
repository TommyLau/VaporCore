/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: Configuration file reader for VaporCore settings
 */

#ifndef VAPORCORE_CONFIG_H
#define VAPORCORE_CONFIG_H
#ifdef _WIN32
#pragma once
#endif

#include <string>
#include <map>
#include <vector>
#include <steam_api.h>

namespace VaporCore {

// Default configuration filename
static const char* const DEFAULT_CONFIG_FILENAME = "vaporcore.ini";

// Configuration section names
static const char* const CONFIG_SECTION_STEAM = "Steam";

// Steam section keys
static const char* const CONFIG_KEY_STEAM_APP_ID = "app_id";
static const char* const CONFIG_KEY_STEAM_STEAM_ID = "steam_id";
static const char* const CONFIG_KEY_STEAM_USERNAME = "username";
static const char* const CONFIG_KEY_STEAM_LANGUAGE = "language";

class Config
{
public:
	// Singleton accessor
    static Config& GetInstance()
	{
		static Config instance;
		return instance;
	}

public:
    // Configuration loading
    bool LoadConfig(const std::string& filename = DEFAULT_CONFIG_FILENAME);
    bool IsLoaded() const { return m_bLoaded; }
    
    // String value getters
    std::string GetString(const std::string& section, const std::string& key, const std::string& defaultValue = "") const;
    
    // Type-specific getters with defaults
    bool GetBool(const std::string& section, const std::string& key, bool defaultValue = false) const;
    int GetInt(const std::string& section, const std::string& key, int defaultValue = 0) const;
    uint32 GetUInt32(const std::string& section, const std::string& key, uint32 defaultValue = 0) const;
    uint64 GetUInt64(const std::string& section, const std::string& key, uint64 defaultValue = 0) const;
    float GetFloat(const std::string& section, const std::string& key, float defaultValue = 0.0f) const;
    
    // List getter (comma-separated values)
    std::vector<std::string> GetStringList(const std::string& section, const std::string& key) const;
    std::vector<int> GetIntList(const std::string& section, const std::string& key) const;
    
    // Section/key existence checks
    bool HasSection(const std::string& section) const;
    bool HasKey(const std::string& section, const std::string& key) const;
    
    // Get all keys in a section
    std::vector<std::string> GetSectionKeys(const std::string& section) const;
    
    // Direct getters for Steam settings
    CGameID GetGameId() const { return m_gameId; }
    CSteamID GetSteamId() const { return m_steamId; }
    const std::string& GetUsername() const { return m_sUsername; }
    const std::string& GetLanguage() const { return m_sLanguage; }

private:
    // Private constructor and destructor for singleton
    Config();
    ~Config();

    // Delete copy constructor and assignment operator
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    // Private helper methods
    std::string Trim(const std::string& str) const;
    std::string ToLower(const std::string& str) const;
    bool ParseLine(const std::string& line, std::string& currentSection);

private:
    // Configuration file name
    std::string m_sConfigFileName;
    bool m_bLoaded;
    
    // Configuration data storage (section -> key -> value)
    std::map<std::string, std::map<std::string, std::string>> m_configData;
    
    // Steam settings (loaded once at startup)
    CGameID m_gameId;
    CSteamID m_steamId;
    std::string m_sUsername;
    std::string m_sLanguage;
};

} // namespace VaporCore

#endif // VAPORCORE_CONFIG_H 
