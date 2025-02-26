#!/bin/sh

if [ -z $1 ]; then
echo " Usage: $0 <file-path> "
exit 1
fi

filename=$1

if [ -e "$filename" ];then

    if [ -d "$filename" ];then
        echo "$filename is a directory"
    elif [ -f "$filename" ];then
        echo "$filename is a normal file"
    else 
        echo "$filename is neither directory nor normal file"
    fi
else 
    echo "file or directory with the name or path $filename doesnot exist"
fi
exit
