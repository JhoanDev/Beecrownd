#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main()
{
    _
    int vet[10], casos, i, j, leds = 0;
    cin >> casos;
    vet[0] = 6;
    vet[1] = 2;
    vet[2] = 5;
    vet[3] = 5;
    vet[4] = 4;
    vet[5] = 5;
    vet[6] = 6;
    vet[7] = 3;
    vet[8] = 7;
    vet[9] = 6;
    string entrada;
    for (i = 0; i < casos; i++)
    {
        cin >> entrada;
        leds = 0;
        for (j = 0; j < entrada.length(); j++)
        {
            leds += vet[entrada[j] - '0'];
        }
        cout << leds << " leds" << endl;
    }
    
    return 0;
}