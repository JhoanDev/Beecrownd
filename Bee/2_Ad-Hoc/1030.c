#include <stdio.h>

int main()
{
    int nc = 0, i = 0, qnt = 0, salto = 0, j = 0,cases = 0;
    scanf("%d", &nc);
    for (i = 0; i < nc; i++)
    {
        scanf("%d %d", &qnt, &salto);
        int sobrevivente = 0;
        for (j = 2; j < qnt + 1; j++)
        {
            sobrevivente = (sobrevivente + salto) % j;
        }
        cases++;
        printf("Case %d: %d\n",cases,sobrevivente+1);
    }

    return 0;
}