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
)

# Add subdirectories
add_subdirectory(src)

install(TARGETS steam_api
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vaporcore
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

# Package configuration
set(CPACK_PACKAGE_NAME "VaporCore")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VENDOR "VaporCore Project")

include(CPack) 