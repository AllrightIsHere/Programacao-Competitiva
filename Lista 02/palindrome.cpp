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

void substringRecursive(int tam, string s)
{
    if (minimo < tam)
        return;

    if (isPalindrome(s))
    {
        if (minimo > tam + 1)
        {
            minimo = tam + 1;
        }
        return;
    }

    string right, left;
    int i;

    for (i = 0; i < s.size(); i++)
    {
        left = s.substr(0, i + 1);
        right = s.substr(i + 1, s.size() - i - 1);

        if (isPalindrome(left))
        {
            substringRecursive(tam + 1, right);
        }
    }
}

int main()
{
    string frase;
    int tam, i = 1;

    cin >> tam;

    while (tam)
    {
        cin >> frase;

        minimo = frase.size();

        substringRecursive(0, frase);

        cout << "Teste " << i << endl;
        cout << minimo << endl
             << endl;

        cin >> tam;
        i++;
    }

    return 0;
}