#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main()
{
    _
    set<string> jewel;
    string aux;
    while (cin >> aux)
    {
        jewel.insert(aux);
    }
    cout << jewel.size() << endl;
    return 0;
}