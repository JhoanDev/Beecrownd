#include <stdio.h>

int main()
{
    int n = 0, res = 0, ult = -1, atual = 0, i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &atual);
        if (atual != ult)
        {
            res++;
        }
        ult = atual;
    }
    printf("%d\n", res);
    return 0;
}