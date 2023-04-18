echo -e "Enter the number of inputs:\c"
read n
echo -e "enter the page_size:\c" 
read m
a=$((m*1024))
for ((i=0;i<n;i++))
do 
echo -e "Enter the logical addr:\c"
read x
pgno=$((x/a))
offset=$((x%a))
echo "Page no:$pgno"
echo "Offset:$offset"
done