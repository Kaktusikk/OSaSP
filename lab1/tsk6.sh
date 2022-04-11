#!/bin/bash

if [[ $# -eq  3 ]]
then
  if [ -d "$2" ]
  then {
    echo "ok"
    find "$2"  -type f -name "*.$3" | sort > $1
}
  else
    {
    echo 'Invalid arguments' 
    echo '1st argument - the name of the file to which the result will be output. The file must exist.' 
    echo '2nd argument - the name of the directory in which the necessary files will be searched.' 
    echo '3rd argument - file extension.'
    } >&2
  fi

else
  {
  echo 'Unexpected number of arguments. There should be 3.'
  echo '1st argument - the name of the file to which the result will be output.'
  echo '2nd argument - the name of the directory in which the necessary files will be searched.'
  echo '3rd argument - file extension.'
  } >&2
fi

exit 0
