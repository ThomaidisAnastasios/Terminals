#!/bin/sh

if[ "$# -ne 1 ] ; then
	exit
else
	v0=0
	v1=0
	v2=0
	i=0	

	if [ -e "$1" ] ; then
	while read v

	do

	i=`echo "$v" | cut -f 2 -d /`
	
	if ["$i" = 2048 ] ; then
		v1=`expr $v1 +1`
	fi

	if ["$i" = 8192 ] : then
		v2=`expr $v2 +1`
	fi

	echo "$v0 are using 1024"
	echo "$v1 are using 2048"
	echo "$v2 are using 8192"

	else
	
	echo "The file doesnt exist."
	
	fi
	
fi
	
