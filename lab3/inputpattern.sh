#!/bin/sh


echo "Enter a pattern to list all the files:"
read filepattern

echo "Enter the path for the folder:"
read folderpath


if [ ! -d "$folderpath" ]; then
    echo "The folder '$folderpath' does not exist."
    exit 1
fi

ls "$folderpath" | grep -i "$filepattern"

exit 0
