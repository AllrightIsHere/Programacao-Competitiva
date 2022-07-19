#include <iostream>
#include <string>

using namespace std;

int main()
{
    int games, round = 0, num1, num2, i;
    string gamerPar, gamerImpar;

    while (true)
    {
        cin >> games;
        if (games == 0)
            break;
        round++;
        cout << "Teste " << round << endl;
        cin >> gamerPar;
        cin >> gamerImpar;

        for (i = 0; i < games; i++)
        {
            cin >> num1;
            cin >> num2;

            if ((num1 + num2) % 2 == 0)
            {
                cout << gamerPar << endl;
            }
            else
            {
                cout << gamerImpar << endl;
            }
        }

        cout << endl;
    }
    return 0;
}