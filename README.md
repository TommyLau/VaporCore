# VaporCore

VaporCore is a comprehensive Steam API emulator that provides a compatible interface for applications that depend on the Steam API. It implements the Steam API with fully functional interfaces, advanced logging, file storage emulation, and multi-version backward compatibility.

## Features

- **Complete Steam API Implementation**: Full implementations of major Steam interfaces with backward compatibility
- **Multi-Architecture Support**: x86 and x64 builds
- **Advanced Logging System**: Configurable debug logging with multiple levels (DEBUG, INFO, WARNING, ERROR)
- **File Storage Emulation**: Local file storage system emulating Steam Cloud
- **Thread-Safe Design**: Meyer's Singleton pattern with proper synchronization
- **Callback Management**: Full Steam callback and call result system
- **Configuration System**: INI-based configuration for customization
- **Multi-Version Support**: Backward compatibility with older Steam SDK versions
- **Debug and Release Builds**: Optimized configurations for development and production
- **Automatic API Generation**: Python-based tools for generating flat API implementations

## Requirements

- **CMake**: 3.20 or higher
- **Compiler**: Visual Studio 2022 with C++ development tools
- **Platform**: Windows 10/11
- **C++ Standard**: C++17 or higher
- **Python**: 3.6 or higher (for API generation tools)

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
- **Final version** format: `MAJOR.MINOR.PATCH.BUILD` (e.g., `0.1.43.93`)
- Use `build.bat no-version` to skip automatic version generation

### Logging
VaporCore uses a sophisticated logging system with multiple levels:
- **INFO**: General operational information and state changes
- **DEBUG**: Detailed function call traces and parameter values
- **WARNING**: Non-critical issues and potential problems
- **ERROR**: Critical errors and failures

Logs are written to `vaporcore_log.txt` by default.

## Project Structure

```
VaporCore/
├── src/
│   ├── steam/                      # Steam API interface implementations
│   │   ├── steam_api_flat.cpp      # Flat API implementations (auto-generated)
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
│       └── vapor_file_storage.cpp  # Local file storage backend
├── include/
│   ├── steam/                      # Steam interface headers
│   │   ├── steam_api_flat.h        # Flat API declarations (auto-generated)
│   │   ├── isteamclient.h          # Steam client interface
│   │   └── ...                     # Other interface headers
│   ├── sdk/                        # Steam SDK versions
│   │   └── [version]/              # SDK files by version number
│   └── vapor/                      # VaporCore system headers
├── scripts/
│   ├── generate_flat_api.py        # Flat API generator script
│   └── ...                         # Other utility scripts
├── build/                          # Build output directory
├── scripts/                        # Build and utility scripts
├── CMakeLists.txt                  # Root CMake configuration
├── vaporcore.example.ini           # Example configuration file
└── README.md                       # This file
```

## Development Tools

### Flat API Generator
The `generate_flat_api.py` script automates the generation of Steam flat API implementations:
- Automatically finds the latest SDK version
- Generates `steam_api_flat.h` and `steam_api_flat.cpp`
- Handles enum types and proper type casting
- Preserves existing implementations when regenerating
- Provides detailed logging of the generation process

Usage:
```bash
python scripts/generate_flat_api.py
```

## API Coverage

VaporCore implements all major Steam interfaces including:

### Core Interfaces
- **ISteamClient**: Main client interface and factory
- **ISteamUser**: User authentication and account management
- **ISteamFriends**: Friends list and social features
- **ISteamUtils**: System utilities and Steam integration
- **ISteamParentalSettings**: Parental control features

### Application & Content
- **ISteamApps**: Application management and DLC
- **ISteamUserStats**: Achievements and statistics
- **ISteamRemoteStorage**: Cloud storage and file management
- **ISteamUGC**: User-generated content
- **ISteamInventory**: Item inventory system

### Multiplayer & Networking
- **ISteamMatchmaking**: Game server browser and lobbies
- **ISteamNetworking**: P2P networking and messaging
- **ISteamGameServer**: Dedicated server functionality

### Additional Features
- **Thread Safety**: Global and per-interface synchronization
- **Singleton Pattern**: Modern C++ singleton implementation
- **Callback System**: Full Steam callback management
- **Multi-Version Support**: SDK version compatibility
- **Local Storage**: File system emulation
- **Configuration**: Flexible INI-based system
