/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: Configuration file reader implementation
 */

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>

#include "vapor_config.h"
#include "vapor_logger.h"

namespace VaporCore {

// Default configuration values (private implementation details)
static const uint32 DEFAULT_STEAM_APP_ID = 0;
static const uint64 DEFAULT_STEAM_ID = 76561198000000000ULL;
static const char* const DEFAULT_STEAM_USERNAME = "VaporCore User";
static const char* const DEFAULT_STEAM_LANGUAGE = "english";

Config::Config()
    : m_sConfigFileName(DEFAULT_CONFIG_FILENAME),
      m_bLoaded(false),
      m_gameId(DEFAULT_STEAM_APP_ID),
      m_steamId(DEFAULT_STEAM_ID),
      m_sUsername(DEFAULT_STEAM_USERNAME),
      m_sLanguage(DEFAULT_STEAM_LANGUAGE)
{
    VLOG_INFO(__FUNCTION__);

    LoadConfig(m_sConfigFileName);
}

Config::~Config()
{
    VLOG_INFO(__FUNCTION__);
}

std::string Config::Trim(const std::string& str) const
{
    // Use C++11 standard library approach
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
    
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();
    
    return (start < end) ? std::string(start, end) : std::string();
}

std::string Config::ToLower(const std::string& str) const
{
    std::string result;
    result.reserve(str.size());
    
    std::transform(str.begin(), str.end(), std::back_inserter(result),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    
    return result;
}

bool Config::ParseLine(const std::string& line, std::string& currentSection)
{
    std::string trimmedLine = Trim(line);
    
    // Skip empty lines and comments
    if (trimmedLine.empty() || trimmedLine[0] == '#' || trimmedLine[0] == ';')
        return true;
    
    // Parse section header [SectionName]
    if (trimmedLine[0] == '[' && trimmedLine.back() == ']')
    {
        currentSection = trimmedLine.substr(1, trimmedLine.length() - 2);
        currentSection = Trim(currentSection);
        // Make section name case-insensitive by converting to lowercase
        currentSection = ToLower(currentSection);
        VLOG_INFO(__FUNCTION__ " - Found section: %s", currentSection.c_str());
        return true;
    }
    
    // Parse key=value pair
    size_t equalPos = trimmedLine.find('=');
    if (equalPos != std::string::npos && !currentSection.empty())
    {
        std::string key = Trim(trimmedLine.substr(0, equalPos));
        std::string value = Trim(trimmedLine.substr(equalPos + 1));
        
        // Make key case-insensitive by converting to lowercase
        key = ToLower(key);
        
        // Remove quotes if present
        if (value.length() >= 2 && 
            ((value[0] == '"' && value.back() == '"') || 
             (value[0] == '\'' && value.back() == '\'')))
        {
            value = value.substr(1, value.length() - 2);
        }
        
        m_configData[currentSection][key] = value;
        VLOG_INFO(__FUNCTION__ " - Config: [%s] %s = %s", currentSection.c_str(), key.c_str(), value.c_str());
        return true;
    }
    
    // Invalid line format
    VLOG_WARNING(__FUNCTION__ " - Invalid config line: %s", trimmedLine.c_str());
    return false;
}

bool Config::LoadConfig(const std::string& filename)
{
    m_sConfigFileName = filename;
    m_configData.clear();
    m_bLoaded = false;
    
    VLOG_INFO(__FUNCTION__ " - Loading configuration from: %s", filename.c_str());
    
    std::ifstream file(filename);
    if (!file.is_open())
    {
        VLOG_WARNING(__FUNCTION__ " - Could not open config file: %s (using defaults)", filename.c_str());
        return false;
    }
    
    std::string line;
    std::string currentSection;
    int lineNumber = 0;
    
    while (std::getline(file, line))
    {
        lineNumber++;
        if (!ParseLine(line, currentSection))
        {
            VLOG_WARNING(__FUNCTION__ " - Error parsing line %d in %s", lineNumber, filename.c_str());
        }
    }
    
    file.close();
    m_bLoaded = true;
    
    // Load Steam settings after config is loaded
    m_gameId = CGameID(GetUInt32(CONFIG_SECTION_STEAM, CONFIG_KEY_STEAM_APP_ID, DEFAULT_STEAM_APP_ID));
    m_steamId = CSteamID(GetUInt64(CONFIG_SECTION_STEAM, CONFIG_KEY_STEAM_STEAM_ID, DEFAULT_STEAM_ID));
    m_sUsername = GetString(CONFIG_SECTION_STEAM, CONFIG_KEY_STEAM_USERNAME, DEFAULT_STEAM_USERNAME);
    m_sLanguage = GetString(CONFIG_SECTION_STEAM, CONFIG_KEY_STEAM_LANGUAGE, DEFAULT_STEAM_LANGUAGE);

    VLOG_INFO(__FUNCTION__ " - Loaded Steam settings: AppId=%u, SteamId=%llu, Username=%s, Language=%s", 
               m_gameId.AppID(), m_steamId.ConvertToUint64(), m_sUsername.c_str(), m_sLanguage.c_str());
    
    VLOG_INFO(__FUNCTION__ " - Configuration loaded successfully from: %s", filename.c_str());
    return true;
}

std::string Config::GetString(const std::string& section, const std::string& key, const std::string& defaultValue) const
{
    // Make lookups case-insensitive
    std::string lowerSection = ToLower(section);
    std::string lowerKey = ToLower(key);
    
    auto sectionIt = m_configData.find(lowerSection);
    if (sectionIt != m_configData.end())
    {
        auto keyIt = sectionIt->second.find(lowerKey);
        if (keyIt != sectionIt->second.end())
        {
            return keyIt->second;
        }
    }
    return defaultValue;
}

bool Config::GetBool(const std::string& section, const std::string& key, bool defaultValue) const
{
    std::string value = ToLower(GetString(section, key));
    if (value.empty()) return defaultValue;
    
    return (value == "true" || value == "1" || value == "yes" || value == "on");
}

int Config::GetInt(const std::string& section, const std::string& key, int defaultValue) const
{
    std::string value = GetString(section, key);
    if (value.empty()) return defaultValue;
    
    try
    {
        return std::stoi(value);
    }
    catch (const std::exception&)
    {
        VLOG_WARNING(__FUNCTION__ " - Invalid integer value for [%s] %s: %s", section.c_str(), key.c_str(), value.c_str());
        return defaultValue;
    }
}

uint32 Config::GetUInt32(const std::string& section, const std::string& key, uint32 defaultValue) const
{
    std::string value = GetString(section, key);
    if (value.empty()) return defaultValue;
    
    try
    {
        unsigned long result = std::stoul(value);
        return static_cast<uint32>(result);
    }
    catch (const std::exception&)
    {
        VLOG_WARNING(__FUNCTION__ " - Invalid uint32 value for [%s] %s: %s", section.c_str(), key.c_str(), value.c_str());
        return defaultValue;
    }
}

uint64 Config::GetUInt64(const std::string& section, const std::string& key, uint64 defaultValue) const
{
    std::string value = GetString(section, key);
    if (value.empty()) return defaultValue;
    
    try
    {
        return std::stoull(value);
    }
    catch (const std::exception&)
    {
        VLOG_WARNING(__FUNCTION__ " - Invalid uint64 value for [%s] %s: %s", section.c_str(), key.c_str(), value.c_str());
        return defaultValue;
    }
}

float Config::GetFloat(const std::string& section, const std::string& key, float defaultValue) const
{
    std::string value = GetString(section, key);
    if (value.empty()) return defaultValue;
    
    try
    {
        return std::stof(value);
    }
    catch (const std::exception&)
    {
        VLOG_WARNING(__FUNCTION__ " - Invalid float value for [%s] %s: %s", section.c_str(), key.c_str(), value.c_str());
        return defaultValue;
    }
}

std::vector<std::string> Config::GetStringList(const std::string& section, const std::string& key) const
{
    std::vector<std::string> result;
    std::string value = GetString(section, key);
    
    if (value.empty()) return result;
    
    std::stringstream ss(value);
    std::string item;
    
    while (std::getline(ss, item, ','))
    {
        item = Trim(item);
        if (!item.empty())
        {
            result.push_back(item);
        }
    }
    
    return result;
}

std::vector<int> Config::GetIntList(const std::string& section, const std::string& key) const
{
    std::vector<int> result;
    std::vector<std::string> stringList = GetStringList(section, key);
    
    for (const std::string& str : stringList)
    {
        try
        {
            result.push_back(std::stoi(str));
        }
        catch (const std::exception&)
        {
            VLOG_WARNING(__FUNCTION__ " - Invalid integer in list for [%s] %s: %s", section.c_str(), key.c_str(), str.c_str());
        }
    }
    
    return result;
}

bool Config::HasSection(const std::string& section) const
{
    std::string lowerSection = ToLower(section);
    return m_configData.find(lowerSection) != m_configData.end();
}

bool Config::HasKey(const std::string& section, const std::string& key) const
{
    std::string lowerSection = ToLower(section);
    std::string lowerKey = ToLower(key);
    
    auto sectionIt = m_configData.find(lowerSection);
    if (sectionIt != m_configData.end())
    {
        return sectionIt->second.find(lowerKey) != sectionIt->second.end();
    }
    return false;
}

std::vector<std::string> Config::GetSectionKeys(const std::string& section) const
{
    std::vector<std::string> result;
    auto sectionIt = m_configData.find(section);
    
    if (sectionIt != m_configData.end())
    {
        for (const auto& pair : sectionIt->second)
        {
            result.push_back(pair.first);
        }
    }
    
    return result;
}

} // namespace VaporCore 
