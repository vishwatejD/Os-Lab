#!bin/bash

if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <filepath_1> <filepath_2> <filepath_3>...."
    exit 1
fi

rm -i "$@"
exit
