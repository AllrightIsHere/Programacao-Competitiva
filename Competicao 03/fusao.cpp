/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int origens[100001];

int encontrar_origem(int banco){
    // encontra a origem do banco
    while(banco != origens[banco]){
        banco = origens[banco];
    }

    return banco;
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, b;

    cin >> K >> b;

    // preenche as origens e quantidades de bancos
    for(int i = 1; i <= K; i++){
        origens[i] = i;
    }

    for(int i = 0; i < b; i++){
        int b1, b2;
        char operacao;

        cin >> operacao >> b1 >> b2;

        if(operacao == 'F'){
            int origem_banco1 = encontrar_origem(b1);
            int origem_banco2 = encontrar_origem(b2);

            // já estão na mesma fusão
            if(origem_banco1 == origem_banco2){
                continue;
            }

            origens[origem_banco2] = origem_banco1;
        }
        else{
            if(encontrar_origem(b1) == encontrar_origem(b2)){
                cout << "S" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }

    }

    return 0;
}