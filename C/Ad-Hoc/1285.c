#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0, i = 0, j = 0, k = 0, iguais = 0, achou = 0;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        char *numero = (char *)malloc(6 * sizeof(char));
        for (i = n; i <= m; i++)
        {
            sprintf(numero, "%d", i);
            for (j = 0; j < strlen(numero); j++)
            {
                for (k = j + 1; k < strlen(numero); k++)
                {
                    if (numero[j] == numero[k])
                    {
                        achou = 1;
                        break;
                    }
                }
            }
            if (achou)
            {
                iguais++;
                achou = 0;
            }
        }
        free(numero);
        printf("%d\n", m + 1 - n - iguais);
        iguais = 0;
    }
    return 0;
}
