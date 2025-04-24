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
    int n, i;
    cin >> n;
    cin.ignore();

    double kg_tot = 0, valor_tot = 0, valor_at = 0;
    string line;
    int kg_atual;
    for (i = 0; i < n; i++)
    {
        cin >> valor_at;
        valor_tot += valor_at;
        cin.ignore();

        getline(cin, line);
        kg_atual = count(line.begin(), line.end(), ' ') + 1;

        cout << "day " << i + 1 << ": " << kg_atual << " kg" << endl;

        kg_tot += kg_atual;
    }

    cout << fixed << setprecision(2);
    cout << (kg_tot / n) << " kg by day" << endl;
    cout << "R$ " << (valor_tot / n) << " by day" << endl;

    return 0;
}