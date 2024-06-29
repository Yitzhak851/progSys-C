# my-solution
ls -ld $my_item | cut -f5 -d" "

# class-solution
ls -ld $my_item | tr -s ' ' | cut -d' ' -f5 