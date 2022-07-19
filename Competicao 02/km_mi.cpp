/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    vector<int> kms;
    int maior = -1;

    while (t--)
    {
        int km;

        cin >> km;

        if (maior < km)
        {
            maior = km;
        }

        kms.push_back(km);
    }

    vector<int> fib;

    int f1 = 1, f2 = 2;

    fib.push_back(0);
    fib.push_back(0);
    fib.push_back(f1);
    fib.push_back(f2);

    while (f2 <= maior)
    {
        fib.push_back(f1 + f2);
        f1 = f2;
        f2 = fib.back();
    }

    for (int km : kms)
    {
        int soma = 0;
        int aux_km = km;

        bool finish = false;

        while (aux_km >= 1)
        {
            // cout << aux_km << endl;
            for (int i = 0; i < fib.size(); i++)
            {
                if (fib[i] > aux_km)
                {
                    soma += fib[i - 2];
                    aux_km -= fib[i - 1];
                    break;
                }
                else if (fib[i] == aux_km)
                {
                    soma += fib[i - 1];
                    aux_km -= fib[i];
                    break;
                }
            }
        }

        cout << soma << endl;
    }

    return 0;
}