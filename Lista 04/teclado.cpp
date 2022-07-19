#include <bits/stdc++.h>

#define ss stack<string>
#define vs vector<string>
#define pb push_back

using namespace std;

void adiciona_frase(bool is_insert_front, vs &f, string frase)
{
    if (is_insert_front)
    {
        f.insert(f.begin(), frase);
    }
    else
    {
        f.pb(frase);
    }
}

int main()
{
    int i;
    string frase;

    while (cin >> frase)
    {
        string aux = "";
        bool is_insert_front = true;
        vs frases;

        for (i = 0; i < frase.size(); i++)
        {
            // ativa a tecla Home
            if (frase[i] == '[')
            {
                adiciona_frase(is_insert_front, frases, aux);
                aux = "";
                is_insert_front = true;
            }
            // ativa a tecla End
            else if (frase[i] == ']')
            {
                adiciona_frase(is_insert_front, frases, aux);
                aux = "";
                is_insert_front = false;
            }
            else
            {
                aux += frase[i];
            }
        }

        adiciona_frase(is_insert_front, frases, aux);

        for (i = 0; i < frases.size(); i++)
        {
            cout << frases[i];
        }

        cout << endl;
    }
    return 0;
}