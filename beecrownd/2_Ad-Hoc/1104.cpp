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
    _ int a, b, aux, i, tam_a, tam_b;
    while ((cin >> a >> b) && a != 0 && b != 0)
    {
        set<int> cards_a;
        set<int> cards_b;
        for (i = 0; i < a; i++)
        {
            cin >> aux;
            cards_a.insert(aux);
        }
        for (i = 0; i < b; i++)
        {
            cin >> aux;
            cards_b.insert(aux);
        }
        tam_a = tam_b = 0;
        for (auto card : cards_a)
        {
            if (cards_b.find(card) == cards_b.end())
                tam_a++;
        }
        for (auto card : cards_b)
        {
            if (cards_a.find(card) == cards_a.end())
                tam_b++;
        }

        (tam_a > tam_b) ? (cout << tam_b << endl) : (cout << tam_a << endl);
    }

    return 0;
}