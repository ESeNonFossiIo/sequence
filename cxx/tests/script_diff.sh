#!/bin/bash



function check_diff()
{
  TOLLERANCE="1.0e-6"
  numdiff -r ${TOLLERANCE} $1 $2 >/dev/null
  RESULT=$?

  echo "RESULT"=$RESULT
  if [ "$RESULT" -eq 0 ]
  then
    true
  else
    false
  fi
}

check_diff $1 $2
