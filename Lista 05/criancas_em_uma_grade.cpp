#include <bits/stdc++.h>

using namespace std;

int pd[510][510];
string s1, s2;
char grade[20][20];
int H, W, tam1, tam2;

void preenche_string(string &s, int x, int y, string passos)
{
    x--;
    y--;
    s.push_back(grade[x][y]);
    for (char p : passos)
    {
        switch (p)
        {
        case 'N':
            x = (x - 1 + H) % H;
            break;
        case 'S':
            x = (x + 1) % H;
            break;
        case 'E':
            y = (y + 1) % W;
            break;
        case 'W':
            y = (y - 1 + W) % W;
            break;
        default:
            break;
        }
        s.push_back(grade[x][y]);
    }
}

int calcula_max(int i, int j)
{
    // chegou no final da string 1
    if (i == tam1)
    {
        return 0;
    }

    // chegou no final da string 2
    if (j == tam2)
    {
        return 0;
    }

    // ganho na recursão
    if (pd[i][j] != -1)
    {
        return pd[i][j];
    }

    int remo = 0;

    if (s1[i] == s2[j])
    {
        remo = max(remo, calcula_max(i + 1, j + 1) + 1);
    }

    // anda em s1
    remo = max(remo, calcula_max(i + 1, j));

    // anda em s2
    remo = max(remo, calcula_max(i, j + 1));

    return pd[i][j] = remo;
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;

    cin >> t;

    for (k = 1; k <= t; k++)
    {
        cin >> H >> W;

        int i, j;

        for (i = 0; i < H; i++)
        {
            for (j = 0; j < W; j++)
            {
                cin >> grade[i][j];
            }
        }

        string passos;
        int x, y;

        cin >> tam1 >> x >> y >> passos;

        preenche_string(s1, x, y, passos);

        cin >> tam2 >> x >> y >> passos;

        preenche_string(s2, x, y, passos);

        tam1++;
        tam2++;

        // cout << s1 << endl << s2 << endl;

        // reseta a matriz da programação dinâmica
        memset(pd, -1, sizeof pd);

        int remocoes = calcula_max(0, 0);

        // cout << remocoes << endl;

        cout << "Case " << k << ": " << (tam1 - remocoes) << ' ' << (tam2 - remocoes) << endl;
    }

    return 0;
}