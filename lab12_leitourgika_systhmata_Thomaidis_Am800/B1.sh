#!/bin/sh

printf "%s%b" "[..........]" "\033[11D"

i=1
st=1

while [ $i -le 5 ]
do
	ri=1	
	li=1

	while [ $ri -le 9 ] 
	do

		printf "%b%s%s%b" "\033[31m" "." "*" "\033[1D"
		
		sleep $st
		ri=`expr $ri + 1`

	done

	while [ $li -le 9 ]
	do

		printf "%b%s%s%b" "\033[1D" "*" "." "\033[2D"		
		
		sleep $st
		li=`expr $li + 1`

	done

i=`expr $i + 1`
done

printf "%b\n" "\033[0m"
