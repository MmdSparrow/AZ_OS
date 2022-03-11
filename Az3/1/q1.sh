#!/bin/bash

regexPattern='^[+-]?[0-9]+([.][0-9]+)?$'

if ! [[ $1 =~ $regexPattern ]] || ! [[ $2 =~ $regexPattern ]]; then
	echo "invalid input! plz enter integer or float number."
	exit 1
else
	let sum=$1+$2
	echo "sum=$sum"

	if [ $1 -gt $2 ]; then
		echo "first number is grater thatn another one."
	else
		echo "second number is greater than another one."
	fi
fi
