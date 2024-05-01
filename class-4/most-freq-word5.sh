#!/bin/bash
sourceDir=$1
targetDir=$2

if [ $# -lt 2 ]; then             # check number of arguments
    echo "Usage: $0 <source-dir> <target-dir>"
    exit 1
fi
if [ ! -d $sourceDir ]; then      # check if source dir exists
    echo "Error: source directory $sourceDir does not exist."
    exit 2
fi
if [ ! -d $targetDir ]; then   # check if target dir exists
    echo "Creating target dir $targetDir."
    mkdir -p $targetDir
else
    echo "Target dir $targetDir already exists."
fi

echo "Copying  contents of $sourceDir to $targetDir."
cp $sourceDir/* $targetDir
cd $targetDir
files=`ls *.txt`   # store list of *.txt files in var $files
for file in $files; do
    freq_word=`cat $file |\
        tr [:space:] "\n" |\
        tr -s "\n" |\
        tr "a-z" "A-Z" |\
        sort | uniq -c |\
        sort -k1,1nr | head -n1 |\
        tr -s " " | cut -d" " -f3`
    echo "  -> The most frequent word in $file is $freq_word"
done

echo "Done."
