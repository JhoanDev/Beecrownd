#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef unsigned long long llu;
typedef unsigned int ui;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _ int qnt, sorteado, i;
    cin >> qnt >> sorteado;
    multiset<string> nomes;
    string aux;
    for (i = 0; i < qnt; i++)
    {
        cin >> aux;
        nomes.insert(aux);
    }
    vector<string> nomes_vec(nomes.begin(), nomes.end());

    cout << nomes_vec[sorteado - 1] << endl;

    return 0;
}