/*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double S, N, M;

    while(cin >> S >> N >> M){
        if(!S && !N && !M){
            break;
        }
        
        // altura do triangulo maior
        double h = 2*S/(M+1);

        double c1, c2, c3;

        cin >> c1 >> c2 >> c3;

        // altura do triangulo interno
        double h1 = h*c1/(N+1);

        // area do triangulo menor
        double area = abs(c3-c2)*h1/2;

        int res = (int) area;

        if(ceil(area) != floor(area)){
            res++;
        }

        cout << res << endl;
    }

    return 0;
}