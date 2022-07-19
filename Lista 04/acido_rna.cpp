#include <bits/stdc++.h>

#define sc stack<char>

using namespace std;

bool valida(char c1, char c2)
{
    return (c1 == 'B' && c2 == 'S') ||
           (c1 == 'S' && c2 == 'B') ||
           (c1 == 'C' && c2 == 'F') ||
           (c1 == 'F' && c2 == 'C');
}

int main()
{
    string rna;
    int i, total;

    while (cin >> rna)
    {
        sc pilha;
        total = 0;

        for (i = 0; i < rna.size(); i++)
        {
            if (!pilha.empty() && valida(rna[i], pilha.top()))
            {
                total++;
                pilha.pop();
            }
            else
            {
                pilha.push(rna[i]);
            }
        }

        cout << total << endl;
    }
}