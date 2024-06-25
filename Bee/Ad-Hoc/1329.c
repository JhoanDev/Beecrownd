#include <stdio.h>

int main(){
    int n,i;
    while (1)
    {   
        scanf("%d",&n);
        if (n ==0)
        {
            break;
        }
        int mary=0,john=0;
        int vet[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d",&vet[i]);
        }
        for (i = 0; i < n; i++)
        {
            if (vet[i] == 0)
            {
                mary++;
            }
            else{
                john++;
            }
        }
        printf("Mary won %d times and John won %d times\n",mary,john);
    }
    return 0;
}