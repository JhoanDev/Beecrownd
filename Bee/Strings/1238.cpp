#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _
    int cases, i, j, k;
    cin >> cases;
    for (i = 0; i < cases; i++)
    {
        string str1, str2, resultado = "";
        cin >> str1 >> str2;
        int tamstr1 = str1.length(), tamstr2 = str2.length();
        j = 0;
        k = 0;
        if (tamstr1 > tamstr2)
        {
            for (j = 0; j < tamstr1; j++)
            {
                resultado += str1[j];
                if (k < tamstr2)
                {
                    resultado += str2[k];
                    k++;
                }
            }
        }
        else
        {
            for (j = 0; j < tamstr2; j++)
            {
                if (k < tamstr1)
                {
                    resultado += str1[k];
                    k++;
                }
                resultado += str2[j];
            }
        }
        cout << resultado << endl;
    }

    return 0;
}