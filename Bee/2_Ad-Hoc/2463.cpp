#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main()
{
    _
    int soma_ant = -9999999;
    int maior = -9999999;
    int cont = 0, i;
    cin >> cont;
    int vet[cont];
    for (i = 0; i < cont; i++)
    {
        cin >> vet[i];
    }
    for (i = 0; i < cont; i++)
    {
        if (soma_ant < 0)
        {
            soma_ant = vet[i];
        }
        else
        {
            soma_ant += vet[i];
        }
        if (maior <= soma_ant)
            maior = soma_ant;
    }
    cout << maior << endl;
    return 0;
}