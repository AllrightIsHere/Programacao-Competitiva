#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, C, M, fig;
    map<int, int> carimbadas;

    cin >> N >> C >> M;

    int count = C;

    while (C--)
    {
        cin >> fig;
        carimbadas[fig] = 1;
    }

    while (M--)
    {
        cin >> fig;
        if (carimbadas.count(fig) && carimbadas[fig])
        {
            carimbadas[fig] = 0;
            count--;
        }
    }

    cout << count << endl;

    return 0;
}