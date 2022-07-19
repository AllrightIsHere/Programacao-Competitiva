#include <bits/stdc++.h>

#define msi map<string, int>
#define msmsi map<string, msi>

using namespace std;

int main()
{
    msmsi dados;
    string nome, presente1, presente2, presente3;
    int N, i;

    cin >> N;

    // adiciona os presentes e pessoas
    for (i = 0; i < N; i++)
    {
        cin >> nome >> presente1 >> presente2 >> presente3;
        msi presentes;
        presentes[presente1] = 1;
        presentes[presente2] = 1;
        presentes[presente3] = 1;
        dados[nome] = presentes;
    }

    while (cin >> nome)
    {
        cin >> presente1;
        dados[nome][presente1] ? cout << "Uhul! Seu amigo secreto vai adorar o/" : cout << "Tente Novamente!";
        cout << endl;
    }

    return 0;
}