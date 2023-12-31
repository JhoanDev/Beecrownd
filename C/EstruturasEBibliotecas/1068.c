#include <stdio.h>
#include <string.h>

int verifica(char *exp)
{
    int abertos = 0;
    int tamanho = strlen(exp);
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (exp[i] == '(')
            abertos++;
        if (exp[i] == ')')
        {
            if (abertos == 0)
                return 0;
            abertos--;
        }
    }
    if (abertos != 0)
        return 0;
    return 1;
}

int main()
{
    char expressao[1001];
    while (scanf(" %[^\n]s", expressao) != EOF)
    {
        printf("%s\n", verifica(expressao) ? "correct" : "incorrect");
    }
    return 0;
}
