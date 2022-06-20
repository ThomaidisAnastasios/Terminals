#!/bin/sh

if [ $# = 0 ] ; then
echo There were no parameters.

elif [ $# != 1 ] ; then
echo You gave too many parameters.

elif [ $# = 1 ] ; then
i=`echo "$j" | egrep '^[a-z][a-z]*$'`

while [ ! -z "$i" ] ; 
do
echo Insert a parameter of a to z only in lowercase type.
read parameter
done

if [ `grep "$j" /etc/passwd` ] ; then
echo The word does exist in the file password.

else
echo The word doesnt exist in the file password.
fi
fi
