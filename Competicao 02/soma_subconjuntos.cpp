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

    int T;

    cin >> T;

    while (T--)
    {
        int N;

        cin >> N;

        vector<long long> conjunto;

        // um número a mais na soma
        long long resposta = 1;

        for (int i = 0; i < N; i++)
        {
            long long num;
            cin >> num;
            conjunto.push_back(num);
        }

        // ordena para pegar as menores somas primeiro
        sort(conjunto.begin(), conjunto.end());

        for (int i = 0; i < N; i++)
        {
            // conjunto somado anterior + 1 é menor que o próximo número
            // então há pelo menos um espaço sobrando
            if (resposta < conjunto[i])
            {
                break;
            }

            resposta += conjunto[i];
        }

        cout << resposta << endl;
    }
    return 0;
}