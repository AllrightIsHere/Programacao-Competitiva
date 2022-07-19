#include <bits/stdc++.h>

#define vs vector<string>
#define pb push_back

using namespace std;

char op;

void populaRegiao(vs &regiao)
{
    cin >> op;

    while (op == 'A')
    {
        string aviao;

        cin >> aviao;
        regiao.pb("A" + aviao);

        cin >> op;
    }
}

int main()
{
    int i, lado;
    vs oeste, norte, sul, leste;

    cin >> op;

    while (op != '0')
    {
        cin >> lado;

        switch (lado)
        {
        case 1:
            populaRegiao(oeste);
            break;
        case 2:
            populaRegiao(sul);
            break;
        case 3:
            populaRegiao(norte);
            break;
        case 4:
            populaRegiao(leste);
            break;

        default:
            break;
        }
    }

    bool primeiro = true;

    while (!norte.empty() || !sul.empty() || !leste.empty() || !oeste.empty())
    {
        if (!oeste.empty())
        {
            primeiro ? cout << oeste[0] : cout << ' ' << oeste[0];
            primeiro = false;
            oeste.erase(oeste.begin());
        }

        if (!norte.empty())
        {
            primeiro ? cout << norte[0] : cout << ' ' << norte[0];
            primeiro = false;
            norte.erase(norte.begin());
        }

        if (!sul.empty())
        {
            primeiro ? cout << sul[0] : cout << ' ' << sul[0];
            primeiro = false;
            sul.erase(sul.begin());
        }

        if (!leste.empty())
        {
            primeiro ? cout << leste[0] : cout << ' ' << leste[0];
            primeiro = false;
            leste.erase(leste.begin());
        }
    }

    cout << endl;

    return 0;
}