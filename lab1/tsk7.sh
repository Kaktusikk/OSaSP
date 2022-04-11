#!/bin/bash

if [[ $# == 2 ]]
then
  if [[ -f "$1" && -x "$2" ]]
  then
    if gcc "$1" -o "$2"
    then
      echo "The program will be successfully launched."
      ./"$2"
    else
      echo "Errors occurred during compilation. The program will not be started." >&2
    fi
fi
else
echo "No arguments entered" >&2
fi
exit 0

