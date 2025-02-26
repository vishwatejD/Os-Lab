#!/bin/sh
echo "Converting all .txt files to .text in current directory and sub directories....."

find . -type f -name "*.txt" | while read file ;do
    mv "$file" "${}
