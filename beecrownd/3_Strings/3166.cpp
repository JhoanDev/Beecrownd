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

int verifica_palavra(vector<vector<char>> &matriz, string target, int linhas, int colunas)
{
    int tam_target = target.length();
    int certas = 0;
    int mi = min(linhas, colunas);
    int i, j;
    int lin, col;

    string diagonal;

    for (i = 0; i < mi; i++)

    {
        diagonal.push_back(matriz[i][i]);
    }

    if (diagonal.find(target) != string::npos)
        return 1;
    reverse(diagonal.begin(), diagonal.end());
    if (diagonal.find(target) != string::npos)
        return 1;
    diagonal.clear();

    for (lin = 1; lin < linhas; lin++)
    {
        i = lin, j = 0;
        while (i < linhas && j < colunas)
        {
            diagonal.push_back(matriz[i++][j++]);
        }
        if (diagonal.find(target) != string::npos)
            return 3;
        reverse(diagonal.begin(), diagonal.end());
        if (diagonal.find(target) != string::npos)
            return 3;
        diagonal.clear();
    }
    for (col = 1; col < colunas; col++)
    {
        i = 0, j = col;
        while (i < linhas && j < colunas)
        {
            diagonal.push_back(matriz[i++][j++]);
        }
        if (diagonal.find(target) != string::npos)
            return 2;
        reverse(diagonal.begin(), diagonal.end());
        if (diagonal.find(target) != string::npos)
            return 2;
        diagonal.clear();
    }
    return 4;
}

int main()
{
    _
    int n, m, p, i, j;
    string aux;
    cin >> n >> m >> p;
    vector<vector<char>> matriz(m, vector<char>(p));
    vector<string> palavras(n);
    for (i = 0; i < n; i++)
    {
        cin >> palavras[i];
        transform(palavras[i].begin(), palavras[i].end(), palavras[i].begin(),
                  [](unsigned char c)
                  { return tolower(c); });
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            cin >> matriz[i][j];
            matriz[i][j] = tolower(matriz[i][j]);
        }
    }

    int res;
    for (i = 0; i < n; i++)
    {
        res = verifica_palavra(matriz, palavras.at(i), m, p);

        if (res == 1)
            cout << res << " Palavra \"" << palavras.at(i) << "\" na diagonal principal" << endl;
        else if (res == 2)
            cout << res << " Palavra \"" << palavras.at(i) << "\" acima da diagonal principal" << endl;
        else if (res == 3)
            cout << res << " Palavra \"" << palavras.at(i) << "\" abaixo da diagonal principal" << endl;
        else
            cout << res << " Palavra \"" << palavras.at(i) << "\" inexistente" << endl;
    }

    return 0;
}