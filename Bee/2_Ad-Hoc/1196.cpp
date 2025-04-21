#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _
        unordered_map<char, char>
            remapear;
    remapear['1'] = '`';
    remapear['2'] = '1';
    remapear['3'] = '2';
    remapear['4'] = '3';
    remapear['5'] = '4';
    remapear['6'] = '5';
    remapear['7'] = '6';
    remapear['8'] = '7';
    remapear['9'] = '8';
    remapear['0'] = '9';
    remapear['-'] = '0';
    remapear['='] = '-';

    remapear['W'] = 'Q';
    remapear['E'] = 'W';
    remapear['R'] = 'E';
    remapear['T'] = 'R';
    remapear['Y'] = 'T';
    remapear['U'] = 'Y';
    remapear['I'] = 'U';
    remapear['O'] = 'I';
    remapear['P'] = 'O';
    remapear['['] = 'P';
    remapear[']'] = '[';
    remapear['\\'] = ']';

    remapear['S'] = 'A';
    remapear['D'] = 'S';
    remapear['F'] = 'D';
    remapear['G'] = 'F';
    remapear['H'] = 'G';
    remapear['J'] = 'H';
    remapear['K'] = 'J';
    remapear['L'] = 'K';
    remapear[';'] = 'L';
    remapear['\''] = ';';

    remapear['X'] = 'Z';
    remapear['C'] = 'X';
    remapear['V'] = 'C';
    remapear['B'] = 'V';
    remapear['N'] = 'B';
    remapear['M'] = 'N';
    remapear[','] = 'M';
    remapear['.'] = ',';
    remapear['/'] = '.';

    string entrada;
    while (getline(cin, entrada))
    {
        string saida = "";

        for (int i = 0; i < entrada.size(); i++)
        {
            if (entrada[i] == ' ')
                saida += ' ';
            else
                saida += remapear[entrada[i]];
        }

        cout << saida << endl;
    }

    return 0;
}