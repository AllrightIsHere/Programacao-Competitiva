#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void dfs(int vertice, auto &g, auto &v)
{
    int i;
    v[vertice] = 1;

    for (i = 0; i < 7; i++)
    {
        if (g[vertice][i] == 1 && v[i] == 0)
        {
            dfs(i, g, v);
        }
    }
}

int main()
{
    int N, i, l, r, teste = 1;
    cin >> N;

    while (N)
    {
        int grafo[7][7] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
        int repeticoes[7] = {0};
        int visitados[7] = {0};
        string frase = "nao";

        // constroi o grafo
        for (i = 0; i < N; i++)
        {
            cin >> l >> r;

            repeticoes[l]++;
            repeticoes[r]++;

            grafo[l][r] = 1;
            grafo[r][l] = 1;
        }

        // verifica as peças finais
        int impares = 0;
        for (i = 0; i < 7; i++)
        {
            if (repeticoes[i] % 2 == 1)
            {
                impares++;
            }
        }

        // é necessário as repetições sejam pares (uma peça liga a outra)
        // ou que haja no máximo 2 ímpares para serem as pontas
        bool pontas_validas = impares == 0 || impares == 2;

        if (pontas_validas)
        {
            // calcula primeiro indice válido para o dfs
            for (i = 0; i < 7; i++)
            {
                if (repeticoes[i] != 0)
                {
                    break;
                }
            }

            // faz o dfs
            dfs(i, grafo, visitados);

            // verifica se usou todas as peças
            for (i = 0; i < 7; i++)
            {
                if (repeticoes[i] > 0 && visitados[i] == 0)
                {
                    break;
                }
            }

            i == 7 ? frase = "sim" : frase = "nao";
        }

        cout << "Teste " << teste++ << endl
             << frase << endl
             << endl;

        cin >> N;
    }

    return 0;
}
