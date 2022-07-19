/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct quadro
{
    int x1, y1;
    int x2, y2;
} quadro;

vector<quadro> quadros;

int n, w, h, qw, qh;

set<int> set_x, set_y;
vector<int> coordenada_x, coordenada_y;

int possivel(int x, int y){
    if(x + qw > w){
        return 0;
    }

    if(y + qh > h){
        return 0;
    }

    if(x < 0 || y < 0){
        return 0;
    }

    for(int i = 0; i < n; i++){
        // colidiu
        if(max(quadros[i].x1, x) < min(quadros[i].x2, x + qw) && max(quadros[i].y1, y) < min(quadros[i].y2, y + qh)){
            return 0;
        }
    }

    return 1;
}

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        quadros.clear();
        set_x.clear();
        set_y.clear();
        coordenada_x.clear();
        coordenada_y.clear();

        cin >> n >> w >> h;

        
        for(int i = 0; i < n; i++){
            quadro q;

            cin >> q.x1 >> q.y1 >> q.x2 >> q.y2;


            quadros.push_back(q);

            if(!set_x.count(q.x1)){
                set_x.insert(q.x1);
                coordenada_x.push_back(q.x1);
            }

            if(!set_y.count(q.y1)){
                set_y.insert(q.y1);
                coordenada_y.push_back(q.y1);
            }

            if(!set_x.count(q.x2)){
                set_x.insert(q.x2);
                coordenada_x.push_back(q.x2);
            }

            if(!set_y.count(q.y2)){
                set_y.insert(q.y2);
                coordenada_y.push_back(q.y2);
            }
        }

        cin >> qw >> qh;

        if(!set_x.count(0)){
            coordenada_x.push_back(0);
        }

        if(!set_y.count(0)){
            coordenada_y.push_back(0);
        }


        sort(coordenada_x.begin(), coordenada_x.end());
        sort(coordenada_y.begin(), coordenada_y.end());
        

        int eh_possivel = 0;

        for(int i = 0; i < coordenada_y.size(); i++){
            // passou do limite
            if(coordenada_y[i] + qh > h){
                break;
            }

            for(int j = 0; j < coordenada_x.size(); j++){
                // passou do limite
                if(coordenada_x[j] + qw > w){
                    break;
                }

                if(possivel(coordenada_x[j], coordenada_y[i])){
                    eh_possivel = 1;
                    cout << coordenada_x[j] << " " << coordenada_y[i] << endl;
                    break;
                }
            }

            if(eh_possivel){
                break;
            }
        }

        if(!eh_possivel){
            cout << "Fail!" << endl;
        }
    }

    return 0;
}