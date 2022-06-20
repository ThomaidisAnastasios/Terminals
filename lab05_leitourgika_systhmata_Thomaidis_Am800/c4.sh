#!/bin/sh

changes=0

tmpfile0=`mktemp /tmp/$0.XXXX`
tmpfile1=`mktemp /tmp/$0.XXXX`

url=http://feeds.feedburner.com/grinsomnia
wget "$url" -O $tmpfile0

while [ "$changes" = 0 ] ; 
do
sleep 10
wget "$url" -O $tmpfile1

if [ `diff $tmpfile0 $tmpfile1` ] ; then
cp $tmpfgile1 $tmpfile0
echo The files are different.

else
echo The files arent different.
fi
done
