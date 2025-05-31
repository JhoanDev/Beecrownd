#!/bin/bash
NP=7
EXEC=main

make clean && make
mpirun -np $NP ./$EXEC 
