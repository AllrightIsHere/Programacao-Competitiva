/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int pd[101][51], mascara_brinquedos[101][51];
int pacotes, pesos;

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

    if (nao_carrega < carrega_peso)
    {
        mascara_brinquedos[i][peso] = 1;
        // pesos += enfeites[i].second;
        // pacotes += 1;
    }

    return pd[i][peso] = max(nao_carrega, carrega_peso);
}

void calcula_peso_enfeites(vector<pair<int, int>> items, int i, int peso, int pac)
{
    // chegou no limite da recursão
    if (i == pac)
    {
        return;
    }

    // item foi adicionado ao resultado
    if (mascara_brinquedos[i][peso])
    {
        pacotes++;
        pesos += items[i].second;
        calcula_peso_enfeites(items, i + 1, peso - items[i].second, pac);
    }

    // não foi adicionado
    else
    {
        calcula_peso_enfeites(items, i + 1, peso, pac);
    }
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    while (N--)
    {
        memset(pd, -1, sizeof pd);
        memset(mascara_brinquedos, 0, sizeof mascara_brinquedos);

        pesos = pacotes = 0;

        int pac;

        cin >> pac;

        // <qtd brinquedos, peso>
        pair<int, int> item;
        vector<pair<int, int>> items;

        for (int i = 0; i < pac; i++)
        {
            cin >> item.first >> item.second;

            items.push_back(item);
        }

        int brinquedos = calcula_peso(0, 50, items, pac);

        calcula_peso_enfeites(items, 0, 50, pac);

        cout << brinquedos << " brinquedos" << endl;
        cout << "Peso: " << pesos << " kg" << endl;
        cout << "sobra(m) " << pac - pacotes << " pacote(s)" << endl
             << endl;
    }

    return 0;
}