#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

int multiples(int num, vector<int> vet)
{
    int ret = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] % num == 0)
            ret++;
    }
    return ret;
}

int main()
{
    int n, i, numbers;
    vector<int> vet;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> numbers;
        vet.push_back(numbers);
    }
    cout << multiples(2, vet) << " Multiplo(s) de " << 2 << endl; 
    cout << multiples(3, vet) << " Multiplo(s) de " << 3 << endl; 
    cout << multiples(4, vet) << " Multiplo(s) de " << 4 << endl; 
    cout << multiples(5, vet) << " Multiplo(s) de " << 5 << endl; 
    return 0;
}