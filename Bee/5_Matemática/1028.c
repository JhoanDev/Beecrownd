#include <stdio.h>

int mdc(int a, int b)
{
    int resto;
    while (a != 0)
    {
        resto = b % a;
        b = a;
        a = resto;
    }
    return b;
}

int main()
{
    int casos, i, j;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++)
    {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        int max;
        max = mdc(f1, f2);
        printf("%d\n", max);
    }
    return 0;
}
