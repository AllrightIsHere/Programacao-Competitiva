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

    /*
    Alexandre Luis
    Gabriel Arrighi
    Thiago Fernandes Dornelles
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    // cout rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.precision(3);
    cout << fixed;

    string line;

    while(getline(cin, line)) {
        double side = stod(line);
        double square = pow(side, 2);

        double area = ((square * M_PI) / 3.0) - (0.5 * square * sin(2*M_PI/3));

        double subarea = square - ((M_PI * square / 2.0) - area);
        double sub1 = 4.0 * subarea;
        double sub2 = 4.0 * (square - (M_PI * square / 4.0) - (2.0 * subarea));
        double sub3 = square - sub1 - sub2;

        cout << sub3 << " " << sub2 << " " << sub1 << endl;
    }

    return 0;
}