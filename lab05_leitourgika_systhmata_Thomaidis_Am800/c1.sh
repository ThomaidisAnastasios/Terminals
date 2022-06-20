#!/bin/sh

if [ $# = 0 ] ; then
echo There were no parameters.

elif [ $# -ne 1 ] ; then
echo You gave too many parameters.

elif [ $# = 1 ] ; then
if [ `echo $1 | grep '[a-z][a-z]*$'` ] ; then
if [ `grep "$1" /etc/passwd` ] ; then
echo The word does exist in the file password.

else 
echo The word doesnt exist in the file password.
fi


else 
echo You inserted non valid input.
fi

fi

