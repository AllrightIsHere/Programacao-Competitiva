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

    cout.precision(1);
    cout << fixed;

    string line;

    int xi;
    while(cin >> xi) {
        int yi, xf, yf, v;
        int xl, yl, xr, yr;

        cin >> yi >> xf >> yf >> v;
        cin >> xl >> yl >> xr >> yr;

        double xHomeToTerrain = xl - xi;
        double xTerrainToSchool = xf - xr;

        
        double upperHomeToTerrain = sqrt(double(pow(double(abs(yi - yr)), 2) + pow(xHomeToTerrain, 2)));
        double upperTerrainToSchool = sqrt(double(pow(yr - yf, 2) + pow(xTerrainToSchool, 2)));

        double lowerHomeToTerrain = sqrt(double(pow(double(abs(yi - yl)), 2) + pow(xHomeToTerrain, 2)));
        double lowerTerrainToSchool = sqrt(double(pow(yl - yf, 2) + pow(xTerrainToSchool, 2)));
        

        double terrainSide = xr - xl;

        double upperDist = upperHomeToTerrain + terrainSide + upperTerrainToSchool;
        double lowerDist = lowerHomeToTerrain + terrainSide + lowerTerrainToSchool;
        double time = min(upperDist, lowerDist) / double(v);

        cout << time << endl;
    }

    return 0;
}