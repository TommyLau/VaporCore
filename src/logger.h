/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef VAPORCORE_LOGGER_H
#define VAPORCORE_LOGGER_H
#ifdef _WIN32
#pragma once
#endif

#ifdef VAPORCORE_ENABLE_LOGGING

#include <string>
#include <fstream>
#include <mutex>
#include <memory>

namespace VaporCore {

enum class LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class Logger {
public:
    static Logger& getInstance();
    
    void initialize(const std::string& filename = "vaporcore.log");
    void setLogLevel(LogLevel level);
    void setEnabled(bool enabled);
    
    void log(LogLevel level, const std::string& message);
    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    
    ~Logger();

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    std::string getCurrentTimestamp();
    std::string levelToString(LogLevel level);
    
    std::ofstream m_logFile;
    std::mutex m_mutex;
    LogLevel m_currentLevel = LogLevel::INFO;
    bool m_enabled = true;
    bool m_initialized = false;
};

// Convenience macros
#define VLOG_DEBUG(msg) VaporCore::Logger::getInstance().debug(msg)
#define VLOG_INFO(msg) VaporCore::Logger::getInstance().info(msg)
#define VLOG_WARNING(msg) VaporCore::Logger::getInstance().warning(msg)
#define VLOG_ERROR(msg) VaporCore::Logger::getInstance().error(msg)

} // namespace VaporCore

#else

// When logging is disabled, define empty macros
#define VLOG_DEBUG(msg) ((void)0)
#define VLOG_INFO(msg) ((void)0)
#define VLOG_WARNING(msg) ((void)0)
#define VLOG_ERROR(msg) ((void)0)

#endif // VAPORCORE_ENABLE_LOGGING

#endif // VAPORCORE_LOGGER_H 
