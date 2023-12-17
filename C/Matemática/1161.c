#include <stdio.h>

unsigned long long int fat(int n)
{
    if (n == 0 || n == 1)
        return 1;
    unsigned long long int resultado = n;
    for (int i = n - 1; i > 0; i--)
        resultado *= i;
    return resultado;
}

unsigned long long int somafat(int fatM, int fatN)
{
    return (fat(fatM) + fat(fatN));
}

int main()
{
    int M, N;
    unsigned long long int resultado;
    while (scanf("%d %d", &M, &N) != EOF)
    {
        resultado = somafat(M, N);
        printf("%llu\n", resultado);
    }
    return 0;
}
