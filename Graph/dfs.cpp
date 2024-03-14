#include <bits/stdc++.h>
using namespace std;
// DFS directed
vector<vector<int>>veze; // Global
vector<bool>posecen;

void dodaj(int u, int v) {
    veze[u].push_back(v); }

void dfs(int c) { // pocetni cvor
    if (!posecen[c]) {
        posecen[c] = true;
        cout << c << ' ';
        for ( auto k : veze[c] )
            dfs(k); } }

int main() {
    int nc = 5; // br cvorova, cin>>
    veze.resize(nc);
    posecen.resize(nc, false);

    dodaj(0,1); dodaj(1,2); dodaj(1,3); dodaj(2,3); dodaj(3,0); dodaj(3,4); 

    dfs(4);

    return 0; }
