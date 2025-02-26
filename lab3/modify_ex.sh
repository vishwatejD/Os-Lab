#!/bin/bash

# Iterate through all files in the current directory (excluding subdirectories)
for file in *; do
    if [[ -f "$file" ]]; then  # Check if it's a regular file
        sed -i -E 's/(^|\.)ex:/\1Example:/g' "$file"
        echo "Modified: $file"
    fi
done
