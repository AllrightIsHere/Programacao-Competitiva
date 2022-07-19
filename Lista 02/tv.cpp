#include <iostream>

using namespace std;

int main()
{
    int M, N, X, Y, i, j, k, teste = 0, soma_X, soma_Y;
    int matrix[1000][1000];

    cin >> M;
    cin >> N;

    while (M || N)
    {
        teste++;

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                cin >> k;
                matrix[i][j] = k;
            }
        }

        cin >> X;
        cin >> Y;

        soma_X = X;
        soma_Y = Y;

        while (X || Y)
        {
            cin >> X;
            cin >> Y;

            soma_X += X;
            soma_Y += Y;
        }

        cout << "Teste " << teste << endl;

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                cout << matrix[(M + (i + soma_Y) % M) % M][(N + (j - soma_X) % N) % N];
                if (j != N - 1)
                    cout << ' ';
            }
            cout << endl;
        }

        cout << endl;

        cin >> M;
        cin >> N;
    }

    return 0;
}