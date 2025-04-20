#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define MAX 5

void verifica(int vet[])
{
    int i;
    int nao_crescente = 0, nao_decrescente = 0;
    for (i = 1; i < MAX; i++)
    {
        if (vet[i - 1] > vet[i])
            nao_crescente = 1;
    }
    for (i = 1; i < MAX; i++)
    {
        if (vet[i - 1] < vet[i])
            nao_decrescente = 1;
    }

    if (nao_crescente && nao_decrescente)
        cout << "N" << endl;
    else if (nao_crescente)
        cout << "D" << endl;
    else
        cout << "C" << endl;
}

int main()
{
    _
    int vet[MAX];
    cin >> vet[0] >> vet[1] >> vet[2] >> vet[3] >> vet[4];
    verifica(vet);
    return 0;
}