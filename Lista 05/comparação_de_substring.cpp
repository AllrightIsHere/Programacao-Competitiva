#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string frase1, frase2;

    while (getline(cin, frase1) && getline(cin, frase2))
    {
        int i, j, k, l;

        int tam_1 = frase1.size(), tam_2 = frase2.size();
        int maior = 0, tmp_maior;

        if (tam_1 < tam_2)
        {
            for (i = 0; i < tam_1; i++)
            {
                for (j = 0; j < tam_2; j++)
                {
                    if (frase1[i] == frase2[j])
                    {
                        tmp_maior = 0;
                        for (k = i, l = j; k < tam_1 && l < tam_2; k++, l++)
                        {
                            if (frase1[k] != frase2[l])
                            {
                                break;
                            }
                            tmp_maior++;
                        }

                        if (tmp_maior > maior)
                        {
                            maior = tmp_maior;
                        }
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < tam_2; i++)
            {
                for (j = 0; j < tam_1; j++)
                {
                    if (frase2[i] == frase1[j])
                    {
                        tmp_maior = 0;
                        for (k = i, l = j; k < tam_2 && l < tam_1; k++, l++)
                        {
                            if (frase2[k] != frase1[l])
                            {
                                break;
                            }
                            tmp_maior++;
                        }

                        if (tmp_maior > maior)
                        {
                            maior = tmp_maior;
                        }
                    }
                }
            }
        }

        cout << maior << endl;
    }

    return 0;
}