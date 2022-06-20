#!/bin/sh

nos=$1

if [ "$1" = "" ] ; then
echo Give the number of students that are currently in the classroom.
read nos
else
nos=$1
fi

i="$nos"
while [ "$i" -gt 0 ]
do
echo There are $i students in the classroom and 1 is leaving.
i=$(($i -1))
done

echo There are no students left in the classroom.

