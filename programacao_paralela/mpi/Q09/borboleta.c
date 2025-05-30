#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

void all_reduce_borboleta(int *soma_local, int my_rank, int comm_sz);

int main(int argc, char *argv[])
{
    int my_rank, comm_sz;
    MPI_Comm comm;

    MPI_Init(NULL, NULL);
    comm = MPI_COMM_WORLD;
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    int soma_local = my_rank + 1;
    all_reduce_borboleta(&soma_local, my_rank, comm_sz);

    printf("%d -> %d\n", my_rank, soma_local);
    MPI_Finalize();
}

void all_reduce_borboleta(int *soma_local, int my_rank, int comm_sz)
{
    int i;
    int aux;
    int potencia = 1;
    while (potencia < comm_sz)
        potencia <<= 1;
    potencia >>= 1;
    int sobrou = comm_sz - potencia;
    int parceiro;
    if (my_rank >= potencia)
        MPI_Send(soma_local, 1, MPI_INT, my_rank - potencia, 0, MPI_COMM_WORLD);
    if (my_rank < sobrou)
    {
        MPI_Recv(&aux, 1, MPI_INT, my_rank + potencia, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        (*soma_local) += aux;
    }

    if (my_rank < potencia)
    {
        for (i = 1; i < potencia; i *= 2)
        {
            parceiro = my_rank ^ i;
            MPI_Sendrecv(soma_local, 1, MPI_INT, parceiro, 0,
                         &aux, 1, MPI_INT, parceiro, 0,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            (*soma_local) += aux;
        }
    }

    if (my_rank >= potencia)
        MPI_Recv(soma_local, 1, MPI_INT, my_rank - potencia, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    if (my_rank < sobrou)
        MPI_Send(soma_local, 1, MPI_INT, my_rank + potencia, 0, MPI_COMM_WORLD);
}