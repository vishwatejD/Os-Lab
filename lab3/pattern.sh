#!/bin/bash

# Read number of lines from user
read -p "Enter the number of lines: " n

num=1
# Loop to print the reverse pyramid
for ((i=n; i>=1; i--))
do
    # Print leading spaces
    for ((j=0; j<n-i; j++))
    do
        echo -n "	"
    done
    
    # Print stars
    for ((k=0; k<2*i-1; k++,num++))
    do
        echo -n "$num	"
	
    done
    
    # Move to the next line
    echo
done
