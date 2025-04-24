#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double RC, XC, YC, RF, XF, YF, DIST;

    while (scanf("%lf %lf %lf %lf %lf %lf", &RC, &XC, &YC, &RF, &XF, &YF) != EOF)
    {
        abs(RC);
        abs(XC);
        abs(YC);
        abs(RF);
        abs(XF);
        abs(YF);
        DIST = sqrt(((XF-XC)*(XF-XC))+((YF-YC)*(YF-YC)));
        if (RC >= (DIST + RF))
            printf("RICO\n");
        else
            printf("MORTO\n");
    }

    return 0;
}
