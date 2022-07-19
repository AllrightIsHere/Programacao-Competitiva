#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    while (cin >> N)
    {
        int i;
        for (i = 0; i < N + 1; i++)
        {
            string frase;
            getline(cin, frase, '\n');
            if (i != 0)
            {
                int cont = 0;

                string delimiter = " ";

                size_t pos = 0;
                string token;
                while ((pos = frase.find(delimiter)) != string::npos)
                {
                    token = frase.substr(0, pos);
                    frase.erase(0, pos + delimiter.length());
                    cont++;
                }
                cont++;

                cout << (char)(cont * 3 + frase.size() - 3 + 'a' - 1) << endl;
            }
        }
    }

    return 0;
}