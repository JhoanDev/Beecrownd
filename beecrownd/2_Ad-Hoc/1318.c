#include <stdio.h>
#include <math.h>

int buscasequencial(int vet[], int tamanho, int key)
{
    if (tamanho != 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (vet[i] == key)
            {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int main()
{
    while (1)
    {
        int numbi, pessoas, i;
        scanf("%d %d", &numbi, &pessoas);
        if (numbi == 0 && pessoas == 0)
            break;
        int bilhetes[numbi];
        int bilhetesfalsos[pessoas];
        int numbiatual = 0;
        int novobi = 0;
        int numbilhetesfalsos = 0;
        for (i = 0; i < pessoas; i++)
        {
            scanf("%d", &novobi);
            if (buscasequencial(bilhetes, numbiatual, novobi))
            {
                if (!buscasequencial(bilhetesfalsos, numbilhetesfalsos, novobi))
                {
                    bilhetesfalsos[numbilhetesfalsos] = novobi;
                    numbilhetesfalsos++;
                }
            }
            else
            {
                bilhetes[numbiatual] = novobi;
                numbiatual++;
            }
        }
        printf("%d\n", numbilhetesfalsos);
    }
    return 0;
}