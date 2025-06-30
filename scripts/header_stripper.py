#!/usr/bin/env python3
"""
VaporCore Header File Stripper
Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>

This script strips header files to create versioned interface files.
It extracts the interface version number from the original file and creates
a new file with the version number in the filename.

Usage: python header_stripper.py <input_header_file>
"""

import os
import sys
import re
import argparse
from pathlib import Path


def extract_interface_version(content):
    """
    Extract interface version number from header content.
    Looks for patterns like STEAMAPPS_INTERFACE_VERSION004 or VERSION004.
    """
    # Pattern to match interface version definitions
    patterns = [
        r'#define\s+\w*INTERFACE_VERSION\w*\s+"[^"]*(\d{3})"',  # "VERSION004"
        r'#define\s+\w*INTERFACE_VERSION(\d{3})\s+',             # VERSION003
        r'INTERFACE_VERSION(\d{3})',                             # Direct VERSION003
    ]
    
    for pattern in patterns:
        match = re.search(pattern, content)
        if match:
            return match.group(1)
    
    return None


def get_class_name(content):
    """
    Extract the main class name from the header content.
    """
    # Look for class declarations
    class_pattern = r'class\s+(I\w+)\s*\{'
    match = re.search(class_pattern, content)
    if match:
        return match.group(1)
    
    return None


def remove_enums_from_class(class_content):
    """
    Remove enum definitions from within the class content.
    Handles both C-style and C++ scoped enum definitions.
    """
    # Remove enum definitions with their complete blocks
    # Pattern matches: enum [class] [name] { ... };
    enum_pattern = r'(\s*)enum\s+(?:class\s+)?\w*\s*\{[^{}]*(?:\{[^{}]*\}[^{}]*)*\}\s*;'
    
    # First, handle nested braces in enum definitions
    def remove_enum_blocks(content):
        result = content
        # Keep removing enum blocks until no more are found
        while True:
            # Find enum keyword
            enum_match = re.search(r'(\s*)enum\s+(?:class\s+)?(\w*\s*)\{', result)
            if not enum_match:
                break
            
            start_pos = enum_match.start()
            brace_start = enum_match.end() - 1  # Position of opening brace
            
            # Find matching closing brace
            brace_count = 1
            pos = brace_start + 1
            while pos < len(result) and brace_count > 0:
                if result[pos] == '{':
                    brace_count += 1
                elif result[pos] == '}':
                    brace_count -= 1
                pos += 1
            
            if brace_count == 0:
                # Find the semicolon after the closing brace
                semicolon_pos = pos
                while semicolon_pos < len(result) and result[semicolon_pos] in ' \t\n\r':
                    semicolon_pos += 1
                
                if semicolon_pos < len(result) and result[semicolon_pos] == ';':
                    # Remove the entire enum definition including semicolon
                    result = result[:start_pos] + result[semicolon_pos + 1:]
                else:
                    # No semicolon found, just remove to closing brace
                    result = result[:start_pos] + result[pos:]
            else:
                # Unmatched braces, skip this enum
                break
        
        return result
    
    return remove_enum_blocks(class_content)


def extract_comment_block_above_class(content, class_name):
    """
    Extract the complete comment block that appears directly above the class declaration.
    Returns the entire comment block with original formatting preserved.
    """
    # Find the class declaration first
    class_start = content.find(f'class {class_name}')
    if class_start == -1:
        return None
    
    # Get content before the class
    content_before_class = content[:class_start]
    lines_before = content_before_class.split('\n')
    
    # Work backwards from the class to find the comment block
    comment_lines = []
    found_comment_block = False
    
    # Start from the end and work backwards
    for i in range(len(lines_before) - 1, -1, -1):
        line = lines_before[i]
        line_stripped = line.strip()
        
        # Skip empty lines right before the class
        if not line_stripped and not found_comment_block:
            continue
            
        # Check if this line is part of a comment block
        if (line_stripped.startswith('//') or 
            line_stripped.startswith('*') or 
            line_stripped.startswith('/*') or
            line_stripped.endswith('*/')):
            found_comment_block = True
            comment_lines.insert(0, line)
        else:
            # If we hit a non-comment line, stop
            if found_comment_block:
                break
    
    # Return the original comment block if found
    if comment_lines:
        return '\n'.join(comment_lines)
    
    return None


def strip_header_content(content, original_filename, version_num, class_name):
    """
    Strip header content to create a minimal versioned interface file.
    """
    base_name = Path(original_filename).stem.lower()
    version_filename = f"{base_name}{version_num}.h"
    guard_name = f"{base_name.upper()}{version_num}_H"
    
    # Extract comment block above class from original file
    comment_block = extract_comment_block_above_class(content, class_name)
    
    # Extract class content (from class declaration to the closing brace)
    class_start = content.find(f'class {class_name}')
    if class_start == -1:
        raise ValueError(f"Could not find class {class_name} in the file")
    
    # Find the matching closing brace for the class
    brace_count = 0
    class_end = -1
    in_class = False
    paren_count = 0
    in_string = False
    in_comment = False
    in_line_comment = False
    prev_char = ''
    
    content_from_class = content[class_start:]
    
    for i, char in enumerate(content_from_class):
        actual_pos = class_start + i
        
        # Handle string literals
        if char == '"' and prev_char != '\\' and not in_comment and not in_line_comment:
            in_string = not in_string
        # Handle line comments
        elif char == '/' and prev_char == '/' and not in_string and not in_comment:
            in_line_comment = True
        # Handle block comments start
        elif char == '*' and prev_char == '/' and not in_string and not in_line_comment:
            in_comment = True
        # Handle block comments end
        elif char == '/' and prev_char == '*' and in_comment:
            in_comment = False
        # Handle end of line comments
        elif char == '\n' and in_line_comment:
            in_line_comment = False
        
        # Only count braces and parentheses if we're not in strings or comments
        if not in_string and not in_comment and not in_line_comment:
            if char == '(':
                paren_count += 1
            elif char == ')':
                paren_count -= 1
            elif char == '{' and paren_count == 0:
                brace_count += 1
                in_class = True
            elif char == '}' and in_class and paren_count == 0:
                brace_count -= 1
                if brace_count == 0:
                    class_end = actual_pos + 1
                    break
        
        prev_char = char
    
    if class_end == -1:
        raise ValueError("Could not find the end of the class definition")
    
    # Extract only the class content, no extra structs or other definitions
    class_content = content[class_start:class_end]
    
    # Extract version-specific class name if it exists
    versioned_class_name = f"{class_name}{version_num}"
    
    # Replace class name with versioned one
    class_content = class_content.replace(f'class {class_name}', f'class {versioned_class_name}')
    
    # Replace constructor and destructor names to match the new class name
    # Handle constructors: ClassName() -> VersionedClassName()
    class_content = re.sub(rf'\b{re.escape(class_name)}\s*\(', f'{versioned_class_name}(', class_content)
    
    # Handle destructors: ~ClassName() -> ~VersionedClassName()
    class_content = re.sub(rf'~\s*{re.escape(class_name)}\s*\(', f'~{versioned_class_name}(', class_content)
    
    # Remove enum definitions from within the class scope
    class_content = remove_enums_from_class(class_content)
    
    # Ensure class ends with semicolon
    if not class_content.rstrip().endswith(';'):
        class_content = class_content.rstrip() + ';'
    
    # Extract the version define line and preserve original naming pattern
    version_define_pattern = rf'#define\s+(\w*INTERFACE_VERSION)\w*\s+"([^"]*)"'
    version_define_match = re.search(version_define_pattern, content)
    
    if version_define_match:
        # Use the original pattern but with the new version number and underscore format
        original_base = version_define_match.group(1)  # e.g., "STEAMREMOTESTORAGE_INTERFACE_VERSION"
        original_value = version_define_match.group(2)  # e.g., "STEAMREMOTESTORAGE_INTERFACE_VERSION005"
        
        # Create the versioned define with underscore format
        version_define = f'#define {original_base}_{version_num} "{original_value}"'
    else:
        # Fallback if pattern not found
        version_define = f'#define {base_name.upper()}_INTERFACE_VERSION_{version_num} "{base_name.upper()}_INTERFACE_VERSION{version_num}"'
    
    # Create the stripped content
    if comment_block:
        comment_section = f"{comment_block}\n"
    else:
        comment_section = ""
    
    stripped_content = f'''/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef {guard_name}
#define {guard_name}
#ifdef _WIN32
#pragma once
#endif

{comment_section}{class_content}

{version_define}

#endif // {guard_name}
'''
    
    return stripped_content, version_filename


def find_related_steam_file(interface_name, base_dir):
    """
    Find the related steam implementation file for a given interface.
    For example, ISteamApps -> steam_apps.h (in include/) or steam_apps.cpp (in src/steam/)
    """
    # Remove the 'I' prefix and convert to snake_case
    if interface_name.startswith('ISteam'):
        steam_name = interface_name[6:]  # Remove 'ISteam'
    elif interface_name.startswith('I'):
        steam_name = interface_name[1:]   # Remove 'I'
    else:
        return None
    
    # Convert CamelCase to snake_case properly handling acronyms
    snake_case = ''
    for i, char in enumerate(steam_name):
        if char.isupper() and i > 0:
            # Add underscore before uppercase letter if:
            # 1. Previous character was lowercase, or
            # 2. Next character exists and is lowercase (end of acronym)
            if (steam_name[i-1].islower() or 
                (i < len(steam_name) - 1 and steam_name[i+1].islower())):
                snake_case += '_'
        snake_case += char.lower()
    
    # Try different possible file names in both include/ and src/steam/ directories
    possible_names = [
        f"steam_{snake_case}.h",
        f"steam{steam_name.lower()}.h",
        f"steam_{snake_case}.cpp",
        f"steam{steam_name.lower()}.cpp",
    ]
    
    # Check in include directory first (for header files)
    include_dir = base_dir / "include"
    for name in possible_names:
        if name.endswith('.h'):
            file_path = include_dir / name
            if file_path.exists():
                return file_path
    
    # Check in src/steam directory for implementation files
    src_steam_dir = base_dir / "src" / "steam"
    for name in possible_names:
        if name.endswith('.cpp'):
            file_path = src_steam_dir / name
            if file_path.exists():
                return file_path
    
    return None


def update_steam_implementation_file(steam_file_path, new_include, new_inheritance):
    """
    Update the steam implementation file to include the new header and add inheritance.
    """
    try:
        with open(steam_file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"Error reading steam implementation file: {e}")
        return False
    
    lines = content.split('\n')
    modified = False
    
    # Step 1: Check if include already exists
    include_line = f"#include <{new_include}>"
    include_exists = any(include_line in line for line in lines)
    
    if not include_exists:
        # Find the last include line for isteam*.h
        last_include_idx = -1
        for i, line in enumerate(lines):
            if re.match(r'#include\s*<isteam.*\.h>', line.strip()):
                last_include_idx = i
        
        if last_include_idx != -1:
            # Insert the new include after the last isteam include
            lines.insert(last_include_idx + 1, include_line)
            modified = True
            print(f"Added include: {include_line}")
        else:
            print(f"Warning: Could not find where to insert include for {new_include}")
    
    # Step 2: Check if inheritance already exists
    inheritance_exists = any(new_inheritance in line for line in lines)
    
    if not inheritance_exists:
        # Find the class declaration and its inheritance list
        class_start_idx = -1
        for i, line in enumerate(lines):
            if re.search(r'class\s+\w+\s*:', line.strip()):
                class_start_idx = i
                break
        
        if class_start_idx != -1:
            # Find the end of the inheritance list
            inheritance_end_idx = class_start_idx
            brace_found = False
            
            for i in range(class_start_idx, len(lines)):
                if '{' in lines[i]:
                    inheritance_end_idx = i
                    brace_found = True
                    break
            
            if brace_found:
                # Find the last public inheritance line before the opening brace
                last_inheritance_line = inheritance_end_idx
                for i in range(inheritance_end_idx, class_start_idx - 1, -1):
                    line_content = lines[i].strip()
                    if line_content.startswith('public ') and 'ISteam' in line_content:
                        last_inheritance_line = i
                        break
                
                # Add the new inheritance
                if last_inheritance_line < inheritance_end_idx:
                    # Add comma to the previous line if it doesn't have one
                    if not lines[last_inheritance_line].rstrip().endswith(','):
                        lines[last_inheritance_line] = lines[last_inheritance_line].rstrip() + ','
                    
                    # Insert the new inheritance line
                    lines.insert(last_inheritance_line + 1, f"    {new_inheritance}")
                    modified = True
                    print(f"Added inheritance: {new_inheritance}")
                else:
                    print(f"Warning: Could not find where to insert inheritance for {new_inheritance}")
            else:
                print(f"Warning: Could not find class opening brace")
        else:
            print(f"Warning: Could not find class declaration")
    
    # Write the modified content back to the file
    if modified:
        try:
            with open(steam_file_path, 'w', encoding='utf-8') as f:
                f.write('\n'.join(lines))
            print(f"Successfully updated: {steam_file_path}")
            return True
        except Exception as e:
            print(f"Error writing steam implementation file: {e}")
            return False
    else:
        print(f"No changes needed for: {steam_file_path}")
        return True


def main():
    parser = argparse.ArgumentParser(description='Strip header files to create versioned interface files')
    parser.add_argument('input_file', help='Input header file path')
    
    args = parser.parse_args()
    
    input_path = Path(args.input_file)
    output_dir = input_path.parent  # Output to same directory as input file
    
    if not input_path.exists():
        print(f"Error: Input file '{input_path}' does not exist")
        sys.exit(1)
    
    if not input_path.suffix == '.h':
        print(f"Error: Input file must be a header file (.h)")
        sys.exit(1)
    
    # Read the input file
    try:
        with open(input_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"Error reading file: {e}")
        sys.exit(1)
    
    # Extract version number
    version_num = extract_interface_version(content)
    if not version_num:
        print("Warning: Could not find interface version number in the file")
        print("Looking for patterns like STEAMAPPS_INTERFACE_VERSION004 or similar")
        print("Assuming version 001")
        version_num = "001"
    
    # Extract class name
    class_name = get_class_name(content)
    if not class_name:
        print("Error: Could not find main class declaration in the file")
        sys.exit(1)
    
    print(f"Found interface version: {version_num}")
    print(f"Found class name: {class_name}")
    
    # Strip content and generate new file
    try:
        stripped_content, output_filename = strip_header_content(content, input_path.name, version_num, class_name)
    except Exception as e:
        print(f"Error processing content: {e}")
        sys.exit(1)
    
    # Write output file
    output_path = output_dir / output_filename
    try:
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write(stripped_content)
        
        print(f"Successfully created: {output_path}")
        print(f"Class renamed to: {class_name}{version_num}")
        
    except Exception as e:
        print(f"Error writing output file: {e}")
        sys.exit(1)
    
    # Step 3: Update related steam implementation file
    base_dir = Path(__file__).parent.parent  # Assuming script is in script/ and src/ is parallel
    related_file = find_related_steam_file(class_name, base_dir)
    
    if related_file:
        print(f"Found related steam implementation file: {related_file}")
        
        new_include = output_filename
        new_inheritance = f"public {class_name}{version_num}"
        
        success = update_steam_implementation_file(related_file, new_include, new_inheritance)
        if success:
            print(f"Successfully updated steam implementation file: {related_file}")
        else:
            print(f"Failed to update steam implementation file: {related_file}")
    else:
        print(f"No related steam implementation file found for {class_name}")


if __name__ == '__main__':
    main() 