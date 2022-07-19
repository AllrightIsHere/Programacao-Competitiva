/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int pd[1001];

int calcula_menor_comprimento(vector<int> furos, int remendo1, int remendo2, int i, int N, int comprimento)
{
    int fim = N - 1;

    if (i > fim)
    {
        return 0;
    }

    if (i >= fim)
    {
        return min(remendo1, remendo2);
    }

    if (pd[i] != -1)
    {
        return pd[i];
    }

    int prox_rem1 = i;
    int prox_rem2 = i;

    for (int j = i + 1; j < N; j++)
    {
        // int distance = min(furos[j] - furos[i], furos[i] + comprimento - furos[j]);
        int distance = furos[j] - furos[i];
        if (distance <= remendo1)
        {
            prox_rem1++;
        }

        if (distance <= remendo2)
        {
            prox_rem2++;
        }
        else if (distance > remendo1)
        {
            break;
        }
    }

    return pd[i] = min(calcula_menor_comprimento(furos, remendo1, remendo2, prox_rem1 + 1, N, comprimento) + remendo1, calcula_menor_comprimento(furos, remendo1, remendo2, prox_rem2 + 1, N, comprimento) + remendo2);
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, comprimento, remendo1, remendo2;

    while (cin >> N >> comprimento >> remendo1 >> remendo2)
    {
        memset(pd, -1, sizeof pd);

        vector<int> furos;

        for (int i = 0; i < N; i++)
        {
            int aux;
            cin >> aux;
            furos.push_back(aux);
        }

        cout << calcula_menor_comprimento(furos, remendo1, remendo2, 0, N, comprimento) << endl;
    }

    return 0;
}