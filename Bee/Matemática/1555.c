#include <stdio.h>
#include <math.h>

double rafael(int x, int y);
double beto(int x, int y);
double carlos(int x, int y);
double max(double a, double b);
double max3(double a, double b, double c);

int main()
{
    int casos, x, y;
    double resultadorafael, resultadobeto, resultadocarlos;
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++)
    {
        scanf("%d %d", &x, &y);
        resultadorafael = rafael(x, y);
        resultadobeto = beto(x, y);
        resultadocarlos = carlos(x, y);
        if (max3(resultadorafael, resultadobeto, resultadocarlos) == resultadorafael)
            printf("Rafael ganhou\n");
        else if (max3(resultadorafael, resultadobeto, resultadocarlos) == resultadocarlos)
            printf("Carlos ganhou\n");
        else if (max3(resultadorafael, resultadobeto, resultadocarlos) == resultadobeto)
            printf("Beto ganhou\n");
    }
    return 0;
}

double rafael(int x, int y)
{
    return pow((3 * x), 2) + pow(y, 2);
}

double beto(int x, int y)
{
    return 2 * pow(x, 2) + pow((5 * y), 2);
}

double carlos(int x, int y)
{
    return -100 * x + pow(y, 3);
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

double max3(double a, double b, double c)
{
    double aux = max(a, b);

    return max(aux, c);
}