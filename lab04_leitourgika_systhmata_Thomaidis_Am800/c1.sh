#!/bin/sh

i=0

echo Enter your name.
read na

echo Enter the number of loops.
read nu


while [ "$i" -lt $nu ]
do
echo $na
i=`expr $i + 1`
done

