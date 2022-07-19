#include <bits/stdc++.h>

#define vs vector<string>
#define pb push_back

using namespace std;

int main()
{
    vs amigos, novos_amigos;
    string nome, nomes;
    int i, j;

    // amigos
    getline(cin, nomes);

    size_t pos = nomes.find(" ");
    while (pos != string::npos)
    {
        nome = nomes.substr(0, pos);
        amigos.pb(nome);
        nomes.erase(0, pos + 1);
        pos = nomes.find(" ");
    }

    amigos.pb(nomes);

    // novos amigos
    getline(cin, nomes);

    pos = nomes.find(" ");
    while (pos != string::npos)
    {
        nome = nomes.substr(0, pos);
        novos_amigos.pb(nome);
        nomes.erase(0, pos + 1);
        pos = nomes.find(" ");
    }

    novos_amigos.pb(nomes);

    // amigo ou nao
    cin >> nome;

    // imprimir resultados
    for (i = 0; i < amigos.size() && amigos[i].compare(nome) != 0; i++)
    {
        cout << amigos[i] << ' ';
    }

    for (j = 0; j < novos_amigos.size() - 1; j++)
    {
        cout << novos_amigos[j] << ' ';
    }

    cout << novos_amigos[j];

    if (nome.compare("nao") != 0)
    {
        for (; i < amigos.size(); i++)
        {
            cout << ' ' << amigos[i];
        }
    }

    cout << endl;

    return 0;
}