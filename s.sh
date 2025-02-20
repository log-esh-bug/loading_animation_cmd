#!/bin/bash
echo "Enter the number to be Repeated: "
read num
echo "Value Entered : $num"
for ((i=0;i<num;i++))
do
	time ./out 2
done
