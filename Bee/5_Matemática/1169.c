#include <stdio.h>
#include <math.h>

int main (){
    int testes;
    scanf("%d", &testes);
    for (int i = 0; i < testes; i++)
    {
        int tabuleiros;
        scanf("%d",&tabuleiros);
        unsigned long long graos = 0;
        for (int j = 0; j < tabuleiros; j++)
        {
            graos += pow(2,j)/12;
        }
        unsigned long long int kg = graos/1000;
        printf("%llu kg\n",kg);
    }
    return 0;
}