#!/bin/bash
echo "Enter the number of strings:"
read n
echo "Enter the Strings:"
for ((i=0;i<n;i++))
do
read string
reverse=$(echo $string | rev)
if [[ $string == $reverse ]]
then
echo "$string is Palindrome"
else
echo "$string is not Palindrome"
fi
done
