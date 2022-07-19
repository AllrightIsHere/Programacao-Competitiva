#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    int asterisco = 0, underline = 0;

    string frase;

    while (getline(cin, frase))
    {
        for (i = 0; i < frase.size(); i++)
        {
            if (frase[i] != '*' && frase[i] != '_')
            {
                cout << frase[i];
            }
            else if (frase[i] == '*')
            {
                if (asterisco)
                {
                    asterisco = 0;
                    cout << "</b>";
                }
                else
                {
                    asterisco = 1;
                    cout << "<b>";
                }
            }
            else
            {
                if (underline)
                {
                    underline = 0;
                    cout << "</i>";
                }
                else
                {
                    underline = 1;
                    cout << "<i>";
                }
            }
        }
        cout << endl;
    }

    return 0;
}