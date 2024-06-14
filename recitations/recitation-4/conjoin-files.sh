#!/bin/bash

##############################
# count-files.sh
# - A script to conjoin all files in the desired path to a new file.
# - Fill in the missing part marked as: '---' and run the script
##########################

# check that there is at least two arguments
if [ --- ]; then
   echo "Usage: $0 <path> <file>"
   exit 1
fi

# at this stage we should know that there is at least two arguments

# check if first argument is a valid path
if [ --- ]; then
   echo "$1 no such path"
   exit 2
fi

#check if the second argument is already exists in folder (which is argument1)
if [ --- ]; then
   echo "$2 already exists"
   exit 3
fi

# Now copy all files with .txt extention into fileList argument,
# and count all files to totalFiles argument.
path=$1
fileList=`ls -l $path | ---`
totalFiles=`echo $fileList | ---`

# iterate over all text files, and append each file into argument2
for f in $fileList
do
   cat ---
done

# print result
echo "$totalFiles files were maerged into $2"
# script will exit with status 0 by default
