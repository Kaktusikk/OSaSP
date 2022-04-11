#!/bin/bash

if [[ $#>0 ]]
then
  echo "arguments: $@"
  echo "$@" > arg.txt
else
  echo "no arguments"
fi

exit 0
