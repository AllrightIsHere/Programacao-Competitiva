#include <bits/stdc++.h>

#define vi vector<int>
#define vs vector<string>

using namespace std;

int main()
{
    int N, num, i, index_atual;
    string nome;

    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        // gera as crianças
        vi numeros;
        vs nomes;

        numeros.resize(N);
        nomes.resize(N);

        cin >> nome >> num;

        nomes[0] = nome;
        numeros[0] = num;

        for (i = N - 1; i > 0; i--)
        {
            cin >> nome >> num;

            nomes[i] = nome;
            numeros[i] = num;
        }

        num = numeros[0];
        index_atual = 0;

        while (N > 1)
        {
            if (num % 2 == 0)
            {
                while (num)
                {
                    index_atual = (index_atual + 1) % numeros.size();
                    while (numeros[index_atual] == 0)
                    {
                        index_atual = (index_atual + 1) % numeros.size();
                    }
                    num--;
                }
            }
            else
            {
                while (num)
                {
                    index_atual = (index_atual - 1 + numeros.size()) % numeros.size();
                    while (numeros[index_atual] == 0)
                    {
                        index_atual = (index_atual - 1 + numeros.size()) % numeros.size();
                    }
                    num--;
                }
            }

            num = numeros[index_atual];
            numeros[index_atual] = 0;
            N--;
        }

        for (i = 0; i < numeros.size() && numeros[i] == 0; i++)
            ;

        cout << "Vencedor(a): " << nomes[i] << endl;
    }

    return 0;
}