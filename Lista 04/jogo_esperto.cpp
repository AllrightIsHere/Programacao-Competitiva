#include <bits/stdc++.h>

#define pii pair<int, int>
#define mii map<int, int>
#define mp make_pair

using namespace std;

int operacao(int num, int op)
{
    switch (op)
    {
    case 0:
        return num * 2;
    case 1:
        return num * 3;
    case 2:
        return num / 2;
    case 3:
        return num / 3;
    case 4:
        return num + 7;
    case 5:
        return num - 7;

    default:
        break;
    }

    return -1;
}

int main()
{
    int N, M, i;

    cin >> N >> M;

    // pair<quantidade de operações, valor atual>
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    mii distancias;

    fila.push(mp(0, N));

    while (!fila.empty())
    {
        pii item = fila.top();
        fila.pop();

        if (item.second == M)
        {
            cout << item.first << endl;
            return 0;
        }

        int distacia_anterior = distancias[item.second];

        for (i = 0; i < 6; i++)
        {
            int result = operacao(item.second, i);

            int distacia_operacao = distancias[result];

            if (distacia_operacao == 0 || distacia_operacao > distacia_anterior + 1)
            {
                distancias[result] = distacia_anterior + 1;

                fila.push(mp(distancias[result], result));
            }
        }
    }

    return 0;
}