#include <bits/stdc++.h>
using namespace std;
// Пећине, https://petlja.org/biblioteka/r/Zbirka3/pecine

int main() {
    ios_base::sync_with_stdio(false);

    int h0, n; cin >> h0 >> n;
    vector<vector<pair<int,int>>>veze(n);
    for (int i = 0; i < n-1; i++  ) {
        int poc, kraj, raz; cin >> poc >> kraj >> raz;
        // pair p...; 
        veze[poc].emplace_back(kraj, raz); // malo brze
    }
    // da odmorimo malo od DFSa
    queue<pair<int,int>>red;
    red.emplace( 0, h0); // init state
    int naj = h0;

    while ( !red.empty() ) {
        pair<int,int>p = red.front(); red.pop();
        naj = min(naj, p.second);
        for (auto v : veze[p.first]) 
            red.emplace(v.first, v.second + p.second);  }
    cout << naj;
    
    return 0; }
