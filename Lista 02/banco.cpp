#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int qtd, i, j, k, aux, count = 0, freq, cont_senha, digito;
    char dig;
    vector<int> vt1, vt3, senha;
    vector<vector<pair<int, int>>> vt2;
    vector<pair<int, int>> vt4;
    pair<int, int> p;

    while (true)
    {
        cin >> qtd;

        if (qtd == 0)
            break;

        count++;

        for (i = 0; i < qtd; i++)
        {
            for (j = 0; j < 10; j++)
            {
                cin >> aux;
                vt1.push_back(aux);
            }

            vt4.clear();

            for (j = 0; j < 6; j++)
            {
                cin >> dig;

                switch (dig)
                {
                case 'A':
                    p.first = vt1[0];
                    p.second = vt1[1];
                    break;
                case 'B':
                    p.first = vt1[2];
                    p.second = vt1[3];
                    break;
                case 'C':
                    p.first = vt1[4];
                    p.second = vt1[5];
                    break;
                case 'D':
                    p.first = vt1[6];
                    p.second = vt1[7];
                    break;
                case 'E':
                    p.first = vt1[8];
                    p.second = vt1[9];
                    break;
                default:
                    break;
                }
                vt4.push_back(p);
            }
            vt2.push_back(vt4);

            vt1.clear();
        }

        /*
        cout << "VT2: ";

        for (i = 0; i < vt2.size(); i++)
        {
            cout << "ttttt: " << endl;
            for (j = 0; j < vt2[i].size(); j++)
                cout << vt2[i][j].first << ' ' << vt2[i][j].second << endl;
        }

        cout << endl;

        */

        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < qtd; j++)
            {
                vt3.push_back(vt2[j][i].first);
                vt3.push_back(vt2[j][i].second);
            }
            /*
            cout << "Primeira: " << endl;
            for (j = 0; j < vt3.size(); j++)
            {
                cout << vt3[j] << ' ';
            }

            cout << endl;

            */

            freq = 0;

            for (j = 0; j < vt3.size(); j++)
            {
                cont_senha = 0;
                for (k = 0; k < vt3.size(); k++)
                {
                    if (vt3[j] == vt3[k])
                        cont_senha++;
                }

                if (cont_senha > freq)
                {
                    digito = vt3[j];
                    freq = cont_senha;
                }
            }

            senha.push_back(digito);
            vt3.clear();
        }

        cout << "Teste " << count << endl;
        for (i = 0; i < senha.size(); i++)
        {
            cout << senha[i] << ' ';
        }

        vt2.clear();
        vt3.clear();
        senha.clear();

        cout << endl
             << endl;
    }

    return 0;
}