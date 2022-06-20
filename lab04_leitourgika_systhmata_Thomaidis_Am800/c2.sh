#!/bin/sh

a=1

while [ $a -le 100 ]

do
n=`expr $a % 3`
 
if [ "$n" -ne 0 ] ; then
echo $a
 
fi
 
a=`expr $a + 1`

done


