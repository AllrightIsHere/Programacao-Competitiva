#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, i, j;
    cin >> N >> M;
    while (N || M)
    {
        vector<int> original, permutacao, anterior;

        int aux;
        for (i = 0; i < N; i++)
        {
            cin >> aux;

            permutacao.push_back(aux - 1);
            original.push_back(i);
            anterior.push_back(i);
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                original[j] = anterior[permutacao[j]];
            }

            anterior = original;
        }

        string s;
        cin >> s;

        for (i = 0; i < N; i++)
        {
            cout << s[original[i]];
        }

        cout << endl;

        cin >> N >> M;
    }

    return 0;
}