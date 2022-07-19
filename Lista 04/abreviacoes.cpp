#include <bits/stdc++.h>

#define vs vector<string>
#define mss map<string, string>
#define msi map<string, int>

using namespace std;

int main()
{
    string frase;
    int i, j;
    getline(cin, frase);

    while (frase != ".")
    {
        string palavra, dotted;
        vs palavras;
        mss dicionario;
        stringstream aux(frase);

        // vetor de palavras
        while (getline(aux, palavra, ' '))
        {
            palavras.push_back(palavra);
        }

        for (i = 0; i < palavras.size(); i++)
        {
            string index = "";
            index += palavras[i][0];
            index += '.';

            if (!dicionario.count(index) && palavras[i].size() > 2)
            {
                // procura todas as palavra com letras do início iguais
                msi contador_iguais;
                string palavra_selecionada;
                int melhor_beneficio = 0;
                for (j = i; j < palavras.size(); j++)
                {
                    if (palavras[j].size() > 2 && palavras[j][0] == index[0])
                    {
                        contador_iguais[palavras[j]]++;
                    }
                }

                // calcula qual palavra vale a pena abreviar

                for (auto it = contador_iguais.begin(); it != contador_iguais.end(); it++)
                {
                    if (!melhor_beneficio)
                    {
                        palavra_selecionada = it->first;
                        melhor_beneficio = (it->first.size() - 2) * it->second;
                    }
                    else
                    {
                        int beneficio = (it->first.size() - 2) * it->second;
                        if (beneficio > melhor_beneficio)
                        {
                            palavra_selecionada = it->first;
                            melhor_beneficio = beneficio;
                        }
                    }
                }

                // após o cálculo add no dicionário
                dicionario[index] = palavra_selecionada;
                for (j = i; j < palavras.size(); j++)
                {
                    if (palavras[j] == palavra_selecionada)
                    {
                        palavras[j] = index;
                    }
                }
            }
        }

        for (i = 0; i < palavras.size() - 1; i++)
        {
            cout << palavras[i] << " ";
        }

        cout << palavras[i] << endl
             << dicionario.size() << endl;

        for (auto it = dicionario.begin(); it != dicionario.end(); it++)
        {
            cout << it->first << " = " << it->second << endl;
        }

        getline(cin, frase);
    }
    return 0;
}