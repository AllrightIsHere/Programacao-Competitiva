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

    int N;

    cin >> N;

    for(int i = 1; i <= N; i++){
        string s1, s2;
        int num1, num2;

        cin >> s1 >> s2;

        num1 = stoi(s1, NULL, 2);
        num2 = stoi(s2, NULL, 2);

        if(__gcd(num1, num2) == 1){
            cout << "Pair #" << i <<": Love is not all you need!" << endl;
            continue;
        }

        cout << "Pair #" << i <<": All you need is love!" << endl;
    }

    return 0;
}