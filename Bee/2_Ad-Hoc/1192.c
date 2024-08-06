#include <stdio.h>

int main()
{
    int n, numero1, numero2;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &numero1, &c, &numero2);
        if (numero1 == numero2)
        {
            printf("%d\n", numero1 * numero2);
        }
        else if ('A' <= c && c <= 'Z')
        {
            printf("%d\n", numero2 - numero1);
        }
        else
        {
            printf("%d\n", numero1 + numero2);
        }
    }
    return 0;
}