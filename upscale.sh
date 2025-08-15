#!/bin/zsh

# Script to recursively upscale all PNG files in a folder and its subfolders using ImageMagick with Nearest Neighbor filter

# Configuration
INPUT_DIR="$1"                     # Input folder (passed as first argument)
OUTPUT_DIR="${INPUT_DIR}/upscaled" # Output folder (subfolder named 'upscaled')
TARGET_SIZE="200%"              # Target resolution for upscaling
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

# Check if any PNG files exist recursively
if ! find "$INPUT_DIR" -type f -iname "*.png" | grep -q .; then
    echo "No PNG files found in '$INPUT_DIR' or its subfolders."
    exit 0
fi

# Iterate over PNG files recursively
find "$INPUT_DIR" -type f -iname "*.png" | while read -r file; do
    # Ensure the file exists (handles edge cases)
    [[ -f "$file" ]] || continue

    # Get the relative path of the file from INPUT_DIR
    relative_path="${file#$INPUT_DIR/}"
    # Get the directory path of the file relative to INPUT_DIR
    relative_dir=$(dirname "$relative_path")
    # Create the corresponding output directory
    output_subdir="${OUTPUT_DIR}/${relative_dir}"
    mkdir -p "$output_subdir" || {
        echo "Error: Could not create output subdirectory '$output_subdir'."
        continue
    }

    # Get the filename without path
    filename=$(basename "$file")
    # Extract name without extension (handles multiple dots)
    name="${filename%.png}"
    # Output file path with suffix in the mirrored subfolder
    output_file="${output_subdir}/${name}${SUFFIX}.png"

    # Skip if output file already exists to avoid overwriting
    if [[ -f "$output_file" ]]; then
        echo "Skipping: '$(basename "$output_file")' already exists in '$output_subdir'."
        continue
    fi

    echo "Processing: $relative_path -> ${relative_dir}/$(basename "$output_file")"

    # Run ImageMagick to upscale the image
    magick "$file" -filter Point -resize "$TARGET_SIZE" "$output_file" 2>/dev/null
    if [ $? -eq 0 ]; then
        echo "Successfully upscaled: $relative_path"
        ((count++))
    else
        echo "Error: Failed to upscale '$relative_path'."
    fi
done

# Summary
echo "----------------------------------------"
echo "Completed: $count PNG files upscaled."
echo "Output saved in: $OUTPUT_DIR"

exit 0