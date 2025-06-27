# VaporCore

VaporCore is a comprehensive Steam API emulator that provides a compatible interface for applications that depend on the Steam API. It implements the Steam API with fully functional interfaces, advanced logging, file storage emulation, and multi-version backward compatibility.

## Features

- **Complete Steam API Implementation**: Full implementations of major Steam interfaces with backward compatibility
- **Multi-Architecture Support**: x86 and x64 builds
- **Advanced Logging System**: Configurable debug logging with multiple levels
- **File Storage Emulation**: Local file storage system emulating Steam Cloud
- **Thread-Safe Design**: Meyer's Singleton pattern with proper synchronization
- **Callback Management**: Full Steam callback and call result system
- **Configuration System**: INI-based configuration for customization
- **Multi-Version Support**: Backward compatibility with older Steam SDK versions
- **Debug and Release Builds**: Optimized configurations for development and production

## Requirements

- **CMake**: 3.20 or higher
- **Compiler**: Visual Studio 2022 with C++ development tools
- **Platform**: Windows 10/11
- **C++ Standard**: C++11 or higher

## Building

### Quick Build
Run the build script (Windows):
```batch
build.bat
```

### Advanced Build Options
The build script supports selective building with various options:

```batch
# Build specific configurations
build.bat debug           # Build debug x86 and x64
build.bat release         # Build release x86 and x64
build.bat x86             # Build debug and release x86
build.bat x64             # Build debug and release x64

# Combine options
build.bat debug x86       # Build debug x86 only
build.bat release x64     # Build release x64 only

# Additional options
build.bat clean           # Clean build directory
build.bat no-version      # Build without git version update
build.bat help            # Show all available options
```

### Manual CMake Build
```batch
# Generate build files
cmake -B build -S . -A x64

# Build all configurations
cmake --build build --config Debug
cmake --build build --config Release
```

### Build Output
The build script organizes output files by configuration:
- **Debug x86**: `build/debug/steam_api.dll`
- **Debug x64**: `build/debug/steam_api64.dll`
- **Release x86**: `build/release/steam_api.dll`
- **Release x64**: `build/release/steam_api64.dll`

Intermediate build files are stored in `build/intermediate/[Config]-[Arch]/`

## Usage

### Basic Integration
1. Build the project using `build.bat` (or manual CMake commands)
2. Copy the appropriate DLL to your application directory:
   - For 64-bit applications: `build/release/steam_api64.dll`
   - For 32-bit applications: `build/release/steam_api.dll`
   - For debugging: Use files from `build/debug/` instead
3. Your application can now use Steam API functions normally

### Configuration
Copy `vaporcore.example.ini` to `vaporcore.ini` and customize settings:
```ini
[Steam]
# Steam App ID (https://store.steampowered.com/app/<app_id>/)
app_id=480

# Steam ID (leave empty for auto-generation)
steam_id=76561198000000000

# Steam username
username=VaporCore User

# Language code (english, french, german, etc.)
language=english
```

### Versioning
The build script automatically generates version information:
- **Base version** is read from `include/version.h.in`
- **Build number** is automatically generated from Git commit count
- **Final version** format: `MAJOR.MINOR.PATCH.BUILD` (e.g., `0.0.1.123`)
- Use `build.bat no-version` to skip automatic version generation

### Logging
Enable debug logging by defining `VAPORCORE_ENABLE_LOGGING=1` during compilation. Logs are written to `vaporcore_log.txt` with configurable levels:
- **DEBUG**: Detailed function call traces
- **INFO**: General operational information  
- **WARNING**: Non-critical issues
- **ERROR**: Critical errors and failures

## Project Structure

```
VaporCore/
├── src/
│   ├── steam/                      # Steam API interface implementations
│   │   ├── steam_client.cpp        # ISteamClient main coordinator
│   │   ├── steam_user.cpp          # ISteamUser authentication
│   │   ├── steam_friends.cpp       # ISteamFriends social features
│   │   ├── steam_utils.cpp         # ISteamUtils system utilities
│   │   ├── steam_apps.cpp          # ISteamApps application management
│   │   ├── steam_user_stats.cpp    # ISteamUserStats achievements/stats
│   │   ├── steam_matchmaking.cpp   # ISteamMatchmaking multiplayer
│   │   ├── steam_networking.cpp    # ISteamNetworking P2P networking
│   │   ├── steam_remote_storage.cpp # ISteamRemoteStorage cloud saves
│   │   └── ...                     # Other Steam interface implementations
│   └── vapor/                      # VaporCore core systems
│       ├── vapor_base.cpp          # Core utilities and synchronization
│       ├── vapor_logger.cpp        # Advanced logging system
│       ├── vapor_config.cpp        # Configuration management
│       ├── vapor_file_storage.cpp  # Local file storage backend
│       └── steam_callback_mgr.cpp  # Callback management system
├── include/                        # Header files
│   ├── steam_*.h                   # Steam interface declarations
│   ├── vapor_*.h                   # VaporCore system headers
│   └── steam/                      # Steam SDK headers
│       └── *.h                     # Official Steam API headers
├── resources/                      # Build resources
│   └── version.rc                  # Windows version information
├── build/                          # Build output directory
├── scripts/                        # Build and utility scripts
├── CMakeLists.txt                  # Root CMake configuration
├── vaporcore.example.ini           # Example configuration file
└── README.md                       # This file
```

## API Coverage

VaporCore provides comprehensive implementations of major Steam interfaces with full backward compatibility:

### Core Interfaces
- **ISteamClient** (v007-v016): Main client interface and factory
- **ISteamUser** (v009-v018): User authentication and account management
- **ISteamFriends** (v004-v014): Friends list, avatars, and social features
- **ISteamUtils** (v002, v004-v007): System utilities and Steam integration

### Application & Content
- **ISteamApps** (v001-v006): Application management and DLC
- **ISteamUserStats** (v003-v010): Achievements, leaderboards, and statistics
- **ISteamRemoteStorage** (v002, v004-v012): Cloud storage and file management
- **ISteamScreenshots** (v001-v002): Screenshot capture and sharing
- **ISteamUGC** (v001-v007): User-generated content and Workshop
- **ISteamInventory**: Item inventory and trading
- **ISteamVideo**: Video content playback

### Multiplayer & Networking  
- **ISteamMatchmaking** (v002, v004, v006-v008): Game server browser and lobbies
- **ISteamNetworking** (v001-v004): P2P networking and messaging
- **ISteamGameServer** (v004-v011): Dedicated server functionality
- **ISteamGameServerStats**: Server-side statistics
- **ISteamGameCoordinator**: Game coordinator messaging

### Media & Input
- **ISteamMusic**: Music player integration
- **ISteamMusicRemote**: Remote music control
- **ISteamController**: Steam Controller input
- **ISteamHTMLSurface** (v002-latest): HTML rendering for overlays

### Additional Services
- **ISteamHTTP** (v001-latest): HTTP request functionality
- **ISteamUnifiedMessages**: Unified messaging system
- **ISteamAppList**: Application enumeration
- **ISteamAppTicket**: Application ownership verification
- **ISteamMasterServerUpdater**: Legacy master server (deprecated)

### Advanced Features
- **Thread-Safe Architecture**: Global and per-interface synchronization
- **Meyer's Singleton Pattern**: Modern C++ singleton implementation for core systems
- **Callback System**: Full Steam callback and call result management
- **Multi-Version Support**: Automatic interface version detection and compatibility
- **Local Storage Backend**: Complete file system emulation for Steam Cloud
- **Configuration Management**: Flexible INI-based configuration system

All interfaces include comprehensive logging, error handling, and maintain compatibility with games across different Steam SDK versions.
