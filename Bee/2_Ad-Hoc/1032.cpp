#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

#define max 3501

void preenche_primos(vector<int> &primos)
{
    int i = 2, j, count = 1;
    int squareroot = 0;
    int primo = 0;
    primos[0] = 2;
    while (count < max)
    {

        squareroot = (int)sqrt((double)i) + 1;
        primo = 1;
        for (j = 2; j <= squareroot; j++)
        {
            if (i % j == 0)
            {
                primo = 0;
                break;
            }
        }
        if (primo)
            primos[count++] = i;
        i++;
    }
}

int main()
{
    _
    vector<int> primos(max, 0);
    preenche_primos(primos);
    int i;
    int n;

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<int> pessoas(n);
        iota(pessoas.begin(), pessoas.end(), 1);
        int iterador = 0;
        int tamanho_atual = n;

        for (i = 0; i < n-1; i++)
        {
            iterador = (iterador+(primos[i]-1)) % tamanho_atual;
            pessoas.erase(pessoas.begin() + iterador);
            tamanho_atual--;
        }
        cout << pessoas[0] << endl;

    }
    return 0;
}