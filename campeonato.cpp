/*
Alexandre Luis
Diego Santos
Gabriel Arrighi
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, i, num_divisoes = 2, kung, lu;

    for (i = 0; i < 16; i++)
    {
        cin >> x;

        if (x == 1)
        {
            kung = i;
        }

        else if (x == 9)
        {
            lu = i;
        }
    }

    int quadrante = 8;

    while (quadrante > 1)
    {
        if (kung / quadrante == lu / quadrante)
        {
            quadrante /= 2;
        }
        else
        {
            break;
        }
    }

    switch (quadrante)
    {
    case 8:
        cout << "final";
        break;
    case 4:
        cout << "semifinal";
        break;
    case 2:
        cout << "quartas";
        break;
    default:
        cout << "oitavas";
        break;
    }

    cout << endl;

    return 0;
}