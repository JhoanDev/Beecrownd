#include <bits/stdc++.h>
#include <cctype>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _
    int i, j, k;
    vector<string> vet;
    string aux;
    bool troca_case = true;

    while (getline(cin, aux) && aux != "pare")
    {
        vet.push_back(aux);
    }

    for (i = 0; i < vet.size(); i++)
    {
        troca_case = true;
        for (j = 0; j < vet[i].length(); j++)
        {
            if (vet[i][j] != ' ')
            {
                if (troca_case)
                {
                    vet[i][j] = toupper(vet[i][j]);
                    troca_case = false;
                }
                else
                {
                    vet[i][j] = tolower(vet[i][j]);
                    troca_case = true;
                }
            }
        }
    }
    for (const auto &str : vet)
    {
        cout << str << endl;
    }

    return 0;
}
