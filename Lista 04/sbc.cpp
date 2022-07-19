#include <bits/stdc++.h>

#define pllii pair<long long int, int>
#define vpii vector<pllii>
#define mp make_pair
#define pb push_back

using namespace std;

class Comparacao
{
public:
    bool operator()(const pllii &a, const pllii &b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int N, i;

    while (cin >> N)
    {
        long long int espera = 0, tempo_execucao = 0, t;
        int c;
        vpii processos;
        pllii aux;
        // prioridade por ciclo
        priority_queue<pllii, vpii, Comparacao> fila;

        for (i = 0; i < N; i++)
        {
            cin >> t >> c;

            processos.push_back(mp(t, c));

            // pega o menor tempo de execução
            if (i == 0 || t < tempo_execucao)
            {
                tempo_execucao = t;
            }
        }

        // ordena os processos pelo tempo de sistema
        sort(processos.begin(), processos.end(), [](const pllii &a, const pllii &b)
             { return a.first < b.first; });

        // adciona na fila os processos
        for (i = 0; i < processos.size(); i++)
        {
            if (processos[i].first > tempo_execucao)
            {
                aux = fila.top();
                fila.pop();

                if (aux.first <= tempo_execucao)
                {
                    espera += tempo_execucao - aux.first;
                }
                else
                {
                    tempo_execucao = aux.first;
                }
                tempo_execucao += aux.second;
            }
            fila.push(processos[i]);
        }

        while (!fila.empty())
        {
            aux = fila.top();
            fila.pop();

            if (aux.first <= tempo_execucao)
            {
                espera += tempo_execucao - aux.first;
            }
            else
            {
                tempo_execucao = aux.first;
            }
            tempo_execucao += aux.second;
        }

        cout << espera << endl;
    }

    return 0;
}