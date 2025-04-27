#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <string.h>

void preenche_vetor(int *vet, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vet[i] = (int)((rand() / (double)RAND_MAX) * n);
    }
}

void printa_vetor(int *vet, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void count_sort(int a[], int n)
{
    int i, j, count;
    int *temp = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (a[j] < a[i])
                count++;
            else if (a[j] == a[i] && j < i)
                count++;
        temp[count] = a[i];
    }
    memcpy(a, temp, n * sizeof(int));
    free(temp);
}

void count_sort_paralelo(int a[], int n, int count_ranks)
{
    int i, j, count;
    int *temp = malloc(n * sizeof(int));

#pragma omp parallel for num_threads(count_ranks) default(none) private(count, i, j) shared(temp, a, n)
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (a[j] < a[i])
                count++;
            else if (a[j] == a[i] && j < i)
                count++;
        temp[count] = a[i];
    }

    memcpy(a, temp, n * sizeof(int));
    free(temp);
}

void count_sort_memcpy_paralelo(int a[], int n, int count_ranks)
{
    int i, j, count;
    int *temp = malloc(n * sizeof(int));

#pragma omp parallel for num_threads(count_ranks) default(none) private(count, i, j) shared(temp, a, n)
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (a[j] < a[i])
                count++;
            else if (a[j] == a[i] && j < i)
                count++;
        temp[count] = a[i];
    }

    int rest = n % count_ranks;
    int part_size = n / count_ranks;
    int my_rank, inicio, fim, tam;

#pragma omp parallel num_threads(count_ranks) default(none) private(my_rank, inicio, fim, tam) shared(a, temp, n, rest, part_size)
    {
        my_rank = omp_get_thread_num();

        inicio = (my_rank < rest) ? ((part_size + 1) * my_rank) : part_size * my_rank + rest;
        fim = (my_rank < rest) ? (inicio) + part_size + 1 : inicio + part_size;

        tam = fim - inicio;

        memcpy(a + inicio, temp + inicio, tam * sizeof(int));
    }

    free(temp);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Uso: %s <num_ranks> <tam_vetor>\n", argv[0]);
        return 0;
    }

    double start_time, end_time;
    double segs;
    int count_ranks = atoi(argv[1]);
    int tam_vetor = atoi(argv[2]);
    srand(time(NULL));

    int *vet1 = (int *)malloc(tam_vetor * sizeof(int));
    if (vet1 == NULL)
    {
        printf("Faltou memória\n");
        exit(1);
    }
    preenche_vetor(vet1, tam_vetor);

    int *vet2 = (int *)malloc(tam_vetor * sizeof(int));
    if (vet2 == NULL)
    {
        printf("Faltou memória\n");
        free(vet1);
        exit(1);
    }
    memcpy(vet2, vet1, tam_vetor * sizeof(int));

    int *vet3 = (int *)malloc(tam_vetor * sizeof(int));
    if (vet3 == NULL)
    {
        printf("Faltou memória\n");
        free(vet1);
        free(vet2);
        exit(1);
    }
    memcpy(vet3, vet1, tam_vetor * sizeof(int));

    int *vet4 = (int *)malloc(tam_vetor * sizeof(int));
    if (vet4 == NULL)
    {
        printf("Faltou memória\n");
        free(vet1);
        free(vet2);
        free(vet3);
        exit(1);
    }
    memcpy(vet4, vet1, tam_vetor * sizeof(int));

    start_time = omp_get_wtime();
    count_sort(vet1, tam_vetor);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Count sort sequencial demorou: %.5lfs\n", segs);

    start_time = omp_get_wtime();
    count_sort_paralelo(vet2, tam_vetor, count_ranks);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Count sort paralelo (original) demorou: %.5lfs\n", segs);

    start_time = omp_get_wtime();
    count_sort_memcpy_paralelo(vet3, tam_vetor, count_ranks);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("Count sort paralelo (com memcpy paralelo) demorou: %.5lfs\n", segs);

    start_time = omp_get_wtime();
    qsort(vet4, tam_vetor, sizeof(int), compare);
    end_time = omp_get_wtime();
    segs = end_time - start_time;
    printf("qsort demorou: %.5lfs\n", segs);


    if (tam_vetor <= 50) {
        printf("\nVetor ordenado (sequencial):\n");
        printa_vetor(vet1, tam_vetor);

        printf("\n\nVetor ordenado (paralelo original):\n");
        printa_vetor(vet2, tam_vetor);

        printf("\n\nVetor ordenado (paralelo com memcpy paralelo):\n");
        printa_vetor(vet3, tam_vetor);

        printf("\n\nVetor ordenado (qsort):\n");
        printa_vetor(vet4, tam_vetor);
        printf("\n");
    }

    free(vet1);
    free(vet2);
    free(vet3);
    free(vet4);
    return 0;
}

/*


a) Se tentarmos paralelizar o laço for i (o laço externo), quais variáveis devem ser
privadas e quais devem ser compartilhadas?  private(count, i, j) shared(temp, a, n)

b) Se paralelizarmos o laço for i usando o escopo especificado na parte anterior,
haverá alguma dependência de dados no laço? Explique sua resposta.

não pois em nenhum momento terá duas treads tentando sobrescrever no mesmo espaço, justamente pelo motivo de para cada iteração
"i" sempre resultará em um "count" diferente.

c) Podemos paralelizar a chamada para memcpy? Podemos modificar o código para que
esta parte da função seja paralelizável? sim, sim.

d) e e) o codigo responde kkk
*/