#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int i, tam = s.size(), mid = tam / 2;

    for (i = 0; i < mid; i++)
    {
        if (s[i] != s[tam - i - 1])
        {
            return false;
        }
    }

    return true;
}

int minSubtringPal(vector<string> vs)
{
    int i, divisoes = 0, tam, len;
    bool cont;

    string s, part, left, right;

    while (!vs.empty())
    {
        s = vs.back();
        vs.pop_back();

        tam = len = s.size();

        cont = true;

        while (cont)
        {
            for (i = 0; i < tam; i++)
            {
                if (i + len > tam)
                {
                    break;
                }
                part = s.substr(i, len);

                if (isPalindrome(part))
                {
                    left = s.substr(0, i);
                    right = s.substr(i + len, tam - i - len);
                    if (left.size())
                    {
                        vs.push_back(left);
                    }
                    if (right.size())
                    {
                        vs.push_back(right);
                    }
                    cont = false;
                    divisoes++;
                    break;
                }
            }

            len--;
        }
    }

    return divisoes;
}

int main()
{
    string frase;
    vector<string> vs;

    frase = "bbabcbbaab";
    vs.push_back(frase);

    cout << minSubtringPal(vs);
    return 0;
}