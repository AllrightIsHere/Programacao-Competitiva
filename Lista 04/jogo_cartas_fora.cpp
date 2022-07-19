#include <bits/stdc++.h>

#define si stack<int>

using namespace std;

int main()
{
    int N;

    cin >> N;

    while (N)
    {
        si pilha;
        int topo;
        while (N)
        {
            if (N > 0)
            {
                pilha.push(N);
            }
            N--;
        }
        cout << "Discarded cards:";
        if (pilha.size() > 1)
        {
            cout << " ";
        }
        while (pilha.size() > 2)
        {
            cout << pilha.top() << ", ";
            pilha.pop();
            topo = pilha.top();
            pilha.pop();

            si aux;

            while (!pilha.empty())
            {
                aux.push(pilha.top());
                pilha.pop();
            }

            pilha.push(topo);

            while (!aux.empty())
            {
                pilha.push(aux.top());
                aux.pop();
            }
        }

        if (pilha.size() > 1)
        {
            cout << pilha.top();
            pilha.pop();
        }
        cout << endl
             << "Remaining card: " << pilha.top() << endl;
        cin >> N;
    }

    return 0;
}