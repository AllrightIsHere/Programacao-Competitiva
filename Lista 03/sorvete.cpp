#include <bits/stdc++.h>

#define pi pair<int, int>
#define vpi vector<pi>
#define mp make_pair
#define pb push_back

using namespace std;

void resolver(vpi &s, int tam)
{
    int i, inicio = s[0].first, fim = s[0].second;

    for (i = 1; i < tam; i++)
    {
        while (s[i].first <= fim && i < tam)
        {
            if (s[i].second > fim)
            {
                fim = s[i].second;
            }

            i++;
        }

        cout << inicio << ' ' << fim << endl;
        inicio = s[i].first;
        fim = s[i].second;
    }

    if (i == tam)
    {
        cout << inicio << ' ' << fim << endl;
    }
}

int main()
{
    int teste = 1, P, S, i;

    cin >> P >> S;

    while (P || S)
    {
        int x, y;
        vpi sorveteiros, solucoes;

        cin >> x >> y;

        sorveteiros.pb(mp(x, y));

        for (i = 1; i < S; i++)
        {
            cin >> x >> y;

            sorveteiros.pb(mp(x, y));
        }

        sort(sorveteiros.begin(), sorveteiros.end(), [](auto &p1, auto &p2)
             { return p1.first < p2.first; });

        cout << "Teste " << teste++ << endl;

        resolver(sorveteiros, S);

        cout << endl;

        cin >> P >> S;
    }
    return 0;
}