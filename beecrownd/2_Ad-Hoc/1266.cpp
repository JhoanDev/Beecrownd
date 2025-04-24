#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int main()
{
    _ int postes, i, tam, saida, percurso_sem_poste, aux, primeiro, indice;
    string entrada;
    while (true)
    {
        cin >> postes;
        vector<int> postes_reais(postes);
        if (postes == 0)
            break;
        primeiro = -1;
        for (i = 0; i < postes; i++)
        {
            cin >> postes_reais[i];
            if (postes_reais[i] && primeiro == -1)
                primeiro = i;
        }
        saida = 0;
        if (primeiro == -1)
        {
            saida = ((postes + 1) / 2);
        }
        else
        {
            indice = primeiro;
            percurso_sem_poste = 0;
            do
            {
                if (!postes_reais[indice])
                {
                    percurso_sem_poste += 1;
                }
                else if (percurso_sem_poste >= 2)
                {
                    saida += percurso_sem_poste / 2;
                    percurso_sem_poste = 0;
                }
                else
                {
                    percurso_sem_poste = 0;
                }
                indice = ((indice + 1) % postes);
            } while (indice != primeiro);
            saida += percurso_sem_poste / 2;
        }
        cout << saida << endl;
    }
    return 0;
}