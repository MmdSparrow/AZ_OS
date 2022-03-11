#!/bin/bash

printf 'enter x: '; read x
printf 'enter y: '; read y
printf 'enter file path: '; read path

y=`expr $y + 1`
i=2

while read -r line
do
	if [ $i -gt $x ] ; then
		echo "$line"
	fi

	i=`expr $i + 1`

	if [ $i -gt $y ] ; then
		break
        fi
done < "$path"
