#!/bin/bash

# Check if a filename is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

file="$1"

# Use awk to print only odd-numbered lines and overwrite the file
awk 'NR % 2 == 1' "$file" > temp.txt && mv temp.txt "$file"

echo "Even-numbered lines removed from $file."
