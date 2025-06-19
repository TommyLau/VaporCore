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
#include <sstream>

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

    // Variadic template methods for format-style logging
    template<typename... Args>
    void debug(const char* format, Args... args) {
        log(LogLevel::DEBUG, formatMessage(format, args...));
    }

    template<typename... Args>
    void info(const char* format, Args... args) {
        log(LogLevel::INFO, formatMessage(format, args...));
    }

    template<typename... Args>
    void warning(const char* format, Args... args) {
        log(LogLevel::WARNING, formatMessage(format, args...));
    }

    template<typename... Args>
    void error(const char* format, Args... args) {
        log(LogLevel::ERROR, formatMessage(format, args...));
    }

    // Single string overloads
    void debug(const std::string& message) { log(LogLevel::DEBUG, message); }
    void info(const std::string& message) { log(LogLevel::INFO, message); }
    void warning(const std::string& message) { log(LogLevel::WARNING, message); }
    void error(const std::string& message) { log(LogLevel::ERROR, message); }
    
    ~Logger();

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    std::string getCurrentTimestamp();
    std::string levelToString(LogLevel level);

    template<typename... Args>
    std::string formatMessage(const char* format, Args... args) {
        int size = snprintf(nullptr, 0, format, args...);
        if (size <= 0) return "Format error";
        
        std::string result;
        result.resize(size + 1);
        snprintf(&result[0], size + 1, format, args...);
        result.pop_back(); // Remove null terminator
        return result;
    }
    
    std::ofstream m_logFile;
    std::mutex m_mutex;
    LogLevel m_currentLevel = LogLevel::INFO;
    bool m_enabled = true;
    bool m_initialized = false;
};

// Convenience macros with variadic arguments support
#define VLOG_DEBUG(...) VaporCore::Logger::getInstance().debug(__VA_ARGS__)
#define VLOG_INFO(...) VaporCore::Logger::getInstance().info(__VA_ARGS__)
#define VLOG_WARNING(...) VaporCore::Logger::getInstance().warning(__VA_ARGS__)
#define VLOG_ERROR(...) VaporCore::Logger::getInstance().error(__VA_ARGS__)

} // namespace VaporCore

#else

// When logging is disabled, define empty macros
#define VLOG_DEBUG(...) ((void)0)
#define VLOG_INFO(...) ((void)0)
#define VLOG_WARNING(...) ((void)0)
#define VLOG_ERROR(...) ((void)0)

#endif // VAPORCORE_ENABLE_LOGGING

#endif // VAPORCORE_LOGGER_H 
