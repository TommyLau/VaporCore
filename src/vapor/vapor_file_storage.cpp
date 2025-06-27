/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 * 
 * Purpose: File storage implementation for Steam Remote Storage emulation
 */

#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cctype>

#include "vapor_file_storage.h"
#include "vapor_logger.h"

namespace VaporCore {

// Default quota limits (matching Steam's typical limits)
static const int32 DEFAULT_TOTAL_QUOTA = 100 * 1024 * 1024;  // 100MB
static const int32 DEFAULT_FILE_LIMIT = 1000;                // Max files

FileStorage::FileStorage(const std::string& storageDir)
    : m_storageDirectory(storageDir)
{
    // Ensure the storage directory exists
    if (!EnsureDirectoryExists()) {
        VLOG_DEBUG(__FUNCTION__ " - Failed to create storage directory: %s", storageDir.c_str());
    }
    
    // Initialize file index from existing files
    CacheFileList();
}

FileStorage::~FileStorage()
{
}

bool FileStorage::WriteFile(const std::string& filename, const void* data, size_t size)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return false;
    }
    
    std::string fullPath = GetFullPath(filename);
    
    try {
        std::ofstream file(fullPath, std::ios::binary);
        if (!file.is_open()) {
            VLOG_ERROR(__FUNCTION__ " - Failed to open file for writing: %s", fullPath.c_str());
            return false;
        }
        
        file.write(static_cast<const char*>(data), size);
        if (!file.good()) {
            VLOG_ERROR(__FUNCTION__ " - Failed to write data to file: %s", fullPath.c_str());
            return false;
        }
        
        file.close();
        
        VLOG_DEBUG(__FUNCTION__ " - Successfully wrote %zu bytes to: %s", size, fullPath.c_str());
        return true;
        
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Exception writing file %s: %s", fullPath.c_str(), e.what());
        return false;
    }
}

int32 FileStorage::ReadFile(const std::string& filename, void* buffer, size_t maxSize)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return 0;
    }

    std::string fullPath = GetFullPath(filename);
    
    try {
        std::ifstream file(fullPath, std::ios::binary);
        if (!file.is_open()) {
            VLOG_DEBUG(__FUNCTION__ " - File not found: %s", fullPath.c_str());
            return 0;
        }
        
        // Get file size
        file.seekg(0, std::ios::end);
        size_t fileSize = static_cast<size_t>(file.tellg());
        file.seekg(0, std::ios::beg);
        
        // Read up to maxSize bytes
        size_t bytesToRead = std::min(fileSize, maxSize);
        file.read(static_cast<char*>(buffer), bytesToRead);
        
        if (!file.good() && !file.eof()) {
            VLOG_ERROR(__FUNCTION__ " - Error reading file: %s", fullPath.c_str());
            return 0;
        }
        
        VLOG_DEBUG(__FUNCTION__ " - Successfully read %zu bytes from: %s", bytesToRead, fullPath.c_str());
        return static_cast<int32>(bytesToRead);
        
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Exception reading file %s: %s", fullPath.c_str(), e.what());
        return 0;
    }
}

bool FileStorage::FileExists(const std::string& filename)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return false;
    }

    std::string fullPath = GetFullPath(filename);
    bool exists = std::filesystem::exists(fullPath) && std::filesystem::is_regular_file(fullPath);
    
    VLOG_DEBUG(__FUNCTION__ " - File exists check: %s = %s", fullPath.c_str(), exists ? "true" : "false");

    return exists;
}

bool FileStorage::DeleteFile(const std::string& filename)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return false;
    }

    std::string fullPath = GetFullPath(filename);
    VLOG_DEBUG(__FUNCTION__ " - Deleting file: %s", fullPath.c_str());
    
    try {
        if (std::filesystem::remove(fullPath)) {
            VLOG_DEBUG(__FUNCTION__ " - Successfully deleted: %s", fullPath.c_str());
            return true;
        } else {
            VLOG_DEBUG(__FUNCTION__ " - File not found for deletion: %s", fullPath.c_str());
            return false;
        }
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Exception deleting file %s: %s", fullPath.c_str(), e.what());
        return false;
    }
}

size_t FileStorage::GetFileSize(const std::string& filename)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return 0;
    }

    std::string fullPath = GetFullPath(filename);
    
    try {
        if (std::filesystem::exists(fullPath)) {
            size_t size = static_cast<size_t>(std::filesystem::file_size(fullPath));
            VLOG_DEBUG(__FUNCTION__ " - File size: %s = %zu bytes", fullPath.c_str(), size);
            return size;
        }
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Exception getting file size %s: %s", fullPath.c_str(), e.what());
    }
    
    return 0;
}

int64 FileStorage::GetFileTimestamp(const std::string& filename)
{
    if (!IsValidFilename(filename)) {
        VLOG_ERROR(__FUNCTION__ " - Invalid filename: %s", filename.c_str());
        return 0;
    }

    std::string fullPath = GetFullPath(filename);
    
    try {
        if (std::filesystem::exists(fullPath)) {
            auto ftime = std::filesystem::last_write_time(fullPath);
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
            auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(sctp.time_since_epoch()).count();
            VLOG_DEBUG(__FUNCTION__ " - File timestamp: %s = %lld", fullPath.c_str(), timestamp);
            return timestamp;
        }
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Exception getting file timestamp %s: %s", fullPath.c_str(), e.what());
    }
    
    return 0;
}

int32 FileStorage::GetFileCount()
{
    // Cache the current file list for subsequent GetFileNameAndSize() calls
    CacheFileList();
    
    int32 count = static_cast<int32>(m_indexToFile.size());
    VLOG_DEBUG(__FUNCTION__ " - File count: %d", count);
    
    return count;
}

std::string FileStorage::GetFileNameAndSize(int index, int32* pSize)
{
    // Check if file list is cached (GetFileCount should be called first)
    if (m_indexToFile.empty()) {
        VLOG_WARNING(__FUNCTION__ " - GetFileNameAndSize called without calling GetFileCount first - caching file list");
        CacheFileList();
    }
    
    if (index < 0 || index >= static_cast<int>(m_indexToFile.size())) {
        VLOG_DEBUG(__FUNCTION__ " - Invalid file index: %d", index);
        if (pSize) *pSize = 0;
        return "";
    }
    
    const std::string& filename = m_indexToFile[index];
    if (pSize) {
        *pSize = static_cast<int32>(GetFileSize(filename));
    }
    
    VLOG_DEBUG(__FUNCTION__ " - File at index %d: %s", index, filename.c_str());
    return filename;
}

size_t FileStorage::GetTotalStorageUsed()
{
    size_t totalSize = 0;
    
    try {
        if (std::filesystem::exists(m_storageDirectory)) {
            for (const auto& entry : std::filesystem::directory_iterator(m_storageDirectory)) {
                if (entry.is_regular_file()) {
                    totalSize += static_cast<size_t>(entry.file_size());
                }
            }
        }
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Error calculating storage usage: %s", e.what());
    }
    
    VLOG_DEBUG(__FUNCTION__ " - Total storage used: %zu bytes", totalSize);
    return totalSize;
}

bool FileStorage::GetQuota(int32* pnTotalBytes, int32* pnAvailableBytes)
{
    if (!pnTotalBytes || !pnAvailableBytes) {
        return false;
    }
    
    size_t usedBytes = GetTotalStorageUsed();
    
    *pnTotalBytes = DEFAULT_TOTAL_QUOTA;
    *pnAvailableBytes = std::max(0, static_cast<int32>(DEFAULT_TOTAL_QUOTA - usedBytes));
    
    VLOG_DEBUG(__FUNCTION__ " - Quota: Total=%d, Available=%d, Used=%zu", 
               *pnTotalBytes, *pnAvailableBytes, usedBytes);
    
    return true;
}

bool FileStorage::EnsureDirectoryExists()
{
    try {
        if (!std::filesystem::exists(m_storageDirectory)) {
            std::filesystem::create_directories(m_storageDirectory);
            VLOG_INFO(__FUNCTION__ " - Created storage directory: %s", m_storageDirectory.c_str());
        }
        return true;
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Failed to create directory %s: %s", m_storageDirectory.c_str(), e.what());
        return false;
    }
}

bool FileStorage::IsValidFilename(const std::string& filename) const
{
    if (filename.empty() || filename.length() > 260) {
        return false;
    }
    
    // Check for invalid characters
    const std::string invalidChars = "<>:\"|?*";
    for (char c : invalidChars) {
        if (filename.find(c) != std::string::npos) {
            return false;
        }
    }
    
    // Check for reserved names (Windows)
    std::string upper = filename;
    std::transform(upper.begin(), upper.end(), upper.begin(), 
                   [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
    
    const std::vector<std::string> reserved = {
        "CON", "PRN", "AUX", "NUL",
        "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9",
        "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6", "LPT7", "LPT8", "LPT9"
    };
    
    for (const std::string& res : reserved) {
        if (upper == res || upper.substr(0, res.length() + 1) == res + ".") {
            return false;
        }
    }
    
    return true;
}

std::string FileStorage::NormalizeFilename(const std::string& filename) const
{
    std::string normalized = filename;
    
    // Convert to lowercase (Steam requirement)
    std::transform(normalized.begin(), normalized.end(), normalized.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    
    // Replace backslashes with forward slashes
    std::replace(normalized.begin(), normalized.end(), '\\', '/');
    
    // Remove leading slashes
    while (!normalized.empty() && normalized[0] == '/') {
        normalized.erase(0, 1);
    }
    
    return normalized;
}

std::string FileStorage::GetFullPath(const std::string& filename) const
{
    std::string normalized = NormalizeFilename(filename);
    return m_storageDirectory + "/" + normalized;
}

void FileStorage::CacheFileList()
{
    m_indexToFile.clear();
    
    try {
        if (std::filesystem::exists(m_storageDirectory)) {
            for (const auto& entry : std::filesystem::directory_iterator(m_storageDirectory)) {
                if (entry.is_regular_file()) {
                    std::string filename = entry.path().filename().string();
                    std::string normalized = NormalizeFilename(filename);
                    m_indexToFile.push_back(normalized);
                }
            }
        }
        VLOG_DEBUG(__FUNCTION__ " - Cached file list, found %zu files", m_indexToFile.size());
    } catch (const std::exception& e) {
        VLOG_ERROR(__FUNCTION__ " - Error caching file list: %s", e.what());
    }
}

} // namespace VaporCore
