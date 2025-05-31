#!/bin/bash
NP=18
EXEC=main

make clean && make
mpirun -np $NP --enable-32bits-pci-domain ./$EXEC 
