#!/bin/bash
NP=4
EXEC=main
SIZE=1234567890

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
