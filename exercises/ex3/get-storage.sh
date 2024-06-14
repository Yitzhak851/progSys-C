#ls -ld $my_item | tr -s ' ' | cut -d' ' -f5 
ls -ld $my_item | cut -f5 -d" "