#include <iostream>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ int i;
    string entrada;
    char caracter_erro;
    bool nao_e_zero = false;
    while (true)
    {
        bool nao_e_zero = false;
        cin >> caracter_erro >> entrada;
        if (caracter_erro == '0' && entrada == "0")
            break;
        int tam = entrada.length();
        for (i = 0; i < tam; i++)
        {
            if (entrada[i] != caracter_erro && entrada[i] != '0')
            {
                nao_e_zero = true;
                break;
            }
        }
        if (!nao_e_zero)
        {
            cout << "0" << endl;
        }
        else
        {
            for (i = i; i < tam; i++)
            {
                if (entrada[i] != caracter_erro)
                {
                    cout << entrada[i];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
