#!/bin/sh

cd `ls -ls /bin > lsfile`

i=0

while
read p
do

j=`echo
$p | cut -f 1 -d " "`

if [ "$j" = "x" ] ; then
continue

fi
i=$(( $i + $j )) done < lsfile echo $i

rm lsfile
done
