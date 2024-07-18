# my-solution

# list_item.sh

#!/bin/bash
dir=$1

num_items=0
files=`ls $dir`
for file in $files; do
    if [ -f "$file" ]; then
        num_items++;
    fi
done

echo $file is 



# class-solution