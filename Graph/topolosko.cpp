#include <bits/stdc++.h>
using namespace std;
// topological sort


int main() {
    int n, e; cin >> n >> e;
    vector<int>brpreth(n);
    vector<vector<int>>sledi(n);
    for (int i = 0; i < e; i++) {    //     p2                      p1
        int p1, p2; cin >> p2 >> p1; // poso 3 se izvrsava pre posla 1
        brpreth[p1]++;
        sledi[p2].push_back(p1);  }
    vector<bool>resen(n, false);
    // O(nn)
    for (int i = 0; i < n; i++) { // za svaki cvor...
        int p;
        for ( p = 0; p < n; p++ ) // trazi posao bez preth.
            if (!resen[p] && brpreth[p]==0)
                break;
        cout << p << endl;
        resen[p] = true;
        for ( auto s : sledi[p] ) // za sve njegove sledbenike...
            brpreth[s]--;




    }


    return 0; }
