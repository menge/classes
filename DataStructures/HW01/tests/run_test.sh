#!/bin/bash

EXECUTABLE=`pwd`/bank
tempfile=`mktemp`
passed=0
failed=0

cd tests/input

for i in *
do
   echo -n "Testing ["
   echo -n $i
   echo -n "]: "
   $EXECUTABLE < $i &> $tempfile

   diff $tempfile ../output/$i &> /dev/null

   if [ "$?" -eq "0" ]; then
      echo "SUCCESS"
      passed=`expr $passed + 1`
   else
      echo "FAILURE"
      failed=`expr $failed + 1`
   fi

   rm $tempfile
done

total=`expr $passed + $failed`
echo ""
echo "================================================================================"
echo "Summary"
echo "================================================================================"
echo "$passed/$total test(s) passed"
echo "$failed/$total test(s) failed"

if [ "$failed" -ne "0" ]; then
   exit 1
fi

exit 0
