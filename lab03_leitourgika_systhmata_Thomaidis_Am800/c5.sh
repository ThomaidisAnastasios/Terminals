#!/bin/sh

n=$1

if [ "$1" = "" ] ; then
 echo "What is your name? "
 read n
else 
 n=$1

fi

if [ "$n" = "Tasos" ] ; then
 echo "Hello Master."
else
 echo "Who are you?"

fi
