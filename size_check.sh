#!/bin/sh

# code style: (C/D/Java/Ruby/C#/OCaml)
#   -T0                  Table driven FSM (default)
#code style: (C/D/Ruby/C#/OCaml)
#   -T1                  Faster table driven FSM
#   -F0                  Flat table driven FSM
#   -F1                  Faster flat table-driven FSM
#code style: (C/D/C#/OCaml)
#   -G0                  Goto-driven FSM
#   -G1                  Faster goto-driven FSM
#code style: (C/D)
#   -G2                  Really fast goto-driven FSM
#   -P<N>                N-Way Split really fast goto-driven FSM

ARM_PREFIX=arm-none-eabi

ARMCC=$ARM_PREFIX-gcc
SIZE=$ARM_PREFIX-size

echo "Defaults"
ragel -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "T1"
ragel -T1 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "F0"
ragel -F0 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "F1"
ragel -F1 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "G0"
ragel -G0 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "G1"
ragel -G1 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

echo "G2"
ragel -G2 -o size_check.c pint.rl
$ARMCC -O1 -c size_check.c
$SIZE size_check.o

rm size_check.c
