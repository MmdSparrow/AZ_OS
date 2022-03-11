#!/bin/bahs

shapeNum=$1
ROW_NUMBER=5

numShape () {
        row=`expr $ROW_NUMBER + 1`
        i=1
        while [ $i -lt $row ]
        do
                j=0
                while [ $j -lt $i ]
                do
			printf '%d' "$i"
			j=`expr $j + 1 `
                done
                printf '\n'
		i=`expr $i + 1 `
        done
}

lineShape () {
	i=0

	while [ $i -lt $ROW_NUMBER ]
	do
		j=0
		while [ $j -lt $i ]
		do
			printf '| '
			j=`expr $j + 1 `
		done

		printf '|_\n'
		i=`expr $i + 1 `
	done
}

starShape () {
	row=`expr $ROW_NUMBER + 2`
	space=`expr $row - 2`
	i=1

	while [ $i -lt $row ]
	do
		j=0
		while [ $j -lt $space ]
		do
			printf ' '
			j=`expr $j + 1`
		done

		j=0
		while [ $j -lt $i ]
                do
                        printf '* '
                        j=`expr $j + 1`
                done

		printf '\n'
		space=`expr $space - 1`
		i=`expr $i + 1`
	done

	space=0
	i=`expr $row - 1`

	while [ $i -gt 0 ]
	do
		j=0
                while [ $j -lt $space ]
                do
                        printf ' '
                        j=`expr $j + 1`
                done

                j=0
                while [ $j -lt $i ]
                do
                        printf '* '
                        j=`expr $j + 1`
                done

                printf '\n'
                space=`expr $space + 1`
                i=`expr $i - 1`
	done
}


case $shapeNum in
    1)
	    lineShape
	    ;;
    2)
   	    starShape
	    ;;
    3)
	    numShape
	    ;;
esac
