#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main()
{
    _
    int number, qnt, i;
    char foot;
    while (cin >> qnt)
    {
        vector<int> dir(31, 0);
        vector<int> esq(31, 0);
        int res = 0;
        for (i = 0; i < qnt; i++)
        {
            cin >> number >> foot;
            if (foot == 'D')
                dir[number - 30]++;
            else
                esq[number - 30]++;
        }
        for (i = 0; i < 31; i++)
        {
            if (dir[i] < esq[i])
                res += dir[i];
            else
                res += esq[i];
        }
        cout << res << endl;
    }
    return 0;
}