#!bin/bash
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <filepath_1> <filepath_2> <filepath_3>...."
    exit 1
fi
declare -a inputs
j=0
for i in $*
do
inputs[j]=$i
((j++))
done
echo $j

for ((i=0;i<$#;i++));do
    echo "${inputs[i]}"
done
exit
