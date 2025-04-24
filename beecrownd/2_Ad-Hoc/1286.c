#include <stdio.h>
#include <stdlib.h>

typedef struct entregas
{
    int pizza;
    int tempo;
} Entregas;

int maior(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int i, j, quantidade, pizzas_max;

    while (1)
    {
        scanf("%d", &quantidade);
        if (quantidade == 0)
        {
            break;
        }

        scanf("%d", &pizzas_max);

        Entregas *entregas = (Entregas *)malloc(quantidade * sizeof(Entregas));

        for (i = 0; i < quantidade; i++)
        {
            scanf("%d %d", &entregas[i].tempo, &entregas[i].pizza);
        }

        int mat[quantidade + 1][pizzas_max + 1];

        for (i = 0; i <= quantidade; i++)
        {
            for (j = 0; j <= pizzas_max; j++)
            {
                if (i == 0 || j == 0)
                {
                    mat[i][j] = 0;
                }
                else if (entregas[i - 1].pizza > j)
                {
                    mat[i][j] = mat[i - 1][j];
                }
                else
                {
                    mat[i][j] = maior(mat[i - 1][j], mat[i - 1][j - entregas[i - 1].pizza] + entregas[i - 1].tempo);
                }
            }
        }
        printf("%d min.\n", mat[quantidade][pizzas_max]);

        free(entregas);
    }

    return 0;
}

/*

3 -> quantidade de entregas
5 -> quantidade max de pizzas

---- entregas ---
[0] -> 15 2
[1] -> 23 3
[2] -> 21 2

 0  1  2   3   4   5
[0][0][0] [0] [0] [0]
[0][0][15][15][15][15]
[0][0][15][23][23][38]
[0][0][21][21][36][44]
*/