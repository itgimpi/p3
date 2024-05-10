#include <bits/stdc++.h>
using namespace std;
// topological sort


int main() {
    int n, e; cin >> n >> e;
    vector<int>brpreth(n);
    vector<vector<int>>sledi(n);
    for (int i = 0; i < e; i++) {    //     p2                      p1
        int p1, p2; cin >> p1 >> p2; // poso 3 se izvrsava pre posla 1
        brpreth[p1]++;
        sledi[p2].push_back(p1);  }

    queue<int>nezavisni;

    for (int p = 0; p < n; p++) 
        if ( brpreth[p] == 0 )
            nezavisni.push(p);

    while ( !nezavisni.empty() ) {
        int p = nezavisni.front();
        nezavisni.pop();
        cout << p << endl;

        for ( auto s : sledi[p] )
            if (--brpreth[s]==0)
                nezavisni.push(s);

    }


    


    return 0; }
