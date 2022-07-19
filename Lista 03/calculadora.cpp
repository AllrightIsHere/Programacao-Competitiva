#include <bits/stdc++.h>

using namespace std;

int main()
{
    int teste = 1, num, i;
    char op;

    cin >> num;

    while (num)
    {
        int soma, n;

        cin >> soma;

        for (i = 1; i < num; i++)
        {
            cin >> op;
            cin >> n;

            op == '+' ? soma += n : soma -= n;
        }

        cout << "Teste " << teste++ << endl
             << soma << endl
             << endl;

        cin >> num;
    }

    return 0;
}