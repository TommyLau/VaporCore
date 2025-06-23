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
    
    for i, char in enumerate(content[class_start:], class_start):
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
                class_end = i + 1
                break
    
    if class_end == -1:
        raise ValueError("Could not find the end of the class definition")
    
    # Extract only the class content, no extra structs or other definitions
    class_content = content[class_start:class_end]
    
    # Extract version-specific class name if it exists
    versioned_class_name = f"{class_name}{version_num}"
    
    # Replace class name with versioned one
    class_content = class_content.replace(f'class {class_name}', f'class {versioned_class_name}')
    
    # Ensure class ends with semicolon
    if not class_content.rstrip().endswith(';'):
        class_content = class_content.rstrip() + ';'
    
    # Extract the version define line and preserve original naming pattern
    version_define_pattern = rf'#define\s+(\w*INTERFACE_VERSION)\w*\s+"([^"]*)"'
    version_define_match = re.search(version_define_pattern, content)
    
    if version_define_match:
        # Use the original pattern but with the new version number
        original_base = version_define_match.group(1)  # e.g., "STEAMREMOTESTORAGE_INTERFACE_VERSION"
        original_value = version_define_match.group(2)  # e.g., "STEAMREMOTESTORAGE_INTERFACE_VERSION005"
        
        # Create the versioned define with original naming pattern
        version_define = f'#define {original_base}{version_num} "{original_value}"'
    else:
        # Fallback if pattern not found
        version_define = f'#define {base_name.upper()}_INTERFACE_VERSION{version_num} "{base_name.upper()}_INTERFACE_VERSION{version_num}"'
    
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
        print("Error: Could not find interface version number in the file")
        print("Looking for patterns like STEAMAPPS_INTERFACE_VERSION004 or similar")
        sys.exit(1)
    
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


if __name__ == '__main__':
    main() 