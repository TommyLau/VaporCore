#!/usr/bin/env python3
"""
VaporCore Flat API Generator
Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>

This script automatically finds the latest SDK version, copies steam_api_flat.h to the include directory,
and generates steam_api_flat.cpp from it.

Usage: python generate_flat_api.py
"""

import os
import re
import sys
import shutil
from pathlib import Path
from typing import List, Dict, Tuple, Optional


class SDKManager:
    def __init__(self, workspace_root: Path):
        self.workspace_root = workspace_root
        self.sdk_dir = workspace_root / "include" / "sdk"
        self.include_dir = workspace_root / "include"
    
    def find_latest_sdk_version(self) -> Optional[Path]:
        """Find the latest SDK version directory"""
        if not self.sdk_dir.exists():
            print(f"❌ SDK directory not found: {self.sdk_dir}")
            print("💡 Please create include/sdk/ directory and place SDK versions there")
            return None
        
        sdk_versions = []
        print(f"🔍 Searching for SDK versions in: {self.sdk_dir}")
        
        # Collect all SDK versions first
        for item in self.sdk_dir.iterdir():
            if item.is_dir():
                # Extract version number from directory name (e.g., "132", "133b", "134a")
                match = re.match(r'^(\d{3})', item.name)
                if match:
                    version_num = int(match.group(1))
                    sdk_versions.append((version_num, item.name, item))
        
        if not sdk_versions:
            print("❌ No SDK versions found in the SDK directory")
            print("💡 Expected directory names like: 132, 133b, 134, etc.")
            return None
        
        # Sort by version number (descending) to get the latest first
        sdk_versions.sort(key=lambda x: x[0], reverse=True)
        
        # Get the latest version (first in sorted list)
        latest_version = sdk_versions[0]
        print(f"✅ Latest SDK version: {latest_version[1]} (numeric: {latest_version[0]})")
        return latest_version[2]
    
    def copy_flat_api_header(self, sdk_path: Path) -> Optional[Path]:
        """Copy steam_api_flat.h from SDK to include directory"""
        source_file = sdk_path / "steam_api_flat.h"
        target_file = self.include_dir / "steam_api_flat.h"
        
        if not source_file.exists():
            print(f"❌ steam_api_flat.h not found in SDK: {source_file}")
            return None
        
        try:
            print(f"📋 Copying {source_file} -> {target_file}")
            shutil.copy2(source_file, target_file)
            print(f"✅ Successfully copied flat API header")
            return target_file
        except Exception as e:
            print(f"❌ Error copying flat API header: {e}")
            return None
    
    def update_from_latest_sdk(self) -> Optional[Path]:
        """Find latest SDK and copy the flat API header"""
        latest_sdk = self.find_latest_sdk_version()
        if not latest_sdk:
            return None
        
        return self.copy_flat_api_header(latest_sdk)


class FunctionSignature:
    def __init__(self, return_type: str, function_name: str, parameters: List[str], full_signature: str):
        self.return_type = return_type.strip()
        self.function_name = function_name.strip()
        self.parameters = parameters
        self.full_signature = full_signature.strip()
        self.interface_name = self._extract_interface_name()
        self.method_name = self._extract_method_name()
    
    def _extract_interface_name(self) -> str:
        """Extract interface name from function name like SteamAPI_ISteamClient_CreateSteamPipe"""
        # Match the interface name which ends after the first underscore following 'ISteam'
        match = re.match(r'SteamAPI_(ISteam\w+?)_', self.function_name)
        return match.group(1) if match else ""
    
    def _extract_method_name(self) -> str:
        """Extract method name from function name"""
        # First extract the interface name, then get everything after it
        interface_name = self._extract_interface_name()
        if interface_name:
            # Remove the SteamAPI_ prefix and interface name, get the rest
            prefix = f"SteamAPI_{interface_name}_"
            if self.function_name.startswith(prefix):
                method_name = self.function_name[len(prefix):]
                
                # Handle overloaded functions: remove trailing numbers (like GetUserStat0 -> GetUserStat)
                # But preserve complex names with numbers inside (like SetPNGIcon_64x64)
                # Pattern: if the method name ends with just digits, remove them
                if re.match(r'^.*\d+$', method_name) and not re.match(r'^.*_\d+x\d+$', method_name):
                    # Remove trailing digits for overloaded functions
                    method_name = re.sub(r'\d+$', '', method_name)
                
                return method_name
        return ""


class FlatAPIGenerator:
    def __init__(self):
        self.functions: List[FunctionSignature] = []
        self.interface_groups: Dict[str, List[FunctionSignature]] = {}
    
    def _fix_original_header_file(self, header_path: str, content: str) -> None:
        """Fix the original header file by removing VR functions and fixing HTML Surface enums"""
        print(f"🔧 Fixing original header file: {header_path}")
        
        # Split content into lines
        lines = content.split('\n')
        fixed_lines = []
        
        # Flag to track if we're in the original header comment block
        in_header_comment = False
        header_comment_replaced = False
        
        for i, line in enumerate(lines):
            # Detect start of original Valve header comment
            if line.strip().startswith('//====== Copyright (c) 1996-2014, Valve Corporation'):
                in_header_comment = True
                if not header_comment_replaced:
                    # Replace with VaporCore header
                    fixed_lines.extend([
                        '/*',
                        ' * VaporCore Steam API Implementation',
                        ' * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>',
                        ' * ',
                        ' * This file is part of VaporCore.',
                        ' * ',
                        ' * Author: Tommy Lau <tommy.lhg@gmail.com>',
                        ' */'
                    ])
                    header_comment_replaced = True
                continue
            
            # Detect end of original header comment block
            if in_header_comment and line.strip() == '//=============================================================================':
                in_header_comment = False
                continue
            
            # Skip lines that are part of the original header comment
            if in_header_comment:
                continue
            
            # Skip VR function declarations
            if line.strip().startswith('S_API') and 'SteamAPI_vr_' in line:
                continue
            
            # Fix HTML Surface enum references
            if 'ISteamHTMLSurface::EHTMLMouseButton' in line:
                line = line.replace('ISteamHTMLSurface::EHTMLMouseButton', 'EHTMLMouseButton')
            if 'ISteamHTMLSurface::EHTMLKeyModifiers' in line:
                line = line.replace('ISteamHTMLSurface::EHTMLKeyModifiers', 'EHTMLKeyModifiers')
            if 'ISteamHTMLSurface::EMouseCursor' in line:
                line = line.replace('ISteamHTMLSurface::EMouseCursor', 'EMouseCursor')
            
            fixed_lines.append(line)
        
        # Write the fixed content back to the file
        fixed_content = '\n'.join(fixed_lines)
        with open(header_path, 'w', encoding='utf-8') as f:
            f.write(fixed_content)
        
        print(f"✅ Fixed header file - replaced header comment, removed VR functions and fixed HTML Surface enums")
    
    def parse_header_file(self, header_path: str) -> None:
        """Parse the header file and extract function signatures"""
        print(f"📖 Parsing header file: {header_path}")
        
        with open(header_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # First, fix the original header file
        self._fix_original_header_file(header_path, content)
        
        # Remove comments and preprocessor directives for parsing
        content = re.sub(r'//.*$', '', content, flags=re.MULTILINE)
        content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
        content = re.sub(r'^\s*#.*$', '', content, flags=re.MULTILINE)
        
        # Fix global enum references that shouldn't have interface scope prefix
        content = content.replace('ISteamHTMLSurface::EHTMLMouseButton', 'EHTMLMouseButton')
        content = content.replace('ISteamHTMLSurface::EHTMLKeyModifiers', 'EHTMLKeyModifiers')
        content = content.replace('ISteamHTMLSurface::EMouseCursor', 'EMouseCursor')
        
        # Find all function declarations
        # Pattern matches: S_API return_type function_name(parameters);
        pattern = r'S_API\s+([^(]+?)\s+(\w+)\s*\(([^)]*)\)\s*;'
        matches = re.findall(pattern, content, re.MULTILINE | re.DOTALL)
        
        for match in matches:
            return_type, function_name, params_str = match
            
            # Skip SteamAPI_vr_ functions entirely
            if function_name.startswith('SteamAPI_vr_'):
                continue
            
            # Clean up parameters
            parameters = []
            if params_str.strip():
                param_parts = params_str.split(',')
                for param in param_parts:
                    param = param.strip()
                    if param and param != 'void':
                        parameters.append(param)
            
            full_signature = f"S_API {return_type} {function_name}({params_str})"
            func_sig = FunctionSignature(return_type, function_name, parameters, full_signature)
            
            if func_sig.interface_name:  # Only include Steam API functions
                self.functions.append(func_sig)
                
                if func_sig.interface_name not in self.interface_groups:
                    self.interface_groups[func_sig.interface_name] = []
                self.interface_groups[func_sig.interface_name].append(func_sig)
        
        print(f"✅ Found {len(self.functions)} Steam API functions across {len(self.interface_groups)} interfaces")
    
    def _get_default_return_value(self, return_type: str) -> str:
        """Get appropriate default return value for the given type"""
        return_type = return_type.strip()
        
        # Handle pointer types
        if '*' in return_type:
            return 'nullptr'
        
        # Handle struct return types
        if 'struct ' in return_type:
            return '{}'
        
        # Handle controller handle types (uint64 typedefs)
        if any(handle in return_type for handle in ['ControllerActionSetHandle_t', 'ControllerDigitalActionHandle_t', 
                                                   'ControllerAnalogActionHandle_t', 'ControllerHandle_t']):
            return '0'
        
        # Handle other specific handle types that have special invalid values
        if 'ScreenshotHandle' in return_type:
            return 'INVALID_SCREENSHOT_HANDLE'
        elif 'HServerListRequest' in return_type:
            return 'nullptr'
        elif 'HServerQuery' in return_type:
            return 'HSERVERQUERY_INVALID'
        elif 'SListenSocket_t' in return_type:
            return 'INVALID_LISTEN_SOCKET'
        elif 'SNetSocket_t' in return_type:
            return '0'
        elif 'UGCHandle_t' in return_type:
            return 'k_UGCHandleInvalid'
        elif 'UGCFileWriteStreamHandle_t' in return_type:
            return 'k_UGCFileStreamHandleInvalid'
        elif 'PublishedFileUpdateHandle_t' in return_type:
            return 'k_PublishedFileUpdateHandleInvalid'
        elif 'HTTPRequestHandle' in return_type:
            return 'INVALID_HTTPREQUEST_HANDLE'
        elif 'HTTPCookieContainerHandle' in return_type:
            return 'INVALID_HTTPCOOKIE_HANDLE'
        elif 'ClientUnifiedMessageHandle' in return_type:
            return 'ISteamUnifiedMessages::k_InvalidUnifiedMessageHandle'
        elif 'UGCQueryHandle_t' in return_type:
            return 'k_UGCQueryHandleInvalid'
        elif 'UGCUpdateHandle_t' in return_type:
            return 'k_UGCUpdateHandleInvalid'
        elif 'Handle' in return_type:
            # Generic fallback for other handle types
            return '0'
        
        # Handle Steam API call types
        if 'SteamAPICall_t' in return_type:
            return 'k_uAPICallInvalid'
        
        # Handle specific enum types
        type_defaults = {
            'EUniverse': 'k_EUniverseInvalid',
            'ESteamAPICallFailure': 'k_ESteamAPICallFailureNone',
            'EPersonaState': 'k_EPersonaStateOffline',
            'EFriendRelationship': 'k_EFriendRelationshipNone',
            'ERemoteStoragePlatform': 'k_ERemoteStoragePlatformNone',
            'ESNetSocketConnectionType': 'k_ESNetSocketConnectionTypeNotConnected',
            'EUserHasLicenseForAppResult': 'k_EUserHasLicenseResultHasLicense',
            'EVoiceResult': 'k_EVoiceResultNotInitialized',
            'EBeginAuthSessionResult': 'k_EBeginAuthSessionResultInvalidTicket',
            'ELeaderboardSortMethod': 'k_ELeaderboardSortMethodNone',
            'ELeaderboardDisplayType': 'k_ELeaderboardDisplayTypeNone',
            'AudioPlayback_Status': 'AudioPlayback_Idle',
            'EItemUpdateStatus': 'k_EItemUpdateStatusInvalid',
            'EResult': 'k_EResultFail'
        }
        
        for enum_type, default_val in type_defaults.items():
            if enum_type in return_type:
                return default_val
        
        # Handle basic types
        if return_type == 'void':
            return ''
        elif 'bool' in return_type:
            return 'false'
        elif any(t in return_type for t in ['int', 'uint', 'HSteamUser', 'HSteamPipe', 'HAuthTicket']):
            return '0'
        elif 'float' in return_type:
            return '0.0f'
        elif 'double' in return_type:
            return '0.0'
        elif 'uint64' in return_type:
            return '0'
        elif 'const char' in return_type or 'char *' in return_type:
            return '""'
        else:
            return '0'  # Default fallback
    
    def _generate_function_call(self, func: FunctionSignature) -> str:
        """Generate the actual function call to the Steam interface"""
        if not func.method_name:
            return f"// TODO: Implement {func.function_name}"
        
        # Handle special case for DestructISteamHTMLSurface - method doesn't exist in interface
        if func.method_name == 'DestructISteamHTMLSurface':
            return f"// reinterpret_cast<{func.interface_name}*>(instancePtr)->{func.method_name}();"
        
        # Extract parameter names for the call, handling global enum types
        param_names = []
        for param in func.parameters[1:]:  # Skip instancePtr
            # Extract parameter name (last word before any array brackets or default values)
            param_clean = re.sub(r'\s*=\s*[^,]*', '', param)  # Remove default values
            param_clean = re.sub(r'\[.*?\]', '', param_clean)  # Remove array brackets
            
            # Handle global enum types that shouldn't have interface scope prefix
            # Remove ISteamHTMLSurface:: prefix for certain enum types that are now global
            if 'ISteamHTMLSurface::EHTMLMouseButton' in param_clean:
                param_clean = param_clean.replace('ISteamHTMLSurface::EHTMLMouseButton', 'EHTMLMouseButton')
            elif 'ISteamHTMLSurface::EHTMLKeyModifiers' in param_clean:
                param_clean = param_clean.replace('ISteamHTMLSurface::EHTMLKeyModifiers', 'EHTMLKeyModifiers')
            elif 'ISteamHTMLSurface::EMouseCursor' in param_clean:
                param_clean = param_clean.replace('ISteamHTMLSurface::EMouseCursor', 'EMouseCursor')
            
            words = param_clean.split()
            if words:
                param_name = words[-1].lstrip('*&')  # Remove pointer/reference symbols
                param_names.append(param_name)
        
        call_params = ', '.join(param_names)
        
        # Generate the return statement
        if func.return_type.strip() == 'void':
            return f"reinterpret_cast<{func.interface_name}*>(instancePtr)->{func.method_name}({call_params});"
        else:
            base_call = f"reinterpret_cast<{func.interface_name}*>(instancePtr)->{func.method_name}({call_params})"
            
            # Handle CSteamID to uint64 conversion
            if func.return_type.strip() == 'uint64':
                # Functions that likely return CSteamID but should return uint64
                if any(name in func.function_name for name in ['GetSteamID', 'GetFriendByIndex', 'GetClanByIndex', 
                                                              'GetFriendFromSourceByIndex', 'GetClanOwner', 
                                                              'GetClanOfficerByIndex', 'GetCoplayFriend', 
                                                              'GetChatMemberByIndex', 'GetLobbyByIndex',
                                                              'GetLobbyMemberByIndex', 'GetLobbyOwner', 
                                                              'GetAppOwner', 'CreateUnauthenticatedUserConnection']):
                    return f"return {base_call}.ConvertToUint64();"
            
            return f"return {base_call};"
    
    def _generate_function_implementation(self, func: FunctionSignature) -> str:
        """Generate the complete function implementation"""
        lines = []
        
        # Function signature
        lines.append(func.full_signature.replace(';', ''))
        lines.append('{')
        
        # Debug log
        lines.append(f'    VLOG_DEBUG("{func.function_name} called");')
        
        # Null check for instancePtr
        default_return = self._get_default_return_value(func.return_type)
        if func.return_type.strip() == 'void':
            lines.append('    if (!instancePtr) return;')
        else:
            lines.append(f'    if (!instancePtr) return {default_return};')
        
        # Function call
        call_line = '    ' + self._generate_function_call(func)
        lines.append(call_line)
        
        lines.append('}')
        
        return '\n'.join(lines)
    
    def generate_cpp_file(self, output_path: str) -> None:
        """Generate the complete cpp file"""
        print(f"🚀 Generating implementation file: {output_path}")
        
        lines = []
        
        # File header
        lines.extend([
            '/*',
            ' * VaporCore Steam API Implementation',
            ' * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>',
            ' * ',
            ' * This file is part of VaporCore.',
            ' * ',
            ' * Author: Tommy Lau <tommy.lhg@gmail.com>',
            ' */',
            '',
            '#include <steam_api.h>',
            '#include <steam_api_flat.h>',
            '#include <steam_gameserver.h>',
            '#include <steam_game_server_stats.h>',
            '',
            '#include "logger.h"',
            ''
        ])
        
        # Generate implementations in the exact order they appear in the header file
        current_interface = None
        for func in self.functions:
            # Add interface header when we encounter a new interface
            if func.interface_name != current_interface:
                if current_interface is not None:
                    lines.append('')  # Add blank line between interfaces
                
                lines.extend([
                    '//-----------------------------------------------------------------------------',
                    f'// {func.interface_name} flat API implementations',
                    '//-----------------------------------------------------------------------------',
                    ''
                ])
                current_interface = func.interface_name
            
            implementation = self._generate_function_implementation(func)
            lines.append(implementation)
            lines.append('')
        
        # Write to file
        content = '\n'.join(lines)
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"✅ Successfully generated {len(self.functions)} function implementations")


def main():
    print("🚀 VaporCore Flat API Generator")
    print("=" * 50)
    
    # Get workspace root directory
    workspace_root = Path(__file__).parent.parent
    
    # Auto-detect latest SDK and copy header
    print("🔍 Searching for latest SDK version...")
    sdk_manager = SDKManager(workspace_root)
    header_path = sdk_manager.update_from_latest_sdk()
    
    if not header_path:
        print("❌ Failed to find or copy header from latest SDK")
        print("💡 Please ensure include/sdk/ directory exists with SDK versions like 132, 133b, 134, etc.")
        return 1
    
    # Always output to src directory
    src_dir = workspace_root / "src"
    output_path = src_dir / 'steam_api_flat.cpp'
    
    try:
        generator = FlatAPIGenerator()
        generator.parse_header_file(str(header_path))
        generator.generate_cpp_file(output_path)
        
        print(f"\n🎉 Successfully generated flat API implementation!")
        print(f"📁 Header file: {header_path}")
        print(f"📁 Output file: {output_path}")
        print(f"📊 Functions generated: {len(generator.functions)}")
        print(f"🔌 Interfaces covered: {len(generator.interface_groups)}")
        
        return 0
        
    except Exception as e:
        print(f"❌ Error generating flat API: {e}")
        import traceback
        traceback.print_exc()
        return 1


if __name__ == '__main__':
    sys.exit(main()) 