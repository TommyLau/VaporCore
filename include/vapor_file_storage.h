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

#ifndef VAPORCORE_FILE_STORAGE_H
#define VAPORCORE_FILE_STORAGE_H
#ifdef _WIN32
#pragma once
#endif

#include <string>
#include <map>
#include <vector>
#include <steam_api.h>

namespace VaporCore {

class FileStorage {
private:
    // Storage configuration
    std::string m_storageDirectory;
    
    // File indexing for GetFileNameAndSize() - populated by GetFileCount()
    std::vector<std::string> m_indexToFile;
    
    // Internal helper methods
    std::string GetFullPath(const std::string& filename) const;
    std::string NormalizeFilename(const std::string& filename) const;
    void CacheFileList();
    
public:
    FileStorage(const std::string& storageDir = "./vaporcore_save");
    ~FileStorage();
    
    // File operations
    bool WriteFile(const std::string& filename, const void* data, size_t size);
    int32 ReadFile(const std::string& filename, void* buffer, size_t maxSize);
    bool FileExists(const std::string& filename);
    bool DeleteFile(const std::string& filename);
    size_t GetFileSize(const std::string& filename);
    int64 GetFileTimestamp(const std::string& filename);
    
    // Enumeration
    int32 GetFileCount();
    std::string GetFileNameAndSize(int index, int32* pSize = nullptr);
    
    // Utility
    bool EnsureDirectoryExists();
    bool IsValidFilename(const std::string& filename) const;
    
    // Storage statistics
    size_t GetTotalStorageUsed();
    bool GetQuota(int32* pnTotalBytes, int32* pnAvailableBytes);
};

} // namespace VaporCore

#endif // VAPORCORE_FILE_STORAGE_H
