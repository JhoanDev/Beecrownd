#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <math.h>

typedef unsigned long long llu;
int main(int argc, char *argv[])
{
    int rank, num_procs;
    llu total_samples;
    llu samples_per_proc;
    llu local_hits = 0;
    llu total_hits = 0;
    unsigned int seed;
    double x, y;
    double start_time, end_time, local_elapsed_time, max_elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (rank == 0)
    {
        if (argc != 2)
        {
            fprintf(stderr, "Usage: %s <total_samples>\n", argv[0]);
            total_samples = -1;
        }
        else
        {
            total_samples = atoll(argv[1]);
            if (total_samples <= 0)
            {
                fprintf(stderr, "Error: Number of samples must be a positive integer.\n");
                total_samples = -1;
            }
        }
    }

    MPI_Bcast(&total_samples, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    if (total_samples == -1)
    {
        MPI_Finalize();
        return 1;
    }

    samples_per_proc = total_samples / num_procs;
    if (rank == num_procs - 1)
        samples_per_proc += total_samples % num_procs;

    seed = (unsigned int)time(NULL) + rank;

    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();

    for (llu i = 0; i < samples_per_proc; ++i)
    {
        x = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        y = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        if (x * x + y * y <= 1.0)
        {
            local_hits++;
        }
    }

    end_time = MPI_Wtime();
    local_elapsed_time = end_time - start_time;

    MPI_Reduce(&local_hits, &total_hits, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_elapsed_time, &max_elapsed_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        double pi_estimate = 4.0 * total_hits / total_samples;
        printf("Pi estimate: %.10lf\n", pi_estimate);
        printf("Total samples: %.6lf\n", max_elapsed_time);
    }

    MPI_Finalize();
    return 0;
}