#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

void reduce_arvore(int *soma_local, int my_rank, int comm_sz);

int main(int argc, char *argv[])
{
    int my_rank, comm_sz;
    MPI_Comm comm;

    MPI_Init(NULL, NULL);
    comm = MPI_COMM_WORLD;
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    int soma_local = my_rank + 1;
    reduce_arvore(&soma_local, my_rank, comm_sz);

    if (my_rank == 0)
    {
        printf("%d -> %d\n", my_rank, soma_local);
    }

    MPI_Finalize();
}

void reduce_arvore(int *soma_local, int my_rank, int comm_sz)
{
    int aux = 0;
    for (int salt = 1; salt < comm_sz; salt <<= 1)
    {
        if ((my_rank & salt) == 0)
        {
            int partner = my_rank + salt;
            if (partner < comm_sz)
            {
                MPI_Recv(&aux, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                *soma_local += aux;
            }
        }
        else
        {
            int partner = my_rank - salt;
            MPI_Send(soma_local, 1, MPI_INT, partner, 0, MPI_COMM_WORLD);
            break;
        }
    }
}