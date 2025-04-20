#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ 
    int n,m,i;
    int prejuizo = 0;
    vector<int> vet(1001,0);
    while (cin >> n >> m)
    {
        for (i = 0; i < n; i++)
        {
            cin >> vet[i];
        }

        for (i = 0; i < m; i++)
        {
            prejuizo += vet[n-i -1];
        }
        
        cout << prejuizo << endl;
        prejuizo = 0;
    }
    

    return 0;
}