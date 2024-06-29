# my-solution
#!/bin/bash
chmod +x .
if [ $# -ne 1 ]; then
        echo "Usage: $0 PATH"
        exit 1
fi
if [ ! -e $1 ]; then
        echo "$1 is not a valid path"
        exit 2
fi
if [ -e $1 ]; then
        my_item=$1
        numBytes=$(source get-storage.sh)
        sumBytes=$numBytes
        dirList=$(ls $my_item)
        if [ -f $1 ]; then
                echo $numBytes
        else
                for file in $dirList; do
                        total_bytes_rec=$($0 $my_item/$file)
                        ((sumBytes += total_bytes_rec))
                done
                echo $sumBytes
        fi
fi

# class-solution
{
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
}
