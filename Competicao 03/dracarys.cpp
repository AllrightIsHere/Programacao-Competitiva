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

    int L1, C1, L2, C2;

    cin >> L1 >> C1 >> L2 >> C2;

    int max1 = max(L1, C1);
    int max2 = max(L2, C2);
    int min1 = min(L1, C1);
    int min2 = min(L2, C2);

    int S = min1 + min2;
    int M = min(max1, max2);

    long long int lado = min(S, M);

    cout << lado*lado << endl;

    return 0;
}