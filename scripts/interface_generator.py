#!/usr/bin/env python3
"""
VaporCore Interface Implementation Generator

This script generates implementation header (.h) and source (.cpp) files 
from Steam interface header files.

Author: Tommy Lau <tommy.lhg@gmail.com>
"""

import argparse
import os
import re
import sys
from pathlib import Path


class InterfaceGenerator:
    def __init__(self, interface_file, output_dir):
        self.interface_file = Path(interface_file)
        self.output_dir = Path(output_dir)
        self.interface_name = ""
        self.class_name = ""
        self.file_base_name = ""
        self.header_guard = ""
        self.include_name = ""
        self.methods = []
        self.purpose_comment = ""
        
    def extract_interface_info(self, content):
        """Extract interface name and methods from the header content"""
        
        # Find interface class definition
        interface_match = re.search(r'class\s+(\w+)\s*\{', content)
        if not interface_match:
            raise ValueError("Could not find interface class definition")
        
        self.interface_name = interface_match.group(1)
        
        # Generate class name (e.g., ISteamVideo -> Steam_Video)
        if self.interface_name.startswith('I'):
            name_part = self.interface_name[1:]  # Remove 'I' prefix
        else:
            name_part = self.interface_name
            
        # Convert CamelCase to Snake_Case
        self.class_name = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', name_part)
        
        # Generate file base name (e.g., Steam_Video -> steam_video)
        self.file_base_name = self.class_name.lower()
        
        # Generate header guard
        self.header_guard = f"VAPORCORE_{self.class_name.upper()}_H"
        
        # Generate include name (e.g., ISteamVideo -> isteamvideo.h)
        self.include_name = self.interface_name.lower() + ".h"
        
        # Extract purpose comment using the same method as header_stripper.py
        self.purpose_comment = self._extract_comment_block_above_class(content, self.interface_name)
        
        # Extract methods
        self._extract_methods(content)
        
    def _extract_comment_block_above_class(self, content, class_name):
        """
        Extract the complete comment block that appears directly above the class declaration.
        Returns the entire comment block with original formatting preserved (copied from header_stripper.py).
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
        
    def _extract_methods(self, content):
        """Extract virtual methods from the interface"""
        
        # Find the class body
        class_start = content.find(f'class {self.interface_name}')
        if class_start == -1:
            return
            
        # Find the opening brace
        brace_start = content.find('{', class_start)
        if brace_start == -1:
            return
            
        # Find the matching closing brace
        brace_count = 0
        pos = brace_start
        in_string = False
        in_comment = False
        in_line_comment = False
        
        while pos < len(content):
            char = content[pos]
            
            # Handle line comments
            if not in_string and not in_comment and pos < len(content) - 1 and content[pos:pos+2] == '//':
                in_line_comment = True
                pos += 2
                continue
            elif in_line_comment and char == '\n':
                in_line_comment = False
                pos += 1
                continue
            elif in_line_comment:
                pos += 1
                continue
                
            # Handle block comments
            if not in_string and not in_line_comment and pos < len(content) - 1 and content[pos:pos+2] == '/*':
                in_comment = True
                pos += 2
                continue
            elif in_comment and pos < len(content) - 1 and content[pos:pos+2] == '*/':
                in_comment = False
                pos += 2
                continue
            elif in_comment:
                pos += 1
                continue
                
            # Handle strings
            if not in_comment and not in_line_comment and char == '"' and (pos == 0 or content[pos-1] != '\\'):
                in_string = not in_string
                pos += 1
                continue
            elif in_string:
                pos += 1
                continue
                
            # Count braces
            if char == '{':
                brace_count += 1
            elif char == '}':
                brace_count -= 1
                if brace_count == 0:
                    break
                    
            pos += 1
            
        if brace_count != 0:
            raise ValueError("Could not find the end of the class definition")
            
        class_body = content[brace_start+1:pos]
        
                # Extract virtual methods with their comments
        self._extract_methods_with_comments(class_body)
        
    def _extract_methods_with_comments(self, class_body):
        """Extract virtual methods along with their associated comments"""
        
        lines = class_body.split('\n')
        current_comment_block = []
        i = 0
        
        while i < len(lines):
            line = lines[i]
            stripped = line.strip()
            
            # Skip empty lines but preserve them in comment blocks if we're collecting
            if not stripped:
                current_comment_block.append(line)
                i += 1
                continue
            
            # Collect all non-method content (comments, METHOD_DESC, section headers, etc.)
            # But skip access specifiers which don't belong in implementation files
            if not stripped.startswith('virtual'):
                # Skip only access specifier lines, but keep all other content
                if stripped not in ['public:', 'private:', 'protected:']:
                    current_comment_block.append(line)
                i += 1
                continue
            
            # Found a virtual method - collect the complete declaration
            method_lines = []
            j = i
            
            # Continue collecting lines until we find '= 0;'
            while j < len(lines):
                method_lines.append(lines[j])
                if '= 0' in lines[j] and ';' in lines[j]:
                    break
                j += 1
            
            if j < len(lines):  # We found a complete method
                # Join all method lines for parsing
                full_method_text = ' '.join(line.strip() for line in method_lines)
                
                # Parse the method signature
                virtual_match = re.search(r'virtual\s+(.+?)\s*=\s*0\s*;', full_method_text)
                if virtual_match:
                    method_signature = virtual_match.group(1).strip()
                    
                    # Find the opening parenthesis to separate return type + method name from parameters
                    paren_pos = method_signature.find('(')
                    if paren_pos != -1:
                        # Split into method declaration and parameters
                        method_decl = method_signature[:paren_pos].strip()
                        
                        # Split method declaration into return type and method name
                        parts = method_decl.split()
                        if len(parts) >= 2:
                            return_type = ' '.join(parts[:-1])
                            method_name = parts[-1]
                            
                            # Reconstruct the method signature preserving multi-line formatting
                            formatted_signature = self._format_method_signature(method_lines, return_type, method_name)
                            
                            # Look ahead for any trailing blank lines after this method
                            trailing_blank_lines = []
                            k = j + 1
                            while k < len(lines) and not lines[k].strip():
                                trailing_blank_lines.append(lines[k])
                                k += 1
                            
                            # Store method with comments and trailing blanks
                            method_info = {
                                'return_type': return_type,
                                'name': method_name,
                                'params': method_signature[paren_pos:],
                                'full_signature': formatted_signature,
                                'preceding_comments': current_comment_block.copy() if current_comment_block else [],
                                'trailing_blank_lines': trailing_blank_lines.copy(),
                                'inline_comment': "",
                                'original_method_lines': method_lines.copy()
                            }
                            
                            self.methods.append(method_info)
                
                # Move past this method and any trailing blank lines, then reset comment collection
                k = j + 1
                while k < len(lines) and not lines[k].strip():
                    k += 1
                i = k
                current_comment_block = []
            else:
                # Incomplete method, skip this line
                i += 1
    
    def _format_method_signature(self, method_lines, return_type, method_name):
        """Format method signature preserving multi-line indentation style"""
        
        # If it's a single line method, return simple format
        if len(method_lines) == 1:
            # Extract parameters from the single line
            line = method_lines[0].strip()
            
            # Find the method parameters by finding the opening parenthesis after the method name
            # and then counting parentheses to find the matching closing one
            virtual_pos = line.find('virtual')
            if virtual_pos == -1:
                return f"{return_type} {method_name}()"
            
            # Find the opening parenthesis
            paren_start = line.find('(', virtual_pos)
            if paren_start == -1:
                return f"{return_type} {method_name}()"
                
            # Find the matching closing parenthesis before '= 0;'
            paren_count = 0
            paren_end = -1
            for i in range(paren_start, len(line)):
                if line[i] == '(':
                    paren_count += 1
                elif line[i] == ')':
                    paren_count -= 1
                    if paren_count == 0:
                        paren_end = i
                        break
            
            if paren_end != -1:
                params = line[paren_start:paren_end+1]
                return f"{return_type} {method_name}{params}"
            else:
                return f"{return_type} {method_name}()"
        
        # Handle multi-line methods
        # First, reconstruct the full method text and extract just the parameters part
        full_text = ' '.join(method_lines)
        
        # Find the parameters section
        paren_start = full_text.find('(')
        if paren_start == -1:
            return f"{return_type} {method_name}()"
        
        # Find the closing parenthesis before '= 0'
        paren_count = 0
        paren_end = -1
        for i in range(paren_start, len(full_text)):
            if full_text[i] == '(':
                paren_count += 1
            elif full_text[i] == ')':
                paren_count -= 1
                if paren_count == 0:
                    paren_end = i
                    break
        
        if paren_end == -1:
            return f"{return_type} {method_name}()"
        
        # Extract the parameters text
        params_text = full_text[paren_start:paren_end+1]
        
        # Now reconstruct with proper formatting by using the original line structure
        # but with the correctly parsed parameters
        base_indent = "\t"
        
        # Split the parameters by commas but preserve the structure
        if params_text == "()":
            return f"{base_indent}{return_type} {method_name}()"
        
        # For multi-line methods, we need to preserve the original line breaks
        # Find where the original method broke lines and apply the same breaks to our formatted version
        formatted_lines = []
        
        # Start with the method declaration
        first_line = method_lines[0].strip()
        paren_pos = first_line.find('(')
        if paren_pos != -1:
            after_paren = first_line[paren_pos+1:]
            if after_paren.strip():  # First line has parameters after opening paren
                formatted_lines.append(f"{base_indent}{return_type} {method_name}({after_paren}")
            else:  # Opening paren is at end of first line
                formatted_lines.append(f"{base_indent}{return_type} {method_name}(")
        
        # Process middle lines (continuation lines)
        for i in range(1, len(method_lines) - 1):
            line = method_lines[i].strip()
            # Calculate indentation to align with opening parenthesis + 1
            base_indent_expanded = base_indent.expandtabs(4)
            first_line_prefix = f"{base_indent_expanded}{return_type} {method_name}("
            continuation_indent = " " * (len(first_line_prefix) + 1)
            formatted_lines.append(f"{continuation_indent}{line}")
        
        # Process the last line - remove only the final ") = 0;" and add " ) override;"
        if len(method_lines) > 1:
            last_line = method_lines[-1].strip()
            # Remove " = 0;" from the end, but preserve the rest
            if last_line.endswith(' = 0;'):
                clean_last = last_line[:-5]  # Remove " = 0;"
                # Remove only the final closing parenthesis
                if clean_last.endswith(' )'):
                    clean_last = clean_last[:-2]  # Remove " )"
                elif clean_last.endswith(')'):
                    clean_last = clean_last[:-1]  # Remove ")"
                
                base_indent_expanded = base_indent.expandtabs(4)
                first_line_prefix = f"{base_indent_expanded}{return_type} {method_name}("
                continuation_indent = " " * (len(first_line_prefix) + 1)
                
                if clean_last.strip():
                    formatted_lines.append(f"{continuation_indent}{clean_last} ) override;")
                else:
                    formatted_lines.append(f"{continuation_indent}) override;")
            else:
                # Fallback - shouldn't happen
                base_indent_expanded = base_indent.expandtabs(4)
                first_line_prefix = f"{base_indent_expanded}{return_type} {method_name}("
                continuation_indent = " " * (len(first_line_prefix) + 1)
                formatted_lines.append(f"{continuation_indent}) override;")
        
        return '\n'.join(formatted_lines)
                     
    def generate_header(self):
        """Generate the header file content"""
        
        methods_decl = []
        for method in self.methods:
            # Add preceding comments if they exist
            if method['preceding_comments']:
                for comment_line in method['preceding_comments']:
                    methods_decl.append(comment_line)
            
            # Add the method declaration (already formatted with proper indentation)
            if '\n' in method['full_signature']:
                # Multi-line signature is already formatted
                methods_decl.append(method['full_signature'])
            else:
                # Single line signature needs tab prefix and override
                method_line = f"\t{method['full_signature']} override;"
                if method['inline_comment']:
                    method_line += f" {method['inline_comment']}"
                methods_decl.append(method_line)
            
            # Add any trailing blank lines after this method
            if 'trailing_blank_lines' in method and method['trailing_blank_lines']:
                for blank_line in method['trailing_blank_lines']:
                    methods_decl.append(blank_line)
        
        header_content = f"""/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#ifndef {self.header_guard}
#define {self.header_guard}
#ifdef _WIN32
#pragma once
#endif

#include <isteamclient.h>
#include <{self.include_name}>

{self.purpose_comment if self.purpose_comment else f"// Purpose: {self.class_name} interface implementation"}
class {self.class_name} :
\tpublic {self.interface_name}
{{
private:
    // Singleton instance
    static {self.class_name}* s_pInstance;

public:
    {self.class_name}();
    ~{self.class_name}();

    // Helper methods
    static {self.class_name}* GetInstance();
    static void ReleaseInstance();

{chr(10).join(methods_decl)}
}};

#endif // {self.header_guard}
"""
        return header_content
        
    def generate_implementation(self):
        """Generate the implementation file content"""
        
        methods_impl = []
        for method in self.methods:
            # Generate default implementation based on return type
            return_type = method['return_type'].strip()
            method_name = method['name']
            
            # Process parameters for implementation (remove default values and extract names properly)
            params_str = method['params']
            impl_params_str, param_names = self._process_implementation_parameters(params_str)
            
            # Generate logging parameters
            if param_names:
                log_params = ', '.join([f'%s' if 'char' in param or 'string' in param.lower() else '%d' for param in param_names])
                log_args = ', ' + ', '.join(param_names)
            else:
                log_params = ""
                log_args = ""
                
            # Generate return statement based on return type
            if return_type == "void":
                return_stmt = ""
            elif "bool" in return_type:
                return_stmt = "\n\treturn false;"
            elif any(t in return_type for t in ["int", "uint", "float", "double"]):
                return_stmt = "\n\treturn 0;"
            elif "*" in return_type:
                return_stmt = "\n\treturn nullptr;"
            else:
                # For enums or other types, try to return a default constructed value
                clean_return_type = return_type.replace("const", "").replace("&", "").strip()
                return_stmt = f"\n\treturn {clean_return_type}();"
            
            # Add comments above the method implementation
            comment_block = ""
            if method['preceding_comments'] or method['inline_comment']:
                # Add preceding comments
                if method['preceding_comments']:
                    for comment_line in method['preceding_comments']:
                        # Remove leading whitespace from comment lines
                        clean_comment = comment_line.strip()
                        comment_block += clean_comment + "\n"
                
                # Add inline comment as a preceding comment for the implementation
                if method['inline_comment']:
                    clean_inline = method['inline_comment'].strip()
                    comment_block += clean_inline + "\n"
                    
            method_impl = f"""{comment_block}{return_type} {self.class_name}::{method_name}{impl_params_str}
{{
\tVLOG_DEBUG("{method_name} called{f" - {log_params}" if log_params else ""}"{log_args});{return_stmt}
}}"""
            methods_impl.append(method_impl)
            
        impl_content = f"""/*
 * VaporCore Steam API Implementation
 * Copyright (c) 2025 Tommy Lau <tommy.lhg@gmail.com>
 * 
 * This file is part of VaporCore.
 * 
 * Author: Tommy Lau <tommy.lhg@gmail.com>
 */

#include <cstring>

#include "{self.file_base_name}.h"
#include "logger.h"

// Static instance
{self.class_name}* {self.class_name}::s_pInstance = nullptr;

{self.class_name}::{self.class_name}()
{{
    VLOG_INFO("{self.class_name} constructor called");
}}

{self.class_name}::~{self.class_name}()
{{
    VLOG_INFO("{self.class_name} destructor called");
}}

// Helper methods
{self.class_name}* {self.class_name}::GetInstance()
{{
    if (!s_pInstance)
    {{
        s_pInstance = new {self.class_name}();
    }}
    return s_pInstance;
}}

void {self.class_name}::ReleaseInstance()
{{
    if (s_pInstance)
    {{
        delete s_pInstance;
        s_pInstance = nullptr;
    }}
}}

{(chr(10) + chr(10)).join(methods_impl)}
"""
        
        # Ensure exactly one blank line at the end
        impl_content = impl_content.rstrip() + '\n'
        return impl_content

    def _process_implementation_parameters(self, params_str):
        """Process parameters for implementation file: remove default values and extract parameter names properly"""
        if params_str == "()":
            return "()", []
        
        # Remove parentheses
        params_content = params_str.strip("()")
        if not params_content:
            return "()", []
        
        # Split parameters by comma, but be careful about nested commas in annotations
        param_parts = []
        current_param = ""
        paren_count = 0
        
        for char in params_content:
            if char == '(':
                paren_count += 1
            elif char == ')':
                paren_count -= 1
            elif char == ',' and paren_count == 0:
                param_parts.append(current_param.strip())
                current_param = ""
                continue
            current_param += char
        
        if current_param.strip():
            param_parts.append(current_param.strip())
        
        # Process each parameter
        processed_params = []
        param_names = []
        
        for param in param_parts:
            # Remove default values (everything after '=')
            if '=' in param:
                param = param.split('=')[0].strip()
            
            # Extract parameter name by removing annotations
            param_name = self._extract_parameter_name(param)
            if param_name:
                param_names.append(param_name)
            
            processed_params.append(param)
        
        impl_params_str = "( " + ", ".join(processed_params) + " )"
        return impl_params_str, param_names
    
    def _extract_parameter_name(self, param):
        """Extract the actual parameter name from a parameter declaration, ignoring annotations"""
        # Remove annotations like OUT_ARRAY_COUNT(...), DESC(...), BUFFER_COUNT(...), etc.
        import re
        
        # Remove all annotation patterns
        cleaned = re.sub(r'\b(OUT_ARRAY_COUNT|ARRAY_COUNT|BUFFER_COUNT|OUT_BUFFER_COUNT|DESC|OUT_STRING_COUNT)\s*\([^)]*\)\s*', '', param)
        
        # Now extract the parameter name
        words = cleaned.split()
        if not words:
            return None
        
        # Take the last word as parameter name, remove pointer/reference symbols
        param_name = words[-1].strip('*&')
        
        # Skip if this looks like a type keyword
        type_keywords = {'const', 'unsigned', 'signed', 'void', 'char', 'int', 'uint32', 'uint64', 'float', 'double', 'bool'}
        if param_name.lower() in type_keywords:
            return None
            
        return param_name
        
    def generate_files(self):
        """Generate both header and implementation files"""
        
        # Read the interface file
        try:
            with open(self.interface_file, 'r', encoding='utf-8') as f:
                content = f.read()
        except Exception as e:
            raise ValueError(f"Could not read interface file: {e}")
            
        # Extract interface information
        self.extract_interface_info(content)
        
        # Ensure output directory exists
        self.output_dir.mkdir(parents=True, exist_ok=True)
        
        # Generate header file
        header_path = self.output_dir / f"{self.file_base_name}.h"
        header_content = self.generate_header()
        
        with open(header_path, 'w', encoding='utf-8') as f:
            f.write(header_content)
            
        print(f"Generated header: {header_path}")
        
        # Generate implementation file
        impl_path = self.output_dir / f"{self.file_base_name}.cpp"
        impl_content = self.generate_implementation()
        
        with open(impl_path, 'w', encoding='utf-8') as f:
            f.write(impl_content)
            
        print(f"Generated implementation: {impl_path}")
        
        return header_path, impl_path


def main():
    parser = argparse.ArgumentParser(
        description='Generate VaporCore implementation files from Steam interface headers',
        epilog='Example: python interface_generator.py include/isteamvideo.h src'
    )
    
    parser.add_argument(
        'interface_file',
        help='Path to the Steam interface header file (e.g., include/isteamvideo.h)'
    )
    
    parser.add_argument(
        'output_dir',
        help='Output directory for generated files (e.g., src)'
    )
    
    args = parser.parse_args()
    
    try:
        generator = InterfaceGenerator(args.interface_file, args.output_dir)
        header_path, impl_path = generator.generate_files()
        
        print(f"\nSuccessfully generated implementation files:")
        print(f"  Header: {header_path}")
        print(f"  Implementation: {impl_path}")
        print(f"\nClass name: {generator.class_name}")
        print(f"Interface: {generator.interface_name}")
        print(f"Methods found: {len(generator.methods)}")
        
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1
        
    return 0


if __name__ == '__main__':
    sys.exit(main()) 