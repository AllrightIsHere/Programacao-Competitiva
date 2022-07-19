#include <bits/stdc++.h>

#define lli long long int
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, N, B;
    int soma, num;
    lli nota;

    while (cin >> N >> B)
    {
        nota = 0;
        soma = 0;

        vi notas;

        priority_queue<pii, vector<pii>, greater<pii>> maximos;
        priority_queue<pii, vector<pii>, less<pii>> minimos;

        // preenche as notas
        for (i = 0; i < N; i++)
        {
            cin >> num;
            notas.pb(num);
            maximos.push(mp(num, i));
            minimos.push(mp(num, i));

            soma += num;

            // primeira bateria
            if (i == B - 1)
            {
                nota += (lli)(soma - maximos.top().first - minimos.top().first);
            }

            // segunda bateria em diante
            if (i >= B)
            {
                soma -= notas[i - B];

                // remove aqueles com os índices fora do intervalo
                while (maximos.top().second <= i - B)
                {
                    maximos.pop();
                }

                // remove aqueles com os índices fora do intervalo
                while (minimos.top().second <= i - B)
                {
                    minimos.pop();
                }

                nota += (lli)(soma - maximos.top().first - minimos.top().first);
            }
        }

        cout << nota << endl;
    }
    return 0;
}