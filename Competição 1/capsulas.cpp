//Alexandre Luis Ribeiro Martins
//Diego Santos Gonçalves
//Gabriel Arrighi Silva

#include <bits/stdc++.h>
#define endl '\n'


using namespace std;


const unsigned long long int INF = 1e9;

vector<unsigned long long int> capsulas;
unsigned long long int N, F;

unsigned long long int binary_search(unsigned long long int esq, unsigned long long int dir) {
    if(esq >= dir) {
        return esq;
    }
    
    unsigned long long int mid = (esq + dir)/2;
    
    unsigned long long int total_capsulas = 0;
    for(unsigned long long int i = 0; i < capsulas.size(); i++) {
        total_capsulas += mid/capsulas[i];
    }
    if(total_capsulas < F) {
        binary_search(mid+1, dir);
    } else {
        binary_search(esq, mid);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unsigned long long int capsula, dias;
    cin >> N >> F;
    while(N--) {
        cin >> capsula;
        capsulas.push_back(capsula);
    }
    
    dias = binary_search(1, INF);
    cout << dias << endl;
}