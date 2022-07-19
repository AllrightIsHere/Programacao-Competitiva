#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    while (N--)
    {
        int deslocamento, i;
        string frase;

        cin >> frase;
        cin >> deslocamento;

        for (i = 0; i < frase.size(); i++)
        {
            cout << (char)('A' + ((frase[i] - deslocamento - 'A' + 26) % 26));
        }
        cout << endl;
    }

    return 0;
}