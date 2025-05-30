#!/bin/bash
NP=18
EXEC=main

make clean && make
mpirun --enable-32bits-pci-domain -np $NP ./$EXEC 
