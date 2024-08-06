#include <stdio.h>

unsigned long long int fib(unsigned long long int num, unsigned long long int *chamadas)
{
    (*chamadas)++;
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return fib(num - 1, chamadas) + fib(num - 2, chamadas);
}

int main()
{
    int casos, i;
    unsigned long long int resultado, fibo, chamadas = 0;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++)
    {
        chamadas = 0;
        scanf("%llu", &fibo);
        resultado = fib(fibo, &chamadas);
        printf("fib(%llu) = %llu calls = %llu\n", fibo, chamadas - 1, resultado);
    }
    return 0;
}
