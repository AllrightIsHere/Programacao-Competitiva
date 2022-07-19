#include <bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int N, M, i, aux, itens, indice_caixa, tempo_caixa, tempo_acrescentado;
    pii caixa;
    cin >> N >> M;

    // tempo que leva o funcionário para atender
    vi V;

    // <tempo gasto até o momento, posição no supermecado>
    priority_queue<pii> fila_caixa;

    for (i = 0; i < N; i++)
    {
        cin >> aux;
        V.pb(aux);
        fila_caixa.push(mp(0, -i));
    }

    int tempo_total = 0;

    // atendendo os clientes
    for (i = 0; i < M; i++)
    {
        cin >> itens;

        caixa = fila_caixa.top();
        fila_caixa.pop();

        indice_caixa = -caixa.second;
        tempo_caixa = -caixa.first;
        // tempo_acrecentado = tempo do caixa até o momento + tempo atendimento * nº itens
        tempo_acrescentado = tempo_caixa + V[indice_caixa] * itens;
        fila_caixa.push(mp(-tempo_acrescentado, -indice_caixa));

        tempo_total = max(tempo_total, tempo_acrescentado);
    }

    cout << tempo_total << endl;

    return 0;
}