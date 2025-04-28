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

int verifica_carta(vector<int> ps_c, vector<int> p_c)
{
    int i;
    int res = -1;
    int maiores_que_o_segundo = 0;
    int maiores_que_o_primeiro = 0;
    vector<int>::iterator it;

    if (ps_c[1] < p_c[1])
        maiores_que_o_segundo++;
    if (ps_c[1] < p_c[0])
        maiores_que_o_segundo++;

    if (ps_c[2] < p_c[1])
        maiores_que_o_primeiro++;
    if (ps_c[2] < p_c[0])
        maiores_que_o_primeiro++;

    if (maiores_que_o_primeiro == 2)
    {
        res = 1;
        for (i = 0; i < 5; i++)
        {
            it = find(p_c.begin(), p_c.end(), res);
            if (it != p_c.end())
                res++;
            it = find(ps_c.begin(), ps_c.end(), res);
            if (it != ps_c.end())
                res++;
        }

        if (res == p_c[0] || res == ps_c[0])
            res++;
        if (res == p_c[0] || res == ps_c[0])
            res++;
        return res;
    }

    if (maiores_que_o_segundo == 2)
    {
        res = ps_c[1] + 1;
        for (i = 0; i < 5; i++)
        {
            it = find(p_c.begin(), p_c.end(), res);
            if (it != p_c.end())
                res++;
            it = find(ps_c.begin(), ps_c.end(), res);
            if (it != ps_c.end())
                res++;
        }
        if (res > 52)
            res = -1;
        return res;
    }

    if (maiores_que_o_primeiro == 1)
    {
        res = ps_c[2] + 1;
        for (i = 0; i < 5; i++)
        {
            it = find(p_c.begin(), p_c.end(), res);
            if (it != p_c.end())
                res++;
            it = find(ps_c.begin(), ps_c.end(), res);
            if (it != ps_c.end())
                res++;
        }
        if (res > 52)
            res = -1;
        return res;
    }
    return res;
}

int main()
{
    _

    vector<int> princess_cards(3);
    vector<int> prince_cards(2);
    int res;

    while (1)
    {
        cin >> princess_cards[0] >> princess_cards[1] >> princess_cards[2] >> prince_cards[0] >> prince_cards[1];
        if (princess_cards[0] == princess_cards[1])
            break;

        sort(prince_cards.begin(), prince_cards.end());
        sort(princess_cards.begin(), princess_cards.end());

        cout << verifica_carta(princess_cards, prince_cards) << endl;
    }

    return 0;
}