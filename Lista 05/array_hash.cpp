#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    while (N--)
    {
        int L, soma = 0, i, j;

        cin >> L;

        for (i = 0; i < L; i++)
        {
            string frase;

            cin >> frase;

            for (j = 0; j < frase.size(); j++)
            {
                soma += (frase[j] - 'A' + i + j);
            }
        }

        cout << soma << endl;
    }

    return 0;
}