#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string frase, big_word;
    int big_size = 0;

    getline(cin, frase, '\n');

    while (frase != "0")
    {
        int word_len = 0;

        // cout << frase << endl;

        for (int i = 0; i < frase.size(); i++)
        {
            if (frase[i] == ' ')
            {
                cout << word_len << '-';
                if (word_len >= big_size)
                {
                    big_word = frase.substr(i - word_len, word_len);
                    big_size = word_len;
                }

                word_len = 0;
            }
            else
            {
                word_len++;
                // cout << word_len << endl;
            }
        }

        cout << word_len << endl;

        if (word_len >= big_size)
        {
            big_word = (frase.size() == word_len ? frase : frase.substr(frase.size() - word_len, word_len));
            big_size = word_len;
        }

        getline(cin, frase, '\n');
    }

    cout << endl
         << "The biggest word: " << big_word << endl;

    return 0;
}