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

    int N;

    cin >> N;

    vector<int> colunas;

    for (int i = 0; i < N; i++)
    {
        int a;

        cin >> a;

        colunas.push_back(a);
    }

    colunas[0] = 1;
    colunas.back() = 1;

    // cout << colunas.back() << endl;

    // ajusta esquerda -> direita
    for (int i = 1; i < N - 1; i++)
    {
        if (colunas[i] - colunas[i - 1] >= 1)
        {
            colunas[i] = colunas[i - 1] + 1;
        }
    }

    // ajusta direta -> esquerda
    for (int i = N - 2; i > 0; i--)
    {
        if (colunas[i] - colunas[i + 1] >= 1)
        {
            colunas[i] = colunas[i + 1] + 1;
        }
    }

    cout << *max_element(colunas.begin(), colunas.end()) << endl;

    return 0;
}