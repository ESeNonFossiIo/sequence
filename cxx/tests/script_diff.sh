#!/bin/bash

RESULT=$(diff $1 $2)
if [ "$RESULT" ]
then
  false
else
  true
fi
