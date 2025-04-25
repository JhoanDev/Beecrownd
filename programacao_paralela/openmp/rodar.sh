#!/bin/bash
if [ -z "$1" ]; then
  echo "Uso: ./run.sh arquivo.c [args...]"
  exit 1
fi

SRC=$1
shift 
echo "Compilando $SRC com OpenMP..."
gcc -Wall -O2 -fopenmp -o main "$SRC"

if [ $? -ne 0 ]; then
  echo "Erro na compilação!"
  exit 2
fi

echo "Executando ./main $@"
./main "$@"

rm -f *.o
