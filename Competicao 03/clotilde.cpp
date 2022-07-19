/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define MIN 1

int canais_proibidos[MAX+1];

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int O, D, K, teste = 0;

    while(cin >> O >> D >> K){
        if(!O && !D && !K){
            break;
        }

        teste++;

        int canal;

        for(int i = 0; i < K; i++){
            cin >> canal;
            canais_proibidos[canal] = teste;
        }
        
        // <canal_atual, operações>
        queue<pair<int,int>> canais;

        canais.push({O, 0});

        bool encontrou = 0;

        while(!canais.empty()){
            pair<int, int> atual = canais.front();
            canais.pop();

            if(atual.first == D){
                encontrou = 1;
                cout << atual.second << endl;
                break;
            }

            if(canais_proibidos[atual.first] == teste){
                continue;
            }

            canais_proibidos[atual.first] = teste;

            int menos_op = atual.first - 1;

            if(menos_op >= MIN){
                canais.push({menos_op, atual.second+1});
            }

            int mais_op = atual.first + 1;

            if(mais_op <= MAX){
                canais.push({mais_op, atual.second+1});
            }

            int x2_op = atual.first * 2;

            if(x2_op <= MAX){
                canais.push({x2_op, atual.second+1});
            }

            if(atual.first % 2 == 0){
                int div2_op = atual.first / 2;
                
                canais.push({div2_op, atual.second+1});
            }

            int x3_op = atual.first * 3;

            if(x3_op <= MAX){
                canais.push({x3_op, atual.second+1});
            }
        }

        if(!encontrou){
            cout << -1 << endl;
        }

    }

    return 0;
}