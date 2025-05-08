VARIAVEIS=10000
THREADS_LIST=(2 4 8)
SCHEDULE_LIST=("static" "dynamic" "guided")
RELATORIO="my_linear_system.txt"

echo "Relatório de Execução - $(date)" > "$RELATORIO"
echo "Variáveis: $VARIAVEIS" >> "$RELATORIO"
echo "---------------------------------------------" >> "$RELATORIO"

for SCHEDULE in "${SCHEDULE_LIST[@]}"; do
    for NUM_THREADS in "${THREADS_LIST[@]}"; do
        export OMP_NUM_THREADS=$NUM_THREADS
        export OMP_SCHEDULE=$SCHEDULE

        echo "Executando com $NUM_THREADS threads | schedule: $SCHEDULE"
        echo "[$SCHEDULE | Threads: $NUM_THREADS]" >> "$RELATORIO"
        ./main "$NUM_THREADS" "$VARIAVEIS" >> "$RELATORIO"
        
        echo "" >> "$RELATORIO"
    done
done

echo "Relatório salvo em: $RELATORIO"
