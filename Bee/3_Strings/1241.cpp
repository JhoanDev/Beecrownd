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
    int tests, i, j, tamstr2, tamstr1, pointer;
    cin >> tests;
    string str1, str2;
    bool combina;
    for (i = 0; i < tests; i++)
    {
        combina = true;
        cin >> str1 >> str2;
        tamstr1 = str1.length();
        tamstr2 = str2.length();
        pointer = tamstr1 - tamstr2;
        for (j = 0; j < tamstr2; j++)
        {
            if (str1[pointer] != str2[j])
            {
                combina = false;
                break;
            }
            pointer++;
        }
        cout << (combina ? "encaixa" : "nao encaixa") << endl;
    }
    return 0;
}
