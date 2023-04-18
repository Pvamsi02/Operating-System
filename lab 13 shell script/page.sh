#!/bin/bash
echo -e "Enter the number of address:\c"
read n
echo -e "Enter page size in bytes:\c"
read pageSize
for ((i=0;i<n;i++))
do 
echo -e "Enter the logical address:\c"
read addr
pageNumber=$((addr/pageSize))
offset=$((addr%pageSize))
echo -e "Page Number = $pageNumber \nPage offset = $offset"
done
