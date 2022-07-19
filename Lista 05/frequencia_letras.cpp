#include <bits/stdc++.h>

#define mci map<char, int>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    string frase;

    int i = 1;

    while (getline(cin, frase))
    {
        mci contador;

        int max = 0;

        for (char c : frase)
        {
            if (isalpha(c))
            {
                contador[tolower(c)]++;

                if (max < contador[tolower(c)])
                {
                    max = contador[tolower(c)];
                }
            }
        }

        for (auto it = contador.begin(); it != contador.end(); it++)
        {
            if (it->second == max)
            {
                cout << it->first;
            }
        }

        if (i)
        {
            i = 0;
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}