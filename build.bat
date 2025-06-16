@echo off
setlocal enabledelayedexpansion

echo ====================================================================
echo VaporCore Steam API Build Script
echo Building Debug and Release versions for x86 and x64 architectures
echo ====================================================================

:: Set build directory
set BUILD_ROOT=%~dp0build
set SOURCE_DIR=%~dp0

:: Create build directories
if not exist "%BUILD_ROOT%" mkdir "%BUILD_ROOT%"
if not exist "%BUILD_ROOT%\debug" mkdir "%BUILD_ROOT%\debug"
if not exist "%BUILD_ROOT%\release" mkdir "%BUILD_ROOT%\release"

:: Function to build specific configuration
call :BuildConfiguration "Debug" "Win32" "x86"
call :BuildConfiguration "Debug" "x64" "x64"
call :BuildConfiguration "Release" "Win32" "x86"
call :BuildConfiguration "Release" "x64" "x64"

echo.
echo ====================================================================
echo Build Summary:
echo ====================================================================
echo Debug x86:     %BUILD_ROOT%\debug\steam_api.dll
echo Debug x64:     %BUILD_ROOT%\debug\steam_api64.dll
echo Release x86:   %BUILD_ROOT%\release\steam_api.dll
echo Release x64:   %BUILD_ROOT%\release\steam_api64.dll
echo ====================================================================

pause
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