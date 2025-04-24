#include <stdio.h>
#include <string.h>

int diamantes(char *exp){
    int abertos = 0;
    int diamantes = 0;
    int tamanho = strlen(exp);
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (exp[i] == '<')
            abertos++;
        if (exp[i] == '>')
        {
            if (abertos != 0){
                diamantes++;
                abertos--;
            }
        }
    }
    return diamantes;
}

int main()
{
    char minerar[1001];
    int testes;
    scanf(" %d",&testes);
    for (int i = 0; i < testes; i++)
    {
        scanf(" %[^\n]s", minerar);
        printf("%d\n", diamantes(minerar));
    }
    
    return 0;
}
