#include <bits/stdc++.h>
// moj drugi neusmereni graf, vektori - koristi se
// undirected graph
using namespace std;
int main() {
    int n = 4;
    int e = 4;
    vector<vector<int>>susedi(n); // lista suseda

    susedi[0].push_back(1); // neusmeren graf, od 0 do 1
    susedi[1].push_back(0); // neusmeren graf, od 1 do 0

    susedi[0].push_back(2); // 
    susedi[2].push_back(0); // 
    susedi[0].push_back(3); // 
    susedi[3].push_back(0); //
    susedi[2].push_back(3); // 
    susedi[3].push_back(2); //



    for ( auto node = 0; node < n; node++ )
        for ( auto s : susedi[node] )
            cout << node << "->" << s << endl;




    return 0; }
