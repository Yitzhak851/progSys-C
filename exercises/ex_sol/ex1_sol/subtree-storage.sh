#!/bin/bash

# check arguments
if [ $# -ne 1 ]; then
   echo "Usage: $0 PATH"
   exit 1
elif [ ! -e $1 ]; then
   echo $1 is not a valid path
   exit 2
fi

# get item size
my_item=$1
size=`source get-storage.sh`

# if item is dir, then call recursively
if [ -d $my_item ]; then
   items=`ls $my_item`
   for item in $items; do
      sub_size=`bash $0 $my_item/$item`
      ((size+=sub_size))
   done
fi

# output result
echo $size
