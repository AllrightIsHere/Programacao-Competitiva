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

    int S;

    cin >> S;

    vector<int> quadradonia, noglonia;

    for (int i = 0; i < S; i++)
    {
        int aux;

        cin >> aux;

        quadradonia.push_back(aux);
    }

    for (int i = 0; i < S; i++)
    {
        int aux;

        cin >> aux;

        noglonia.push_back(aux);
    }

    sort(quadradonia.begin(), quadradonia.end());
    sort(noglonia.begin(), noglonia.end());

    int i = 0, j = 0;
    int vitorias = 0;

    while (i < S && j < S)
    {
        // noglonia vence
        if (quadradonia[i] < noglonia[j])
        {
            vitorias++;
            i++;
            j++;
        }

        // pega a próxima vitória
        while (quadradonia[i] >= noglonia[j] && j < S)
        {
            j++;
        }
    }

    cout << vitorias << endl;

    return 0;
}