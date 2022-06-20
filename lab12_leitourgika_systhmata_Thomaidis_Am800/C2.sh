#!/bin/sh
. ./functions.sh

noc=`tput columnss`
nol=`tput lines`

echo "Number of columns are $noc and number of lines $nol."
echo "Input a name."
read n

strs=${#n}

offset=`expr $strs / 2`
y_center=`expr $nol / 2`
x_center=`expr $noc / 2 - $offset`

print $x_center $y_center $n
