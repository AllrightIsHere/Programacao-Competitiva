/*
Alexandre Luis
Diego Santos
Gabriel Arrighi
*/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> somas, int soma, int depth, int l, int r)
{
    // cout << "L = " << l << " R = " << r << endl;
    if (depth == somas.size())
    {
        return soma;
    }

    int direita = numeric_limits<int>::max();

    if (r <= somas.size() - 1)
    {
        direita = solve(somas, soma + somas[depth][r], depth + 1, l, r + 1);
    }

    int esquerda = numeric_limits<int>::max();

    if (l >= 0)
    {
        esquerda = solve(somas, soma + somas[depth][l], depth + 1, l - 1, r);
    }

    return min(direita, esquerda);
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i, j;
    vector<vector<int>> somas;

    cin >> N;

    somas.resize(N);

    for (i = 0; i < N; i++)
    {
        if (somas[i].empty())
        {
            somas[i].resize(N);
        }

        for (j = 0; j < N; j++)
        {
            cin >> somas[i][j];
        }
    }

    for (i = N - 2; i >= 0; i--)
    {
        for (j = 0; j < N; j++)
        {
            somas[i][j] += somas[i + 1][j];
        }
    }

    int minimo = numeric_limits<int>::max();

    for (i = 0; i < N; i++)
    {
        // cout << "i = " << i << endl;
        minimo = min(minimo, solve(somas, somas[0][i], 1, i - 1, i + 1));
    }

    cout << minimo << endl;
    return 0;
}