#include <bits/stdc++.h>

using namespace std;

regex cria_regex(string reg)
{
    string new_regex = "";

    for (char c : reg)
    {
        if (c != '.')
        {
            new_regex.push_back(c);
        }
    }
    // cout << new_regex << endl;
    return regex(new_regex);
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string reg;

    while (cin >> reg)
    {
        // cout << reg << endl;
        int N;

        cin >> N;

        // cout << N << endl;

        string teste;

        regex r = cria_regex(reg);

        for (int i = 0; i < N + 1; i++)
        {
            getline(cin, teste, '\n');
            if (i != 0)
            {
                // cout << teste << endl;
                cout << (regex_match(teste, r) ? "Y" : "N") << endl;
            }
        }
        cout << endl;
    }

    return 0;
}