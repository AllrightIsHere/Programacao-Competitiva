/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int pd[1001][1001];

int calcula_peso(int i, int peso, vector<pair<int, int>> enfeites, int P)
{
    // limite da recursão: Atingiu o limite de itens ou peso negativo
    if (i == P || peso <= 0)
    {
        return 0;
    }

    // já foi calculado o resultado
    if (pd[i][peso] != -1)
    {
        return pd[i][peso];
    }

    int nao_carrega = calcula_peso(i + 1, peso, enfeites, P);

    // Peso passou do limite
    if (enfeites[i].second > peso)
    {
        return pd[i][peso] = nao_carrega;
    }

    // não passou do limite: decide em carregar ou não o peso
    int carrega_peso = calcula_peso(i + 1, peso - enfeites[i].second, enfeites, P) + enfeites[i].first;
    return pd[i][peso] = max(nao_carrega, carrega_peso);
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G;

    cin >> G;

    for (int i = 1; i <= G; i++)
    {
        cout << "Galho " << i << ":\n";
        cout << "Numero total de enfeites: ";

        memset(pd, -1, sizeof pd);

        int P, W;

        cin >> P >> W;

        // <qtd_enfeite, peso>
        pair<int, int> item;

        vector<pair<int, int>> enfeites;

        for (int j = 0; j < P; j++)
        {
            cin >> item.first >> item.second;

            enfeites.push_back(item);
        }

        cout << calcula_peso(0, W, enfeites, P) << endl
             << endl;
    }

    return 0;
}