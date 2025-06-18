/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2024 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifdef VAPORCORE_ENABLE_LOGGING

#include "logger.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>

namespace VaporCore {

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::initialize(const std::string& filename) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (m_initialized) {
        if (m_logFile.is_open()) {
            m_logFile.close();
        }
    }
    
    m_logFile.open(filename, std::ios::out | std::ios::app);
    if (m_logFile.is_open()) {
        m_initialized = true;
        // Write initialization message directly to avoid deadlock
        std::string timestamp = getCurrentTimestamp();
        m_logFile << "[" << timestamp << "] [INFO ] VaporCore Logger initialized - " << filename << std::endl;
        m_logFile.flush();
    } else {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        m_initialized = false;
    }
}

void Logger::setLogLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_currentLevel = level;
}

void Logger::setEnabled(bool enabled) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_enabled = enabled;
}

void Logger::log(LogLevel level, const std::string& message) {
    if (!m_enabled || static_cast<int>(level) < static_cast<int>(m_currentLevel)) {
        return;
    }
    
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_initialized && level != LogLevel::INFO) {
        // Auto-initialize with default filename if not already done
        initialize();
    }
    
    if (m_initialized && m_logFile.is_open()) {
        std::string timestamp = getCurrentTimestamp();
        std::string levelStr = levelToString(level);
        
        m_logFile << "[" << timestamp << "] [" << levelStr << "] " << message << std::endl;
        m_logFile.flush(); // Ensure immediate write
    }
    
    // Also output to console for important messages
    if (level >= LogLevel::WARNING) {
        std::cerr << "[" << levelToString(level) << "] " << message << std::endl;
    }
}

void Logger::debug(const std::string& message) {
    log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::ERROR, message);
}

Logger::~Logger() {
    if (m_logFile.is_open()) {
        std::string timestamp = getCurrentTimestamp();
        m_logFile << "[" << timestamp << "] [INFO ] VaporCore Logger shutting down" << std::endl;
        m_logFile.flush();
        m_logFile.close();
    }
}

std::string Logger::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    ss << "." << std::setfill('0') << std::setw(3) << ms.count();
    
    return ss.str();
}

std::string Logger::levelToString(LogLevel level) {
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