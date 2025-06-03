#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define comm MPI_COMM_WORLD

int *gen_array(int n);
// MODIFICADO: A assinatura da função agora usa long long int
void reduce_arvore(long long int *soma_local, int my_rank, int comm_sz);

int main(int argc, char *argv[])
{
    int my_rank, comm_sz, size_array, *local_array_a = NULL, *local_array_b = NULL, *array_a = NULL, *array_b = NULL, chunk_size, i;
    long long int local_prod_esc;
    double start_time, end_time, min_time, max_time;

    MPI_Init(&argc, &argv);

    // ... (o resto do código de inicialização não muda) ...
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if (my_rank == 0)
    {
        if (argc != 2)
        {
            fprintf(stderr, "Erro: Argumento ausente.\n");
            fprintf(stderr, "Uso: mpiexec -n <num_procs> %s <tamanho_do_array>\n", argv[0]);
            size_array = -1;
        }
        else
        {
            size_array = atoi(argv[1]);
            if (size_array <= 0)
            {
                fprintf(stderr, "Erro: O tamanho do array deve ser um número positivo.\n");
                size_array = -1;
            }
        }
    }

    MPI_Bcast(&size_array, 1, MPI_INT, 0, comm);

    if (size_array <= 0)
    {
        MPI_Finalize();
        exit(1);
    }

    MPI_Barrier(comm);
    start_time = MPI_Wtime();

    chunk_size = size_array / comm_sz;

    local_array_a = (int *)malloc(sizeof(int) * chunk_size);
    local_array_b = (int *)malloc(sizeof(int) * chunk_size);
    srand(time(NULL) + my_rank);

    if (my_rank == 0)
    {
        array_a = gen_array(size_array);
        array_b = gen_array(size_array);

        for (i = 1; i < comm_sz; i++)
        {
            MPI_Send((array_a + (chunk_size * i)), chunk_size, MPI_INT, i, 0, comm);
            MPI_Send((array_b + (chunk_size * i)), chunk_size, MPI_INT, i, 1, comm);
        }

        for (i = 0; i < chunk_size; i++)
        {
            local_array_a[i] = array_a[i];
            local_array_b[i] = array_b[i];
        }

        free(array_a);
        free(array_b);
    }
    else
    {
        MPI_Recv(local_array_a, chunk_size, MPI_INT, 0, 0, comm, MPI_STATUS_IGNORE);
        MPI_Recv(local_array_b, chunk_size, MPI_INT, 0, 1, comm, MPI_STATUS_IGNORE);
    }
    
    local_prod_esc = 0;
    for (i = 0; i < chunk_size; i++)
        local_prod_esc += (long long int)local_array_a[i] * local_array_b[i];

    free(local_array_a);
    free(local_array_b);
    reduce_arvore(&local_prod_esc, my_rank, comm_sz);

    end_time = MPI_Wtime();
    MPI_Reduce(&start_time, &min_time, 1, MPI_DOUBLE, MPI_MIN, 0, comm);
    MPI_Reduce(&end_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, comm);

    if (my_rank == 0)
    {
        printf("produto escalar entre A e B: %lld\n", local_prod_esc);
        printf("Tempo de execucao: %f segundos\n", max_time - min_time);
    }

    MPI_Finalize();
    return 0;
}

int *gen_array(int n)
{
    int i;
    int *array = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        array[i] = 100 * (double)rand() / RAND_MAX;
    }
    return array;
}

void reduce_arvore(long long int *soma_local, int my_rank, int comm_sz)
{
    long long int aux = 0;
    for (int salt = 1; salt < comm_sz; salt <<= 1)
    {
        if ((my_rank & salt) == 0)
        {
            int partner = my_rank + salt;
            if (partner < comm_sz)
            {
                MPI_Recv(&aux, 1, MPI_LONG_LONG, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                *soma_local += aux;
            }
        }
        else
        {
            int partner = my_rank - salt;
            MPI_Send(soma_local, 1, MPI_LONG_LONG, partner, 0, MPI_COMM_WORLD);
            break;
        }
    }
}