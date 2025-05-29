#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <math.h>

typedef long long ll;
typedef unsigned int ui;

int main(int argc, char *argv[])
{
    int rank, num_procs, rest;
    ll lancamentos_totais, lancamentos_locais, acertos_locais = 0, acertos_totais = 0;
    ui seed;
    double x, y;
    double start_time, end_time, min_start_time, max_end_time;

    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <lancamentos totais>\n", argv[0]);
        exit(1);
    }

    lancamentos_totais = atoll(argv[1]);
    if (lancamentos_totais <= 0)
    {
        fprintf(stderr, "Erro: a quantidade de lancamentos tem que ser positiva\n");
        exit(1);
    }

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    rest = lancamentos_totais % num_procs;

    lancamentos_locais = lancamentos_totais / num_procs;
    if (rank < rest)
        lancamentos_locais++;

    seed = (ui)time(NULL) + rank;

    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();

    for (ll i = 0; i < lancamentos_locais; ++i)
    {
        x = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        y = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;

        if (x * x + y * y <= 1.0)
        {
            acertos_locais++;
        }
    }
    end_time = MPI_Wtime();

    MPI_Reduce(&acertos_locais, &acertos_totais, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Reduce(&start_time, &min_start_time, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&end_time, &max_end_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        double pi_estimate = 4.0 * acertos_totais / lancamentos_totais;
        printf("Pi aprox: %.10lf\n", pi_estimate);
        printf("Tempo: %.6lfs\n", (max_end_time - min_start_time));
    }

    MPI_Finalize();
    return 0;
}