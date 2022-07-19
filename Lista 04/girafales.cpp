#include <bits/stdc++.h>

#define mss map<string, string>

using namespace std;

int main()
{
    int total, N, M, i, j, k;

    cin >> N;

    while (N)
    {
        mss nomes;
        string nome, assinatura;

        total = 0;

        for (i = 0; i < N; i++)
        {
            cin >> nome >> assinatura;
            nomes[nome] = assinatura;
        }

        cin >> M;

        for (i = 0; i < M; i++)
        {
            cin >> nome >> assinatura;
            if (nomes[nome].compare(assinatura) != 0)
            {
                k = 0;
                for (j = 0; j < nomes[nome].size(); j++)
                {
                    if (nomes[nome][j] != assinatura[j])
                    {
                        k++;
                    }
                    if (k == 2)
                    {
                        total++;
                        break;
                    }
                }
            }
        }

        cout << total << endl;

        cin >> N;
    }

    return 0;
}