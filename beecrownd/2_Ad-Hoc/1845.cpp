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

int main()
{
    _
        string minusculas = "jpsxvbfz";
    string maiusculas = "JPSXVBFZ";
    string linha;
    bool repetido = false;
    int i;

    while (getline(cin, linha))
    {
        repetido = false;
        for (auto car : linha)
        {
            if ((minusculas.find(car) != string::npos) && !repetido)
            {
                cout << "f";
                repetido = true;
            }
            else if ((maiusculas.find(car) != string::npos) && !repetido)
            {
                cout << "F";
                repetido = true;
            }
            else if ((minusculas.find(car) == string::npos) && (maiusculas.find(car) == string::npos))
            {
                repetido = false;
                cout << car;
            }
        }
        cout << endl;
    }

    return 0;
}
