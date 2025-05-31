#!/bin/bash

NP=4 
EXEC=main
BIN_COUNT=10      # Número de caixas (bins)
MIN_MEAS=0.0      # Valor mínimo da medição
MAX_MEAS=100.0    # Valor máximo da medição
DATA_COUNT=1000000 # Número total de dados a serem gerados

echo "Limpando e compilando..."
make clean && make
if [ $? -ne 0 ]; then
    echo "Erro na compilação. Abortando."
    exit 1
fi

echo "Executando o programa MPI com $NP processos..."
mpirun  -np $NP ./$EXEC $BIN_COUNT $MIN_MEAS $MAX_MEAS $DATA_COUNT 
echo "Execução concluída."