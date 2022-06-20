#!/bin/sh

cp /etc/passwd passwd2.txt

linesnumber=`wc -l passwd2.txt`

echo the lines are $linesnumber
