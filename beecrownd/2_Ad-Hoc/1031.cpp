#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    //_
    int n;
    while (cin >> n && n != 0)
    {
        int m;
        for (m = 1;; m++)
        {
            vector<bool> desligados(n + 1, false);
            int pos = 1;

            for (int desligados_count = 1; desligados_count < n; desligados_count++)
            {
                desligados[pos] = true;
                int passos = 0;

                while (passos < m)
                {
                    pos++;
                    if (pos > n) pos = 1;
                    if (!desligados[pos])
                        passos++;
                }
            }

            if (!desligados[13]) 
                break;
        }
        cout << m << endl;
    }

    return 0;
}
