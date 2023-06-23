#include <stdio.h>

typedef struct ponto
{
    int vertical;
    int horizontal;
} Ponto;

int main()
{
    int k = 0, i = 0;
    while (1)
    {
        scanf("%d", &k);
        if (k == 0)
            break;
        Ponto divisor, ponto;
        scanf("%d %d", &divisor.vertical, &divisor.horizontal);
        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &ponto.vertical, &ponto.horizontal);
            if (divisor.vertical == ponto.vertical || ponto.horizontal == divisor.horizontal)
                printf("divisa\n");
            else if (ponto.vertical > divisor.vertical)
            {
                if (ponto.horizontal > divisor.horizontal)
                    printf("NE\n");
                else
                    printf("SE\n");
            }
            else
            {
                if (ponto.horizontal > divisor.horizontal)
                    printf("NO\n");
                else
                    printf("SO\n");
            }
        }
    }
}