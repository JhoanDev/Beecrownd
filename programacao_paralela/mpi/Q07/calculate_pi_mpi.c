#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

typedef long long int ll;
typedef unsigned int ui;

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 0;
    double x, y, distancia_quadrada, estimativa_pi, ini, end;
    int i, qtd_circ = 0, world_size, world_rank, rest;
    ui seed = time(NULL), thread_seed;
    int count_ranks = atoi(argv[1]);
    ll num_lancamentos = atoi(argv[2]);
    ini = omp_get_wtime();

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    ll local_num_lancamentos;
    int rest = num_lancamentos % world_size;


    thread_seed = seed + omp_get_thread_num();
    for (i = 0; i < num_lancamentos; i++)
    {
        x = (rand_r(&thread_seed) / (double)RAND_MAX - 0.5) * 2;
        y = (rand_r(&thread_seed) / (double)RAND_MAX - 0.5) * 2;

        distancia_quadrada = x * x + y * y;
        if (distancia_quadrada <= 1)
            qtd_circ++;
    }

    estimativa_pi = 4.0 * qtd_circ / (double)num_lancamentos;

    printf("%.10lf\n", estimativa_pi);
    end = omp_get_wtime();
    printf("%.5lfs\n", end - ini);

    return 0;
}