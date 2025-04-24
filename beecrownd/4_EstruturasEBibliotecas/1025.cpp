#include <iostream>
#include <map>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ 
    int numeros, consultas, i, j, target, result, cases = 0, aux;
    while (true)
    {
        cin >> numeros >> consultas;
        if (numeros == 0 && consultas == 0)
            break;
        map<int, int> mapa;
        for (i = 0; i < numeros; i++)
        {
            cin >> aux;
            mapa[aux]++;
        }
        cout << "CASE# " << ++cases << ":" << endl;
        for (i = 0; i < consultas; i++)
        {
            cin >> target;
            if (mapa.count(target) == 0)
            {
                cout << target << " not found" << endl;
            }
            else
            {
                result = 1;
                for (const auto &pair : mapa)
                {
                    if (pair.first == target)
                    {
                        break;
                    }
                    else
                    {
                        result += pair.second;
                    }
                }
                cout << target << " found at " << result << endl;
            }
        }
    }

    return 0;
}