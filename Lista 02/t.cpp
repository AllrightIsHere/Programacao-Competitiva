#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ehPalindromo(string s)
{
    int i;

    for (i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}

bool ehTudoPalindromo(vector<string> vs)
{
    int i;

    for (i = 0; i < vs.size(); i++)
    {
        if (!ehPalindromo(vs[i]))
        {
            return false;
        }
    }

    return true;
}

void proximasMascaras(vector<vector<int>> *mascaras, int tam, int divisoes)
{
    vector<int> mascara, v1, combinado;
    int i;

    for (i = 1; i < tam; i++)
    {
        v1.push_back(i);
    }

    for (i = 0; i < divisoes; i++)
    {
        combinado.push_back(0);
    }

    unsigned MAX = ~(1 << divisoes), NUM = 1, MASK;

    while (MAX & NUM)
    {
        /* Conta os bits 1's. */
        MASK = 1;
        int k = 0;
        while (MAX & MASK)
        {
            if (NUM & MASK)
                k++;
            MASK = MASK << 1;
        }

        /* Monta o resultado somente se
         * a quantidade de bits k é igual
         * a divisoes. */
        if (k == divisoes)
        {
            MASK = 1;
            int i = 0, j = 0;

            while (MAX & MASK)
            {
                /* Verdadeiro se NUM tem um bit 1
                 * na posição indicada por MASK. */
                if (NUM & MASK)
                {
                    /* Gera a combinação em str */
                    combinado[i] = v1[j];
                    i++;
                }
                j++;
                /* Desloca a máscara */
                MASK = MASK << 1;
            }

            /* fazer a mascara */

            mascara.clear();

            mascara.push_back(1);

            for (i = 1; i < tam; i++)
            {
                mascara.push_back(0);
            }

            for (i = 0; i < combinado.size(); i++)
            {
                mascara[combinado[i]] = 1;
            }

            mascaras->push_back(mascara);
            combinado.clear();
        }

        NUM++;
    }
}

void pegarVetorString(vector<string> *vs, string frase, vector<int> mascara)
{
    string s;
    int i;

    vs->clear();

    s = frase[0];

    for (i = 1; i < mascara.size(); i++)
    {
        if (mascara[i] == 0)
        {
            s += frase[i];
            continue;
        }

        if (mascara[i] == 1)
        {
            vs->push_back(s);
            s = frase[i];
        }
    }

    vs->push_back(s);
}

void inicializaMascara(vector<int> *mascara, int tam)
{
    int i;

    mascara->clear();

    mascara->push_back(1);

    for (i = 1; i < tam; i++)
    {
        mascara->push_back(0);
    }
}

int main()
{
    int tam, i = 0, j, divisoes;
    bool terminou;
    string frase;
    vector<int> mascara;
    vector<vector<int>> mascaras;
    vector<string> vs;

    while (true)
    {
        cin >> tam;
        // tam = 100;
        if (tam == 0)
            break;

        i++;

        divisoes = 1;

        cin >> frase;

        // frase = "ajcfeafjegjccehhfeibcijdgiacbafbbaifagegcfigciehceagcjjaibdbbadeadjbjgjddiafggeaaegcghfgjihcicjjgach";

        inicializaMascara(&mascara, tam);

        pegarVetorString(&vs, frase, mascara);

        terminou = ehTudoPalindromo(vs);

        while (!terminou)
        {
            divisoes++;
            mascaras.clear();
            proximasMascaras(&mascaras, tam, divisoes);

            for (j = 0; j < mascaras.size(); j++)
            {
                pegarVetorString(&vs, frase, mascaras[j]);
                if (ehTudoPalindromo(vs))
                {
                    terminou = true;
                    break;
                }
            }
        }

        cout << "Teste " << i << endl
             << divisoes << endl
             << endl;

        // break;
    }

    return 0;
}