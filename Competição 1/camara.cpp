/*
Alexandre Luis
Diego Santos
Gabriel Arrighi
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> valores;
    int N, M, soma = 0, soma_aux = 0;

    cin >> M >> N;

    valores.resize(N);

    while (M--)
    {
        int X, V, Y;

        cin >> X >> V >> Y;

        valores[X - 1] -= V;
        valores[Y - 1] += V;
        soma += V;
    }

    for (int v : valores)
    {
        soma_aux += abs(v);
    }
    soma_aux /= 2;

    if (soma != soma_aux)
    {
        cout << "S" << endl
             << soma_aux << endl;
    }
    else
    {
        cout << "N" << endl
             << soma_aux << endl;
    }

    return 0;
}