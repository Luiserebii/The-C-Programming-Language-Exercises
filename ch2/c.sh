#!/bin/bash
# Simply pass in the exercise number to compile and run
if [ $1 == 3 ]
then
	cc 2-$1.c -lm && ./a.out
else 
	cc 2-$1.c && ./a.out
fi

