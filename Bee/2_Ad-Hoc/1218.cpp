#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _
    int target;
    int num_aux;
    char sex_aux;
    int caso = 1;
    
    while (cin >> target)
    {
        if (caso != 1)
            cout << endl;

        int qnt_masc = 0, qnt_fem = 0;
        string line;
        
        cin.ignore();
        getline(cin, line);  
        
        istringstream ss(line);
        
        while (ss >> num_aux >> sex_aux)  
        {
            if (num_aux == target)
            {
                if (sex_aux == 'F') 
                    qnt_fem++;
                else 
                    qnt_masc++;
            }
        }

        cout << "Caso " << caso++ << ":" << endl;
        cout << "Pares Iguais: " << qnt_fem + qnt_masc << endl;
        cout << "F: " << qnt_fem << endl;
        cout << "M: " << qnt_masc << endl;
    }

    return 0;
}
