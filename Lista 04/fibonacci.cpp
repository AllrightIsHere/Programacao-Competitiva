#include <bits/stdc++.h>

#define MOD 1000007
#define ulli unsigned long long int

using namespace std;

int main()
{
    int T, K, N, i, j;
    int fib = 0;
    cin >> T;

    while (T--)
    {
        cin >> K >> N;

        vector<ulli> numeros_fib;

        if (K >= N)
        {
            cout << N - 1 << endl;
        }

        else
        {
            // insere os primeiros K
            for (i = 0; i < K; i++)
            {
                numeros_fib.push_back(i % MOD);
            }

            // preenche de K em K
            for (i = K; i < N; i++)
            {
                ulli soma = 0;
                for (j = 0; j < K; j++)
                {
                    soma += numeros_fib[j];
                }
                numeros_fib.erase(numeros_fib.begin());
                numeros_fib.push_back(soma % MOD);
            }

            cout << numeros_fib.back() << endl;
        }
    }
    return 0;
}