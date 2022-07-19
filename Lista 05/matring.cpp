#include <bits/stdc++.h>

#define lli long long int
#define vli vector<lli>
#define pb push_back
#define mod 257

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    vli numeros;

    lli F, L;

    int i, j, N;

    for (i = 0; i < 4; i++)
    {
        cin >> str;

        if (i == 0)
        {
            N = str.length();
            F = str[0] - '0';
            L = str[N - 1] - '0';

            for (j = 1; j < N - 1; j++)
            {
                numeros.pb(str[j] - '0');
            }
        }
        else
        {
            F = F * 10 + str[0] - '0';
            L = L * 10 + str[N - 1] - '0';

            for (j = 1; j < N - 1; j++)
            {
                numeros[j - 1] = numeros[j - 1] * 10 + str[j] - '0';
            }
        }
    }

    for (i = 0; i < N - 2; i++)
    {
        // Ci = (F * Mi + L) mod 257
        cout << (char)((F * numeros[i] + L) % mod);
    }
    cout << endl;

    return 0;
}