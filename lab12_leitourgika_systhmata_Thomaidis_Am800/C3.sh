#!/bin/sh

printf "%s%b" "[..........]" "\033[11D"

i=1

while [ $i -le 10 ] 

do
	printf "%b%s" "\033[31m" "*"
	i=`expr $i + 1`
	sleep 1
done

printf "%b\n" "\033[0m"
