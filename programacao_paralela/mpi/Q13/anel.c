#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define comm MPI_COMM_WORLD

int main(int argc, char *argv[])
{
    int comm_sz, my_rank, mensagem = 0, source, dest, flag = 1, qnt_saidas = 0;
    int i = 0;
    char **saida = NULL;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if (my_rank == 0)
    {
        if (argc != 2)
        {
            fprintf(stderr, "Erro: Argumento ausente.\n");
            fprintf(stderr, "Uso correto: mpiexec -n <num_procs> %s <tamanho_do_array>\n", argv[0]);
            mensagem = -1;
        }
        else
        {
            mensagem = atoi(argv[1]);
            if (mensagem <= 0)
            {
                fprintf(stderr, "Erro: O argumento deve ser um número inteiro positivo.\n");
                mensagem = -1;
            }
        }
    }

    MPI_Bcast(&mensagem, 1, MPI_INT, 0, comm);

    if (mensagem <= 0)
    {
        MPI_Finalize();
        exit(1);
    }

    if (my_rank == 0)
        saida = (char **)malloc((mensagem * 3) * sizeof(char *));

    source = (my_rank - 1 + comm_sz) % comm_sz;
    dest = (my_rank + 1) % comm_sz;
    i = comm_sz;

    while (flag)
    {
        if (my_rank == (i % comm_sz))
        {
            char *buffer = (char *)malloc(100 * sizeof(char));
            snprintf(buffer, 100, "[Processo %d] Enviando valor %d para o processo %d\n",
                     my_rank, --mensagem, dest);

            MPI_Send(&mensagem, 1, MPI_INT, dest, i, comm);

            if (my_rank != 0)
            {
                MPI_Send(buffer, 100, MPI_CHAR, 0, my_rank, comm);
                free(buffer);
            }
            else
            {
                saida[qnt_saidas++] = buffer;
            }
        }

        if (my_rank == ((i + 1) % comm_sz))
        {
            MPI_Recv(&mensagem, 1, MPI_INT, source, i, comm, MPI_STATUS_IGNORE);

            char *buffer = (char *)malloc(100 * sizeof(char));
            snprintf(buffer, 100, "[Processo %d] Recebeu valor %d do processo %d\n",
                     my_rank, mensagem, source);

            if (mensagem < 0)
                flag = 0;

            if (my_rank != 0)
            {
                MPI_Send(buffer, 100, MPI_CHAR, 0, my_rank, comm);
                free(buffer);
            }
            else
            {
                saida[qnt_saidas++] = buffer;
            }
        }

        if (my_rank == 0)
        {
            if ((i % comm_sz) != 0)
            {

                char *buffer = (char *)malloc(100 * sizeof(char));
                MPI_Recv(buffer, 100, MPI_CHAR, (i % comm_sz), (i % comm_sz), comm, MPI_STATUS_IGNORE);
                saida[qnt_saidas++] = buffer;
            }
            if ((i + 1) % comm_sz != 0)
            {
                char *buffer = (char *)malloc(100 * sizeof(char));
                MPI_Recv(buffer, 100, MPI_CHAR, ((i + 1) % comm_sz), ((i + 1) % comm_sz), comm, MPI_STATUS_IGNORE);
                saida[qnt_saidas++] = buffer;
            }
        }

        MPI_Bcast(&flag, 1, MPI_INT, ((i + 1) % comm_sz), comm);

        i++;
    }

    if (my_rank == 0)
    {
        for (i = 0; i < qnt_saidas; i++)
        {
            printf("%s", saida[i]);
            free(saida[i]);
        }
        free(saida);
    }

    MPI_Finalize();
    return 0;
}
