#!/bin/bash
# Simply pass in the exercise number to compile and run
if [ $1 == 2 ]
then
        cc 4-$1.c -lm && ./a.out
else
        cc 4-$1.c && ./a.out
fi

