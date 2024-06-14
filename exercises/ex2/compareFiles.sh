#!/bin/bash
file1=$1
file2=$2

if [ ! -r "$file1" ]; then
    echo "File $file1 does not exist or no read permissions"
    exit 1
fi

if [ ! -r "$file2" ]; then
    echo "File $file2 does not exist or no read permissions"
    exit 1
fi

message=$(diff -y $file1 $file2 | cat -n | grep "|" | head -n1)
if [ "$message" != "" ]; then
    echo "$message" | sed -r 's/^[[:space:]]*([[:digit:]]+)\t(.*[^[:space:]])[[:space:]]+\|\t(.*)$/|       |Inconsistency found in line \1:\n|       |your solution:"\2"\n|       |     expected:"\3"/'
    exit 0
fi

message=$(diff -y $file1 $file2 | cat -n | grep "<[[:space:]]*$" | head -n1)
if [ "$message" != "" ]; then
    echo "$message" | sed -r 's/^[[:space:]]*([[:digit:]]+)[[:space:]](.*)[[:space:]]+<$/|       |Your soluiton has extra line #\1: "\2"/'
    exit 0
fi

message=$(diff -y $file1 $file2 | cat -n | grep -E "^[[:space:]]*[[:digit:]]+[[:space:]]+>" | head -n1)"MARK"
if [ "$message" != "MARK" ]; then
    echo "$message" | sed -r 's/^[[:space:]]*([[:digit:]]+)[[:space:]]+>(.*)MARK$/|       |Your soluiton has missing line #\1: "\2"/'
    exit 0
fi
