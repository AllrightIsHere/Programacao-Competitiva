/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> visitados;
vector<vector<int>> familias;
int M;

void dfs(int origem){
    if(visitados[origem]){
        return;
    }

    visitados[origem] = 1;

    for(int i = 0; i < M; i++){
        if(familias[origem][i]){
            dfs(i);
        }
    }
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;

    cin >> M >> N;

    map<string, int> membros;
    int index = 0;

    familias.resize(M);
    
    for(int i = 0; i < M; i++){
        familias[i].resize(M);
    }

    while(N--){
        string nome1, rel, nome2;

        cin >> nome1 >> rel >> nome2;

        if(!membros.count(nome1)){
            membros[nome1] = index;
            index++;
        }

        if(!membros.count(nome2)){
            membros[nome2] = index;
            index++;
        }

        familias[membros[nome1]][membros[nome2]] = 1;
        familias[membros[nome2]][membros[nome1]] = 1;
    }

    int qtd = 0;

    visitados.resize(M);

    for(int i = 0; i < M; i++){
        if(!visitados[i]){
            dfs(i);
            qtd++;
        }
    }

    cout << qtd << endl;
    
    return 0;
}