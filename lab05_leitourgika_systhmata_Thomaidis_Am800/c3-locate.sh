#!/bin/sh

if [ $# = 0 ] ; then
echo There was no parameter inserted.

elif [ $# !=  1 ] ; then
echo There were too many parameters.

else
if [ `echo $1 | grep '^[a-z0-9A-Z.]*$'` ] ; then
i=`grep "$1" ~/file.db`
fi

if [ $? = 0 ] ; then
echo It exists in the file.

else
echo The file wasnt found.
fi
fi
