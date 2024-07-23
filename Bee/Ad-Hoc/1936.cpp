#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main()
{
    _
    vector<int> fat(11);
    int i, n, res = 0, temp;
    cin >> n;
    fat[0] = 1;
    for (i = 1; i <= 10; i++)
    {
        fat[i] = fat[i - 1] * i;
    }
    for (i = 10; i > 0; i--)
    {
        temp = n / fat[i];
        res +=  temp;
        n -= temp * fat[i];
    }
    cout << res << endl;
    return 0;
}