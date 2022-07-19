#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    string frase;
    string vogais;

    cin >> frase;

    for (i = 0; i < frase.size(); i++)
    {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
        {
            vogais += frase[i];
        }
    }

    for (i = 0; i < vogais.length() / 2; i++)
    {
        if (vogais[i] != vogais[vogais.length() - i - 1])
        {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}