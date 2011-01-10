#!/bin/bash

EXECUTABLE=`pwd`/bank
tempfile=`mktemp`

cd tests/input

for i in *
do
   echo -n "Testing ["
   echo -n $i
   echo -n "]: "
   $EXECUTABLE < $i &> $tempfile

   diff -q $tempfile ../output/$i > /dev/null

   if [ "$?" -eq "0" ]; then
      echo "SUCCESS"
   else
      echo "FAILURE"
   fi

   rm $tempfile
done
