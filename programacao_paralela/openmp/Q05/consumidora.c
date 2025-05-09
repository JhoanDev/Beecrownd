#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <unistd.h>
#include "fila.h"

void produtor(int my_rank, Fila *fila, int *flag)
{
    char *linha = NULL;
    char nome_arq[32];
    size_t tam = 0;
    snprintf(nome_arq, sizeof(nome_arq), "thread_%d.txt", my_rank);

    FILE *arq = fopen(nome_arq, "rt");
    if (!arq)
    {
        fprintf(stderr, "Erro ao abrir arquivo: %s\n", nome_arq);
#pragma omp atomic
        (*flag)--;
        return;
    }

    while (getline(&linha, &tam, arq) != -1)
    {
        char *copia = strdup(linha);
        if (copia != NULL)
        {
#pragma omp critical
            fila_insere(fila, copia);
        }
    }
    free(linha);
    fclose(arq);

#pragma omp atomic
    (*flag)--;
}

void consumidor(int my_rank, Fila *fila, int *flag, int *count_tokens)
{
    while (1)
    {
        char *linha = NULL;
        int fila_vazia_local;

#pragma omp critical
        {
            fila_vazia_local = fila_vazia(fila);
            if (!fila_vazia_local)
            {
                linha = fila_retira(fila);
            }
        }

        if (linha != NULL)
        {
            char *token, *ptr;
            token = strtok_r(linha, " \n", &ptr);
            while (token != NULL)
            {
                printf("thread %d Tokenized -> : %s\n", my_rank, token);
                (*count_tokens)++;
                token = strtok_r(NULL, " \n", &ptr);
            }
            free(linha);
        }
        else
        {
#pragma omp flush(flag)
            if (*flag == 0 && fila_vazia_local)
            {
                break;
            }
            usleep(100);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;

    int num_ranks = atoi(argv[1]);
    if (num_ranks & 1)
        return 0;

    int count_tokens = 0;
    int flag = num_ranks / 2;
    Fila *fila = cria_fila();

#pragma omp parallel num_threads(num_ranks) default(none) shared(flag, fila, count_tokens)
    {
        int my_rank = omp_get_thread_num();
        if (my_rank & 1)
        {
            produtor(my_rank, fila, &flag);
        }
        else
        {
            consumidor(my_rank, fila, &flag, &count_tokens);
        }
    }

    printf("Quantidade de tokens lidos: %d\n", count_tokens);
    fila_libera(fila);
    return 0;
}