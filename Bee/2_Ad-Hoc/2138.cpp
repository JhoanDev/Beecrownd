#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ int i;
    string s;
    vector<int> contador(10, 0);
    int maior, max;
    while (cin >> s)
    {
        for (i = 0; i < s.length(); i++)
        {
            contador[s[i] - '0']++;
        }
        maior = 0;
        max = contador[0];
        for (i = 1; i < 10; i++)
        {
            if (max <= contador[i])
            {
                maior = i;
                max = contador[i];
            }
        }
        cout << maior << endl;
        fill(contador.begin(), contador.end(), 0);
    }

    return 0;
}