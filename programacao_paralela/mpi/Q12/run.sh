#!/bin/bash
NP=8
EXEC=main
SIZE=80000000

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
