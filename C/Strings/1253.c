#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define alfabeto "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void imprime_texto_decodificado(char *criptografada, int posicoes)
{
    int i,j,posatual;
    int posicaoreal;
    int tamanho = strlen(criptografada);
    char *decodificada = (char *)malloc((tamanho+1) * sizeof(char));

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (criptografada[i] == alfabeto[j])
            {
                posatual = j;
                break;
            }
        }
        posicaoreal = ((posatual-posicoes+26)%26);
        decodificada[i] = alfabeto[posicaoreal];
    }
    decodificada[tamanho] = '\0';
    printf("%s\n",decodificada);
    free(decodificada);
}

int main()
{
    int testes, i;
    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        int posicoes;
        char *criptografada = (char *)malloc(51 * sizeof(char));
        scanf(" %[^\n]", criptografada);
        scanf("%d",&posicoes);
        imprime_texto_decodificado(criptografada, posicoes);
        free(criptografada);
    }
    return 0;
}
