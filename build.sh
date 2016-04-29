#!/bin/sh

ragel pint.rl
gcc -c pint.c
gcc -c pint_test.c
gcc -o pint pint.o pint_test.o
