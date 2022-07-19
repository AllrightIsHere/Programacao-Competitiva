#include <bits/stdc++.h>

#define lli long long int
#define pii pair<lli, lli>
#define vi vector<lli>
#define di deque<pii>
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define mp make_pair

using namespace std;

void operacao(di &maximos, di &minimos, lli nota, int index)
{
    // remove todos na lista menor ou igual que a nota atual
    while (!maximos.empty() && maximos.back().first <= nota)
    {
        maximos.ppb();
    }

    // remove todos na lista maior ou igual que a nota atual
    while (!minimos.empty() && minimos.back().first >= nota)
    {
        minimos.ppb();
    }

    maximos.pb(mp(nota, index));
    minimos.pb(mp(nota, index));
}

int main()
{
    int i, j, N, B;
    lli nota, soma, num;

    while (cin >> N >> B)
    {
        nota = 0;
        soma = 0;

        vi notas;

        di maximos, minimos;

        // preenche as notas
        for (i = 0; i < N; i++)
        {
            cin >> num;
            notas.pb(num);
        }

        // calcula primeira bateria
        for (i = 0; i < B; i++)
        {
            soma += notas[i];

            operacao(maximos, minimos, notas[i], i);
        }

        nota += (soma - minimos[0].first - maximos[0].first);

        // calcula da segunda bateria em diante
        for (i = B; i < N; i++)
        {
            soma -= notas[i - B];
            soma += notas[i];

            if (maximos[0].second == i - B)
            {
                maximos.ppf();
            }

            if (minimos[0].second == i - B)
            {
                minimos.ppf();
            }

            operacao(maximos, minimos, notas[i], i);

            nota += (soma - maximos[0].first - minimos[0].first);
        }

        cout << nota << endl;
    }
    return 0;
}