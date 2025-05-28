#!/bin/bash
NP=8
VAR=12345678900
EXEC=main

make clean && make
mpirun -np $NP ./$EXEC $VAR 
