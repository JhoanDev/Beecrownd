#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    unsigned long long int sum;
    int cases, rows, i ,j;
    scanf("%d", &cases);
    for (i = 0; i < cases; i++)
    {
        sum = 0;
        scanf("%d", &rows);
        for (j = 0; j < rows; j++)
        {
            sum += pow(2,j);
        }
        printf("%llu\n", sum);
    }
     
    return 0;
}