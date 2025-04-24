#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second

bool aux_compara(pair<int, int> a, pair<int, int> b)
{
    if (a.s != b.s)
        return a.s < b.s;
    return a.f > b.f;
}

int main()
{
    _
    int i, caso = 0;
    string entrada;
    while (getline(cin, entrada))
    {
        if (caso++)
            cout << endl;
        unordered_map<char, int> frequencias;
        for (char caracter : entrada)
        {
            frequencias[caracter]++;
        }

        vector<pair<int, int>> frequencias_ordenadas;

        for (auto aux : frequencias)
        {
            frequencias_ordenadas.push_back(make_pair(aux.first, aux.second));
        }

        sort(frequencias_ordenadas.begin(), frequencias_ordenadas.end(), aux_compara);

        for (auto aux : frequencias_ordenadas)
        {
            cout << aux.first << " " << aux.second << endl;
        }
    }

    return 0;
}