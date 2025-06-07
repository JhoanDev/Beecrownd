#!/bin/bash
NP=8
EXEC=main
MENSAGEM=10000000

make clean && make
mpirun -np $NP ./$EXEC $MENSAGEM 
