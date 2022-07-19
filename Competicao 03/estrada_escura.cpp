/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> grafo;
vi visitado;
priority_queue<ii> pq;


void processar(int vertice){
    visitado[vertice] = 1;

    for(auto &[v, w]: grafo[vertice]){
        if(!visitado[v]){
            pq.push({-w, -v});
        }
    }
}

int checar_visitados(){
    for(int i = 0; i < visitado.size(); i++){
        if(visitado[i] == 0){
            return i;
        }
    }

    return -1;
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin >> m >> n;

    while (m && n)
    {
        int origem, destino, peso;

        long long int soma_pesos = 0;

        grafo.assign(m, vii());

        for(int i = 0; i < n; i++){
            cin >> origem >> destino >> peso;
            grafo[origem].emplace_back(destino, peso);
            grafo[destino].emplace_back(origem, peso);
            soma_pesos+=peso;
        }

        visitado.assign(m, 0);
        processar(0);

        long long int custo_minimo = 0, num_visitados = 0;

        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();

            w = -w;
            u = -u;

            if(visitado[u]){
                continue;
            }

            custo_minimo += w;

            processar(u);
            num_visitados++;

            if(num_visitados == m - 1){
                break;
            }
        }

        int proxima_cidade = checar_visitados();
        pq = priority_queue<ii>();
        
        // outros ciclos de estradas
        while(proxima_cidade != -1){

            processar(proxima_cidade);

            while(!pq.empty()){
                auto [w, u] = pq.top();
                pq.pop();

                w = -w;
                u = -u;

                if(visitado[u]){
                    continue;
                }

                custo_minimo += w;

                processar(u);
                num_visitados++;

                if(num_visitados == m - 1){
                    break;
                }
            }

            proxima_cidade = checar_visitados();
            
            pq = priority_queue<ii>();
        }

        cout << soma_pesos - custo_minimo << endl;

        cin >> m >> n;
    }
    

    return 0;
}