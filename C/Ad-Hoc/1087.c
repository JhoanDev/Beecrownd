#include <stdio.h>

int main()
{
    int DX, DY, TX, TY;
    while (1)
    {
        int movimentos = 2;
        scanf(" %d %d %d %d", &DX, &DY, &TX, &TY);
        if (DX == 0 && DY == 0 && TX == 0 && TY == 0)
            break;
        if (DX == TX && DY == TY)
            movimentos = 0;
        else if (DX == TX || DY == TY)
            movimentos = 1;
        else
        {
            for (int i = 1; i <= 8; i++)
            {
                if ((DX - i) == TX && (DY + i) == TY)
                {
                    movimentos = 1;
                }
                else if ((DX + i) == TX && (DY - i) == TY)
                {
                    movimentos = 1;
                }
                else if ((DX + i) == TX && (DY + i) == TY)
                {
                    movimentos = 1;
                }
                else if ((DX - i) == TX && (DY - i) == TY)
                {
                    movimentos = 1;
                }
            }
        }
        printf("%d\n", movimentos);
    }
    return 0;
}
