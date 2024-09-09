#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    int p1, p2;
    cin >> p1 >> p2;
    if (p2 >= 0 && p2 <= 2)
    {
        cout << "nova" << endl;
    }
    else if (p2 >= 97 && p2 <= 100)
    {
        cout << "cheia" << endl;
    }
    else if (p2 <= 96 && p2 >= 3)
    {
        if (p1 > p2)
        {
            cout << "minguante" << endl;
        }
        else if (p2 > p1)
        {
            cout << "crescente" << endl;
        }
    }

    return 0;
}