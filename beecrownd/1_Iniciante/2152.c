#include <stdio.h>

int main()
{

    int testes;
    scanf("%d", &testes);
    int hora, minutos, abriu;
    for (int i = 0; i < testes; i++)
    {
        scanf("%d %d %d", &hora, &minutos, &abriu);
        if (abriu)
        {
            if (hora < 10 && minutos < 10)
            {
                printf("0%d:0%d - A porta abriu!\n", hora, minutos);
            }
            else if (hora < 10)
            {
                printf("0%d:%d - A porta abriu!\n", hora, minutos);
            }

            else if (minutos < 10)
            {
                printf("%d:0%d - A porta abriu!\n", hora, minutos);
            }
            else
            {
                printf("%d:%d - A porta abriu!\n", hora, minutos);
            }
        }

        else
        {
            if (hora < 10 && minutos < 10)
            {
                printf("0%d:0%d - A porta fechou!\n", hora, minutos);
            }
            else if (hora < 10)
            {
                printf("0%d:%d - A porta fechou!\n", hora, minutos);
            }

            else if (minutos < 10)
            {
                printf("%d:0%d - A porta fechou!\n", hora, minutos);
            }
            else
            {
                printf("%d:%d - A porta fechou!\n", hora, minutos);
            }
        }
    }

    return 0;
}