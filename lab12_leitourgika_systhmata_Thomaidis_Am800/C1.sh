#!/bin/sh

nol=`tput lines`
noc=`tput cols`

echo "Number of lines are $nol and number of columns are $noc."
echo "Input a name."
read n

strs=${#n}

offset=`expr $strs / 2`
y_center=`expr $nol / 2`
x_center=`expr $noc / 2 - $offset`

printf "%b %b %s %b \n" "\033[2J" "\033[${y_center};${x_center}f" "$n" "\033[0m"
