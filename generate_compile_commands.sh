#!/bin/bash

# Script to generate compile_commands.json for better C/C++ IntelliSense support
# This script uses bear to intercept the make commands and generate a compilation database

echo "Generating compilation database for better C/C++ IntelliSense support..."

# Check if bear is installed
if ! command -v bear &> /dev/null; then
    echo "Error: bear is not installed. Please install it first:"
    echo "  macOS: brew install bear"
    echo "  Ubuntu/Debian: sudo apt-get install bear"
    echo "  Or build from source: https://github.com/rizsotto/Bear"
    exit 1
fi

# Clean previous build artifacts
echo "Cleaning previous build artifacts..."
make clean

# Generate compilation database using bear
echo "Generating compile_commands.json..."
bear -- make -j1

if [ $? -eq 0 ]; then
    echo "Successfully generated compile_commands.json"
    echo "You can now enjoy better IntelliSense support in Cursor/VS Code!"
else
    echo "Error: Failed to generate compile_commands.json"
    exit 1
fi

# Optional: Show some statistics
if [ -f "compile_commands.json" ]; then
    echo "Compilation database statistics:"
    echo "  Number of compilation commands: $(jq length compile_commands.json 2>/dev/null || echo "unknown")"
    echo "  File size: $(ls -lh compile_commands.json | awk '{print $5}')"
fi 