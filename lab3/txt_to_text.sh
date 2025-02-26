#!/bin/bash

# Find all .txt files and rename them to .text
find . -type f -name "*.txt" | while read file; do
    new_name="${file%.txt}.text"  # Change extension
    mv "$file" "$new_name"
    echo "Renamed: $file -> $new_name"
done
