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

int sacos, comedores, pipocas_por_segundo, i, j;
ll max_pipocas = 0;

bool possivel(ll m, vector<int> pipocas)
{
    int comp = 1;
    ll resta = pipocas_por_segundo * m;

    for (i = 0; i < sacos; i++)
    {
        if (resta >= pipocas[i])
            resta -= pipocas[i];
        else
        {
            comp++;
            resta = pipocas_por_segundo * m;
            i--;
        }

        if (comp > comedores)
            return false;
    }
    return true;
}

int main()
{
    _

    cin >> sacos >> comedores >> pipocas_por_segundo;
    vector<int> pipocas(sacos, 0);
    for (i = 0; i < sacos; i++)
    {
        cin >> pipocas[i];
        max_pipocas += pipocas[i];
    }

    ll limite_superior, limite_inferior;
    limite_superior = max_pipocas / pipocas_por_segundo + 1;
    limite_inferior = 0;

    while (limite_superior > limite_inferior)
    {
        int m = (limite_inferior + limite_superior) / 2;

        if (!possivel(m, pipocas))
            limite_inferior = m + 1;
        else
            limite_superior = m;
    }
    cout << limite_inferior << endl;

    return 0;
}