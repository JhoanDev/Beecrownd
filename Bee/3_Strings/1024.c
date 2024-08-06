#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int testes, i;
    int j, k;
    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        char *string = (char *)malloc(1010 * sizeof(char));
        scanf(" %[^\n]", string);
        int tamanho = strlen(string);
        int metade = tamanho / 2;
        char aux;
        for (j = 0; j < tamanho; j++)
        {
            if (isupper(string[j]) || islower(string[j]))
            {
                string[j] = string[j] + 3;
            }
        }
        k = tamanho - 1;
        for (j = 0; j < metade; j++)
        {
            aux = string[j];
            string[j] = string[k];
            string[k] = aux;
            k--;
        }
        for (j = metade; j < tamanho; j++)
        {
            string[j] = string[j] - 1;
        }
        printf("%s\n", string);
    }
    return 0;
}
