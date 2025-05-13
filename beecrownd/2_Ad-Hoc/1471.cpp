#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    int mergulhadores, sobreviventes, i, aux;

    while (cin >> mergulhadores >> sobreviventes)
    {
        set<int> morreram;
        string saida = "";
        for (i = 0; i < sobreviventes; i++)
        {
            cin >> aux;
            morreram.insert(aux);
        }
        for (i = 1; i <= mergulhadores; i++)
        {
            if (morreram.find(i) == morreram.end())
                saida += to_string(i) + " ";
        }
        if (saida.length() == 0)
            saida = "*";
        cout << saida << endl;
    }

    return 0;
}