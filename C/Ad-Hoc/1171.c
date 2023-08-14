#include <stdio.h>

void bublesort(int vetor[], int qnt[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                aux = qnt[j];
                qnt[j] = qnt[j + 1];
                qnt[j + 1] = aux;
            }
        }
    }
}

int buscalinear(int vetor[], int n, int v)
{
    if (n == 0)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == v)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, number, cont = 0, retorno;
    scanf("%d", &n);
    int x[n];
    int qnt[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        retorno = buscalinear(x, cont, number);
        if (retorno != -1)
            qnt[retorno]++;
        else
        {
            x[cont] = number;
            qnt[cont] = 1;
            cont++;
        }
    }
    bublesort(x, qnt, cont);
    for (int i = 0; i < cont; i++)
    {
        printf("%d aparece %d vez(es)\n", x[i], qnt[i]);
    }
}