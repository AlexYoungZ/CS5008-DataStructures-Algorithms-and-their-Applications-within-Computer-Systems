#!/bin/bash

# look into a predefined list of directories
# and count the number of files that exist in each directory and its subdirectories.
# If that number is above a threshold, then the script will generate a warning message.
# practical and actually more useful than system finder, faster

DIRECTORIES="/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang"

# Count the number of arguments passed in
if [[ $# -le 0 ]]
then
    echo "Using default value for COUNT!"
else
    if [[ $1 =~ ^-?[0-9]+([0-9]+)?$ ]]
    then
        COUNT=$1
    fi
fi

while read -d ':' dir; do
    if [ ! -d "$dir" ]
    then
        echo "**" Skipping $dir
        continue
    fi
    files=`find $dir -type f | wc -l`
    if [ $files -lt $COUNT ]
    then
        echo "Everything is fine in $dir: $files"
    else
        echo "WARNING: Large number of files in $dir: $files!"
    fi
done <<< "$DIRECTORIES:"