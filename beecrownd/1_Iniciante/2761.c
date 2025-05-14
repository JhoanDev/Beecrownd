#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, i, dif;
    float b;
    char c;
    char d[50];

    scanf("%d %f %c %[^\n]", &a, &b, &c, d);
    printf("%d%.6f%c%s\n", a, b, c, d);
    printf("%d\t%.6f\t%c\t%s\n", a, b, c, d);

    char aux[11];

    sprintf(aux, "%d", a);
    dif = 10 - strlen(aux);
    for (i = 0; i < dif; i++)
        printf(" ");
    printf("%d", a);

    sprintf(aux, "%.6f", b);
    dif = 10 - strlen(aux);
    for (i = 0; i < dif; i++)
        printf(" ");
    printf("%.6f", b);

    printf("         %c", c);

    dif = 10 - strlen(d);
    for (i = 0; i < dif; i++)
        printf(" ");

    printf("%s\n", d);

    return 0;
}