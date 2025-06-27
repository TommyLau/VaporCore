/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifdef VAPORCORE_ENABLE_LOGGING

#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>

#include "vapor_base.h"
#include "vapor_logger.h"

namespace VaporCore {

Logger& Logger::GetInstance() {
    static Logger instance;
    return instance;
}

void Logger::Initialize(const std::string& filename) {
    VAPORCORE_LOCK_GUARD();
    
    // If already initialized and file is open, keep using it
    if (m_initialized && m_logFile.is_open()) {
        return;
    }
    
    m_logFile.open(filename, std::ios::out | std::ios::app);

    if (m_logFile.is_open()) {
        m_initialized = true;
        // Write initialization message directly to avoid deadlock
        Log(LogLevel::INFO, "VaporCore Logger initialized - " + filename);
    } else {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        m_initialized = false;
    }
}

void Logger::SetLogLevel(LogLevel level) {
    VAPORCORE_LOCK_GUARD();
    m_currentLevel = level;
}

void Logger::SetEnabled(bool enabled) {
    VAPORCORE_LOCK_GUARD();
    m_enabled = enabled;
}

void Logger::Log(LogLevel level, const std::string& message) {
    if (!m_enabled || static_cast<int>(level) < static_cast<int>(m_currentLevel)) {
        return;
    }

    VAPORCORE_LOCK_GUARD();
    
    if (!m_initialized) {
        // Initialize the logger if it's not initialized
        Initialize();
    }

    std::string timeStamp = GetCurrentTimestamp();
    std::string levelString = LevelToString(level);
        
    m_logFile << "[" << timeStamp << "] [" << levelString << "] " << message << std::endl;
    m_logFile.flush(); // Ensure immediate write
    
    // Also output to console for important messages
    if (level >= LogLevel::WARNING) {
        std::cerr << "[" << LevelToString(level) << "] " << message << std::endl;
    }
}

Logger::~Logger() {
    if (m_logFile.is_open()) {
        Log(LogLevel::INFO, "VaporCore Logger shutting down");
        m_logFile.close();
    }
}

std::string Logger::GetCurrentTimestamp() {
    auto currentTime = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(currentTime);
    auto milliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime.time_since_epoch()) % 1000;
    
    std::stringstream stringStream;
    stringStream << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
    stringStream << "." << std::setfill('0') << std::setw(3) << milliSeconds.count();
    
    return stringStream.str();
}

std::string Logger::LevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO ";
        case LogLevel::WARNING: return "WARN ";
        case LogLevel::ERROR:   return "ERROR";
        default:                return "UNKNOWN";
    }
}

} // namespace VaporCore

#endif // VAPORCORE_ENABLE_LOGGING 
