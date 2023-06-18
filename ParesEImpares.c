#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pei
{
    int *array;
    int inicio;
    int fim;
} PEI;

void merge(int *array, int inicio, int meio, int fim)
{
    int *a, p1, p2, tamanho, i, j, k, fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    a = (int *)malloc(tamanho * sizeof(int));
    if (a != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (array[p1] < array[p2])
                    a[i] = array[p1++];
                else
                    a[i] = array[p2++];
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    a[i] = array[p1++];
                else
                    a[i] = array[p2++];
            }
        }
    }
    for (j = 0; j < tamanho; j++)
    {
        array[j] = a[j];
    }
    free(a);
}

void merge_sort(int *array, int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        merge_sort(array, inicio, meio);
        merge_sort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

int main()
{
    int linhas = 0, x = 0, i = 0;
    scanf("%d", &linhas);
    PEI impar;
    PEI par;
    impar.array = malloc(linhas * sizeof(int));
    par.array = malloc(linhas * sizeof(int));
    impar.inicio = 0;
    par.inicio = 0;
    impar.fim = 0;
    par.fim = 0;
    for (i = 0; i < linhas; i++)
    {
        scanf("%d", &x);
        if (x % 2 == 0)
        {
            par.array[par.fim] = x;
            par.fim++;
        }
        else
        {
            impar.array[impar.fim] = x;
            impar.fim++;
        }
    }
    merge_sort(par.array, par.inicio, par.fim - 1);
    merge_sort(impar.array, impar.inicio, impar.fim - 1);
    for (i = 0; i < par.fim; i++)
    {
        printf("%d\n", par.array[i]);
    }
    for (i = impar.fim - 1; i >= impar.inicio; i--)
    {
        printf("%d\n", impar.array[i]);
    }

    return 0;
}
