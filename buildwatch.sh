#!/bin/bash
outputfile=`mktemp`
while true; do
  script -q -c "./build.sh" $outputfile > /dev/null
  clear
  cat $outputfile
  inotifywait -qq *.c* *.h*
done
