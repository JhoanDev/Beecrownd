#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define max 10000

void gen_data(int *array, int size);
void merge(int arr[], int inicio, int meio, int fim);
void mergeSort(int arr[], int inicio, int fim);
int isSorted(int arr[], int size);
void print_array(int *array, int size, const char *title);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <tamanho_do_array>\n", argv[0]);
        exit(1);
    }
    int size = atoi(argv[1]);
    if (size <= 0)
    {
        fprintf(stderr, "O tamanho do array precisa ser > 0\n");
        exit(1);
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Falha ao alocar memória para o array.\n");
        exit(1);
    }

    gen_data(array, size);

    if (size < 100) {
        print_array(array, size, "Array Original:");
    }

    clock_t start_time = clock();
    
    mergeSort(array, 0, size - 1);
    
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("----------------------------------------\n");
    printf("Tempo de ordenação: %f segundos sequencial com tamanho %d\n", cpu_time_used, size);

    if (size < 100) {
        print_array(array, size, "Array Ordenado:");
    }
    
    if (isSorted(array, size))
    {
        printf("Sucesso: O array foi ordenado corretamente.\n");
    }
    else
    {
        printf("Erro: O array não foi ordenado corretamente.\n");
    }
    printf("----------------------------------------\n");
    
    free(array); 
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
        fprintf(stderr, "Falha ao alocar memória em merge().\n");
        exit(1);
    }

    for (i = 0; i < n1; i++) L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

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