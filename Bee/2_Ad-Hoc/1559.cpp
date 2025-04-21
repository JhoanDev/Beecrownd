#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

#define ordem_matriz 4

void quais_possiveis(int matriz[ordem_matriz][ordem_matriz])
{
    int i, j;

    int nenhum_possivel = 0;
    string saida;

    for (i = 0; i < ordem_matriz; i++)
    {
        for (j = 0; j < ordem_matriz; j++)
        {
            if(matriz[i][j] == 2048) goto final;
        }
    }
    

    // teste baixo
    for (i = 0; i < ordem_matriz - 1; i++)
    {
        for (j = 0; j < ordem_matriz; j++)
        {
            if (matriz[i][j] != 0 && (matriz[i + 1][j] == 0 || matriz[i + 1][j] == matriz[i][j]))
            {
                nenhum_possivel = 1;
                saida += "DOWN";
                break;
            }
        }
        if (nenhum_possivel == 1)
            break;
    }

    // teste esquerda
    for (i = 0; i < ordem_matriz; i++)
    {
        for (j = 3; j > 0; j--)
        {
            if (matriz[i][j] != 0 && (matriz[i][j - 1] == 0 || matriz[i][j - 1] == matriz[i][j]))
            {
                nenhum_possivel = 2;
                if (saida.size() > 1)
                {
                    saida += ' ';
                }
                saida += "LEFT";
                break;
            }
        }
        if (nenhum_possivel == 2)
            break;
    }

    // teste direita
    for (i = 0; i < ordem_matriz; i++)
    {
        for (j = 0; j < ordem_matriz - 1; j++)
        {
            if (matriz[i][j] != 0 && (matriz[i][j + 1] == 0 || matriz[i][j + 1] == matriz[i][j]))
            {
                nenhum_possivel = 3;
                if (saida.size() > 1)
                {
                    saida += ' ';
                }
                saida += "RIGHT";
                break;
            }
        }
        if (nenhum_possivel == 3)
            break;
    }

    // teste cima
    for (i = 3; i > 0; i--)
    {
        for (j = 0; j < ordem_matriz; j++)
        {
            if (matriz[i][j] != 0 && (matriz[i - 1][j] == 0 || matriz[i - 1][j] == matriz[i][j]))
            {
                nenhum_possivel = 4;
                if (saida.size() > 1)
                {
                    saida += ' ';
                }
                saida += "UP";
                break;
            }
        }
        if (nenhum_possivel == 4)
            break;
    }

    final:
    nenhum_possivel ? (cout << saida << endl) : (cout << "NONE" << endl);
}

int main()
{
    _ int matriz[ordem_matriz][ordem_matriz];
    int testes, i, j, k;
    cin >> testes;
    for (k = 0; k < testes; k++)
    {
        for (i = 0; i < ordem_matriz; i++)
        {
            for (j = 0; j < ordem_matriz; j++)
            {
                cin >> matriz[i][j];
            }
        }
        quais_possiveis(matriz);
    }

    return 0;
}