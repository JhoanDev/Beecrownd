#!/bin/bash
NP=8
VAR=1234567890
EXEC=main

make clean && make
mpirun -np $NP ./$EXEC $VAR 
