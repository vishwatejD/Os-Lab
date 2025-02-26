#!/bin/bash
if [ -z "$1" ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

num1=$1
sum=0

function_add() {
    num=$1
    if [ $num -eq 0 ]; then
        echo $sum
        return
    fi 
    digit=$((num % 10))
    sum=$((sum + digit))
    function_add $((num / 10)) 
}
echo $(function_add $num1)

