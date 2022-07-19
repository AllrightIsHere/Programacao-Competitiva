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

    int num_pecas, num_queries, casos = 1;

    while(cin >> num_pecas >> num_queries){
        if(!num_pecas && !num_queries){
            break;
        }
        cout << "CASE# " << casos << ":" << endl;

        vector<int> pecas;

        for(int i = 0; i < num_pecas; i++){
            int a;
            cin >> a;
            pecas.push_back(a);
        }

        sort(pecas.begin(), pecas.end());

        int q;
        //5 found at 4
        for(int i = 0; i < num_queries; i++){
            cin >> q;

            auto res = find(pecas.begin(), pecas.end(), q);

            if (res != pecas.end()){
                cout << q << " found at " << res - pecas.begin() + 1 << endl;
            }

            else{
                cout << q << " not found" << endl;
            }
        }
        casos++;
    }

    return 0;
}