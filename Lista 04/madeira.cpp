#include <bits/stdc++.h>

#define msi map<string, int>

using namespace std;

int main()
{
    int N, i;
    string nome;

    cin >> N;
    cin.ignore();

    // lê o primeiro '\n'
    getline(cin, nome);

    for (i = 0; i < N; i++)
    {
        msi hash;
        int total = 0;

        while (getline(cin, nome) && nome != "")
        {
            hash[nome]++;
            total++;
        }

        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            cout << it->first << ' ' << setprecision(4) << fixed << (it->second * 100.0) / total << endl;
        }

        if (i != N - 1)
        {
            cout << endl;
        }
    }

    return 0;
}