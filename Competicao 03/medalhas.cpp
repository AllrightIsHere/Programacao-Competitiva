/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct quadro {
    string pais;
    int ouro, prata, bronze;
} quadro;

bool comparador(quadro a, quadro b){
    if (a.ouro != b.ouro){
        return a.ouro > b.ouro;
    }

    if (a.prata != b.prata){
        return a.prata > b.prata;
    }

    if (a.bronze != b.bronze){
        return a.bronze > b.bronze;
    }

    return a.pais < b.pais;
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<quadro> quadros;

    for(int i = 0; i < N; i++){
        quadro item;

        cin >> item.pais >> item.ouro >> item.prata >> item.bronze;

        quadros.push_back(item);
    }

    sort(quadros.begin(), quadros.end(), comparador);

    for(quadro item : quadros){
        cout << item.pais << ' ' << item.ouro << ' ' << item.prata << ' ' << item.bronze << endl;
    }

    return 0;
}