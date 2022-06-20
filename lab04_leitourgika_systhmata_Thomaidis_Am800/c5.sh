#!/bin/sh

i=1
random=`od -vAn -N4 -tu4 < /dev/urandom`
echo $random

echo Type a number.
read n 

while [ "$n" -ne "$random" ] 
do
 
if [ "$n" -lt "$random" ];then
echo You gave a smaller number.
i=`expr $i + 1`

else 
echo You gave a bigger number.
i=`expr $i + 1`

fi 
echo Type a number.
read n

done

echo Gongratulations you found the random number.The number of tries equalles $i.

