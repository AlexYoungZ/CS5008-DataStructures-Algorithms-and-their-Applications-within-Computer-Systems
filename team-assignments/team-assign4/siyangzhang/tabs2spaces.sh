#!/bin/bash

# read a text file and convert each tab to the specified number of space characters
# useful to avoid tab to space / space to tab conversion

for f in "$@"; do
  if [ ! -f $f ]; then
    echo $f does not exist!
    continue
  fi
  echo "Converting $f."
  newFile=$(expand -t 4 "$f")
  echo "$newFile" >"$f"
done
