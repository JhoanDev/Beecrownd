#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int linhas, colunas, i, j, costas = 0;
    scanf("%d %d", &linhas, &colunas);

    char **mat = (char **)malloc(linhas * sizeof(char *));
    if (mat == NULL)
        exit(1);
    for (i = 0; i < linhas; i++)
    {
        mat[i] = (char *)malloc(colunas * sizeof(char));
        if (mat[i] == NULL)
            exit(1);
    }
    for (i = 0; i < linhas; i++)
    {
        scanf("%s", mat[i]);
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (mat[i][j] == '#')
            {
                if (j == 0 || i == 0 || (i == linhas - 1 && j != 0) || (j == colunas - 1 && i != 0 && i != linhas - 1))
                {
                    costas++;
                }
                else if (mat[i - 1][j] == '.' || mat[i + 1][j] == '.' || mat[i][j + 1] == '.' || mat[i][j - 1] == '.')
                {
                    costas++;
                }
            }
        }
    }
    printf("%d\n", costas);
    return 0;
}