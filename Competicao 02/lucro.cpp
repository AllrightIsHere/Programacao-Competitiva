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

    int N, custoPorDia;

    while (cin >> N >> custoPorDia)
    {
        int l, maior_lucro = 0;

        vector<int> lucros;

        for (int i = 0; i < N; i++)
        {
            cin >> l;
            lucros.push_back(l - custoPorDia);
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= lucros.size() - i; j++)
            {
                int intervalo = 0;
                for (int k = j; k < j + i; k++)
                {
                    intervalo += lucros[k];
                }

                if (intervalo > maior_lucro)
                {
                    maior_lucro = intervalo;
                }
            }
        }

        cout << maior_lucro << endl;
    }

    return 0;
}