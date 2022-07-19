#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, caixa1, caixa2;

    cin >> N >> caixa1;

    if (caixa1 > 8)
    {
        cout << "N" << endl;
        return 0;
    }

    N--;

    while (N--)
    {
        caixa2 = caixa1;
        cin >> caixa1;

        if (caixa1 - caixa2 > 8)
        {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}