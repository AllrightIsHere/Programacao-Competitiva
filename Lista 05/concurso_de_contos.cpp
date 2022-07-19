#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, C;

    while (cin >> N >> L >> C)
    {
        // cout << N << ' ' << L << ' ' << C << endl;
        string frase;

        getline(cin, frase, '\n');
        getline(cin, frase, '\n');

        // cout << frase << endl;

        stringstream palavras(frase);

        string palavra_atual;

        int linhas = 0, cont_caracter = 0;

        palavras >> palavra_atual;

        cont_caracter = palavra_atual.size();

        if (cont_caracter == C)
        {
            cont_caracter = 0;
            linhas++;
        }
        else
        {
            cont_caracter++;
        }

        while (palavras >> palavra_atual)
        {
            cont_caracter += palavra_atual.size();

            if (cont_caracter == C)
            {
                cont_caracter = 0;
                linhas++;
            }
            else if (cont_caracter > C)
            {
                cont_caracter = palavra_atual.size();
                cont_caracter++;
                linhas++;
            }
            else
            {
                cont_caracter++;
            }
        }

        if (cont_caracter != 0)
        {
            linhas++;
        }

        int paginas = (linhas % L == 0 ? linhas / L : (linhas / L) + 1);

        cout << paginas << endl;
    }

    return 0;
}