# VaporCore Steam API Library

# Collect all source files
file(GLOB_RECURSE VAPORCORE_SOURCES
    "*.cpp"
    "*.cxx"
    "*.cc"
)

file(GLOB_RECURSE VAPORCORE_HEADERS
    "*.h"
    "*.hpp"
    "*.hxx"
)

# Define the main library target
add_library(steam_api SHARED
    ${VAPORCORE_SOURCES}
    ${VAPORCORE_HEADERS}
)

# Set target properties
set_target_properties(steam_api PROPERTIES
    OUTPUT_NAME "steam_api${VAPORCORE_ARCH}"
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
)

# Platform-specific configurations
if(WIN32)
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
    
    # Generate .def file for proper exports
    #set_target_properties(steam_api PROPERTIES
    #    LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/steam_api.def"
    #)
    
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
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include/vaporcore>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
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

target_include_directories(steam_api PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
