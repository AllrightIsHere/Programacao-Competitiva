#include <bits/stdc++.h>

#define INF 500000000
#define endl "\n"
#define vi vector<int>
#define vbb vector<vector<bool>>

using namespace std;

int tam;

void resize(vbb &m, vi &c)
{
    int i;

    c.resize(tam);

    m.resize(tam);

    for (i = 0; i < tam; i++)
    {
        m[i].resize(tam);
    }
}

/*
i, j => da frase de i até j é palíndromo?
*/

void findAllPalindromes(string s, vbb &m)
{
    int i, j;

    for (i = 0; i < tam; i++)
    {
        m[i][i] = true;
    }

    for (j = 1; j < tam; j++)
    {
        for (i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
            {
                if (i + 1 >= j - 1)
                {
                    m[i][j] = true;
                }
                else if (m[i + 1][j - 1])
                {
                    m[i][j] = true;
                }
            }
        }
    }
}

// calcula o mínimo de camadas

void findMinSubPalindromes(string s, vbb &m, vi &c)
{
    int i, j, menor;

    for (j = 0; j < tam; j++)
    {
        if (m[0][j])
        {
            c[j] = 1;
        }
        else
        {
            menor = INF;
            for (i = 1; i <= j; i++)
            {
                if (m[i][j])
                {
                    if (c[i - 1] + 1 < menor)
                    {
                        menor = c[i - 1] + 1;
                    }
                }
            }
            c[j] = menor;
        }
    }
}

int main()
{
    int test = 1;

    cin >> tam;

    while (tam)
    {
        string frase;

        cin >> frase;

        vbb matriz;
        vi camadas;

        resize(matriz, camadas);

        findAllPalindromes(frase, matriz);

        findMinSubPalindromes(frase, matriz, camadas);

        cout << "Teste " << test++ << endl
             << camadas[tam - 1] << endl
             << endl;

        cin >> tam;
    }

    return 0;
}