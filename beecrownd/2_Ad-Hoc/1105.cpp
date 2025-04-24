#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    int ban, div, i;
    int devedor, crediario, money;
    while (true)
    {
        cin >> ban >> div;
        if (ban == 0 && div == 0)
            break;
        int vet[ban];
        for (i = 0; i < ban; i++)
        {
            cin >> vet[i];
        }
        for (i = 0; i < div; i++)
        {
            cin >> devedor >> crediario >> money;
            vet[crediario - 1] += money;
            vet[devedor - 1] -= money;
        }
        bool x1 = true;
        for (i = 0; i < ban; i++)
        {
            if (vet[i] < 0)
            {
                x1 = false;
                break;
            }
        }
        cout << (x1 ? "S" : "N") << endl;
    }
    return 0;
}