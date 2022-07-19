#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    regex reg = regex("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{6,32}$");

    string frase;

    while (getline(cin, frase, '\n'))
    {
        if (frase.size() > 0)
            cout << "Senha " << (regex_match(frase, reg) ? "valida." : "invalida.") << endl;
    }
    return 0;
}