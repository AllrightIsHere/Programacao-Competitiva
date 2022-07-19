/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<stack<int>> hastes;

        hastes.resize(N);

        int i = 1;

        while (true)
        {
            bool has_add = false;

            for (int j = 0; j < hastes.size(); j++)
            {
                if (hastes[j].empty())
                {
                    hastes[j].push(i);
                    has_add = true;
                    break;
                }
                double raiz = sqrt(hastes[j].top() + i);
                if (ceil(raiz) == floor(raiz))
                {
                    hastes[j].push(i);
                    has_add = true;
                    break;
                }
            }

            if (!has_add)
            {
                cout << i - 1 << endl;
                break;
            }

            i++;
        }
    }

    return 0;
}