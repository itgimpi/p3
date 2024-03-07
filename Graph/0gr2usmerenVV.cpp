#include <bits/stdc++.h>
// moj drugi usmereni graf, vektori - koristi se
// directed graph
using namespace std;
int main() {
    int n = 4;
    int e = 4;
    vector<vector<int>>susedi(n); // lista suseda

    susedi[0].push_back(1); // usmeren graf, od 0 do 1
    susedi[0].push_back(2); // usmeren graf, od 0 do 2
    susedi[0].push_back(3); // usmeren graf, od 0 do 3
    susedi[2].push_back(3); // usmeren graf, od 2 do 3

    for ( auto node = 0; node < n; node++ )
        for ( auto s : susedi[node] )
            cout << node << "->" << s << endl;




    return 0; }
