#include <bits/stdc++.h>

#define ulli unsigned long long int
// dias de treino, multa
#define pii pair<ulli, ulli>
// dia inserido, <dias de treino, multa>
#define ppii pair<ulli, pii>
#define mp make_pair

using namespace std;

class Comparacao
{
public:
    bool operator()(const ppii a, const ppii b)
    {
        return a.second.first * b.second.second > a.second.second * b.second.first;
    }
};

using namespace std;

int main()
{
    priority_queue<ppii, vector<ppii>, Comparacao> dragoes;
    ulli T, F, dia_atual = 0, dias_treino = 0, multa = 0;

    while (cin >> T >> F)
    {
        dragoes.push(mp(dia_atual, mp(T, F)));
        // treina o próximo dragão
        if (dias_treino == 0)
        {
            ppii d = dragoes.top();
            dragoes.pop();
            multa += (dia_atual - d.first) * d.second.second;
            dias_treino = d.second.first;
        }
        dias_treino--;
        dia_atual++;
    }
    while (!dragoes.empty())
    {
        // treina o próximo dragão
        if (dias_treino == 0)
        {
            ppii d = dragoes.top();
            dragoes.pop();
            multa += (dia_atual - d.first) * d.second.second;
            dias_treino = d.second.first;
        }
        dias_treino--;
        dia_atual++;
    }
    cout << multa << endl;
}