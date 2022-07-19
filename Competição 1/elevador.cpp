#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, caixa1, caixa2, peso;
    vector<int> pesos;

    cin >> N;

    while (N--)
    {
        cin >> peso;
        pesos.push_back(peso);
    }

    sort(pesos.begin(), pesos.end());

    caixa1 = pesos[0];

    if (caixa1 > 8)
    {
        cout << "N" << endl;
        return 0;
    }

    for (int i = 1; i < pesos.size(); i++)
    {
        caixa2 = caixa1;
        caixa1 = pesos[i];

        if (caixa1 - caixa2 > 8)
        {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}