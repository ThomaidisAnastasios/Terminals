#!/bin/sh
echo Type your name.
read na
echo Type the number of loops.
read nu
i=0
while [ "$i" -lt "$nu" ]
do
echo $na
i=`expr "$i" + 1 `
j=`expr "$i" % 10`
if [ "$j" = 0 ] ; then
echo If you want to continue give Y or y.Else give N or n.
read an
if [ "$an" = "Y" -o "$an" = "y" ]; then
continue
elif [ "$an" = "N" -o "$an" = "n" ]; then
break
else echo If you want to continue give Y or y.Else give N or n.
read an 
fi
fi 
done

