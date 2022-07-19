#include <bits/stdc++.h>

#define pi pair<int, int>
#define mp make_pair

using namespace std;

bool estaDentro(pi p1, pi p2, pi p)
{
    return p.first >= p1.first && p.first <= p2.first && p.second <= p1.second && p.second >= p2.second;
}

int main()
{
    int i, teste = 1, n, X1, Y1, X2, Y2;
    pi p1, p2;

    cin >> X1 >> Y1 >> X2 >> Y2;

    while (X1 || Y1 || X2 || Y2)
    {
        int total = 0;

        p1 = mp(X1, Y1);
        p2 = mp(X2, Y2);

        cin >> n;

        for (i = 0; i < n; i++)
        {
            cin >> X1 >> Y1;

            if (estaDentro(p1, p2, mp(X1, Y1)))
            {
                total++;
            }
        }

        cout << "Teste " << teste++ << endl
             << total << endl;

        cin >> X1 >> Y1 >> X2 >> Y2;
    }

    return 0;
}