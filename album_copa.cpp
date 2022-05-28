#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, fig;
    set<int> figurinhas;

    cin >> N >> M;

    while (M--)
    {
        cin >> fig;
        figurinhas.insert(fig);
    }

    cout << N - figurinhas.size() << endl;

    return 0;
}