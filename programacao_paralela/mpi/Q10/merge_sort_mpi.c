#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define max 10000
#define comm MPI_COMM_WORLD

void gen_data(int *array, int size);
void mergeSort(int arr[], int inicio, int fim);
int isSorted(int arr[], int size);
void print_array(int *array, int size, const char *title);

int main(int argc, char *argv[])
{
    int my_rank, comm_sz, size_data, rest, local_size_data, i, chunk, salt, par, par_size_data, j, k;
    int *global_data = NULL, *local_data = NULL, *send_counts = NULL, *displs = NULL;
    double start_time, end_time, elapsed_time; // Variáveis para o tempo

    MPI_Init(&argc, &argv);
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if (my_rank == 0)
    {
        if (argc != 2)
        {
            fprintf(stderr, "Erro: Argumento ausente.\n");
            fprintf(stderr, "Uso: mpiexec -n <num_procs> %s <tamanho_do_array>\n", argv[0]);
            size_data = -1;
        }
        else
        {
            size_data = atoi(argv[1]);
            if (size_data <= 0)
            {
                fprintf(stderr, "Erro: O tamanho do array deve ser um número positivo.\n");
                size_data = -1;
            }
        }
    }

    MPI_Bcast(&size_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (size_data <= 0)
    {
        MPI_Finalize();
        exit(1);
    }
    
    chunk = size_data / comm_sz;
    rest = size_data % comm_sz;
    local_size_data = chunk + (my_rank < rest);
    local_data = (int *)malloc(local_size_data * sizeof(int));

    if (my_rank == 0)
    {
        global_data = (int *)malloc(size_data * sizeof(int));
        send_counts = (int *)malloc(comm_sz * sizeof(int));
        displs = (int *)malloc(comm_sz * sizeof(int));

        int offset = 0;
        for (i = 0; i < comm_sz; i++)
        {
            send_counts[i] = chunk + (i < rest);
            displs[i] = offset;
            offset += send_counts[i];
        }

        gen_data(global_data, size_data);
        if (size_data < 100)
            print_array(global_data, size_data, "Array Original (no processo 0):");
    }

    if (my_rank == 0)
    {
        start_time = MPI_Wtime();
    }

    MPI_Scatterv(global_data, send_counts, displs, MPI_INT, local_data, local_size_data, MPI_INT, 0, comm);
    
    if (my_rank == 0)
    {
        free(global_data);
        free(send_counts);
        free(displs);
    }

    mergeSort(local_data, 0, local_size_data - 1);

    for (salt = 1; salt < comm_sz; salt <<= 1)
    {
        if ((my_rank & salt) == 0)
        {
            par = my_rank + salt;
            if (par < comm_sz)
            {
                MPI_Recv(&par_size_data, 1, MPI_INT, par, 0, comm, MPI_STATUS_IGNORE);
                int *par_data = (int *)malloc(par_size_data * sizeof(int));
                MPI_Recv(par_data, par_size_data, MPI_INT, par, 1, comm, MPI_STATUS_IGNORE);
                int *new_array = (int *)malloc((par_size_data + local_size_data) * sizeof(int));
                int n1 = local_size_data;
                int n2 = par_size_data;

                i = 0, j = 0, k = 0;
                while (i < n1 && j < n2)
                {
                    if (local_data[i] <= par_data[j])
                        new_array[k++] = local_data[i++];
                    else
                        new_array[k++] = par_data[j++];
                }
                while (i < n1) new_array[k++] = local_data[i++];
                while (j < n2) new_array[k++] = par_data[j++];

                free(local_data);
                free(par_data);
                local_data = new_array;
                local_size_data += par_size_data;
            }
        }
        else
        {
            par = my_rank - salt;
            MPI_Send(&local_size_data, 1, MPI_INT, par, 0, comm);
            MPI_Send(local_data, local_size_data, MPI_INT, par, 1, comm);
            free(local_data);
            local_size_data = 0;
            break;
        }
    }

    if (my_rank == 0)
    {
        end_time = MPI_Wtime();
        elapsed_time = end_time - start_time;
        printf("----------------------------------------\n");
        printf("Tempo de ordenação: %f segundos com %d processos e tamanho %d\n", elapsed_time, comm_sz, size_data);

        if (size_data < 100)
        {
            print_array(local_data, local_size_data, "Array Ordenado (no processo 0):");
        }
        
        if (isSorted(local_data, local_size_data))
        {
            printf("Sucesso: O array foi ordenado corretamente.\n");
        }
        else
        {
            printf("Erro: O array não foi ordenado corretamente.\n");
        }
        printf("----------------------------------------\n");
        free(local_data);
    }
    
    MPI_Finalize();
    return 0;
}

void gen_data(int *array, int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = (int)(max * (rand() / (double)RAND_MAX));
    }
}
void merge(int arr[], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para L ou R em merge().\n");
        MPI_Abort(MPI_COMM_WORLD, 1); 
        exit(EXIT_FAILURE); 
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

int isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void print_array(int *array, int size, const char *title)
{
    printf("%s\n", title);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}