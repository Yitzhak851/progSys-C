#!/bin/bash

##############################
# count-files.sh
# - script for counting all readable files that are located
#   in the subtree below a given directory
##########################


# check that there is at least one argument
if [ $# -lt 1 ]; then
   echo "Usage: $0 <path>"
   exit 2
fi

# at this stage we know that there is at least one argument
# check if first argument is a valid path (ignore remaining arguments)
if [ ! -e $1 ]; then
   echo "no such path"
   exit 1
fi

# at this point, the first argument is a valid path. We apply recursion to
# determine number of files and list of directories using scripts from Problem 2
path=$1
numFiles=`ls -l $path | grep -c "^-r..r..r"`
dirList=`ls -l $path | grep "^dr..r..r" | sed -r 's/^.* (.*)$/\1/'`

# iterate over readable directories and call recursively
numItems=$numFiles
for d in $dirList
do
   # apply this script on the path of directory $d
   # since we know that $d corresponds to a valid directory, we don't need to check exit status
   numItems_rec=`$0 $path/$d`
   # add to count using arithmetic operator +=
   ((numItems+=numItems_rec))
done

# print result
echo $numItems
# script will exit with status 0 by default
