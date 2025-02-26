#!/bin/bash

# Read file extension and target folder from user
read -p "Enter file extension (e.g., .text): " ext
read -p "Enter target folder name: " folder

# Create target folder if it doesn't exist
mkdir -p "$folder"

# Find and move files only in the current directory (not subdirectories)
find . -maxdepth 1 -type f -name "*$ext" -exec mv {} "$folder" \;

echo "Moved all $ext files to $folder"
