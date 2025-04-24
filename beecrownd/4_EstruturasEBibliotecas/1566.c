#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testes, i, j;
    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        int *alturas = (int *)calloc(212, sizeof(int));
        int pessoas;
        int temp;
        int bolean = 1;
        scanf("%d", &pessoas);
        for (j = 0; j < pessoas; j++)
        {
            scanf("%d", &temp);
            alturas[temp - 20]++;
        }
        for (j = 0; j <= 210; j++)
        {
            if (alturas[j] > 0)
            {
                while (alturas[j] != 0)
                {
                    if (bolean)
                    {
                        printf("%d", j + 20);
                        bolean = 0;
                    }
                    else
                    {
                        printf(" %d", j + 20);
                    }
                    alturas[j]--;
                }
            }
        }
        printf("\n");
        free(alturas);
    }
    return 0;
}