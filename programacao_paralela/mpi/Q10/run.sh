#!/bin/bash
NP=8
EXEC=main
SIZE=123456789

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
