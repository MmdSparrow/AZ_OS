#!/bin/bash

num1=$1
num2=$3
operation=$2

case $operation in
	"+")
		printf '%f\n' "$( bc -l <<<"$num1 + $num2" )"
		;;
	"-")
		printf '%f\n' "$( bc -l <<<"$num1 - $num2" )"
		;;
	"*")
		printf '%f\n' "$( bc -l <<<"$num1 * $num2" )"
		;;
	"/")
		printf '%f\n' "$( bc -l <<<"$num1 / $num2" )"
		;;
esac
