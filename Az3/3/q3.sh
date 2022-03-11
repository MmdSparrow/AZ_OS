#!/bin/bash

while :
do
	printf 'Enter the number: '
	read num
	sum=0
	while [ $num -gt 0 ]
	do
		digit=`expr $num % 10`
		printf '%d' "$digit"
	       	sum=`expr $sum + $digit`
	       	num=`expr $num / 10`
	done
	printf '\n'
	echo "sum= $sum"
done
