/*
Alexandre Luis
Diego Santos
Gabriel Arrighi
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L, H, i, j, num;
    int soma, melhor_sub;
    vector<int> sequencia;
    vector<int> mascara;

    cin >> N >> L >> H;

    int diff = H - L;

    for (i = 0; i < N; i++)
    {
        cin >> num;
        sequencia.push_back(num);
    }

    for (i = 0; i < N; i++)
    {
        cin >> num;
        mascara.push_back(num);
    }

    int cont_sub = 0;
    soma = 0;

    for (i = 0; i < N; i++)
    {
        soma += sequencia[i];

        if (mascara[i] == 1)
        {
            cont_sub += 1;
        }

        if (cont_sub == L)
        {
            int cont_mais = 0;
            for (j = i + 1; j - i < diff; j++)
            {
            }
        }
    }

    return 0;
}