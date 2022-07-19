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

    int N, K;

    while (cin >> N >> K)
    {
        vector<int> fila;

        fila.push_back(0);

        int pessoa, anterior = 0;

        for (int i = 1; i < N; i++)
        {
            cin >> pessoa;

            fila.push_back(pessoa - anterior);

            anterior = pessoa;
        }

        sort(fila.begin(), fila.end());

        int soma = 0;

        for (int i = 0; i < N - K + 1; i++)
        {
            soma += fila[i];
        }

        cout << soma << endl;
    }

    return 0;
}