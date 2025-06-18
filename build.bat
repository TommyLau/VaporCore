@echo off
setlocal enabledelayedexpansion

:: Set build directory
set BUILD_ROOT=%~dp0build
set SOURCE_DIR=%~dp0

:: Parse command line arguments
set BUILD_DEBUG=0
set BUILD_RELEASE=0
set BUILD_X86=0
set BUILD_X64=0
set CLEAN_BUILD=0
set SHOW_HELP=0

if "%1"=="" (
    set BUILD_DEBUG=1
    set BUILD_RELEASE=1
    set BUILD_X86=1
    set BUILD_X64=1
)

:parse_args
if "%1"=="clean" set CLEAN_BUILD=1
if "%1"=="debug" set BUILD_DEBUG=1
if "%1"=="release" set BUILD_RELEASE=1
if "%1"=="x86" set BUILD_X86=1
if "%1"=="x64" set BUILD_X64=1
if "%1"=="help" set SHOW_HELP=1
if "%1"=="-h" set SHOW_HELP=1
if "%1"=="--help" set SHOW_HELP=1
shift
if not "%1"=="" goto parse_args

:: Show help if requested
if %SHOW_HELP%==1 (
    echo VaporCore Steam API Build Script
    echo.
    echo Usage: build.bat [options]
    echo.
    echo Options:
    echo   clean          Clean build directory
    echo   debug          Build debug configurations
    echo   release        Build release configurations
    echo   x86            Build x86 configurations
    echo   x64            Build x64 configurations
    echo   help, -h       Show this help
    echo.
    echo Examples:
    echo   build.bat              Build all configurations
    echo   build.bat clean        Clean build directory
    echo   build.bat debug        Build debug x86 and x64
    echo   build.bat release x64  Build release x64 only
    echo   build.bat x86          Build debug and release x86
    goto :eof
)

:: Clean build directory if requested
if %CLEAN_BUILD%==1 (
    echo Cleaning build directory...
    if exist "%BUILD_ROOT%" (
        rmdir /s /q "%BUILD_ROOT%"
        echo Build directory cleaned.
    ) else (
        echo Build directory does not exist.
    )
    goto :eof
)

:: Determine what to build
if %BUILD_DEBUG%==0 if %BUILD_RELEASE%==0 if %BUILD_X86%==0 if %BUILD_X64%==0 (
    echo No valid build configuration specified. Use 'build.bat help' for usage.
    goto :eof
)

:: If only architecture specified, build both debug and release
if %BUILD_DEBUG%==0 if %BUILD_RELEASE%==0 (
    if %BUILD_X86%==1 (
        set BUILD_DEBUG=1
        set BUILD_RELEASE=1
    )
    if %BUILD_X64%==1 (
        set BUILD_DEBUG=1
        set BUILD_RELEASE=1
    )
)

:: If only config specified, build both architectures
if %BUILD_X86%==0 if %BUILD_X64%==0 (
    if %BUILD_DEBUG%==1 (
        set BUILD_X86=1
        set BUILD_X64=1
    )
    if %BUILD_RELEASE%==1 (
        set BUILD_X86=1
        set BUILD_X64=1
    )
)

echo ====================================================================
echo VaporCore Steam API Build Script
if %BUILD_DEBUG%==1 if %BUILD_RELEASE%==1 (
    echo Building Debug and Release versions
) else (
    if %BUILD_DEBUG%==1 (
        echo Building Debug version
    )
    if %BUILD_RELEASE%==1 (
        echo Building Release version
    )
)
if %BUILD_X86%==1 if %BUILD_X64%==1 (
    echo for x86 and x64 architectures
) else (
    if %BUILD_X86%==1 (
        echo for x86 architecture
    )
    if %BUILD_X64%==1 (
        echo for x64 architecture
    )
)
echo ====================================================================

:: Create build directories
if not exist "%BUILD_ROOT%" mkdir "%BUILD_ROOT%"
if %BUILD_DEBUG%==1 (
    if not exist "%BUILD_ROOT%\debug" mkdir "%BUILD_ROOT%\debug"
)
if %BUILD_RELEASE%==1 (
    if not exist "%BUILD_ROOT%\release" mkdir "%BUILD_ROOT%\release"
)

:: Build configurations based on parameters
if %BUILD_DEBUG%==1 if %BUILD_X86%==1 call :BuildConfiguration "Debug" "Win32" "x86"
if %BUILD_DEBUG%==1 if %BUILD_X64%==1 call :BuildConfiguration "Debug" "x64" "x64"
if %BUILD_RELEASE%==1 if %BUILD_X86%==1 call :BuildConfiguration "Release" "Win32" "x86"
if %BUILD_RELEASE%==1 if %BUILD_X64%==1 call :BuildConfiguration "Release" "x64" "x64"

echo.
echo ====================================================================
echo Build Summary:
echo ====================================================================
if %BUILD_DEBUG%==1 if %BUILD_X86%==1 echo Debug x86:     %BUILD_ROOT%\debug\steam_api.dll
if %BUILD_DEBUG%==1 if %BUILD_X64%==1 echo Debug x64:     %BUILD_ROOT%\debug\steam_api64.dll
if %BUILD_RELEASE%==1 if %BUILD_X86%==1 echo Release x86:   %BUILD_ROOT%\release\steam_api.dll
if %BUILD_RELEASE%==1 if %BUILD_X64%==1 echo Release x64:   %BUILD_ROOT%\release\steam_api64.dll
echo ====================================================================

goto :eof

:BuildConfiguration
set CONFIG_NAME=%~1
set ARCH_CMAKE=%~2
set ARCH_SUFFIX=%~3

set CONFIG_LOWER=%CONFIG_NAME%
if "%CONFIG_NAME%"=="Debug" set CONFIG_LOWER=debug
if "%CONFIG_NAME%"=="Release" set CONFIG_LOWER=release

set BUILD_DIR=%BUILD_ROOT%\intermediate\%CONFIG_NAME%-%ARCH_SUFFIX%
set OUTPUT_DIR=%BUILD_ROOT%\%CONFIG_LOWER%

echo.
echo Building %CONFIG_NAME% %ARCH_SUFFIX%...
echo Build Directory: %BUILD_DIR%
echo Output Directory: %OUTPUT_DIR%

:: Create build directory
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
if not exist "%BUILD_ROOT%\intermediate" mkdir "%BUILD_ROOT%\intermediate"

:: Configure with CMake
echo Configuring...
cmake -S . -B "%BUILD_DIR%" -A %ARCH_CMAKE% -DCMAKE_BUILD_TYPE=%CONFIG_NAME% -DBUILD_SHARED_LIBS=ON -DCMAKE_RUNTIME_OUTPUT_DIRECTORY="%OUTPUT_DIR%" -DCMAKE_LIBRARY_OUTPUT_DIRECTORY="%OUTPUT_DIR%" -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY="%OUTPUT_DIR%"

if errorlevel 1 (
    echo ERROR: CMake configuration failed for %CONFIG_NAME% %ARCH_SUFFIX%
    exit /b 1
)

:: Build with CMake
echo Building...
cmake --build "%BUILD_DIR%" --config %CONFIG_NAME% --parallel

if errorlevel 1 (
    echo ERROR: Build failed for %CONFIG_NAME% %ARCH_SUFFIX%
    exit /b 1
)

:: Copy DLL to final output directory
echo Copying DLL to output directory...
if "%ARCH_SUFFIX%"=="x86" (
    set DLL_NAME=steam_api.dll
) else (
    set DLL_NAME=steam_api64.dll
)
copy "%BUILD_DIR%\bin\%CONFIG_NAME%\!DLL_NAME!" "%OUTPUT_DIR%\!DLL_NAME!" >nul

echo Successfully built %CONFIG_NAME% %ARCH_SUFFIX%

goto :eof 