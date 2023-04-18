#!/bin/bash
echo -e "Enter a number:\c"
read n
length=${#n}
sum=0
for ((i=0;i<length;i++))
do 
digit=${n:$i:1}
sum=$(echo $sum + $digit^$length | bc)
done
if [ $sum -eq $n ];then
echo "$n is a amstrong number"
else
echo "$n is not amstrong number"
fi
