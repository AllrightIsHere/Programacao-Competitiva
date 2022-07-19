#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minimo;

bool isPalindrome(string s)
{
    int i, tam = s.size(), j = tam / 2;

    for (i = 0; i < j; i++)
    {
        if (s[i] != s[tam - i - 1])
        {
            return false;
        }
    }

    return true;
}

int substringRecursive(vector<string> vs, string s)
{
    if (isPalindrome(s))
    {
        if (minimo > vs.size() + 1)
            minimo = vs.size() + 1;
        return vs.size() + 1;
    }

    int i;

    string right, left;

    for (i = 0; i < s.size() - 1; i++)
    {
        left = s.substr(0, i + 1);
        right = s.substr(i + 1, s.size() - (i + 1));

        vector<string> t = vs;

        if (isPalindrome(left))
        {
            t.push_back(left);
            substringRecursive(t, right);
        }

        if (isPalindrome(right))
        {
            t.push_back(right);
            substringRecursive(t, left);
        }
    }
}

int main()
{
    vector<string> vs;
    string frase = "bbabcbbaab";
    minimo = frase.size();

    substringRecursive(vs, frase);
    cout << minimo;

    return 0;
}