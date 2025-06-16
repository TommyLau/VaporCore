# VaporCore

VaporCore is a Steam API emulator that provides a compatible interface for applications that depend on the Steam API.

## Features

- Steam API implementation with stub functions
- Multi-architecture support (x86 and x64)
- Debug and release build configurations
- CMake build system

## Requirements

- CMake 3.20 or higher
- Visual Studio 2022 with C++ development tools
- Windows 10/11

## Building

Run the build script:

```batch
build.bat
```

This builds all configurations:
- Debug x86: `build/debug/steam_api.dll`
- Debug x64: `build/debug/steam_api64.dll`
- Release x86: `build/release/steam_api.dll`
- Release x64: `build/release/steam_api64.dll`

## Usage

1. Build the project using `build.bat`
2. Copy the appropriate DLL to your application directory

## Project Structure

```
VaporCore/
├── src/                    # Source files
├── include/sdk/100/        # Steam SDK headers
├── build/                  # Build output
├── build.bat              # Build script
└── CMakeLists.txt         # CMake configuration
```

## API Coverage

Current implementation includes stub functions for:
- ISteamClient
- ISteamUser
- ISteamFriends
- ISteamUtils
- ISteamMatchmaking
- ISteamUserStats
- ISteamApps
- ISteamNetworking 