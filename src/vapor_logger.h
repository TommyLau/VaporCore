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
#include <memory>
#include <sstream>

enum class LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class Logger {
public:
    static Logger& GetInstance();
    
    void Initialize(const std::string& filename = "vaporcore.log");
    void SetLogLevel(LogLevel level);
    void SetEnabled(bool enabled);
    
    void Log(LogLevel level, const std::string& message);

    // Variadic template methods for format-style logging
    template<typename... Args>
    void Debug(const char* format, Args... args) {
        Log(LogLevel::DEBUG, FormatMessage(format, args...));
    }

    template<typename... Args>
    void Info(const char* format, Args... args) {
        Log(LogLevel::INFO, FormatMessage(format, args...));
    }

    template<typename... Args>
    void Warning(const char* format, Args... args) {
        Log(LogLevel::WARNING, FormatMessage(format, args...));
    }

    template<typename... Args>
    void Error(const char* format, Args... args) {
        Log(LogLevel::ERROR, FormatMessage(format, args...));
    }

    // Single string overloads
    void Debug(const std::string& message) { Log(LogLevel::DEBUG, message); }
    void Info(const std::string& message) { Log(LogLevel::INFO, message); }
    void Warning(const std::string& message) { Log(LogLevel::WARNING, message); }
    void Error(const std::string& message) { Log(LogLevel::ERROR, message); }
    
    ~Logger();

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    std::string GetCurrentTimestamp();
    std::string LevelToString(LogLevel level);

    template<typename... Args>
    std::string FormatMessage(const char* format, Args... args) {
        int bufferSize = snprintf(nullptr, 0, format, args...);
        if (bufferSize <= 0) return "Format error";
        
        std::string formattedResult;
        formattedResult.resize(bufferSize + 1);
        snprintf(&formattedResult[0], bufferSize + 1, format, args...);
        formattedResult.pop_back(); // Remove null terminator
        return formattedResult;
    }
    
    std::ofstream m_logFile;
    LogLevel m_currentLevel = LogLevel::INFO;
    bool m_enabled = true;
    bool m_initialized = false;
};

// Convenience macros with variadic arguments support
#define VLOG_DEBUG(...) Logger::GetInstance().Debug(__VA_ARGS__)
#define VLOG_INFO(...) Logger::GetInstance().Info(__VA_ARGS__)
#define VLOG_WARNING(...) Logger::GetInstance().Warning(__VA_ARGS__)
#define VLOG_ERROR(...) Logger::GetInstance().Error(__VA_ARGS__)

// Convenience macros for log level control
#define VLOG_SET_LEVEL(level) Logger::GetInstance().SetLogLevel(level)
#define VLOG_SET_DEBUG() Logger::GetInstance().SetLogLevel(LogLevel::DEBUG)
#define VLOG_SET_INFO() Logger::GetInstance().SetLogLevel(LogLevel::INFO)
#define VLOG_SET_WARNING() Logger::GetInstance().SetLogLevel(LogLevel::WARNING)
#define VLOG_SET_ERROR() Logger::GetInstance().SetLogLevel(LogLevel::ERROR)

#else

// When logging is disabled, define empty macros
#define VLOG_DEBUG(...) ((void)0)
#define VLOG_INFO(...) ((void)0)
#define VLOG_WARNING(...) ((void)0)
#define VLOG_ERROR(...) ((void)0)

// Disabled log level control macros
#define VLOG_SET_LEVEL(level) ((void)0)
#define VLOG_SET_DEBUG() ((void)0)
#define VLOG_SET_INFO() ((void)0)
#define VLOG_SET_WARNING() ((void)0)
#define VLOG_SET_ERROR() ((void)0)

#endif // VAPORCORE_ENABLE_LOGGING

#endif // VAPORCORE_LOGGER_H 
