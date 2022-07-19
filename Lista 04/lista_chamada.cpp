#include <bits/stdc++.h>

#define vs vector<string>
#define pb push_back

using namespace std;

int main()
{
    int N, K;
    vs alunos;

    cin >> N >> K;

    while (N--)
    {
        string nome;
        cin >> nome;
        alunos.pb(nome);
    }

    sort(alunos.begin(), alunos.end());

    cout << alunos[K - 1] << endl;

    return 0;
}