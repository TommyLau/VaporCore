# VaporCore

VaporCore is a Steam API emulator that provides a compatible interface for applications that depend on the Steam API.

## Features

- Steam API implementation with stub functions
- Multi-architecture support (x86 and x64)
- Debug and release build configurations
- CMake build system

## Requirements

- **CMake**: 3.20 or higher
- **Compiler**: Visual Studio 2022 with C++ development tools
- **Platform**: Windows 10/11
- **C++ Standard**: C++17 or higher

## Building

### Quick Build
Run the build script:
```batch
build.bat
```

### Manual Build
```batch
# Generate build files
cmake -B build -S . -A x64

# Build all configurations
cmake --build build --config Debug
cmake --build build --config Release
```

### Build Output
- Debug x64: `build/bin/steam_api64.dll`
- Release x64: `build/bin/steam_api64.dll`
- Debug x86: `build/bin/steam_api.dll`
- Release x86: `build/bin/steam_api.dll`

## Usage

### Basic Integration
1. Build the project using `build.bat`
2. Copy the appropriate DLL to your application directory:
   - For 64-bit applications: `steam_api64.dll`
   - For 32-bit applications: `steam_api.dll`
3. Your application can now use Steam API functions normally

### Logging
Enable debug logging by defining `VAPORCORE_ENABLE_LOGGING=1` during compilation. Logs are written to `vaporcore_log.txt`.

## Project Structure

```
VaporCore/
├── src/
│   ├── steam_api.cpp           # Main Steam API exports
│   ├── steam_client.h/.cpp     # ISteamClient implementation
│   ├── vaporcore_base.h/.cpp   # Base utilities and synchronization
│   └── logger.h/.cpp           # Logging system
├── include/sdk/100/            # Steam SDK 100 headers
│   ├── steam_api.h             # Main Steam API header
│   ├── isteamclient.h          # ISteamClient interface
│   └── ...                     # Other Steam interface headers
├── build/                      # Build output directory
├── CMakeLists.txt             # Root CMake configuration
├── src/CMakeLists.txt         # Source CMake configuration
└── README.md                  # This file
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