#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numdias, i, custodia, lucro, j, k, custo, receita;
    while (scanf("%d", &numdias) != EOF)
    {
        scanf("%d", &custodia);
        int receitas[numdias];
        for (i = 0; i < numdias; i++)
        {
            scanf("%d", &receitas[i]);
        }
        int lucromax = 0;
        for (i = 0; i < numdias; i++)
        {
            for (k = 0; k < numdias; k++)
            {
                receita = 0;
                custo = 0;
                for (j = i; j <= k; j++)
                {
                    receita += receitas[j];
                    custo += custodia;
                }
                lucro = receita - custo;
                if (lucro > lucromax)
                    lucromax = lucro;
            }
        }
        printf("%d\n",lucromax);
    }
}