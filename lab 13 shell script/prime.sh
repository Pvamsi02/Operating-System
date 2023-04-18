#!/bin/bash
echo -e "Enter number: \c" 
read n
for((i=2;i<n;i++))
do
if [ $((n % i)) -eq 0 ];
then
echo "$n is Composite"
exit 0
fi
done
echo "$n is Prime"

