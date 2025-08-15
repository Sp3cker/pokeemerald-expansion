#!/bin/bash

# Script to upscale all PNG files in a folder using ImageMagick with Nearest Neighbor filter

# Configuration
INPUT_DIR="$1"                     # Input folder (passed as first argument)
OUTPUT_DIR="${INPUT_DIR}/upscaled" # Output folder (subfolder named 'upscaled')
TARGET_SIZE="256x256"              # Target resolution for upscaling
SUFFIX="_upscaled"                 # Suffix for output filenames (optional)

# Check if ImageMagick is installed
if ! command -v magick >/dev/null 2>&1; then
    echo "Error: ImageMagick is not installed. Please install it first."
    echo "On macOS: brew install imagemagick"
    echo "On Ubuntu: sudo apt install imagemagick"
    echo "On Windows: Download from https://imagemagick.org"
    exit 1
fi

# Check if input directory is provided
if [ -z "$INPUT_DIR" ]; then
    echo "Usage: $0 <input_directory>"
    echo "Example: $0 ./images"
    exit 1
fi

# Check if input directory exists
if [ ! -d "$INPUT_DIR" ]; then
    echo "Error: Directory '$INPUT_DIR' does not exist."
    exit 1
fi

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR" || {
    echo "Error: Could not create output directory '$OUTPUT_DIR'."
    exit 1
}

# Counter for processed files
count=0

# Iterate over PNG files in the input directory
for file in "$INPUT_DIR"/*.png; do
    # Check if any PNG files exist
    if [ ! -f "$file" ]; then
        echo "No PNG files found in '$INPUT_DIR'."
        exit 0
    fi

    # Get the filename and extension
    filename=$(basename "$file")
    name="${filename%.*}"
    ext="${filename##*.}"

    # Define output file path
    output_file="${OUTPUT_DIR}/${name}${SUFFIX}.${ext}"

    echo "Processing: $filename -> $output_file"

    # Run ImageMagick to upscale the image
    magick "$file" -filter Point -resize "$TARGET_SIZE" "$output_file" 2>/dev/null
    if [ $? -eq 0 ]; then
        echo "Successfully upscaled: $filename"
        ((count++))
    else
        echo "Error: Failed to upscale '$filename'."
    fi
done

# Summary
echo "----------------------------------------"
echo "Completed: $count PNG files upscaled."
echo "Output saved in: $OUTPUT_DIR"

exit 0
