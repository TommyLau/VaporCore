cmake_minimum_required(VERSION 3.20)

# Project definition
project(VaporCore
    VERSION 0.0.1
    DESCRIPTION "Yet another Steam API Emulator"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build configuration options
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(ENABLE_LOGGING "Enable debug logging" ON)

# Platform detection
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VAPORCORE_PLATFORM "x64")
    set(VAPORCORE_ARCH "64")
else()
    set(VAPORCORE_PLATFORM "x86")
    set(VAPORCORE_ARCH "")
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compiler-specific settings
if(MSVC)
    # Visual Studio specific settings
    add_compile_options(/W4 /WX- /permissive-)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    
    # Multi-processor compilation
    add_compile_options(/MP)
    
    # Debug information format
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/ZI)
    else()
        add_compile_options(/Zi)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang specific settings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Build configuration
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(VAPORCORE_DEBUG=1)
    if(ENABLE_LOGGING)
        add_compile_definitions(VAPORCORE_ENABLE_LOGGING=1)
    endif()
else()
    add_compile_definitions(VAPORCORE_RELEASE=1)
    add_compile_definitions(NDEBUG)
endif()

# Global include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vapor
    ${CMAKE_CURRENT_SOURCE_DIR}/src/steam
)

# Collect all source files from src directory and subdirectories
file(GLOB_RECURSE VAPORCORE_SOURCES
    "src/vapor/*.cpp"
    "src/steam/*.cpp"
)

# Add Windows resource file
if(WIN32)
    set(VAPORCORE_RESOURCES
        resources/version.rc
    )
endif()

# Define the main library target
add_library(steam_api SHARED
    ${VAPORCORE_SOURCES}
    ${VAPORCORE_RESOURCES}
)

# Set target properties
set_target_properties(steam_api PROPERTIES
    OUTPUT_NAME "steam_api${VAPORCORE_ARCH}"
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
)

# Platform-specific configurations
if(WIN32)
    # Enable resource compiler
    enable_language(RC)
    
    # Windows-specific settings
    set_target_properties(steam_api PROPERTIES
        SUFFIX ".dll"
    )
    
    # Export definitions
    target_compile_definitions(steam_api PRIVATE
        STEAM_API_EXPORTS
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )
    
    # Link against Windows libraries
    target_link_libraries(steam_api PRIVATE
        kernel32
        user32
        advapi32
        shell32
        ws2_32
        winmm
    )
    
elseif(UNIX)
    # Unix-specific settings
    set_target_properties(steam_api PROPERTIES
        PREFIX "lib"
        SUFFIX ".so"
    )
    
    target_compile_definitions(steam_api PRIVATE
        VAPORCORE_EXPORTS
    )
    
    # Link against system libraries
    target_link_libraries(steam_api PRIVATE
        dl
        pthread
    )
endif()

# Include directories
target_include_directories(steam_api
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/steam>
        $<INSTALL_INTERFACE:include/vaporcore>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vapor
        ${CMAKE_CURRENT_SOURCE_DIR}/src/steam
)

# Compiler-specific optimizations
if(MSVC)
    target_compile_options(steam_api PRIVATE
        $<$<CONFIG:Release>:/O2 /Ob2 /DNDEBUG>
        $<$<CONFIG:Debug>:/Od /Zi>
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(steam_api PRIVATE
        $<$<CONFIG:Release>:-O3 -DNDEBUG>
        $<$<CONFIG:Debug>:-O0 -g>
    )
endif()
 