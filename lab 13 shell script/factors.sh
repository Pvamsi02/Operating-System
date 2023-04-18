#!/bin/bash
echo -e "Enter the value of n:\c"
read n
for ((i=1;i<=n;i++))
do
if [ $((n%i)) -eq 0 ];then
echo -e "$i "
fi
done
