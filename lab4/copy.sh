#!bin/sh
if [ "$#" -ne 2 ]; then
    echo " Usage: $0 <file-path1> <file-path2>"
    exit 1
fi

source_file=$1
Destination_file=$2

if [ -e "$source_file" ];then
    cp -i "$source_file" "$Destination_file"
    echo "File with path $Destination_file is created"
else 
    echo "File with the given name or path does not exist"
    echo "Failed to copy!"
fi
exit